#ifndef HACKSLASH_SIGSTP_TASK_3_PARSER_H
#define HACKSLASH_SIGSTP_TASK_3_PARSER_H
#include <cstdint>
#include <istream>
#include <string>
#include <unordered_map>
#include <vector>

// Using uint16_t as 3 characters have only around 15 bits of entropy, can be easily fit in 16-bit integer, should also
// make the comparisions much faster
using Node = uint16_t;

struct NodeData {
  Node left, right;
};

enum class Instruction : bool {
  Left = false,
  Right = true,
};

// Store as an unordered_map to make lookups constant time
using Puzzle = std::unordered_map<Node, NodeData>;
using Instructions = std::vector<Instruction>;

// Helper function to parse a node from a file streamm
auto parseNode(std::istream &inp) -> Node;
// Helper function to parse a node from a string
auto parseNode(std::string str) -> Node;
// Parse the puzzle from the file
auto parsePuzzle(std::istream &inp) -> Puzzle;
// Parse the instructiosn from the file
auto parseInstruction(std::istream &inp) -> Instructions;
#endif