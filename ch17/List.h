#ifndef GUARD_List_h
#define GUARD_List_h

#include <string>

struct Link {
public:
	std::string value;

	Link( const std::string& v, Link* p=nullptr, Link* s=nullptr)
		: value{v}, prev{p}, succ{s} {}

	Link* insert(Link* n);
	Link* add(Link* n);
	Link* erase();
	Link* find(const std::string) const;
	Link* advance(int) const;
	Link* next() const { return succ;}
	Link* previous() const {return prev;}

private:
	Link* prev;
	Link* succ;


};

Link* Link::insert(Link* n)
{
	if(n==nullptr) return this;
	if(this==nullptr) return n;
	n->succ = this;
	if(prev) prev->succ=n;
	n->prev = prev;
	prev = n;
	return n;
}

Link* Link::add(Link* n)
{
	if(n==nullptr) return this;
	if(this==nullptr) return n;
	n->perv = this;
	n->succ = succ;
	if(succ) succ->prev = n;
	succ = n;
	
	return this;
}

Link* Link::erase(Link*p)
{
	if(this==nullptr) return nullptr;
	if(succ) succ->prev=prev;
	if(prev) prev->succ=succ;
	return succ;
}

Link* Link::find(const std::string& s)
{
	Link* p = this;
	while(p) {
		if(p->value==s) return p;
		p = p->succ;
	}
	return nullptr;
}

Link* Link::advance(int n)
{
	if(this==nullptr) return nullptr;
	Link* p = const_cast<Link*>(this);
	if(0<n) {
		while(n--) {
			if(p->succ==nullptr) return nullptr;
			p = p->succ;
		}
	} else if(n<0) {
		while(n++) {
			if(p->prev==nullptr) return nullptr;
			p = p->prev;
		}
	}
	return p;
}





#endif
