#include <stdio.h>
#ifdef MINE
#include "smart_ptr.h"
#else
#include "s.h"
#endif
class shape {
public:
    virtual ~shape(){}
};

class circle : public shape {
public:
    ~circle() { puts("~circle()"); }
};

int main() {
    smart_ptr<circle> ptr1(new circle());
    printf("use count of ptr1 is %ld\n", ptr1.use_count());
    smart_ptr<shape> ptr2(std::move(ptr1));
    printf("use count of ptr2 is %ld\n", ptr2.use_count());
    printf("use count of ptr2 is %ld\n", ptr2.use_count());
    printf("use count of ptr1 is %ld\n", ptr1.use_count());
    if(ptr1) {
        puts("ptr1 is not empty!");
    }
    return 0;
}
