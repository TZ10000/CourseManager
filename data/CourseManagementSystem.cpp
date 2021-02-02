#include<fstream>
#include<iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <time.h>
using namespace std;

class Course
{
    public:
        int classnum;       // the class number
        int startTime;      // the time that the class is offerred
        int endTime;        // the time that the class ends
        string preRequisite;
        string coRequisite;
        string date;
        void SetClassNum();
        void SetDate();
        void SetStartTime();
        void SetEndTime();
        void Setpre();
        void Setco();
};
void Course::SetClassNum()
{
    cout << "Please input course number: ";
    cin >> this->classnum;
}
void Course::SetDate()
{
    cout << "Please input course date e.g. MWF : ";
    cin >> this->date;
}
void Course::SetStartTime()
{
    cout << "Please input start time e.g.800 : ";
    cin >> this->startTime;
}
void Course::SetEndTime()
{
    cout << "Please input end time e.g.800 : ";
    cin >> this->endTime;
}
void Course::Setpre()
{
    cout << "Please input preRequisite for this course" << endl;
    cout << "Use space to divide different courses" << endl;
    cout << "Type 0 if there is none." << endl;
    cin >> this->preRequisite;
}
void Course::Setco()
{
    cout << "Please input coRequisite for this course" << endl;
    cout << "Use space to divide different courses" << endl;
    cout << "Type 0 if there is none." << endl;
    cin >> this->coRequisite;
}

class Interface
{
    public:
        void MenuUI();
        void StudentUI();
        void TeacherUI();
};
void Interface::MenuUI()
{
    cout << " ////////////////////////////////////////////////////////////////////// " << endl;
    cout << " /// Welcome to the School Course Management System, please select: /// " << endl;
    cout << " /// 1.I am a Student.                                              /// " << endl;
    cout << " /// 2.I am a Teacher.                                              /// " << endl;
    cout << " ////////////////////////////////////////////////////////////////////// " << endl;
};
void Interface::StudentUI()
{
    cout << "////////////////////////////////////////////////////" << endl;
    cout << "/// I want to...                                 ///" << endl;
    cout << "///                                              ///" << endl;
    cout << "/// 1. Search a course.                          ///" << endl;
    cout << "/// 2. Add courses to my schedule.               ///" << endl;
    cout << "/// 3. Drop courses from my schedule.            ///" << endl;
    cout << "/// 4. Auto generate my personal course schedule.///" << endl;
    cout << "////////////////////////////////////////////////////" << endl;
};
void Interface::TeacherUI()
{
    cout << "///////////////////////////////////////////////" << endl;
    cout << "/// I want to...                            ///" << endl;
    cout << "///                                         ///" << endl;
    cout << "/// 1. Input a course.                      ///" << endl;
    cout << "/// 2. Delete a course.                     ///" << endl;
    cout << "/// 3. Search a course.                     ///" << endl;
    cout << "///////////////////////////////////////////////" << endl;
};

void InputCourse()
{
            Course course;
            string fasp;
            string year;
            int semchoice;

            cout << "Which year?" << endl;
            cin >> year;
            cout << "Fall or Spring?" << endl;
            cout << "1.Fall" << endl;
            cout << "2.Spring" << endl;
            cin >> semchoice;
            
            if (semchoice == 1)
                fasp = "FA";
            if (semchoice == 2)
                fasp = "SP";
            // ifstream inFile("Schedule" + fasp + year + ".txt");
                // if (!inFile)
                // {
                //     ofstream inFile("Schedule" + fasp + year + ".txt");
                //     inFile << "Course Number            Days           Time           Prereq           Coreq" << endl;
                // }
            ofstream outFile("Schedule" + fasp + year + ".txt", ios::app);
            course.SetClassNum();
            course.SetDate();
            course.SetStartTime();
            course.SetEndTime();
            course.Setpre();
            course.Setco();
            outFile << course.classnum << "            " << course.date \
                    << "            " << course.startTime << "-" << course.endTime\
                    << "            " << course.preRequisite \
                    << "            " << course.coRequisite << endl;
            
}

int main()
{
    Interface interface;
    int identity;  // store the user's choice

    interface.MenuUI();
    cin >> identity;

    if (identity == 1)  // is a student
    {
        int choice; // store the value of the user's choice
        interface.StudentUI();
        cin >> choice;
    }

    if (identity == 2)  // is a teacher
    {    
        int choice; // store the value of the user's choice
        bool isback = false;  // decides if the user choose to go back from their choice
        interface.TeacherUI();
        cin >> choice;

        while(!isback)
        {
            switch (choice)
            {       
                case 1:  // Course Input
                {
                    char yn;
                    InputCourse();
                    cout << "Add other one? [Y/N]" << endl;
                    cin >> yn;
                    if (yn == 'Y' || yn == 'y')
                        isback = false;
                    else if (yn == 'N' || yn == 'n')
                        isback = true;
                    // else
                    // {
                    //     // TODO: error handling
                    // }
                }

                // // Course change
                // case 2:

                // // Course search
                // case 3:

            }
        }
    }  

    return 0;
}