#ifndef SCHEDULE_H
#define SCHEDULE_H
#include <iostream>
#include "Time.h"
#include <string>
#include "Seat.h"
#include "CinemaRoom.h"

using namespace std;

class Schedule
{
public:
	Schedule();
	void createSeat(CinemaRoom*);
	~Schedule();
	string getId() const;
	string getFilmId() const;
	string getCinemaRoomId() const;
	Seat* getSeatStatus() const;
	int getShow() const;
	int getBaseCost() const;
	Time getTime() const;
	void setId(const string&);
	void setFilmId(const string&);
	Seat* getSeat(string);
	int getRow();
	int getColumn();
	void setShow(const int&);
	void setTime(const Time&);
	void setBaseCost(int);
	void setSeatStatus(Seat&);
	void setCinemaRoomId(const string&);
	void showSeatStatus();
	void readDataFile(fstream&);
	void writeDataFile(fstream&);
	void writeData();
private:
	string id;
	string filmId;
	string cinemaRoomId;
	int show;
	Time time;
	Seat* seatStatus;
	int row;
	int column;
	int baseCost;
};

#endif