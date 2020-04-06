#include <iostream>

template <typename T>
class vector {

    private:
        T* elem;
        int sz;
        
    public:
        vector(int s);
        ~vector() {delete[] elem;};

        T& operator[](int i);
        const T& operator[](int i) const;
        int size() const {return sz;}
};

template <typename T>
vector<T>::vector(int s)
{
    if(s >= 0) 
    {
        elem = new T[s];
        sz = s;
    }
    
}

template <typename T>
T& vector<T>::operator[](int i)
{
    if(i >= 0 ) return elem[i];
    else throw std::out_of_range{"out_of_range"};
}

template <typename T>
const T& vector<T>::operator[](int i) const
{
    if(i >= 0 ) return elem[i];
    else throw std::out_of_range{"out_of_range"}; 
}