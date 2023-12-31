#ifndef APP_H
#define APP_H

#include <iostream>
#include <string>
#include <vector>

#include "account.h"

using namespace std;

/*
*****************************
  This is where you start!
  However, make sure you do not not write all your code in a single file!
*****************************
*/

class App {
 private:
  static vector<Account *> account_address_vector_;

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
};

#endif  // APP_H
