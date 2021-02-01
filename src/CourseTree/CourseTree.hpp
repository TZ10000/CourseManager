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

    /* Build a quarter's course tree from the txt file */
    bool buildTreeFromFile(const char* filename);

    /* generate a schedule for the current quarter */
    void generateschedule(vector<Course>& schedule, vector<string>& majorRequirement);

    /* destructor */
    ~CourseTree();
};

#endif  // COURSETREE_HPP
