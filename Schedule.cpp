#include "Schedule.h"
#include <Windows.h>
Schedule::Schedule() {
	this->seatStatus = nullptr;
}

void Schedule::createSeat(CinemaRoom* room) {
	Seat* seats;
	seats = new Seat[room->getRow() * room->getColumn()];
	for (int i = 1; i <= room->getColumn(); i++) {
		string id = "";
		id.push_back(i + 64);
		for (int j = 1; j <= room->getRow(); j++) {
			if (j < 10) {
				id.push_back(48);
				id.push_back(j + 48);
			}
			else {
				id.push_back((j / 10) + 48);
				id.push_back((j % 10) + 48);
			}
			Seat seat;
			seat.setId(id);
			id.resize(id.size() - 2);
			if (i > 3) {
				seat.setVip(true);
			}
			else {
				seat.setVip(false);
			}
			seats[room->getRow() * (i - 1) + j - 1] = seat;
		}
	}
	this->seatStatus = seats;
	this->row = room->getRow();
	this->column = room->getColumn();
}

string Schedule::getId() const {
	return this->id;
}

string Schedule::getFilmId() const {
	return this->filmId;
}

string Schedule::getCinemaRoomId() const {
	return this->cinemaRoomId;
}

int Schedule::getShow() const {
	return this->show;
}

Seat* Schedule::getSeatStatus() const {
	return this->seatStatus;
}

Time Schedule::getTime() const {
	return this->time;
}

int Schedule::getBaseCost() const {
	return this->baseCost;
}

void Schedule::showSeatStatus() {
	HANDLE cl = GetStdHandle(STD_OUTPUT_HANDLE);
	char a = char(64);
	SetConsoleTextAttribute(cl, 0xC);
	cout << "\n\n\t\t\t\t\t\t\tTHONG TIN CUA LICH CHIEU " << this->getId();
	SetConsoleTextAttribute(cl, 7);
	cout << "\n\n\n\t\t\t\t\t    ";
	for (int i = this->row; i > 0; i--) {
		cout << i;
		if (i > 9) cout << "  ";
		else cout << "   ";
	}
	for (int i = this->column; i > 0; i--) {
		cout << "\n\n\t\t\t\t\t";
		SetConsoleTextAttribute(cl, 7);
		cout << char(a + i) << "   ";
		for (int j = this->row; j > 0; j--) {
			if (i < 4) {
				SetConsoleTextAttribute(cl, 0xC | 0x80);
				if ((this->getSeatStatus() + (i - 1) * this->row + j - 1)->getChecked() == 1) { 
					SetConsoleTextAttribute(cl, 0xC | 0x40);
					cout << "   "; 
				}
				else cout << "   ";
				//cout << (this->getSeatStatus() + (i - 1) * this->row + j - 1)->getId();
				SetConsoleTextAttribute(cl, 7);
				cout << " ";
			}
			else {
				SetConsoleTextAttribute(cl, 0xC | 0xA0);
				if ((this->getSeatStatus() + (i - 1) * this->row + j - 1)->getChecked() == 1) {
					SetConsoleTextAttribute(cl, 0xC | 0x40);
					cout << "   ";
				}
				else cout << "   ";
				//cout << (this->getSeatStatus() + (i - 1) * this->row + j - 1)->getId();
				SetConsoleTextAttribute(cl, 7);
				cout << " ";
			}
		}
		cout << "\t\t";
		if (i == 1) {
			SetConsoleTextAttribute(cl, 0xE);
			cout << "Ma phim: " << this->filmId;
		}
		else if (i == 2) {
			SetConsoleTextAttribute(cl, 0xE);
			cout << "Ma phong chieu: " << this->cinemaRoomId;
		}
		else if (i == 3) {
			SetConsoleTextAttribute(cl, 0xE);
			cout << "Ca chieu thu:  " << this->show;
		}
		else if (i == 4) {
			SetConsoleTextAttribute(cl, 0xE);
			cout << "Gia ve ghe thuong:  " << this->baseCost;
		}
		else if (i == 5) {
			SetConsoleTextAttribute(cl, 0xE);
			cout << "Gia ve ghe VIP:  " << this->baseCost + 5;
		}
		else if (i == 6) {
			SetConsoleTextAttribute(cl, 0xE);
			cout << "Ngay chieu:  "; this->getTime().writet();
		}
		else if (i == 7) {
			SetConsoleTextAttribute(cl, 0xC | 0x80);
			cout << "  ";
			SetConsoleTextAttribute(cl, 0xE);
			cout << "  Ghe thuong";
		}
		else if (i == 8) {
			SetConsoleTextAttribute(cl, 0xC | 0xA0);
			cout << "  ";
			SetConsoleTextAttribute(cl, 0xE);
			cout << "  Ghe VIP";
		}
		else if (i == 9) {
			SetConsoleTextAttribute(cl, 0xC | 0x40);
			cout << "  ";
			SetConsoleTextAttribute(cl, 0xE);
			cout << "  Ghe da dat";
		}
	}
	SetConsoleTextAttribute(cl, 0xF0 | 0x70);
	cout << "\n\n\n\t\t\t\t\t\t";
	for (int i = 0; i < ((this->row - 2) * 4 - 1) / 2 - 4; i++) cout << " ";
	cout << "MAN HINH";
	for (int i = 0; i < ((this->row - 2) * 4 - 1) / 2 - 3; i++) cout << " ";
	cout << "\n\t\t\t\t";
	SetConsoleTextAttribute(cl, 7);
}

