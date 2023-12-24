#include <iostream>
#include <unordered_map>
#include <fstream>
#include <cctype>
#include <string>
#include <cstdlib>

using namespace std;

int main()
{
    ifstream file;
    file.open("input2.txt");
    string str;
    file>>str;
    int sum = 0;
    while(file>>str) //100 cases
    {
        int semicount=0;
        int corr = 0;
        str.pop_back();
        int id = atoi(str.c_str());
        unordered_map<string, int> hash;
        int set = 0;
        while(str != "Game")
        {
            int num;
            file>>num;
            if (num == 0){
                if ((hash["red"] <= 12) && (hash["blue"]<=14) && (hash["green"] <=13))
                {
                    if (corr==semicount)
                    sum=sum+id;
                    hash.clear();
                }
                hash.clear();
                file.clear();
            }
            file>>str;
            if (!isalpha(str[str.size()-1]))
            {
                if (str[str.size()-1] == ';'){
                    str.pop_back();
                    hash[str] = num;
                    // check the ting
                    semicount++;
                    for(auto itr = hash.begin(); itr!= hash.end(); itr++)
                    {
                        cout<<itr->first<<" "<<itr->second<<endl;
                    }
                    cout<<endl;
                    if ((hash["red"] <= 12) && (hash["blue"]<=14) && (hash["green"] <=13))
                    {
                        corr++;
                        hash.clear();
                        set = 1;
                    }
                    hash.clear();
                }
                else
                    str.pop_back();
            }
            if (!set)
            {
                hash[str] =num;
            }
            set=0;
        }
        cout<<sum;
    }

    return 0;
}


