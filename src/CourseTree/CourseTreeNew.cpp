#include<fstream>
#include<iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <time.h>
#include "Course.hpp"
#include "CourseTree.hpp"
using namespace std;

int main()
{
    CourseTree mytree;
    ifstream infile("ScheduleFA21.txt");
    bool readHeader = false;
    while(infile)
    {
        Course* newCourse = new Course();
        string courseNum;
        string s;
        if (!getline(infile, s)) break;     // if the file is empty, exit the loop

        // skip the header of the file
        if (!readHeader)
        {
            readHeader = true;
            continue;
        }

        // read each line of the dataset, each line represent a course
        istringstream ss(s);
        vector<string> record;
        record = mytree.StringParse(s);

        // if format is wrong, skip current line
        if (record.size() != 5)
            continue;

        // extract the information
        courseNum = record[0];
        string days(record[1]);
        string time(record[2]);
        vector<string> prereq = mytree.ParsePrereq(record[3]);
        vector<string> coreq = mytree.ParsePrereq(record[4]);

        // Build the tree
        // parse start time and end time
        vector<int> timevector = mytree.ParseTime(time);
        int start = timevector[0];
        int end = timevector[1];

        // parse day
        int parsedday = -1;
        if (days == "MWF")
            parsedday = 135;

        if (days == "TTh")
            parsedday = 24;
                     
        newCourse->name = courseNum;
        newCourse->day = parsedday;
        newCourse->startTime = start;
        newCourse->endTime = end;
        newCourse->preReqNum = prereq;
    
        mytree.allCourseMap.insert(pair<string,Course*>(courseNum,newCourse));  // leave the pointer part empty
        // if failed to read the file, clear the graph and return
    }
    // CourseTree coursetree;
    // if (coursetree.BuildMapfromFile("ScheduleFA21.txt"))
    // {
    //     string coursenum = "CSE8B";
    //     Course* coursepointer;
    //     coursepointer = coursetree.allCourseMap.at(coursenum);

    //     cout << "Class Number: " << coursepointer->name << endl;
    //     cout << "Day: " << coursepointer->day << endl;
    //     cout << "Start: " << coursepointer->startTime << endl;
    //     cout << "End: " << coursepointer->endTime << endl;
    //     for (auto x:coursepointer->preReqNum)
    //         cout << "preRequisite: " << x << endl;
    // }

    return 0;
}