/********************************************************
 * Author		: Hao Ding
 * Email		: dinghao_nwpu@hotmail.com
 * Created Time	: Thu 02 Jan 2014 06:31:58 AM CST
 * Filename		: MyString.cpp
 * Description	: 
 * ******************************************************/
#include <iostream>
#include <cstring>
#include <cstdlib>
#include "MyString.h"
using namespace std;

MyString::MyString(const char *str) {
	m_data = NULL;
	if (str != NULL) {	// check if str is empty
		m_data = new char[strlen(str) + 1];	// allocate memory
		if (m_data != NULL) {	// check if allocation succeeds
			strcpy(m_data, str);
		}
	}
	else {	// str is empty
		m_data = new char[1];
		m_data[0] = '\0';
	}
}

MyString::MyString(const char ch, size_t n) {
	m_data = NULL;
	if (n > 0) { // check if the length is positive
		m_data = new char[n];
		if (m_data != NULL) {	// check if allocation succeeds
			for (int i = 0; i < n; i++) {
				m_data[i] = ch;
			}
		}
	}
	else {	// n is 0 or negative
		m_data = new char[1];
		m_data[0] = '\0';
	}
}

MyString::MyString(const MyString &rStr) {
	m_data = NULL;
	if (rStr.m_data != NULL) {	// check if rStr is empty
		m_data = new char[strlen(rStr.m_data) + 1];	// allocate mem
		if (m_data != NULL) {	// check if allocation succeeds
			strcpy(m_data, rStr.m_data);
		}
	}
}

MyString::~MyString() {
	if (m_data != NULL) {
		delete[] m_data;
		m_data = NULL;
	}
}

size_t MyString::getLength() const {
	return strlen(m_data);
}

void MyString::getSub(const size_t start, const size_t end, char *subStr) {
	for (size_t i = 0; i < end - start; i++) {
		subStr[i] = m_data[start + i];
	}
	subStr[end - start] = '\0';
	return;
}

void MyString::c_str(char *str) {
	for (size_t i = 0; i < strlen(m_data) + 1; i++){
		str[i] = m_data[i];
	}
	return;
}

bool MyString::isExist(const char ch) const{
	for (size_t i = 0; i < strlen(m_data); i++) {
		if ( ch == m_data[i]) {
			return true;
		}
	}
	return false;
}

bool MyString::isExist(const char *rStr){
	for (size_t i = 0; i < strlen(m_data); i++) {
		char *tmpStr = new char[strlen(rStr)+1];
		getSub(i, i + strlen(rStr), tmpStr);
		if (strcmp(rStr, tmpStr) == 0) {
			return true;
		}
	}
	return false;
}

bool MyString::isExist(const MyString &subStr){
	for (size_t i = 0; i < strlen(m_data); i++) {
		char *tmpStr = new char[strlen(subStr.m_data)+1];
		getSub(i, i + strlen(subStr.m_data), tmpStr);
		if (strcmp(subStr.m_data, tmpStr) == 0) {
			return true;
		}
	}
	return false;
}

MyString &MyString::operator=(const MyString &rStr) {
	if (this != &rStr) {	// check if this equal to &rStr
		if (m_data != NULL) {	// if m_data is not empty
			delete[] m_data;
			m_data = NULL;
		}
		if (rStr.m_data != NULL) {	// check if rStr is empty
			m_data = new char[strlen(rStr.m_data) + 1];
			if (m_data != NULL) { // check if allocation succeeds
				strcpy(m_data, rStr.m_data);
			}
		}
	}
	return *this;
}

bool MyString::operator==(const MyString &rStr) const {
	if (strcmp(m_data, rStr.m_data) == 0) {
		return true;
	}
	return false;
}

ostream &operator<<(ostream &os, const MyString &str) {
	os << str.m_data;
	return os;
}

