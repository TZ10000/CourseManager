/**
 * Tree to store all the course information for one quarter.
 */

#ifndef COURSETREE_HPP
#define COURSETREE_HPP

#include <iostream>
#include <vector>
#include "Course.hpp"
#include <map>
using namespace std;


/**
 * Tree that need to read a file to generate a complete course schedule for one 
 * quarter
 */
class CourseTree {
  protected:
    // TODO: add data structures used in actor graph

  public:
    map<string, Course*> allCourseMap;

    Course* root = new Course();

    /* constructor */
    CourseTree();

    /* get a course node with ceratain course name */
    Course* GetCourse(string name);

    /* Build a map (key: coursenum, val: Course) */
    bool BuildMapfromFile (string filename);

    /* Build a quarter's course tree from the txt file */
    void BuildTreeFromFile(const char* filename);

    /* parse the time string like 1800-1900 to start time and end time */
    vector<int> ParseTime(string timeStr);

    /* parse the prereq "CSE1,CSE2" to two strings, store them into vector */
    vector<string> ParsePrereq(string prereq);

    /* generate a schedule for the current quarter */
    void Generateschedule(vector<Course>& schedule, vector<string>& majorRequirement);
    /* parse the input string*/
    vector<string> StringParse(string str);
    /* destructor */
    ~CourseTree();
};

#endif  // COURSETREE_HPP
