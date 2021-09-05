#include<iostream>
#include<cassert>
#include<vector>
using namespace std;

class ArrayInt {
private:
	int m_length;
    	int *m_data;

public:
    	ArrayInt(): m_length(0), m_data(nullptr) { 
	}

    	ArrayInt(int length): m_length(length) {
        assert(length >= 0);

        if (length > 0)
            m_data = new int[length];
        else
            m_data = nullptr;
    	}	

    	~ArrayInt() {
        delete[] m_data;
    	}
        int& operator[](int index) {
        assert(index >= 0 && index < m_length);
        return m_data[index];
   	}	

	void pop_back() {
		--m_length;
		int* data = new int[m_length];
		for (int i = 0; i < m_length; i++)
                        data[i] = m_data[i];
		delete [] m_data;
		m_data = data;
		
	}
	void pop_front() {
		--m_length;
		int* data = new int[m_length];
		for (int i = 0; i < m_length; i++)
			data[i] = m_data[i + 1];
		delete [] m_data;
		m_data = data;
	}
	void sort() {
		for (int i = 0; i < m_length; i++)
			for (int j = 0; j < m_length - 1; j++)
				if(m_data[j] > m_data[j + 1]) {
						int t = m_data[j];
						m_data[j] = m_data[j + 1];
						m_data[j + 1] = t;
				}
	}
	void print() {
		for (int i = 0; i < m_length; i++)
			cout << m_data[i] << " ";
		cout << "\n";
	}

};

int main() {
	ArrayInt a(8);
	for(int i = 0; i < 8; i++)
		a[i] = i + 1;
	a[4] = 0;
	a.print();
	a.sort();
	a.print();
	a.pop_back();
	a.print();
	a.pop_front();
	a.print();
	
	int n = 0;
	int k = 0;
	vector<int> b {2, 4, 6, 4, 2, 12, 12};
	for(int i = 0; i < b.size(); i++) {
		for(int j = 0; j < i; j++)
			if(b[i] != b[j]) k++;
		if (k == i) n++;
		k = 0;
	}
	cout << n;

	return 0;
}
