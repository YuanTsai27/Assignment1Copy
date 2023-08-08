
#include "message.h"

#include <iostream>

using namespace std;

/*
*****************************
  DO NOT MODIFY THIS FILE
*****************************
*/

const Message Message::ACCOUNT_CREATED(
    "Account successfully created for '%s' with starting credit of $%s.");

const Message Message::PRINT_ACCOUNTS_HEADER("There %s %s account%s%s");
const Message Message::PRINT_ACCOUNT_ENTRY(
    "*) '%s' has $%s credit and has completed %s order%s (%s cancelled)");

const Message Message::TOP_UP_SUCCESSFUL(
    "Successfully topped up '%s' with $%s. Current balance is $%s.");

const Message Message::USERNAME_NOT_FOUND(
    "Cannot find an account with username '%s'.");

const Message Message::ERROR_CREATE_ACCOUNT_DUPLICATE_USERNAME(
    "Cannot create account for '%s' with $%s. Account already exists.");
const Message Message::ERROR_CREATE_ACCOUNT_SHORT_USERNAME(
    "Cannot create account for '%s' with $%s. Username must be at least 2 "
    "characters long.");
const Message Message::ERROR_CREATE_ACCOUNT_NEGATIVE_CREDIT(
    "Cannot have a negative initial credit. Using $0 instead.");
const Message Message::ERROR_CREATE_ACCOUNT_INVALID_CREDIT(
    "$'%s' is an invalid credit amount. Using $0 instead.");

const Message Message::ERROR_TOPUP_NEGATIVE_CREDIT(
    "Cannot have a negative top up amount. Credit has not changed.");
const Message Message::ERROR_TOPUP_INVALID_CREDIT(
    "$'%s' is an invalid top up amount. Credit has not changed.");

const Message Message::ORDER_STARTED(
    "Order #%s initiated for '%s'. Please add your items.");
const Message Message::ORDER_CANCELLED("Order #%s has been cancelled.");
const Message Message::ORDER_SUBMITTED(
    "Order #%s has been submitted with %s item%s.");
const Message Message::ORDER_SUBMIT_INSUFFICIENT_CREDIT(
    "Insufficient credit to complete order #%s with %s item%s.");

const Message Message::DESCRIPTION_BURGER("burger '%s' (%s)");
const Message Message::DESCRIPTION_DRINK("drink %s");
const Message Message::DESCRIPTION_COMBO(
    "combo burger '%s' (%s) with drink %s");
const Message Message::DESCRIPTION_COMBO_ALTERNATIVE("%s with %s");

const Message Message::ADDED_BURGER(
    "Added burger '%s' (%s) to order #%s for $%s.");
const Message Message::ADDED_DRINK("Added drink %s to order #%s for $%s.");
const Message Message::ADDED_COMBO(
    "Added combo burger '%s' (%s) with drink %s to order #%s for $%s.");
const Message Message::ADDED_COMBO_ALTERNATIVE(
    "Added combo %s with %s to order #%s for $%s.");

const Message Message::INVALID_COMMAND_ORDER_OPEN(
    "Invalid command. You cannot do this while an order is open.");
const Message Message::INVALID_COMMAND_ORDER_CLOSED(
    "Invalid command. You cannot do this without an open order.");

const Message Message::PRINT_TOTAL_SALES(
    "Total burger sales: %s, Total drink sales: %s");

const Message Message::COMMAND_NOT_FOUND(
    "Command '%s' not found. Run 'help' for the list of available commands.");
const Message Message::WRONG_ARGUMENT_COUNT(
    "Incorrect number of arguments for %s.");
const Message Message::END("Program ended.");

Message::Message(const std::string &msg) { this->msg_ = msg; }

std::string Message::GetMessage() const { return GetMessage({}); }

std::string Message::GetMessage(std::initializer_list<std::string> args) const {
  std::string result = msg_;
  for (const string &arg : args) {
    size_t pos = result.find("%s");
    if (pos != std::string::npos) {
      result.replace(pos, 2, arg);
    }
  }
  return result;
}

void Message::PrintMessage() const { PrintMessage({}); }

void Message::PrintMessage(std::initializer_list<std::string> args) const {
  cout << GetMessage(args) << endl;
}
