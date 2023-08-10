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

int App::num_accounts_ = 0; // initialisation of the static field
std::vector<int> App::credit_balance_vector_ = {1};
std::vector<string> usernames_vector_ = {"hello"};


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
  string m  = Message::ACCOUNT_CREATED.GetMessage({username_input, credit_amount}); //initialisating m to print
  bool isUsernameDuplicated = false;

  //process to check if account is duplicated


  if (username_input.length() < 2){
      m  = Message::ERROR_CREATE_ACCOUNT_SHORT_USERNAME.GetMessage({username_input, credit_amount}); //changing m to duplicate msg
  } else if (isUsernameDuplicated == true){
      m = Message::ERROR_CREATE_ACCOUNT_DUPLICATE_USERNAME.GetMessage({username_input, credit_amount});
  } else{

    //usernames_vector_.push_back(username_input);

      if (floor(std::stod(credit_amount)) != std::stod(credit_amount)){ //checking if credit input is a whole number
        credit_balance_vector_.push_back(0); //if input credit amount is not a whole number
      } else {
        credit_balance_vector_.push_back(std::stod(credit_amount));
      }

      //cout << credit_balance_vector_.at(0) << endl;
      cout << credit_balance_vector_.at(num_accounts_ + 1) << endl;
      cout << usernames_vector_.at(0) << endl;
      
      num_accounts_ ++;

  }
  
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
