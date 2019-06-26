#include "stack.hpp"
Stack::Stack(int max_length){
	MAX_LENGTH = max_length;
	mData = new pair[MAX_LENGTH];
	mTop = 0;
}
pair Stack::pop(){
	mTop--;
	return mData[mTop];
}
void Stack::push(pair data){
	mData[mTop].left = data.left;
	mData[mTop].right = data.right;
	// mData[mTop] = data;
	mTop++;
}
bool Stack::is_empty(){
	return (mTop == 0);
}
Stack::~Stack(){
	delete [] mData;
}