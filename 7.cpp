#include <iostream>
#include <memory>
#include <utility>
using namespace std;

class Date {
	int day;
	int month;
	int year;
	public:
	void setDate (int d, int m, int y) {
		day = d;
		month = m;
		year = y;
	}
	int getDay () {
		return day;
	}
	int getMonth () {
		return month;
	}
	int getYear () {
		return year;
	}
	friend ostream& operator<< (ostream&out, const Date &d);
	friend ostream& operator<< (ostream&out, const unique_ptr <Date> d);
};
ostream& operator<< (ostream&out, const unique_ptr <Date> d) {
        out << d->day << "." << d->month << "." << d->year << endl;
        return out;
}

ostream& operator<< (ostream&out, const Date &d) {
	out << d.day << "." << d.month << "." << d.year << endl;
	return out;
}

unique_ptr <Date> Compare (unique_ptr <Date> d1, unique_ptr <Date> d2) {
	if (d1->getYear() != d2->getYear()) 
		if (d1->getYear() > d2->getYear())
			return d1; 
		else
			return d2;
	
	else {
		if (d1->getMonth() != d2->getMonth()) {
			if (d1->getMonth() > d2->getMonth())
				return d1;
			else 
				return d2;
		}
		else {
			if (d1->getDay() != d2->getDay()) {
                        	if (d1->getDay() > d2->getDay())
                                	return d1;
                        	else
                                	return d2;
			}
			else return d1;
                }
	}
}

void Change (unique_ptr <Date> d1, unique_ptr <Date> d2) {
	unique_ptr <Date> d = make_unique <Date> ();
	d = move(d2);
	d2 = move(d1);
	d1 = move(d);
}

int main() {
	unique_ptr <Date> today = make_unique <Date> ();
	unique_ptr <Date> date = make_unique <Date> ();
	today->setDate(16, 9, 2021);	
	cout << today->getDay() << endl;
	cout << today->getMonth() << endl;
	cout << today->getYear() << endl;
	cout << *today;
	date = move(today);
	if (today)
		cout << "today not null\n";
	else
		cout << "today null\n";
	if (date)
                cout << "date not null\n";
        else
                cout << "date null\n";

	unique_ptr <Date> date1 = make_unique <Date> ();
	unique_ptr <Date> date2 = make_unique <Date> ();
	date1->setDate(23, 6, 2019);
	date2->setDate(4, 10, 2019);
	cout << Compare(move(date1), move(date2));
	return 0;
}

