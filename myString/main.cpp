/********************************************************
 * Author		: Hao Ding
 * Email		: mailtodinghao@gmail.com
 * Created Time	: Thu 02 Jan 2014 07:41:03 AM CST
 * Filename		: main.cpp
 * Description	: 
 * ******************************************************/
#include <iostream>
#include <cstring>
#include <cstdlib>
#include "MyString.h"
using namespace std;

int main(){
	MyString str1("s1");
	MyString str2 = "str2";
	MyString *str3 = new MyString("str3");
	cout << "str1: " << str1 << endl;
	cout << "str2: " << str2 << endl;
	cout << "str3: " << *str3 << endl;
	str2 = str1;
	str1 = "LONGSTRING";
	cout << "str1: " << str1 << endl;
	cout << "str2: " << str2 << endl;
	cout << "str3: " << *str3 << endl;
	cout << "Length of str3: " << str3->getLength() << endl;
	
	MyString str4("STR");
	char tmp[] = "tmp";
	str1.getSub(0, 2, tmp);
	cout << "tmp: " << tmp << endl;
	cout << "isExist('R') in str1: " << str1.isExist('R') << endl;
	cout << "isExist(" << "tmp" << ") in str1: " << str1.isExist(tmp) << endl;
	cout << "isExist(str4) in str1: " << str1.isExist(str4) << endl;
	cout << "str1 == str4 ? : " << str1.operator==(str4) << endl;
	cout << "str1 == str4 ? : " << (str1==str4) << endl;
    return 0;
}

