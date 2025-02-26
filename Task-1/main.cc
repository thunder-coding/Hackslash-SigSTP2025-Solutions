#include "ATM.h"
#include <cstdlib>
#include <iostream>
#include <vector>

auto main() -> int {
  ATM atm;
  std::cout << "Welcome to the ATM!\n";
  char chr;
  do {
    std::cout << "[D]eposit, [W]ithdraw, [B]alance, e[X]it: ";
    std::cin >> chr;
    switch (chr) {
    case 'D':
    case 'd': {
      std::vector<int> depositedNotesCount;
      depositedNotesCount.resize(atm.notes.size());
      for (size_t i = 0; i < atm.notes.size(); i++) {
        std::cout << "Enter the number of $" << atm.notes[i] << " notes: ";
        std::cin >> depositedNotesCount[i];
      }
      atm.deposit(depositedNotesCount);
    } break;
    case 'W':
    case 'w': {
      int amount;
      std::cout << "Enter Amount: $";
      std::cin >> amount;
      const auto withdrawnNotes = atm.withdraw(amount);
      if (withdrawnNotes.size() == 1 && withdrawnNotes[0] == -1) {
        std::cout << "Unable to process your transaction at this moment.\n"
                  << "It seems that the ATM machine wasn't able to dispense notes for your amount.\n"
                  << "You can try withdrawing another amount.\n";
      } else {
        std::cout << "You just withdrew $" << amount << ". You should have received:\n";
        for (size_t i = 0; i < atm.notes.size(); i++) {
          std::cout << withdrawnNotes[i] << "x $" << atm.notes[i] << " notes\n";
        }
      }
    } break;
    case 'b':
    case 'B': {
      std::cout << "ATM balance is: $" << atm.balance() << "\n";
      std::cout << "Notes with the ATM:\n";
      for (size_t i = 0; i < atm.notes.size(); i++) {
        std::cout << atm.balanceNotes()[i] << "x $" << atm.notes[i] << " notes\n";
      }
    } break;
    // Catch this inside switch so that it does not default. The loop will be exited by the while condition
    case 'x':
    case 'X': {
    } break;
    default: {
      std::cout << "Invalid option. Please try again.\n";
    } break;
    }
  } while (chr != 'x' && chr != 'X');
  std::cout << "Thankyou for visiting our ATM!\n";
  return EXIT_SUCCESS;
}