#include <iostream>
using namespace std;

template <typename T>
T div (T a, T b) {
	if (b == 0.0)
		throw "DivisionByZero";
	return a/b;	
}

class Ex {
public:
	double x;
	Ex (double x) {
		this->x  = x;
	}
};

class Bar {
        double y;
public:
        Bar () {
                y = 0;
        }
	void set (double a) {
		if (a + y > 100) 
			throw Ex (a*y);
		else y = a;
	}
};

class Robot {
public:
	int i;
	int j;
	Robot () {
		i = 0;
		j = 0;
	}
	void move (char d) {
		if (d == 'r') j++;
		else if (d == 'l') j--;
		else if (d == 'u') i--;
		else if (d == 'd') i++;
		else throw "IllegalCommand";
		if (i < 0 || i > 9 || j > 9 || j < 0) throw "OffThrField";
	}
};

int main () {
	int a = 6;
	int b = 2;
	try {		
		cout << div<int>(a, b) << endl;
	}
	catch (const char* ex) {
		cerr << "Error: " << ex << endl;
	}

	Bar bar;
	try {
		int n;
		do {
			cin >> n;
			bar.set(n);
		}
		while (n != 0);
	}
	catch (Ex e) {
		cerr << "Error: " << e.x << endl;
	}

	Robot r;
	try {
		r.move('r');
        	r.move('o');
	}
	catch (const char* exs) {
		cerr << "Error: " << exs << ", your position: (" << r.i << ", " <<r.j << ")";
	}
	return 0;
}



