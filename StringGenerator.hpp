//
// Created by Aamulya Sehgal on 12/4/21.
//

#ifndef CSCI570FINALPROJECT_STRINGGENERATOR_HPP
#define CSCI570FINALPROJECT_STRINGGENERATOR_HPP

#include <string>
#include <vector>

std::pair<std::string, std::string> inputStringGenerator(std::string_view strOne, std::string_view strTwo,
                                                         const std::vector<size_t> &j, const std::vector<size_t> &k);

#endif //CSCI570FINALPROJECT_STRINGGENERATOR_HPP
