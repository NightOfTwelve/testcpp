//
// Created by ThinkPad on 2025-05-07.
//

#include <iostream>


class X{};
class Y: public virtual X{};
class Z: public virtual X{};
class A: public Y, public Z{};

int main(){
    X x;
    Y y;
    Z z;
    A a;
    std::cout << sizeof(x) << std::endl << sizeof(y) << std::endl << sizeof(z) << std::endl << sizeof(a) << std::endl;

    return 0;
}