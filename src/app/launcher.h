
#ifndef LAUNCHER_H
#define LAUNCHER_H

#include <string>

#include "app.h"
#include "command.h"

/*
*****************************
  DO NOT MODIFY THIS FILE
*****************************
*/

class Launcher {
 private:
  App app_;
  static std::string COMMAND_PREFIX;

 public:
  Launcher();
  void Start();
  bool ProcessCommand(const std::string &cmd);
  void PrintBanner() const;
  std::string GetCommandPrefix() const;
};

#endif  // LAUNCHER_H
