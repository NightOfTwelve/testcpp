//
// Created by ThinkPad on 2025-05-07.
//

#include <iostream>
using std::cout;
using std::endl;
using std::type_info;

class Base
{
public:

    Base(int i) :baseI(i){};

//    virtual void print(void){ std::cout << "调用了虚函数Base::print()"; }
    virtual void print(void) { std::cout << "调用了虚函数Base::print() " << this->baseI << std::endl; }// TODO error !!!

    virtual void setI(){ std::cout<<"调用了虚函数Base::setI()";}

    virtual ~Base(){}

    void getI() { std::cout << "getI()" << std::endl;}

private:
    int baseI;
};

//int test() {
int main() {
    Base b(1000);

    // https://www.cnblogs.com/zfyouxi/p/5060288.html
    // https://c.biancheng.net/view/2301.html
    // https://zhuanlan.zhihu.com/p/261589696
    cout << "typeid(b)  : " << typeid(b).name() << endl;// https://zhuanlan.zhihu.com/p/261589696
    const type_info& nInfo = typeid(b);
    //cout << nInfo.name() << " | " << nInfo.raw_name() << " | " << nInfo.hash_code() << endl;// https://c.biancheng.net/view/2301.html
    cout << nInfo.name() << " | " << nInfo.hash_code() << endl;// https://c.biancheng.net/view/2301.html

    int * vptrAdree = (int *)(&b);// 32位
    std::cout << "虚函数指针（vprt）的地址是：\t"<<vptrAdree << std::endl;

    // ---------------------------------------------
    typedef void(*Fun)(void);
    Fun vfunc = (Fun)*( (int *)*(int*)(&b));
    std::cout << "第一个虚函数的地址是：" << (int *)*(int*)(&b) << std::endl;
    std::cout << "通过地址，调用虚函数Base::print()：";
    vfunc();// TODO this ???

    // ---------------------------------------------
    std::cout << "\n----------------" << std::endl;
    typedef void(*fn_print)(Base*);
    fn_print p = (fn_print) *((int*)*(int*)(&b));
    p(&b);// TODO not 1000 ???
    Base* pb = &b;
    p(pb);

    // ---------------------------------------------
    // 第二个虚函数setI()的地址为: (int *)(*(int*)(&b))+1
    std::cout << "\n第二个虚函数的地址是：" << ((int*)(*(int*)(&b)) + 1) << std::endl;
    typedef void (*fn_setI)(void);
    fn_setI seti = (fn_setI) * ((int*)(*(int*)(&b)) + 1);
    std::cout << "通过地址，调用虚函数Base::setI()：";
    seti();

    getchar();
    return 0;
}

