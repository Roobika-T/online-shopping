#include <bits/stdc++.h>
using namespace std;
int main()
{
	string A="Inventory.txt";
	ofstream fp;
	fp.open(A,ios::app);
//	printf("123456789012345678901234567890123456789012345678901234567890\n");
//	cout<<left<<"File Opened"<<setw(30)<<setfill('*')<<"Successfull";
	fp<<"Product"<<setw(15)<<"Price"<<setw(15)<<"Count\n";
	fp<<"ABCDE"<<setw(15)<<1000<<setw(15)<<100
	  <<endl<<"FGHIJ"<<setw(15)<<2000<<setw(15)<<200
	  <<endl<<"KLMNO"<<setw(15)<<3000<<setw(15)<<300;
	fp.close();
}
