
#include <iostream>
using namespace std;

class complex_t{
private:
	float a;
	float b;
public:
	complex_t(float A,float B){a = A;b = B;};
	complex_t(){a = 0;b = 0;};
	complex_t(const complex_t& ct);
	float geta(){return a;};
	float getb(){return b;};
	complex_t operator*( const complex_t& obj);
	complex_t operator/( const complex_t& obj);
	void operator+=(const complex_t& obj);
	void operator-=(const complex_t& obj);
	void operator*=(const complex_t& obj);
	void operator/=(const complex_t& obj);
	void operator=(const complex_t& obj);
	bool operator==(const complex_t& obj);
	std::ostream& operator<<(std::ostream &output);
	void operator>>(std::istream &input);
};

complex_t::complex_t(const complex_t& ct) {
	a = ct.a;
	b = ct.b;
}
std::ostream& complex_t::operator<<(std::ostream &output){
    this->b == 0 ? output << a : output << a << " + (" << b << ")\n";
	return output;
}
void complex_t::operator>>(std::istream &input){
	input >> a >> b;
}
void complex_t::operator+=(const complex_t& obj){
	this->a += obj.a;
    this->b += obj.b;
}
void complex_t::operator-=(const complex_t& obj){
    this->a -= obj.a;
    this->b -= obj.b;
}
void complex_t::operator*=(const complex_t& obj){
	float A, B;
	A = a*obj.a - b*obj.b;
    B = a*obj.b + b*obj.a;
	a = A;
	b = B;
}
void complex_t::operator/=(const complex_t& obj){
	try{
		if (obj.a*obj.a + obj.b*obj.b==0){
			throw 1;
		}
       	float A, B;
		A = (a * obj.a + b * obj.b)/(obj.a*obj.a + obj.b*obj.b);
		B = (b * obj.a - a * obj.b)/(obj.a*obj.a + obj.b*obj.b);
		a = A;
		b = B;
	}
	catch(int c){
		cout << "Division by zero" << endl;
		return;
   	}
}
complex_t complex_t::operator*(const complex_t& obj){
    float A, B;
	A = a*obj.a - b*obj.b;
    B = a*obj.b + b*obj.a;
	complex_t res(A, B);
	return res;
}
void complex_t::operator=(const complex_t& obj){
	a = obj.a;
	b = obj.b;
}
bool complex_t::operator==(const complex_t& obj){
	if (a == obj.a and b == obj.b){
		return true;
	}else{
		return false;
	}
}

complex_t complex_t::operator/(const complex_t& obj){
	try{
		if (obj.a*obj.a + obj.b*obj.b==0){
			throw 1;
		}
       	float A, B;
		A = (a * obj.a + b * obj.b)/(obj.a*obj.a + obj.b*obj.b);
		B = (b * obj.a - a * obj.b)/(obj.a*obj.a + obj.b*obj.b);
		complex_t res(A, B);
		return res;
	}
	catch(int c){
		cout << "Division by zero" << endl;
		
   	}
}

