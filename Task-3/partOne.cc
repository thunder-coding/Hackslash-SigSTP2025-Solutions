#include "parser.h"
#include "solution.h"
#include <cstdint>

auto partOne(const Instructions &instructions, const Puzzle &puzzle) -> uint64_t {
  uint64_t steps = 0;
  for (Node currentNode = parseNode("AAA"); currentNode != parseNode("ZZZ"); steps++) {
    switch (instructions[steps % instructions.size()]) {
    case Instruction::Left:
      currentNode = puzzle.at(currentNode).left;
      break;
    case Instruction::Right:
      currentNode = puzzle.at(currentNode).right;
      break;
    }
  }
  // steps actually does contain the correct number of steps since we are incrementing it when we check for the last
  // condition where currentNode != parseNode("ZZZ").
  return steps;
}