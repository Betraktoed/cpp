#include <iostream>
#include <fstream>
#include "lab8.h"
#include <ctime>
#include <cstdlib>
using namespace std;
#define RND_DLT(x) (std::rand() % (2 * (x) + 1) - (x))
#define RND_DPS(a, b) ((a) + std::rand() % ((b) - (a) + 1))

#define SET(x) x

#define DELTA 100000


int main(int argc, char** argv){

	CTreeSet<int> M1, M2;
    int i, j;

    for(i = 0; i < RND_DPS(100, 1000); i++) {
        M1.makeEmpty();

        for(j = 0; j < RND_DPS(0, 1000); j++)
            M1.add(RND_DLT(DELTA));


        M2.makeEmpty();

        for(j = 0; j < RND_DPS(0, 1000); j++)
            M2.add(RND_DLT(DELTA));

        std::cout << std::endl;

        std::cout << "M1 = " << M1 << std::endl;
		std::cout << "M2 = " << M2 << std::endl; 
    }
	
	return 0;
}
