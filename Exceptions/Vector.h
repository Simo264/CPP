class Vector
{
private:
    double* elem = nullptr;
    int sz = 0;

public:
    Vector (int s);
    double& operator[](int i);
    int size() const;
};