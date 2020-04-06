#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string::iterator> find_all(string& s, char c)
{
    vector<string::iterator> res;

    for(string::iterator p = s.begin(); p != s.end(); p++)
    {
        if(*p == c)
            res.push_back(p);
    }

    return res;
}

int main()
{
    string str = "Ciao, sono sono Alfredo e vivo a Milano";
    char c = 'a';

    for(auto p : find_all(str, c))
    {
        if(*p != c)
            cerr << "A bug!\n";
        else
            cout << *p;
    }
}