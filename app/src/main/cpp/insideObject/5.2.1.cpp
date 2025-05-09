//
// Created by ThinkPad on 2025-05-08.
//

#include <iostream>

using std::cout;
using std::endl;


class Base {
public:
    Base(int i) :baseI(i){};
    virtual ~Base(){}
    int getI(){ return baseI; }
    static void countI(){};
    virtual void print(void){ cout << "Base::print()"; }

private:
    int baseI;
    static int baseS;
};

class Base_2 {
public:
    Base_2(int i) :base2I(i){};
    virtual ~Base_2(){}
    int getI(){ return base2I; }
    static void countI(){};
    virtual void print(void){ cout << "Base_2::print()"; }

private:
    int base2I;
    static int base2S;
};

class Drive_multyBase :public Base, public Base_2 {
public:
    Drive_multyBase(int d) :Base(1000), Base_2(2000) ,Drive_multyBaseI(d){};
    virtual void print(void){ cout << "Drive_multyBase::print" ; }
    virtual void Drive_print(){ cout << "Drive_multyBase::Drive_print" ; }

private:
    int Drive_multyBaseI;
};


typedef void(*Fun)(void);

// https://www.cnblogs.com/QG-whz/p/4909359.html

int main_vs() {
    Drive_multyBase d(3000);
    //[0]
    cout << "[0]Base::vptr";
    cout << "\t地址：" << (int *)(&d) << endl;
    cout << "\tvtbl地址：" << std::hex << *(int *)(&d) << endl;

    int * vptrAddr = (int *)(&d);// 32位
    std::cout << "虚函数指针（vptr）的地址是：\t"<< vptrAddr << std::endl;

    int *vtblAddr = (int *)(*(int *)(&d));
    std::cout << "虚函数表（vtblAddr）的地址是：\t"<< vtblAddr << std::endl;
    std::cout << "虚函数表[0]：\t"<< std::hex << vtblAddr[0] << std::endl;
    std::cout << "虚函数表[1]：\t"<< std::hex << vtblAddr[1] << std::endl;
    std::cout << "虚函数表[2]：\t"<< std::hex << vtblAddr[2] << std::endl;
    std::cout << "虚函数表[3]：\t"<< std::hex << vtblAddr[3] << std::endl;


    //vprt[0]析构函数无法通过地址调用，故手动输出
    cout << "  [0]" << "Derive::~Derive" << endl;

    //vprt[1]
    cout << "  [1]";
    Fun fun1 = (Fun) * ((int*)(*(int*)(&d)) + 1);// *((int*)(*(int*)(&b)) + 1);
    fun1();
    cout << "\t地址:\t" << *((int *)*((int *)(&d))+1) << endl;


    //vprt[2]
    cout << "  [2]";
    Fun fun2 = (Fun)*((int *)*((int *)(&d)) + 2);
    fun2();
    cout << "\t地址:\t" << *((int *)*((int *)(&d)) + 2) << endl;


    //[1]
    cout << "[1]Base::baseI=" << *(int*)((int *)(&d) + 1);
    cout << "\t地址：" << (int *)(&d) + 1;
    cout << endl;


    //[2]
    cout << "[2]Base_::vptr";
    cout << "\t地址：" << (int *)(&d)+2 << endl;

    //vprt[0]析构函数无法通过地址调用，故手动输出
    cout << "  [0]" << "Drive_multyBase::~Derive" << endl;

    //vprt[1]
    cout << "  [1]";
    Fun fun4 = (Fun)*((int *)*((int *)(&d))+1);
    fun4();
    cout << "\t地址:\t" << *((int *)*((int *)(&d))+1) << endl;

    //[3]
    cout << "[3]Base_2::base2I=" << *(int*)((int *)(&d) + 3);
    cout << "\t地址：" << (int *)(&d) + 3;
    cout << endl;

    //[4]
    cout << "[4]Drive_multyBase::Drive_multyBaseI=" << *(int*)((int *)(&d) + 4);
    cout << "\t地址：" << (int *)(&d) + 4;
    cout << endl;

    getchar();

    return 0;
}


