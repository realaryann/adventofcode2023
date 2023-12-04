#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;
 
int main()
{
    ifstream book;
    book.open("input1.txt");
    string word;
    int sum = 0;
    while(book>>word)
    {
        int rememberlow;
        int top,bottom;
        for(int i = 0; i<word.size(); i++)
        {
            if (isdigit(word[i]))
            {
                bottom = word[i] - '0';
                rememberlow = i;
                break;
            }
        }
        for(int j = word.size()-1; j>=0; j--)
        {
            if (isdigit(word[j]))
            {
                top = word[j] - '0';
                break;
            }
        }
        int currdigit = bottom*10+top;
        sum=sum+currdigit;
    }
    cout<<sum;
    return 0;
}

