#include <iostream>
#include <array>
#include <fstream>
#include <sys/resource.h>
#include "SequenceAlignment.hpp"
#include "EfficientSequenceAlignment.hpp"
#include "StringGenerator.hpp"
#include "StringTrim.hpp"

int main(int argc, char *argv[]) {
	if (argc < 2) {
		std::cout << "Please include an input file name (./CSCI570FinalProject input.txt)" << std::endl;
		std::cout << "You can also include an output file name (defaults to output.txt) "
								 "(./CSCI570FinalProject input.txt output.txt)" << std::endl;
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

	std::ifstream fin{inputFileName};
	std::string strOne, strTwo;
	std::vector<size_t> j;
	std::vector<size_t> k;
	std::getline(fin, strOne);
//	boost::trim(strOne);
	trim(strOne);
	size_t value;
	while (fin >> value) {
		j.push_back(value);
	}
	fin.clear();
	std::getline(fin, strTwo);
//	boost::trim(strTwo);
	trim(strTwo);
	while (fin >> value) {
		k.push_back(value);
	}

	const auto[stringOne, stringTwo] = inputStringGenerator(strOne, strTwo, j, k);

	std::cout << "StringOne: " << stringOne << std::endl;
	std::cout << "StringTwo: " << stringTwo << std::endl;

	std::cout << std::endl;

	std::cout << "Problem Size (sum of string sizes): " << stringOne.size() + stringTwo.size() << std::endl;

	std::cout << std::endl;

	std::ofstream fout{outputFileName};

	rusage start, end;
	int startReturn, endReturn;
	timeval diffTime;
	long diffMemory;
	size_t alignmentCost;
	std::string sequenceOne, sequenceTwo;

	startReturn = getrusage(RUSAGE_SELF, &start);
	if (startReturn) return startReturn;

	const SequenceAlignment sequenceAlignment(stringOne, stringTwo, gapSymbol, gapPenalty, mismatchPenalty);
	alignmentCost = sequenceAlignment.align();
	std::tie(sequenceOne, sequenceTwo) = sequenceAlignment.sequence();

	endReturn = getrusage(RUSAGE_SELF, &end);
	if (endReturn) return endReturn;

	diffTime = {.tv_sec  = end.ru_utime.tv_sec + end.ru_stime.tv_sec - start.ru_utime.tv_sec - start.ru_stime.tv_sec,
		.tv_usec = end.ru_utime.tv_usec + end.ru_stime.tv_usec - start.ru_utime.tv_usec - start.ru_stime.tv_usec};

	diffMemory = end.ru_maxrss - start.ru_maxrss;

	std::cout << "Standard Version: " << std::endl;
	std::cout << std::endl;

	std::cout << "Time:   " << diffTime.tv_sec * 1000000 + diffTime.tv_usec << " us" << std::endl;
	std::cout << "Memory: " << diffMemory << " kB" << std::endl;
	std::cout << std::endl;

	std::cout << "Alignment Cost: " << alignmentCost << std::endl;
	std::cout << "Sequence:\nstringOne: " << sequenceOne << "\nstringTwo: " << sequenceTwo << std::endl;
	std::cout << std::endl;

	if (sequenceOne.size() <= 50) {
		fout << sequenceOne << std::endl;
		fout << sequenceTwo << std::endl;
	}
	else {
		fout << sequenceOne.substr(0, 50) << " ... "
				 << sequenceOne.substr(sequenceOne.size() - 50) << std::endl;
		fout << sequenceTwo.substr(0, 50) << " ... "
				 << sequenceTwo.substr(sequenceTwo.size() - 50) << std::endl;
	}

	fout << diffTime.tv_sec * 1000000 + diffTime.tv_usec << std::endl;
	fout << diffMemory << std::endl;

	fout << std::endl;

	startReturn = getrusage(RUSAGE_SELF, &start);
	if (startReturn) return startReturn;

	const EfficientSequenceAlignment
		efficientSequenceAlignment(stringOne, stringTwo, gapSymbol, gapPenalty, mismatchPenalty);
	std::tie(sequenceOne, sequenceTwo) = efficientSequenceAlignment.sequence();
	alignmentCost = efficientSequenceAlignment.align();

	endReturn = getrusage(RUSAGE_SELF, &end);
	if (endReturn) return endReturn;

	diffTime = {.tv_sec  = end.ru_utime.tv_sec + end.ru_stime.tv_sec - start.ru_utime.tv_sec - start.ru_stime.tv_sec,
		.tv_usec = end.ru_utime.tv_usec + end.ru_stime.tv_usec - start.ru_utime.tv_usec - start.ru_stime.tv_usec};

	diffMemory = end.ru_maxrss - start.ru_maxrss;

	std::cout << "Efficient Version:" << std::endl;
	std::cout << std::endl;

	std::cout << "Time:   " << diffTime.tv_sec * 1000000 + diffTime.tv_usec << " us" << std::endl;
	std::cout << "Memory: " << diffMemory << " kB" << std::endl;
	std::cout << std::endl;

	std::cout << "Alignment Cost: " << alignmentCost << std::endl;
	std::cout << "Sequence:\nstringOne: " << sequenceOne << "\nstringTwo: " << sequenceTwo << std::endl;

	if (sequenceOne.size() <= 50) {
		fout << sequenceOne << std::endl;
		fout << sequenceTwo << std::endl;
	}
	else {
		fout << sequenceOne.substr(0, 50) << " ... "
				 << sequenceOne.substr(sequenceOne.size() - 50) << std::endl;
		fout << sequenceTwo.substr(0, 50) << " ... "
				 << sequenceTwo.substr(sequenceTwo.size() - 50) << std::endl;
	}

	fout << diffTime.tv_sec * 1000000 + diffTime.tv_usec << std::endl;
	fout << diffMemory << std::endl;

	return 0;
}
