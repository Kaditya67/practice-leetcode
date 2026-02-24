#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
using namespace std;

class TaskManager {
private:
    unordered_map<int, pair<int, int>> taskMap;  // Maps taskId to a pair (priority, userId)
    set<pair<int, int>, greater<pair<int, int>>> priorityQueue;  // Max-heap by priority

public:
    TaskManager(vector<vector<int>>& tasks) {
        for (const auto& task : tasks) {
            int userId = task[0];
            int taskId = task[1];
            int priority = task[2];
            taskMap[taskId] = {priority, userId};
            priorityQueue.insert({priority, taskId});
        }
    }

    void add(int userId, int taskId, int priority) {
        taskMap[taskId] = {priority, userId};
        priorityQueue.insert({priority, taskId});
    }

    void edit(int taskId, int newPriority) {
        int oldPriority = taskMap[taskId].first;
        priorityQueue.erase({oldPriority, taskId});
        taskMap[taskId].first = newPriority;
        priorityQueue.insert({newPriority, taskId});
    }

    void rmv(int taskId) {
        int priority = taskMap[taskId].first;
        priorityQueue.erase({priority, taskId});
        taskMap.erase(taskId);
    }

    int execTop() {
        if (priorityQueue.empty()) {
            return -1;
        }
        auto topTask = *priorityQueue.begin();
        int taskId = topTask.second;
        int userId = taskMap[taskId].second;
        priorityQueue.erase(priorityQueue.begin());
        taskMap.erase(taskId);
        return userId;
    }
};

int main() {
    // Initializing tasks
    vector<vector<int>> tasks = {
        {1, 101, 5},
        {2, 102, 8},
        {3, 103, 7}
    };
    
    // Creating TaskManager instance
    TaskManager taskManager(tasks);
    
    // Executing top task
    cout << "Executing task by user ID: " << taskManager.execTop() << endl;  // Should execute task with priority 8
    
    // Adding a new task
    taskManager.add(4, 104, 9);
    cout << "Executing task by user ID: " << taskManager.execTop() << endl;  // Should execute task with priority 9
    
    // Editing an existing task's priority
    taskManager.edit(103, 10);
    cout << "Executing task by user ID: " << taskManager.execTop() << endl;  // Should execute task with updated priority 10
    
    // Removing a task
    taskManager.rmv(104);
    cout << "Executing task by user ID: " << taskManager.execTop() << endl;  // Should execute task with priority 8
    
    return 0;
}
