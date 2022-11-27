#include "TicketManager.h"
#include <Windows.h>
void checkTkId(const string& id) {
	if (id.size() != 4) throw Error(9);
	for (int i = 0; i < id.length(); i++) {
		if (id[i] > '9' || id[i] < '0') {
			throw Error(1);
		}
	}
}

TicketManager::TicketManager(ScheduleManager& scheduleList, StaffManager& staffManager) {
	this->scheduleList = &scheduleList;
	this->staffManager = &staffManager;
}

Ticket TicketManager::setTicketInfor() {
	Node* node = this->head;
	Ticket ticket;
	string id;
	string customerName = "";
	string customerPhone;
	string staffId;
	string idin;
	string templ = "tk";
	int cost;
	int amount;
	int count = 0;
	Seat* seat = nullptr;
	int soda_corn;
	int check = 0;
	do {
		do {
			cout << "\n\t\t\t\t\t\t\tNhap id(vi du: tk0001, tk0100): ";
			try {
				cout << templ;
				getline(cin, idin);
				checkTkId(idin);
				break;
			}
			catch (Error error) {
				error.getMessage();
			}
		} while (true);
		id = templ + idin;
		if (this->findById(id) != nullptr) {
			do {
				cout << "\t\t\t\t\t\t\t\tMa bi trung!. Lua chon";
				cout << "\n\t\t\t\t\t\t\t1. Nhap lai";
				cout << "\t\t\t2. Thoat";
				cout << "\n\t\t\t\t\t\t\t";
				check = getInt();
				if (check != 1 && check != 2) {
					cout << "\t\t\t\t\t\t\tLua chon khong hop le! Moi chon lai.\n";
					system("pause");
				}
			} while (check != 1 && check != 2);
		}
		else check = 3;
	} while (check == 1 || check == 0);
	if (check == 2) {
		ticket.setId("null");
		return ticket;
	}
	check = 0;
	do {
		fflush(stdin);
		try {
			cout << "\t\t\t\t\t\t\tNhap so dien thoai khach hang: ";
			customerPhone = getphone();
			break;
		}
		catch (Error error) {
			error.getMessage();
		}
		catch (...) {
			cout << "Invalid information" << endl;
		}
	} while (true);
	check = 0;
	for (int i = 0; i < this->length; i++) {
		if (node->data.getCustomerPhone() == customerPhone) {
			customerName = node->data.getCustomerName();
			cout << "\t\t\t\t\t\t\tTen khach hang la: " << customerName << endl;
			system("pause");
			break;
		}
		node = node->next;
	}
	if (customerName == "") {
		cout << "\t\t\t\t\t\t\tNhap ten khach hang: ";
		getline(cin, customerName);
	}
	check = 0;
	do {
		system("cls");
		cout << "\n";
		this->staffManager->write();
		cout << "\n\t\t\t\t\t\t\tNhap ma nhan vien: ";
		getline(cin, staffId);
		if (this->staffManager->findById(staffId) == nullptr) {
			do {
				cout << "\t\t\t\t\t\t\t\tKhong tim thay nhan vien!. Lua chon";
				cout << "\n\t\t\t\t\t\t\t1. Nhap lai";
				cout << "\t\t\t2. Thoat";
				cout << "\n\t\t\t\t\t\t\t";
				check = getInt();
				if (check != 1 && check != 2) {
					cout << "\t\t\t\t\t\t\tLua chon khong hop le! Moi chon lai.\n";
					system("pause");
				}
			} while (check != 1 && check != 2);
		}
		else check = 3;
	} while (check == 1 || check == 0);
	if (check == 2) {
		ticket.setId("null");
		return ticket;
	}
	cout << "\t\t\t\t\t\t\tNhap so bap nuoc: ";
	soda_corn = getInt();
	ticket.setId(id);
	ticket.setCustomerName(customerName);
	ticket.setCustomerPhone(customerPhone);
	ticket.setStaffId(staffId);
	ticket.setSoda_Corn(soda_corn);
	return ticket;
}

int TicketManager::getRevenue() {
	Node* node = this->head;
	int revenue = 0;
	for (int i = 0; i < this->length; i++) {
		revenue += this->scheduleList->findById(node->data.getScheduleId())->getBaseCost() * (node->data.getCountReg() + node->data.getCountVip());
		if (this->scheduleList->getType(node->data.getScheduleId()) == 2) {
			revenue *= 2;
		}
		else if (this->scheduleList->getType(node->data.getScheduleId()) == 3) {
			revenue *= 3;
		}
		revenue += node->data.getCountVip() * 5;
		revenue += node->data.getSoda_Corn() * 20;
		node = node->next;
	}
	return revenue;
}

int TicketManager::getRevenue(Time& t1, Time& t2) {
	Node* node = this->head;
	int revenue = 0;
	for (int i = 0; i < this->length; i++) {
		Time t = (this->scheduleList)->findById(node->data.getScheduleId())->getTime();
		if (t >= t1 && t <= t2) {
			revenue += this->scheduleList->findById(node->data.getScheduleId())->getBaseCost() * (node->data.getCountReg() + node->data.getCountVip());
			if (this->scheduleList->getType(node->data.getScheduleId()) == 2) {
				revenue *= 2;
			}
			else if (this->scheduleList->getType(node->data.getScheduleId()) == 3) {
				revenue *= 3;
			}
			revenue += node->data.getCountVip() * 5;
			revenue += node->data.getSoda_Corn() * 20;
		}
		node = node->next;
	}
	return revenue;
}

