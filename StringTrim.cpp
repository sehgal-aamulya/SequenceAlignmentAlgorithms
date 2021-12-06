//
// Created by Aamulya Sehgal on 12/4/21.
//

#include "StringTrim.hpp"

bool isSpace(char ch) {
	return std::use_facet<std::ctype<char>>(std::locale()).is(std::ctype_base::space, ch);
}

void trimLeft(std::string &str) {
	auto it = str.begin();
	while (it != str.end()) {
		if (!isSpace(*it)) break;
		++it;
	}
	str.erase(str.begin(), it);
}

void trimRight(std::string &str) {
	auto it = str.end();
	while (it != str.begin()) {
		if (!isSpace(*(--it))) {
			++it;
			break;
		}
	}
	str.erase(it, str.end());
}

void trim(std::string &str) {
	trimLeft(str);
	trimRight(str);
}
