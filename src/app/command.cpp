
#include "command.h"

#include <iostream>

#include "message.h"
#include "utils.h"
using namespace std;

/*
*****************************
  DO NOT MODIFY THIS FILE
*****************************
*/

const Command Command::NEW_ACCOUNT(
    "NEW_ACCOUNT", 2,
    "Create a new account for <USERNAME> with specified <CREDIT>");
const Command Command::TOP_UP_CREDIT(
    "TOP_UP_CREDIT", 2,
    "Top up credit for <USERNAME> by specified <ADDITIONAL_CREDIT>");
const Command Command::PRINT_ACCOUNTS("PRINT_ACCOUNTS", 0,
                                      "Print all accounts in the system");

const Command Command::NEW_ORDER("NEW_ORDER", 1,
                                 "Start a new order for <USERNAME>");
const Command Command::CANCEL_ORDER("CANCEL_ORDER", 0,
                                    "Cancel the current order");
const Command Command::SUBMIT_ORDER("SUBMIT_ORDER", 0,
                                    "Submit the current order");

const Command Command::ADD_BURGER("ADD_BURGER", 2,
                                  "Add a burger to the current order with "
                                  "specified <BURGER_NAME> and <SIZE>");
const Command Command::ADD_DRINK(
    "ADD_DRINK", 1,
    "Add a drink to the current order with specified <DRINK_TYPE>");
const Command Command::ADD_COMBO(
    "ADD_COMBO", 3,
    "Add a combo to the current order with specified <BURGER_NAME>, <SIZE> and "
    "<DRINK_TYPE>");
const Command Command::PRINT_ALL_SALES("PRINT_ALL_SALES", 0,
                                       "Print all sales data");

const Command Command::HELP("HELP", 0, "Print usage");
const Command Command::EXIT("EXIT", 0, "Exit the application");
const Command Command::INVALID("_____INVALID____", 0,
                               "Placeholder for INVALID Command value");

std::initializer_list<Command> Command::commands = {
    Command::NEW_ACCOUNT,     Command::TOP_UP_CREDIT, Command::PRINT_ACCOUNTS,
    Command::NEW_ORDER,       Command::CANCEL_ORDER,  Command::SUBMIT_ORDER,
    Command::ADD_BURGER,      Command::ADD_DRINK,     Command::ADD_COMBO,
    Command::PRINT_ALL_SALES, Command::HELP,          Command::EXIT};

Command::Command(const std::string &name, int num_args,
                 const std::string &message) {
  this->name_ = name;
  this->num_args_ = num_args;
  this->message_ = message;
}

Command::Command(const std::string &name, int num_args,
                 const std::string &message,
                 const std::vector<std::string> &option_prompts) {
  this->name_ = name;
  this->num_args_ = num_args;
  this->message_ = message;
  this->option_prompts_ = option_prompts;
}

std::string Command::GetName() const { return name_; }

bool Command::HasArguments() const { return num_args_ > 0; }

int Command::GetNumArgs() const { return num_args_; }

bool Command::HasOptions() const { return option_prompts_.size() > 0; }

int Command::GetNumOptions() const { return option_prompts_.size(); }

std::string Command::GetMessage() const { return message_; }

std::string Command::GetOptionPrompt(int index) const {
  return option_prompts_[index];
}

bool Command::operator==(const Command &other) const {
  return name_ == other.name_;
}

bool Command::operator!=(const Command &other) const {
  return !(*this == other);
}

std::string Command::GetHelp() {
  std::string help;
  for (const Command &command : commands) {
    int num_args = command.GetNumArgs();
    help += command.GetName() + "\t";
    help += "[" + (num_args == 0 ? "no" : to_string(command.GetNumArgs())) +
            " argument" + (num_args == 1 ? "" : "s") + "]";
    help += "\t";
    help += command.GetMessage() + "\n";
  }
  return help;
}

bool Command::IsValidCommand(const std::string &cmd_input) {
  return Find(cmd_input) != Command::INVALID;
}

const Command &Command::Find(const std::string &cmd_input) {
  string cmd = Utils::GetFirstWord(cmd_input);
  cmd = Utils::GetUppercaseUnderscore(cmd);

  for (const Command &command : commands) {
    if (command.GetName() == cmd) {
      return command;
    }
  }

  return Command::INVALID;
}
