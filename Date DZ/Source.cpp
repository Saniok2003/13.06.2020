#include "Date.h"

int main()
{
	Date d1(30, 6, 2020);
	d1.AddOneDay();
	d1.Print();
	Date d2(1, 1, 2020);
	// d2--;
	--d2;
	d2.Print();
	Date d3(30, 12, 2020);
	// d3++;
	++d3;
	d3.Print();
	Date d4(30, 12, 2021);
	Date d5(30, 12, 2020);
	cout << operator>(d4, d5) << endl;
	cout << operator<(d4, d5) << endl;
	cout << operator==(d4, d5) << endl;
	cout << operator!=(d4, d5) << endl;
	Date d6(1, 1, 2020);
	d6.operator+=(30);
	d6.Print();
	d6.operator-=(1);
	d6.Print();
	ofstream out("file.txt");
	Date d7(14, 4, 2007);
	out << d7;
	out.close();
	ifstream in("file.txt");
	Date d8;
	in >> d8;
	d8.Print();
	Date d9(5,3,2012);
	d9.operator()(3);
	d9.Print();
	Date d10(29, 3, 2016);
	d10.operator()(2, 10);
	d10.Print();
	Date d11(29, 2, 2004);
	d11.operator()(2, 12, 4);
	d11.Print();

	system("pause");
	return 0;
}