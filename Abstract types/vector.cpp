#include <iostream>

class vector{

    private:
        int sz = NULL;
        double* elem = nullptr;

    public:
        vector() :sz{0}, elem{new double[0]} {};
        vector(int size) :sz{size}, elem{new double[size]} {};
        vector(std::initializer_list<double> list) :sz{static_cast<int>(list.size())}, elem{new double[list.size()]} {
            std::copy(list.begin(), list.end(), elem);
        };

        int size() const { return sz; };
        double& operator[](int i) { return elem[i]; };
};