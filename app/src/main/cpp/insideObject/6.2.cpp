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


typedef void(*Fun)(void);
int main_vs() {
    B1 a;
    cout << "B1对象内存大小为：" << sizeof(a) << endl;// 16

    //取得B1的虚函数表
    cout << "[0]B1::vptr";
    cout << "\t地址：" << (int *)(&a) << endl;

    //输出虚表B1::vptr中的函数
    for (int i = 0; i < 2; ++i) {
        cout << "  [" << i << "]";
        Fun fun1 = (Fun) * ((int *) *(int *)(&a) + i);
        fun1();
        cout << "\t地址：\t" << ((int *) *(int *) (&a) + i) << endl;
    }

    //[1]
    cout << "[1]vbptr ";
    cout << "\t地址：" << (int *) (&a) + 1 << endl;  //虚表指针的地址
    //输出虚基类指针条目所指的内容
    for (int i = 0; i < 2; i++) {
        cout << "  [" << i << "]";
        cout << *(int *) ((int *) *((int *) (&a) + 1) + i);
        cout << endl;
    }


    //[2]
    cout << "[2]B1::ib1=" << *(int *) ((int *) (&a) + 2);
    cout << "\t地址：" << (int *) (&a) + 2;
    cout << endl;

    //[3]
    cout << "[3]值=" << *(int *) ((int *) (&a) + 3);
    cout << "\t\t地址：" << (int *) (&a) + 3;
    cout << endl;

    //[4]
    cout << "[4]B::vptr";
    cout << "\t地址：" << (int *) (&a) + 3 << endl;

    //输出B::vptr中的虚函数
    for (int i = 0; i < 2; ++i) {
        cout << "  [" << i << "]";
        Fun fun1 = (Fun) * ((int *) *((int *) (&a) + 4) + i);
        fun1();
        cout << "\t地址:\t" << *((int *) *((int *) (&a) + 4) + i) << endl;
    }

    //[5]
    cout << "[5]B::ib=" << *(int *) ((int *) (&a) + 5);
    cout << "\t地址: " << (int *) (&a) + 5;
    cout << endl;

    return 0;
}

// android
int main() {
    B1 a;
    cout << "B1对象内存大小为：" << sizeof(a) << endl;// 16

    //取得B1的虚函数表
    cout << "[0]B1::vptr";
    cout << "\t地址：" << (int *)(&a) << endl;

    // typeinfo
    cout << "\ttypeinfo 地址：\t" << ((int *)*(int *)(&a) - 1) << "\t值：\t0x" << std::hex << *((int *)*(int *)(&a) - 1) << endl;
    // offset to this
    cout << "\toffset to this 地址：\t" << ((int *)*(int *)(&a) - 2) << "\t值：\t0x" << std::hex << *((int *)*(int *)(&a) - 2) << endl;

    //输出虚表B1::vptr中的函数  TODO 6项??????
    for (int i = 0; i < 8; ++i) {
        cout << "  [" << i << "]";
        Fun fun1 = (Fun) * ((int *) *(int *)(&a) + i);
        //fun1();
        cout << "\t地址：\t" << ((int *)*(int *) (&a) + i) << "值：\t0x" << std::hex << *((int *) *(int *) (&a) + i) << endl;
    }

    //[1]
    cout << "[1]vbptr ";
    cout << "\t地址：" << (int *)(&a) + 1 << endl;  //虚表指针的地址
    cout << "\t值：0x" << std::hex << *((int *)(&a) + 1) << endl;  // 0x64



    //[2]
    cout << "[2]B1::ib1=" << *(int *) ((int *) (&a) + 2);
    cout << "\t地址：" << (int *) (&a) + 2;
    cout << endl;
//    for (int i = 0; i < 2; ++i) {
//        cout << "  [" << i << "]";
//        Fun fun1 = (Fun) * ((int *) *((int *) (&a) + 2) + i);
//        fun1();
//        cout << "\t地址:\t" << *((int *) *((int *) (&a) + 2) + i) << endl;
//    }

    //[3]
    cout << "[3]值=" << *(int *) ((int *) (&a) + 3);// 1 ib???
    cout << "\t\t地址：" << (int *) (&a) + 3;
    cout << endl;

    //[4]
    cout << "[4]B::vptr";
    cout << "\t地址：" << (int *)(&a) + 4 << endl;
    cout << "\t值：" << *((int *)(&a) + 4) << endl;

//    //输出B::vptr中的虚函数
//    for (int i = 0; i < 2; ++i) {
//        cout << "  [" << i << "]";
//        Fun fun1 = (Fun) * ((int *) *((int *) (&a) + 4) + i);
//        fun1();
//        cout << "\t地址:\t" << *((int *) *((int *) (&a) + 4) + i) << endl;
//    }

    //[5]
    cout << "[5]B::ib=" << *(int *) ((int *) (&a) + 5);
    cout << "\t地址: " << (int *) (&a) + 5;
    cout << "\t值: " << *((int *)(&a) + 5);
    cout << endl;

    return 0;
}