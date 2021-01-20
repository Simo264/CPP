#include <iostream> 
using namespace std;

int main()
{
    //int i = cin.get(); 
    //cout << "i=" << i ;
    
    //char c;
    //cin.get(c);
    //cout << "c=" << c;
    
    /* 
    char buffer[20];
    cin.get(buffer, 20, '\n');                      // cin.get()
    cout << "Buffer[]=" << buffer << endl;
    
    cout << "put=";
    for(int i = 0; buffer[i]; i++)
        cout.put(buffer[i]);                        // cout.put()
    
    */

    
    //char buffer[10];
    //cin.read(buffer, 10);                         // read()
    //cout << "buffer[]=" << buffer << endl;
    //cout << "gcount=" << cin.gcount() << endl;    // gcount()

    char buffer[20];
    cin.get(buffer, sizeof(buffer), '\n');
    cout << "buffer[]="; cout.write(buffer, cin.gcount());

    cin.get();
    return 0;
}