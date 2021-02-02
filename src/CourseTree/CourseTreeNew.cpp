#include "CourseTree.hpp"
#include "Course.hpp"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

vector<string> StringParse(string str)
{
    // Used to split string around spaces.
    istringstream ss(str);
    vector<string> outstr;
    string word; // for storing each word
 
    // Traverse through all words
    // while loop till we get 
    // strings to store in string word
    while (ss >> word) 
    {
        outstr.push_back(word);
    }
    return outstr;
}


vector<int> removeDupWord(string str)
{
    string word = "";
    vector<string> outstr;
    vector<int> outint;
    for (auto x : str) 
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
// Driver code
int main()
{
    string str = "930-1130";
    //vector<string> out = removeDupWord(str);
    vector<int> out = removeDupWord(str);
    for (auto x : out)
    {
        cout << x << endl;
    }
    return 0;
}
 