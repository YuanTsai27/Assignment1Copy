#ifndef MESSAGE_H
#define MESSAGE_H

#include <initializer_list>
#include <string>

/*
*****************************
  DO NOT MODIFY THIS FILE
*****************************
*/

class Message {
 private:
  std::string msg_;

 public:
  static const Message ACCOUNT_CREATED;

  static const Message PRINT_ACCOUNTS_HEADER;
  static const Message PRINT_ACCOUNT_ENTRY;

  static const Message USERNAME_NOT_FOUND;

  static const Message ERROR_CREATE_ACCOUNT_DUPLICATE_USERNAME;
  static const Message ERROR_CREATE_ACCOUNT_SHORT_USERNAME;
  static const Message ERROR_CREATE_ACCOUNT_NEGATIVE_CREDIT;
  static const Message ERROR_CREATE_ACCOUNT_INVALID_CREDIT;

  static const Message TOP_UP_SUCCESSFUL;
  static const Message ERROR_TOPUP_NEGATIVE_CREDIT;
  static const Message ERROR_TOPUP_INVALID_CREDIT;

  static const Message ORDER_STARTED;
  static const Message ORDER_CANCELLED;
  static const Message ORDER_SUBMITTED;
  static const Message ORDER_SUBMIT_INSUFFICIENT_CREDIT;

  static const Message DESCRIPTION_BURGER;
  static const Message DESCRIPTION_DRINK;
  static const Message DESCRIPTION_COMBO;
  static const Message DESCRIPTION_COMBO_ALTERNATIVE;

  static const Message ADDED_BURGER;
  static const Message ADDED_DRINK;
  static const Message ADDED_COMBO;
  static const Message ADDED_COMBO_ALTERNATIVE;

  static const Message INVALID_COMMAND_ORDER_OPEN;
  static const Message INVALID_COMMAND_ORDER_CLOSED;

  static const Message PRINT_TOTAL_SALES;

  static const Message COMMAND_NOT_FOUND;
  static const Message WRONG_ARGUMENT_COUNT;
  static const Message END;

  Message(const std::string &msg);
  std::string GetMessage() const;
  std::string GetMessage(std::initializer_list<std::string> args) const;
  void PrintMessage() const;
  void PrintMessage(std::initializer_list<std::string> args) const;
};

#endif  // MESSAGE_H
