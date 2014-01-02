/********************************************************
 * Author		: Hao Ding
 * Email		: dinghao_nwpu@hotmail.com
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
	cout << "str1: " << str1 << endl;
	cout << "str2: " << str2 << endl;
	cout << "str3: " << *str3 << endl;
	cout << "Length of str3: " << str3->getLength() << endl;
    return 0;
}

