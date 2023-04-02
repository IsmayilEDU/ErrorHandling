#pragma once

template<class Type>
class Vector {
private:
	Type* _array = nullptr;
	size_t _size = 0;
	size_t _capacity = 15;
public:
	Vector();
	Vector(size_t capacity);
	~Vector();
	const Type* get_array() const;
	const size_t get_size() const;
	const size_t capacity() const;
	void print();
	Type& operator[](int index);
	Vector& operator()(int index);
	Vector& push_back(const Type value);
	Vector& push_front(const Type value);
	Vector& pop_back();
	Vector& pop_front();
	void delete_by_index(const int index);
	void insert_by_index(const int index, const Type element);
	// tapsa index-ni qaytarsin,
	// tapmasa -1 (unsigned int-in max qiymeti qayidacaq)
	size_t find(const Type element);
	size_t rfind(const Type element);
	// reverse true gonderilse, tersine sort olunsun.
	void sort(bool reverse = false);

};

