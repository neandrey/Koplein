#include <iostream>
using namespace std;

const int STACK_SIZE = 10;

class Stack {
private:
	long items[STACK_SIZE];
	int sp;

public:
	void initialize();
	long top() const;
	long pop();
	void push(long);
	long out_sp() const;
};

void Stack::initialize(){
	sp = -1;
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

long Stack::out_sp() const {
	return sp;
}

int main() {
	Stack q;
	q.initialize();
	q.push(1);
	long i = q.top();
	cout << "sp = " << q.out_sp() << endl;
	q.pop();
	i = q.top();
	cout << "sp = " << q.out_sp() << endl;
	
	return 0;
}
