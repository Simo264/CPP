#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
    // |==============================================|
    // |map<Key, Value> --> Key = String, Value = int |
    // |==============================================|

    map<string, int> phone_book =
    {
        {"David", 12356},
        {"Karl", 24878},
        {"Arthur", 55432}
    };

    cout << phone_book["David"] << endl;  //--> 12356
    cout << phone_book["Simone"] << endl; // --> 0 (Doesn't exist the string "Simone")

    cout << "\nPrint list:\n";
    for(auto a : phone_book)
    {
        cout << a.first << " " << a.second << endl;
    }
    
}