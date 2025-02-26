#include "TaskManager.h"
#include <algorithm>
#include <string>
#include <vector>

auto operator<(const Task &lhs, const Task &rhs) -> bool { return lhs.priority < rhs.priority; }

auto TaskManager::Queue(const Priority &priority, const std::string &description) -> TaskId {
  Task const task = {
      .priority = priority,
      .id = ++lastTaskId,
      .description = description,
  };
  // modernize-use-ranges is forcing use of std::ranges::upper_bound, but it seems like it isn't as complete right now
  // as much as std::upper_bound NOLINTNEXTLINE(modernize-use-ranges)
  auto iter = std::upper_bound(this->queue.begin(), this->queue.end(), task);
  this->queue.insert(iter, task);
  return this->lastTaskId;
}

[[nodiscard]] auto TaskManager::getTasks() const -> std::vector<Task> { return this->queue; }

[[nodiscard]] auto TaskManager::highestPriority() const -> Task { return this->queue.front(); }

auto TaskManager::removeTask(const TaskId &taskId) -> bool {
  bool removed = false;
  for (auto iter = this->queue.begin(); iter != this->queue.end(); iter++) {
    if (iter->id == taskId) {
      removed = true;
      this->queue.erase(iter);
      break;
    }
  }
  return removed;
}

auto TaskManager::isEmpty() -> bool { return this->queue.empty(); }

void TaskManager::clear() { this->queue.clear(); }