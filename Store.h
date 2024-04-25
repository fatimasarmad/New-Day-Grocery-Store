#pragma once
#include<Windows.h>
#include<stdlib.h>
#include<iostream>
#include<fstream>
#include<string>
#include<conio.h>
using namespace std;
#include "Classnames.h"
class prod_food_catal
{
private:
	string name;
	string category;
	string subcategory;
	int quantity;
	int price;
public:
	prod_food_catal()
	{
		name = "";
		category = "";
		subcategory = "";
		quantity = 10;
		price = 100;
	}
	void display()
	{
		cout << "Name: " << name << endl;
		cout << "Category: " << category << endl;
		cout << "Subcategory: " << subcategory << endl;
		cout << "Quantity: " << quantity << endl;
		cout << "Price: " << price << endl;
	}
	prod_food_catal(string n, string c, string s)
	{
		name = n;
		category = c;
		subcategory = s;
	}
	//destructor
	~prod_food_catal()
	{

	}
	//settergetter
	void setquantity(int q)
	{
		quantity = q;
	}
	int getquantity()
	{
		return quantity;
	}
	void setprice(int p)
	{
		price = p;
	}
	int getprice()
	{
		return price;
	}
	void setname(string name)
	{
		this->name = name;
	}
	void setcategory(string category)
	{
		this->category = category;
	}
	void setsubcategory(string sub)
	{
		this->subcategory = sub;
	}
	string getname()
	{
		return name;
	}
	string getcategory()
	{
		return category;
	}
	string getsubcategory()
	{
		return subcategory;
	}
	void operator=(prod_food_catal a)
	{
		name = a.getname();
		category = a.getcategory();
		subcategory = a.getsubcategory();
	}
	/*void setquanity(int a);
	void setprice(int price);*/

};
class User
{
protected:
	string name;
	string password;
	string cnic;
	string gender;
	string type;
	string phone;
	string address;
public:
	bool verify();
	bool Login(string name);
	void Signup();
	void ShowMenu();
	string getname();
};

class productcatalog
{
private:
	prod_food_catal* p;
	int size_f;
	int i = 0;
public:
	productcatalog()
	{

		size_f = 40;
		p = new prod_food_catal[size_f];
	}
	void update_product(int id)
	{
		string name;
		string category;
		string subcategory;
		cout << "Enter the name of the product" << endl;
		cin >> name;
		cout << "Enter the category of the product" << endl;
		cin >> category;
		cout << "Enter the subcategory of the product" << endl;
		cin >> subcategory;
		p[id].setname(name);
		p[id].setcategory(category);
		p[id].setsubcategory(subcategory);
	}
	void addproduct(prod_food_catal a)
	{
		p[i] = a;
		i++;
	}
	void displayproductcatalog()
	{
		for (int i = 0; i < size_f; i++)
		{
			if (p[i].getname() != "")
			{
				cout << "Name: " << p[i].getname() << endl;
				cout << "Category: " << p[i].getcategory() << endl;
				cout << "Subcategory: " << p[i].getsubcategory() << endl;
			}
		}
	}

	void write_catalog_to_file()
	{
		//binary file write for product catalog
		ofstream fout;
		fout.open("productcatalog.txt", ios::binary);
		for (int i = 0; i < size_f; i++)
		{
			fout.write((char*)&p[i], sizeof(p[i]));
		}
		fout.close();
	}
	void set_size_f(int a)
	{
		size_f = a;
	}
	void read_catalog_from_file()
	{

		//binary file read for product catalog
		ifstream fin;
		fin.open("productcatalog.txt", ios::binary);
		prod_food_catal* temp = new prod_food_catal[size_f];
		for (int i = 0; i < size_f; i++)
		{
			fin.read((char*)&temp[i], sizeof(temp[i]));
		}
		/*delete[] p;*/
		p = temp;
		fin.close();
	}
	void deleteproduct(string name)
	{
		if (!searchproduct(name))
		{
			cout << "Product is already not in the catalog!" << endl;
			return;
		}
		read_catalog_from_file();
		prod_food_catal* temp = new prod_food_catal[size_f - 1];
		int j = 0;
		for (int i = 0; i < size_f; i++)
		{
			if (p[i].getname() != name)
			{
				temp[j] = p[i];
				j++;
			}
		}
		size_f--;
		p = NULL;
		p = temp;
		ofstream fout;
		fout.open("productcatalog.txt", ios::binary | ios::trunc);
		for (int i = 0; i < size_f; i++)
		{
			fout.write((char*)&p[i], sizeof(p[i]));
		}
		fout.close();

	}

