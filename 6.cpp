#include <iostream>
#include <iomanip>
using namespace std;

ostream &endll (ostream &stream) {
	cout << "\n\n";
	return stream;
}

int main() {
	int a;
	cin >> a;
	while (cin.fail() == 1) {
		cerr << "Error\n";
		cin.clear();
		cin.sync();
		cin >> a;		
	}
	cout << endll << a;
	return 0;
}
