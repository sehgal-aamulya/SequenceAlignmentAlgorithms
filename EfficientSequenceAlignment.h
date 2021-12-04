//
// Created by Aamulya Sehgal on 11/17/21.
//

#ifndef CSCI570FINALPROJECT_EFFICIENTSEQUENCEALIGNMENT_H
#define CSCI570FINALPROJECT_EFFICIENTSEQUENCEALIGNMENT_H


#include <string>
#include <vector>
#include <array>
#include <iterator>

class EfficientSequenceAlignment {
	const std::string_view stringOne, stringTwo;
	const int gapPenalty;
	const std::array<std::array<int, 4>, 4> &mismatchPenalty;
	mutable size_t _align;
	mutable std::string sequenceOne, sequenceTwo;

	std::vector<size_t> iteratorAlign(auto strOneBegin, auto strOneEnd, auto strTwoBegin, auto strTwoEnd) const;
	std::pair<std::string, std::string> sequence(std::string_view strOne, std::string_view strTwo) const;

	public:
	EfficientSequenceAlignment(
		std::string_view stringOne, std::string_view stringTwo,
		int gapPenalty, const std::array<std::array<int, 4>, 4> &mismatchPenalty);

	size_t align() const;
	std::pair<std::string, std::string> sequence() const;
};


#endif //CSCI570FINALPROJECT_EFFICIENTSEQUENCEALIGNMENT_H
