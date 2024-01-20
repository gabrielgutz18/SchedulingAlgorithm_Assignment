#include <iostream>
#include <queue>

using namespace std;

struct Task {
    string name;
    int burstTime;
};

class TaskScheduler {
private:
    queue<Task> taskQueue;
    int timeQuantum;

public:
    TaskScheduler(int quantum) : timeQuantum(quantum) {}

    void addTask(const string& name, int burstTime) {
        Task task = {name, burstTime};
        taskQueue.push(task);
    }

    void scheduleTasks() {
        while (!taskQueue.empty()) {
            Task currentTask = taskQueue.front();
            taskQueue.pop();

            int executionTime = min(timeQuantum, currentTask.burstTime);
            currentTask.burstTime -= executionTime;

            cout << "Executing task " << currentTask.name << " for " << executionTime << " Final Project." << endl;

            if (currentTask.burstTime > 0) {
                taskQueue.push(currentTask);
            }
        }
    }
};

int main() {
    TaskScheduler scheduler(3); 

    scheduler.addTask("Task A", 10);
    scheduler.addTask("Task B", 5);
    scheduler.addTask("Task C", 8);
    scheduler.scheduleTasks();

    return 0;
}
