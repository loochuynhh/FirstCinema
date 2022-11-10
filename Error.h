#ifndef ERROR_H
#define ERROR_H
#include <iostream>
#include <string>

using namespace std;

class Error
{
public:
	void getMessage();
    Error(int);
    Error();
private:
	int errorCode;
};

#endif
