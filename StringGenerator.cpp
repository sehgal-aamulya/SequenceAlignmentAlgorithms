//
// Created by Aamulya Sehgal on 12/4/21.
//

#include "StringGenerator.h"

std::pair<std::string, std::string> inputStringGenerator(std::string_view strOne, std::string_view strTwo,
																												 std::span<size_t> j, std::span<size_t> k) {
	std::string resultOne{strOne}, resultTwo{strTwo};
	for (const size_t i: j) resultOne.insert(i + 1, resultOne);
	for (const size_t i: k) resultTwo.insert(i + 1, resultTwo);
	return {resultOne, resultTwo};
}
