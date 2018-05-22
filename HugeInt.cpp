#include <iomanip>
#include <sstream>
#include"HugeInt.h"
using namespace std;

ostream & operator << (ostream &out,const HugeInt& n){
	if(n.num[0]!=0){
		out << n.num[0];
	}
	for(int i=1;i<30;i++){
		if(n.num[i]!=11){
			out << n.num[i];
		}
	}
	return out;
}
istream &operator >> (istream & in,HugeInt & n){
	n.num[0]=0;
	for(int i=1;i<30;i++){
		n.num[i]=11;
	}
	for(int i=1;i<30;i++){
		in >> setw(1) >> n.num[i];
	}
	n.count=0;
	for(int i=1;i<30;i++){
		if(n.num[i]!=11){n.count++;}
	}
	return in;
}

HugeInt:: HugeInt(string z){
	string str;
	count = z.size();
	num[0]=0;
	for(int i=1;i<=count;i++){
		str=z[i];
		istringstream buffer(str);
		buffer >> num[i];
	}
	for(int j=count+1;j<30;j++){
		num[j]=11;
	}
}
HugeInt:: HugeInt(int y){
	num[0]=0;
	for(int i=1;i<30;i++){
		 num[i]=11;
	}
	for(int i=0;i<30;i++){
		if((y/(10^i))=0){
			count = i;
			break;
		}
	}
	for(int i=1;i<30;i++){
		  num[count+1-i]=y%(10^i)/(10^(i-1));
	}
}

HugeInt:: HugeInt(){}
HugeInt:: ~HugeInt(){}

HugeInt HugeInt:: operator +(const HugeInt& n2){
	HugeInt n1;
	n1.num[0]=0;
	for(int i=1;i<30;i++){
		n1.num[i]=11;
	}
	if(this->count > n2.count){
		n1.count = this->count;
		for(int i=1;i<=this->count-n2.count;i++){
			n1.num[i] = this->num[i];
		}
		for(int i=this->count-n2.count+1;i<=this->count;i++){
			n1.num[i] = this->num[i] + n2.num[i-this->count+n2.count];
		}
	}else if(this->count < n2.count){
		n1.count = n2.count;
		for(int i=1;i<=n2.count-this->count;i++){
			n1.num[i] = n2.num[i];
		}
		for(int i=n2.count-this->count+1;i<=n2.count;i++){
			n1.num[i] = n2.num[i] + this->num[i-n2.count+this->count];
		}
	}else{
		n1.count = this->count;
		for(int i=1;i<=this->count;i++){
			n1.num[i] = this->num[i] + n2.num[i];
		}
	}
	for(int i=n1.count;i>0;i--){
		n1.num[i-1] += n1.num[i]/10;
		n1.num[i] %= 10;
	}

	//n1.num[i] = this->num[i] + n2.num[i];
	return n1;
}

HugeInt HugeInt:: operator -(const HugeInt& n2){
	HugeInt n1;
	n1.num[0]=0;
	for(int i=1;i<30;i++){
		ni.num[i]=11;
	}
	if(this->count > n2.count){
		
	}else if(this->count < n2.count){
				 
	}else{

	}
	//n1.num[i] = this->num[i] - n2.num[i];

	return n1;
}

