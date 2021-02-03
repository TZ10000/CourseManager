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
        newCourse->taken = false;
        newCourse->startTime = start;
        newCourse->endTime = end;
        newCourse->preReqNum = prereq;
    
        allCourseMap.insert(pair<string,Course*>(courseNum,newCourse));  // leave the pointer part empty
        // if failed to read the file, clear the graph and return

    }
    if (!infile.eof())
    //if(infile.eof())
    {
        cerr << "Failed to read " << filename << endl;
        return false;
    }
    infile.close();
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

/* generate a schedule for the current quarter 
 * return false if major does not exist
 */
bool CourseTree::Generateschedule(string major) {
    // get the need to take information from the maps
    try {
        vector<string> majorReqirement = majorCourseList.at(major);
        int numElective = majorElectiveNum.at(major);
        vector<string> electiveList = majorElectiveList.at(major);
    } catch (const std::exception& e) {
        // major not exist
        return false;
    }

    // store the courses that can be take currently
    vector<Course*> cantake();  
    Course* curr;
    for (string s : majorReqirement) {
        try {
            curr = allCourseMap.at(s);           
            // check if the course was taken
            if (curr->taken == false) {
                cantake.push_back(curr);
            }
            
        } catch (const std::exception& e) {
            continue;
        }
    }

    vector<vector<Course*>> possiblePermutations();
    // Check if time overlapped by permutation, save all permutations that
    // have size = 4
    for (int i = 0; i < cantake.size(); i++) {
        Course* firstCourse = cantake.at(i);

        // j,k,l loop performs permutations for a element
        for (int j = i + 1; j < cantake.size(); j++) {
            Course* secondCourse = cantake.at(j);
            // if second course overlap with first course
            if (((secondCourse->startTime > firstCourse->startTime) && (secondCourse->startTime < firstCourse->endTime)) || 
                ((secondCourse->endTime > firstCourse->startTime) && (secondCourse->endTime < firstCourse->endTime))) {
                    continue;
            }
            
            for (int k = j + 1; k < cantake.size(); k++) {
                Course* thirdCourse = cantake.at(k);
                // if third course overlap with the previous ones
                if (((thirdCourse->startTime > firstCourse->startTime) && (thirdCourse->startTime < firstCourse->endTime)) ||
                    ((thirdCourse->endTime > firstCourse->startTime) && (thirdCourse->endTime < firstCourse->endTime)) ||
                    ((thirdCourse->startTime > secondCourse->startTime) && (thirdCourse->startTime < secondCourse->endTime)) ||
                    ((thirdCourse->endTime > secondCourse->startTime) && (thirdCourse->endTime < secondCourse->endTime))) {
                        continue;
                }
                
                for (int l = k + 1; l < cantake.size(); l++) {
                    Course* fourthCourse = cantake.at(l) {
                    // if fourth course overlap
                    if (((fourthCourse->startTime > firstCourse->startTime) && (fourthCourse->startTime < firstCourse->endTime)) || 
                        ((fourthCourse->endTime > firstCourse->startTime) && (fourthCourse->endTime < firstCourse->endTime))
                        ((fourthCourse->startTime > secondCourse->startTime) && (fourthCourse->startTime < secondCourse->endTime)) || 
                        ((fourthCourse->endTime > secondCourse->startTime) && (fourthCourse->endTime < secondCourse->endTime))
                        ((fourthCourse->startTime > thirdCourse->startTime) && (fourthCourse->startTime < thirdCourse->endTime)) || 
                        ((fourthCourse->endTime > thirdCourse->startTime) && (fourthCourse->endTime < thirdCourse->endTime))) {
                            continue;
                    }

                    // else this is one possible permutation
                    possiblePermutations.push_back({firstCourse, secondCourse, thirdCourse, fourthCourse});
                    }
                }
            }
        }
    }


    return true;
}

bool CourseTree::buildMajorVector(string filename) {
    ifstream infile(filename);
    bool readHeader = false;

    while(infile)
    {
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
        if (record.size() != 4)
            continue;

        // extract the information
        string major(record[0]);
        vector<string> requiredCourses = ParsePrereq(record[1]);
        string requiredElective(record[2]);
        vector<string> electiveList = ParsePrereq(record[3]);
    
        // insert the variables read into the map
        majorCourseList.insert(pair<string, vector<string>>(major,requiredCourses));
        majorElectiveNum.insert(pair<string, int>(major, requiredElective));
        majorElectiveList.insert(pair<string, vector<string>>(major,electiveList));
    }

    if (!infile.eof())
    //if(infile.eof())
    {
        cerr << "Failed to read " << filename << endl;
        return false;
    }
    infile.close();
    return true;
}

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