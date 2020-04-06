#include "vector.cpp"
using namespace std;

void read(vector<std::string>& v)
{
    for(int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
}

int main()
{
    vector<std::string> vs (5);
    vs[0] = "Ciao";
    vs[1] = "come";
    vs[2] = "stai";
    vs[3] = "?";
    vs[4] = "?";

    read(vs);
}