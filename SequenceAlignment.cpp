//
// Created by Aamulya Sehgal on 11/16/21.
//

#include "SequenceAlignment.h"
#include "NucleotideBases.h"

SequenceAlignment::SequenceAlignment(
	std::string_view stringOne, std::string_view stringTwo, char gapSymbol,
	int gapPenalty, const std::array<std::array<int, 4>, 4> &mismatchPenalty)
	: stringOne(stringOne), stringTwo(stringTwo),
		gapSymbol(gapSymbol), gapPenalty(gapPenalty), mismatchPenalty(mismatchPenalty),
		_optimalMatrix(stringOne.size() + 1, std::vector<size_t>(stringTwo.size() + 1)) {}

size_t SequenceAlignment::align() const {
	if (_optimalMatrix[stringOne.size()][stringTwo.size()]) return _optimalMatrix[stringOne.size()][stringTwo.size()];

	for (size_t j = 0; j < _optimalMatrix[0].size(); ++j) _optimalMatrix[0][j] = j * gapPenalty;
	for (size_t i = 0; i < _optimalMatrix.size(); ++i) _optimalMatrix[i][0] = i * gapPenalty;

	for (size_t i = 1; i < _optimalMatrix.size(); ++i) {
		for (size_t j = 1; j < _optimalMatrix[0].size(); ++j) {
			_optimalMatrix[i][j] = std::min(mismatchPenalty
																			[fromCharacter(stringOne[i - 1])][fromCharacter(stringTwo[j - 1])]
																				+ _optimalMatrix[i - 1][j - 1],
																			std::min(gapPenalty + _optimalMatrix[i - 1][j],
																							 gapPenalty + _optimalMatrix[i][j - 1]));
		}
	}

	return _optimalMatrix[stringOne.size()][stringTwo.size()];
}

std::pair<std::string, std::string> SequenceAlignment::sequence() const {
	if (!_optimalMatrix[stringOne.size()][stringTwo.size()]) align();

	std::string sequenceOne, sequenceTwo;

	size_t i = stringOne.size(), j = stringTwo.size();
	while (i > 0 && j > 0) {
		if (_optimalMatrix[i][j] == gapPenalty + _optimalMatrix[i][j - 1]) {
			sequenceTwo.insert(0, stringTwo.substr(j - 1, 1));
			sequenceOne.insert(0, 1, gapSymbol);
			--j;
		}
		else if (_optimalMatrix[i][j] == gapPenalty + _optimalMatrix[i - 1][j]) {
			sequenceOne.insert(0, stringOne.substr(i - 1, 1));
			sequenceTwo.insert(0, 1, gapSymbol);
			--i;
		}
		else {
			sequenceOne.insert(0, stringOne.substr(i - 1, 1));
			sequenceTwo.insert(0, stringTwo.substr(j - 1, 1));
			--i;
			--j;
		}
	}
	while (i > 0) {
		sequenceOne.insert(0, stringOne.substr(i - 1, 1));
		sequenceTwo.insert(0, 1, gapSymbol);
		--i;
	}
	while (j > 0) {
		sequenceOne.insert(0, 1, gapSymbol);
		sequenceTwo.insert(0, stringTwo.substr(j - 1, 1));
		--j;
	}

	return {sequenceOne, sequenceTwo};
}

const std::vector<std::vector<size_t>> &SequenceAlignment::optimalMatrix() const {
	return _optimalMatrix;
}

void printOptimalMatrix(std::string_view stringOne, std::string_view stringTwo,
												const std::vector<std::vector<size_t>> &optimalMatrix) {
	std::cout << "     ";
	for (const char &ch: stringTwo) {
		std::cout << "   " << ch;
	};
	std::cout << std::endl;

	for (int64_t i = 0; i < optimalMatrix.size(); ++i) {
		if (i) std::cout << stringOne[i - 1] << " ";
		else std::cout << "  ";
		for (int64_t j = 0; j < optimalMatrix[0].size(); ++j) {
			std::cout << std::setw(3) << std::setfill('0') << optimalMatrix[i][j] << " ";
		}
		std::cout << std::endl;
	}

	std::cout << std::endl;
}

void printMismatchPenalty(const std::array<std::array<int, 4>, 4> &mismatchPenalty) {
	std::string alphabets = "ACGT";
	std::cout << " ";
	for (const char &ch: alphabets) {
		std::cout << "   " << ch;
	}
	std::cout << std::endl;

	for (int i = 0; i < mismatchPenalty.size(); ++i) {
		std::cout << alphabets[i] << " ";
		for (int j = 0; j < mismatchPenalty[0].size(); ++j) {
			std::cout << std::setw(3) << std::setfill('0') << mismatchPenalty[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}
