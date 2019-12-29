#include <fstream>
#include <iostream>
#include <regex>
#include <string>
#include <vector>
using namespace std;

string readFileToString(string filename) {
  ifstream file(filename);
  std::string content((std::istreambuf_iterator<char>(file)),
                      (std::istreambuf_iterator<char>()));
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
  printMatches(findPhoneNumbers(readFileToString(argv[1])));
  return 0;
}
