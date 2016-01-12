#ifndef GUARD_Vec_h
#define GUARD_Vec_h

class Vec{
	int sz;
	double* elem;
	int space;

public:
	void reserve(int);


};


Vec::reserve(int newalloc)
{
	if(newalloc<=space) return;
	double* p = new double[newalloc];
	for(int i=0;i<sz;++i) p[i] = elem[i];
	delete[] elem;
	elem = p;
	space = newalloc;
}

#endif
