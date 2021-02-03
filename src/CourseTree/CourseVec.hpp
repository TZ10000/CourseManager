/**
 * struct coursevec that contains all the information
 */

#ifndef COURSEVEC_HPP
#define COURSEVEC_HPP

#include "Course.hpp"
#include <iostream>
#include <vector>
using namespace std;

/**
 * course* vector need to have backtrack function for build schdule
 */
class CourseVec {
  public:
    vector<Course*> content;
    CourseVec* from;

    // constructor
    CourseVec(vector<Course*> content, CourseVec* from) : 
        content(content), from(from) {}

};

#endif  // COURSEVEC_HPP