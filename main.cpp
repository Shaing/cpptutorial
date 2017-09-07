#include <iostream>
#include <string>
#include <memory>
#include "main.h"

using namespace std;

enum class WHICH : unsigned int
{
    B = 1,
    C,
    D,
    E,
};

class A
{
public:
    A() : setting("pure"){ cout << "a ctor: " << setting << endl; }
    ~A(){}
    virtual void set(const string& str){ setting = str; }
    virtual void scan()=0;
    virtual const string& get(){ return setting; }

private:
    string setting;
};

class Ai
{
public:
    Ai(){}
    ~Ai(){}
    virtual void set(const string& str){ setting = str; }
    virtual void scan(){ cout << "class Ai scan" << endl; }
    virtual const string& get(){ return setting; }

private:
    string setting;
};

class B : public A
{
public:
    void scan() override
    {
        set("B of A");
        cout << "scan by: " << get() << endl;
    }
};

class Bi : public Ai
{
public:
    Bi(){ cout << "Class Bi ctor" << endl; }
};

class Bc
{
public:
    Bc()
    { 
       cout << "Class Bc ctor" << endl;
       Ai().scan();
    }
private:
    //Ai ai;
};

class C : public A
{
public:
    void scan() override
    {
        set("C of A");
        cout << "scan by: " << get() << endl;
    }
};

class Ci : public Ai
{
public:
    Ci(){ cout << "Class Ci ctor" << endl; }
};

class D : public A
{
public:
    void scan() override
    {
        set("D of A");
        cout << "scan by: " << get() << endl;
    }
};

A* CREATE(const WHICH& which)
{
    switch(which)
    {
        case WHICH::B:
            return new B();
            break;
        case WHICH::C:
            return new C();
            break;
        case WHICH::D:
            return new D();
            break;
        default:
            cout << "nullptr!" << endl;
            return nullptr;
            break;
    }
}

int main(int argc, char* argv[])
{
    std::cout << "=======================================================================" << std::endl;
    std::cout << TITLE << "\t\t";
    std::cout << "Built Time/Date: " << __TIME__ << " / " << __DATE__ << std::endl;;
    std::cout << "=======================================================================" << std::endl;

    // poly
    cout << "below is poly:" << endl;
    auto in = 1;
    while(in)
    {
        cin >> in;
        unique_ptr<A> a(CREATE(WHICH(in)));
        if(a != nullptr)
            a->scan();
    }
    cout << "\n";
    // inher
    cout << "below is inher:" << endl;
    //Bi bi;
    //bi.scan();
    Bi().scan();
    Ci().scan();
    cout << "\n";
    //Aggregation
    cout << "below is Aggregation:" << endl;
    Bc bc;

    return 0;
}