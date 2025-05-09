//
// Created by ThinkPad on 2025-05-08.
//


#include <iostream>

using std::cout;
using std::endl;
using std::ostream;

class Point3d {
public:
    Point3d(float x = 0.0,float y = 0.0,float z = 0.0) : _x(x), _y(y), _z(z){}

    float x() const {return _x;}
    float y() const {return _y;}
    float z() const {return _z;}

private:
    float _x;
    float _y;
    float _z;
};

inline ostream& operator<<(ostream &os, const Point3d &pt) {
    os << "(" << pt.x() << "," << pt.y() << "," << pt.z() << ")";
}

void TestPoint3Member(const Point3d& p) {

    cout << "推测_x的地址是：" << (float *) (&p) << endl;
    cout << "推测_y的地址是：" << (float *) (&p) + 1 << endl;
    cout << "推测_z的地址是：" << (float *) (&p) + 2 << endl;

    cout << "根据推测出的地址输出_x的值：" << *((float *)(&p)) << endl;
    cout << "根据推测出的地址输出_y的值：" << *((float *)(&p)+1) << endl;
    cout << "根据推测出的地址输出_z的值：" << *((float *)(&p)+2) << endl;

}

int main() {
    //测试代码
    Point3d a(1,2,3);
    TestPoint3Member(a);

    return 0;
}