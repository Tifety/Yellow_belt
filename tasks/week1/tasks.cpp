/* Yandex course "Yellow Belt". Task week 1 simulating simple task tracker.
 * There are some mens with number of tasks. 4 status in tasks NEW, IN_PROGRESS, TESTING, DONE. Adding 1 task per command Add. 
 * Migrating in method Perform is for updating tasks. Number of update is given to function. Updating is simply top-down. 
 * There is a nuber od tasks to uodate. First updating NEW, adding updated tasks to IN_PROGRESS and so on. No double-updating. 
 * PerformPersonTasks return two maps. One with updated tsks and one with not updated unsolved; Nulls should not be in maps. 
*/

#include <stdlib.h>
#include <map>
#include <iostream>
#include <tuple>


using namespace std;

// for saving tasks status
enum class TaskStatus {
    NEW,
    IN_PROGRESS,
    TESTING,
    DONE
};

// this is a map saiving tasks count of each status. For one person in next usage.
using TasksInfo = map<TaskStatus, int>;

// Rude function to decide how to update tasks. Need smth more nice.
int Changes (int number_tasks, int & to_update) {
    int answer;
    if (number_tasks > to_update) {
        answer = to_update;
        to_update = 0;
//        cout << "in func " << to_update << endl;
    } else {
        answer = number_tasks;
        to_update -= number_tasks;
//        cout << "in func" <<  to_update << endl;
    }
    return answer;
}

// Deleting stasus with 0 tasks in it.
void Check_zero (TasksInfo & work) {
    for (auto item : work) {
        if (item.second == 0) work.erase(item.first);
    }
}


class TeamTasks {
public:
    // just get
    const TasksInfo& GetPersonTasksInfo (const string& person) const {
        return tracker.at(person);
    }

    // add new tasks by +1 to ststus NEW; 
    void AddNewTask (const string& person) {
        tracker[person][TaskStatus::NEW]++;
    }

// updating tasks. It will nice to use "for ", but cause of enum class I cant do it. Don't kniw how to. 
    tuple <TasksInfo, TasksInfo> PerformPersonTasks (const string& person, int task_count) {
        // update is for map of tasks that been updated in fucntion 
        // and old is for tasks that didn't change their status 
        TasksInfo update;
        TasksInfo old;
        // update starts with IN_PROGRESS cause for new NEW tasks there is ADD
        update[TaskStatus::IN_PROGRESS] = Changes(tracker[person][TaskStatus::NEW], task_count);
        if (task_count != 0)
            update[TaskStatus::TESTING]= Changes(tracker[person][TaskStatus::IN_PROGRESS], task_count);
        if (task_count != 0)
            update[TaskStatus::DONE] = Changes(tracker[person][TaskStatus::TESTING], task_count);
        Check_zero (update); // deleting zero elements
        // i is simple, old is tasks we have in stutus minus updated tasks
        // and there no DONE in old
        old[TaskStatus::NEW] = tracker[person][TaskStatus::NEW] - update[TaskStatus::IN_PROGRESS];
        old[TaskStatus::IN_PROGRESS]= tracker[person][TaskStatus::IN_PROGRESS] - update[TaskStatus::TESTING];
        old[TaskStatus::TESTING]= tracker[person][TaskStatus::TESTING] - update[TaskStatus::DONE];
        Check_zero (old); // deleting zero elements
        // fix updates in "main" map
        tracker[person][TaskStatus::NEW]= old[TaskStatus::NEW];
        tracker[person][TaskStatus::IN_PROGRESS]=update[TaskStatus::IN_PROGRESS]+old[TaskStatus::IN_PROGRESS];
        tracker[person][TaskStatus::TESTING]=update[TaskStatus::TESTING]+old[TaskStatus::TESTING];
        tracker[person][TaskStatus::DONE]+=update[TaskStatus::DONE];
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
    TeamTasks track;
    track.AddNewTask("Il");
    track.AddNewTask("Iv");
    track.AddNewTask("Iv");
    track.AddNewTask("Iv");
    cout << "Ils tasks ";
    PrintTasksInfo(track.GetPersonTasksInfo("Il"));
    cout << "Ivs tasks ";
    PrintTasksInfo(track.GetPersonTasksInfo("Iv"));
    TasksInfo updated;
    TasksInfo old;

    tie (updated, old)= track.PerformPersonTasks("Iv", 2);
    cout << "Up Iv tasks ";
    PrintTasksInfo(updated);
    cout << "Ol Iv tasks ";
    PrintTasksInfo(old);


    tie (updated, old)= track.PerformPersonTasks("Iv", 2);
    cout << "Up Iv tasks ";
    PrintTasksInfo(updated);
    cout << "Ol Iv tasks ";
    PrintTasksInfo(old);
    /*  cout << tasks[TaskStatus::NEW] << endl;
    int a = 5;
    // trly
    TasksInfo updated;
    TasksInfo old;
    cout << "=====================" << endl;
    tie (updated, old)= track.PerformPersonTasks("I", 4);
    cout << "=========================" << endl;
    PrintTasksInfo(track.GetPersonTasksInfo("I"));
    cout << "===========================" << endl;
    Check_zero (updated);
    for (auto item : updated) {
        cout << item.second << endl;
    }
    cout << "Updated: " ; PrintTasksInfo(updated);
    //cout << "Stay: " ; PrintTasksInfo(old);
    //TasksInfo update;
    TasksInfo stay;
    update[TaskStatus::IN_PROGRESS] = Changes(tasks[TaskStatus::NEW], a);
    cout << update[TaskStatus::IN_PROGRESS] << " update in progress and tasks to renew is " << a << endl;
    update[TaskStatus::TESTING]= Changes(tasks[TaskStatus::IN_PROGRESS], a);
    cout << update[TaskStatus::TESTING] << " update in testing  and tasks to renew is " << a << endl;
    update[TaskStatus::DONE] = Changes (tasks[TaskStatus::TESTING], a);
    cout << update[TaskStatus::DONE] << " update in done  and tasks to renew is " << a << endl;
     cout << Changes (3, a) << " "<< a << endl;
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
