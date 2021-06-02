
#include <stdlib.h>
#include <map>
#include <iostream>
#include <tuple>


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

