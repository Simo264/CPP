#include "Point.cpp"

class shape{

    public:
        virtual Point center() const = 0;
        virtual void move(Point to) = 0;
        virtual void rotate(int angle) = 0;

        ~shape() {};
};