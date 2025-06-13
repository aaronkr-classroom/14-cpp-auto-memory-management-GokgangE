//Ref_handle.h
#pragma once
#ifndef GUARD_Ref_handle_h
#define GUARD_Ref_handle_h

#include <cstddef>
#include <stdexcept>

using namespace std;

template <class T> class Ref_handle {
public:
	// ���� ī��Ʈ�� ������ó�� ����
	Ref_handle() : p(0), refptr(new size_t(1)) { }
	Ref_handle(T* t) : p(t), refptr(new size_t(1)) { }
	Ref_handle(const Ref_handle& h) : p(h, p), refptr(h.refptr) {
		++*refptr;
	}

	Ref_handle& operator=(const Ref_handle&);
	~Ref_handle();

	//������ ����
	operator bool() const { return p; }
	T& operator*() const {
		if (p) return *p;
		throw runtime_error("unbound Ref_handle");
	}
	T* operator->() const {
		if (p) return p;
		throw runtime_error("unbound Ref_handle");
	}
private:
	T* p;
	size_t* refptr;
};


#endif // !GUARD_Ref_Handle_h

