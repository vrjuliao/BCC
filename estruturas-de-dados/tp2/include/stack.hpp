#ifndef STACK_TP2
#define STACK_TP2
typedef struct {
	int left;
	int right;
} pair;

//simple way to implement a stack data structure
class Stack{
private:
	int MAX_LENGTH;
	pair* mData;
	int mTop;
public:
	Stack(int max_length);
	virtual pair pop();
	virtual void push(pair data);
	virtual bool is_empty();
	~Stack();
};
#endif