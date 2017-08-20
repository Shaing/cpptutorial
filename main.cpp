#include "main.h"
#include <iostream>
#include <map>
#include <string>

using namespace std;

class mem
{
public:
    mem() : i(0), y(0){}
    int i;
    int y;
};

class FOO
{
public:
    FOO() : i(100){}

    void set(const int& I)
    { 
        cout << "lI:" << I << endl;
        cout << "&I:" << &I << endl;
        i = I; 
        cout << "set::i:" << i << endl;
        cout << "set::&i:" << &i << endl;
    }

    void set(const int&& I)
    { 

        cout << "rI:" << I << endl;
        cout << "&I:" << &I << endl;
        i = I; 
        cout << "set::i:" << i << endl;
        cout << "set::&i:" << &i << endl;
    }
    const int& get(){ return i; }

private:
    int i;
};

int& get()
{
    //cout << i << endl;
    static int i = 9;
    cout << "31 get()::i: " << i << endl;
    cout << "32 get()::&i: " << &i << endl;
    return ++i;
}

void coutVal(const auto& x)
{
    cout << x << endl;
}


int main(int argc, char* argv[])
{
    std::cout << "=======================================================================" << std::endl;
    std::cout << TITLE << "\t\t";
    std::cout << "Built Time/Date: " << __TIME__ << " / " << __DATE__ << std::endl;;
    std::cout << "=======================================================================" << std::endl;
/*
    map<string, string> m;

    cout << "m size:" << m.size() << endl;
    m["MN"] = "";    
    cout << "m size:" << m.size() << endl;
    m["FW"] = "H";    
    cout << "m size:" << m.size() << endl;

    cout << "MN: " << m["MN"] << endl;
    m["MN"] = "HUANG";
    cout << "MN: " << m["MN"] << endl;
    cout << "m size:" << m.size() << endl;

    m["SN"] = "123";
    cout << "m size:" << m.size() << endl;
    m["SN"] = "456";
    cout << "m size:" << m.size() << endl;
*/
    FOO f;
    const int val = 1000; // rvalue
    const int* pavl = &val;
    cout << "&val:" << &val << endl;
    f.set(*pavl);
    f.set(19999);
    int i1 = f.get();
    cout << "i1: " << i1 << endl;

    int i = 0;
    cout << "&i: " << &i << endl;

    i = get(); 
    cout << "get(): " << get() << endl;
    cout << "&get(): " << &get() << endl;
    cout << "i: " << i << endl;
    cout << "75 &i: " << &i << endl;

    get() = 666;
    cout << "78 get(): " << get() << endl;


    //val = 1001;
    cout << val << endl;
    cout << "i1: " << i1 << endl;

    int ti = 999;
    cout << "&ti:" << &ti << endl;
    int &tri = ti;

    cout << "tri:" << tri << endl;
    cout << "&tri:" << &tri << endl;

    ti = 1999;
    cout << "tri:" << tri << endl;
    


   // int x = 255;
   // char cx = x;
   // unsigned char ucx = x;
   // signed char scx = x;
   // printf("%d\n", cx);
   // printf("%d\n", ucx);
   // printf("%d\n", scx);

    int &iii = ti;
    int *i4 = &iii;
    cout << iii << endl;
    cout << *i4 << endl;

    iii = i;
    cout << "120 iii: " << iii << endl;
    cout << "121 &iii: " << &iii << endl;
    cout << "122 ti: " << ti << endl;
    
    i4 = &i;
    cout << "125 i4: " << *i4 << endl;


    mem m;

    cout << "m.i &:" << &m.i << endl;
    cout << "m.y &" << &m.y << endl;

    const int &cri = 1;
    coutVal(cri);

    string s{"allen shaing"};
    coutVal(s);

    int &&rri = 111; // refernce rvalue
    coutVal(rri);
    cout << &rri << endl;

    int pri = 111; // copy temp
    int &ri = pri; // refernce lvalue
    coutVal(ri);





    return 0;
}