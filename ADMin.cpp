#include <bits/stdc++.h>
using namespace std;
class Inventory
{
	string name;
	int price;
	public:
		int count;
		Inventory(string nme,int pri,int cou)
		{
			name=nme;
			price=pri;
			count=cou;
		}
		void modify_items(int no)
		{
			count=count-no;
		}
		void modify(int n)
		{
			count=count+n;
			cout<<"Count="<<count;
		}
		void print()
		{
			cout<<name<<setw(10)<<price<<setw(10)<<count<<"\n";
		}
		string get_name()
		{
			return name;
		}
		int get_price()
		{
			return price;
		}
		int get_count()
		{
			return count;
		}
};
int main()
{
	ifstream fp;
	fp.open("ADMIN.txt");
	string line;
	map <string,int> mp;
	while(getline(fp,line))
	{
		cout<<line<<endl;
		stringstream sss{line};
		string prod;
		int pri,cou;
		sss>>prod>>pri>>cou;
		bool flag=0;
		mp[prod]=mp[prod]+cou;
	}
	for(auto it:mp)
	{
		cout<<it.first<<"\t"<<it.second<<"\n";
	}
	fp.close();
}
