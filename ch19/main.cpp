#include "Vec.h"

#include <iostream>
#include <vector>
using namespace::std;

int main()
{
	Vec<double> v(10);
	for(int i=0;i<v.size();++i) {
		v[i] = i;
		cout << v[i] << endl;
	}

	return 0;
}


