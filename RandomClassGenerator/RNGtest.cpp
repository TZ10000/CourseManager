#include<fstream>
#include<iostream>
#include<vector>
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
    cout << rand() % 1;
    
}
