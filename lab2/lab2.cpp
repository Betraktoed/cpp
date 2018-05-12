#include <iostream>
using namespace std;

class complex{
private:
	float a,b;
public:
	complex() {a = 0; b = 0;};
	complex(float A, float B);
	void print(std::ostream& print) const;
	void add(complex obj);
	void sub(complex obj);
	void mul(int c);
	void div(int c);
};

complex::complex(float A, float B){
	a = A;
	b = B;
}
void complex::print(std::ostream& print) const {
	print << a << " + (" << b << ")" << endl;
}
void complex::add(complex obj){
	a += obj.a;
	b += obj.b;
}
void complex::sub(complex obj){
	a -= obj.a;
	b -= obj.b;
}
void complex::mul(int c){
	a *= c;
	b *= c;
}
void complex::div(int c){
	try{
		if (c == 0){
			throw 1;
		}
		a /= c;
		b /= c;
	}
	catch(int c){
		cout << "Division by zero" << endl;		
   	}
}

int main(void){
	complex a(3.0, 4.6);
	complex b(1.6, -2.1);
	a.div(4);
	a.print(std::cout);
	return 0;
}
