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
    }

    return 0;
}
