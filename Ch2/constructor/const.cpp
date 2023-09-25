class B {
public:
    B() {
        p = 0; s = 0;
    }
    int f();
private:
    char* p;
    short s;
};

class C {
public:
    int g();
private:
    int i;
    B b;
};

class D {
public:
    int h();
private:
    int j, k;
};

C gc; //p and s init, value i = 0

int main() {
    C c; // p and s init, value i not define
    D d; // j and k not define
    int l = c.g();
}