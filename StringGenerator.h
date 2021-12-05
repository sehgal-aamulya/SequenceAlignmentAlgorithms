//
// Created by Aamulya Sehgal on 12/4/21.
//

#ifndef CSCI570FINALPROJECT_STRINGGENERATOR_H
#define CSCI570FINALPROJECT_STRINGGENERATOR_H

#include <string>
#include <span>

std::pair<std::string, std::string> inputStringGenerator(
	std::string_view strOne, std::string_view strTwo, std::span<size_t> j, std::span<size_t> k);

#endif //CSCI570FINALPROJECT_STRINGGENERATOR_H
