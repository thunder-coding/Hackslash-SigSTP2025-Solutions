#include "../../utils/test.h"
#include "../parser.h"
#include "../solution.h"
#include <chrono>
#include <cstdlib>
#include <fstream>
#include <iostream>
auto main() -> int {
  const auto &start = std::chrono::system_clock::now();
  {
    ASSERT_EQ(parseNode("AAA"), 0);
    ASSERT_EQ(parseNode("ZZZ"), 26 * 26 * 25 + 26 * 25 + 25);
  }
  std::cout << "PASS: Node Parsing\n";
  {
    std::ifstream instructionsFile("Task-3/tests/example-1-instructions.txt");
    ASSERT(instructionsFile);
    const auto instructions = parseInstruction(instructionsFile);
    ASSERT_EQ(instructions.size(), 2);
    ASSERT_EQ(instructions[0], Instruction::Right);
    ASSERT_EQ(instructions[1], Instruction::Left);
  }
  {
    std::ifstream instructionsFile("Task-3/tests/example-2-instructions.txt");
    ASSERT(instructionsFile);
    const auto instructions = parseInstruction(instructionsFile);
    ASSERT_EQ(instructions.size(), 3);
    ASSERT_EQ(instructions[0], Instruction::Left);
    ASSERT_EQ(instructions[1], Instruction::Left);
    ASSERT_EQ(instructions[2], Instruction::Right);
  }
  std::cout << "PASS: Instruction Parsing\n";
  {
    std::ifstream puzzleFile("Task-3/tests/example-1-puzzle.txt");
    ASSERT(puzzleFile);
    const auto puzzle = parsePuzzle(puzzleFile);
    ASSERT_EQ(puzzle.size(), 7);
    ASSERT(puzzle.contains(parseNode("AAA")));
    ASSERT_EQ(puzzle.at(parseNode("AAA")).left, parseNode("BBB"));
    ASSERT_EQ(puzzle.at(parseNode("AAA")).right, parseNode("CCC"));
    ASSERT(puzzle.contains(parseNode("BBB")));
    ASSERT_EQ(puzzle.at(parseNode("BBB")).left, parseNode("DDD"));
    ASSERT_EQ(puzzle.at(parseNode("BBB")).right, parseNode("EEE"));
    ASSERT(puzzle.contains(parseNode("CCC")));
    ASSERT_EQ(puzzle.at(parseNode("CCC")).left, parseNode("ZZZ"));
    ASSERT_EQ(puzzle.at(parseNode("CCC")).right, parseNode("GGG"));
    ASSERT(puzzle.contains(parseNode("DDD")));
    ASSERT_EQ(puzzle.at(parseNode("DDD")).left, parseNode("DDD"));
    ASSERT_EQ(puzzle.at(parseNode("DDD")).right, parseNode("DDD"));
    ASSERT(puzzle.contains(parseNode("EEE")));
    ASSERT_EQ(puzzle.at(parseNode("EEE")).left, parseNode("EEE"));
    ASSERT_EQ(puzzle.at(parseNode("EEE")).right, parseNode("EEE"));
    ASSERT(puzzle.contains(parseNode("GGG")));
    ASSERT_EQ(puzzle.at(parseNode("GGG")).left, parseNode("GGG"));
    ASSERT_EQ(puzzle.at(parseNode("GGG")).right, parseNode("GGG"));
    ASSERT(puzzle.contains(parseNode("ZZZ")));
    ASSERT_EQ(puzzle.at(parseNode("ZZZ")).left, parseNode("ZZZ"));
    ASSERT_EQ(puzzle.at(parseNode("ZZZ")).right, parseNode("ZZZ"));
  }
  {
    std::ifstream puzzleFile("Task-3/tests/example-2-puzzle.txt");
    ASSERT(puzzleFile);
    const auto puzzle = parsePuzzle(puzzleFile);
    ASSERT_EQ(puzzle.size(), 3);
  }
  std::cout << "PASS: Puzzle Parsing\n";
  {
    std::ifstream instructionsFile("Task-3/tests/example-1-instructions.txt");
    ASSERT(instructionsFile);
    const auto instructions = parseInstruction(instructionsFile);
    std::ifstream puzzleFile("Task-3/tests/example-1-puzzle.txt");
    ASSERT(puzzleFile);
    const auto puzzle = parsePuzzle(puzzleFile);
    ASSERT_EQ(partOne(instructions, puzzle), 2);
  }
  {
    std::ifstream instructionsFile("Task-3/tests/example-2-instructions.txt");
    ASSERT(instructionsFile);
    const auto instructions = parseInstruction(instructionsFile);
    std::ifstream puzzleFile("Task-3/tests/example-2-puzzle.txt");
    ASSERT(puzzleFile);
    const auto puzzle = parsePuzzle(puzzleFile);
    ASSERT_EQ(partOne(instructions, puzzle), 6);
  }
  std::cout << "PASS: Puzzle Part 1\n";
  {
    std::ifstream instructionsFile("Task-3/tests/example-3-instructions.txt");
    ASSERT(instructionsFile);
    const auto instructions = parseInstruction(instructionsFile);
    std::ifstream puzzleFile("Task-3/tests/example-3-puzzle.txt");
    ASSERT(puzzleFile);
    const auto puzzle = parsePuzzle(puzzleFile);
    ASSERT_EQ(partTwo(instructions, puzzle), 6);
  }
  std::cout << "PASS: Puzzle Part 2\n";
  const auto &end = std::chrono::system_clock::now();
  std::cout << "Successfully passed all tests in " << std::chrono::duration<double>(end - start).count() * 1000
            << "ms\n";
  return EXIT_SUCCESS;
}