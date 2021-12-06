//
// Created by Aamulya Sehgal on 12/4/21.
//

#include <string>
#include <iostream>
#include <fstream>
#include <sys/resource.h>
#include "SequenceAlignment.h"
#include "StringGenerator.h"
#include "StringTrim.h"

int main(int argc, char *argv[]) {
	if (argc < 2) {
		std::cout << "Please include an input file name (./7952603892_basic input.txt)" << std::endl;
		std::cout << "You can also include an output file name (defaults to output.txt) "
								 "(./7952603892_basic input.txt output.txt)" << std::endl;
		return EXIT_FAILURE;
	}

	const std::array<std::array<int, 4>, 4> mismatchPenalty = {
		0, 110, 48, 94,
		110, 0, 118, 48,
		48, 118, 0, 110,
		94, 48, 110, 0
	};

	const int gapPenalty = 30;

	const char gapSymbol = '_';

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
	int startReturn, endReturn;

	startReturn = getrusage(RUSAGE_SELF, &start);
	if (startReturn) return startReturn;

	const SequenceAlignment sequenceAlignment(stringOne, stringTwo, gapSymbol, gapPenalty, mismatchPenalty);
	const size_t alignmentCost = sequenceAlignment.align();
	const auto[sequenceOne, sequenceTwo] = sequenceAlignment.sequence();

	endReturn = getrusage(RUSAGE_SELF, &end);
	if (endReturn) return endReturn;

	double diffTime = (end.ru_utime.tv_sec * 1000000.0 + end.ru_utime.tv_usec +
		end.ru_stime.tv_sec * 1000000.0 + end.ru_stime.tv_usec -
		start.ru_utime.tv_sec * 1000000.0 - start.ru_utime.tv_usec -
		start.ru_stime.tv_sec * 1000000.0 - start.ru_stime.tv_usec) /
		1000000.0;

	double diffMemory = end.ru_maxrss - start.ru_maxrss;

	if (diffMemory == 0.0) {
		diffMemory = end.ru_maxrss;
	}

	std::cout << "Basic Version:" << std::endl;

	std::cout << "StringOne: " << stringOne << std::endl;
	std::cout << "StringTwo: " << stringTwo << std::endl;

	std::cout << std::endl;

	std::cout << "Problem Size (product of string sizes): " << stringOne.size() * stringTwo.size() << std::endl;

	std::cout << std::endl;

	if (sequenceOne.size() <= 50) {
		std::cout << sequenceOne << std::endl;
		std::cout << sequenceTwo << std::endl;

		fout << sequenceOne << std::endl;
		fout << sequenceTwo << std::endl;
	}
	else {
		std::cout << sequenceOne.substr(0, 50) << " "
							<< sequenceOne.substr(sequenceOne.size() - 50)
							<< std::endl;
		std::cout << sequenceTwo.substr(0, 50) << " "
							<< sequenceTwo.substr(sequenceTwo.size() - 50)
							<< std::endl;

		fout << sequenceOne.substr(0, 50) << " "
				 << sequenceOne.substr(sequenceOne.size() - 50)
				 << std::endl;
		fout << sequenceTwo.substr(0, 50) << " "
				 << sequenceTwo.substr(sequenceTwo.size() - 50)
				 << std::endl;
	}

	std::cout << alignmentCost << std::endl;
	std::cout << std::fixed << diffTime << std::endl;
	std::cout << std::fixed << diffMemory << std::endl;


	fout << alignmentCost << std::endl;
	fout << std::fixed << diffTime << std::endl;
	fout << std::fixed << diffMemory << std::endl;

	return 0;
}
