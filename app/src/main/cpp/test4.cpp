//
// Created by ThinkPad on 2025-05-08.
//

#include <iostream>

// https://tjzhang-src.github.io/.github.io/2024/10/17/C-%E5%AF%B9%E8%B1%A1%E6%A8%A1%E5%9E%8B/

class Member {
public:
    Member(int value) : value(value) {
        std::cout << "Member constructed with value: " << value << std::endl;
    }

    void display() const {
        std::cout << "Value: " << value << std::endl;
    }

private:
    int value;
};

class Container {
public:
    // Container 的构造函数需要初始化 Member
//    Container(int memberValue) : member(memberValue) {
//      std::cout << "Container constructed." << std::endl;
//  }

    void displayMember() const {
        member.display();
    }

private:
    Member member; // Member 没有默认构造函数
};

int main() {
    Container container{};
    container.displayMember();
    return 0;
}