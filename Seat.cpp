#include "Seat.h"

Seat::Seat() {
    this->checked = false;
}

Seat::Seat(string id, bool vip) {
    Seat();
    this->id = id;
    this->vip = vip;
}

string Seat::getId() const{
    return this->id;
}

void Seat::setId(const string& id) {
    this->id = id;
}

bool Seat::getVip() const{
    return this->vip;
}

void Seat::setVip(const bool& vip) {
    this->vip = vip;
}

bool Seat::getChecked() const {
    return this->checked;
}

void Seat::setChecked(const bool& checked) {
    this->checked = checked;
}

