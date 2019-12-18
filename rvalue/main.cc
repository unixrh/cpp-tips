#include <stdio.h>
class shape{};
class circle : public shape{};
void foo(const shape&)
{
    puts("foo(const shape&)");
}
void foo(shape&&)
{
    puts("foo(shape&&)");
}
void bar(const shape& s)
{
    puts("bar(const shape&)");
    foo(s);
}
void bar(shape&& s)
{
    puts("bar(shape&&)");
    foo(s);         // s is a lvalue, so it'll call foo(const shape&)
}
int main()
{
    bar(circle());  // circle() is a rvalue, so it'll call bar(shape&& s)
}
