// Str_Vec.cpp
#include <iostream>
#include <iterator>
#include <cstring>

#include "Str_Vec.h"

// 12.3.2 / p216
std::istream& operator>>(std::istream& is, Str& s) {
	// ������ �� ����
	s.data->clear();

	// ����
	char c;
	while (is.get(c) && isspace(c)) ; // �ƹ��͵� ����

	// ��� ���ڰ� ������ ���� ������� �Է��� ����
	if (is) {
		do s.data->push_back(c);
		while (is.get(c) && !isspace(c)) ; // �ƹ��͵� ����

		// ���� ������ �ٽ� ��Ʈ������ ������
		if (is)
			is.unget();
	}
	return is;
}

std::istream& getline(std::istream& is, Str& s) {
	// ������ �� ����
	s.data->clear();

	// ����
	char c;
	while (is.get(c) && isspace(c)); // �ƹ��͵� ����

	// ��� ���ڰ� ������ ���� ������� �Է��� ����
	if (is) {
		do s.data->push_back(c);
		while (is.get(c) && !isspace(c)); // �ƹ��͵� ����

		// ���� ������ �ٽ� ��Ʈ������ ������
		if (is)
			is.unget();
	}
	return is;
}

std::ostream& operator<<(std::ostream& os, const Str& s) {
	for (Str::size_type i = 0; i != s.size(); ++i) {
		os << s[i];
	}
	return os;
}

// Section 12.3.3 / p219
Str operator+(const Str& s, const Str& t) {
	Str r = s;
	r += t;
	return r;
}