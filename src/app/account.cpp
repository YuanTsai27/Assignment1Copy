#include "account.h"

#include <iostream>

#include "message.h"
#include "utils.h"

using namespace std;

int Account::next_account_number_ = 0;

Account::Account(const std::string &username,
                 const std::string &credit_amount) {
  username_ = username;
  credit_amount_ = credit_amount;
  account_number_ = next_account_number_;
  next_account_number_++;
}

// testing

std::string Account::GetUsername() const { return username_; }

std::string Account::GetCredit() const { return credit_amount_; }

int Account::GetAccNumber() const { return account_number_; }

void Account::TopUpCredit(std::string &credit_amount) {
  int new_credit_amount = stoi(credit_amount_) + stoi(credit_amount);
  credit_amount_ = to_string(new_credit_amount);
}

Account::~Account() {}