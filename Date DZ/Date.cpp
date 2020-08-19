#include "Date.h"

Date::Date(int day, int month, int year)
	{
		this->day = day;
		if (day > 30)
		{
			this->day = day - 30;
			this->month = month + 1;
		}
		this->year = year;
		if (month > 12)
		{
			this->month = month - 12;
			this->year = year + 1;
		}
		if (day <= 30 && month <= 12)
		{
			this->day = day;
			this->month = month;
			this->year = year;
		}
	}
	void Date::Print() const
	{
		cout << "Date: " << day << '.' << month << '.' << year << endl;
	}
	void Date::AddOneDay()
	{
		this->day = this->day + 1;
		if (this->day > 30)
		{
			this->day = this->day - 30;
			this->month = month + 1;
			this->year = year;
			if (month > 12)
			{
				this->month = month - 12;
				this->year = year + 1;
			}
		}
	}
	Date Date::operator++()
	{
		this->day = this->day + 1;
		if (this->day > 30)
		{
			this->day = this->day - 30;
			this->month = month + 1;
			this->year = year;
			if (month > 12)
			{
				this->month = month - 12;
				this->year = year + 1;
			}
		}
		return *this;
	}
	Date Date::operator++(int)
	{
		this->day = this->day + 1;
		if (this->day > 30)
		{
			this->day = this->day - 30;
			this->month = month + 1;
			this->year = year;
			if (month > 12)
			{
				this->month = month - 12;
				this->year = year + 1;
			}
		}
		return *this;
	}
	Date Date::operator--()
	{
		if (this->day == 1)
		{
			this->day = 30;
			this->month = this->month - 1;
			if (this->month == 0)
			{
				this->month = 12;
				this->year = this->year - 1;
			}
		}
		else
		{
			this->day = this->day - 1;
		}
		return *this;
	}
	Date Date::operator--(int)
	{
		if (this->day == 1)
		{
			this->day = 30;
			this->month = this->month - 1;
			if (this->month == 0)
			{
				this->month = 12;
				this->year = this->year - 1;
			}
		}
		else
		{
			this->day = this->day - 1;
		}
		return *this;
	}
	void Date::operator+=(int number)
	{
		this->day = this->day + number;
		if (this->day > 30)
		{
			this->day = this->day - 30;
			this->month = month + 1;
			this->year = year;
			if (month > 12)
			{
				this->month = month - 12;
				this->year = year + 1;
			}
		}
	}
	void Date::operator-=(int number)
	{
		if (this->day == 1)
		{
			this->day = 31;
			this->day = this->day - number;
			this->month = this->month - 1;
			if (this->month == 0)
			{
				this->month = 12;
				this->year = this->year - 1;
			}
		}
		else
		{
			this->day = this->day - 1;
		}
	}

	void Date::operator()(int days)
	{
		this->day = this->day + days;
		if (this->day > 30)
		{
			this->day = this->day - 30;
			this->month = month + 1;
			this->year = year;
			if (month > 12)
			{
				this->month = month - 12;
				this->year = year + 1;
			}
		}
	}
	void Date::operator()(int days, int month)
	{
		this->month = this->month + month;
		if (this->month > 12)
		{
			this->month = 1;
			this->year = this->year + 1;
		}
		this->day = this->day + days;
		if (this->day > 30)
		{
			this->day = this->day - 30;
			this->month = this->month + 1;
		}
	}
	void Date::operator()(int days, int month, int year)
	{

		this->year = this->year + year;
		this->month = this->month + month;
		if (this->month > 12)
		{
			this->month = this->month - month;
			this->year = this->year + 1;
		}
		this->day = this->day + days;
		if (this->day > 30)
		{
			this->day = this->day - 30;
			this->month = this->month + 1;
		}
	}
	ofstream& operator<<(ofstream& ofs, const Date& d)
	{
		ofs << d.day << endl;
		ofs << d.month << endl;
		ofs << d.year << endl;
		return ofs;
	}
	ifstream& operator>>(ifstream& ifs, Date& d)
	{
		ifs >> d.day;
		ifs >> d.month;
		ifs >> d.year;
		return ifs;
	}
	bool operator>(const Date& d1, const Date& d2)
	{
		return ((d1.day + (d1.month * 30) + (d1.year * 365)) > (d2.day + (d2.month * 30) + (d2.year * 365)));
	}
	bool operator<(const Date& d1, const Date& d2)
	{
		return ((d1.day + (d1.month * 30) + (d1.year * 365)) < (d2.day + (d2.month * 30) + (d2.year * 365)));
	}
	bool operator!=(const Date& d1, const Date& d2)
	{
		return((d1.day + (d1.month * 30) + (d1.year * 365)) != (d2.day + (d2.month * 30) + (d2.year * 365))) != 0;
	}
	bool operator==(const Date& d1, const Date& d2)
	{
		return((d1.day + (d1.month * 30) + (d1.year * 365)) == (d2.day + (d2.month * 30) + (d2.year * 365))) != 0;
	}