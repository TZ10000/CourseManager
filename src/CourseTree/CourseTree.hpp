/**
 * Tree to store all the course information for one quarter.
 */

#ifndef COURSETREE_HPP
#define COURSETREE_HPP

#include <iostream>
#include <vector>
#include "Course.hpp"
using namespace std;


/**
 * Tree that need to read a file to generate a complete course schedule for one 
 * quarter
 */
class CourseTree {
  protected:
    // TODO: add data structures used in actor graph

  public:
    Course* root = new Course();

    /* constructor */
    CourseTree();

    /* get a course node with ceratain course name */
    Course* getCourse(string name);

    /* Build a quarter's course tree from the txt file */
    bool buildTreeFromFile(const char* filename);

    /* parse the time string like 1800-1900 to start time and end time */
    vector<int> parseTime(string timeStr);

    /* parse the prereq "CSE1,CSE2" to two strings, store them into vector */
    vector<string> parsePrereq(string prereq);

    /* generate a schedule for the current quarter */
    void generateschedule(vector<Course>& schedule, vector<string>& majorRequirement);

    /* destructor */
    ~CourseTree();
};

#endif  // COURSETREE_HPP
