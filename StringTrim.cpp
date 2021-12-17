//
// Created by Aamulya Sehgal on 12/4/21.
//

#include "StringTrim.hpp"

bool isSpace(char ch) {
	return std::use_facet<std::ctype<char>>(std::locale()).is(std::ctype_base::space, ch);
}

void trimLeft(std::string &str) {
	str.erase(std::begin(str), std::find_if(std::begin(str), std::end(str), std::not_fn(isSpace)));
}

void trimRight(std::string &str) {
	str.erase(std::find_if(std::rbegin(str), std::rend(str), std::not_fn(isSpace))
							.base(), std::end(str));
}

void trim(std::string &str) {
	trimLeft(str);
	trimRight(str);
}
