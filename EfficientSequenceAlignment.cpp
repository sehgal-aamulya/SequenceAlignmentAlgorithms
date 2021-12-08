//
// Created by Aamulya Sehgal on 11/17/21.
//

#include "EfficientSequenceAlignment.hpp"
#include "SequenceAlignment.hpp"
#include "NucleotideBases.hpp"

EfficientSequenceAlignment::EfficientSequenceAlignment(
	std::string_view stringOne, std::string_view stringTwo, char gapSymbol,
	int gapPenalty, const std::array<std::array<int, 4>, 4> &mismatchPenalty)
	: stringOne(stringOne), stringTwo(stringTwo), gapSymbol(gapSymbol), gapPenalty(gapPenalty),
		mismatchPenalty(mismatchPenalty), _align{} {}

template<typename T>
std::vector<size_t>
EfficientSequenceAlignment::iteratorAlign(T strOneBegin, T strOneEnd, T strTwoBegin, T strTwoEnd) const {
	const auto strTwoSize = strTwoEnd - strTwoBegin;

	std::array<std::vector<size_t>, 2> optimalMatrix{std::vector<size_t>(strTwoSize + 1),
																									 std::vector<size_t>(strTwoSize + 1)};
	size_t index = 0;
	for (size_t j = 0; j < optimalMatrix[index].size(); ++j) optimalMatrix[index][j] = j * gapPenalty;

	const auto strOneSize = strOneEnd - strOneBegin;
	for (size_t i = 1; i <= strOneSize; ++i) {
		index = 1 - index;
		optimalMatrix[index][0] = i * gapPenalty;

		for (size_t j = 1; j <= strTwoSize; ++j) {
			optimalMatrix[index][j] =
				std::min(mismatchPenalty[fromCharacter(*(strOneBegin + i - 1))]
								 [fromCharacter(*(strTwoBegin + j - 1))]
									 + optimalMatrix[1 - index][j - 1],
								 std::min(gapPenalty + optimalMatrix[1 - index][j], gapPenalty + optimalMatrix[index][j - 1]));
		}
	}

	return optimalMatrix[index];
}

std::pair<std::string, std::string>
EfficientSequenceAlignment::sequence(std::string_view strOne, std::string_view strTwo) const {
	if (strOne.size() <= 2 || strTwo.size() <= 2) {
		SequenceAlignment sequenceAlignment(strOne, strTwo, gapSymbol, gapPenalty, mismatchPenalty);
		return sequenceAlignment.sequence();
	}

	const std::string_view leftStrOne = strOne.substr(0, strOne.size() / 2);
	const std::string_view rightStrOne = strOne.substr(strOne.size() / 2);

	const std::vector<size_t>
		left = iteratorAlign(leftStrOne.cbegin(), leftStrOne.cend(), strTwo.cbegin(), strTwo.cend());
	const std::vector<size_t>
		right = iteratorAlign(rightStrOne.crbegin(), rightStrOne.crend(), strTwo.crbegin(), strTwo.crend());

	auto leftIt = left.cbegin();
	auto rightIt = right.crbegin();
	size_t minValue = SIZE_MAX, minIndex = SIZE_MAX;
	for (size_t i = 0; i < left.size(); ++i) {
		const size_t value = *leftIt + *rightIt;
		if (minValue > value) {
			minValue = value;
			minIndex = i;
		}
		++leftIt;
		++rightIt;
	}

	const std::string_view leftStringTwo = strTwo.substr(0, minIndex);
	const std::string_view rightStringTwo = strTwo.substr(minIndex);

	const auto[leftSequenceOne, leftSequenceTwo]   = sequence(leftStrOne, leftStringTwo);
	const auto[rightSequenceOne, rightSequenceTwo] = sequence(rightStrOne, rightStringTwo);

	return {leftSequenceOne + rightSequenceOne, leftSequenceTwo + rightSequenceTwo};
}

std::pair<std::string, std::string> EfficientSequenceAlignment::sequence() const {
	if (sequenceOne.empty()) std::tie(sequenceOne, sequenceTwo) = sequence(stringOne, stringTwo);
	return {sequenceOne, sequenceTwo};
}

size_t EfficientSequenceAlignment::align() const {
	if (sequenceOne.empty()) sequence();
	if (!_align) {
		for (size_t i = 0; i < sequenceOne.size(); ++i) {
			if (sequenceOne[i] == gapSymbol || sequenceTwo[i] == gapSymbol) _align += gapPenalty;
			else _align += mismatchPenalty[fromCharacter(sequenceOne[i])][fromCharacter((sequenceTwo[i]))];
		}
	}
	return _align;
}
