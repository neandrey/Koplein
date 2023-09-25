#include <stdio.h>

class X {
public:
    void foo() {
        fooCounter++;
    }
    static void printCounts() {
        printf("foo called %d times\n", fooCounter);
    }
private:
    static int fooCounter;
};

int X::fooCounter = 0;

int main() {
    //printCounts(); Error
    X::printCounts();
}