int TicketManager::getRevenue(string staffId) {
	Node* node = this->head;
	int revenue = 0;
	for (int i = 0; i < this->length; i++) {
		if (node->data.getStaffId() == staffId) {
			revenue += this->scheduleList->findById(node->data.getScheduleId())->getBaseCost() * (node->data.getCountReg() + node->data.getCountVip());
			if (this->scheduleList->getType(node->data.getScheduleId()) == 2) {
				revenue *= 2;
			}
			else if (this->scheduleList->getType(node->data.getScheduleId()) == 3) {
				revenue *= 3;
			}
			revenue += node->data.getCountVip() * 5;
			revenue += node->data.getSoda_Corn() * 20;
		}
		node = node->next;
	}
	return revenue;
}

void TicketManager::getRevenueY(int year) {
	Node* node = this->head;
	int revenue[20][12];
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 12; j++) revenue[i][j] = 0;
	}
	for (int i = 0; i < this->staffManager->getLength(); i++) {
		cout << "a: " << i << endl;
		for (int j = 0; j < this->length; j++) {
			cout << "b: " << j << endl;
			if (this->scheduleList->findById(node->data.getScheduleId())->getTime().getYear() == year && (staffManager->operator[](i).getId()).compare(node->data.getStaffId()) == 0) {
				revenue[i][this->scheduleList->findById(node->data.getScheduleId())->getTime().getMonth() - 1] += this->scheduleList->findById(node->data.getScheduleId())->getBaseCost() * (node->data.getCountReg() + node->data.getCountVip());
				if (this->scheduleList->getType(node->data.getScheduleId()) == 2) {
					revenue[i][this->scheduleList->findById(node->data.getScheduleId())->getTime().getMonth() - 1] *= 2;
				}
				else if (this->scheduleList->getType(node->data.getScheduleId()) == 3) {
					revenue[i][this->scheduleList->findById(node->data.getScheduleId())->getTime().getMonth() - 1] *= 3;
				}
				revenue[i][this->scheduleList->findById(node->data.getScheduleId())->getTime().getMonth() - 1] += node->data.getCountVip() * 5;
				revenue[i][this->scheduleList->findById(node->data.getScheduleId())->getTime().getMonth() - 1] += node->data.getSoda_Corn() * 20;
			}
			node = node->next;
		}
		node = this->head;
	}
	cout << "\t\t\t\t";
	for (int i = 0; i < 100; i++) cout << "-"; cout << endl;
	cout << "\t\t\t\t";
	cout << "|  MaNV/Thang  |  01  |  02  |  03  |  04  |  05  |  06  |  07  |  08  |  09  |  10  |  11  |  12  |\n";
	cout << "\t\t\t\t";
	for (int i = 0; i < 100; i++) cout << "-"; cout << endl;
	for (int i = 0; i < this->staffManager->getLength(); i++) {
		cout << "\t\t\t\t";
		cout << "|    " << left << setw(10) << (this->staffManager->operator[](i).getId()) << "|";
		for (int j = 0; j < 12; j++) {
			cout << " " << left << setw(5) << revenue[i][j] << "|";
		}
		cout << endl;
	}
	cout << "\t\t\t\t";
	for (int i = 0; i < 100; i++) cout << "-"; cout << endl;
}
void TicketManager::readFile(fstream& filein) {
	int len;
	filein >> len;
	for (int i = 0; i < len; i++) {
		Ticket ticket;
		string* ids = ticket.readDataFile(filein);
		this->add(ticket);
		int amount = 0;
		while (*(ids + amount) != "")
		{
			amount++;
		}
		Ticket* tic = this->findById(ticket.getId());
		if (tic == nullptr) return;
		for (int i = 0; i < amount; i++) {
			if (strcmp((ids + i)->c_str(), "E") > 0) {
				tic->addSeat(*(ids + i), true);
			}
			else {
				tic->addSeat(*(ids + i), false);
			}
			int cnt = ((*(ids + i))[0] - 65) * this->scheduleList->findById(tic->getScheduleId())->getRow() + ((*(ids + i))[1] - 48) * 10 + ((*(ids + i))[2] - 48) - 1;
			(this->scheduleList->findById(tic->getScheduleId())->getSeatStatus() + cnt)->setChecked(1);
		}
	}
}
void TicketManager::writeFile(fstream& fileout) {
	Node* node = this->head;
	fileout << length << "\n";
	for (int i = 0; i < length; i++) {
		node->data.writeDataFile(fileout);
		node = node->next;
	}
}
void TicketManager::write() {
	HANDLE cl = GetStdHandle(STD_OUTPUT_HANDLE);
	Node* node = this->head;
	cout << "\t\t\t";
	SetConsoleTextAttribute(cl, 0xF0 | 0x70);
	cout << "                |                |                 |                  |                              |         |          ";
	SetConsoleTextAttribute(cl, 0); cout << "|\n\t\t\t";
	SetConsoleTextAttribute(cl, 0xF0 | 0x70);
	cout << "   Ma hoa don   |  Ma nhan vien  |  Ma lich chieu  |  SDT khach hang  |        Ten khach hang        |  So ve  | Bap nuoc ";
	SetConsoleTextAttribute(cl, 0); cout << "|\n\t\t\t";
	SetConsoleTextAttribute(cl, 0xF0 | 0x70);
	cout << "                |                |                 |                  |                              |         |          ";
	SetConsoleTextAttribute(cl, 0); cout << "|\n";
	SetConsoleTextAttribute(cl, 7);
	for (int i = 0; i < length; i++) {
		cout << "\t\t\t";
		node->data.writeData();
		node = node->next;
	}
	cout << "\t\t\t";
	for (int x = 0; x < 122; x++) cout << "-"; cout << endl;
}