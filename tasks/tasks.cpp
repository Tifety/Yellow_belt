//#ufljf
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


 /*       tuple <TasksInfo, TasksInfo> PerformPersonTasks (const string& person, int task_count) {
            TasksInfo changes;
            TasksInfo update;
            TasksInfo old;
            changes[TaskStatus::NEW]=
        }
        }

   */
    private:
        map <string, TasksInfo> tracker;
};

int Changes (int number_tasks, int & to_update) {
    int answer;
    if (number_tasks > to_update) {
        answer = to_update;
        to_update = 0;
        cout << "in func " << to_update << endl;
    } else {
        answer = number_tasks;
        to_update -= number_tasks;
        cout << "in func" <<  to_update << endl;
    }
    return answer;
}

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
//tasks[TaskStatus::DONE]=4;
PrintTasksInfo(tasks);
TeamTasks track;
track.AddNewTask("I");
track.AddNewTask("I");
PrintTasksInfo(track.GetPersonTasksInfo("I"));
cout << tasks[TaskStatus::NEW] << endl;
int a = 5;
cout << Changes (3, a) << " "<< a << endl; 
cout << a << endl;
a = 3;
cout << Changes (5, a) << endl;
cout << a << endl;
a = 0;
cout << Changes (0, a) << endl;
cout << a << endl;
a = 8;
cout << Changes (0, a) << endl;
cout << a << endl;
a =0 ;
cout << Changes (7, a) << endl;
cout << a << endl;
a = 4;
cout << Changes (4, a) << endl;
cout << a << endl;
}
