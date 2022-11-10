#include "Error.h"

Error::Error(int code) {
    this->errorCode = code;
}

Error::Error() {
    this->errorCode = 0;
}

void Error::getMessage() {
    switch(this->errorCode) {
        case 1: {
            cout << "\t\t\t\t\t\t\tVui long chi nhap so! Moi nhap lai." << endl;
            break;
        }
        case 2: {
            cout << "\t\t\t\t\t\t\tSo dien thoai gom 10 hoac 11 so! Moi nhap lai.\n";
            break;
		}
        case 3: {
            cout << "\t\t\t\t\t\t\tNgay thang khong phu hop!. Moi nhap lai.\n";
            break;
        }
        case 4: {
            cout << "\t\t\t\t\t\t\tThang khong hop le! Moi nhap lai.\n";
            break;
        }
        case 5: {
            cout << "\t\t\t\t\t\t\tNgay khong duoc am! Moi nhap lai.\n";
            break;
        }
        case 6: {
            cout << "\t\t\t\t\t\t\tNam khong hop le! Moi nhap lai.\n";
            break;
        }
        case 7: {
            cout << "\t\t\t\t\t\t\tChi nhap 2 chu so! Moi nhap lai.\n";
            break;
        }
        case 8: {
            cout << "\t\t\t\t\t\t\tChi nhap 3 chu so! Moi nhap lai.\n";
            break;
        }
        case 9: {
            cout << "\t\t\t\t\t\t\tChi nhap 4 chu so! Moi nhap lai.\n";
            break;
        }
        default:
            cout << "\t\t\t\t\t\t\tLoi nhap." << endl;
    }
}