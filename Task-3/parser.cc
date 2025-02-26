#include "parser.h"
#include <cstdio>
#include <istream>
#include <stdexcept>
#include <string>

// Helper macro to ensure that we are parsing correctly.
// throws an exception when something goes wrong during parsing.
//
#define MAKESURE_ELSE_ERROR_PARSING(x)                                                                                 \
  if (!(x)) {                                                                                                          \
    throw std::runtime_error("Unexpected error parsing puzzle file");                                                  \
  }

auto parseInstruction(std::istream &inp) -> Instructions {
  Instructions directions = {};
  // NOLINTNEXTLINE(bugprone-narrowing-conversions)
  for (char ch = inp.get(); !inp.eof(); ch = inp.get()) {
    switch (ch) {
    case 'L':
      directions.emplace_back(Instruction::Left);
      break;
    case 'R':
      directions.emplace_back(Instruction::Right);
      break;
    default:
      throw std::runtime_error("Invalid character encountered in instruction file");
    }
  }
  return directions;
}

auto parseNode(std::istream &inp) -> Node {
  Node node = 0;
  for (int i = 0; i < 3; i++) {
    node *= 26;
    node += (inp.get() - 'A');
  }
  return node;
}

auto parseNode(std::string str) -> Node {
  Node node = 0;
  for (int i = 0; i < 3; i++) {
    node *= 26;
    node += (str[i] - 'A');
  }
  return node;
}

// Use MAKESURE_ELSE_ERROR_PARSING to make sure we are actually parsing it correctly at each step, used like checkpoints
auto parsePuzzle(std::istream &inp) -> Puzzle {
  Puzzle nodes;
  // This is intentionally an int instead of a char, as inp.get() will return an EOF which is supposed to be greater
  // than 255.
  int chr;
  while (true) {
    Node const node = parseNode(inp);
    Node left;
    Node right;
    chr = inp.get();
    MAKESURE_ELSE_ERROR_PARSING(chr == ' ');
    chr = inp.get();
    MAKESURE_ELSE_ERROR_PARSING(chr == '=');
    chr = inp.get();
    MAKESURE_ELSE_ERROR_PARSING(chr == ' ');
    chr = inp.get();
    MAKESURE_ELSE_ERROR_PARSING(chr == '(');
    left = parseNode(inp);
    chr = inp.get();
    MAKESURE_ELSE_ERROR_PARSING(chr == ',');
    chr = inp.get();
    MAKESURE_ELSE_ERROR_PARSING(chr == ' ');
    right = parseNode(inp);
    chr = inp.get();
    MAKESURE_ELSE_ERROR_PARSING(chr == ')');
    chr = inp.get();
    NodeData const nodeData = {
        .left = left,
        .right = right,
    };
    nodes.emplace(node, nodeData);
    if (inp.eof()) {
      break;
    }
    MAKESURE_ELSE_ERROR_PARSING(chr == '\n');
  }
  return nodes;
}