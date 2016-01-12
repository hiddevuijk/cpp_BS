#ifndef GUARD_Vec_h
#define GUARD_Vec_h

#include <initializer_list>

template<class P1, class P2>
void copy(P1 begin, P1 end, P2 target)
{
	while(begin!=end) {
		*target = *begin;
		++target;
		++begin;
	}
}

class Vec {
private:

	int sz;
	double* elem;
	int space;
public:
	Vec() : sz{0}, elem{nullptr}, space{0} {}

	explicit Vec(int s)
		: sz{s}, elem{new double[sz]}, space{s}
		{
			for( int i=0;i<s;++i)
				elem[i] = 0;
		}

	
	Vec(const Vec&);
	Vec& operator=(const Vec&);

	Vec(Vec&&);
	Vec& operator=(Vec&&);


	~Vec() { delete[] elem; }

	double& operator[](int n) { return elem[n];}
	const double& operator[](int n) const {return elem[n];}


	int size() const { return sz;}
	int capacity() const;


	void resize(int);
	void push_back(double);
	void reserve(int);

};




Vec::Vec(const Vec& arg)
	: sz{arg.sz}, elem{new double[arg.sz]}
{
	copy(arg.elem,arg.elem+sz,elem);
}

Vec& Vec::operator=(const Vec& a)
{
	double* p = new double[a.sz];
	copy(a.elem,a.elem+a.sz,elem);
	delete[] elem;
	elem=p;
	sz = a.sz;
	return *this;
}


Vec::Vec(Vec&& a)
	: sz{a.sz}, elem{a.elem}
{
	a.sz=0;
	a.elem=nullptr;
}


Vec& Vec::operator=(Vec&& a)
{
	delete[] elem;
	elem = a.elem;
	sz=a.sz;
	a.elem =nullptr;
	a.sz=0;
	return *this;
}


void Vec::reserve(int newalloc)
{
	if(newalloc<=space) return;
	double* p = new double[newalloc];
	for(int i=0;i<sz;++i) p[i] = elem[i];
	delete[] elem;
	elem = p;
	space = newalloc;
}

int Vec::capacity() const
{
	return space;
}

void Vec::resize(int newsize)
{
	reserve(newsize);
	for(int i=sz;i<newsize;++i) elem[i]=0;
	sz = newsize;
}

void Vec::push_back(double d)
{
	if(space==0)
		reserve(8);
	else if(sz==space)
		reserve(2*space);
	elem[sz]=d;
	++sz;
}
#endif
