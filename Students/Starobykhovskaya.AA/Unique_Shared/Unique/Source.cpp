#include <iostream>
//#include <conio.h>

using namespace std;

class Cat {
public:
	int name;
	friend ostream& operator<<(ostream& os, Cat& cat);
};

ostream& operator<<(ostream& os, Cat& cat) {
	os << cat.name << endl;
	return os;
}

template <class T>
class Unique_ptr {
private:

	T *obj; // pointer, which we store

	bool isExist;
	// ��������������� ��������� ������������
	Unique_ptr& operator= (const Unique_ptr& tmp) {}
	Unique_ptr(const Unique_ptr& t) {}
public:
	//�����������
	Unique_ptr(T *t) {

		obj = t;
		isExist = true;
	}
	//����������� �����������(������ ������ ������ ���������������� ������ �������� ������ ������)

	// ����������
	~Unique_ptr() {

		this->Reset();
	}

	//����� ��������
	void Reset() {
		if (isExist) {
			delete obj;
			isExist = false;
			cout << "The object was deleted." << endl;
			//_getch();
		}

	}

	// ��������������� ��������� *
	T* operator* () {
		return obj;
	}
	// ��������������� ��������� ->
	T* operator-> () {
		return obj;
	}
	// ����������� ����� ������(������ �������)
	T* Release() {
		T* temp = obj;
		obj = nullptr;
		//cout << "release" << endl;
		isExist = false;
		return temp;
	}


};

int main()
{
	setlocale(LC_ALL, "Russian");
	
	Unique_ptr<int> t(new int(2));
	Unique_ptr<Cat> a(new Cat());
	a->name = 78;
	cout << a->name << endl;
	Cat *c;
	c = a.Release();

	//_getch();

}
