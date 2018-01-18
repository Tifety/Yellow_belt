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

void Check_zero (TasksInfo & work) {
    for (auto item : work) {
        if (item.second == 0) work.erase(item.first);
    }
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
            if (task_count != 0) 
            update[TaskStatus::TESTING]= Changes(tracker[person][TaskStatus::IN_PROGRESS], task_count);
            if (task_count != 0)
            update[TaskStatus::DONE] = Changes(tracker[person][TaskStatus::TESTING], task_count);
           Check_zero (update);
            old[TaskStatus::NEW] = tracker[person][TaskStatus::NEW] - update[TaskStatus::IN_PROGRESS];
           old[TaskStatus::IN_PROGRESS]= tracker[person][TaskStatus::IN_PROGRESS] - update[TaskStatus::TESTING];
           old[TaskStatus::TESTING]= tracker[person][TaskStatus::TESTING] - update[TaskStatus::DONE];
           Check_zero (old);
            tracker[person][TaskStatus::NEW]= old[TaskStatus::NEW];
            tracker[person][TaskStatus::IN_PROGRESS]=update[TaskStatus::IN_PROGRESS]+old[TaskStatus::IN_PROGRESS];
            tracker[person][TaskStatus::TESTING]=update[TaskStatus::TESTING]+old[TaskStatus::TESTING];
            tracker[person][TaskStatus::DONE]+=update[TaskStatus::DONE];
       /*      cout << update[TaskStatus::IN_PROGRESS] << " update in progress and tasks to renew is " << task_count << endl;
            cout << update[TaskStatus::TESTING] << " update in testing  and tasks to renew is " << task_count << endl;
            cout << update[TaskStatus::DONE] << " update in done  and tasks to renew is " << task_count << endl;
            cout << old[TaskStatus::NEW] << "stays in new" << endl;
            cout << old[TaskStatus::IN_PROGRESS] << "stays in progess" << endl;
            cout << old[TaskStatus::TESTING] << "stays in testing" << endl; */
                return tie (update, old);

                    }


 
    private:
        map <string, TasksInfo> tracker;
};