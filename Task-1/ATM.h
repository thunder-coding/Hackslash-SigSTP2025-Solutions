#ifndef HACKSLASH_SIGSTP_TASK_1_ATM_H
#define HACKSLASH_SIGSTP_TASK_1_ATM_H
#include <vector>

class ATM {
private:
  std::vector<int> notesCount = {0, 0, 0, 0, 0};

public:
  // NOLINTNEXTLINE(misc-non-private-member-variables-in-classes)
  const std::vector<int> notes = {20, 50, 100, 200, 500};
  ATM();
  // Deposit bank notes inside the ATM
  void deposit(std::vector<int> banknotesCount);
  // Get how many bank notes are there inside the ATM
  [[nodiscard]] auto balanceNotes() const -> const std::vector<int> &;
  // Get total ATM balance
  [[nodiscard]] auto balance() const -> int;
  // Withdraw money from the ATM
  // If the ATM is not able to give that money.
  // On successful invocation, returns count of each of the notes disbursed.
  // On any error it will return a { -1 }
  auto withdraw(int amount) -> std::vector<int>;
};
#endif