#include <iostream>
#include <list>
#include <vector>
#include "Person.cpp"
using namespace std;

void people_to_string(list<Person>& people)
{
    for(auto a : people)
        cout << a.age << " " << a.name << "\n";
}

bool has_char(string& s, char c)
{
    auto p = find(s.begin(), s.end(), c); 
    if(p != s.end()) //find() returns end() to indicate 'not found'
        return true;
    else 
        return false;
}

int main()
{
    
    list<Person> people = 
    {
        {"Simone", 20},
        {"Ciccio", 23},
        {"Alfredo", 65}
    };

    string str = "Ciao, sono sono Alfredo e vivo a Milano";
    char c = 'z';


    if(has_char(str,c) == true)
        cout << "La lettera '" << c << "' e' presente!";
    else
        cout << "La lettera '" << c << "' NON è presente!";
}