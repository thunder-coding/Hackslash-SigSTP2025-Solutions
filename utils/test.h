// This header file was shamelessly stolen from one of my other projects.
// I hope stealing from myself isn't considered plagiarism
#ifndef HACKSLASH_SIGSTP_UTILS_H
#define HACKSLASH_SIGSTP_UTILS_H

// I use clang-tidy to enfore consistent coding style and catch bugs early.
// There is a .clang-tidy file which I use on my personal projects as well in case you wanna checkout :)
// NOLINTBEGIN(misc-include-cleaner);
#include <iostream>
#include <source_location>
// NOLINTEND(misc-include-cleaner);

#define ASSERT(expr)                                                                                                   \
  if (!(expr)) {                                                                                                       \
    std::cerr << std::source_location::current().file_name() << ":" << std::source_location::current().line() << ":"   \
              << std::source_location::current().column() << ": Assertion failed: " << #expr << "\n";                  \
    throw std::runtime_error("Assertion failed");                                                                      \
  }

#define ASSERT_NOT(expr) ASSERT(!(expr));

#define ASSERT_EQ(a, b) ASSERT((a) == (b));

#define ASSERT_NE(a, b) ASSERT((a) != (b));

#define ASSERT_LT(a, b) ASSERT((a) < (b));

#define ASSERT_LE(a, b) ASSERT((a) <= (b));

#define ASSERT_GT(a, b) ASSERT((a) > (b));

#define ASSERT_GE(a, b) ASSERT((a) >= (b));

#endif // HACKSLASH_SIGSTP_UTILS_H