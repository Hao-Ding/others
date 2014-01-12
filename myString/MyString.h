/********************************************************
 * Author		: Hao Ding
 * Email		: mailtodinghao@gmail.com
 * Created Time	: Thu 02 Jan 2014 06:26:42 AM CST
 * Filename		: MyString.h
 * Description	: 
 * ******************************************************/
#ifndef _MYSTRING_H
#define _MYSTRING_H
#include <ostream>
using namespace std;

class MyString
{
public:
	MyString(const char *str = NULL);	// constructor
	MyString(const char ch, const size_t n);	//constructor from ch*n
	MyString(const MyString &rStr);	// copy constructor
	~MyString();						// destructor

	size_t getLength() const;	// get the length of string
	void getSub(const size_t start, const size_t end, char *subStr);	// get subString from start to end-1; min of start is 0; end > start
	void c_str(char *str);	// transfer to c-style char array
	bool isExist(const char ch) const;	// check whether ch is existed
	bool isExist(const char *rStr);	// check whether str is existed
	bool isExist(const MyString &subStr);	// check whether subStr is existed

	MyString &operator=(const MyString &rStr);	// overload of =
	bool operator==(const MyString &rStr) const;	// overload of ==
	friend ostream &operator<<(ostream &os, const MyString &str);	//overload of <<
//	friend MyString &operator+ (, const MyString &str);	//overload of <<
private:
	char *m_data;
};
#endif // _MYSTRING_H

