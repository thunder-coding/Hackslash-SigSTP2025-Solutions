#include "ATM.h"
#include <cassert>
#include <cstddef>
#include <vector>

ATM::ATM() { assert(notes.size() == notesCount.size()); }

void ATM::deposit(std::vector<int> banknotesCount) {
  assert(banknotesCount.size() == notes.size());
  for (size_t i = 0; i < notes.size(); i++) {
    notesCount[i] += banknotesCount[i];
  }
}

auto ATM::balanceNotes() const -> const std::vector<int> & { return this->notesCount; }

auto ATM::balance() const -> int {
  int balance = 0;
  for (size_t i = 0; i < notes.size(); i++) {
    balance += notesCount[i] * notes[i];
  }
  return balance;
}
auto ATM::withdraw(int amount) -> std::vector<int> {
  std::vector<int> withdrawalNotesCount;
  withdrawalNotesCount.resize(notes.size(), 0);
  // i is the index + 1 of the note we are at.
  // We start by the largest one and prioritize giving larger notes
  for (size_t i = notes.size(); i != 0; i--) {
    withdrawalNotesCount[i - 1] = amount / notes[i - 1];
    if (withdrawalNotesCount[i - 1] > notesCount[i - 1]) {
      return {-1};
    }
    amount -= withdrawalNotesCount[i - 1] * notes[i - 1];
  }
  // We could not figure out how to give the amount the user requested
  if (amount != 0) {
    return {-1};
  }
  for (size_t i = 0; i != notes.size(); i++) {
    this->notesCount[i] -= withdrawalNotesCount[i];
  }
  return withdrawalNotesCount;
}