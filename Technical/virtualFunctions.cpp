#include<iostream>
#include<bits/stdc++.h> 
using namespace std;

class A {
	public:
		virtual string print_type() {
			return "Class A method called";
		}
};

class B : public A {
	public:
		string print_type() {
				return "Class B method called";
		}
};

int main(){
	A * obj1 = new A();
	A * obj2 = new B();
	cout<<obj1->print_type()<<endl;
	cout<<obj2->print_type()<<endl;
	delete(obj1);
	delete(obj2);
	return 0;
}