	void addproduct(string name)
	{
		if (searchproduct(name))
		{
			cout << "Product is already in the catalog ! " << endl;
			return;
		}
		prod_food_catal a;
		a.setname(name);
		string b;
		cout << "Enter category: ";
		cin >> b;
		a.setcategory(b);
		string c;
		cout << "Enter subcategory: ";
		cin >> c;
		size_f++;
		a.setsubcategory(c);
		addproduct(a);
		write_catalog_to_file();
	}

	bool searchproduct(string name)
	{
		//return true if string is present in catalog
		for (int i = 0; i < size_f; i++)
		{
			if (p[i].getname() == name)
			{
				return true;
			}
		}
		return false;
	}
};
void populate_food_catal()
{
	productcatalog P;
	prod_food_catal m1("Chicken", "Food", "Meat");
	P.addproduct(m1);
	prod_food_catal m2("Beef", "Food", "Meat");
	P.addproduct(m2);
	prod_food_catal m3("Mutton", "Food", "Meat");
	P.addproduct(m3);
	prod_food_catal m4("Fish", "Food", "Meat");
	P.addproduct(m4);
	prod_food_catal d1("Milk", "Food", "Dairy");
	P.addproduct(d1);
	prod_food_catal d2("Eggs", "Food", "Dairy");
	P.addproduct(d2);
	prod_food_catal d3("Yogurt", "Food", "Dairy");
	P.addproduct(d3);
	prod_food_catal d4("Cheese", "Food", "Dairy");
	P.addproduct(d4);
	prod_food_catal f1("Apple", "Food", "Fruits");
	P.addproduct(f1);
	prod_food_catal f2("Banana", "Food", "Fruits");
	P.addproduct(f2);
	prod_food_catal f3("Mango", "Food", "Fruits");
	P.addproduct(f3);
	prod_food_catal f4("Orange", "Food", "Fruits");
	P.addproduct(f4);
	prod_food_catal f5("Watermelon", "Food", "Fruits");
	P.addproduct(f5);
	prod_food_catal v1("Tomato", "Food", "Vegetables");
	P.addproduct(v1);
	prod_food_catal v2("Potato", "Food", "Vegetables");
	P.addproduct(v2);
	prod_food_catal v3("Onion", "Food", "Vegetables");
	P.addproduct(v3);
	prod_food_catal v4("Cucumber", "Food", "Vegetables");
	P.addproduct(v4);
	prod_food_catal s1("Chocolates", "Food", "Snacks");
	P.addproduct(s1);
	prod_food_catal s2("Biscuits", "Food", "Snacks");
	P.addproduct(s2);
	prod_food_catal s3("Chips", "Food", "Snacks");
	P.addproduct(s3);
	prod_food_catal sp1("Spices", "Food", "Spices");
	P.addproduct(sp1);
	prod_food_catal g1("Lentils", "Food", "Grains");
	P.addproduct(g1);
	prod_food_catal g2("Wheat", "Food", "Grains");
	P.addproduct(g2);
	prod_food_catal g3("Flour", "Food", "Grains");
	P.addproduct(g3);
	prod_food_catal g4("Rice", "Food", "Grains");
	P.addproduct(g4);
	prod_food_catal ce("Cereal", "Food", "Cereal");
	P.addproduct(ce);
	prod_food_catal p1("Shampoo", "Personal_Hygiene", "Personal");
	P.addproduct(p1);
	prod_food_catal p2("Soap", "Personal_Hygiene", "Personal");
	P.addproduct(p2);
	prod_food_catal p3("Santizer", "Personal_Hygiene", "Personal");
	P.addproduct(p3);
	prod_food_catal p4("Detergent", "Household", "Cleaning");
	P.addproduct(p4);
	prod_food_catal p5("Dish_soap", "Household", "Cleaning");
	P.addproduct(p5);
	prod_food_catal p6("Washroom_cleaner", "Household", "Cleaning");
	P.addproduct(p6);
	P.displayproductcatalog();
	P.write_catalog_to_file();
}
class Inventory
{
private:
	int size_f;
	prod_food_catal* p;
	int size;
	int i = 0;
public:
	Inventory()
	{
		size_f = 40;
		p = new prod_food_catal[size_f];
		i = 0;
	}

