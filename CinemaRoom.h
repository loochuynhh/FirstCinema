#ifndef CINEMAROOM_H
#define CINEMAROOM_H
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

class CinemaRoom
{
public:
	string getId();
	int getRow();
	int getColumn();
	string getStatus();
	void setId(const string&);
	void setRow(int);
	void setColumn(int);
	void setStatus(const string&);
	void readDataFile(fstream&);
	void writeDataFile(fstream&);
	void writeData();
private:
	string id;
	int row;
	int column;
	string status;
	int type;
};

#endif
