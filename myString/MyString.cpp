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
	if (str != NULL) {
		m_data = new char[strlen(str) + 1];
		if (m_data != NULL) {
			strcpy(m_data, str);
		}
	}
	else {
		m_data = new char[1];
		m_data[0] = '\0';
	}
}

MyString::MyString(const MyString &other) {
	m_data = NULL;
	if (other.m_data != NULL) {
		m_data = new char[strlen(other.m_data) + 1];
		if (m_data != NULL) {
			strcpy(m_data, other.m_data);
		}
	}
}

MyString::~MyString() {
	if (m_data != NULL) {
		delete[] m_data;
		m_data = NULL;
	}
}

MyString &MyString::operator=(const MyString &other) {
	if (this != &other) {
		if (m_data != NULL) {
			delete[] m_data;
			m_data = NULL;
		}
		if (other.m_data != NULL) {
			m_data = new char[strlen(other.m_data) + 1];
			strcpy(m_data, other.m_data);
		}
	}
	return *this;
}

ostream &operator<<(ostream &os, const MyString &str) {
	os << str.m_data;
	return os;
}

size_t MyString::getLength() const {
	return strlen(m_data);
}
