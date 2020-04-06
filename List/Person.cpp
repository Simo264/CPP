#include <string>
class Person
{
public:
    std::string name;
    int age;

    Person(std::string n, int a) :name{n}, age{a} {}
    ~Person(){}
};