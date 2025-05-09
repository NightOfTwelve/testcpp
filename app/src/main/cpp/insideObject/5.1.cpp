//
// Created by ThinkPad on 2025-05-09.
//


#include <iostream>
#include <typeinfo>
#include <string>

using std::cout;
using std::endl;
using std::string;

// https://www.cnblogs.com/QG-whz/p/4909359.html
// Base 包含了上面这5中类型的数据或函数：
class Base {
public:
    Base(int i) :baseI(i){};
    int getI(){ return baseI; }
    static void countI(){};
    virtual ~Base(){}
    virtual void print(void){ cout << "Base::print()"; }

private:
    int baseI;
    static int baseS;
};


class Derive : public Base {
public:
    Derive(int d) :Base(1000),      DeriveI(d){};
    //overwrite父类虚函数
    virtual void print(void){ cout << "Drive::print()" ; }
    // Derive声明的新的虚函数
    virtual void Drive_print(){ cout << "Drive::Drive_print()" ; }
    virtual ~Derive(){}
private:
    int DeriveI;
};


// 验证类对象的布局
void test1() {
    Base b(1000);
}


void testBase(Base &p) {
    cout << "对象的内存起始地址：" << &p << endl;
    cout << "type_info信息:" << endl;
//    RTTICompleteObjectLocator str = *((RTTICompleteObjectLocator*)*((int*)*(int*)(&p) - 1));
//
//    string classname(str.pTypeDescriptor->name);
//    classname = classname.substr(4, classname.find("@@") - 4);
//    cout <<  "根据type_info信息输出类名:"<< classname << endl;

    cout << "虚函数表地址:" << (int *)(&p) << endl;

    //验证虚表
    cout << "虚函数表第一个函数的地址：" << (int *)*((int*)(&p)) << endl;
    cout << "析构函数的地址:" << (int* )*(int *)*((int*)(&p)) << endl;
    cout << "虚函数表中，第二个虚函数即print（）的地址：" << ((int*)*(int*)(&p) + 1) << endl;

    //通过地址调用虚函数print（）
    typedef void(*Fun)(void);
    Fun IsPrint=(Fun)* ((int*)*(int*)(&p) + 1);
    cout << endl;
    cout << "调用了虚函数";
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



typedef void(*Fun)(void);

int main_vs() {
    Derive d(2000);
    //[0]
    cout << "[0]Base::vptr";
    cout << "\t地址：" << (int *)(&d) << endl;
    //vprt[0]
    cout << "  [0]";
    Fun fun1 = (Fun)*((int *)*((int *)(&d)));
    fun1();
    cout << "\t地址:\t" << *((int *)*((int *)(&d))) << endl;

    //vprt[1]析构函数无法通过地址调用，故手动输出
    cout << "  [1]" << "Derive::~Derive" << endl;

    //vprt[2]
    cout << "  [2]";
    Fun fun2 = (Fun)*((int *)*((int *)(&d)) + 2);
    fun2();
    cout << "\t地址:\t" << *((int *)*((int *)(&d)) + 2) << endl;
    //[1]
    cout << "[2]Base::baseI=" << *(int*)((int *)(&d) + 1);
    cout << "\t地址：" << (int *)(&d) + 1;
    cout << endl;
    //[2]
    cout << "[2]Derive::DeriveI=" << *(int*)((int *)(&d) + 2);
    cout << "\t地址：" << (int *)(&d) + 2;
    cout << endl;
    getchar();

    return 0;
}

// android
int main() {
    Derive d(2000);// void **vtbl = (void *)&d;

    // typeinfo
    cout << "\t地址:\t" << ((int *)*((int *)(&d)) - 1) << "\t值：0x" << std::hex<< *((int *)*((int *)(&d)) - 1) << endl;
    // offset to this
    cout << "\t地址:\t" << ((int *)*((int *)(&d)) - 2) << "\t值：0x" << std::hex<< *((int *)*((int *)(&d)) - 2) << endl;
    cout << "\t地址:\t" << ((int *)*((int *)(&d)) - 3) << "\t值：0x" << std::hex<< *((int *)*((int *)(&d)) - 3) << endl;


    //[0]
    cout << "[0]Base::vptr";
    cout << "\t地址：" << (int *)(&d) << endl;
    //vptr[0]
    cout << "  [0]";
    Fun fun1 = (Fun)*((int *)*((int *)(&d)));
    fun1();
    cout << "\t地址:\t" << std::hex << *((int *)*((int *)(&d))) << endl;

    //vprt[1]析构函数无法通过地址调用，故手动输出
    cout << "  [1]" << "Derive::~Derive" << endl;
    Fun f = (Fun)*((int *)*((int *)(&d)) + 1);
    //f();
    cout << "\t地址:\t" << *((int *)*((int *)(&d)) + 1) << endl;

    //vprt[2]
    cout << "  [2]";
    Fun fun2 = (Fun)*((int *)*((int *)(&d)) + 2);
    fun2();
    cout << "\t地址:\t" << *((int *)*((int *)(&d)) + 2) << endl;

    //vprt[3]
    cout << "  [3]";
    Fun vfun3 = (Fun)*((int *)*((int *)(&d)) + 3);
    vfun3();
    cout << "\t地址:\t" << *((int *)*((int *)(&d)) + 3) << endl;

    //vprt[4]
    cout << "  [4]";
    Fun vfun4 = (Fun)*((int *)*((int *)(&d)) + 4);
    //vfun4();
    cout << "\t地址:\t" << *((int *)*((int *)(&d)) + 4) << endl;

    //[1]
    cout << "[2]Base::baseI=" << *(int*)((int *)(&d) + 1);
    cout << "\t地址：" << (int *)(&d) + 1;
    cout << endl;
    //[2]
    cout << "[2]Derive::DeriveI=" << *(int*)((int *)(&d) + 2);
    cout << "\t地址：" << (int *)(&d) + 2;
    cout << endl;
    getchar();

    return 0;
}

