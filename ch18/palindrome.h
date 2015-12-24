#ifndef GUARD_palindrome_h
#define GUARD_palindrome_h

#include <string>

bool is_palindrome(const std::string& s)
{
	int first = 0;
	int last = s.length() -1;
	while(first<last) {
		if(s[first]!=s[last]) return false;
		++first;
		--last;
	}
	return true;
}

bool is_palindrome(const char* fisrt, const char* last)
{

	while(first<last) {
		if(*first!=*last) return false;
		++first;
		--last;
	}
	
	return true;
}

#endif
