#ifndef GUARD_Vec_h
#define GUARD_Vec_h

#include <initializer_list>
template<typename T>
class Vec {
private:

	int sz;
	T* elem;
	int space;

public:
	explicit Vec(int s) 
		: sz{s}, elem{new T[sz]},space{s}
		{
			for( int i=0;i<s;++i)
				elem[i] = 0;
		}
	~Vec() { delete[] elem; }

	int size() const { return sz;}
	
	template<class P1, class P2> void copy(P1,P1,P2);

//	Vec(std::initializer_list<double>lst) 
//		:sz{static_cast<int>(lst.size())}, elem{new double[sz]},space{static_cast<int>(lst.size())}
//		{
//			copy(lst.begin(),lst.end(),elem);
//		}

	Vec(const Vec&);
	Vec& operator=(const Vec&);

	Vec(Vec&&);
	Vec& operator=(Vec&&);

	T& operator[](int n) { return elem[n];}
	const T& operator[](int n) const {return elem[n];}

	double get(int n) const { return elem[n];}
	void set(int n, double v) {elem[n] = v; }

	void reserve(int);
	int capacity() const {return space;}
	void resize(int);
	void push_back(const T&);
};


//template<class P1, class P2>
//void Vec::copy(P1 begin, P1 end, P2 target)
//{
//	while(begin!=end) {
//		*target = *begin;
//		++target;
//		++begin;
//	}
//}

Vec::Vec(const Vec& arg)
	: sz{arg.sz}, elem{new double[arg.sz]},space{arg.sz}
{
	copy(arg.elem,arg.elem+sz,elem);
}

Vec& Vec::operator=(const Vec& a)
{
	if(this==&a) return *this;
	if(a.sz<=space) {
		for(int i=0;i<a.sz;++i) elem[i]=a.elem[i];
		sz=a.sz;
		return *this;
	}

	double* p = new double[a.sz];
	for(int i=0;i<a.sz;++i) p[i]=a.elem[i];
	delete[] elem;
	space=sz=a.sz;
	elem=p;
	return *this;	
}


Vec::Vec(Vec&& a)
	: sz{a.sz}, elem{a.elem}, space{a.sz}
{
	a.sz=0;
	a.elem=nullptr;
}


Vec& Vec::operator=(Vec&& a)
{
	delete[] elem;
	elem = a.elem;
	sz=a.sz;
	space = a.sz;
	a.elem =nullptr;
	a.sz=0;
	return *this;
}

void Vec::reserve(int newalloc)
{
	if(newalloc<=space) return;
	double* p= new double[newalloc];
	for(int i=0;i<sz;++i) p[i]=elem[i];
	delete elem;
	elem=p;
	space=newalloc;
}

void Vec::resize(int newsize)
{
	reserve(newsize);
	for(int i=sz;i<newsize;++i) elem[i]=0;
	sz = newsize;
}

void Vec::push_back(const T& d)
{
	if(space==0){
		reserve(8);
	} else if(sz==space) {
		reserve(2*space);
	}
	elem[sz]=d;
	++sz;
} 


#endif
