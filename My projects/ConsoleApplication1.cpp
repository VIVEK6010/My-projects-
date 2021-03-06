//Header files included

#include <iostream.h>
#include <conio.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <fstream.h>
#include <process.h>
#include <time.h>	//to generate random no.s in diff. time intervals 
#include <iomanip.h>

class info		 //class info Declared
{
	char name[34];
	int  id;
	char Bank_name[45];
	int  contact_no;
	int  m_deposit;
	int  ac_no;
	int  pin;
public:
	info() {   }			//constructor
	~info() {   }			//destructor 
	void put_ac(int &m);	//member function to declare account no.
	void getdata();			//member function to get data 
	void getid();			//member function to get id 
	void putdata();			//member function to put data 
	int  get_id();			//member function to get account no.
	void getmoney(int n);	//member function to get money
	void putmoney(int n);	//member function to add money
	void getnewdata();		//member function to get new name 
	int  info::get_pin();
}emp;	//object declared 

fstream f1, f2;	//streams declared

				//Function prototype declared
void intro();	//to introduce programmer
void open();	//to open streams streams	
void close();	//to close streams streams
void edit();	//to edit files 
int  menu();	//to have menu to user
void assign(int n);
void new_ac();	//to add new account
void del_ac();	//to add delete 
void money();	//to have money related issues  
void mod_ac();	//to modify accout 
void view();	//to display all members 
void print();	//to have tabular view 
void print2();
void search();


//Main fuction
void main()
{
	intro(); // to intro programmer
	int k = 0;
	while (k != 8)
	{
		emp.getid();
		system("cls");
		k = menu();
		k = getche();
	}
}
//Main fuction ends

