#include <iostream>
#include <regex>
#include <string>
#include <vector>
using namespace std;

string readFileToString(string filename) {
  // WIP
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
int main() {
  vector<string> myVar = findPhoneNumbers("847-845-8577 224-565-6294 gretbrtbe rwhfyb");
  printMatches(myVar);
  return 0;
}
