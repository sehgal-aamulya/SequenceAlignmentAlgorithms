//
// Created by Aamulya Sehgal on 12/4/21.
//

#include <string>
#include <algorithm>
#include <random>
#include <array>
#include <iostream>
#include <fstream>

int main() {
	const std::string_view fileName = "plotdata.csv";

	std::ofstream fout{fileName.data()};

	std::string strOne{"ACTG"};
	std::string strTwo{"TACG"};

	std::random_device rd;
	std::mt19937 g(rd());

	std::shuffle(strOne.begin(), strOne.end(), g);
	std::shuffle(strTwo.begin(), strTwo.end(), g);

	std::string stringOne{strOne};
	std::string stringTwo{strTwo};

	fout << "type,problemsize,cputime,memoryusage" << std::flush;

	std::string basic = "./BasicCSV " + stringOne + " " + stringTwo + " " + fileName.data();
	system(basic.c_str());

	std::string efficient = "./EfficientCSV " + stringOne + " " + stringTwo + " " + fileName.data();
	system(efficient.c_str());

	for (int generations = 1; generations <= 8; ++generations) {
		std::shuffle(strOne.begin(), strOne.end(), g);
		std::shuffle(strTwo.begin(), strTwo.end(), g);

		stringOne = strOne;
		stringTwo = strTwo;

		for (int rounds = 1; rounds <= generations; ++rounds) {
			std::uniform_int_distribution<unsigned long> distribution(1ul, stringOne.size());
			unsigned long pos = distribution(g);
			stringOne.insert(pos, stringOne);
			pos = distribution(g);
			stringTwo.insert(pos, stringTwo);
		}

		basic = "./BasicCSV " + stringOne + " " + stringTwo + " " + fileName.data();
		system(basic.c_str());

		efficient = "./EfficientCSV " + stringOne + " " + stringTwo + " " + fileName.data();
		system(efficient.c_str());
	}

	std::shuffle(strOne.begin(), strOne.end(), g);
	std::shuffle(strTwo.begin(), strTwo.end(), g);

	stringOne = strOne;
	stringTwo = strTwo;

	for (int rounds = 1; rounds <= 8; ++rounds) {
		std::uniform_int_distribution<unsigned long> distribution(1ul, stringOne.size());
		unsigned long pos = distribution(g);
		stringOne.insert(pos, stringOne);
		if (rounds < 8) {
			pos = distribution(g);
			stringTwo.insert(pos, stringTwo);
		}
	}

	basic = "./BasicCSV " + stringOne + " " + stringTwo + " " + fileName.data();
	system(basic.c_str());

	efficient = "./EfficientCSV " + stringOne + " " + stringTwo + " " + fileName.data();
	system(efficient.c_str());

	std::shuffle(strOne.begin(), strOne.end(), g);
	std::shuffle(strTwo.begin(), strTwo.end(), g);

	stringOne = strOne;
	stringTwo = strTwo;

	for (int rounds = 1; rounds <= 8; ++rounds) {
		std::uniform_int_distribution<unsigned long> distribution(1ul, stringOne.size());
		unsigned long pos = distribution(g);
		stringOne.insert(pos, stringOne);
		if (rounds & 1) {
			std::uniform_int_distribution<unsigned long> oddDistribution(1ul, stringTwo.size());
			pos = oddDistribution(g);
			stringTwo.insert(pos, stringTwo);
		}
	}

	basic = "./BasicCSV " + stringOne + " " + stringTwo + " " + fileName.data();
	system(basic.c_str());

	efficient = "./EfficientCSV " + stringOne + " " + stringTwo + " " + fileName.data();
	system(efficient.c_str());

	stringOne = "ACACACTGACTACTGACTGGTGACTACTGACTGGACTGACTACTGACTGGTGACTACTGACTGG";
	stringTwo = "TATTATTATACGCTATTATACGCGACGCGGACGCGTATACGCTATTATACGCGACGCGGACGCG";

	basic = "./BasicCSV " + stringOne + " " + stringTwo + " " + fileName.data();
	system(basic.c_str());

	efficient = "./EfficientCSV " + stringOne + " " + stringTwo + " " + fileName.data();
	system(efficient.c_str());

	stringOne = "ACACACTGACTACTGACTGGTGACTACTGACTGGACTGACTACTGACTGGTGACTACTGACTGG";
	stringTwo = "TTATTATACGCGACGCGATTATACGCGACGCG";

	basic = "./BasicCSV " + stringOne + " " + stringTwo + " " + fileName.data();
	system(basic.c_str());

	efficient = "./EfficientCSV " + stringOne + " " + stringTwo + " " + fileName.data();
	system(efficient.c_str());

	strOne = "ACCA";
	strTwo = "GTTG";

	std::shuffle(strOne.begin(), strOne.end(), g);
	std::shuffle(strTwo.begin(), strTwo.end(), g);

	stringOne = strOne;
	stringTwo = strTwo;

	for (int rounds = 1; rounds <= 8; ++rounds) {
		std::uniform_int_distribution<unsigned long> distribution(1ul, stringOne.size());
		unsigned long pos = distribution(g);
		stringOne.insert(pos, stringOne);
		pos = distribution(g);
		stringTwo.insert(pos, stringTwo);
	}

	basic = "./BasicCSV " + stringOne + " " + stringTwo + " " + fileName.data();
	system(basic.c_str());

	efficient = "./EfficientCSV " + stringOne + " " + stringTwo + " " + fileName.data();
	system(efficient.c_str());

	strOne = "AGGA";
	strTwo = "CTTC";

	std::shuffle(strOne.begin(), strOne.end(), g);
	std::shuffle(strTwo.begin(), strTwo.end(), g);

	stringOne = strOne;
	stringTwo = strTwo;

	for (int rounds = 1; rounds <= 8; ++rounds) {
		std::uniform_int_distribution<unsigned long> distribution(1ul, stringOne.size());
		unsigned long pos = distribution(g);
		stringOne.insert(pos, stringOne);
		pos = distribution(g);
		stringTwo.insert(pos, stringTwo);
	}

	basic = "./BasicCSV " + stringOne + " " + stringTwo + " " + fileName.data();
	system(basic.c_str());

	efficient = "./EfficientCSV " + stringOne + " " + stringTwo + " " + fileName.data();
	system(efficient.c_str());

	strOne = "ATTA";
	strTwo = "GCCG";

	std::shuffle(strOne.begin(), strOne.end(), g);
	std::shuffle(strTwo.begin(), strTwo.end(), g);

	stringOne = strOne;
	stringTwo = strTwo;

	for (int rounds = 1; rounds <= 8; ++rounds) {
		std::uniform_int_distribution<unsigned long> distribution(1ul, stringOne.size());
		unsigned long pos = distribution(g);
		stringOne.insert(pos, stringOne);
		pos = distribution(g);
		stringTwo.insert(pos, stringTwo);
	}

	basic = "./BasicCSV " + stringOne + " " + stringTwo + " " + fileName.data();
	system(basic.c_str());

	efficient = "./EfficientCSV " + stringOne + " " + stringTwo + " " + fileName.data();
	system(efficient.c_str());

	strOne = "ACCA";
	strTwo = "GTTG";

	std::shuffle(strOne.begin(), strOne.end(), g);
	std::shuffle(strTwo.begin(), strTwo.end(), g);

	stringOne = strOne;
	stringTwo = strTwo;

	for (int rounds = 1; rounds <= 8; ++rounds) {
		std::uniform_int_distribution<unsigned long> distribution(1ul, stringOne.size());
		unsigned long pos = distribution(g);
		stringOne.insert(pos, stringOne);
		pos = distribution(g);
		stringTwo.insert(pos, stringTwo);
	}

	basic = "./BasicCSV " + stringOne + " " + stringTwo + " " + fileName.data();
	system(basic.c_str());

	efficient = "./EfficientCSV " + stringOne + " " + stringTwo + " " + fileName.data();
	system(efficient.c_str());

	strOne = "AGGA";
	strTwo = "CTTC";

	std::shuffle(strOne.begin(), strOne.end(), g);
	std::shuffle(strTwo.begin(), strTwo.end(), g);

	stringOne = strOne;
	stringTwo = strTwo;

	for (int rounds = 1; rounds <= 8; ++rounds) {
		std::uniform_int_distribution<unsigned long> distribution(1ul, stringOne.size());
		unsigned long pos = distribution(g);
		stringOne.insert(pos, stringOne);
		pos = distribution(g);
		stringTwo.insert(pos, stringTwo);
	}

	basic = "./BasicCSV " + stringOne + " " + stringTwo + " " + fileName.data();
	system(basic.c_str());

	efficient = "./EfficientCSV " + stringOne + " " + stringTwo + " " + fileName.data();
	system(efficient.c_str());

	strOne = "AAAA";
	strTwo = "GGGG";

	stringOne = strOne;
	stringTwo = strTwo;

	for (int rounds = 1; rounds <= 8; ++rounds) {
		std::uniform_int_distribution<unsigned long> distribution(1ul, stringOne.size());
		unsigned long pos = distribution(g);
		stringOne.insert(pos, stringOne);
		pos = distribution(g);
		stringTwo.insert(pos, stringTwo);
	}

	basic = "./BasicCSV " + stringOne + " " + stringTwo + " " + fileName.data();
	system(basic.c_str());

	efficient = "./EfficientCSV " + stringOne + " " + stringTwo + " " + fileName.data();
	system(efficient.c_str());

	strOne = "CCCC";
	strTwo = "TTTT";

	stringOne = strOne;
	stringTwo = strTwo;

	for (int rounds = 1; rounds <= 8; ++rounds) {
		std::uniform_int_distribution<unsigned long> distribution(1ul, stringOne.size());
		unsigned long pos = distribution(g);
		stringOne.insert(pos, stringOne);
		pos = distribution(g);
		stringTwo.insert(pos, stringTwo);
	}

	basic = "./BasicCSV " + stringOne + " " + stringTwo + " " + fileName.data();
	system(basic.c_str());

	efficient = "./EfficientCSV " + stringOne + " " + stringTwo + " " + fileName.data();
	system(efficient.c_str());

	strOne = "AAAA";
	strTwo = "TTTT";

	stringOne = strOne;
	stringTwo = strTwo;

	for (int rounds = 1; rounds <= 8; ++rounds) {
		std::uniform_int_distribution<unsigned long> distribution(1ul, stringOne.size());
		unsigned long pos = distribution(g);
		stringOne.insert(pos, stringOne);
		pos = distribution(g);
		stringTwo.insert(pos, stringTwo);
	}

	basic = "./BasicCSV " + stringOne + " " + stringTwo + " " + fileName.data();
	system(basic.c_str());

	efficient = "./EfficientCSV " + stringOne + " " + stringTwo + " " + fileName.data();
	system(efficient.c_str());

	strOne = "CCCC";
	strTwo = "GGGG";

	stringOne = strOne;
	stringTwo = strTwo;

	for (int rounds = 1; rounds <= 8; ++rounds) {
		std::uniform_int_distribution<unsigned long> distribution(1ul, stringOne.size());
		unsigned long pos = distribution(g);
		stringOne.insert(pos, stringOne);
		pos = distribution(g);
		stringTwo.insert(pos, stringTwo);
	}

	basic = "./BasicCSV " + stringOne + " " + stringTwo + " " + fileName.data();
	system(basic.c_str());

	efficient = "./EfficientCSV " + stringOne + " " + stringTwo + " " + fileName.data();
	system(efficient.c_str());

	return 0;
}