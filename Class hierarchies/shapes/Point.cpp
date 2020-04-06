class Point{

    private:
        int x;
        int y;

    public:
        Point(int xx, int yy) :x{xx}, y{yy} {};
        ~Point() {};
        int X() {return x;}
        int Y() { return y;}
};