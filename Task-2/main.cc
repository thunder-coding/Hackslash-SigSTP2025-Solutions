#include "TaskManager.h"
#include <cstdlib>
#include <iostream>
#include <string>
auto main() -> int {
  TaskManager taskManager;
  char chr;
  do {
    std::cout << "[A]dd task, [D]isplay tasks (priority-wise), [H]ighest Task, [R]emove Task by id, [C]lear, e[X]it: ";
    std::cin >> chr;
    switch (chr) {
    // [A]dd task
    case 'A':
    case 'a': {
      Priority priority;
      std::string description;
      std::cout << "Task Priority (0-65535): ";
      std::cin >> priority;
      // Eat the newline
      std::getline(std::cin, description);
      std::cout << "Task Description: ";
      std::getline(std::cin, description);
      TaskId const taskId = taskManager.Queue(priority, description);
      std::cout << "Successfully queued with task id " << taskId << ".\n";
    } break;
    // [D]isplay tasks (priority-wise)
    case 'D':
    case 'd': {
      if (taskManager.isEmpty()) {
        std::cout << "No tasks to do.\n"
                  << "Kindly queue some tasks and come again.\n";
      } else {
        for (const auto &task : taskManager.getTasks()) {
          std::cout << "TaskId: " << task.id << "\n"
                    << "Priority: " << task.priority << "\n"
                    << "Description: " << task.description << "\n\n";
        }
      }
    } break;
    // [H]ighest Task
    case 'H':
    case 'h': {
      if (taskManager.isEmpty()) {
        std::cout << "No tasks to do.\n"
                  << "Kindly queue some tasks and come again.\n";
      } else {
        const auto task = taskManager.getTasks().front();
        std::cout << "TaskId: " << task.id << "\n"
                  << "Priority: " << task.priority << "\n"
                  << "Description: " << task.description << "\n\n";
      }
    } break;
    // [R]emove Task by id
    case 'R':
    case 'r': {
      TaskId taskId;
      std::cout << "Enter the task id of the task you want to remove: ";
      std::cin >> taskId;
      if (taskManager.removeTask(taskId)) {
        std::cout << "Successfully removed task from the queue.\n";
      } else {
        std::cout << "Task not found in the queue. \n";
      }

    } break;
    // [C]lear task
    case 'C':
    case 'c': {
      taskManager.clear();
      std::cout << "Successfully cleared all tasks from the queue.\n";
    } break;
    // Catch this inside switch so that it does not default. The loop will be exited by the while condition
    case 'X':
    case 'x': {
    } break;
    default: {
      std::cout << "Invalid option '" << chr << "'. Please try again.\n";
    } break;
    }
  } while (chr != 'x' && chr != 'X');
  std::cout << "Thank you for using task manager. Hope to see you again.\n";
  return EXIT_SUCCESS;
}