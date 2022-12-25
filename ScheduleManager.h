#pragma once
#include "Manager.h"
#include "Schedule.h"
#include "FilmManager.h"
#include "CinemaRoomManager.h"

class ScheduleManager : public Manager<Schedule>
{
public:
	ScheduleManager(FilmManager& FilmManager, CinemaRoomManager& room);
	void getShow();
	Schedule setScheduleInfor();
	int getType(const string&);
	bool checkRoomExist(const string&, const Time&);
	bool checkFilmExist(const string&, const Time&);
	bool checkShow(int show, int minute);
	void readFile(fstream&);
	void writeFile(fstream&);
	void write();
private:
	FilmManager* filmManager;
	CinemaRoomManager* cinemaRoomManager;
};
