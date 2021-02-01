/**
 * Read from a file and build a course tree for each quarter
 */

#include "CourseTree.hpp"
#include "Course.hpp"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

/* Default constructor */
CourseTree::CourseTree() {}

/* Build the courseTree dataset file.
 * Each line of the dataset file must be formatted as:
 * Couesenum<tab> Days<tab> Time<tab> Prereq<tab> coReq
 * If course A is the prerequisite of course B, course B will be a 
 * leave for course A.
 */
bool courseTree::buildTreeFromFile(const char* filename) {
    ifstream infile(filename);
    bool readHeader = false;

    while (infile) {
        string s;
        if (!getline(infile, s)) break;     // if the file is empty, exit the loop

        // skip the header of the file
        if (!readHeader) {
            readHeader = true;
            continue;
        }

        // read each line of the dataset, each line represent a course
        istringstream ss(s);
        vector<string> record;
        while (ss) {
            string str;
            if (!getline(ss, str, '\t')) break;
            record.push_back(str);
        }

        // if format is wrong, skip current line
        if (record.size() != 5) {
            continue;
        }

        // extract the information
        string courseNum(record[0]);
        string days(record[1]);
        string time(record[2]);     // read in as a string
        string prereq(record[3]);
        string coreq(record[4]);

        // Build the tree
        // parse start time and end time
        vector<int> timevector = parseTime(time);
        int start = timevector[0];
        int end = timevector[1];

        // parse day
        int parsedday = -1;
        if (days == "MWF") {
            parsedday = 135;
        }

        if (days == "TTh") {
            parsedday = 24;
        }

        // If no prereq, the course should be connected directly to the root.
        if (prereq == "None") {
            Course* currCourse = new Course(courseNum, start, end, parsedday, root);
            root->childrenCourse.add(currCourse);
        }

        // If has prereq, set the course to the leave of the prereq, update
        // prereq's children vector
        else {
            // need to support multiple prereq. Course* parentCourse = getCourse(prereq)
        }
    }

    // if failed to read the file, clear the graph and return
    if (!infile.eof()) {
        cerr << "Failed to read " << filename << endl;
        return false;
    }
    infile.close();

    return true;
}

// TODO
Course* getCourse(string name) {
    
}

// TODO
vector<string> parsePrereq(string prereq) {

}

/* TODO
 * two times are splited by - . 
 * store the starttime into vector[0], endtime into vector[1]
 */
vector<int> parseTime(string timeStr) {
    
}

/* generate a schedule for the current quarter */
void generateschedule(vector<Course>& schedule, vector<string>& majorRequirement) {}

/* destructor */
~CourseTree(){}
