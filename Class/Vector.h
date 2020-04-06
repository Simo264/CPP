#include <iostream>

class Vector
{
    private:
        double* elem = nullptr;
        int sz = 0;

    public:
        Vector();
        Vector(int size);
        Vector(std::initializer_list<double> list);

        int size() const;
        double& operator[](int i);
        void init_vector(int n);
        void read_vector();
};