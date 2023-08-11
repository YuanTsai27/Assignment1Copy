#ifndef APP_H
#define APP_H

#include "account.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
*****************************
  This is where you start!
  However, make sure you do not not write all your code in a single file!
*****************************
*/


class App {
 private:

  //std::string username_;
  //std::string credit_amount_;
  static int num_accounts_;
  static std::vector<std::string> usernames_vector_;
  static std::vector<int> credit_balance_vector_;



 public:
  App();
  void CreateNewAccount(const std::string &username,
                        const std::string &credit_amount);
  void TopUpAccount(const std::string &username,
                    const std::string &additional_credit);
  void PrintAccounts() const;
  void StartNewOrder(const std::string &username);
  void CancelCurrentOrder();
  void SubmitCurrentOrder();
  void AddBurgerToCurrentOrder(const std::string &burger_name,
                               const std::string &size);
  void AddDrinkToCurrentOrder(const std::string &drink_type);
  void AddComboToCurrentOrder(const std::string &burger_name,
                              const std::string &size,
                              const std::string &drink_type);
  void PrintAllSales() const;
 
  static int GetNumAccounts() {
        return num_accounts_;
  }

  static const std::vector<std::string>& GetUsernamesVector() {
      return usernames_vector_;
  }

  static const std::vector<int>& GetCreditBalanceVector() {
      return credit_balance_vector_;
  }
  
};

 

#endif  // APP_H
