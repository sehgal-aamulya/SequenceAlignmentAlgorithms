//
// Created by Aamulya Sehgal on 12/4/21.
//

#include <string>
#include <algorithm>
#include <random>
#include <array>
#include <fstream>

int main(int argc, char *argv[]) {
  const std::string_view fileName{(argc >= 2) ? argv[1] : "plotdata.csv"};

  std::ofstream fout{fileName.data()};

  std::string strOne{"ACTG"};
  std::string strTwo{"TACG"};

  std::random_device rd;
  std::mt19937 g(rd());

  std::string stringOne{strOne};
  std::string stringTwo{strTwo};

  fout << "type,problemsize,cputime,memoryusage" << std::flush;

  const std::string basic = "./BasicCSV";
  const std::string efficient = "./EfficientCSV";

  std::string cmd{" "};

  for (int generations = 1; generations <= 12; ++generations) {
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

    cmd = " ";
    cmd.append(stringOne).append(" ").append(stringTwo).append(" ").append(fileName);

    system((basic + cmd).c_str());
    system((efficient + cmd).c_str());
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

  cmd = " ";
  cmd.append(stringOne).append(" ").append(stringTwo).append(" ").append(fileName);

  system((basic + cmd).c_str());
  system((efficient + cmd).c_str());

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

  cmd = " ";
  cmd.append(stringOne).append(" ").append(stringTwo).append(" ").append(fileName);

  system((basic + cmd).c_str());
  system((efficient + cmd).c_str());

  stringOne = "ACACACTGACTACTGACTGGTGACTACTGACTGGACTGACTACTGACTGGTGACTACTGACTGG";
  stringTwo = "TATTATTATACGCTATTATACGCGACGCGGACGCGTATACGCTATTATACGCGACGCGGACGCG";

  cmd = " ";
  cmd.append(stringOne).append(" ").append(stringTwo).append(" ").append(fileName);

  system((basic + cmd).c_str());
  system((efficient + cmd).c_str());

  stringOne = "ACACACTGACTACTGACTGGTGACTACTGACTGGACTGACTACTGACTGGTGACTACTGACTGG";
  stringTwo = "TTATTATACGCGACGCGATTATACGCGACGCG";

  cmd = " ";
  cmd.append(stringOne).append(" ").append(stringTwo).append(" ").append(fileName);

  system((basic + cmd).c_str());
  system((efficient + cmd).c_str());

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

  cmd = " ";
  cmd.append(stringOne).append(" ").append(stringTwo).append(" ").append(fileName);

  system((basic + cmd).c_str());
  system((efficient + cmd).c_str());

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

  cmd = " ";
  cmd.append(stringOne).append(" ").append(stringTwo).append(" ").append(fileName);

  system((basic + cmd).c_str());
  system((efficient + cmd).c_str());

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

  cmd = " ";
  cmd.append(stringOne).append(" ").append(stringTwo).append(" ").append(fileName);

  system((basic + cmd).c_str());
  system((efficient + cmd).c_str());

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

  cmd = " ";
  cmd.append(stringOne).append(" ").append(stringTwo).append(" ").append(fileName);

  system((basic + cmd).c_str());
  system((efficient + cmd).c_str());

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

  cmd = " ";
  cmd.append(stringOne).append(" ").append(stringTwo).append(" ").append(fileName);

  system((basic + cmd).c_str());
  system((efficient + cmd).c_str());

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

  cmd = " ";
  cmd.append(stringOne).append(" ").append(stringTwo).append(" ").append(fileName);

  system((basic + cmd).c_str());
  system((efficient + cmd).c_str());

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

  cmd = " ";
  cmd.append(stringOne).append(" ").append(stringTwo).append(" ").append(fileName);

  system((basic + cmd).c_str());
  system((efficient + cmd).c_str());

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

  cmd = " ";
  cmd.append(stringOne).append(" ").append(stringTwo).append(" ").append(fileName);

  system((basic + cmd).c_str());
  system((efficient + cmd).c_str());

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

  cmd = " ";
  cmd.append(stringOne).append(" ").append(stringTwo).append(" ").append(fileName);

  system((basic + cmd).c_str());
  system((efficient + cmd).c_str());

  return 0;
}
