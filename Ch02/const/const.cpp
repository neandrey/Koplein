struct s {
    int a;
    int f(int aa) {
        return a = aa;
    }
    int g(int aa) const {
        return aa;
    }
// h(int aa) const {return a = aa;}
};

void g() {
    s o1;
    const s o2;
    o1.a = 1;
    // o2.a = 2;
    o1.f(3);
    // o2.f(4);
    o1.g(5);
    // o2.g(6);


}
