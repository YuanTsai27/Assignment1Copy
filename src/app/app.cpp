#include "app.h"

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

App::App() {
  // TODO implement
  int accountCounts = 0;
}

void App::CreateNewAccount(const std::string &username_input,
                           const std::string &credit_amount) {

  /* possible rejection scenarios
  - username less than 2 letters
  - account username already exists 
  - input credit not whole number (but account creation proceeds)
  */

  if (length(&username_input) < 2){
    string m  = Message::ERROR_CREATE_ACCOUNT_SHORT_USERNAME.GetMessage({username_input, credit_amount});
  }
  else if { //account already exists


  } 
  else {
    //successful account creation
  username_ = username_input;
  credit_amount_ = credit_amount;
  
  if (floor(std::stod(str)) != std::stod(str)){
    credit_amount_ = "0"; // if input credit amount is not a whole number
  }

  App this(username_input,credit_amount, 0);
  string m  = Message::ACCOUNT_CREATED.GetMessage({username_input, credit_amount});
  }

  cout << m << endl; 
  
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
