//
// Created by ThinkPad on 2025-05-07.
//

#include <stdio.h>

//class Base {     virtual void print(void);    };
//class Drive1 :public Base{    virtual void print(void);    };
//class Drive2 :public Base{    virtual void print(void);    };

class Base {
public:
    virtual void print(void) {
        printf("Base::print()");
    }
};
class Drive1 :public Base{
public:
    virtual void print(void) {
        printf("Drive1::print()");
    }
};
class Drive2 :public Base{
public:
    virtual void print(void) {
        printf("Drive2::print()");
    }
};


void test() {
    Base *ptr1 = new Base;
    Base *ptr2 = new Drive1;
    Base *ptr3 = new Drive2;

    ptr1->print();//调用Base::print()
    ptr2->print();//调用Drive1::print()
    ptr3->print();//调用Drive2::print()

    delete ptr1;
    delete ptr2;
    delete ptr3;
}