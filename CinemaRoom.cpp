#include "CinemaRoom.h"

string CinemaRoom::getId() {
	return this->id;
}

int CinemaRoom::getRow() {
	return this->row;
}

int CinemaRoom::getColumn() {
	return this->column;
}

string CinemaRoom::getStatus() {
	return this->status;
}

void CinemaRoom::setId(const string& id) {
	this->id = id;
}

void CinemaRoom::setRow(int row) {
	this->row = row;
}

void CinemaRoom::setColumn(int column) {
	this->column = column;
}

void CinemaRoom::setStatus(const string& status) {
	this->status = status;
}

void CinemaRoom::readDataFile(fstream& filein) {
	filein.ignore(20, 10);
	string id, status;
	int row, column;
	getline(filein, id, ',');
	this->setId(id);
	filein >> row;
	this->setRow(row);
	filein.ignore(20, 32);
	filein >> column;
	this->setColumn(column);
	getline(filein, status, '.');
	this->setStatus(status);
}
void CinemaRoom::writeDataFile(fstream& fileout) {
	fileout << this->getId() << ", ";
	fileout << this->getRow() << ", ";
	fileout << this->getColumn() << ", ";
	fileout << this->getStatus() << ". ";
	fileout << "\n";
}
void CinemaRoom::writeData() {
	cout << "|";
	cout << left << setw(10) << " " << left << setw(8) << this->getId() << left << setw(8) << " " << "|";
	cout << left << setw(5) << " " << left << setw(8) << this->row*this->column << "|";
	cout << left << setw(15) << " " << left << setw(20) << this->getStatus() << "|";
	cout << "\n";
}