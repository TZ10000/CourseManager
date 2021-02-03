#include<fstream>
#include<iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <time.h>
#include <sstream>
#include "Course.hpp"
#include "CourseTree.hpp"
using namespace std;

class SetCourse
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
void SetCourse::SetClassNum()
{
    cout << "Please input course number: ";
    cin >> this->classnum;
}
void SetCourse::SetDate()
{
    cout << "Please input course date e.g. MWF : ";
    cin >> this->date;
}
void SetCourse::SetStartTime()
{
    cout << "Please input start time e.g.800 : ";
    cin >> this->startTime;
}
void SetCourse::SetEndTime()
{
    cout << "Please input end time e.g.800 : ";
    cin >> this->endTime;
}
void SetCourse::Setpre()
{
    cout << "Please input preRequisite for this course" << endl;
    cout << "Use space to divide different courses" << endl;
    cout << "Type 0 if there is none." << endl;
    cin >> this->preRequisite;
}
void SetCourse::Setco()
{
    cout << "Please input coRequisite for this course" << endl;
    cout << "Use space to divide different courses" << endl;
    cout << "Type 0 if there is none." << endl;
    cin >> this->coRequisite;
}

class Interface
{
    public:
        void StartUI();
        void StudentUI();
        void TeacherUI();
        bool ShowFullCourses();
};
void Interface::StartUI()
{
    cout << " /////////////////////////////////////// " << endl;
    cout << " ///          Welcome to the         /// " << endl;
    cout << " /// School Course Management System /// " << endl;
    cout << " /// ------------------------------- /// " << endl;
    cout << " ///                                 /// " << endl; 
    cout << " /// please select:                  /// " << endl;
    cout << " /// 1.I am a Student.               /// " << endl;
    cout << " /// 2.I am a Teacher.               /// " << endl;
    cout << " ///                                 /// " << endl; 
    cout << " /////////////////////////////////////// " << endl;
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
    cout << "/// 5. Show all course.                          ///" << endl;
    cout << "/// 0. Exit the Program.                         ///" << endl;
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
    cout << "/// 4. Show all course.                     ///" << endl;
    cout << "/// 0. Exit the Program.                    ///" << endl;
    cout << "///////////////////////////////////////////////" << endl;
};
bool Interface::ShowFullCourses()
{
    cout << "Which year? (EX: 21,22,23)" << endl;
    string year;
    cin >> year;
    cout << "Fall or Spring?" << endl;
    cout << "1. Fall" << endl;
    cout << "2. Spring" << endl;

    int fasp;
    cin >> fasp;
    string faspstr;
    if (fasp == 1)
        faspstr = "FA";
    else if (fasp == 2)
        faspstr = "SP";
    
    ifstream infile("Schedule" + faspstr + year + ".txt");
    while(infile)
    {        
        string s;
        if (!getline(infile, s)) break;     // if the file is empty, exit the loop
        cout << s << endl;
    }
    if (!infile.eof())
    {
        cerr << "Schedule" + faspstr + year + ".txt" << "does not exist." << endl;
        return false;        
    }
    infile.close();
    return true;
}

void InputCourse()
{
            SetCourse setcourse;
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
            ofstream outFile("Schedule" + fasp + year + ".txt", ios::app);
            setcourse.SetClassNum();
            setcourse.SetDate();
            setcourse.SetStartTime();
            setcourse.SetEndTime();
            setcourse.Setpre();
            setcourse.Setco();
            outFile << setcourse.classnum << "            " << setcourse.date \
                    << "            " << setcourse.startTime << "-" << setcourse.endTime\
                    << "            " << setcourse.preRequisite \
                    << "            " << setcourse.coRequisite << endl;
}

