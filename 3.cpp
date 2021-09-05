#include<iostream>
#define PI 3.1415926535
using namespace std;

class Figure {
public:
	Figure() {
	}
	virtual int area() = 0;

};

class Parallelogram: virtual public Figure {
protected:
	int a;
	int b;
	int d1;
	int d2;
public:
	Parallelogram() {
	}
};

class Circle: virtual public Figure {
int r;
public:
	Circle() {
		r = 12;
	}
	int area() {
		return PI*r*r;
	}
		
};

class Rectangle: public Parallelogram {
public:
	Rectangle() {
	}
	int area() {
		return a*b;
	}

};

class Square: public Parallelogram {
public:
	Square() {
		a = 6;
	}
	int area() {
		return a*a;
	}
};

class Rhombus: public Parallelogram {
public:
	Rhombus() {
	}
	int area() {
		return d1*d2/2;
	}
};

class Car {
protected:
	string company;
	string model;
public:
	Car(string c, string m) {
		cout << c << " " << m << "\n";
	}
};

class PassengerCar: virtual public Car {
public:
	PassengerCar(string c, string m): Car(c, m) {
	}

};

class Bus: virtual public Car {
public:
	Bus(string c, string m): Car(c, m) {

	}

};

class Minivan: public PassengerCar, public Bus {
public:
	Minivan(string c, string m): Car(c,m), PassengerCar(c,m), Bus(c,m) {
	}

};

class Fraction {
	int p;
	unsigned int q;
public:
	Fraction (int p, unsigned int q) {
		this->p = p;
		this->q = q;
	}
	void print() {
		cout << p << "/" << q << " ";
	}
	Fraction operator+(const Fraction &C) {
		p = p * C.q + C.p * q;
		q = q * C.q;
		return Fraction(p, q);
	}
	Fraction operator-(const Fraction &C) {
	        p = p * C.q - C.p * q;
                q = q * C.q;
                return Fraction(p, q);
        }
	Fraction operator*(const Fraction &C) {
                p = p * C.p;
                q = q * C.q;
                return Fraction(p, q);
        }
	Fraction operator/(const Fraction &C) {
                p = p * C.q;
                q = q * C.p;
                return Fraction(p, q);
        }
	Fraction operator-() {
                return Fraction(-p, q);
        }
	bool operator==(const Fraction &C) {
		if(p * C.q == q * C.p)
			return 1;
		return 0;
	}
	bool operator!=(const Fraction &C) {
                if(p * C.q == q * C.p)
                        return 0;
                return 1;
        }
	bool operator>(const Fraction &C) {
                if(p * C.q > q * C.p)
                        return 1;
                return 0;
        }
	bool operator<=(const Fraction &C) {
                if(Fraction(p, q) > Fraction(C.p, C.q))
                        return 0;
                return 1;
        }
	bool operator<(const Fraction &C) {
                if(p * C.q < q * C.p)
                        return 1;
                return 0;
        }
	bool operator>=(const Fraction &C) {
		if(Fraction(p, q) < Fraction(C.p, C.q))
                        return 0;
                return 1;
        }

};

class Card {
	enum Suit {hearts, spades, clubs, diamonds};
	enum Rank {Ace = 1, Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King};
	bool IsFaceUp;
public:
	void Flip() {
		IsFaceUp = !IsFaceUp;
	}
	int GetValue() {
		Rank r;
		return r;
	}
};

int main() {
	Square *s = new Square();
	cout << s->area() << "\n";
	delete s;

	Car car("Audi", "Q3");
	PassengerCar passengercar("Skoda", "Oktavia");
	Bus bus("Volvo", "9500");
	Minivan minivan("Nissan", "Serena");

	Fraction a(2, 5);
	Fraction b(3, 4);
	a = a + b;
	a.print();
	a = a - b;
	a.print();
	a = a * b;
	a.print();
	a = a / b;
	a.print();
	a = -a;
	a.print();
	printf("%d ", a == b);
	printf("%d ", a != b);
	printf("%d ", a > b);
	printf("%d ", a <= b);
	printf("%d ", a < b);
	printf("%d ", a >= b);

	return 0;
}
