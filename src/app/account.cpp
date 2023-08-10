#include "account.h"

#include <iostream>

#include "message.h"
#include "utils.h"

using namespace std;

Account::Account(const std::string &username, const std::string &credit_amount) {
  username_ = username;
  credit_amount_ = credit_amount;
  account_number_ = next_account_number_;
  next_account_number_ ++;
}

std::string Account::GetUsername() const { return username_; }

std::string Account::GetCredit() const { return credit_amount_; }

std::string Account::GetAccNumber() const { return account_amount_; }