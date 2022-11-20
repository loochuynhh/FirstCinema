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
	void deleteByRoom(const string&);
	void deleteByFilm(const string&);
	void readFile(fstream&);
	void writeFile(fstream&);
	void write();
private:
	FilmManager* filmManager;
	CinemaRoomManager* cinemaRoomManager;
};
