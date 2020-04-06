#include "Circle.cpp"
#include <vector>

class Smiley : public Circle{

    private:
        std::vector<shape*> eyes;
        shape* mouth;

    public:
        Smiley(Point p, int r) :Circle{p,r}, mouth{nullptr} {}
        ~Smiley()
        {
            delete mouth;
            for(auto p : eyes) delete p;
        }

        void move(Point to) {}
        void rotate(int) {}

        void add_eyes(shape* s) {eyes.push_back(s); }
        void set_mouth(shape* s) { mouth = s;}
};