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

int CinemaRoom::getType() {
	return this->type;
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

void CinemaRoom::setType(int type) {
	this->type = type;
}

void CinemaRoom::readDataFile(fstream& filein) {
	filein.ignore(20, 10);
	string id, status;
	int row, column, type;
	getline(filein, id, ',');
	this->setId(id);
	filein >> row;
	this->setRow(row);
	filein.ignore(20, 32);
	filein >> column;
	this->setColumn(column);
	filein.ignore(1);
	filein >> type;
	this->setType(type);
	filein.ignore(2);
	getline(filein, status, '.');
	this->setStatus(status);
}
void CinemaRoom::writeDataFile(fstream& fileout) {
	fileout << this->getId() << ", ";
	fileout << this->getRow() << ", ";
	fileout << this->getColumn() << ", ";
	fileout << this->getType() << ", ";
	fileout << this->getStatus() << ". ";
	fileout << "\n";
}
void CinemaRoom::writeData() {
	cout << "|";
	cout << left << setw(6) << " " << left << setw(11) << this->getId() << "|";
	cout << left << setw(7) << " " << left << setw(8) << this->row << "|";
	cout << left << setw(6) << " " << left << setw(8) << this->column << "|";
	if (this->getType() == 1) cout << left << setw(6) << " " << left << setw(8) << "2D" << "|";
	else if (this->getType() == 2) cout << left << setw(6) << " " << left << setw(8) << "3D" << "|";
	else cout << left << setw(5) << " " << left << setw(9) << "IMAX" << "|";
	cout << left << setw(4) << " " << left << setw(9) << this->getStatus() << "|";
	cout << "\n";
}