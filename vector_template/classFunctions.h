#pragma once



template<class Type>
Vector<Type>::Vector()
{
	try
	{
		//	Invalid type
		if (checkTypeName<Type>() == false)
		{
			throw myError("Type can be only float, double, int or char!", __TIME__, __LINE__);
		}

		this->_array = new Type[this->_capacity];
	}
	catch (const std::exception& ex)
	{
		cout << ex.what() << endl;
	}
	
}

template<class Type>
Vector<Type>::Vector(size_t capacity)
{
	try
	{
		//	Invalid type
		if (checkTypeName<Type>() == false)
		{
			throw myError("Type can be only float, double, int or char!", __TIME__, __LINE__);
		}
		try
		{
			//	If capacity == negative		ERROR	
			if (capacity < 0)
			{
				throw bad_array_new_length();

			}
			if (capacity < 15)
			{
				this->_array = new Type[this->_capacity];
			}

			this->_capacity = capacity;
			this->_array = new Type[this->_capacity];

		}
		catch (const std::exception& ex)
		{
			cout << ex.what() << endl;
		}

	}
	catch (const myError& ex)
	{
		cout << ex.what() << endl;
	}
}

template<class Type>
Vector<Type>::~Vector()
{
	delete[] this->_array;
}

template<class Type>
const Type* Vector<Type>::get_array() const
{
	return this->_array;
}

template<class Type>
const size_t Vector<Type>::get_size() const
{
	return this->_size;
}

template<class Type>
const size_t Vector<Type>::capacity() const
{
	return this->_capacity;
}

template<class Type>
void Vector<Type>::print()
{
	if (this->_array != nullptr)
	{
		for (size_t i = 0; i < this->_size; i++)
		{
			cout << this->_array[i] << endl;
		}
	}
}

template<class Type>
Type& Vector<Type>::operator[](int index)
{
	try
	{
		//	If index == negative	ERROR
		if (index < 0)
		{
			throw myError("Index can not be negative number!",__TIME__, __LINE__);
		}
		return this->_array[index];
	}
	catch (const exception& ex)
	{
		cout << ex.what() << endl;
	}
}

template<class Type>
Vector<Type>& Vector<Type>::operator()(int index)
{
	try
	{
		//	If index == negative	ERROR
		if (index < 0)
		{
			throw myError("Index can not be negative number!", __TIME__, __LINE__);
		}
		return this->_array[index];
	}
	catch (const exception& ex)
	{
		cout << ex.what() << endl;
	}
}

template<class Type>
Vector<Type>& Vector<Type>::push_back(const Type value)
{
	if ((this->_size + 1) == this->_capacity)
	{
		this->_capacity += 15;
		Type* newArray = new Type[this->_capacity];
		for (size_t i = 0; i < this->_size; i++)
		{
			newArray[i] = this->_array[i];
		}
		newArray[this->_size] = value;

		delete[] this->_array;
		this->_array = newArray;
	}
	else
	{
		this->_array[this->_size] = value;
	}
	this->_size++;

	return *this;
}

template<class Type>
Vector<Type>& Vector<Type>::push_front(const Type value)
{
	if ((this->_size + 1) == this->_capacity)
	{
		this->_capacity += 15;

		int* newArray = new int[this->_capacity];
		newArray[0] = value;
		for (size_t i = 1; i <= this->_size; i++)
		{
			newArray[i] = this->_array[i];
		}

		delete[] this->_array;
		this->_array = newArray;
	}
	else
	{
		int* newArray = new int[this->_capacity];
		newArray[0] = value;
		for (size_t i = 1; i <= this->_size; i++)
		{
			newArray[i] = this->_array[i - 1];
		}

		delete[] this->_array;
		this->_array = newArray;
	}



	this->_size++;

	return *this;
}

template<class Type>
Vector<Type>& Vector<Type>::pop_back()
{
	int* newArray = new int[this->_capacity];
	for (size_t i = 0; i < this->_size - 1; i++)
	{
		newArray[i] = this->_array[i];
	}

	delete[] this->_array;
	this->_array = newArray;

	this->_size--;

	return *this;
}

template<class Type>
Vector<Type>& Vector<Type>::pop_front()
{
	int* newArray = new int[this->_capacity];
	for (size_t i = 1; i < this->_size; i++)
	{
		newArray[i - 1] = this->_array[i];
	}

	delete[] this->_array;
	this->_array = newArray;

	this->_size--;

	return *this;
}

template<class Type>
void Vector<Type>::delete_by_index(const int index)
{
	try
	{
		//	If index == negative	ERROR	
		if (index < 0)
		{
			throw myError("Index can not be negative number!", __TIME__, __LINE__);
		}

		if (index < this->_size)
		{
			int* newArr = new Type[this->_capacity];

			for (size_t i = 0; i < this->_size; i++)
			{
				if (i < index)
				{
					newArr[i] = this->_array[i];
				}
				else
				{
					newArr[i] = this->_array[i + 1];
				}
			}

			this->_size--;

			delete[] this->_array;
			this->_array = newArr;
		}
	}
	catch (const exception& ex)
	{
		cout << ex.what() << endl;
	}

}

template<class Type>
void Vector<Type>::insert_by_index(const int index, const Type element)
{
	try
	{
		//	If index == negative	ERROR	
		if (index < 0)
		{
			throw myError("Index can not be negative number!", __TIME__, __LINE__);
		}

		if (index < this->_size)
		{
			if (_size + 1 == _capacity)
			{
				_capacity += 15;
			}

			int* newArr = new int[this->_capacity];

			for (size_t i = 0; i < this->_size + 1; i++)
			{
				if (i < index)
				{
					newArr[i] = this->_array[i];
				}
				else if (i == index)
				{
					newArr[i] = element;
				}
				else
				{
					newArr[i] = this->_array[i - 1];
				}
			}

			this->_size++;

			delete[] this->_array;
			this->_array = newArr;
		}
	}
	catch (const exception& ex)
	{
		cout << ex.what() << endl;
	}
}


// tapsa index-ni qaytarsin,
// tapmasa -1 (unsigned int-in max qiymeti qayidacaq)
template<class Type>
size_t Vector<Type>::find(const Type element)
{
	size_t index;
	for (size_t i = 0; i < this->_size; i++)
	{
		if (this->_array[i] == element)
		{
			index = i;
			break;
		}
	}

	return index;
}

template<class Type>
size_t Vector<Type>::rfind(const Type element)
{
	size_t index;
	for (size_t i = this->_size - 1; i >= 0; i--)
	{
		if (this->_array[i] == element)
		{
			index = i;
			break;
		}
	}

	return index;
}

// reverse true gonderilse, tersine sort olunsun.
template<class Type>
void Vector<Type>::sort(bool reverse)
{
	if (reverse)
	{
		for (size_t i = 0; i < _size; i++)
		{
			for (size_t j = 0; j < _size; j++)
			{
				if (_array[j] < _array[j + 1])
				{
					swap(_array[j], _array[j + 1]);
				}
			}
		}
	}
	else
	{
		for (size_t i = 0; i < _size; i++)
		{
			for (size_t j = 0; j < _size; j++)
			{
				if (_array[j] > _array[j + 1])
				{
					swap(_array[j], _array[j + 1]);
				}
			}
		}
	}
}

