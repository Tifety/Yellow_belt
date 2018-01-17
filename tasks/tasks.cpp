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

class TeamTasks {
    public: 
        const TasksInfo& GetPersonTasksInfo (const string& person) const {
            return tracker.at(person);
        }
        void AddNewTask (const string& person) {
        tracker[person][TaskStatus::NEW]++;
        }


       tuple <TasksInfo, TasksInfo> PerformPersonTasks (const string& person, int task_count) {
            TasksInfo update;
            TasksInfo old;
            update[TaskStatus::IN_PROGRESS] = Changes(tracker[person][TaskStatus::NEW], task_count);
            update[TaskStatus::TESTING]= Changes(tracker[person][TaskStatus::IN_PROGRESS], task_count);
            update[TaskStatus::DONE] = Changes(tracker[person][TaskStatus::TESTING], task_count);
            old[TaskStatus::NEW] = tracker[person][TaskStatus::NEW] - update[TaskStatus::IN_PROGRESS];
           old[TaskStatus::IN_PROGRESS]= tracker[person][TaskStatus::IN_PROGRESS] - update[TaskStatus::TESTING];
           old[TaskStatus::TESTING]= tracker[person][TaskStatus::TESTING] - update[TaskStatus::DONE];
            tracker[person][TaskStatus::NEW]= old[TaskStatus::NEW];
            tracker[person][TaskStatus::IN_PROGRESS]=update[TaskStatus::IN_PROGRESS]+old[TaskStatus::IN_PROGRESS];
            tracker[person][TaskStatus::TESTING]=update[TaskStatus::TESTING]+old[TaskStatus::TESTING];
            tracker[person][TaskStatus::DONE]+=update[TaskStatus::DONE];
            cout << update[TaskStatus::IN_PROGRESS] << " update in progress and tasks to renew is " << task_count << endl;
            cout << update[TaskStatus::TESTING] << " update in testing  and tasks to renew is " << task_count << endl;
            cout << update[TaskStatus::DONE] << " update in done  and tasks to renew is " << task_count << endl;
            cout << old[TaskStatus::NEW] << "stays in new" << endl;
            cout << old[TaskStatus::IN_PROGRESS] << "stays in progess" << endl;
            cout << old[TaskStatus::TESTING] << "stays in testing" << endl;
                return tie (update, old);

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
//tasks[TaskStatus::DONE]=4;
PrintTasksInfo(tasks);
TeamTasks track;
track.AddNewTask("I");
track.AddNewTask("I");
track.AddNewTask("I");
track.AddNewTask("I");
track.AddNewTask("I");
track.AddNewTask("I");
track.AddNewTask("I");
PrintTasksInfo(track.GetPersonTasksInfo("I"));
cout << tasks[TaskStatus::NEW] << endl;
int a = 5;
// trly
cout << "=====================" << endl;
tuple <TasksInfo, TasksInfo> tr = track.PerformPersonTasks("I", 4);
cout << "=========================" << endl;
PrintTasksInfo(track.GetPersonTasksInfo("I"));
cout << "===========================" << endl;
TasksInfo update;
TasksInfo stay;
update[TaskStatus::IN_PROGRESS] = Changes(tasks[TaskStatus::NEW], a);
cout << update[TaskStatus::IN_PROGRESS] << " update in progress and tasks to renew is " << a << endl;
update[TaskStatus::TESTING]= Changes(tasks[TaskStatus::IN_PROGRESS], a);
cout << update[TaskStatus::TESTING] << " update in testing  and tasks to renew is " << a << endl;
update[TaskStatus::DONE] = Changes (tasks[TaskStatus::TESTING], a);
cout << update[TaskStatus::DONE] << " update in done  and tasks to renew is " << a << endl;
/* cout << Changes (3, a) << " "<< a << endl; 
cout << a << endl;
a = 3;
cout << Changes (tasks[TaskStatus::NEW], a) << endl;
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
cout << a << endl;*/
}
