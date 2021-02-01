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

    bool taken;         // if the student took the course

    // Null constructor
    Course() : name(""), startTime(-1), endTime(-1), taken(false) {}

    // Course constructor
    Course(string name, startTime starttime, endTime endtime) : taken(false) {}

    /* TODO */
    void take() {
        taken = true;
    }

};

#endif  // COURSE_HPP