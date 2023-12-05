#include <iostream>
#include <unordered_map>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    ifstream file;
    file.open("input2.txt");
    string str;
    file>>str;
    file>>str;
    for(int i = 0; i<100; i++) //100 cases
    {
        unordered_map<string, int> hash;
        while(str != "Game")
        {
            int num;
            file>>num;
            file>>str;
            hash[str]+=num;
            cout<<hash[str]<<endl;
            break;
        }
        file>>str;
    }
    return 0;
}


