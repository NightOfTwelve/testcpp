//
// Created by ThinkPad on 2025-05-08.
//


#include <iostream>

using std::cout;
using std::endl;

class B{};
class B1 :public virtual  B{};
class B2 :public virtual  B{};
class D : public B1, public B2{};

int main() {
    B b;
    B1 b1;
    B2 b2;
    D d;
    cout << "sizeof(b)=" << sizeof(b)<<endl;// 1
    cout << "sizeof(b1)=" << sizeof(b1) << endl;// 4
    cout << "sizeof(b2)=" << sizeof(b2) << endl;// 4
    cout << "sizeof(d)=" << sizeof(d) << endl;// 8
    getchar();

    return 0;
}
