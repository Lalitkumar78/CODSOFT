#include<iostream>
#include<vector>
#include<string>
using namespace std;

struct Task
{
    string name;
    bool completed;

    Task(string taskName)
    {
        name = taskName;
        completed = false;
    }
};

void addTask(vector<Task> &tasks);
void viewTasks(const vector<Task> &tasks);
void markTaskCompleted(vector<Task> &tasks);
void removeTask(vector<Task> &tasks);

int main()
{
    vector<Task> tasks;
    int choice;

    do
    {
        cout<<"\n.... TO-DO LIST MENU ....\n";
        cout<<"1). Add Task\n";
        cout<<"2). View Tasks\n";
        cout<<"3). Mark Task as Completed\n";
        cout<<"4). Remove Task\n";
        cout<<"5). Exit\n";
        cout<<"Enter your choice: ";
        cin>>choice;
        cin.ignore();

        switch(choice) 
        {
            case 1:
                addTask(tasks);
                break;
            case 2:
                viewTasks(tasks);
                break;
            case 3:
                markTaskCompleted(tasks);
                break;
            case 4:
                removeTask(tasks);
                break;
            case 5:
                cout<<"Exiting... Bye!\n";
                break;
            default:
                cout<<"Invalid option. Try again.\n";
        }
    } while(choice != 5);

    return 0;
}

void addTask(vector<Task> &tasks) 
{
    string taskName;
    cout<<"Enter task name: ";
    getline(cin, taskName);
    tasks.push_back(Task(taskName));
    cout<<"Task added successfully!\n";
}

void viewTasks(const vector<Task> &tasks)
{
    if(tasks.empty()) 
    {
        cout<<"No tasks available.\n";
        return;
    }

    cout<<"\nYour Tasks:\n";
    for(size_t i = 0; i < tasks.size(); ++i) 
    {
        cout<<i + 1<<". "<<tasks[i].name;
        cout<<" ["<<(tasks[i].completed ? "Done":"Pending")<<"]\n";
    }
}

void markTaskCompleted(vector<Task> &tasks) 
{
    int num;
    viewTasks(tasks);
    cout<<"Enter task number to mark completed: ";
    cin>>num;

    if(num > 0 && num <= tasks.size()) 
    {
        tasks[num - 1].completed = true;
        cout<<"Task marked as completed!\n";
    } 
    else{
        cout<<"Invalid task number.\n";
    }
}

void removeTask(vector<Task> &tasks) 
{
    int num;
    viewTasks(tasks);
    cout<<"Enter task number to remove: ";
    cin>>num;

    if(num > 0 && num <= tasks.size()) 
    {
        tasks.erase(tasks.begin() + (num - 1));
        cout<<"Task removed successfully.\n";
    } else {
        cout<<"Invalid task number.\n";
    }
}