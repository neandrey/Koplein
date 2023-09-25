#define STACK_SIZE 10

struct Stack {
	long items[STACK_SIZE];
	int sp;
};

void Stack_initialize(struct Stack *s)
{
	s->sp = -1;
}

long Stack_top(struct Stack *s)
{
	return s->items[s->sp];
}

long Stack_pop(struct Stack *s)
{
	return s->items[s->sp--];
}

void Stack_push(struct Stack *s, long i)
{
	s->items[++s->sp] = i;
}

int main() {
	struct Stack q;
	long i;
	Stack_initialize(&q);
	Stack_push(&q, 1);
	i = Stack_top(&q);
	Stack_pop(&q);
}

