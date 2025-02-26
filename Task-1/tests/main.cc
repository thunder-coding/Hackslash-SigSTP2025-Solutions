#include "../../utils/test.h"
#include "../ATM.h"
#include <chrono>
#include <cstdlib>
#include <iostream>

auto main() -> int {
  const auto &start = std::chrono::system_clock::now();

  {
    ATM atm;
    atm.deposit({33, 23, 5, 0, 34});
    ASSERT_EQ(atm.balanceNotes().size(), 5);
    ASSERT_EQ(atm.balanceNotes()[0], 33);
    ASSERT_EQ(atm.balanceNotes()[1], 23);
    ASSERT_EQ(atm.balanceNotes()[2], 5);
    ASSERT_EQ(atm.balanceNotes()[3], 0);
    ASSERT_EQ(atm.balanceNotes()[4], 34);
    atm.deposit({854, 219, 467, 982, 137});
    ASSERT_EQ(atm.balanceNotes().size(), 5);
    ASSERT_EQ(atm.balanceNotes()[0], 887);
    ASSERT_EQ(atm.balanceNotes()[1], 242);
    ASSERT_EQ(atm.balanceNotes()[2], 472);
    ASSERT_EQ(atm.balanceNotes()[3], 982);
    ASSERT_EQ(atm.balanceNotes()[4], 171);
  }
  {
    ATM atm;
    atm.deposit({0, 0, 0, 0, 1});
    const auto withdrawnNotes = atm.withdraw(100);
    ASSERT_EQ(withdrawnNotes.size(), 1);
    ASSERT_EQ(withdrawnNotes[0], -1);
    ASSERT_EQ(atm.balanceNotes().size(), 5);
    ASSERT_EQ(atm.balanceNotes()[0], 0);
    ASSERT_EQ(atm.balanceNotes()[1], 0);
    ASSERT_EQ(atm.balanceNotes()[2], 0);
    ASSERT_EQ(atm.balanceNotes()[3], 0);
    ASSERT_EQ(atm.balanceNotes()[4], 1);
  }
  std::cout << "PASS: Money Deposit\n";
  {
    ATM atm;
    atm.deposit({0, 0, 0, 0, 1});
    const auto withdrawnNotes = atm.withdraw(100);
    ASSERT_EQ(withdrawnNotes.size(), 1);
    ASSERT_EQ(withdrawnNotes[0], -1);
    ASSERT_EQ(atm.balanceNotes().size(), 5);
    ASSERT_EQ(atm.balanceNotes()[0], 0);
    ASSERT_EQ(atm.balanceNotes()[1], 0);
    ASSERT_EQ(atm.balanceNotes()[2], 0);
    ASSERT_EQ(atm.balanceNotes()[3], 0);
    ASSERT_EQ(atm.balanceNotes()[4], 1);
  }
  {
    ATM atm;
    atm.deposit({0, 0, 0, 0, 1});
    atm.deposit({0, 2, 3, 0, 1});
    const auto withdrawnNotes = atm.withdraw(500);
    ASSERT_EQ(withdrawnNotes.size(), 5);
    ASSERT_EQ(withdrawnNotes[0], 0);
    ASSERT_EQ(withdrawnNotes[1], 0);
    ASSERT_EQ(withdrawnNotes[2], 0);
    ASSERT_EQ(withdrawnNotes[3], 0);
    ASSERT_EQ(withdrawnNotes[4], 1);
    ASSERT_EQ(atm.balanceNotes().size(), 5);
    ASSERT_EQ(atm.balanceNotes()[0], 0);
    ASSERT_EQ(atm.balanceNotes()[1], 2);
    ASSERT_EQ(atm.balanceNotes()[2], 3);
    ASSERT_EQ(atm.balanceNotes()[3], 0);
    ASSERT_EQ(atm.balanceNotes()[4], 1);
  }
  {
    ATM atm;
    atm.deposit({0, 2, 3, 0, 2});
    const auto withdrawnNotes = atm.withdraw(800);
    ASSERT_EQ(withdrawnNotes.size(), 1);
    ASSERT_EQ(withdrawnNotes[0], -1);
  }
  {
    ATM atm;
    atm.deposit({0, 3, 0, 0, 0});
    const auto withdrawnNotes = atm.withdraw(60);
    ASSERT_EQ(withdrawnNotes.size(), 1);
    ASSERT_EQ(withdrawnNotes[0], -1);
  }
  std::cout << "PASS: Money Withdrawl\n";
  const auto &end = std::chrono::system_clock::now();
  std::cout << "Successfully passed all tests in " << std::chrono::duration<double>(end - start).count() * 1000
            << "ms\n";
  return EXIT_SUCCESS;
}