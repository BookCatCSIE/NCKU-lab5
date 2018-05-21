#ifndef HUGEINT_H
#define HUGEINT_H
#include <iostream>
#include <string>
using namespace std;

class HugeInt{
	friend ostream &operator <<(ostream&,const HugeInt&);
	friend istream &operator >>(istream&,HugeInt&);
	
	public:
		HugeInt(string z);
		HugeInt(int y);
		HugeInt();
		~HugeInt();

		HugeInt operator +(const HugeInt &);
		HugeInt operator -(const HugeInt &);

	private:
		int num[30];
		int count;
};
#endif
