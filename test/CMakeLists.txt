
option(TASK_1_TEST_CASES "Run the test cases for Task 1" ON)
option(TASK_2_TEST_CASES "Run the test cases for Task 2" OFF)
option(TASK_3_TEST_CASES "Run the test cases for Task 3" OFF)

# Add the test executable and link it with the library targets
add_executable(tester_app ./tester.cpp)

# Include the "src" directory to access the source files
target_include_directories(tester_app PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../src)

# Link the subdirectory targets to the test executable
target_link_libraries(tester_app SrcTarget SrcAppSupportTarget)

# Add the tests to CTest for Task 1
if(TASK_1_TEST_CASES)
  add_test(NAME Task_1_ZeroAccounts COMMAND tester_app 1)
  add_test(NAME Task_1_CreateNewAccount COMMAND tester_app 2)
  add_test(NAME Task_1_CreateNewAccountWithHeader COMMAND tester_app 3)
  add_test(NAME Task_1_CreateTwoNewAccountsWithoutPrint COMMAND tester_app 4)
  add_test(NAME Task_1_CreateTwoNewAccountsWithPrint COMMAND tester_app 5)
  add_test(NAME Task_1_CreateNewAccountNegative COMMAND tester_app 9)
  add_test(NAME Task_1_TopUpValid COMMAND tester_app 14)
  add_test(NAME Task_1_TopUpNegativeWithoutPrintAccounts COMMAND tester_app 16)
  add_test(NAME Task_1_TopUpUsernameNotFound COMMAND tester_app 17)
endif()

# Add the tests to CTest for Task 2 
if(TASK_2_TEST_CASES)
  add_test(NAME Task_2_StartNewOrderUsernameExists COMMAND tester_app 19)
  add_test(NAME Task_2_CancelOrder COMMAND tester_app 21)
  add_test(NAME Task_2_NewOrderOpenInvalidCommands COMMAND tester_app 23)
  add_test(NAME Task_2_MultiOrdersDifferentUsers COMMAND tester_app 25)
  add_test(NAME Task_2_MultiOrdersDifferentUsersSavedOrderNumbers COMMAND tester_app 27)
endif()

# Add the tests to CTest for Task 3
if(TASK_3_TEST_CASES)
  add_test(NAME Task_3_AddBurger COMMAND tester_app 29)
  add_test(NAME Task_3_AddDrinksSecondOrder COMMAND tester_app 32)
  add_test(NAME Task_3_AddCombos COMMAND tester_app 33)
  add_test(NAME Task_3_NotEnoughCredit COMMAND tester_app 35)
  add_test(NAME Task_3_TopUpBeforeOrderToHaveEnoughCredit COMMAND tester_app 37)
  add_test(NAME Task_3_PrintAllSalesOneOrder COMMAND tester_app 38)
endif()

