
#include <iostream>
#include "unique_ptr.hpp"

class Test {
public:
    Test() {
        std::cout << "Test created" << std::endl;
    }
    ~Test() {
        std::cout << "Test destroyed" << std::endl;
    }
    void sayHello() const {
        std::cout << "Hello from Test" << std::endl;
    }
};

int main() {

    Unique_ptr<Test> ptr(new Test());
    ptr->sayHello();

    Unique_ptr<Test> ptr2 = std::move(ptr);
    if (ptr2) {
        ptr2->sayHello();
    } else {
        std::cout << "ptr is null after move" << std::endl;
    }

    Unique_ptr<Test> ptr3;
    ptr3 = std::move(ptr2);
    if (ptr3) {
        ptr3->sayHello();
    } else {
        std::cout << "ptr2 is null after move assignment" << std::endl;
    }

    ptr3.reset(new Test());
    ptr3->sayHello();

    Test* rawPtr = ptr3.release();
    if (!ptr3) {
        std::cout << "ptr3 is null after release" << std::endl;
    }
    delete rawPtr;

    return 0;
}
