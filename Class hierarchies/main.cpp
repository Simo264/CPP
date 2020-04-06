#include <iostream>
#include "./shapes/Smiley.cpp"
using namespace std;

int main()
{
    int r = 10;
    Point p(5,5);

    Circle c(p, r);
    p = c.center();
    cout << "X: " << p.X() << "\nY: " << p.Y() << "\nRadius: " << c.radius();

    Smiley sm(p,r);
}