	void update_product(int id)
	{
		string name;
		int quantity;
		int price;
		cout << "Enter the name of the product" << endl;
		cin >> name;
		cout << "Enter the quanitity of the product" << endl;
		cin >> quantity;
		cout << "Enter the subcategory of the product" << endl;
		cin >> price;
		p[id].setname(name);
		p[id].setquantity(quantity);
		p[id].setprice(price);
	}
	void addproduct(prod_food_catal a)
	{
		p[i] = a;
		i++;
	}
	void displayproductcatalog()
	{
		for (int i = 0; i < size_f; i++)
		{
			if (p[i].getname() != "")
			{
				cout << "Name: " << p[i].getname() << endl;

				cout << "Quantity: " << p[i].getquantity() << endl;

				cout << "Price: " << p[i].getprice() << endl;
			}
		}
	}

	void write_inventory_to_file()
	{
		//binary file write for product catalog
		ofstream fout;
		fout.open("inventory.txt", ios::binary);
		for (int i = 0; i < size_f; i++)
		{
			fout.write((char*)&p[i], sizeof(p[i]));
		}
		fout.close();
	}
	void set_size_f(int a)
	{
		size_f = a;
	}
	void read_catalog_from_file()
	{

		//binary file read for product catalog
		ifstream fin;
		fin.open("inventory.txt", ios::binary);
		prod_food_catal* temp = new prod_food_catal[size_f];
		for (int i = 0; i < size_f; i++)
		{
			fin.read((char*)&temp[i], sizeof(temp[i]));
		}
		/*delete[] p;*/
		p = temp;
		fin.close();
	}

	bool searchproduct(string name)
	{
		//return true if string is present in catalog
		for (int i = 0; i < size_f; i++)
		{
			if (p[i].getname() == name)
			{
				p[i].display();
				return true;
			}
		}
		return false;
	}
};

class prod_food_inven
{
private:
	string name;
	string category;
	string subcategory;
	int quantity;
	int price;
public:
	prod_food_inven()
	{
		name = "";
		category = "";
		subcategory = "";
		quantity = 0;
		price = 0;
	}
	prod_food_inven(string n, string c, string s, int q, int p)
	{
		name = n;
		category = c;
		subcategory = s;
		quantity = q;
		price = p;
	}
	//destructor
	~prod_food_inven()
	{

	}
	//settergetter
	void setname(string name)
	{
		this->name = name;
	}
	void setcategory(string category)
	{
		this->category = category;
	}
	void setsubcategory(string sub)
	{
		this->subcategory = sub;
	}
	string getname()
	{
		return name;
	}
	string getcategory()
	{
		return category;
	}
	string getsubcategory()
	{
		return subcategory;
	}
	void operator=(prod_food_catal a)
	{
		name = a.getname();
		category = a.getcategory();
		subcategory = a.getsubcategory();
	}
	/*void setquanity(int a);
	void setprice(int price);*/

};

class Manager : public User
{
private:
	Inventory I;
public:
	Manager()
	{
		name = "Fatima";
		password = "Fatima123";
	}
	Manager(string name, string password)
	{
		this->name = name;
		this->password = password;
	}
	void populate_managers()
	{
		/*Admin A;
		Manager m1("Fatima", "Fatima123");
		Manager m2("Ayesha", "Ayesha123");
		Manager m3("Hira", "Hira123");
		Manager m4("Sadia", "Sadia123");
		Manager m5("Sana", "Sana123");
		Manager m6("Sara", "Sara123");
		Manager m7("Sadia", "Sadia123");
		
		A.add_manager(m1);
		A.add_manager(m2);
		A.add_manager(m3);
		A.add_manager(m4);
		A.add_manager(m5);
		A.add_manager(m6);
		A.add_manager(m7);
		
		A.writeallmanagerstofile();
		Admin B;
		B.readallmanagersfromfile();
		B.Display();*/
	}

