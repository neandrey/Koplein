#include <iostream>
#include <sys/types.h>
#include <unistd.h> 
#include <sys/stat.h>
#include <fcntl.h>

using namespace std;
class FileRef {
private:
    class File& f;
    char buf[1];
    unsigned long ix;
public:
    FileRef(File& ff, unsigned long i) : f(ff), ix(i) {}
    FileRef& operator=(char c);
    operator char();
};

class File {
    friend class FileRef;
public:
    File(const char* name) {
        fd = open(name, O_RDWR | O_CREAT, 0664);
    }
    ~File() {
        close(fd);
    }
    FileRef operator[] (unsigned long ix) {
        return FileRef(*this, ix);
    }
private:
    int fd;
};

FileRef& FileRef::operator=(char c) {
    lseek(f.fd, ix, 0);
    write(f.fd, &c, 1);
    return *this;
}

FileRef::operator char() {
    lseek(f.fd, ix, 0);
    read(f.fd, buf, 1);
    return buf[0];
}

int main() {
    File foo("foo");
    foo[5] = '5';
    foo[10] = 'l';
    char c = foo[5];
    cout << "c = " << c << endl;
}