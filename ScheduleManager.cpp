#include "ScheduleManager.h"
#include <Windows.h>
void checkScdId(const string& id) {
	if (id.size() != 3) throw Error(8);
	for (int i = 0; i < id.length(); i++) {
		if (id[i] > '9' || id[i] < '0') {
			throw Error(1);
		}
	}
}

ScheduleManager::ScheduleManager(FilmManager& filmManager, CinemaRoomManager& room) {
	this->filmManager = &filmManager;
	this->cinemaRoomManager = &room;
}

Schedule ScheduleManager::setScheduleInfor() {
	Node* node = this->head;
	Schedule schedule;
	string id;
	string filmId;
	string cinemaRoomId;
	string templ = "scd";
	int baseCost;
	int show;
	int date;
	int month;
	int year;
	int check = 0;
	string idin;
	do {
		do {
			cout << "\n\t\t\t\t\t\t\tNhap id(vi du: scd001, scd010,...): ";
			try {
				cout << templ;
				getline(cin, idin);
				checkScdId(idin);
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
		schedule.setId("null");
		return schedule;
	}
	check = 0;
	do {
		system("cls");
		cout << "\n";
		this->filmManager->write();
		cout << "\n\t\t\t\t\t\t\tNhap ma phim: ";
		getline(cin, filmId);
		if (this->filmManager->findById(filmId) == nullptr) {
			do {
				cout << "\t\t\t\t\t\t\t\tKhong tim thay phim!. Lua chon";
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
		schedule.setId("null");
		return schedule;
	}
	check = 0;
	do {
		system("cls");
		cout << "\n";
		this->cinemaRoomManager->write();
		cout << "\n\t\t\t\t\t\t\tNhap ma phong chieu: ";
		getline(cin, cinemaRoomId);
		if (this->cinemaRoomManager->findById(cinemaRoomId) == nullptr) {
			do {
				cout << "\t\t\t\t\t\t\t\tKhong tim thay phong chieu!. Lua chon";
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
		else if (this->cinemaRoomManager->findById(cinemaRoomId)->getStatus() == "bad") {
			do {
				cout << "\t\t\t\t\t\t\t\tPhong chieu dang co van de!. Lua chon";
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
		schedule.setId("null");
		return schedule;
	}
	system("cls");
	cout << "\n";
	getShow();
	cout << "\t\t\t\t\t\t\tNhap ca so: ";
	show = getInt();
	while (show < 1 || show > 5)
	{
		cout << "\t\t\t\t\t\t\tSo ca khong hop le!" << endl;
		cout << "\t\t\t\t\t\t\tNhap ca so: ";
		show = getInt();
	}
	do {
		try {
			cout << "\t\t\t\t\t\t\tNhap ngay chieu: ";
			date = getInt();
			cout << "\t\t\t\t\t\t\tNhap thang chieu: ";
			month = getInt();
			cout << "\t\t\t\t\t\t\tNhap nam chieu: ";
			year = getInt();
			checktime(date, month, year);
			break;
		}
		catch (Error error) {
			error.getMessage();
		}
	} while (true);
	Time t(date, month, year);
	for (int i = 0; i < this->length; i++) {
		if (node->data.getFilmId() == filmId && node->data.getCinemaRoomId() == cinemaRoomId && node->data.getShow() == show && node->data.getTime() == t) {
			cout << "\t\t\t\t\t\t\tlich chieu nay da ton tai!" << endl;
			system("pause");
			schedule.setId("null");
			return schedule;
		}
		node = node->next;
	}
	cout << "\t\t\t\t\t\t\tNhap gia ve co ban: ";
	baseCost = getInt();
	schedule.setId(id);
	schedule.setFilmId(filmId);
	schedule.setCinemaRoomId(cinemaRoomId);
	schedule.setShow(show);
	schedule.setTime(t);
	schedule.setBaseCost(baseCost);
	return schedule;
}

int ScheduleManager::getType(const string& id) {
	return this->cinemaRoomManager->findById(this->findById(id)->getCinemaRoomId())->getType();
}

bool ScheduleManager::checkRoomExist(const string& id, const Time& t) {
	Node* node = this->head;
	int i = 0;
	while (i < this->length) {
		if (node->data.getCinemaRoomId() == id && node->data.getTime() >= t) {
			return true;
		}
		node = node->next;
		i++;
	}
	return false;
}

bool ScheduleManager::checkFilmExist(const string& id, const Time& t) {
	Node* node = this->head;
	int i = 0;
	while (i < this->length) {
		if (node->data.getFilmId() == id && node->data.getTime() >= t) {
			return true;
		}
		node = node->next;
		i++;
	}
	return false;
}

void ScheduleManager::getShow() {
	cout << "\t\t\t\t\t\t\t\t";
	cout << "Ca 1: " << "7:00 - 9:00" << endl;
	cout << "\t\t\t\t\t\t\t\t";
	cout << "Ca 2: " << "10:00 - 12:00" << endl;
	cout << "\t\t\t\t\t\t\t\t";
	cout << "Ca 3: " << "13:00 - 16:00" << endl;
	cout << "\t\t\t\t\t\t\t\t";
	cout << "Ca 4: " << "17:00 - 20:00" << endl;
	cout << "\t\t\t\t\t\t\t\t";
	cout << "Ca 5: " << "21:00 - 0:00" << endl;
}

void ScheduleManager::readFile(fstream& filein) {
	int len;
	filein >> len;
	for (int i = 0; i < len; i++) {
		Schedule schedule;
		schedule.readDataFile(filein);
		CinemaRoom* room = this->cinemaRoomManager->findById(schedule.getCinemaRoomId());
		this->add(schedule);
		findById(schedule.getId())->createSeat(room);
	}
}

void ScheduleManager::writeFile(fstream& fileout) {
	Node* node = this->head;
	fileout << length << "\n";
	for (int i = 0; i < length; i++) {
		node->data.writeDataFile(fileout);
		node = node->next;
	}
}
void ScheduleManager::write() {
	HANDLE cl = GetStdHandle(STD_OUTPUT_HANDLE);
	Node* node = this->head;
	cout << "\n\t\t\t\t\t\t";
	SetConsoleTextAttribute(cl, 0xF0 | 0x70);
	cout << "                  |             |                  |      |            |                     ";
	SetConsoleTextAttribute(cl, 0); cout << "|\n\t\t\t\t\t\t";
	SetConsoleTextAttribute(cl, 0xF0 | 0x70);
	cout << "   Ma lich chieu  |   Ma phim   |  Ma phong chieu  |  Ca  | Gia co ban |     Ngay chieu      ";
	SetConsoleTextAttribute(cl, 0); cout << "|\n\t\t\t\t\t\t";
	SetConsoleTextAttribute(cl, 0xF0 | 0x70);
	cout << "                  |             |                  |      |            |                     ";
	SetConsoleTextAttribute(cl, 0); cout << "|\n";
	SetConsoleTextAttribute(cl, 7);
	for (int i = 0; i < length; i++) {
		cout << "\t\t\t\t\t\t";
		node->data.writeData();
		node = node->next;
	}
	cout << "\t\t\t\t\t\t";
	for (int x = 0; x < 93; x++) cout << "-"; cout << endl;
}