#include "parser.h"
#include "solution.h"
#include <cmath>
#include <cstddef>
#include <cstdint>
#include <numeric>
#include <vector>

auto partTwo(const Instructions &instructions, const Puzzle &puzzle) -> uint64_t {
  std::vector<Node> currentNodes;
  // Start by finding all elements ending with a A
  for (const auto &node : puzzle) {
    if (node.first % 26 == 0) {
      currentNodes.emplace_back(node.first);
    }
  }
  std::vector<size_t> steps;
  steps.resize(currentNodes.size(), 0);
  for (size_t i = 0; i != currentNodes.size(); i++) {
    auto node = currentNodes[i];
    // This is similar to partOne(), we are just finding the step where the node ends with a "Z"
    for (; node % 26 != 25; steps[i]++) {
      switch (instructions[steps[i] % instructions.size()]) {
      case Instruction::Left:
        node = puzzle.at(node).left;
        break;
      case Instruction::Right:
        node = puzzle.at(node).right;
        break;
      }
    }
  }
  // Now the LCM of all the steps is the step where all the nodes will end with a "Z". So find that
  uint64_t lcm = 1;
  for (const auto &step : steps) {
    lcm = std::lcm(lcm, step);
  }
  return lcm;
}