void open()		   //to open streams
{
	f1.open("info ", ios::in | ios::binary | ios::app);
	f2.open("info2", ios::in | ios::binary | ios::app);
}
void close()  //to close streams 
{
	f1.close();
	f2.close();
}
void edit()
{
	remove("info");
	rename("info2", "info");
}
void new_ac()		 //to create new Account 
{
	system("cls");
	print2();
	int persons, n;
	f1.open("info", ios::out | ios::binary | ios::app);
	emp.getdata();

	f1.write((char*)&emp, sizeof(emp));
	cout << "\n\n\n\t\tAccount Created .... " << endl;
	getch();
	emp.put_ac(n);
	cout << endl << "\t\tYour Account No.  is = " << n << endl << endl;

	f1.close(); //to close streams streams
}
void intro()	//to introduce programmer
{
	system("cls");
	cout << endl << endl << endl << setw(28) << " Hello ! This is Mayank " << endl
		<< setw(20) << " From " << endl << setw(20) << " XII - C " << endl << endl << endl << endl;
	cout << endl << endl << endl;
	getch();

	cout << "# NOTE: " << endl;
	cout << "* USERS ARE EXPECTED TO ";
	getch();
}
void del_ac()	//to delete account 
{
	system("cls");
	print2();
	int n;
	char ch = 'y';
	cout << "Enter your Id no.  ";
	cin >> n;
	open(); //to open streams streams
	system("cls");
	while (!f1.eof() && f1.read((char*)&emp, sizeof(emp)))
	{
		if (n == emp.get_id())
		{
			print();
			emp.putdata();
			cout << endl << endl;
			cout << "\n\nAre you Sure(y/n) ";
			ch = getche();

			if (ch == 'n' || ch == 'N')
			{
				f2.write((char*)&emp, sizeof(emp));
			}
		}

		else
			f2.write((char*)&emp, sizeof(emp));

	}

	close(); //to close streams streams
	edit();
}
int  menu()			//to display menu
{
	print2();
	int n;
	cout << "\t\t\t1. NEW ACCOUNT " << endl << endl << endl;
	cout << "\t\t\t2. DELETE ACCOUNT" << endl << endl << endl;
	cout << "\t\t\t3. MONEY RELATED ISSUES " << endl << endl << endl;
	cout << "\t\t\t4. MODIFY ACCOUNT " << endl << endl << endl;
	cout << "\t\t\t5. VIEW ALL ACCOUNT HOLDERS " << endl << endl << endl;
	cout << "\t\t\t6. SEARCH " << endl << endl << endl;
	cout << "\t\t\t7. INFO " << endl << endl << endl;
	cout << "\t\t\t8. EXIT " << endl << endl << endl;
	cout << "Your choice :: ";
	cin >> n;
	assign(n);		//to assign values to functions 
	return n;
}
void assign(int n)
{
	if (n == 1)
	{
		new_ac();
	}
	else if (n == 2)
	{
		del_ac();
	}
	else if (n == 3)
	{
		money();
	}
	else if (n == 4)
	{
		mod_ac();
	}
	else if (n == 5)
	{
		view();
	}
	else if (n == 6)
	{
		search();
	}
	else if (n == 7)
	{
		intro();
	}
	else
		exit(0);

}
void money()		 //to add money
{
	int n, k, id, cash;
	system("cls");
	print2();
	cout << "\t\t\t1.Add " << endl << endl
		<< "\t\t\t2.Withdraw" << endl << endl;		cin >> n;

	system("cls");
	print2();

	cout << "Enter your Id ";		cin >> id;
	if (n == 1)
	{
		open();
		while (!f1.eof() && f1.read((char*)&emp, sizeof(emp)))
		{
			if (emp.get_id() == id)
			{
				cout << "How much ?? ";
				cin >> cash;
				emp.putmoney(cash);
			}
			f2.write((char*)&emp, sizeof(emp));
		}
		close();
		edit();
		cout << "\n\n\t\t\t\t Modification Done !! ";
	}

	else if (n == 2)
	{
		open();
		while (!f1.eof() && f1.read((char*)&emp, sizeof(emp)))
		{
			if (emp.get_id() == id)
			{
				cout << "How much ?? ";
				cin >> cash;
				emp.getmoney(cash);
			}
			f2.write((char*)&emp, sizeof(emp));

		}
		close();
		edit();
		cout << "\n\n\t\t\t\t Modification Done !! ";
	}

}
void mod_ac()	  //to modify name
{
	system("cls");
	print2();
	int n, k = 1;
	cout << "Enter your Id no. ";	cin >> n;
	open(); //to open streams streams
	system("cls");
	while (!f1.eof() && f1.read((char*)&emp, sizeof(emp)))
	{
		if (n == emp.get_id())
		{
			print();
			emp.putdata();
			cout << endl << endl;
			emp.getnewdata();
			f2.write((char*)&emp, sizeof(emp));
		}
		else
			f2.write((char*)&emp, sizeof(emp));
	}

	cout << endl << endl << "\t\t\t\t Modification Done !! ";
	close(); //to close streams streams
	edit();
}
void print()
{
	print2();
	cout << "   _________________________________________________________________________________________" << endl;
	cout << setw(10) << "ID" << setw(14) << "Name" << setw(18) << "Bank name" << setw(22) << "Contact No." << setw(20) << "Cash" << endl;
	cout << "   _________________________________________________________________________________________" << endl;
}
void view()			//to display all data 
{
	system("cls");
	open(); //to open streams streams
	print();
	while (!f1.eof() && f1.read((char*)&emp, sizeof(emp)))
	{
		emp.putdata();
	}
	close(); //to close streams streams
}
void print2()
{
	cout << "\t\t\t\t" << " ______________________________________________ " << endl
		<< "\t\t\t\t" << "|           WELCOME TO THE BANK                |" << endl
		<< "\t\t\t\t" << "|______________________________________________|" << endl << endl << endl << endl;
}
void search()
{
	open();
	system("cls");
	print2();
	int n, m;
	cout << "Enter id no. ";
	cin >> n;

	while (!f1.eof() && f1.read((char*)&emp, sizeof(emp)))
	{
		if (emp.get_id() == n)
		{
			cout << "Enter your Pin ";
			cin >> m;

			if (emp.get_pin() == m)
			{
				system("cls");
				print2();
				print();
				emp.putdata();
			}
		}
	}
	close();
}

//CLASS FUNCTIONS
void info::getdata()
{
	cout << "Name = ";				cin >> name;
	cout << "Bank = ";				cin >> Bank_name;
	cout << "Contact no. = ";		cin >> contact_no;
	cout << "Money Deposited = ";	cin >> m_deposit;
	cout << "Pin = ";				cin >> pin;
}
void info::putdata()
{
	cout << setw(10) << id << setw(14) << name << setw(16) << Bank_name << setw(20) << contact_no << setw(24) << m_deposit << endl;
}
void info::getid()
{
	open();
	id = 1;
	while (!f1.eof() && f1.read((char*)&emp, sizeof(emp)))
	{
		id++;
	}
	close();
}
void info::put_ac(int &m)
{
	int maxrand = 10000;
	srand((unsigned)time(NULL));
	m = rand() % maxrand;
	ac_no = m;
}
int  info::get_id()
{
	return id;
}
void info::getmoney(int n)
{
	m_deposit -= n;
}
void info::putmoney(int n)
{
	m_deposit += n;
}
void info::getnewdata()
{
	cout << "Enter new name ";
	cin >> name;
}
int  info::get_pin()
{
	return pin;
}