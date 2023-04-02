#pragma once

class myError : public exception
{

	string _message;
	string _time;
	int _line;

public:

	myError(const string message, const string time, const int line)
	{
		this->_time = time;
		this->_line = line;
		_message = "\nMessage: " + (string)message
			+ "\nTime: " + _time
			+ "\nLine: " + to_string(_line);
	}
	
	char const* what() const
	{
		return _message.c_str();
	}
};

//	Check sent type name for int, double, char or float
template<typename Type>
bool checkTypeName()
{
	bool check = true;

	//	Type name cast to string
	Type t;
	char* typeName = new char[30];
	short last = 0;
	for (short i = 0; typeid(t).name()[i] != '\0'; i++)
	{
		typeName[i] = typeid(t).name()[i];
		last = i;
	}
	typeName[last + 1] = '\0';
	const char* constTypeName = typeName;
	string type = constTypeName;

	if (type != "int" && type != "double" && type != "float" && type != "char")
	{
		check = false;
	}

	return check;
}