#include<fstream>
#include<iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <time.h>
#include <sstream>
#include <typeinfo>
#include <unordered_map>
#include <conio.h>
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
    int identity = -1;  // store the user's choice

    while (identity != 1 && identity != 2)
    {
        interface.StartUI();
        cin >> identity;
    }

    if (identity == 1)  // is a student
    {

 ////// WARNING goto landing airstrip  //////
 /*//*/ label_StudentUI:               //////
 ////////////////////////////////////////////
        int choice = -1; // store the value of the user's choice
        interface.StudentUI();
        // while (choice == -1 || typeid(choice).name() != "i")
        // {
            cout << "Your choice here" << endl;
        // }
        cin.clear();
        if (cin >> choice)
        {
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
                        char answer = ' ';
                        while ( answer != 'y' && answer != 'Y' && answer != 'n' && answer != 'N')
                        {
                            cout << "Search another? [Y/N]" << endl;
                            cin >> answer;
                            if (answer == 'y' || answer == 'Y')
                                goto label_StudentCourseSearch;
                            if (answer == 'n' || answer == 'N')
                                goto label_StudentUI;
                        }

                    }
                    goto label_StudentUI;
                }

                // Add Course
                case 2:
                {
            ////// WARNING goto landing airstrip  //////
            /*//*/ label_StudentAddCourse:        //////
            ////////////////////////////////////////////
                    int sem = -1;
                    string semstr;
                    string studentName;
                    string year;
                    cout << "Your Name?" << endl;
                    cin >> studentName;
                    cout << "Which year? ex: 22,21,20" << endl;
                    cin >> year;
                    while (sem != 1 && sem != 2)
                    {
                        cout << "Which semester?" << endl;
                        cout << "1.Fall" << endl;
                        cout << "2.Spring" << endl;
                        cin >> sem;
                        if (sem == 1)
                            semstr = "FA";
                        else
                            semstr = "SP";
                    }
                    string coursenum;
                    Course* coursepointer;
                    CourseTree myTree;
                    if (myTree.BuildMapfromFile("Schedule" + semstr + year + ".txt"))
                    {
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
                                goto label_StudentAddCourse;
                            if (answer == 'n' || answer == 'N')
                                goto label_StudentUI;
                        }
                    }
                    else
                        goto label_StudentAddCourse;

                    cout << "Class Number: " << coursepointer->name << endl;
                    if (coursepointer->day == 24)
                        cout << "Day: " << "TTH" << endl;
                    if (coursepointer->day == 135)
                        cout << "Day: " << "MWF" << endl;
                    cout << "Start: " << coursepointer->startTime << endl;
                    cout << "End: " << coursepointer->endTime << endl;
                    for (auto x:coursepointer->preReqNum)
                        cout << "preRequisite: " << x << endl;
                    
                    char answer = ' ';
                    while (answer != 'y' && answer != 'Y' && answer != 'n' && answer != 'N')
                    {
                        cout << "Are you sure to add?[Y/N]" << endl;
                        cin >> answer;
                        if (answer == 'y' || answer == 'Y')
                        {
                            ofstream outfile(studentName + semstr + year + ".txt" , ios::app);  // Create a txt file to store the student
                            outfile << coursenum << endl;
                            cout << "Added!" << endl;
                            goto label_StudentUI;
                        }
                        else
                        {
                            goto label_StudentAddCourse;
                        }
                    }
                }

                // Drop Course
                case 3:
                {
            ////// WARNING goto landing airstrip  //////
            /*//*/ label_StudentDropCourse:       //////
            ////////////////////////////////////////////
                    int sem = -1;
                    string semstr;
                    string studentName;
                    string year;
                    cout << "Your Name?" << endl;
                    cin >> studentName;
                    cout << "Which year? ex: 22,21,20" << endl;
                    cin >> year;
                    while (sem != 1 && sem != 2)
                    {
                        cout << "Which semester?" << endl;
                        cout << "1.Fall" << endl;
                        cout << "2.Spring" << endl;
                        cin >> sem;
                        if (sem == 1)
                            semstr = "FA";
                        else
                            semstr = "SP";
                    }
                    ifstream infile(studentName + semstr + year + ".txt");
                    while (infile)
                    {
                        vector<string> allStudentCourse;  // stores all of the student's course
                        vector<string> newAllStudentCourse;  // stores the new student course
                        string line;  // each line that read from the file;
                        string coursedrop;
                        cout << "Which course do you want to drop?" << endl;
                        cin >> coursedrop;
                        while(getline(infile,line))
                            allStudentCourse.push_back(line);

                        for (auto x : allStudentCourse)  // drop the course
                        {
                            if (x == coursedrop)
                            {
                                cout << "Dropped!" << endl;
                                continue;
                            }
                            newAllStudentCourse.push_back(x);
                        }

                        if (newAllStudentCourse.size() == allStudentCourse.size())  // if no such course
                        {
                            cout << "No such Course!" << endl;
                            continue;
                        }
                        else
                        {
                            ofstream outfile(studentName + semstr + year + ".txt");
                            for (auto x : newAllStudentCourse)
                            {
                                outfile << x << endl;
                            }
                            outfile.close();
                            char answer = ' ';
                            while (answer != 'y' && answer != 'Y' && answer != 'n' && answer != 'N')
                            {
                                cout << "Drop Another?[Y/N]" << endl;
                                cin >> answer;
                                if (answer == 'y'||answer =='Y')
                                {
                                    continue;
                                }
                                if (answer == 'n' || answer == 'Y')
                                {
                                    goto label_StudentUI;
                                }
                            }
                        }
                    }
                    if (!infile)
                        cout << "No such profile!" << endl;
                    else
                        infile.close();
                    goto label_StudentUI;  // if no such file go back to the main page
                }

                // Show all Course
                case 5:
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
                        char answer = ' ';
                        while ( answer != 'y' && answer != 'Y' && answer != 'n' && answer != 'N')
                        {
                            cout << "Try again? [Y/N]" << endl;
                            cin >> answer;
                            if (answer == 'y' || answer == 'Y')
                                goto label_StudentShowAllCourse;
                            if (answer == 'n' || answer == 'N')
                                goto label_StudentUI;
                        }
                    }
                }
                
                // Generate Course Table
                case 4:
                {
                    string studentName;
                    string year;
                    int sem; // student's choice between fall or spring
                    string semstr;  // the system's interpretation based on student's choice
                    cout << "Your Name?" << endl;
                    cin >> studentName;
                    while (year != "20" && year != "21" && year != "22" && year != "23")
                    {
                        cout << "which semester are you currently in? ex: 20,21,22" << endl;
                        cin >> year;
                    }
                    while (sem != 1 && sem != 2)
                    {
                        cout << "Which semester?" << endl;
                        cout << "1.Fall" << endl;
                        cout << "2.Spring" << endl;
                        cin >> sem;
                        if (sem == 1)
                            semstr = "FA";
                        else
                            semstr = "SP";
                    }
                    CourseTree myTree;
                    cout << studentName + semstr + year + ".txt" << endl;
                    ifstream infilestudent(studentName + semstr + year + ".txt");
                    unordered_map<string,int> coursemap;
                    bool buildMapSuccessful;
                    while (infilestudent)
                    {
                        string line;
                        getline(infilestudent,line);
                        coursemap.insert(pair<string,int>(line,1));
                    }
                    if (sem == 2)  // if it is spring
                    {
                        buildMapSuccessful = myTree.BuildMapfromFile( "ScheduleFA" + to_string(stoi(year) + 1) + ".txt");
                        cout << "Build from ScheduleFA" + to_string(stoi(year) + 1) + ".txt" << endl;
                    }
                    else if (sem == 1)  // if it is fall
                    {
                        buildMapSuccessful = myTree.BuildMapfromFile( "SchduleSP" + year + ".txt");
                        cout << "Build from SchduleFA" + year + ".txt" << endl;

                    }

                    unordered_map<string,int> coursesDelete;//  courses that need to be delete from the map
                    map<string,Course*> newCourseMap; // create a new map that contains classes that have not taken
                    map<string,Course*> canTakeCourse;  // the course that can be taken 
                    if (buildMapSuccessful)
                    {
                        for (auto x : myTree.allCourseMap)  // Loop through all of the courses
                        {
                            if (coursemap.find(x.second->name) != coursemap.end())  // means course found
                            {
                                coursesDelete.insert(pair<string,int>(x.second->name,1));  // push that course to the deletelist
                                for (auto y : x.second->preReqNum)  // push its preReq to the deletelist
                                {
                                    if (y == "None")  // if the preReq doesn't == None
                                        break;
                                    else
                                        coursesDelete.insert(pair<string,int>(y,1));
                                }
                            }
                        }

                        for (auto x : myTree.allCourseMap)  // Loop through all of the courses
                        {
                            if(coursesDelete.find(x.second->name)!=coursesDelete.end())  // if there is a course
                            {
                                continue;
                            }
                            else
                            {
                                newCourseMap.insert(x);  // generate courses without preRequisites and taken courses
                            }
                        }

                        // get rid of those cannot take because of preReq does not met
                        for (auto x: newCourseMap)  // loop through all courses
                        {
                            bool shouldAdd = true;
                            for (auto y : x.second->preReqNum)  // loop through all preRequisite course
                            {
                                if (y == "None")
                                {
                                    shouldAdd = true;
                                    break;
                                }
                                if (coursesDelete.find(y) == coursesDelete.end())  // if there is one preRequisite missing
                                {
                                    shouldAdd = false; 
                                    break;
                                }
                            }
                            if (shouldAdd)
                            {
                                canTakeCourse.insert(x);
                            }
                        }
                        cout << "Here are the courses you can take" << endl;
                        for(auto x:canTakeCourse)
                        {
                            cout << x.first << endl;
                        }
                        infilestudent.close();
                    }
                    else
                    {
                        cout << "The semester does not exist!" << endl;
                    }
                    cout << "Press any key to back to the main page." << endl;
                    getch();
                    goto label_StudentUI;
                }
                
                // Exit
                case 0:  // Exit the program
                {
                    cout << ">>>Thank you<<<" << endl;
                    _sleep(1*1000);
                    exit(0);
                }

                default:
                    goto label_StudentUI;
            }
    
        }
        goto label_StudentUI;
    }
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
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
                _sleep(1*1000);
                exit(0);
            }
            case 1:  // Course Input
            {
            ////// WARNING goto landing airstrip  //////
            /*//*/ label_CourseInput:             //////
            ////////////////////////////////////////////
                char yn = ' ';
                InputCourse();
                while ( yn != 'y' && yn != 'Y' && yn != 'n' && yn != 'N')
                {
                    cout << "Add other one? [Y/N]" << endl;
                    cin >> yn;
                    if (yn == 'Y' || yn == 'y')
                        goto label_CourseInput;  // if the user chooses yes, then repeat the process
                    else if (yn == 'N' || yn == 'n')
                        goto label_TeacherUI;  
                    // if the user chooses no, then go back to the teacher interface
                }
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


                int fasp = -1;
                string faspstr;
                while (fasp != 1 && fasp != 2)
                {
                    cout << "Fall or Spring?" << endl;
                    cout << "1. Fall" << endl;
                    cout << "2. Spring" << endl;
                    cin >> fasp;
                    if (fasp == 1)
                        faspstr = "FA";
                    else if (fasp == 2)
                        faspstr = "SP";
                }

                string coursenum;
                Course* coursepointer;
                CourseTree myTree;
                if (myTree.BuildMapfromFile("Schedule" + faspstr + year + ".txt"))
                {

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

                }
                else
                    goto label_TeacherCourseSearch;
                cout << "Class Number: " << coursepointer->name << endl;
                if (coursepointer->day == 24)
                    cout << "Day: " << "TTH" << endl;
                if (coursepointer->day == 135)
                    cout << "Day: " << "MWF" << endl;
                cout << "Start: " << coursepointer->startTime << endl;
                cout << "End: " << coursepointer->endTime << endl;
                for (auto x:coursepointer->preReqNum)
                    cout << "preRequisite: " << x << endl;
                char answer = ' ';
                cin >> answer;
                while ( answer != 'y' && answer != 'Y' && answer != 'n' && answer != 'N')
                {
                    cout << "Search another? [Y/N]" << endl;
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
                    char answer = ' ';
                    while ( answer != 'y' && answer != 'Y' && answer != 'n' && answer != 'N')
                    {
                        cout << "Show another semester? [Y/N]" << endl;
                        cin >> answer;
                        if (answer == 'y' || answer == 'Y')
                            goto label_TeacherShowAllCourse;
                        if (answer == 'n' || answer == 'N')
                            goto label_TeacherUI;
                    }

                }
                else
                {
                    char answer = ' ';
                    while ( answer != 'y' && answer != 'Y' && answer != 'n' && answer != 'N')
                    {
                        cout << "Try again? [Y/N]" << endl;
                        cin >> answer;
                        if (answer == 'y' || answer == 'Y')
                            goto label_TeacherShowAllCourse;
                        if (answer == 'n' || answer == 'N')
                            goto label_TeacherUI;
                    }
                }
                

            }

            default:
            {
                goto label_TeacherUI;
            }
        }
    }  

    return 0;
}