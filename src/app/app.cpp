#include "app.h"
#include "account.h"

#include <string>
#include <memory>
#include <vector>
#include <cmath>

#include <iostream>

#include "message.h"
#include "utils.h"

using namespace std;

/*
*****************************
  This is where you start!
  However, make sure you do not not write all your code in a single file!
*****************************
*/

int App::num_accounts_ = 0; //initialisation of static fields
std::vector<std::string> App::usernames_vector_ = {};
std::vector<int> App::credit_balance_vector_ = {};

App::App() {
  // TODO implement

}


void App::CreateNewAccount(const std::string &username_input,
                           const std::string &credit_amount){
  /* possible rejection scenarios
  - username less than 2 letters
  - account username already exists 
  - input credit not whole number (but account creation proceeds)
  */

  
  string m1  = "initialisation"; //initialisating messages to print
  string m2 = "initialisation";
  bool isUsernameDuplicated = false;
  bool isCreditInvalid = false;
  int credit_int = 0; //setting credit number to 0
  std::string username_lowercased = Utils::GetLowercase(username_input);

  /*
  hierachy of error messages
  1. username less than 2 letters
  2. username already exists
  3. credit is negative
  4. credit is invalid (has non-numbers)
  
  */

  // process to check if input credit is valid

  for (int i = 0; i < credit_amount.length(); i++) {
    if ((i == 0 && credit_amount[i] == '-')){
      isCreditInvalid = true;
      m1 = Message::ERROR_CREATE_ACCOUNT_NEGATIVE_CREDIT.GetMessage({to_string(credit_int)});
      break;
    } else if ( credit_amount[i] < '0' || credit_amount[i] > '9') {
      isCreditInvalid = true;
      m1 = Message::ERROR_CREATE_ACCOUNT_INVALID_CREDIT.GetMessage({credit_amount, to_string(credit_int)});
      break;
      }
    }

  if (!isCreditInvalid){
        credit_int = std::stoi(credit_amount); // initiallising credit number for print output
  }

  //process to check if account is duplicated, using static integer of number of accounts made.
  if (num_accounts_ > 0){
    for (int i = 0; i < num_accounts_; i++) {
      if(usernames_vector_.at(i) == username_lowercased){
        isUsernameDuplicated = true;
      }
    }
  }

  if (username_input.length() < 2){
      m2  = Message::ERROR_CREATE_ACCOUNT_SHORT_USERNAME.GetMessage({username_lowercased, to_string(credit_int)}); //changing m to duplicate msg
  } else if (isUsernameDuplicated){
      m2 = Message::ERROR_CREATE_ACCOUNT_DUPLICATE_USERNAME.GetMessage({username_lowercased, to_string(credit_int)});
  } else {

      credit_balance_vector_.push_back(credit_int); //registering usernames and credit into account static vectors
      usernames_vector_.push_back(username_lowercased);

      m2 = Message::ACCOUNT_CREATED.GetMessage({username_lowercased, to_string(credit_int)});
      
      num_accounts_ ++;
  }

  //printing relevant outputs
  if (isCreditInvalid){
      cout << m1 << endl;
  }
      
  cout << m2 << endl;
  
  
}

void App::TopUpAccount(const std::string &username_input,
                       const std::string &additional_credit) {
  // TODO implement

  bool does_username_exist = false;
  bool is_credit_invalid = false; 

  int index;
  int existing_balance_int;
  int new_credit_amount;
  std::string username_lowercased = Utils::GetLowercase(username_input);

  string m = Message::USERNAME_NOT_FOUND.GetMessage({username_lowercased});;

  /*hierachy of error messages
  1. username not found
  2. negative topup
  3. invalid topup
  */

  for (int i = 0; i < num_accounts_; i++){
        if(usernames_vector_.at(i) == username_lowercased){
            does_username_exist = true;
            index = i;

            break;
          }
  }

  if (does_username_exist){ //if username is valid, proceed to topup credit check

      for (int i = 0; i < additional_credit.length(); i++) {
        if ((i == 0 && additional_credit[i] == '-')){
          is_credit_invalid = true;
          m = Message::ERROR_TOPUP_NEGATIVE_CREDIT.GetMessage({});
          break;
        } else if ( additional_credit[i] < '0' || additional_credit[i] > '9') {
          is_credit_invalid = true;
          m = Message::ERROR_TOPUP_INVALID_CREDIT.GetMessage({additional_credit});
          break;
          }
      }
    
  } 

  if (!is_credit_invalid && does_username_exist){
    existing_balance_int = credit_balance_vector_.at(index);
    new_credit_amount = existing_balance_int + stoi(additional_credit);
  
    credit_balance_vector_.at(index) = new_credit_amount;

    m = Message::TOP_UP_SUCCESSFUL.GetMessage({username_lowercased, additional_credit, to_string(new_credit_amount)});
  }


  /*

  // checking if there are non-numbers in additional credit string
  for (int i = 0; i < additional_credit.length(); i++) {
        if ( additional_credit[i] < '0' || additional_credit[i] > '9') {
            letters_in_credit = true;
            m = Message::ERROR_TOPUP_INVALID_CREDIT.GetMessage({additional_credit});
            break;
        }
  }

  // checking if additional credit topup is negative or a non-integer
  if ((stod(additional_credit) < 0 && !letters_in_credit)){
    negative_credit = true;
    m = Message::ERROR_TOPUP_NEGATIVE_CREDIT.GetMessage({});
  } else {
    if (floor(std::stod(additional_credit)) != std::stod(additional_credit)){
      credit_not_int = true;
      m = Message::ERROR_TOPUP_INVALID_CREDIT.GetMessage({additional_credit});
    }
  }
  */

  cout << m << endl;
}

void App::PrintAccounts() const {
  // TODO implement

  string a, b, c, d, e;
  string m1, m2;

  int credit_balance;
  std::string username;
  int orders_completed = 0;
  int cancelled_orders = 0;

  b = to_string(num_accounts_);

  // setting a
  if (num_accounts_ == 1){
    a = "is";
    c = "";
  } else{
    a = "are";
    c = "s";
  }

  // setting c

  if (num_accounts_ > 0){
    d = ":";
  } else {
    d = ".";
  }

  m1 = Message::PRINT_ACCOUNTS_HEADER.GetMessage({a, b, c, d});
  cout << m1 << endl;

  for (int i = 0; i < num_accounts_; i++ ){
    credit_balance = credit_balance_vector_.at(i);
    username = usernames_vector_.at(i);
    if (orders_completed == 1){
      e = "";
    } else{
      e = "s";
    }
    m2 = Message::PRINT_ACCOUNT_ENTRY.GetMessage({username, to_string(credit_balance), to_string(orders_completed), e, to_string(cancelled_orders) });
    cout << m2 << endl;
  }

}

void App::StartNewOrder(const std::string &username) {
  // TODO implement
}

void App::CancelCurrentOrder() {
  // TODO implement
}

void App::SubmitCurrentOrder() {
  // TODO implement
}

void App::AddBurgerToCurrentOrder(const std::string &burger_name,
                                  const std::string &size) {
  // TODO implement
}

void App::AddDrinkToCurrentOrder(const std::string &drink_type) {
  // TODO implement
}

void App::AddComboToCurrentOrder(const std::string &burger_name,
                                 const std::string &size,
                                 const std::string &drink_type) {
  // TODO implement
}

void App::PrintAllSales() const {
  // TODO implement
}
