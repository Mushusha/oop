#include <iostream>
#include <string.h>
using namespace std;

class Person {
	protected:
	string name;
	int age;
	string gen;
	int weight;
	public:
	void setName(string n) {
		name = n;
	}
	void setAge(int a) {
		age = a;
	}
	void setWeight(int w) {
		weight = w;
	}

};

class Student: public Person {
	int year;
	public:
	void setYear(int y) {
		year = y;
	}
	int nextYear() {
		return (year + 1);
	}
	void print () const {
		cout << name << " " << year << "\n";
	}
};

class Fruit {
	protected:
	string name;
	string color;
	public:
	string getName() const {
		return name;
	}
	string getColor() const {
		return color;
	}
};

class Apple: public Fruit {
	public:
	Apple() {
		name = "apple";
	}
	Apple(string a) {
                color = a;
        }


};

class Banana: public Fruit {
	public:
		Banana() {
			name = "banana";
			color = "yellow";
		}
};

class GrannySmith: public Apple {
	public:	
		GrannySmith () {
			name = "Granny Smith apple";
			color = "green";
		}

};


int main() {
	Student Ivan;
	Ivan.setName("Ivan");
	Ivan.setYear(2019);
	Student Kirill;
	Kirill.setName("Kirill");
	Kirill.setYear(2018);
	Ivan.print();
	Kirill.print();

	Apple a("red");
    	Banana b;
    	GrannySmith c;

    	cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
    	cout << "My " << b.getName() << " is " << b.getColor() << ".\n";
    	cout << "My " << c.getName() << " is " << c.getColor() << ".\n";
	return 0;
}
