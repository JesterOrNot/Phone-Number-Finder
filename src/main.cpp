#include <exception>
#include <fstream>
#include <iostream>
#include <regex>
#include <string>
#include <vector>
using namespace std;

string readFileToString(string filename) {
  string content;
  try {
    ifstream file(filename);
    std::string content1((std::istreambuf_iterator<char>(file)),
                         (std::istreambuf_iterator<char>()));
    content = content1;
  } catch (exception e) {
    cout << "The file does not exist!\n";
    return "";
  }
  return content;
}

vector<string> findPhoneNumbers(string contents) {
  vector<string> matches;
  regex expression("\\d{3}-\\d{3}-\\d{4}");
  smatch match;
  while (regex_search(contents, match, expression)) {
    matches.push_back(match.str(0));
    contents = match.suffix().str();
  }
  return matches;
}
void printMatches(vector<string> matches) {
  for (auto item : matches) {
    cout << item << endl;
  }
}
int main(int argc, char **argv) {
  if (argc >= 2) {
    printMatches(findPhoneNumbers(readFileToString(argv[1])));
  } else {
    cout << "Please specify a file!\n";
  }
  return 0;
}
