#include "parser.h"
#include "solution.h"
#include <cstdlib>
#include <fstream>
#include <iostream>

auto main() -> int {
  std::ifstream instructionsFile("Task-3/instructions.txt");
  if (!instructionsFile) {
    std::cerr << "Error opening instructions.txt\n";
    return EXIT_FAILURE;
  }
  std::ifstream puzzleFile("Task-3/puzzle.txt");
  if (!puzzleFile) {
    std::cerr << "Error opening puzzle.txt\n";
    return EXIT_FAILURE;
  }
  const auto instructions = parseInstruction(instructionsFile);
  const auto puzzle = parsePuzzle(puzzleFile);
  std::cout << "Part 1 Solution: " << partOne(instructions, puzzle) << '\n';
  std::cout << "Part 2 Solution: " << partTwo(instructions, puzzle) << '\n';
  return EXIT_SUCCESS;
}