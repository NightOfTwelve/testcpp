//
// Created by ThinkPad on 2025-05-08.
//

#include <iostream>

//using namespace std;

using std::cout;
using std::endl;

// https://www.cnblogs.com/QG-whz/p/4909359.html

class Base
{
public:

    Base(int i) :baseI(i){};

    int getI(){ return baseI; }

    static void countI(){};

    virtual ~Base(){}

    virtual void print(void){ cout << "Base::print()" << endl; }



private:

    int baseI;

    static int baseS;
};


int main11() {
    Base b(1000);
    b.print();
    return 0;
}



void testBase( Base&p)
{
    cout << "对象的内存起始地址：" << &p << endl;
    cout << "type_info信息:" << endl;
    RTTICompleteObjectLocator str = *((RTTICompleteObjectLocator*)*((int*)*(int*)(&p) - 1));


    string classname(str.pTypeDescriptor->name);
    classname = classname.substr(4, classname.find("@@") - 4);
    cout <<  "根据type_info信息输出类名:"<< classname << endl;

    cout << "虚函数表地址:" << (int *)(&p) << endl;

    //验证虚表
    cout << "虚函数表第一个函数的地址：" << (int *)*((int*)(&p)) << endl;
    cout << "析构函数的地址:" << (int* )*(int *)*((int*)(&p)) << endl;
    cout << "虚函数表中，第二个虚函数即print（）的地址：" << ((int*)*(int*)(&p) + 1) << endl;

    //通过地址调用虚函数print（）
    typedef void(*Fun)(void);
    Fun IsPrint=(Fun)* ((int*)*(int*)(&p) + 1);
    cout << endl;
    cout<<"调用了虚函数";
    IsPrint(); //若地址正确，则调用了Base类的虚函数print（）
    cout << endl;

    //输入static函数的地址
    p.countI();//先调用函数以产生一个实例
    cout << "static函数countI()的地址：" << p.countI << endl;

    //验证nonstatic数据成员
    cout << "推测nonstatic数据成员baseI的地址：" << (int *)(&p) + 1 << endl;
    cout << "根据推测出的地址，输出该地址的值：" << *((int *)(&p) + 1) << endl;
    cout << "Base::getI():" << p.getI() << endl;

}

int main() {
    Base b(1000);
    testBase(b);
}

