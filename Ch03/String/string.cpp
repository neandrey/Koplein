#include <cstring>
#include <cstdio>
#include <iostream>

using namespace std;
class String {
public:
    operator const char* () const {
        return rep;
    }
    operator int();
    friend String operator+(const char*, const String&);
    friend String operator+(const String&, const char*);
    String operator+(const String& s) const;
    int length() const;
    String();
    String(const String&);
    String& operator=(const String&);
    ~String();
    String(const char*);
    const char* const C_rep() {
        return (const char* const)rep;
    }
private:
    char* rep;
};

String::operator int() {
    int retval;
    if (sscanf(rep, "%d", &retval) != 1) return 0;
    else return retval;
}

String::String() {
    rep = new char[1];
    rep[0] = '\0';
}

String::String(const String& s) {
    rep = new char[s.length() + 1];
    ::strcpy(rep, s.rep);
}

String& String::operator=(const String& s) {
    if (rep != s.rep) {
        delete[] rep;

        int lengthOfOriginal = s.length() + 1;
        rep = new char[lengthOfOriginal];
        ::strcpy(rep, s.rep);
    }
    return *this;
}

String::~String() {
    delete[] rep;
}

String::String(const char* s) {
    int lengthOfOriginal = ::strlen(s) + 1;
    rep = new char[lengthOfOriginal];
    ::strcpy(rep, s);
}

int String::length() const {
    return ::strlen(rep);
}

String String::operator+(const String& s) const {

    char* buf = new char[s.length() + length() + 1];
    ::strcpy(buf, rep);
    ::strcat(buf, s.rep);
    String retval(buf);
    delete[] buf;

    return retval;
}

String operator+(const char* s, const String& S) {
    String retval;
    retval.rep = new char[::strlen(s) + S.length()];
    ::strcpy(retval.rep, s);
    ::strcat(retval.rep, S.rep);

    return retval;
}

String operator+(const String& S, const char* s) {
    String retval;
    retval.rep = new char[::strlen(s) + S.length()];
    ::strcpy(retval.rep, S.rep);
    ::strcat(retval.rep, s);

    return retval;
}

int main() {
    String s("this is s");
    printf("string is %s\n", s.C_rep());

    String s1("Hello ");
    s1 = "abcd " + s1;
    s1 = s1 + "efgh";

    cout << s1.C_rep() << endl;

    char buf[10];
    printf("enter nuber of bytes: ");
    scanf("%s\n", buf);
    String sbuf = buf;

    //Явное преобразование в int
    printf("read in value %d\n", int(sbuf));

    char* thing = new char[100];
    ::strcpy(thing, (const char* const)sbuf);
    cout << thing << endl;

    int charLeftInThing = 100 - sbuf;
    cout << charLeftInThing << endl;

    return 0;
}