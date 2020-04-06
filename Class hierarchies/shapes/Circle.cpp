#include "shape.cpp"

class Circle : public shape{

    private:
        Point p; //center
        int r; //radius

    public:
        Circle(Point p, int rr) :p{p}, r{rr} {};
        Point center() const {return p;}
        int radius() const {return r;}
        
        void move(Point to) { p = to;}
        void rotate(int) {}
};