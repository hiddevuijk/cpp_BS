
#include "Vec.h"
#include "Link.h"


#include <iostream>
#include <string>

using namespace::std;

int main()
{
	int a=10;
	const int* cptra = &a;
	int* ptra = const_cast<int*>(cptra);


	return 0;
}