Seat* Schedule::getSeat(string id) {
	for (int i = 0; i < this->row * this->column; i++) {
		if ((this->seatStatus + i)->getId() == id) return (this->seatStatus + i);
	}
	return nullptr;
}

void Schedule::setId(const string& id) {
	this->id = id;
}

void Schedule::setFilmId(const string& filmId) {
	this->filmId = filmId;
}

void Schedule::setBaseCost(int base) {
	this->baseCost = base;
}

void Schedule::setSeatStatus(Seat& seat) {
	this->seatStatus = &seat;
	cout << "done 3" << endl;
}

int Schedule::getRow() {
	return this->row;
}
int Schedule::getColumn() {
	return this->column;
}
void Schedule::setShow(const int& period) {
	this->show = period;
}

void Schedule::setCinemaRoomId(const string& id) {
	this->cinemaRoomId = id;
}

void Schedule::setTime(const Time& Day) {
	this->time = Day;
}

Schedule::~Schedule() {
	delete[] this->seatStatus;
}

void Schedule::readDataFile(fstream& filein) {
	filein.ignore(20, 10);
	string id, filmid, cnmrid;
	int show, baseCost;
	Time time;
	getline(filein, id, ',');
	this->setId(id);
	filein.ignore(1);
	getline(filein, filmid, ',');
	this->setFilmId(filmid);
	filein.ignore(1);
	getline(filein, cnmrid, ',');
	this->setCinemaRoomId(cnmrid);
	filein.ignore(1);
	filein >> show;
	this->setShow(show);
	filein.ignore(1);
	filein >> baseCost;
	this->setBaseCost(baseCost);
	filein.ignore(1);
	this->time.readfilet(filein);
}
void Schedule::writeDataFile(fstream& fileout) {
	fileout << this->getId() << ", ";
	fileout << this->getFilmId() << ", ";
	fileout << this->getCinemaRoomId() << ", ";
	fileout << this->getShow() << ", ";
	fileout << this->getBaseCost() << ", ";
	this->time.writefilet(fileout);
	fileout << "\n";
}
void Schedule::writeData() {
	cout << "|";
	cout << "     " << left << setw(12) << this->getId() << "|";
	cout << "    " << left << setw(9) << this->getFilmId() << "|";
	cout << "      " << left << setw(12) << this->getCinemaRoomId() << "|";
	cout << "  " << left << setw(4) << this->getShow() << "|";
	cout << "     " << left << setw(7) << this->getBaseCost() << "|";
	cout << "     ";
	this->getTime().writet();
	cout << "     |\n";
}