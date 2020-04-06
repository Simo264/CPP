#include <iostream>
#include <list>
#include "vector.cpp"
#include "container.cpp"
using namespace std;

/* v e c t o r _ c o n t a i n e r */
class vector_container : public Container{
    
    private:
        vector v;

    public:
        vector_container(int s) :v(s) {}
        ~vector_container() {}

        int size() const {return v.size();}
        double& operator[] (int i) {return v[i];}
};

/* v e c t o r _ c o n t a i n e r */
class list_container : public Container{
    list<double> lst;

    public:
        list_container() {}
        list_container(initializer_list<double> l) :lst{l} {}
        ~list_container(){}

        double& operator[](int i)
        {
            for(auto& x : lst)
            {
                if(i == 0) return x;
                --i;
            }
            throw out_of_range("list container");
        }
        int size() const { return lst.size(); }
};

void use(Container& c)
{
    const int sz = c.size();

    for(int i = 0; i < sz; i++)
        cout << c[i] << " ";
}

/* M A I N */

int main()
{
    vector_container vc(5);
    list_container lc {1,2,3,4,5,6,7};
}

