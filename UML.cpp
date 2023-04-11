#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class pizza
{
private:
	string variety;
	int size;

public:

	pizza()
	{
		variety = "";
		size = 0;
	}
	pizza(string v, int o)
	{
		variety = v;
		size = o;
	}

	string getVar()
	{
		return variety;
	}

	int getSize()
	{
		return size;
	}
};

class pizzaBoom
{
private:
	int* quantitySold;
	pizza* menu;
	int size;

public:
	pizzaBoom(int x)
	{
		quantitySold = new int[x];
		menu = new pizza[x];
		size = x;
		string z;
		int v;

		for (int i = 0;i < size;i++)
		{
			cout << "Enter variety and size " << i + 1 << endl;
			cin >> z >> v;
			menu[i] = pizza(z, v);
		}

	}

	void sellPizza(string n, int s, int nSold)
	{
	
		for (int i = 0;i < size;i++)
		{
			if ((n == menu[i].getVar())&&(s==menu[i].getSize()))
				quantitySold[i] += nSold;
		}
	}
	
	void logSales(string fileName)
	{
		ofstream file{ fileName };
		file.open(fileName);
		if (file.fail())
			cout << "error";
		else
		{
			string m = "Pizza type 			size			Quantity";
			string f;
			string space = "			";
			file << m;
			for (int i = 0;i < size;i++)
			{
				f = menu[i].getVar() + space + to_string(menu[i].getSize()) + space + to_string(quantitySold[i]);
				file << f;
			}

			file.close();
		}

	}

	void displaySalesFromFile(string fileName)
	{
		string line;
		ifstream read(fileName);
		read.open(fileName);

		while (getline(read, line))
		{
			cout << line << endl;
		}
		read.close();
	}

	void storeInObjectFile(string fileName)
	{
		ofstream file(fileName);
		file.open(fileName);
		for (int i = 0;i < size;i++)
		{
			file.write((char*)&menu[i], sizeof(menu[i]));
		}
		file.close();


	}

	void displayMenuBySizeFromFile(string fileName, int minS)
	{
		ifstream file;
		file.open(fileName, ios::in);
		pizza p;
		file.read((char*)&p, sizeof(p));
		while (!file.eof()) {
			{
				if (p.getSize() > minS)
				{
					cout << p.getVar() << " " << p.getSize() << endl;

				}
				file.read((char*)&p, sizeof(p));
			}
			file.close();


		}
	}
};


