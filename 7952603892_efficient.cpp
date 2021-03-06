//
// Created by Aamulya Sehgal on 12/4/21.
//

#include <iostream>
#include <string>
#include <fstream>
#include <sys/resource.h>
#include "EfficientSequenceAlignment.hpp"
#include "StringGenerator.hpp"
#include "StringTrim.hpp"

int main(int argc, char *argv[]) {
  if (argc < 2) {
    std::cout << "Please include an input file name (./7952603892_efficient input.txt)" << std::endl;
    std::cout << "You can also include an output file name (defaults to output.txt) "
                 "(./7952603892_efficient input.txt output.txt)" << std::endl;
    return EXIT_FAILURE;
  }

  constexpr std::array<std::array<int, 4>, 4> mismatchPenalty = {
    0, 110, 48, 94,
    110, 0, 118, 48,
    48, 118, 0, 110,
    94, 48, 110, 0
  };

  constexpr int gapPenalty = 30;

  constexpr char gapSymbol = '_';

  const std::string_view inputFileName{argv[1]};
  const std::string_view outputFileName{(argc >= 3) ? argv[2] : "output.txt"};

  std::ifstream fin{inputFileName.data()};
  std::string strOne, strTwo;
  std::vector<size_t> j;
  std::vector<size_t> k;

  std::getline(fin, strOne);
  trim(strOne);

  size_t value;
  while (fin >> value) {
    j.push_back(value);
  }
  fin.clear();

  std::getline(fin, strTwo);
  trim(strTwo);

  while (fin >> value) {
    k.push_back(value);
  }

  const auto[stringOne, stringTwo] = inputStringGenerator(strOne, strTwo, j, k);

  std::ofstream fout{outputFileName.data()};

  rusage start, end;

  const int startReturn = getrusage(RUSAGE_SELF, &start);
  if (startReturn) return startReturn;

  const EfficientSequenceAlignment
    efficientSequenceAlignment(stringOne, stringTwo, gapSymbol, gapPenalty, mismatchPenalty);
  const auto[sequenceOne, sequenceTwo] = efficientSequenceAlignment.sequence();
  const size_t alignmentCost = efficientSequenceAlignment.align();

  const int endReturn = getrusage(RUSAGE_SELF, &end);
  if (endReturn) return endReturn;

  const double diffTime = (end.ru_utime.tv_sec * 1000000.0 + end.ru_utime.tv_usec +
    end.ru_stime.tv_sec * 1000000.0 + end.ru_stime.tv_usec -
    start.ru_utime.tv_sec * 1000000.0 - start.ru_utime.tv_usec -
    start.ru_stime.tv_sec * 1000000.0 - start.ru_stime.tv_usec) /
    1000000.0;

  double diffMemory = end.ru_maxrss - start.ru_maxrss;

  if (diffMemory == 0.0) diffMemory = end.ru_maxrss;

  #ifdef __APPLE__
  diffMemory /= 1024.0;
  #endif

  #ifndef NDEBUG
  std::cout << "Efficient Version:" << std::endl;

  std::cout << "StringOne: " << stringOne << std::endl;
  std::cout << "StringTwo: " << stringTwo << std::endl;

  std::cout << std::endl;

  std::cout << "Problem Size (sum of string sizes): " << stringOne.size() + stringTwo.size() << std::endl;

  std::cout << std::endl;
  #endif

  if (sequenceOne.size() <= 50) {
    #ifndef NDEBUG
    std::cout << sequenceOne << std::endl;
    std::cout << sequenceTwo << std::endl;
    #endif

    fout << sequenceOne << std::endl;
    fout << sequenceTwo << std::endl;
  }
  else {
    #ifndef NDEBUG
    std::cout << sequenceOne.substr(0, 50) << " "
              << sequenceOne.substr(sequenceOne.size() - 50)
              << std::endl;
    std::cout << sequenceTwo.substr(0, 50) << " "
              << sequenceTwo.substr(sequenceTwo.size() - 50)
              << std::endl;
    #endif

    fout << sequenceOne.substr(0, 50) << " "
         << sequenceOne.substr(sequenceOne.size() - 50)
         << std::endl;
    fout << sequenceTwo.substr(0, 50) << " "
         << sequenceTwo.substr(sequenceTwo.size() - 50)
         << std::endl;
  }

  #ifndef NDEBUG
  std::cout << alignmentCost << std::endl;
  std::cout << std::fixed << diffTime << std::endl;
  std::cout << std::fixed << diffMemory << std::endl;
  #endif

  fout << alignmentCost << std::endl;
  fout << std::fixed << diffTime << std::endl;
  fout << std::fixed << diffMemory << std::endl;

  return 0;
}
