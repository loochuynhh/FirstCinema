#include "StaffManager.h"
#include <Windows.h>
void checkStId(const string& id) {
	if(id.size() != 3) throw Error(8);
	for (int i = 0; i < id.length(); i++) {
		if (id[i] > '9' || id[i] < '0') {
			throw Error(1);
		}
	}
}

void StaffManager::readFile(fstream& filein) {
	int len;
	filein >> len;
	for (int i = 0; i < len; i++) {
	 	Staff staff;
	 	staff.readDataFile(filein);
	 	this->add(staff);
	}
}
void StaffManager::writeFile(fstream& fileout) {
	Node* node = this->head;
	fileout << length << "\n";
	for (int i = 0; i < length; i++) {
		node->data.writeDataFile(fileout);
		node = node->next;
	}
}
void StaffManager::write() {
	HANDLE cl = GetStdHandle(STD_OUTPUT_HANDLE);
	Node* node = this->head;
	cout << "\n\t";
	SetConsoleTextAttribute(cl, 0xF0 | 0x70);
	cout << "              |                           |      |              |                       |                 |            |               |                                 ";	
	SetConsoleTextAttribute(cl, 0); cout << "|\n\t";
	SetConsoleTextAttribute(cl, 0xF0 | 0x70);
	cout << " Ma nhan vien |       Ten nhan vien       | Tuoi |  Cong viec   |       Tai khoan       |     Mat khau    |  Ngay lam  | So dien thoai |       Email                     ";	
	SetConsoleTextAttribute(cl, 0); cout << "|\n\t";
	SetConsoleTextAttribute(cl, 0xF0 | 0x70);
	cout << "              |                           |      |              |                       |                 |            |               |                                 ";
	SetConsoleTextAttribute(cl, 0); cout << "|\n";
	SetConsoleTextAttribute(cl, 7);
	for (int i = 0; i < length; i++) {
		cout << "\t";
		node->data.writeData();
		node = node->next;
	}
	cout << "\t";
	for (int i = 0; i < 169; i++) cout << "-"; cout << endl;
}
void StaffManager::writerl() {
	HANDLE cl = GetStdHandle(STD_OUTPUT_HANDLE);
	Node* node = this->head;
	cout << "\n\t\t\t";
	SetConsoleTextAttribute(cl, 0xF0 | 0x70);
	cout << "              |                           |                           |         |               |                                ";
	SetConsoleTextAttribute(cl, 0); cout << "|\n\t\t\t";
	SetConsoleTextAttribute(cl, 0xF0 | 0x70);
	cout << " Ma nhan vien |       Ten nhan vien       |    Ten nhan than          | Tuoi NT | SDT nhan than |      Email nhan than           ";
	SetConsoleTextAttribute(cl, 0); cout << "|\n\t\t\t";
	SetConsoleTextAttribute(cl, 0xF0 | 0x70);
	cout << "              |                           |                           |         |               |                                ";
	SetConsoleTextAttribute(cl, 0); cout << "|\n";
	SetConsoleTextAttribute(cl, 7);
	for (int i = 0; i < length; i++) {
		cout << "\t\t\t";
		node->data.writeDatarl();
		node = node->next;
	}
	cout << "\t\t\t";
	for (int i = 0; i < 129; i++) cout << "-"; cout << endl;
}
Staff StaffManager::setStaff() {
	cout << "\n\t\t\t\t\t\t\t**Nhap day du thong tin nhan vien**";
	Staff staff;
	string id, name, job, account, password, phone, mail, phonerl, mailrl, namerl;
	int age, agerl, date, month, year;
	Infor infor;
	Inforrl inforrl;
	string idin;
	string templ = "st";
	int check = 0;
	do {
		do {
			cout << "\n\t\t\t\t\t\t\tNhap ID nhan vien(vi du: st001, st020): ";
			try {
				cout << templ;
				getline(cin, idin);
				checkStId(idin);
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
		staff.setId("null");
		return staff;
	}
	check = 0;
	cout << "\t\t\t\t\t\t\tNhap ten nhan vien: ";
	getline(cin, name);
	cout << "\t\t\t\t\t\t\tNhap cong viec: ";
	getline(cin, job);
	cout << "\t\t\t\t\t\t\tNhap tai khoan nhan vien: ";
	getline(cin, account);
	cout << "\t\t\t\t\t\t\tNhap mat khau nhan vien: ";
	getline(cin, password);
	do {
		try {
			cout << "\t\t\t\t\t\t\tNhap so dien thoai nhan vien: ";
			phone = getphone();
			break;
		}
		catch (Error error) {
			error.getMessage();
		}
	} while (true);
	infor.setPhone(phone);
	cout << "\t\t\t\t\t\t\tNhap mail nhan vien: ";
	getline(cin, mail);
	infor.setMail(mail);
	cout << "\t\t\t\t\t\t\tNhap tuoi nhan vien: ";
	age = getInt();
	infor.setAge(age);
	do {
		try {
			cout << "\t\t\t\t\t\t\tNhap ngay nhan vien bat dau lam: ";
			date = getInt();
			cout << "\t\t\t\t\t\t\tNhap thang nhan vien bat dau lam: ";
			month = getInt();
			cout << "\t\t\t\t\t\t\tNhap nam nhan vien bat dau lam: ";
			year = getInt();
			checktime(date, month, year);
			break;
		}
		catch (Error error) {
			error.getMessage();
		}
	} while (true);
	Time t(date, month, year);
	staff.setTimeSt(t);
	cout << "\t\t\t\t\t\t\tNhap ten nhan than: ";
	getline(cin, namerl);
	inforrl.setNamerl(namerl);
	do {
		try {
			cout << "\t\t\t\t\t\t\tNhap so dien thoai nhan than: ";
			phonerl = getphone();
			break;
		}
		catch (Error error) {
			error.getMessage();
		}
	} while (true);
	inforrl.setPhone(phonerl);
	cout << "\t\t\t\t\t\t\tNhap mail nhan than: ";
	getline(cin, mailrl);
	inforrl.setMail(mailrl);
	cout << "\t\t\t\t\t\t\tNhap tuoi nhan than: ";
	agerl = getInt();
	inforrl.setAge(agerl);
	staff.setInforSt(infor);
	staff.setRelative(inforrl);
	staff.setId(id); staff.setName(name); staff.setAccount(account); staff.setJob(job); staff.setPassword(password);
	return staff;
}
void StaffManager::update(){
	string id;
	cout << "\t\t\t\t\t\t\tNhap id: ";
	getline(cin, id);
	if (findById(id) == nullptr) {
		cout << "\t\t\t\t\t\t\tKhong tim thay id phu hop!\n";
		system("pause");
	}
	else {
		int opttmp = 0;
		Staff* staff = findById(id);
		do {
			cout << "\t\t\t\t\t\t\t1. Sua ten nhan vien" << endl;
			cout << "\t\t\t\t\t\t\t2. Sua cong viec" << endl;
			cout << "\t\t\t\t\t\t\t3. Sua tai khoan" << endl;
			cout << "\t\t\t\t\t\t\t4. Sua mat khau" << endl;
			cout << "\t\t\t\t\t\t\t5. Sua thoi gian bat dau lam" << endl;
			cout << "\t\t\t\t\t\t\t6. Sua tuoi nhan vien" << endl;
			cout << "\t\t\t\t\t\t\t7. Sua so dien thoai" << endl;
			cout << "\t\t\t\t\t\t\t8. Sua mail nhan vien" << endl;
			cout << "\t\t\t\t\t\t\t9. Sua ten nhan than" << endl;
			cout << "\t\t\t\t\t\t\t10. Sua tuoi nhan than" << endl;
			cout << "\t\t\t\t\t\t\t11. Sua so dien thoai nhan than" << endl;
			cout << "\t\t\t\t\t\t\t12. Sua mail nhan than" << endl;
			cout << "\t\t\t\t\t\t\t0. Xac nhan va thoat" << endl;
			cout << "\t\t\t\t\t\t\t\t>> Nhap lua chon: ";
			opttmp = getInt();
			string up;
			int upn;
			Infor infor = staff->getInforSt();
			Inforrl inforrl = staff->getRelative();
			switch (opttmp) {
			case(1): {
				cout << "\t\t\t\t\t\t\tNhap ten nhan vien: ";
				getline(cin, up);
				staff->setName(up);
				break;
			}
			case(2): {
				cout << "\t\t\t\t\t\t\tNhap cong viec: ";
				getline(cin, up);
				staff->setJob(up);
				break;
			}
			case(3): {
				cout << "\t\t\t\t\t\t\tNhap tai khoan: ";
				getline(cin, up);
				staff->setAccount(up);
				break;
			}
			case(4): {
				cout << "\t\t\t\t\t\t\tNhap mat khau: ";
				getline(cin, up);
				staff->setPassword(up);
				break;
			}
			case(5): {
				int date, month, year;
				do {
					try {
						cout << "\t\t\t\t\t\t\tNhap ngay bat dau lam: ";
						date = getInt();
						cout << "\t\t\t\t\t\t\tNhap thang bat dau lam: ";
						month = getInt();
						cout << "\t\t\t\t\t\t\tNhap nam bat dau lam: ";
						year = getInt();
						checktime(date, month, year);
						break;
					}
					catch (Error error) {
						error.getMessage();
					}
				} while (true);
				Time time(date, month, year);
				staff->setTimeSt(time);
				break;
			}
			case(6): {
				cout << "\t\t\t\t\t\t\tNhap tuoi nhan vien: ";
				upn = getInt();
				infor.setAge(upn); 
				staff->setInforSt(infor);
				break;
			}
			case(7): {
				do {
					try {
						cout << "\t\t\t\t\t\t\tNhap so dien thoai nhan vien: ";
						up = getphone();
						break;
					}
					catch (Error error) {
						error.getMessage();
					}
				} while (true);
				infor.setPhone(up); 
				staff->setInforSt(infor);
				break;
			}
			case(8): {
				cout << "\t\t\t\t\t\t\tNhap mail nhan vien: ";
				getline(cin, up);
				infor.setMail(up);
				staff->setInforSt(infor);
				break;
			}
			case(9): {
				cout << "\t\t\t\t\t\t\tNhap ten nhan than: ";
				getline(cin, up);
				inforrl.setNamerl(up);
				staff->setRelative(inforrl);
				break;
			}
			case(10): {
				cout << "\t\t\t\t\t\t\tNhap tuoi nhan than: ";
				upn = getInt();
				inforrl.setAge(upn);
				staff->setRelative(inforrl);
				break;
			}
			case(11): {
				do {
					try {
						cout << "\t\t\t\t\t\t\tNhap so dien thoai nhan than: ";
						up = getphone();
						break;
					}
					catch (Error error) {
						error.getMessage();
					}
				} while (true);
				inforrl.setPhone(up);
				staff->setRelative(inforrl);
				break;
			}
			case(12): {
				cout << "\t\t\t\t\t\t\tNhap mail nhan than: ";
				getline(cin, up);
				inforrl.setMail(up);
				staff->setRelative(inforrl);
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
}

void StaffManager::readSalaryFile(fstream& filein) {
	Node* node = this->head;
	for (int i = 0; i < this->length; i++) {
		int slength;
		filein >> slength;
		node->data.setSlength(slength);
		Salary* salary = new Salary[slength];
		for (int j = 0; j < slength; j++) {
			(salary + j)->readFile(filein);
		}
		node->data.setStSalary(salary);
		node = node->next;
	}
}

void StaffManager::writeSalaryFile(fstream& fileout) {
	Node* node = this->head;
	for (int i = 0; i < this->length; i++) {
		fileout << node->data.getSlength() << endl;
		for (int j = 0; j < node->data.getSlength(); j++) {
			(node->data.getStSalary() + j)->writeFile(fileout);
		}
		node = node->next;
	}
}
void StaffManager::writeSalaryY(int year) {
	HANDLE cl = GetStdHandle(STD_OUTPUT_HANDLE);
	Node* node = this->head;
	int salaryTable[20][12][2];
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 12; j++) {
			for (int k = 0; k < 2; k++) salaryTable[i][j][k] = 0;
		}
	}
	for (int i = 0; i < this->length; i++) {
		for (int j = 0; j < node->data.getSlength(); j++) {
			if ((node->data.getStSalary() + j)->getTimeslr().getYear() == year) {
				salaryTable[i][(node->data.getStSalary() + j)->getTimeslr().getMonth() - 1][0] = (node->data.getStSalary() + j)->getSalaryBase();
				salaryTable[i][(node->data.getStSalary() + j)->getTimeslr().getMonth() - 1][1] = (node->data.getStSalary() + j)->getBonus();
			}
		}
		node = node->next;
	}
	node = this->head;
	SetConsoleTextAttribute(cl, 0xF0 | 0x70);
	cout << "\n\t";
	cout << "             |              |          |          |          |          |          |          |          |          |          |          |          |           ";
	SetConsoleTextAttribute(cl, 0); cout << "|\n\t";
	SetConsoleTextAttribute(cl, 0xF0 | 0x70);
	cout << "  MaNV/Thang |  Loai Luong  |    01    |    02    |    03    |    04    |    05    |    06    |    07    |    08    |    09    |    10    |    11    |    12     ";
	SetConsoleTextAttribute(cl, 0); cout << "|\n\t";
	SetConsoleTextAttribute(cl, 0xF0 | 0x70);
	cout << "             |              |          |          |          |          |          |          |          |          |          |          |          |           ";
	SetConsoleTextAttribute(cl, 0); cout << "|\n";
	SetConsoleTextAttribute(cl, 7);
	for (int i = 0; i < length; i++) {
		for (int cnt = 0; cnt < 3; cnt++) {
			if (cnt == 1) {
				cout << "\t";
				cout << "|   " << left << setw(9) << node->data.getId();
				cout << "|    Thuong    |";
				for (int j = 0; j < 12; j++) {
					cout << " " << left << setw(9) << salaryTable[i][j][1] << "|";
				}
			}
			else if (cnt == 0) {
				cout << "\t";
				cout << "|            |    Co ban    |";
				for (int j = 0; j < 12; j++) {
					cout << " " << left << setw(9) << salaryTable[i][j][0] << "|";
				}
			}
			else {
				cout << "\t";
				cout << "|            |  Tong cong   |";
				for (int j = 0; j < 12; j++) {
					cout << " " << left << setw(9) << salaryTable[i][j][0] + salaryTable[i][j][1] << "|";
				}
			}
			cout << endl;
		}
		cout << "\t";
		for (int i = 0; i < 161; i++) cout << "-"; cout << endl;
		node = node->next;
	}
}
void StaffManager::addSalary() {
	Node* node = this->head;
	string id;
	Salary tmp;
	int check = 1;
	do {
		cout << "\n\t\t\t\t\t\t\tNhap ma nhan vien muon them luong: ";
		getline(cin, id);
		if (this->findById(id) != nullptr) {
			Staff* staff = this->findById(id);
			check = 2;
			int date, month, year, salarybase, bonus;
			cout << "\t\t\t\t\t\t\tNhap ngay tra luong: ";
			date = getInt();
			cout << "\t\t\t\t\t\t\tNhap thang tra luong: ";
			month = getInt();
			cout << "\t\t\t\t\t\t\tNhap nam tra luong: ";
			year = getInt();
			Time timeslr(date, month, year);
			tmp.setTimeslr(timeslr);
			cout << "\t\t\t\t\t\t\tNhap luong co ban: ";
			salarybase = getInt();
			tmp.setSalaryBase(salarybase);
			cout << "\t\t\t\t\t\t\tNhap luong thuong them: ";
			bonus = getInt();
			tmp.setBonus(bonus);
			staff->addslr(tmp);
			cout << "\t\t\t\t\t\t\tLuong da duoc them cho nhan vien!.\n";
		}
		else {
			do {
				cout << "\t\t\t\t\t\t\t\tMa nhan vien khong hop le!. Lua chon";
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
	} while (check == 1);
}