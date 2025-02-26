#include "../../utils/test.h"
#include "../TaskManager.h"
#include <chrono>
#include <cstdlib>
#include <iostream>
auto main() -> int {
  const auto &start = std::chrono::system_clock::now();
  TaskManager taskManager;
  // Make sure that TaskManager is empty by default
  ASSERT(taskManager.isEmpty());
  ASSERT_EQ(taskManager.getTasks().size(), 0);
  ASSERT_EQ(taskManager.Queue(367, "Task 1"), 0);
  ASSERT_EQ(taskManager.highestPriority().id, 0);
  ASSERT_EQ(taskManager.Queue(367, "Task 2"), 1);
  ASSERT_EQ(taskManager.highestPriority().id, 0);
  ASSERT_EQ(taskManager.Queue(360, "Task 3"), 2);
  ASSERT_EQ(taskManager.getTasks().size(), 3);
  ASSERT_EQ(taskManager.getTasks()[0].id, 2);
  ASSERT_EQ(taskManager.getTasks()[0].description, "Task 3");
  ASSERT_EQ(taskManager.getTasks()[0].priority, 360);
  ASSERT_EQ(taskManager.getTasks()[1].id, 0);
  ASSERT_EQ(taskManager.getTasks()[1].description, "Task 1");
  ASSERT_EQ(taskManager.getTasks()[1].priority, 367);
  ASSERT_EQ(taskManager.getTasks()[2].id, 1);
  ASSERT_EQ(taskManager.getTasks()[2].description, "Task 2");
  ASSERT_EQ(taskManager.getTasks()[2].priority, 367);
  std::cout << "PASS: Queue Task\n";
  ASSERT_EQ(taskManager.highestPriority().id, 2);
  ASSERT_EQ(taskManager.highestPriority().description, "Task 3");
  std::cout << "PASS: Highest Priority\n";
  ASSERT(taskManager.removeTask(2));
  ASSERT_EQ(taskManager.getTasks().size(), 2);
  ASSERT_EQ(taskManager.getTasks()[0].id, 0);
  ASSERT_EQ(taskManager.getTasks()[1].id, 1);
  std::cout << "PASS: Remove Task\n";
  taskManager.clear();
  ASSERT(taskManager.isEmpty());
  std::cout << "PASS: Clear Tasks\n";
  const auto &end = std::chrono::system_clock::now();
  std::cout << "Successfully passed all tests in " << std::chrono::duration<double>(end - start).count() * 1000
            << "ms\n";
  return EXIT_SUCCESS;
}