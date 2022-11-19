#ifndef CHAIR_H
#define CHAIR_H
#include <iostream>

using namespace std;

class Seat
{
public:
    Seat();
    Seat(string, bool);
    string getId() const;
    void setId(const string&);
    bool getVip() const;
    void setVip(const bool&);
    bool getChecked() const;
    void setChecked(const bool&);
private:
    string id;
    bool vip;
    bool checked;
};

#endif
