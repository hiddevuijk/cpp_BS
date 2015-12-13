#include <iostream>


using namespace::std;

int main()
{
//	double* p = new double[5];
	double p[5];
	double d=0.0;
	double* ptr = p;
	int i=0;
	while(ptr!=(p+5)) {
		*(p+i) = d++;
		++ptr;
		++i;
		
	} 
	cout << *p << endl;
	cout << *(p+2) << endl;
	

	return 0;
}
