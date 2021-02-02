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
void CourseTree::BuildTreeFromFile(const char* filename)
{

    for(auto x : allCourseMap)
    {
        if (x.second->preReqNum.at(0) == "None")
        {
            x.second->prereq.push_back(root);
            root->childrenCourse.push_back(x.second);
        }
        else
        {
            for (auto y : x.second->preReqNum)
            {
                x.second->prereq.push_back(allCourseMap.at(y));
                allCourseMap.at(y)->childrenCourse.push_back(x.second);
            }
        }
    }
    // ifstream infile(filename);
    // bool readHeader = false;

    // while (infile)
    // {
    //     string s;
    //     if (!getline(infile, s)) break;     // if the file is empty, exit the loop

    //     // skip the header of the file
    //     if (!readHeader)
    //     {
    //         readHeader = true;
    //         continue;
    //     }

    //     // read each line of the dataset, each line represent a course
    //     istringstream ss(s);
    //     vector<string> record;
    //     record = StringParse(s);
    //     // while (ss) {
    //     //     string str;
    //     //     if (!getline(ss, str, '\t')) break;
    //     //     record.push_back(str);
    //     // }

    //     // if format is wrong, skip current line
    //     if (record.size() != 5)
    //         continue;

    //     // extract the information
    //     string courseNum(record[0]);
    //     string days(record[1]);
    //     string time(record[2]);     // read in as a string
    //     string prereq(record[3]);
    //     string coreq(record[4]);

    //     // Build the tree
    //     // parse start time and end time
    //     vector<int> timevector = ParseTime(time);
    //     int start = timevector[0];
    //     int end = timevector[1];

    //     // parse day
    //     int parsedday = -1;
    //     if (days == "MWF")
    //         parsedday = 135;

    //     if (days == "TTh")
    //         parsedday = 24;

    //     // If no prereq, the course should be connected directly to the root.
    //     if (prereq == "None")
    //     {
    //         Course* currCourse = new Course(courseNum, start, end, parsedday, root);
    //         root->childrenCourse.push_back(currCourse);
    //     }

    //     // If has prereq, set the course to the leave of the prereq, update
    //     // prereq's children vector
    //     else
    //     {
    //         // need to support multiple prereq. Course* parentCourse = getCourse(prereq)
    //     }
    // }

    // if failed to read the file, clear the graph and return
    // if (!infile.eof())
    // {
    //     cerr << "Failed to read " << filename << endl;
    //     return false;
    // }
    // infile.close();
    // return false;

}

bool CourseTree::BuildMapfromFile(string filename)
{
    ifstream infile(filename);
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
        record = StringParse(s);
        // while (ss) {
        //     string str;
        //     if (!getline(ss, str, '\t')) break;
        //     record.push_back(str);
        // }

        // if format is wrong, skip current line
        if (record.size() != 5)
            continue;

        // extract the information
        courseNum = record[0];
        string days(record[1]);
        string time(record[2]);
        vector<string> prereq = ParsePrereq(record[3]);
        vector<string> coreq = ParsePrereq(record[4]);

        // Build the tree
        // parse start time and end time
        vector<int> timevector = ParseTime(time);
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
    
        allCourseMap.insert(pair<string,Course*>(courseNum,newCourse));  // leave the pointer part empty
        // if failed to read the file, clear the graph and return
        if (!infile.eof())
        {
            cerr << "Failed to read " << filename << endl;
            return false;
        }
        infile.close();
    }
    return true;
}

// TODO
Course* CourseTree::GetCourse(string name)
{
    
}

// TODO
vector<string> CourseTree::ParsePrereq(string prereq)
{    
    string word = "";
    vector<string> outstr;
    for (auto x : prereq) 
    {
        if (x == '-')
        {
            outstr.push_back(word);
            word = "";
        }
        else {
            word = word + x;
        }
    }
    outstr.push_back(word);
    return outstr;
}

/* TODO
 * two times are splited by - . 
 * store the starttime into vector[0], endtime into vector[1]
 */
vector<int> CourseTree::ParseTime(string timeStr) 
{
    string word = "";
    vector<string> outstr;
    vector<int> outint;
    for (auto x : timeStr) 
    {
        if (x == '-')
        {
            outstr.push_back(word);
            word = "";
        }
        else {
            word = word + x;
        }
    }
    outstr.push_back(word);
    for (auto x : outstr)
    {
        outint.push_back(stoi(x));
    }
    return outint;
}

/* generate a schedule for the current quarter */
void CourseTree::Generateschedule(vector<Course>& schedule, vector<string>& majorRequirement) {}

/* parse the input string*/
vector<string> CourseTree::StringParse(string str)
{    
    vector<string> outstr;
    istringstream ss(str);
    string word; // for storing each word
    // Traverse through all words
    // while loop till we get 
    // strings to store in string word
    while (ss >> word) 
        outstr.push_back(word);
    
    return outstr;
}

/* destructor */
CourseTree::~CourseTree()
{

}
