//
// Created by ThinkPad on 2025-05-08.
//


#include <iostream>

using std::cout;
using std::endl;

class B {
public:
    int ib;

public:
    B(int i=1) :ib(i){}
    virtual void f() { cout << "B::f()" << endl; }
    virtual void Bf() { cout << "B::Bf()" << endl; }
};

class B1 : virtual public B {
public:
    int ib1;

public:
    B1(int i = 100 ) :ib1(i) {}
    virtual void f() { cout << "B1::f()" << endl; }
    virtual void f1() { cout << "B1::f1()" << endl; }
    virtual void Bf1() { cout << "B1::Bf1()" << endl; }
};

class B2 : virtual public B {
public:
    int ib2;

public:
    B2(int i = 1000) :ib2(i) {}
    virtual void f() { cout << "B2::f()" << endl; }
    virtual void f2() { cout << "B2::f2()" << endl; }
    virtual void Bf2() { cout << "B2::Bf2()" << endl; }
};


class D : public B1, public B2 {
public:
    int id;

public:
    D(int i= 10000) :id(i){}
    virtual void f() { cout << "D::f()" << endl; }
    virtual void f1() { cout << "D::f1()" << endl; }
    virtual void f2() { cout << "D::f2()" << endl; }
    virtual void Df() { cout << "D::Df()" << endl; }
};


typedef void(*Fun)(void);

int main()
{
    D d;
    cout << "D对象内存大小为：" << sizeof(d) << endl;

    //取得B1的虚函数表
    cout << "[0]B1::vptr";
    cout << "\t地址：" << (int *)(&d) << endl;

    //输出虚表B1::vptr中的函数
    for (int i = 0; i<3; ++i) {
        cout << "  [" << i << "]";
        Fun fun1 = (Fun)*((int *)*(int *)(&d) + i);
        fun1();
        cout << "\t地址：\t" << *((int *)*(int *)(&d) + i) << endl;
    }

    //[1]
    cout << "[1]B1::vbptr ";
    cout << "\t地址：" << (int *)(&d) + 1 << endl;  //虚表指针的地址
    //输出虚基类指针条目所指的内容
    for (int i = 0; i < 2; i++) {
        cout << "  [" << i << "]";
        cout << *(int *)((int *)*((int *)(&d) + 1) + i);
        cout << endl;
    }


    //[2]
    cout << "[2]B1::ib1=" << *(int*)((int *)(&d) + 2);
    cout << "\t地址：" << (int *)(&d) + 2;
    cout << endl;

    //[3]
    cout << "[3]B2::vptr";
    cout << "\t地址：" << (int *)(&d) + 3 << endl;

    //输出B2::vptr中的虚函数
    for (int i = 0; i<2; ++i) {
        cout << "  [" << i << "]";
        Fun fun1 = (Fun)*((int *)*((int *)(&d) + 3) + i);
        fun1();
        cout << "\t地址:\t" << *((int *)*((int *)(&d) + 3) + i) << endl;
    }

    //[4]
    cout << "[4]B2::vbptr ";
    cout << "\t地址：" << (int *)(&d) + 4 << endl;  //虚表指针的地址
    //输出虚基类指针条目所指的内容
    for (int i = 0; i < 2; i++) {
        cout << "  [" << i << "]";
        cout << *(int *)((int *)*((int *)(&d) + 4) + i);
        cout << endl;
    }

    //[5]
    cout << "[5]B2::ib2=" << *(int*)((int *)(&d) + 5);
    cout << "\t地址: " << (int *)(&d) + 5;
    cout << endl;

    //[6]
    cout << "[6]D::id=" << *(int*)((int *)(&d) + 6);
    cout << "\t地址: " << (int *)(&d) + 6;
    cout << endl;

    //[7]
    cout << "[7]值=" << *(int*)((int *)(&d) + 7);
    cout << "\t\t地址：" << (int *)(&d) + 7;
    cout << endl;

    //间接父类
    //[8]
    cout << "[8]B::vptr";
    cout << "\t地址：" << (int *)(&d) + 8 << endl;

    //输出B::vptr中的虚函数
    for (int i = 0; i<2; ++i) {
        cout << "  [" << i << "]";
        Fun fun1 = (Fun)*((int *)*((int *)(&d) + 8) + i);
        fun1();
        cout << "\t地址:\t" << *((int *)*((int *)(&d) + 8) + i) << endl;
    }

    //[9]
    cout << "[9]B::id=" << *(int*)((int *)(&d) + 9);
    cout << "\t地址: " << (int *)(&d) +9;
    cout << endl;

    getchar();

    return 0;
}