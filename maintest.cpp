
//
// #include "TaskManager.h"
// int function(const int& i) {
//     int j = i;
//     j += 100;
//     return j ;
// }
//
// bool applay(const int& i) {
//     return  (i < 100);
// }
//
// int main() {
//     TaskManager tm;
//
//     // Create some tasks
//     Task task1(1, TaskType::Meeting, "Discuss project goals");
//     Task task2(2, TaskType::Development, "Implement feature X");
//     Task task3(3, TaskType::Testing, "Test feature X");
//     Task task4(4, TaskType::Documentation, "Write docs for feature X");
//     Task task5(5, TaskType::Research, "Explore new tech");
//
//     // Assign tasks to employees
//     tm.assignTask("Alice", task1);
//     tm.assignTask("Bob", task2);
//     tm.assignTask("Alice", task3);
//     tm.assignTask("Charlie", task4);
//     tm.assignTask("Bob", task5);
//     tm.assignTask("Alice", task2);
//     tm.printAllEmployees();
//     std::cout << std::endl;
//
//     tm.printAllTasks();
//     std::cout << std::endl;
//
//     // Complete a task and verify it no longer appears
//     tm.completeTask("Alice");
//     tm.completeTask("Alice");
//     tm.completeTask("Alice");
//     tm.printAllTasks();
//     std::cout << std::endl;
//
//     tm.bumpPriorityByType(TaskType::Documentation, 2);
//
//     tm.printTasksByType(TaskType::Documentation);
//     std::cout << std::endl;
//
//     tm.printTasksByType(TaskType::Research);
//     std::cout << std::endl;
//     tm.printAllEmployees();
//     std::cout << std::endl;
//     return true;
//     }
