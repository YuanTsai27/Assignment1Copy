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
  bool CreditHasLetters = false;
  int credit_int = 0; //setting credit number to 0
  std::string username_lowercased = Utils::GetLowercase(username_input);

  // process to check if input credit is valid

  for (int i = 0; i < credit_amount.length(); i++) {
        if ( credit_amount[i] < '0' || credit_amount[i] > '9') {
            CreditHasLetters = true;
            isCreditInvalid = true;
            m1 = Message::ERROR_CREATE_ACCOUNT_INVALID_CREDIT.GetMessage({credit_amount, to_string(credit_int)});
            break;
        }
  }

  if (!CreditHasLetters){
      if ((floor(std::stod(credit_amount)) != std::stod(credit_amount)) || (std::stod(credit_amount) < 0)){ 
        isCreditInvalid = true;
        credit_int = 0;

        if (std::stod(credit_amount) < 0){ //setting appropriate message regarding invalid credit 
          m1 = Message::ERROR_CREATE_ACCOUNT_NEGATIVE_CREDIT.GetMessage({to_string(credit_int)});
        } else {
          m1 = Message::ERROR_CREATE_ACCOUNT_INVALID_CREDIT.GetMessage({credit_amount, to_string(credit_int)});
        }
        
      }else{
        credit_int = std::stoi(credit_amount); // initiallising credit number for print output
      }
  }

  //process to check if account is duplicated, using static integer of number of accounts made.
  if (num_accounts_ > 0){
    for (int i = 0; i < num_accounts_; i++) {
      if(usernames_vector_.at(i) == username_input){
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

  //need to check if account exists
}

void App::PrintAccounts() const {
  // TODO implement

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
