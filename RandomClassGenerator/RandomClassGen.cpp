#include<fstream>
#include<iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <time.h>
using namespace std;

struct Course
{
    string major;       // short abbrev of the major name
    int classnum;       // the class number
    int starttime;      // the time that the class is offerred
    int endtime;        // the time that the class ends
    string premajor;    // the major name of the pre-requisite class
    string preclassnum; // the class number of the pre-requisite class
};

vector<int> Randomshuffle(int shufflenum)
{
    vector<int> initialvec;
    vector<int> outputvec;
    for (int i = 0; i < shufflenum; i++)
    {
        initialvec.push_back(i);
    }
    int temp = shufflenum;
    for (int i = 0; i < shufflenum; i++)
    {
        int rdm = rand() % temp;  // find a random within it
        outputvec.push_back(initialvec.at(rdm));  // add the number in that place to the output vector
        initialvec.at(rdm) = initialvec.at(initialvec.size() - 1);
        initialvec.pop_back();
        temp--;
    }
    return outputvec;
}


int main()
{
    string newmajor = "CSE";
    vector<int> randomCoursesNum_Last1 = Randomshuffle(10);  // this is a vector that contains the last 2 digits of the class number
    vector<int> randomCoursesNum_Last2 = Randomshuffle(10);
    vector<int> randomCoursesNum;
    
    vector<int> randomStartTime;
    vector<int> randomEndTime;
    /* this is a random time from 800 - 1700, class can start any where from these time but only
    from 00 or 30. for example, a 845 class is not legal*/

    vector<int> randomPreRequisite; 
    /* contains the pre Requisite class of the every class, the class number of the preRequisite
    will not be larger than its own preRequisite */

    /* generating 50 random course numbers 1__ 2__ 3__ 4__ 5__ all have 10 courses */
    for (int i = 1; i < 6; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            randomCoursesNum.push_back(i * 100 + randomCoursesNum_Last2.at(j) * 10 + randomCoursesNum_Last1.at(j));
        }
    }
    sort(randomCoursesNum.begin(),randomCoursesNum.end());
    // test case
    // for (int i = 0; i < randomCoursesNum.size(); i++)
    //     cout << randomCoursesNum[i] << endl;

    /* Generating Time slots*/
    for (int i = 0; i < 50; i++)
    {
        int hour = rand() % (18-8) + 8;  // generate from 800 to 1700
        int minuteval = rand() % 10;
        // get the minute, see if they start from 30 or 0
        if (minuteval < 5)
        {
            minuteval = 30;
        }
        else
        {
            minuteval = 0;
        }
        randomStartTime.push_back(hour * 100 + minuteval);
    }
    // test case
    // for (int i = 0; i < randomStartTime.size(); i++)
    //     cout << randomStartTime[i] << endl;
    randomEndTime = randomStartTime;
    for (int i = 0; i < 50; i++)
    {
        int rdm = rand() % 10;
        if (rdm < 5)
            randomEndTime.at(i) = randomEndTime.at(i) + 100;  // 1 hour class
        else
            randomEndTime.at(i) = randomEndTime.at(i) + 200;  // 2 hour class
    }
    // test case
    // for (int i = 0; i < randomEndTime.size(); i++)
    //     cout << randomEndTime[i] << endl;

    /* Generating random pre-Requisite */
    for (int i = 0; i < 10; i++)
    {
        randomPreRequisite.push_back(0);  // the first 10 classes will not have preRequi;
    }

    for (int i = 1; i < 5; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            int rdm = rand() % 2;
            if (rdm == 0) // If this class has 0 PreRe
                randomPreRequisite.push_back(0);
            else if (rdm == 1) // If this class has 1 PreRe
            {
                randomPreRequisite.push_back(randomCoursesNum.at(rand() % i * 10 + rand() % (j + 1)));
            } 
        }
    }
    // test case
    // for (int i = 0; i < randomPreRequisite.size(); i++)
    //     cout << randomPreRequisite.at(i) << endl;
    // 为什么我每次跑出来的结果都是一样啊草
    ofstream outfile ("CSECourseSchedule.txt");  // Create a new text file to contain the course information
    for (int i = 0; i < randomCoursesNum.size(); i++)
    {
        //outfile << randomCoursesNum.at(i) << endl;
        int courseNum = randomCoursesNum.at(i);
        int startTime = randomStartTime.at(i);
        int endTime = randomEndTime.at(i);
        int preRe = randomPreRequisite.at(i);
        if (preRe == 0)
            outfile << "CSE" << courseNum << ' ' << startTime << '-' << endTime << ' ' << endl;
        else
            outfile << "CSE" << courseNum << ' ' << startTime << '-' << endTime << ' ' << "CSE" << preRe << endl;
    }

    return 0;
}
