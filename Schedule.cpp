#include "Schedule.h"

Schedule::Schedule() {
	this->seatStatus = nullptr;
}

void Schedule::createSeat(CinemaRoom* room) {
	Seat *seats;
	seats = new Seat[room->getRow()*room->getColumn()];
	for(int i = 0; i < room->getRow(); i++) {
		char a = 'A' + i;
		for(int j = 0; j < room->getColumn(); j++) {
			string idt = string(&a);
			string idt2;
			int k = j + 1;
			if(k < 10) {
				idt2 = "0";
				idt2.append(to_string(k));
			}
			else idt2 = to_string(k);
			string id = idt.append(idt2);
			Seat seat;
			seat.setId(id);
			if(i > 3) {
				seat.setVip(true);
			}
			else {
				seat.setVip(false);
			}
			seats[room->getColumn()*i + j] = seat;
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

Seat* Schedule::getSeatStatus() const{
	return this->seatStatus;
}

Time Schedule::getTime() const {
	return this->time;
}

void Schedule::showSeatStatus() {
	for(int i = 0; i < this->row; i++) {
		for(int j = 0; j < this->column; j++) {
			if((this->seatStatus + this->column*i + j)->getChecked()) cout << "xx" << " ";
			else cout << (this->seatStatus + this->column*i + j)->getId() << "  ";
		}
		cout << endl;
	}
}

Seat* Schedule::getSeat(string id) {
	for(int i = 0; i < this->row*this->column; i++) {
		if((this->seatStatus + i)->getId() == id) return (this->seatStatus + i);
	}
	return nullptr;
}

void Schedule::setId(const string& id) {
	this->id = id;
}

void Schedule::setFilmId(const string& filmId) {
	this->filmId = filmId;
}

void Schedule::setSeatStatus(Seat& seat) {
	this->seatStatus = &seat;
	cout << "done 3" << endl;
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
	int show;
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
	this->time.readfilet(filein);
}
void Schedule::writeDataFile(fstream& fileout) {
	fileout << this->getId() << ", ";
	fileout << this->getFilmId() << ", ";
	fileout << this->getCinemaRoomId() << ", ";
	fileout << this->getShow() << ", ";
	this->time.writefilet(fileout);
	fileout << "\n";
}
void Schedule::writeData() {
	cout << "|";
	cout << "   " << left << setw(14) << this->getId() << "|";
	cout << "   " << left << setw(10) << this->getFilmId() << "|";
	cout << "    " << left << setw(14) << this->getCinemaRoomId() << "|";
	cout << "  " << left << setw(4) << this->getShow() << "|";
	cout << "     ";
	this->getTime().writet();
	cout << "     |\n";
}