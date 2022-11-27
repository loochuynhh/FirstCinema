#include "Ticket.h"

string Ticket::getId() const {
	return this->id;
}

string Ticket::getScheduleId() const {
	return this->scheduleId;
}

string Ticket::getCustomerName() const {
	return this->customerName;
}

string Ticket::getCustomerPhone() const {
	return this->customerPhone;
}

string Ticket::getStaffId() const {
	return this->staffId;
}

int Ticket::getCountReg() {
	return this->regSeat;
}

int Ticket::getCountVip() {
	return this->vipSeat;
}

int Ticket::getSoda_Corn() {
	return this->soda_corn;
}

string* Ticket::getIdVipSeat(int i) {
	return this->idVip + i;
}

string* Ticket::getIdRegSeat(int i) {
	return this->idReg + i;
}

void Ticket::setSeat(int vipSeat, int regSeat, string* idVip, string* idReg) {
	this->vipSeat = vipSeat;
	this->regSeat = regSeat;
	this->idVip = idVip;
	this->idReg = idReg;
}

void Ticket::setInfor(Ticket ticket) {
	this->id = ticket.id;
	this->scheduleId = ticket.scheduleId;
	this->customerName = ticket.customerName;
	this->customerPhone = ticket.customerPhone;
	this->staffId = ticket.staffId;
	this->soda_corn = ticket.soda_corn;
}

string* Ticket::getIdAllSeat() {
	string* all = new string[this->vipSeat + this->regSeat];
	for (int i = 0; i < this->vipSeat; i++) {
		*(all + i) = *(this->idVip + i);
	}

	for (int i = this->vipSeat; i < this->vipSeat + this->regSeat; i++) {
		*(all + i) = *(this->idReg + (i - this->vipSeat));
	}
	return all;
}

void Ticket::addSeat(const string& id, bool vip) {
	if (vip) {
		string* vip = new string[this->vipSeat + 1];
		for (int i = 0; i < this->vipSeat; i++) {
			*(vip + i) = *(this->idVip + i);
		}
		vip[this->vipSeat] = id;
		delete[] this->idVip;
		this->idVip = vip;
		this->vipSeat++;
	}
	else {
		string* reg = new string[this->regSeat + 1];
		for (int i = 0; i < this->regSeat; i++) {
			*(reg + i) = *(this->idReg + i);
		}
		reg[this->regSeat] = id;
		delete[] this->idReg;
		this->idReg = reg;
		this->regSeat++;
	}
}

void Ticket::setId(const string& id) {
	this->id = id;
}

void Ticket::setScheduleId(const string& id) {
	this->scheduleId = id;
}

void Ticket::setCustomerName(const string& name) {
	this->customerName = name;
}

void Ticket::setCustomerPhone(const string& phone) {
	this->customerPhone = phone;
}

void Ticket::setStaffId(const string& id) {
	this->staffId = id;
}

void Ticket::setSoda_Corn(int soda_corn) {
	this->soda_corn = soda_corn;
}

Ticket::Ticket() {
	this->regSeat = 0;
	this->vipSeat = 0;
	this->idVip = nullptr;
	this->idReg = nullptr;
}

Ticket::~Ticket() {
	delete[] this->idVip;
	delete[] this->idReg;
}

string* Ticket::readDataFile(fstream& filein) {
	filein.ignore(20, 10);
	string id, scheduleid, customername, customerphone, staffid;
	int vipSeat, soda_corn, regSeat, amount;
	getline(filein, id, ',');
	this->setId(id);
	filein.ignore(1);
	getline(filein, scheduleid, ',');
	this->setScheduleId(scheduleid);
	filein.ignore(1);
	getline(filein, customername, ',');
	this->setCustomerName(customername);
	filein.ignore(1);
	getline(filein, customerphone, ',');
	this->setCustomerPhone(customerphone);
	filein.ignore(1);
	getline(filein, staffid, ',');
	this->setStaffId(staffid);
	filein.ignore(1);
	filein >> amount;
	filein.ignore(2);
	string* ids = new string[amount + 1];
	for (int i = 0; i < amount; i++) {
		string seatId;
		getline(filein, seatId, ',');
		filein.ignore(1);
		ids[i] = seatId;
	}
	ids[amount] = "";
	filein >> soda_corn;
	this->setSoda_Corn(soda_corn);
	return ids;
}
void Ticket::writeDataFile(fstream& fileout) {
	fileout << this->getId() << ", ";
	fileout << this->getScheduleId() << ", ";
	fileout << this->getCustomerName() << ", ";
	fileout << this->getCustomerPhone() << ", ";
	fileout << this->getStaffId() << ", ";
	fileout << this->getCountVip() + this->getCountReg() << ", ";
	for (int i = 0; i < this->getCountVip(); i++) fileout << this->getIdVipSeat(i) << ", ";
	for (int i = 0; i < this->getCountReg(); i++) fileout << this->getIdRegSeat(i) << ", ";
	fileout << this->getSoda_Corn() << ".";
	fileout << "\n";
}
void Ticket::writeData() {
	cout << "|";
	cout << "     " << left << setw(10) << this->getId() << "|";
	cout << "     " << left << setw(11) << this->getStaffId() << "|";
	cout << "     " << left << setw(12) << this->getScheduleId() << "|";
	cout << "   " << left << setw(15) << this->getCustomerPhone() << "|";
	cout << "   " << left << setw(27) << this->getCustomerName() << "|";
	cout << "    " << left << setw(5) << this->vipSeat + this->regSeat << "|";
	cout << "    " << left << setw(5) << this->getSoda_Corn() << "|\n";
}