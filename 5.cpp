#include <iostream>
#include <string>
using namespace std;

template<typename T>
class Pair1 {
	T a;
	T b;
public:
	Pair1(T a, T b) {
		this->a = a;
		this->b = b;
	}
	T first() const {
		return a;
	}
	T second() const {
		return b;
	}
};

template<typename T, typename U>
class Pair {
protected:
        T a;
        U b;
public:
        Pair(T a, U b) {
                this->a = a;
                this->b = b;
        }
        T first() const {
                return a;
        }
        U second() const {
                return b;
        }
};
/*template<typename U>
class StringValuePair: public Pair<string, U> {
public:
	StringValuePair(string a, U b): Pair(a, b) {
	}
};*/

int main() {
	Pair1<int> p1(6, 9);
    	cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';

    	const Pair1<double> p2(3.4, 7.8);
    	cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';

	Pair<int, double> p3(6, 7.8);
	cout << "Pair: " << p3.first() << ' ' << p3.second() << '\n';

    	const Pair<double, int> p4(3.4, 5);
    	cout << "Pair: " << p4.first() << ' ' << p4.second() << '\n';

	//StringValuePair<int> svp("Amazing", 7);
    	//cout << "Pair: " << svp.first() << ' ' << svp.second() << '\n';

	return 0;
}
