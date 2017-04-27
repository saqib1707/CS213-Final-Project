#include <iostream>
//#include <stdlib.h>
using namespace std;
#ifndef test

class Test{
private:
	int a,b;
public:
	Test(int a, int b){
		this->a=a;
		this->b=b;
	}
	void show(){
		cout<<"a="<<this->a<<"\n";
		cout<<"b="<<this->b<<"\n";
	}
};

#endif