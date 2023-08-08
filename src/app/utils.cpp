
#include "utils.h"

#include <algorithm>
using namespace std;

/*
*****************************
  DO NOT MODIFY EXISTING METHODS
  However, you are welcome to add additional methods.
*****************************
*/

std::string Utils::WHITESPACE = " \n\r\t\f\v";

std::string Utils::TrimString(const std::string &str) {
  return TrimStringRight(TrimStringLeft(str));
}

std::string Utils::TrimStringLeft(const std::string &str) {
  size_t start = str.find_first_not_of(WHITESPACE);
  return (start == std::string::npos) ? "" : str.substr(start);
}

std::string Utils::TrimStringRight(const std::string &str) {
  size_t end = str.find_last_not_of(WHITESPACE);
  return (end == std::string::npos) ? "" : str.substr(0, end + 1);
}

std::string Utils::GetFirstWord(const std::string &str) {
  return SplitString(str).at(0);
}

std::string Utils::GetUppercaseUnderscore(const std::string &str) {
  string result = GetUppercase(str);
  std::replace(result.begin(), result.end(), '-', '_');
  return result;
}

std::string Utils::GetLowercase(const std::string &str) {
  string result = str;
  std::transform(result.begin(), result.end(), result.begin(), ::tolower);
  return result;
}

std::string Utils::GetUppercase(const std::string &str) {
  string result = str;
  std::transform(result.begin(), result.end(), result.begin(), ::toupper);
  return result;
}

std::vector<std::string> Utils::SplitString(const std::string &str) {
  vector<string> result;
  string trimmed = TrimString(str);
  size_t start = 0;
  size_t end = trimmed.find_first_of(WHITESPACE);
  while (end != string::npos) {
    result.push_back(trimmed.substr(start, end - start));
    start = end + 1;
    end = trimmed.find_first_of(WHITESPACE, start);
  }
  result.push_back(trimmed.substr(start));
  return result;
}

bool Utils::StartsWith(const std::string &str, const std::string &prefix) {
  return str.size() >= prefix.size() &&
         str.compare(0, prefix.size(), prefix) == 0;
}

bool Utils::StartsWithIgnoreCase(const std::string &str,
                                 const std::string &prefix) {
  return str.size() >= prefix.size() &&
         GetLowercase(str).compare(0, prefix.size(), GetLowercase(prefix)) == 0;
}

bool Utils::Contains(const std::string &str, const std::string &s,
                     bool ignore_case) {
  string outer = ignore_case ? GetLowercase(str) : str;
  string inner = ignore_case ? GetLowercase(s) : s;
  return outer.find(inner) != std::string::npos;
}

bool Utils::IsInteger(const std::string &str) {
  // Allow negative numbers
  if (str.length() > 0 && str[0] == '-') {
    return IsInteger(str.substr(1));
  }
  return !str.empty() && std::find_if(str.begin(), str.end(), [](char c) {
                           return !isdigit(c);
                         }) == str.end();
}
