#include <iostream>
#include <conio.h>

using namespace std;

template <class T>
class Shared_ptr {
private:

	int *c; //object type: counter
	T *obj; // pointer, which we store

public:
	// �������������
	Shared_ptr() {
		c = nullptr;
		obj = nullptr;
	}
	//�����������
	Shared_ptr(T *t) {
		obj = t;
		c = new int(1);
	}
	//����������� �����������(������ ������ ������ ���������������� ������ �������� ������ ������)
	Shared_ptr(Shared_ptr& t) { //Shared_ptr p(new int(2));Shared_ptr a(p);
		this->c = t.c;
		this->obj = t.obj;
		((*c)++);
	}
	// ����������
	~Shared_ptr() {
		this->Reset();
	}
	//����� ��������
	void Reset() {
		if (c == nullptr) {
			throw "empty pointer";
		//	cout << "������ ���������. ��� �������" << endl;
		}
		else {
			if ((*c) == 1) {
				delete obj;
				delete c;
				//cout << "������ ��� ������" << endl;
				c = nullptr;
				obj = nullptr;
			}
			else {
				obj = nullptr;
				((*c)--);

				//cout << " ��������-" << *c << endl;
				c = nullptr;
			}
		}
		//_getch();
	}
	// ��������������� ��������� ������������
	Shared_ptr& operator= (const Shared_ptr& tmp) {
		// this-> Reset();
		this->obj = tmp.obj;
		this->c = tmp.c;
		(*c)++;
		return *this;
	}


	// ����������� ����� ������(������ �������)
	T* Release() {
		T* t = obj;
		if (c == nullptr) {
			throw "empty object";
		}

		if ((*c) == 1) {
			obj = nullptr;
			c = nullptr;
		}
		else {
			obj = nullptr;
			(*c)--;
			c = nullptr;
		}
		return t;
	}

	T* operator* () {
		return obj;
	}

	T* operator-> () {
		return obj;
	}


};
int main()
{
	setlocale(LC_ALL, "Russian");
	int *x = new int(7);
	int *y = new int(5);
	Shared_ptr <int> a(x);
	cout << *(*a) << endl;
	a.Reset();
	Shared_ptr <int> b(new int(3));
	cout << *(*b) << endl;
	b.Reset();


	Shared_ptr <int> c(y);
	Shared_ptr <int> d;
	d = c;
	cout << *(*d) << endl;
	//  d.Reset();
	//c.Reset();
	b.Reset();
	system("Pause");

}
