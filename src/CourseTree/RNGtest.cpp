#include<fstream>
#include<iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <time.h>
#include <sstream>
#include <typeinfo>
#include "Course.hpp"
#include "CourseTree.hpp"
#include <unordered_map>
using namespace std;


vector<int> Randomshuffle(int shufflenum)
{
    vector<int> initialvec;
    vector<int> outputvec;
    for (int i = 0; i < shufflenum; i++)
    {
        initialvec.push_back(i);
    }
    int temp = shufflenum;
    for (int i = 0; i < shufflenum; i++)
    {
        int rdm = rand() % temp;  // find a random within it
        outputvec.push_back(initialvec.at(rdm));  // add the number in that place to the output vector
        initialvec.at(rdm) = initialvec.at(initialvec.size() - 1);
        initialvec.pop_back();
        temp--;
    }
    return outputvec;
}

int main()
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
    }
    for(auto x:canTakeCourse)
    {
        cout << x.first << endl;
    }

}
