#include <iostream>
using namespace std;

const int STACK_SIZE = 10;

class Stack {
public:
	Stack();
	Stack(int);
	~Stack();
	long top() const;
	long pop();
	void push(long);

private:
	long *items;
	int sp;
};

Stack::Stack() {
	items = new long[STACK_SIZE];
	sp = -1;
}

Stack::Stack(int size) {
	items = new long[size];
	sp = -1;
}

Stack::~Stack() {
	delete[] items;
}

long Stack::top() const {
	return items[sp];
}

long Stack::pop(){
	return items[sp--];
}

void Stack::push(long i) {
	items[++sp] = i;
}

int main() {
	Stack q;
	Stack r(15);
	q.push(1);
	long i = q.top();
	q.pop();
	
	return 0;
}
