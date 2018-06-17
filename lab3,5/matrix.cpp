#include <iostream>
#include <fstream>
#include "Matrix.h"
using namespace std;
int main(int argc, char** argv) {
    std::fstream fileA, fileB;
    CMatrix A, B;
    fileA.open(argv[1]);
    fileB.open(argv[2]);
    A>>fileA;
    B>>fileB;
	if (A == B){
		cout << "DIO DAA" << endl;
	}
    (A * B)<<(std::cout);

    return 0;
}
