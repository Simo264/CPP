#include <iostream>
using namespace std;

namespace mySpace{
    
    class complex{
        public:
            complex(int xx, char ch) :x{xx}, c{ch} {};

            int getX() {return x;};
            char getC() {return c;};

        private:
            int x;
            char c;
    };

    int main();
}

int mySpace::main()
{
    int x = 99;
    char c = 'f';

    mySpace::complex comp(x,c);
    cout << "X = " << comp.getX() << endl;
    cout << "C = " << comp.getC() << endl;

    getchar();

    return 0;
}

int main()
{
    return mySpace::main();
}