int main() {


    Drive_multyBase d(3000);
    //[0]
    cout << "[0]Base::vptr";
    cout << "\t地址：" << (int *)(&d) << endl;
    cout << "\tvtbl地址：" << std::hex << *(int *)(&d) << endl;

    int * vptrAddr = (int *)(&d);// 32位
    std::cout << "虚函数指针（vptr）的地址是：\t"<< vptrAddr << std::endl;// TODO how to calculate virtual table size???

    int *vtblAddr = (int *)(*(int *)(&d));
    std::cout << "虚函数表（vtblAddr）的地址是：\t"<< vtblAddr << std::endl;
    std::cout << "虚函数表[0]：\t"<< std::hex << vtblAddr[0] << std::endl;
    std::cout << "虚函数表[1]：\t"<< std::hex << vtblAddr[1] << std::endl;
    std::cout << "虚函数表[2]：\t"<< std::hex << vtblAddr[2] << std::endl;
    std::cout << "虚函数表[3]：\t"<< std::hex << vtblAddr[3] << std::endl;

    {

        //vprt[0]析构函数无法通过地址调用，故手动输出
        cout << "  [0]" << "Derive::~Derive" << endl;
        Fun fun0 = (Fun) * ((int*)(*(int*)(&d)));// (libnativetest.so`Drive_multyBase::~Drive_multyBase() + 1 at native-lib.cpp:41)
    //    fun0();
        cout << "\t地址:\t" << *((int *)*((int *)(&d))) << endl;

        //vprt[1]
        cout << "  [1]";
        Fun fun1 = (Fun) * ((int*)(*(int*)(&d)) + 1);// *((int*)(*(int*)(&b)) + 1);
    //    fun1();// 地址跟上一个不一样 (libnativetest.so`Drive_multyBase::~Drive_multyBase() + 1 at native-lib.cpp:41)
        cout << "\t地址:\t" << *((int *)*((int *)(&d))+1) << endl;


        //vptr[2]
        cout << "  [2]";
        Fun fun2 = (Fun)*((int *)*((int *)(&d)) + 2);
        fun2();
        cout << "\t地址:\t" << *((int *)*((int *)(&d)) + 2) << endl;

        //vptr[3]
        cout << "  [3]";
        Fun fun3 = (Fun)*((int *)*((int *)(&d)) + 3);
        fun3();
        cout << "\t地址:\t" << *((int *)*((int *)(&d)) + 3) << endl;

        //vptr[4] this offset
        int off = *((int *)*((int *)(&d)) + 4);// -8 ((~0xfffffff8 & 0xFFFFFFFF) + 1)
        cout << "\toffset:\t" << off << endl;// fffffff8  ((~0xfffffff8 & 0xFFFFFFFF) + 1) = 8
        cout << "\toffset:\t" << *(int *)((int *)*((int *)(&d)) + 4) << endl;
    }

    //[1]
    cout << "[1]Base::baseI=" << *(int*)((int *)(&d) + 1);// 1000
    cout << "\t地址：" << (int *)(&d) + 1;
    cout << endl;


    //[2]
    cout << "[2]Base_::vptr";
    cout << "\t地址：" << (int *)(&d)+2 << endl;

    {
        //vptr[0]析构函数无法通过地址调用，故手动输出
        cout << "  [0]" << "Drive_multyBase::~Derive" << endl;
        Fun fun4_0 = (Fun)*((int *)*((int *)(&d)+2));// (libnativetest.so`non-virtual thunk to Drive_multyBase::~Drive_multyBase() + 1 at native-lib.cpp)
        cout << "\t地址:\t" << *((int *)*((int *)(&d)+2)) << endl;

        //vptr[1]
        cout << "  [1]";
        Fun fun4 = (Fun)*((int *)*((int *)(&d)+2)+1);// (libnativetest.so`non-virtual thunk to Drive_multyBase::~Drive_multyBase() + 1 at native-lib.cpp)
        //fun4();
        cout << "\t地址:\t" << *((int *)*((int *)(&d)+2)+1) << endl;

        //vprt[2]
        cout << "  [2]";
        Fun fun5 = (Fun)*((int *)*((int *)(&d))+2);// (libnativetest.so`Drive_multyBase::print() + 1 at native-lib.cpp:44)
        fun5();
        cout << "\t地址:\t" << *((int *)*((int *)(&d))+2) << endl;
    }

    //[3]
    cout << "[3]Base_2::base2I=" << *(int*)((int *)(&d) + 3);// *((int *)(&d) + 3) -> 2000
    cout << "\t地址：" << (int *)(&d) + 3;
    cout << endl;

    //[4]
    cout << "[4]Drive_multyBase::Drive_multyBaseI=" << *(int*)((int *)(&d) + 4);// 3000
    cout << "\t地址：" << (int *)(&d) + 4;
    cout << endl;

    getchar();

    return 0;
}