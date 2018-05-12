#include <iostream>
using namespace std;
template <typename T>
class printSize{
    private:
        T element;
    public:
    printSize(T element): element(element){}
    T printType(){
        cout << "Size of variable type" << element<< ":" << sizeof(T) << endl;
    }
};

int main(void)
{
	int i=1;
	char c='1';
	short s=2;
	bool b=0;
	long l=1223;
	float f=1.23;
	double d=12.23;
	printSize<int> typei(i);
	typei.printType();
	printSize<char> typec(c);
	typec.printType();
	printSize<short> types(s);
	types.printType();
	printSize<bool> typeb(b);
	typeb.printType();
	printSize<long> typel(l);
	typel.printType();
	printSize<float> typef(f);
	typef.printType();
	printSize<double> typed(d);
	typed.printType();
	return 0;
}

