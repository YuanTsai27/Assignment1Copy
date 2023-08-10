#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>
#include <vector>

using namespace std;

class Account {
 private:
  std::string username_;
  std::string credit_amount_;
  int account_number_;
  static int next_account_number_;

 public:
  Account(const std::string &username, const std::string &credit_amount);
  std::string GetUsername() const;
  std::string GetCredit() const;
};


#endif  // ACCOUNT_H
