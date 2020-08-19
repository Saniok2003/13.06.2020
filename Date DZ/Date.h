#pragma once
#include <iostream>
#include <fstream>
using namespace std;
class Date
{
private:
	int day;    // maximum 30
	int month; // maximum 12
	int year;
	friend bool operator>(const Date& d1, const Date& d2);
	friend bool operator<(const Date& d1, const Date& d2);
	friend bool operator!=(const Date& d1, const Date& d2);
	friend bool operator==(const Date& d1, const Date& d2);
	friend ofstream& operator<<(ofstream& of, const Date& point);
	friend ifstream& operator>>(ifstream& ifs, Date& point);
public:
	Date() : day(0), month(0), year(0) {      }
	Date(int day, int month, int year);
	void Print() const;
	void AddOneDay();
	Date operator++();
	Date operator++(int);
	Date operator--();
	Date operator--(int);
	void operator+=(int number);
	void operator-=(int number);
	void operator()(int days);
	void operator()(int days, int month);
	void operator()(int days, int month, int year);

};
ofstream& operator<<(ofstream& ofs, const Date& d);
ifstream& operator>>(ifstream& ifs, Date& d);
bool operator>(const Date& d1, const Date& d2);
bool operator<(const Date& d1, const Date& d2);
bool operator!=(const Date& d1, const Date& d2);
bool operator==(const Date& d1, const Date& d2);