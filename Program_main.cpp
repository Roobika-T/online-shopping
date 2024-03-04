#include <bits/stdc++.h>
using namespace std;
class Inventory
{
	string name;
	int price,count;
	public:
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
void admin()
{
	cout<<"Welcome ADMIN\n";
	ifstream fp;
	fp.open("ADMIN.txt");
	string line;
	map <string,int> mp;
	while(getline(fp,line))
	{
		//cout<<line<<endl;
		stringstream sss{line};
		string prod;
		int pri,cou;
		sss>>prod>>pri>>cou;
		mp[prod]=mp[prod]+cou;
	}
	auto max=mp.begin();
	string MAX_Sell=max->first;
	int MAX=max->second;
	cout<<MAX<<"\n";
	for(auto it:mp)
	{
		if(it.second>MAX)
		{
			MAX=it.second;
			MAX_Sell=it.first;
		}
	}
	fp.close();
	cout<<"The max Sell stock is "<<MAX_Sell<<" no.of stocks sold is "<<MAX<<endl;
	ifstream fp1;
	fp1.open("Monthly_report.txt");
	string Line;
	int SP=0,CP=0,COU;
	getline(fp1,Line);
	while(getline(fp1,Line))
	{
		stringstream sk{Line};
		string prod;
		int cp,sp;
		sk>>prod>>sp>>cp;
		for(auto it:mp)
		{
			if(it.first==prod)
			{
				COU=it.second;
			}
		}
		SP=SP+COU*sp;
		CP=CP+COU*cp;
	}
	fp1.close();
	cout<<"Total Selling Price:-"<<SP<<endl;
	cout<<"Total Cost Price/Manufacturing Price:-"<<CP<<endl;
}
void Billing(string Buy_file,vector <Inventory> V)
{
	ifstream fp{Buy_file};
	ifstream FP;
	vector <Inventory> V1;
	FP.open("ADMIN.txt");
	if(FP)
	{
		string LINE;
		while(getline(FP,LINE))
		{
			stringstream sss{LINE};
			string pro;
			int pri,no;
			sss>>pro>>pri>>no;
			V1.emplace_back(pro,pri,no);
		}
	}
	FP.close();
	string line;
	int Tot=0;
	cout<<"Bill is\n";
	cout<<"Product"<<setw(10)<<"Price"<<setw(20)<<"No.of items"<<setw(30)<<"Total Price"<<endl;
	while(getline(fp,line))
	{
		stringstream ss{line};
		string pro;
		int pri,no;
		ss>>pro>>pri>>no;
		cout<<pro<<setw(10)<<pri<<setw(20)<<no<<setw(30)<<(no*pri)<<endl;
		Tot=Tot+(pri*no);
		V1.emplace_back(pro,pri,no);
	}
	cout<<"____________________________________________________________________________________________"
		<<"\nTotal Price to be paid ="<<Tot<<"\n";
	cout<<"____________________________________________________________________________________________"<<endl;
	fp.close();
	char *bf=&Buy_file[0];
	remove(bf);
	ofstream fp1{"Inventory.txt"};
	fp1<<"Product"<<setw(15)<<"Price"<<setw(15)<<"Count"<<endl;
	for(auto it:V)
	{
		fp1<<it.get_name()<<setw(15)<<it.get_price()<<setw(15)<<it.get_count()<<endl;
	}
	ofstream FP1{"ADMIN.txt"};
	for(auto it:V1)
	{
		FP1<<it.get_name()<<setw(15)<<it.get_price()<<setw(15)<<it.get_count()<<endl;
	}
	FP1.close();
	fp1.close();
	
}
int main()
{
	Start:
	vector <Inventory> V;
	cout<<"Please Login"<<endl;
	map<string,string> mp={{"ABC","XYZ"},{"DEF","XYZ123"},{"GHI","123XYZ"}};//Login Details
	string nme,pwd;
	cout<<"Enter the name:-";
	fflush(stdin);
	getline(cin,nme);
	fflush(stdin);
	cout<<"Enter the password:-";
	fflush(stdin);
	getline(cin,pwd);
	fflush(stdin);
	bool flag=0;
	if(nme=="Admin" && pwd=="Admin@123")//Login details for Admin is Name:-Admin and password:-Admin@123
	{
		admin();
		return 0;
	}
	for(auto it:mp)
	{
		if(it.first==nme && it.second==pwd)
		{
//			cout<<"Customer authenicated";
			flag=1;
		}
	}
	if(flag==0)
	{
		cout<<"Invalid customer\n";
		return(0);
	}
	cout<<"Press 1 -----> Cart\n"
		<<"Press 2 -----> Shopping\n";
	string file_name=nme+pwd+".txt";
	string Buy_file;
	bool flag1=0;
	int k;
	cin>>k;
	switch(k)
	{
		case 1:
			{
				ifstream fp;
				fp.open(file_name);
				if(!fp)
				{
					cout<<"To items in cart!";
					return 0;
				}
				string line1;
				cout<<"Product"<<setw(10)<<"Price"<<setw(20)<<"No.of items"<<setw(30)<<"Total Price"<<endl;
				while(getline(fp,line1))
				{
					stringstream ss1{line1};
					string pro;
					int pri,item;
					ss1>>pro>>pri>>item;
					cout<<pro<<setw(10)<<pri<<setw(20)<<item<<setw(30)<<(pri*item)<<endl;
				}
				break;
			}
		case 2:
			{
				ifstream fp;
				fp.open("Inventory.txt");
				string line;
				getline(fp,line);
//				cout<<line;
				cout<<"Product available \n";
				cout<<"Product"<<setw(10)<<"Price"<<endl;
				while(getline(fp,line))
				{
					stringstream ss{line};
					string name;
					int price,count;
					ss>>name>>price>>count;
					cout<<name<<setw(10)<<price<<endl;
					V.emplace_back(name,price,count);
				}
				fp.close();
				string name;
				int no;
				int k1=1;
				while(k1!=2 && k1!=3)
				{
					cout<<"Enter the product name:- ";
					cin>>name;
					cout<<"Enter the no.of items:-";
					cin>>no;
					bool flag=0;
					int index=-1;
					for(int i=0;i<V.size();i++)
					{
						if(V[i].get_name()==name)
						{
							flag=1;
							index=i;
						}
					}
					if(flag==0)
					{
						cout<<"Product not found\n";
					}
					else if(flag==1)
					{
						cout<<"Press 1 -----> to add to cart\n"
							<<"Press 2 -----> Place Order\n";
						int k2;
						cin>>k2;
						if(k2==1)
						{
							ofstream fp;
							fp.open(file_name,ios::app);
							fp<<V[index].get_name()<<setw(10)<<V[index].get_price()<<setw(10)<<no<<"\n";
							fp.close();
						}
						else if(k2==2)
						{
							V[index].modify_items(no);
							V[index].print();
							Buy_file=nme+pwd+"Buy.txt";
							ofstream fp;
							fp.open(Buy_file,ios::app);
							fp<<V[index].get_name()<<setw(10)<<V[index].get_price()<<setw(10)<<no<<"\n";
							fp.close();
							flag1=1;
						}
					}
					cout<<"Press 1 -----> Add more items\n"
						<<"Press 2 -----> To get Bill\n"
						<<"Press 3 -----> Exit\n";
					cin>>k1;
				}
				break;
			}
		default:
			cout<<"Wrong Choice";
	}
	if(flag1==1)
	{
		Billing(Buy_file,V);
		goto Start;
	}
}
