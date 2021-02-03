#include<fstream>
#include<iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <time.h>
using namespace std;


int main()
{
    label1:
    cout << "1";
    int i = 0;
    cin >> i;
    if(i == 1)
        goto label1;
    else
        cout << "finished" << endl;
    return 0;
    


}