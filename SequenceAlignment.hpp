//
// Created by Aamulya Sehgal on 11/16/21.
//

#ifndef CSCI570FINALPROJECT_SEQUENCEALIGNMENT_HPP
#define CSCI570FINALPROJECT_SEQUENCEALIGNMENT_HPP

#include <string_view>
#include <vector>
#include <array>
#include <iostream>
#include <iomanip>
#include <string>

class SequenceAlignment {
	const std::string_view stringOne, stringTwo;
	const char gapSymbol;
	const int gapPenalty;
	const std::array<std::array<int, 4>, 4> &mismatchPenalty;
	mutable std::vector<std::vector<size_t>> _optimalMatrix;

	public:
	SequenceAlignment(
		std::string_view stringOne, std::string_view stringTwo, char gapSymbol,
		int gapPenalty, const std::array<std::array<int, 4>, 4> &mismatchPenalty);

	size_t align() const;
	std::pair<std::string, std::string> sequence() const;
	const std::vector<std::vector<size_t>> &optimalMatrix() const;
};

void printOptimalMatrix(std::string_view stringOne, std::string_view stringTwo,
												const std::vector<std::vector<size_t>> &optimalMatrix);

void printMismatchPenalty(const std::array<std::array<int, 4>, 4> &mismatchPenalty);

#endif //CSCI570FINALPROJECT_SEQUENCEALIGNMENT_HPP
