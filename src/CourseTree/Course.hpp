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

    // bool taken;         // if the student took the course, not sure if we need it
    Course* prereq;
    vector<Course*> childrenCourse;

    // Null constructor
    Course() : name(""), startTime(-1), endTime(-1), day(-1), prereq(nullptr), childrenCourse(vector<Course*>()) {}

    // Course constructor
    Course(string name, startTime starttime, endTime endtime, day day, prereq prereq) : 
        name(name), startTime(starttime), endTime(endtime), prereq(prereq), 
        day(day), childrenCourse(vector<Course*>()) {}

    // Add the course to childcourse list
    void addChild(Course* child) {
      childrenCourse.add(child);
    }

    /* TODO */
    // void take() {
    //     taken = true;
    // }

};

#endif  // COURSE_HPP