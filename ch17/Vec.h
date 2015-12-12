#ifndef GUARD_Vec_h
#define GUARD_Vec_h

class Vec {
private:

	int sz;
	double* elem;

public:
	Vec(int s) 
		: sz{s}, elem{new double[s]}
		{
			for( int i=0;i<s;++i)
				elem[i] = 0;
		}
	~Vec() { delete[] elem; }

	int size() const { return sz;}

	double get(int n) const { return elem[n];}
	void set(int n, double v) {elem[n] = v; }


};

#endif
