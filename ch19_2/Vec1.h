#ifndef GUARD_Vec_h
#define GUARD_Vec_h

#include <initializer_list>

class Vec {
private:

	int sz;
	double* elem;

public:
	explicit Vec(int s) 
		: sz{s}, elem{new double[sz]}
		{
			for( int i=0;i<s;++i)
				elem[i] = 0;
		}
	~Vec() { delete[] elem; }

	int size() const { return sz;}
	
	template<class P1, class P2> void copy(P1,P1,P2);

	Vec(std::initializer_list<double>lst) 
		:sz{static_cast<int>(lst.size())}, elem{new double[sz]}
		{
			copy(lst.begin(),lst.end(),elem);
		}

	Vec(const Vec&);
	Vec& operator=(const Vec&);

	Vec(Vec&&);
	Vec& operator=(Vec&&);


	double& operator[](int n) { return elem[n];}
//	double operator[](int n) const {return elem[n];}

	double get(int n) const { return elem[n];}
	void set(int n, double v) {elem[n] = v; }


};


template<class P1, class P2>
void Vec::copy(P1 begin, P1 end, P2 target)
{
	while(begin!=end) {
		*target = *begin;
		++target;
		++begin;
	}
}

Vec::Vec(const Vec& arg)
	: sz{arg.sz}, elem{new double[arg.sz]}
{
	copy(arg.elem,arg.elem+sz,elem);
}

Vec& Vec::operator=(const Vec& a)
{
	double* p = new double[a.sz];
	Vec::copy(a.elem,a.elem+a.sz,elem);
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





#endif
