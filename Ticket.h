#ifndef TICKET_H
#define TICKET_H
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include "Seat.h"
#include "string.h"

using namespace std;

class Ticket
{
public:
	string getId() const;
	string getScheduleId() const;
	string getCustomerName() const;
	string getCustomerPhone() const;
	string getStaffId() const;
	int getCountVip();
	int getCountReg();
	int getSoda_Corn();
	string* getIdVipSeat();
	string* getIdRegSeat();
	string* getIdAllSeat();
	void addSeat(const string&, bool);
	void setId(const string&);
	void setScheduleId(const string&);
	void setCustomerName(const string&);
	void setCustomerPhone(const string&);
	void setStaffId(const string&);
	void setSoda_Corn(int);
	string* readDataFile(fstream&);
	void writeDataFile(fstream&);
	void writeData();
	void setInfor(Ticket);
	void setSeat(int, int, string*, string*);
	Ticket();
	~Ticket();
private:
	string id;
	string scheduleId;
	string customerName;
	string customerPhone;
	string staffId;
	int vipSeat;
	int regSeat;
	string* idVip;
	string* idReg;
	int soda_corn;
};

#endif