int main()
{
    Interface interface;
    int identity;  // store the user's choice

    interface.StartUI();
    cin >> identity;

    if (identity == 1)  // is a student
    {
        int choice; // store the value of the user's choice

 ////// WARNING goto landing airstrip  //////
 /*//*/ label_StudentUI:               //////
 ////////////////////////////////////////////
        interface.StudentUI();
        cin >> choice;

        switch (choice)
        {
        // Course Search
            case 1:
            {
        ////// WARNING goto landing airstrip  //////
        /*//*/ label_StudentCourseSearch:     //////
        ////////////////////////////////////////////
                cout << "Which year? (EX: 21,22,23)" << endl;
                string years;
                cin >> years;
                cout << "Fall or Spring?" << endl;
                cout << "1. Fall" << endl;
                cout << "2. Spring" << endl;

                int fasp;
                cin >> fasp;
                string faspstr;
                if (fasp == 1)
                    faspstr = "FA";
                else if (fasp == 2)
                    faspstr = "SP";
                
                CourseTree myTree;
                if (myTree.BuildMapfromFile("Schedule" + faspstr + years + ".txt"))
                {
                    string coursenum;
                    Course* coursepointer;
                    cout << "Type in Course Num (ex: CSE8B)" << endl;
                    cin >> coursenum;

                    try
                    {
                        coursepointer = myTree.allCourseMap.at(coursenum);
                    }
                    catch(const std::exception& e)
                    {
                        cout << "Not found in this semester,try again? [Y/N]" << endl;
                        char answer;
                        cin >> answer;
                        if (answer == 'y' || answer == 'Y')
                            goto label_StudentCourseSearch;
                        if (answer == 'n' || answer == 'N')
                            goto label_StudentUI;
                    }

                    cout << "Class Number: " << coursepointer->name << endl;
                    if (coursepointer->day == 24)
                        cout << "Day: " << "TTH" << endl;
                    if (coursepointer->day == 135)
                        cout << "Day: " << "MWF" << endl;
                    cout << "Start: " << coursepointer->startTime << endl;
                    cout << "End: " << coursepointer->endTime << endl;
                    for (auto x:coursepointer->preReqNum)
                        cout << "preRequisite: " << x << endl;
                    cout << "Search another? [Y/N]" << endl;
                    char answer;
                    cin >> answer;
                    if (answer == 'y' || answer == 'Y')
                        goto label_StudentCourseSearch;
                    if (answer == 'n' || answer == 'N')
                        goto label_StudentUI;
                }
            }
            
            // Add Course
            case 2:
            {
        ////// WARNING goto landing airstrip  //////
        /*//*/ label_StudentAddCourse:        //////
        ////////////////////////////////////////////
                cout << "Your Name?" << endl;
                string studentName;
                cin >> studentName;
                cout << "Which year? ex: 22,21,20" << endl;
                string year;
                cin >> year;
                cout << "Which semester?" << endl;
                cout << "1.Fall" << endl;
                cout << "2.Spring" << endl;
                int sem;
                cin >> sem;
                string semstr;
                if (sem == 1)
                    semstr = "FA";
                else
                    semstr = "SP";
                ofstream outfile(studentName + semstr + year + ".txt");  // Create a txt file to store the student


            }

            // Drop Course
            case 3:
            {

            }

            // Show all Course
            case 4:
            {
        ////// WARNING goto landing airstrip   //////
        /*//*/ label_StudentShowAllCourse:     //////
        /////////////////////////////////////////////
                if (interface.ShowFullCourses())
                {
                    cout << "Show another semester? [Y/N]" << endl;
                    char answer;
                    cin >> answer;
                    if (answer == 'y' || answer == 'Y')
                        goto label_StudentShowAllCourse;
                    if (answer == 'n' || answer == 'N')
                        goto label_StudentUI;
                }
                else
                {
                    cout << "Try again? [Y/N]" << endl;
                    char answer;
                    cin >> answer;
                    if (answer == 'y' || answer == 'Y')
                        goto label_StudentShowAllCourse;
                    if (answer == 'n' || answer == 'N')
                        goto label_StudentUI;
                }
                

            }
            
            // Generate Course Table
            case 5:
            {

            }
            
            // Exit
            case 0:  // Exit the program
            {
                cout << ">>>Thank you<<<" << endl;
                exit(0);
            }
        }
    }

    if (identity == 2)  // is a teacher
    {    
        int choice; // store the value of the user's choice
        bool isback = false;  // decides if the user choose to go back from their choice

 ////// WARNING goto landing airstrip  //////
 /*//*/ label_TeacherUI:               //////
 ////////////////////////////////////////////
        interface.TeacherUI();
        cin >> choice;
        switch (choice)
        {   
            case 0:  // Exit the program
            {
                cout << ">>>Thank you<<<" << endl;
                exit(0);
            }
            case 1:  // Course Input
            {
            ////// WARNING goto landing airstrip  //////
            /*//*/ label_CourseInput:             //////
            ////////////////////////////////////////////
                char yn;
                InputCourse();
                cout << "Add other one? [Y/N]" << endl;
                cin >> yn;
                if (yn == 'Y' || yn == 'y')
                    goto label_CourseInput;  // if the user chooses yes, then repeat the process
                else if (yn == 'N' || yn == 'n')
                    goto label_TeacherUI;  // if the user chooses no, then go back to the teacher interface
                // else
                // {
                //     // TODO: error handling
                // }
            }

            // // Course change
            // case 2:

            // // Course search
            case 3:
            {
        ////// WARNING goto landing airstrip  //////
        /*//*/ label_TeacherCourseSearch:     //////
        ////////////////////////////////////////////
                cout << "Which year? (EX: 21,22,23)" << endl;
                string year;
                cin >> year;
                cout << "Fall or Spring?" << endl;
                cout << "1. Fall" << endl;
                cout << "2. Spring" << endl;

                int fasp;
                cin >> fasp;
                string faspstr;
                if (fasp == 1)
                    faspstr = "FA";
                else if (fasp == 2)
                    faspstr = "SP";
                
                CourseTree myTree;
                if (myTree.BuildMapfromFile("Schedule" + faspstr + year + ".txt"))
                {
                    string coursenum;
                    Course* coursepointer;
                    cout << "Type in Course Num (ex: CSE8B)" << endl;
                    cin >> coursenum;

                    try
                    {
                        coursepointer = myTree.allCourseMap.at(coursenum);
                    }
                    catch(const std::exception& e)
                    {
                        cout << "Not found in this semester,try again? [Y/N]" << endl;
                        char answer;
                        cin >> answer;
                        if (answer == 'y' || answer == 'Y')
                            goto label_TeacherCourseSearch;
                        if (answer == 'n' || answer == 'N')
                            goto label_TeacherUI;
                    }

                    cout << "Class Number: " << coursepointer->name << endl;
                    if (coursepointer->day == 24)
                        cout << "Day: " << "TTH" << endl;
                    if (coursepointer->day == 135)
                        cout << "Day: " << "MWF" << endl;
                    cout << "Start: " << coursepointer->startTime << endl;
                    cout << "End: " << coursepointer->endTime << endl;
                    for (auto x:coursepointer->preReqNum)
                        cout << "preRequisite: " << x << endl;
                    cout << "Search another? [Y/N]" << endl;
                    char answer;
                    cin >> answer;
                    if (answer == 'y' || answer == 'Y')
                        goto label_TeacherCourseSearch;
                    if (answer == 'n' || answer == 'N')
                        goto label_TeacherUI;
                }
            }
            // show all course
            case 4:
            {
        ////// WARNING goto landing airstrip   //////
        /*//*/ label_TeacherShowAllCourse:     //////
        /////////////////////////////////////////////
                if (interface.ShowFullCourses())
                {
                    cout << "Show another semester? [Y/N]" << endl;
                    char answer;
                    cin >> answer;
                    if (answer == 'y' || answer == 'Y')
                        goto label_TeacherShowAllCourse;
                    if (answer == 'n' || answer == 'N')
                        goto label_TeacherUI;
                }
                else
                {
                    cout << "Try again? [Y/N]" << endl;
                    char answer;
                    cin >> answer;
                    if (answer == 'y' || answer == 'Y')
                        goto label_TeacherShowAllCourse;
                    if (answer == 'n' || answer == 'N')
                        goto label_TeacherUI;
                }
                

            }
        }
    }  

    return 0;
}