class vector
{
private:
    int sz;
    double* elem;

public:
    vector(std::initializer_list<double> lst);
    vector(int s);
    ~vector();

    double& operator[](int i);
    int size() const { return sz; };
};

vector::vector(std::initializer_list<double> lst) :elem{new double[lst.size()]}, sz{static_cast<int>(lst.size())} //init with a list
{
    std::copy(lst.begin(), lst.end(), elem); //copy from lst into elem
}

vector::vector(int s) :sz{s}, elem{new double[s]} 
{
    for(int i = 0; i < s; i++)
        elem[i] = 0;
}

vector::~vector()
{
    delete[] elem;
}

double& vector::operator[](int i)
{
    return elem[i];
}