	void readfromfile()
	{
		ifstream fin;
		fin.open("Manager.txt");
		if (fin.is_open())
		{
			fin >> name;
			fin >> password;
		}
		else
		{
			cout << "File not found" << endl;
		}
		fin.close();
	}

	void Display()
	{
		cout << "Name: " << name << endl;
		cout << "Password: " << password << endl;
	}
	void writetofile()
	{
		ofstream fout;
		fout.open("Manager.txt", ios::app);
		fout << name << endl;
		fout << password << endl;
		fout.close();
	}
	void showmenu()
	{
		int choice=0;

		{
			cout << "1. Inventory" << endl;
			cout<<"2. Update Inventory"<<endl;
			cout << "6. Exit" << endl;
			cin >> choice;
		}
	}
};
class Admin :public User
{
	Manager* M; //islamabad
	productcatalog P;
	int size;
private:
public:
	void ShowMenu()
	{
		cout << "1. Add Manager" << endl;
		cout << "2. Manage Product catalog" << endl;
		cout << "3. Show Product Catalog" << endl;
		cout << "4. Exit" << endl;
		int opt;
		cin >> opt;
		while (opt != 99)
		{
			switch (opt)
			{
			case 1:
				add_manager();
				break;
			case 2:
			{
				int id = 0;
				cout << "Enter the id you want to update: " << endl;
				cin >> id;
				P.update_product(id);
				break;
			}
			case 3:
				populate_food_catal();
				P.read_catalog_from_file();
				P.displayproductcatalog();
				break;
			case 4:
				exit(0);
				break;
			default:
				cout << "Invalid Option" << endl;
				break;
			}
			cout << "1. Add Manager" << endl;
			cout << "2. Manage Product Manager" << endl;
			cout << "3. Show Manager" << endl;
			cout << "4. Exit" << endl;
			cin >> opt;
		}
	}
	void setAdmin();
	void register_manager();
	void register_customer();
	Admin()
	{
		name = "Fatima";
		password = "Fatima123";
		M = NULL;
		size = 0;
	}
	void Display()
	{
		cout << "Name: " << name << endl;
		cout << "Password: " << password << endl;
	}
	void writetofile()
	{
		//binary file writing for admin
		ofstream fout;
		fout.open("Admin.txt", ios::binary);
		fout.write((char*)this, sizeof(*this));
		fout.close();
	}
	void readfromfile()
	{
		//binary file reading for admin
		ifstream fin;
		fin.open("Admin.txt", ios::binary);
		fin.read((char*)this, sizeof(*this));
		fin.close();
	}
	void readallmanagersfromfile()
	{
		Manager* A = new Manager[size];
		int i = 0;
		//read managers array from file till file does not end
		ifstream fin;
		fin.open("Manager.txt", ios::binary);
		fin.read((char*)&A[i], sizeof(*&A[i]));
		while (!fin.eof())
		{
			size++;
			fin.read((char*)&A[i], sizeof(*&A[i]));
		}
		fin.close();
		//display M
		for (int i = 0; i < size; i++)
		{
			M[i] = A[i];
		}
	}
	void writeallmanagerstofile()
	{
		//write managers array to file
		ofstream fout;
		fout.open("Manager.txt", ios::binary | ios::trunc);
		for (int i = 0; i < size; i++)
		{
			fout.write((char*)&M[i], sizeof(*&M[i]));
		}
		fout.close();
	}
	void Displaymanagers()
	{
		for (int i = 0; i < size; i++)
		{
			M[i].Display();
		}
	}
	void Login()
	{
		string p;
		cout << "Enter your passsword: " << endl;
		cin >> p;
		if (p == password)
		{
			cout << "Login Successful" << endl;
			ShowMenu();
		}
		else
		{
			cout << "Login Failed" << endl;
		}
	}
	void add_manager(Manager M)
	{
		Manager* temp = new Manager[size + 1];
		for (int i = 0; i < size; i++)
		{
			temp[i] = this->M[i];
		}
		temp[size] = M;
		size++;
		delete[] this->M;
		this->M = temp;
	}
	void add_manager()
	{
		Manager X;
		X.Signup();
		if (size == 0)
		{
			this->M = new Manager[size + 1];
			M[0] = X;
			size++;
		}
		else
		{
			int a = size + 1;
			Manager* temp = new Manager[a];
			for (int i = 0; i < size; i++)
			{
				temp[i] = M[i];
			}
			delete[]M;
			temp[size] = X;
			size++;
			M = temp;
		}
	}

};
bool User::Login(string a)
{

	string password;
	cout << "Enter your password here" << endl;
	cin >> password;
	if (password == this->password)
	{
		cout << "Login Successful" << endl;
		return 1;
	}
	else
	{
		cout << "Login Failed" << endl;
		return 0;
	}
}
void User::Signup()
{

	cout << "Enter your name here" << endl;
	cin >> name;
	cout << "Enter your password here" << endl;
	cin >> password;
	//password should have one capital letter, one small letter, one number
	string d = password;
	int countuppe = 0;
	int countlowe = 0;

	for (int i = 0; i < d.size(); i++)
	{
		if (d[i] >= 65 && d[i] <= 90)
		{
			countuppe++;
		}
		if (d[i] >= 97 && d[i] <= 122)
		{
			countlowe++;
		}
	}
	while (d.size() != 9 || countuppe <= 0 || countlowe <= 0)

	{
		cout << "Password should have one capital letter, one small letter, one number and should be 9 characters long" << endl;
		cin >> d;

		for (int i = 0; i < d.size(); i++)
		{
			if (d[i] >= 65 && d[i] <= 90)
			{
				countuppe++;
			}
			if (d[i] >= 97 && d[i] <= 122)
			{
				countlowe++;
			}
		}
	}
	password = d;
	cout << "Correct pass" << endl;
	//confirm password
	string confirm;
	cout << "Confirm your password here" << endl;
	cin >> confirm;
	while (confirm != password)
	{
		cout << "Password does not match" << endl;
		cout << "Enter your password again" << endl;
		cin >> confirm;
	}

	cout << "Enter your cnic here" << endl;
	cin >> cnic;
	//cnic should be 13 characters long
	//cnic should only have numbers
	bool num = false;
	bool len = false;

	while (num == false || len == false)
	{

		if (cnic.size() == 13)
		{
			len = true;
		}
		for (int i = 0; i < cnic.size(); i++)
		{
			if (cnic[i] >= 48 && cnic[i] <= 57)
			{
				num = true;
				continue;
			}
			else
			{
				num = false;
				break;
			}
		}
		if (num == false || len == false)
		{
			cout << "Enter your cnic here" << endl;
			cin >> cnic;
			num = false;
			len = false;
		}
	}
	int g;
	cout << "Enter your gender: ";
	cin >> g;
	while (g != 1 && g != 2)
	{
		cin >> g;
	}
	if (g == 1)
		gender = "male";
	else
		gender = "female";
	cout << "Enter your phone number here" << endl;
	cin >> phone;
	cout << "Enter your address" << endl;
	cin >> address;
}


int checkfilesize()
{
	int count = 0;
	prod_food_catal* b = new prod_food_catal;

	ifstream zout;
	zout.open("productcatalog.txt", ios::binary);
	while (zout.read((char*)&b, sizeof(b)))
	{

		count++;
	}
	count = count / 15;
	int re = count;
	zout.close();
	return re;
}
class Product
{
private:
	string name;
	string type;
	string brand;
	string price;
	int quantity;
public:
	
};
class Categories
{
private:
	string name;
	Product* P;
	int size;
public:
	
};
class Categories_food
{
private:
	string name;
	Product* P;
	int size;
public:
};


class Store
{
protected:
	Manager *M;
	Inventory I;
	//Product_Catalog P;
public:
	//
};

class Islamabad : public Store
{

};
class Karachi : public Store
{

};
class Lahore : public Store
{

};

class Online_Shopping
{
private:
};

void populate_inventory()
{
	
}
