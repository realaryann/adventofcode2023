#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
int main()
{
    int sum = 0;
    ifstream file;
    file.open("input4.txt");
    string str;
    //Collect all the inputs for a given instance in an array
    for (int i = 0; i<202; i++) //202 cases
    {
        int count = 0;
        int inp;
        file>>str;
        file>>str;
        vector<int> sol;
        // reached the solution list
        while(file>>inp)
        {
            sol.push_back(inp);
        }
        file.clear();
        file>>str;
        //reached the input list
        vector<int> input;
        int num;
        while (file>>num)
        {
            input.push_back(num);
        }
        file.clear();
        //sol now contains all the solutions, we must check them against the inputs
        //check and assign a point to every match
        for(int i = 0; i<input.size(); i++)
        {
            for(int j = 0; j<sol.size(); j++)
            {
                if (input[i] == sol[j])
                {
                    count++;
                }
            }
        }
        int addthis = (1<<(count-1));
        if (addthis>0)
        sum=sum+addthis;
    }
    cout<<sum;
    return 0;
}
