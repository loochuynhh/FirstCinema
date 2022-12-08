#include "CinemaRoomManager.h"
#include <Windows.h>

void checkCnmrId(const string& id) {
	if(id.size() != 2) throw Error(7);
	for (int i = 0; i < id.length(); i++) {
		if (id[i] > '9' || id[i] < '0') {
			throw Error(1);
		}
	}
}

void CinemaRoomManager::showType() {
	cout << "\n\t\t\t\t\t\t\t1: 2D";
	cout << "\n\t\t\t\t\t\t\t2: 3D";
	cout << "\n\t\t\t\t\t\t\t3: IMAX\n";
}

CinemaRoom CinemaRoomManager::setCinemaRoomInfor() {
	CinemaRoom cinemaRoom;
	string templ = "cnmr";
	string id;
	string idin;
	int check = 0;
	do {
		do {
			cout << "\n\t\t\t\t\t\t\tNhap id(vi du: cnmr01, cnmr02,...): ";
			try {
				cout << templ;
				getline(cin, idin);
				checkCnmrId(idin);
				break;
			} catch(Error error) {
				error.getMessage();
			}
		} while(true);	
		id = templ + idin;		
		if(this->findById(id) != nullptr) {
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
	} while(check == 1 || check == 0);
	if (check == 2) {
		cinemaRoom.setId("null");
		return cinemaRoom;
	}
	check = 0;
	string status;
	do {
		cout << "\t\t\t\t\t\t\tNhap tinh trang phong chieu(great, good, normal, bad): ";
		getline(cin, status);
		if(status != "bad" && status != "normal" && status != "good" && status != "great") {
			do {
				cout << "\t\t\t\t\t\t\t\tTinh trang khong hop le!. Lua chon";
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
	} while(check == 1 || check == 0);
	if (check == 2) {
		cinemaRoom.setId("null");
		return cinemaRoom;
	}
	int row, column, type;
	cout << "\t\t\t\t\t\t\tNhap so hang ghe: ";
	row = getInt();
	cout << "\t\t\t\t\t\t\tNhap so cot ghe: ";
	column = getInt();
	check = 0;
	do {
		cout << "\t\t\t\t\t\t\tNhap dinh dang phong chieu: ";
		this->showType();
		cout << "\t\t\t\t\t\t\t";
		type = getInt();
		if(type < 1 || type > 3) {
		do {
			cout << "\t\t\t\t\t\t\t\tDinh dang khong hop le!. Lua chon";
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
	} while(check == 1 || check == 0);
	if (check == 2) {
		cinemaRoom.setId("null");
		return cinemaRoom;
	}	
	cinemaRoom.setId(id);
	cinemaRoom.setStatus(status);
	cinemaRoom.setColumn(column);
	cinemaRoom.setRow(row);
	cinemaRoom.setType(type);
	return cinemaRoom;
}

void CinemaRoomManager::update(const string& id) {
	HANDLE cl = GetStdHandle(STD_OUTPUT_HANDLE);
	int opttmp = 0;
	CinemaRoom* room = findById(id);
	do {
		system("cls");
		cout << "\n\t\t\t\t\t\t";
		SetConsoleTextAttribute(cl, 0xF0 | 0x70);
		cout << "                  |               |              |              |              ";
		SetConsoleTextAttribute(cl, 0); cout << "|\n\t\t\t\t\t\t";
		SetConsoleTextAttribute(cl, 0xF0 | 0x70);
		cout << "  Ma phong chieu  |  So hang ghe  |  So cot ghe  |  Chat luong  |  Tinh trang  ";
		SetConsoleTextAttribute(cl, 0); cout << "|\n\t\t\t\t\t\t";
		SetConsoleTextAttribute(cl, 0xF0 | 0x70);
		cout << "                  |               |              |              |              ";
		SetConsoleTextAttribute(cl, 0); cout << "|\n\t\t\t\t\t\t";
		SetConsoleTextAttribute(cl, 7);
		room->writeData();
		cout << "\t\t\t\t\t\t";
		for (int x = 0; x < 78; x++) cout << "-"; cout << endl;
		cout << "\n\t\t\t\t\t\t\t1. Sua so hang ghe" << endl;
		cout << "\t\t\t\t\t\t\t2. Sua so cot ghe" << endl;
		cout << "\t\t\t\t\t\t\t3. Sua tinh trang" << endl;
		cout << "\t\t\t\t\t\t\t4. Sua dinh dang" << endl;
		cout << "\t\t\t\t\t\t\t0. Xac nhan va thoat" << endl;
		cout << "\t\t\t\t\t\t\t>> Nhap lua chon: ";
		opttmp = getInt();
		string up;
		int upn;
		switch (opttmp) {
		case(1): {
			cout << "\t\t\t\t\t\t\tNhap so hang ghe: ";
			upn = getInt();
			room->setColumn(upn);
			break;
		}
		case(2): {
			cout << "\t\t\t\t\t\t\tNhap so cot ghe: ";
			upn = getInt();
			room->setRow(upn);
			break;
		}
		case(3): {
			int check = 0;
			do {
				cout << "\t\t\t\t\t\t\tNhap tinh trang phong chieu(great, good, normal, bad): ";
				getline(cin, up);
				if(up != "bad" && up != "normal" && up != "good" && up != "great") {
					do {
						cout << "\t\t\t\t\t\t\t\tTinh trang khong hop le!. Lua chon";
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
			} while(check == 1 || check == 0);
			if(up == "bad") {
				SetConsoleTextAttribute(cl, 4);
				cout << "\n\t\t\t\t\t\tLUU Y:    SAU KHI XAC NHAN THAY DOI PHONG CHIEU CAP NHAT TINH TRANG KHONG TOT SE DUOC XOA TRONG LICH CHIEU\n";
				SetConsoleTextAttribute(cl, 7);
				cout << "\n\t\t\t\t\t\t\t\tBan co chac chan muon cap nhat.";
				cout << "\n\t\t\t\t\t\t\t1. Cap nhat.";
				cout << "\t\t\t0. Thoat.";
				cout << "\n\t\t\t\t\t\t\t";
				int idel; idel = getInt();
				if(idel == 1){
					room->setStatus(up);
				}
				else if (idel == 0) {}
				else {
					cout << "\t\t\t\t\t\t\tLua chon khong hop le!\n";
					system("pause");
				}
			}	
			else if(check != 2) room->setStatus(up);			
			break;
		}
		case(4): {
			int check = 0;
			do {
				cout << "\t\t\t\t\t\t\tNhap dinh dang phong chieu: ";
				this->showType();
				cout << "\t\t\t\t\t\t\t";
				upn = getInt();
				if(upn < 1 || upn > 3) {
				do {
					cout << "\t\t\t\t\t\t\t\tDinh dang khong hop le!. Lua chon";
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
			} while(check == 1 || check == 0);
			if(check != 2) room->setType(upn);
			break;
		}
		case(0): {
			break;
		}
		default:
			cout << "\t\t\t\t\t\t\tLua chon khong hop le! Moi chon lai.\n";
			system("pause");	
		}
	} while (opttmp != 0);
}
void CinemaRoomManager::readFile(fstream& filein) {
	int len;
	filein >> len;
	for (int i = 0; i < len; i++) {
		CinemaRoom cnmr;
		cnmr.readDataFile(filein);
		this->add(cnmr);
	}
}
void CinemaRoomManager::writeFile(fstream& fileout) {
	Node* node = this->head;
	fileout << length << "\n";
	for (int i = 0; i < length; i++) {
		node->data.writeDataFile(fileout);
		node = node->next;
	}
}
void CinemaRoomManager::write() {
	HANDLE cl = GetStdHandle(STD_OUTPUT_HANDLE);
	Node* node = this->head;
	cout << "\t\t\t\t\t\t";
	SetConsoleTextAttribute(cl, 0xF0 | 0x70);
	cout << "                  |               |              |              |              ";
	SetConsoleTextAttribute(cl, 0 ); cout << "|\n\t\t\t\t\t\t";
	SetConsoleTextAttribute(cl, 0xF0 | 0x70);
	cout << "  Ma phong chieu  |  So hang ghe  |  So cot ghe  |  Chat luong  |  Tinh trang  ";
	SetConsoleTextAttribute(cl, 0 ); cout << "|\n\t\t\t\t\t\t";
	SetConsoleTextAttribute(cl, 0xF0 | 0x70);
	cout << "                  |               |              |              |              ";
	SetConsoleTextAttribute(cl, 0 ); cout << "|\n";
	SetConsoleTextAttribute(cl, 7);
	for (int i = 0; i < length; i++) {
		cout << "\t\t\t\t\t\t";
		node->data.writeData();
		node = node->next;
	}
	cout << "\t\t\t\t\t\t";
	for (int x = 0; x < 79; x++) cout << "-"; cout << endl;
}