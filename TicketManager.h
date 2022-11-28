#pragma once
#include "ScheduleManager.h"
#include "StaffManager.h"
#include "Ticket.h"
#include "Time.h"
#include "Error.h"

class TicketManager : public Manager<Ticket>
{
public:
	long long int getRevenue();
	long long int getRevenue(string);
	long long int getRevenue(Time&, Time&);
	void getRevenueY(int);
	TicketManager(ScheduleManager&, StaffManager&);
	Ticket setTicketInfor();
	void readFile(fstream&);
	void writeFile(fstream&);
	void write();
private:
	ScheduleManager* scheduleList;
	StaffManager* staffManager;
};