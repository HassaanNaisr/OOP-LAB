#include "iostream"
#include "string"

using namespace std;

class Planner 
{
public:
    string daytask[31];  

    Planner() 
    {
        for (int i = 0; i < 31; i++) 
        {
            daytask[i] = "";  
        }
    }

    void addTask(int month);
    void removeTask(int month);
    void displayTasks(Planner planners[]);
};

void Planner::addTask(int month)  
{
    int day = 0;
    
    cout << "Opening task planner for month " << month + 1 << endl;

    if (month == 3 || month == 5 || month == 8 || month == 10) 
    { 
        while (day < 1 || day > 30) 
        {
            cout << "Enter a day to add a task (1-30): ";
            cin >> day;
            if (day < 1 || day > 30) 
            {
                cout << "Invalid date, this month only has 30 days" << endl;
            }
        }
    } 
    else if (month == 1) 
    { 
        while (day < 1 || day > 28) 
        {
            cout << "Enter a day to add a task (1-28): ";
            cin >> day;
            if (day < 1 || day > 28) 
            {
                cout << "Invalid date, this month only has 28 days" << endl;
            }
        }
    } 
    else 
    { 
        while (day < 1 || day > 31) 
        {
            cout << "Enter a day to add a task (1-31): ";
            cin >> day;
            if (day < 1 || day > 31) 
            {
                cout << "Invalid date, this month only has 31 days" << endl;
            }
        }
    }

    if (daytask[day - 1] != "")  
    {
        cout << "This day already has a task: " << daytask[day - 1] << endl;
        return;
    }

    cout << "Enter a task for this day: ";
    cin.ignore();  
    getline(cin, daytask[day - 1]);

    cout << "Task added successfully" << endl;
}

void Planner::removeTask(int month)
{
    int day = 0;
    
    cout << "Opening task remover for month " << month + 1 << endl;

    if (month == 3 || month == 5 || month == 8 || month == 10) 
    { 
        while (day < 1 || day > 30) 
        {
            cout << "Enter a day to remove a task (1-30): ";
            cin >> day;
            if (day < 1 || day > 30) 
            {
                cout << "Invalid date, this month only has 30 days" << endl;
            }
        }
    } 
    else if (month == 1) 
    { 
        while (day < 1 || day > 28) 
        {
            cout << "Enter a day to remove a task (1-28): ";
            cin >> day;
            if (day < 1 || day > 28) 
            {
                cout << "Invalid date, this month only has 28 days" << endl;
            }
        }
    } 
    else 
    { 
        while (day < 1 || day > 31) 
        {
            cout << "Enter a day to remove a task (1-31): ";
            cin >> day;
            if (day < 1 || day > 31) 
            {
                cout << "Invalid date, this month only has 31 days" << endl;
            }
        }
    }

    if (daytask[day - 1] == "") 
    {
        cout << "No task found for this day" << endl;
        return;
    }

    cout << "Removing task: " << daytask[day - 1] << endl;
    daytask[day - 1] = "";  
    cout << "Task removed successfully" << endl;
}

void Planner::displayTasks(Planner planners[])  
{
    int hasTasks = 0; 

    for (int month = 0; month < 12; month++)  
    {
        cout << "Month " << month + 1 << ":" << endl;
        int monthHasTasks = 0;  

        for (int day = 0; day < 31; day++)  
        {
            if (planners[month].daytask[day] != "")  
            {
                cout << "   Day " << day + 1 << ": " << planners[month].daytask[day] << endl;
                monthHasTasks = 1;
                hasTasks = 1;
            }
        }

        if (monthHasTasks == 0)  
        {
            cout << "   No tasks for this month." << endl;
        }
    }

    if (hasTasks == 0)  
    {
        cout << "No tasks found for any month." << endl;
    }
}

int main() 
{
    Planner planners[12]; 
    int choice = 0;
    
    while (choice != 4) 
    {
        cout << "\nHello Hassan! What would you like to do?" << endl;
        cout << "1) Add a task for a certain day" << endl;
        cout << "2) Remove a task from a certain day" << endl;
        cout << "3) Display all tasks" << endl;
        cout << "4) Exit the planner" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) 
        {
            case 1: 
            {
                int month = 0;
                while (month < 1 || month > 12) 
                {
                    cout << "For which month (1-12) would you like to add a task? ";
                    cin >> month;
                    if (month < 1 || month > 12) 
                    {
                        cout << "Invalid month, please choose between 1 and 12" << endl;
                    }
                }
                planners[month - 1].addTask(month - 1);  
                break;
            }
            case 2:
            {
                int month = 0;
                while (month < 1 || month > 12) 
                {
                    cout << "For which month (1-12) would you like to remove a task? ";
                    cin >> month;
                    if (month < 1 || month > 12) 
                    {
                        cout << "Invalid month, please choose between 1 and 12" << endl;
                    }
                }
                planners[month - 1].removeTask(month - 1);
                break;
            }
            case 3:
                planners[0].displayTasks(planners);  
                break;
            case 4:
                cout << "Exiting planner" << endl;
                break;
            default:
                cout << "Invalid choice, please try again" << endl;
        }
    }

    return 0;
}
