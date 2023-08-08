
#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <vector>

/*
*****************************
  DO NOT MODIFY EXISTING METHODS
  However, you are welcome to add additional methods.
*****************************
*/

class Utils {
 private:
  static std::string WHITESPACE;

 public:
  static std::string TrimString(const std::string &str);
  static std::string TrimStringLeft(const std::string &str);
  static std::string TrimStringRight(const std::string &str);
  static std::string GetFirstWord(const std::string &str);
  static std::string GetUppercaseUnderscore(const std::string &str);
  static std::string GetUppercase(const std::string &str);
  static std::string GetLowercase(const std::string &str);
  static std::vector<std::string> SplitString(const std::string &str);
  static bool StartsWith(const std::string &str, const std::string &prefix);
  static bool StartsWithIgnoreCase(const std::string &str,
                                   const std::string &prefix);
  static bool Contains(const std::string &str, const std::string &s,
                       bool ignore_case);
  static bool IsInteger(const std::string &str);
};

#endif  // UTILS_H
