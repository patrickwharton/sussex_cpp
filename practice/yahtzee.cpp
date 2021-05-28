#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <exception>
// #include <vector>

struct InputException : public std::exception {
  const char* what() const throw() {
    return "Incorrect number of inputs, must have filename only";
  }
};

int main(int argc, char const *argv[]) {

  // check inputs
  try {
    if (argc != 2) {
      throw InputException();
      // std::cout << "Incorrect number of inputs, must have filename only" << '\n';
      // return 1;
    }
  }
  catch (InputException& e) {
    std::cout << e.what() << '\n';
    return 1;
  }

  // declare input file stream
  std::ifstream inFile;

  // open file
  inFile.open(argv[1]);

  if (!inFile) {
    try {
      throw InputException();
    }
    catch (InputException& e) {
      std::cout << e.what() << '\n';
      return 1;
    }
  }

  // initiate vector
  // std::vector<int> vect;
  std::map<int, int> mapper;

  // iterate through lines of file
  std::string line;
  while (std::getline(inFile, line)) {
    int temp = stoi(line);
    // vect.push_back(temp);
    mapper[temp] += temp;
  }

  int max_score = 0;
  std::map<int, int>::iterator it;
  for (it = mapper.begin(); it != mapper.end(); it++) {
    if (it->second > max_score) {
      max_score = it->second;
    }
  }
  //
  // for (size_t i = 0; i < vect.size(); i++) {
  //   std::cout << vect.at(i) << '\n';
  // }

  // return max sum of grouped inputs
  std::cout << "Max Score is " << max_score << '\n';

  return max_score;
}
