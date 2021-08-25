#include<iostream>
#include <cstdint>

class Power {
	int base;
	int pow;
	public:
	void set (int b, int p) {
		base = b;
		pow = p;
	}
	int calculate () {
		int k = 1;
		for (int i = 0; i < pow; i++)
		k = k*base;
		return k;
	}
};

class RGBA {
	std::uint8_t m_red = 0;
	std::uint8_t m_green = 0;
	std::uint8_t m_blue = 0;
	std::uint8_t m_alpha = 255;
	public:
	RGBA(uint8_t r, uint8_t g, uint8_t b, uint8_t a) {
	m_red = r;
	m_green = g;
	m_blue = b;
	m_alpha = a;
	}
	void print() {
		printf("%d %d %d %d\n", m_red, m_green, m_blue, m_alpha); 
	}

};

class Stack {
	int a[10];
	int len;
	public:
	void reset() {
		len = 0;
		for (int i = 0; i < 10; i++)
			a[i] = 0;
	}
	bool push(int n) {
		for (int i = 0; i < 10; i++)
			if (a[i] == 0) {
				a[i] = n;
				return 1;
				break;
				}
		return 0;

	}
	void pop() {
		if (a[0] != 0) {
			for (int i = 0; i < 10; i++) 
                        	if (a[i] == 0) {
                                	a[i - 1] = 0;
                                        break;
                                }
		}
		else printf ("stack empty\n");
		

	}

	void print() {
		printf("( ");
		int i = 0;
		while (a[i] != 0)
			printf("%d ", a[i++]);
		printf(")\n");
	}
};



int main() {
	Power one;
	one.set (2, 6);
	printf("%d\n", one.calculate());
	RGBA two (2, 4, 6, 8);
	two.print();
	Stack stack;
    	stack.reset();
    	stack.print();

    	stack.push(3);
    	stack.push(7);
    	stack.push(5);
    	stack.print();

    	stack.pop();
    	stack.print();

    	stack.pop();
    	stack.pop();
    	stack.print();

	return 0;
}
