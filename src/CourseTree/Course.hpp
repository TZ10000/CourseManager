/**
 * struct course that contains all the information
 */

#ifndef COURSE_HPP
#define COURSE_HPP

#include <iostream>
#include <vector>
using namespace std;

/**
 * Tree that need to read a file to generate a complete course schedule for one 
 * quarter
 */
class Course {
  public:
    string name;
    int startTime;      // 18:00 will be presented as 1800
    int endTime;
    int day;
    vector<string> preReqNum;  // store the name 
    bool taken;         // if the student took the course
    vector<Course*> prereq;
    vector<Course*> childrenCourse;

    // Null constructor
    Course() : name(""), startTime(-1), endTime(-1), day(-1), taken(true), prereq(vector<Course*>()), childrenCourse(vector<Course*>()) {}

    // Course constructor
    Course(string name, int starttime, int endtime, int day, Course* prereq) : 
        name(name), taken(false), startTime(starttime), endTime(endtime), prereq(vector<Course*>()), 
        day(day), preReqNum(vector<string>()), childrenCourse(vector<Course*>()) {}

    // Add the course to childcourse list
    void addChild(Course* child) {
      childrenCourse.push_back(child);
    }


    void take() {
        taken = true;
    }

};

#endif  // COURSE_HPP