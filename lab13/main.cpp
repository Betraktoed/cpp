#include"my_string.hpp"

int main(){
	my_string ms();
	char arr[] = "te";
	char arr2[] = "test2";
	char arr1 = 's';
	my_string ms1(arr);
	my_string ms2(arr2);
	std::cin >> ms1;
	ms1 += ms2;
	std::cout << ms1 << std::endl;
	
	return 0;
}
