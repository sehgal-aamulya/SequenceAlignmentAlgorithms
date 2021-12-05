//
// Created by Aamulya Sehgal on 12/4/21.
//

#include <string>
#include <iostream>
#include <fstream>
#include <sys/resource.h>
#include "SequenceAlignment.h"

int main(int argc, char *argv[]) {
	if (argc < 3) {
		std::cout << "Please include an input strings (./7952603892_basic.out <string1> <string2>)" << std::endl;
		std::cout << "You can also include an output file name (defaults to output.txt) "
								 "(./7952603892_basic.out <string1> <string2> output.txt)" << std::endl;
		return EXIT_FAILURE;
	}

	std::ofstream fout{(argc >= 4) ? argv[3] : "output.txt", std::ios::out | std::ios::app};

	const std::array<std::array<int, 4>, 4> mismatchPenalty = {
		0, 110, 48, 94,
		110, 0, 118, 48,
		48, 118, 0, 110,
		94, 48, 110, 0
	};

	const int gapPenalty = 30;

	const char gapSymbol = '_';

	std::string stringOne = argv[1];
	std::string stringTwo = argv[2];

	rusage start, end;

	const int startReturn = getrusage(RUSAGE_SELF, &start);
	if (startReturn) return startReturn;

	const SequenceAlignment sequenceAlignmentGeneration(stringOne, stringTwo, gapSymbol, gapPenalty, mismatchPenalty);
	const size_t alignmentCost = sequenceAlignmentGeneration.align();
	const auto[sequenceOne, sequenceTwo] = sequenceAlignmentGeneration.sequence();

	const int endReturn = getrusage(RUSAGE_SELF, &end);
	if (endReturn) return endReturn;

	const double diffTime = (end.ru_utime.tv_sec * 1000000.0 + end.ru_utime.tv_usec +
		end.ru_stime.tv_sec * 1000000.0 + end.ru_stime.tv_usec -
		start.ru_utime.tv_sec * 1000000.0 - start.ru_utime.tv_usec -
		start.ru_stime.tv_sec * 1000000.0 - start.ru_stime.tv_usec) /
		1000000.0;

	double diffMemory = end.ru_maxrss - start.ru_maxrss;

	if (diffMemory == 0.0) {
		diffMemory = end.ru_maxrss;
	}

	std::cout << std::endl << "Basic," << stringOne.size() * stringTwo.size() << "," << std::fixed << diffTime << ","
						<< diffMemory;
	std::cout << std::endl << "Alignment Cost: " << alignmentCost << std::endl;
	std::cout << "Sequence:\n" << sequenceOne << std::endl << sequenceTwo << std::endl;
	fout << std::endl << "Basic," << stringOne.size() * stringTwo.size() << "," << std::fixed << diffTime << ","
			 << diffMemory;

	return 0;
}