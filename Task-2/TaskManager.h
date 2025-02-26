#ifndef HACKSLASH_SIGSTP_TASK_2_TASKMANAGER_H
#define HACKSLASH_SIGSTP_TASK_2_TASKMANAGER_H
#include <cstdint>
#include <limits>
#include <string>
#include <vector>

using Priority = uint16_t;
using TaskId = uint64_t;
struct Task {
  Priority priority;
  TaskId id;
  std::string description;
};

// for implementing std::less<Task> used by std::upper_bound when searching for where to insert the new task
auto operator<(const Task &lhs, const Task &rhs) -> bool;

class TaskManager {
private:
  // the id of last task
  // Start with the maximum so that the first task gets 0 id
  // Since we are using unsigned int, overflow is defined
  TaskId lastTaskId = std::numeric_limits<TaskId>::max();
  // We are not using std::priority_queue as we need to access the underlying container
  // With std::priority_queue we can't access the underlying container to get the tasks as it is protected
  std::vector<Task> queue;

public:
  auto Queue(const Priority &priority, const std::string &description) -> TaskId;
  [[nodiscard]] auto getTasks() const -> std::vector<Task>;
  auto removeTask(const TaskId &taskId) -> bool;
  [[nodiscard]] auto highestPriority() const -> Task;
  auto isEmpty() -> bool;
  void clear();
};
#endif