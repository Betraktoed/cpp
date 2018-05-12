#include <iostream>
#include "lab2.h"
using namespace std;


int main(void){
	complex_t A(3.0, 4.1);
	complex_t B(2.1,-1.3);
	A += B;
	complex_t C;
	B = A / C;
	if ( A == B){
		std::cout << "DIO" << std::endl;
	}else{
		std::cout << "JOJO" << std::endl;
	}
	A<<(std::cout);
	return 0;
}

	
