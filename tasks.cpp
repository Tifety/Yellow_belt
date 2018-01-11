#include <stdlib.h>
#include <map>
#include <iostream>
#include <tuple>

using namespace std;

enum class TaskStatus {
    NEW,
    IN_PROGRESS,
    TESTING,
    DONE
};

using TasksInfo = map<TaskStatus, int>;

class TeamTasks {
    public: 
        const TasksInfo& GetPersonTasksInfo (const string& person) const {
            return tracker.at(person);
        }
        void AddNewTask (const string& person) {
        tracker[person][TaskStatus::NEW]++;
        }
        tuple <TasksInfo, TasksInfo> PerformPersonTasks (const string& person, int task_count) {
            TasksInfo changes;
            for (auto item : tracker[person]) {
                    changes[item.first] = item.second;
                    }
        }
    private:
        map <string, TasksInfo> tracker; 
};

void PrintTasksInfo (TasksInfo tasks_info) {
    cout << tasks_info[TaskStatus::NEW] << "new tasks, "
         << tasks_info[TaskStatus::IN_PROGRESS] << "tasks in progress, " 
         << tasks_info[TaskStatus::TESTING] << "tasks are being tested" 
         << " and " << tasks_info[TaskStatus::DONE] << "tasks are done \n";
}

int main () {
TasksInfo tasks;
tasks[TaskStatus::NEW]=1;
tasks[TaskStatus::IN_PROGRESS]=2;
tasks[TaskStatus::TESTING]=3;
tasks[TaskStatus::DONE]=4;
PrintTasksInfo(tasks);
TeamTasks track;
track.AddNewTask("I");
track.AddNewTask("I");
PrintTasksInfo(track.GetPersonTasksInfo("I"));

}
