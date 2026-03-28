/*
Title    :- PHARMACY MANEGMENT  SYSTEM

                  Using  By Class 
*/

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;
// global function to all classes to use it .
void Mainpage();

// All main user and Customer functions on medicine class
class Medicine {
private:
	// Encapsulated private medicine informations .
	string Medcine_name;
	int  Medcine_id;
	float Medcine_price;
	int Stock_length;
	int  Medcine_Quantity;

	string Date;
public:
	// constractor for medcine Class
	Medicine() {
		Medcine_id = 0;
		Medcine_price = 0;
	}
	// over loaded constractor for Medicine Class
	Medicine(int id, float price, string name) {
		Medcine_name = name;
		Medcine_price = price;
		Medcine_id = id;

	}
	// getter functions 
	int getid() const {
		return Medcine_id;
	}


	string getname() const {
		return  Medcine_name;
	}
	float getprice() {
		return Medcine_price;
	}
	int getQuantity() {
		return Medcine_Quantity;
	}
	
		string getdate(){
			return Date;
	}
	// setters 
	void setid(int id) {
		Medcine_id = id;
	}
	void setprice(float price) {
		Medcine_price = price;
	}
	void setname(string name) {
		Medcine_name = name;
	}
	void setQuantity(int Quantity) {
		Medcine_Quantity = Quantity;
	}
	void setdate(string date) {
		Date = date;
	}
	// input function for all informations
	void input() {
		cout << "Enter ID: ";
		cin >> Medcine_id;
		cin.ignore();

		cout << "Enter Name: ";
		getline(cin, Medcine_name);

		cout << "Enter price ";
		cin >> Medcine_price;
		cin.ignore();

		cout << "Enter quantity: ";
		cin >> Medcine_Quantity;
		;
		cout << " Enter Manufacturing Date Up To Expired Date " << endl;
		cin >> Date;
		cin.ignore();
		
	}
	void Display() {
		cout << "ID: " << Medcine_id << endl;
		cout << "                         " << endl;
		cout << "Name: " << Medcine_name << endl;
		cout << "                         " << endl;
		cout << "Price : " << Medcine_price << endl;
		cout << "                         " << endl;
		cout << "Quantity :" << Medcine_Quantity;
		cout << "                         " << endl;
		cout << "Manufacturing Date - Expired Date : "<< Date << endl;
		cout << "                         " << endl;
		
			


	}
	// convert inputed information in to single stright line 
	string formattoline() const {
		stringstream ss;
		ss << Medcine_id << "," << Medcine_name << "," << Medcine_price << "," << Medcine_Quantity << "," << Date;
		return ss.str();
	}
	// read the single straight line and divide the given inputed information 
	void fromLine(string line) {
		stringstream ss(line);
		char comma;

		ss >> Medcine_id >> comma;
		getline(ss, Medcine_name, ',');
		ss >> Medcine_price >> comma;
		ss >> Medcine_Quantity >> comma;
		getline(ss,Date);
	}
	void AddtoInverntory() {
		ofstream file("MyMedicines.txt", ios::app);
		input();
		file << formattoline() << endl;
		file.close();
		cout << "Medicine  added successfully." <<endl;;
	   

	}
	void RemoveInventory() {

				ifstream file("MyMedicines.txt");
				ofstream temp("temp.txt");
				string line, targetName;
				Medicine M;
				bool found = false;

				cout << "Enter the name of the medicine to remove: ";
				cin.ignore();
				getline(cin, targetName);

				while (getline(file, line)) {
					M.fromLine(line);
					if (M.getname() != targetName) {
						temp << line << endl;
					}
					else {
						found = true;
					}
				}

				file.close();
				temp.close();

				remove("MyMedicines.txt");
				rename("temp.txt", "MyMedicines.txt");

				if (found) {
					cout << "Medicine removed successfully.\n";
				}
				else {
					cout << "Medicine not found.\n";
				}

		}
	void viewInventory() {
		//
		ifstream file("MyMedicines.txt");
		string line;
		Medicine M;

		while (getline(file, line)) {
			M.fromLine(line);
			M.Display();
		}

		file.close();
	}
	void DeleteMedicine() {
		ifstream file("MyMedicines.txt");
		ofstream temp("temp.txt");

		int searchId;
		bool found = false;
		string line;

		cout << "Enter ID Of the Medicine to delete: ";
		cin >> searchId;
		cin.ignore();

		while (getline(file, line)) {
			Medicine M;
			M.fromLine(line);

			if (M.getid() == searchId) {
				found = true;
			}
			else {
				temp << line << endl;
			}
		}

		file.close();
		temp.close();

		remove("MyMedicines.txt");
		rename("temp.txt", "MyMedicines.txt");

		if (found)
			cout << "Medicine  deleted successfully. :)" << endl;
		else
			cout << "Medicine Not Found :( " << endl;
	}
	void SearchMedcine() {
		ifstream file("MyMedicines.txt");
		string line, targetName;
		Medicine M;
		bool found = false;

		cout << "Enter the name of the medicine to search: ";
		cin.ignore();
		getline(cin, targetName);

		while (getline(file, line)) {
			M.fromLine(line);
			if (M.getname() == targetName) {
				cout << "\nMedicine Found:\n";
				M.Display();
				found = true;
				break;
			}
		}

		if (!found) {
			cout << "Medicine not found in inventory.\n";
		}

		file.close();

	}
	void AddtoStock() {
		ifstream file("MyMedicines.txt");
		ofstream temp("temp.txt");
		string line, targetName;
		int amount;
		Medicine M;
		bool found = false;

		cout << "Enter medicine name to restock: " << endl;
		cin.ignore();
		getline(cin, targetName);
		cout << " Enter quantity to add  ";
		cin >> amount;

		while (getline(file, line)) {
			M.fromLine(line);
			if (M.getname() == targetName) {
				M.setQuantity(M.getQuantity() + amount);
				found = true;
			}
			temp << M.formattoline() << endl;
		}

		file.close();
		temp.close();

		rename("temp.txt", "Mystock.txt");

		if (found) cout << "Stock updated successfully.\n";
		else cout << "Medicine not found.\n";

	}
	void RemoveFromStock() {
		ifstream file("MyMedicines.txt");
		ofstream temp("temp.txt");
		string line, targetName;
		int amount;
		Medicine M;
		bool found = false;

		cout << "Enter medicine name to remove from stock: ";
		cin.ignore();
		getline(cin, targetName);
		cout << "Enter quantity to remove: ";
		cin >> amount;

		while (getline(file, line)) {
			M.fromLine(line);
			if (M.getname() == targetName) {
				if (M.getQuantity() >= amount) {
					M.setQuantity(M.getQuantity() - amount);
					found = true;
				}
				else {
					cout << "Error: Not enough stock available!\n";
				}
			}
			temp << M.formattoline() << endl;
		}

		file.close();
		temp.close();

		rename("temp.txt", "Mystock.txt");

		if (found) cout << "Stock decreased successfully.\n";
		else if (!found) cout << "Transaction failed or medicine not found.\n";

	}
	void viewstock() {
		//

		ifstream file("Mystock.txt");
		string line;
		Medicine M;

		while (getline(file, line)) {
			M.fromLine(line);
			M.Display();
		}

		file.close();
	}
	void purchase_stock() {
		ifstream file("MyMedicines.txt");
		ofstream temp("temp.txt");
		string line, targetName;
		int amount;
		Medicine M;
		bool found = false;

		cout << "Enter medicine name to restock: " << endl;
		cin.ignore();
		getline(cin, targetName);
		cout << " Enter quantity to add  ";
		cin >> amount;

		while (getline(file, line)) {
			M.fromLine(line);
			if (M.getname() == targetName) {
				M.setQuantity(M.getQuantity() + amount);
				found = true;
			}
			temp << M.formattoline() << endl;
		}

		file.close();
		temp.close();

		rename("temp.txt", "MyCart.txt");

		if (found) cout << "Medicine  Added To Cart  successfully.\n";
		else cout << "Medicine not found.\n";

	}
	void searchstock() {
		ifstream file("MyMedicines.txt");
		string line, targetName;
		Medicine M;
		bool found = false;

		cout << "Enter the name of the medicine to search: ";
		cin.ignore();
		getline(cin, targetName);

		while (getline(file, line)) {
			M.fromLine(line);
			if (M.getname() == targetName) {
				cout << "\nMedicine Found:\n";
				M.Display();
				found = true;
				break;
			}
		}

		if (!found) {
			cout << "Medicine not found in inventory.\n";
		}

		file.close();


	}
	void viewcart() {
		//

		ifstream file("MyCart.txt");
		string line;
		Medicine M;

		while (getline(file, line)) {
			M.fromLine(line);
			M.Display();
		}

		file.close();
	}
	void ReportIsuee() {
		string customerreport;
		cout << " Please Enter Your Report For The Admin" << endl;
		fstream report;
		report.open("Report.txt", ios::out);
		if (report.is_open()) {
			cin.ignore();
			getline(cin, customerreport);
			
			report << customerreport << endl;
			report.close();
			cout << "Report submitted successfully." << endl;
		}
		
	}
	void Viewreport() {
		ifstream file("report.txt");
		string word;

		if (!file) {
			cout << "Error: Cannot open report.txt" << endl;
			return;
		}

		while (file >> word) {
			cout << word;
			cout << " ";
		}

		file.close();
	}
};

Medicine I;
// all admin regstring and loging 
class Admin {
private:
	string username;
	string password;
public:
	void clearScreen() {
		cout << "\x1B[2J\x1B[1;1H";
	}
	void continue_admin() {
		
		int x;
		cout << " coutinue ?" << endl;
		cout << " 1 . Yes " << endl;
		cout << " 2 . No " << endl;
		cin >> x;
		if (x == 1) {
			Admin_page(username);
		}
		else if (x == 2) {
			clearScreen();
		}
		else {
			cout << " Invalid input " << endl;
			continue_admin();
		}
	}
	

	void  Admin_page(string username) {
		Admin A;
		Medicine M;
		int userchoice;
		cout << " ===  Welcome  To Innventory Managment  System" << username << " ===  " << endl;
		cout << "                        " << endl;
		cout << "1 . Add Medicine To Inventory " << endl;
		cout << "                        " << endl;
		cout << "2 . Remove Medicine From  Inventory " << endl;
		cout << "                        " << endl;
		cout << "3 . View Inventory Medicines " << endl;
		cout << "                          " << endl;
		cout << "4 . Search Inventory Medicines " << endl;
		cout << "                        " << endl;
		cout << "5 . Add To Stock  " << endl;
		cout << "                        " << endl;
		cout << "6 . Remove From Stock " << endl;
		cout << "                        " << endl;
		cout << "7 . View Stock Medicines " << endl;
		cout << "                        " << endl;
		cout << "8 . View Report from Customer " << endl;
		cout << "                        " << endl;
		cout << "9 . Exit to Main page" << endl;
		cout << "                        " << endl;
		cin >> userchoice;
		switch (userchoice)
		{
		case 1:
			M.AddtoInverntory();
			A.continue_admin();
			// AddtoInverntory();
			
		case 2:
			M.RemoveInventory();
			A.continue_admin();
		case 3:
			M.viewInventory();
			A.continue_admin();
			// viewInventory();
			break;
		case 4:
			M.SearchMedcine();
			A.continue_admin();
			// A.SearchMedicine();
			break;
		case 5:
			M.AddtoStock();
			A.continue_admin();
			// A.Add_to_stock();
			break;
		case 6:

			M.RemoveFromStock();
			A.continue_admin();
			// A.Remove_from_stock();
		
		case 7:
			M.viewstock();
			A.continue_admin();
		case 8:
			M.Viewreport();
			A.continue_admin();
			// A.display_user_massage();
		
		case 10:
			Mainpage();
			
		
		default:
			
			break;
		}
	};
	void registerAdmin() {
		ofstream file("Admin_info.txt", ios::app);
		cout << "--- Admin Registration ---\n";
		cout << "Enter Admin Username: ";
		cin >> username;
		cout << "Enter Admin Password: ";
		cin >> password;
		file << username << " " << password << endl;
		file.close();
		clearScreen();
		cout << "Admin Registered Successfully Log In Now " << endl;
		
	}

	bool login1() {
		Admin A;
		ifstream file("Admin_info.txt");
		string u, p;
		cout << "username :";
		cin >> username;
		cout << "password :";
		cin >> password;
		
		while (file >> u >> p) {
			if (u == username && p == password) {
				file.close();
				clearScreen();
				cout << "Admin Login Successfully "<< "Welcome "<<username  << endl;
				A.Admin_page(username);
				return true;


			}
		}
		file.close();
		cout << " invalid password or username  " << endl;
		return false;
	}

	bool Admin_Menu() {
		int choice;
		Admin A;
		cout << " ===  Admin Menu  === "<<endl;
		cout << "1. Register  Admin" << endl;
		cout << "2. Login" <<endl;
		cout << "0. Exit " << endl;;
		cout << "Enter choice - > ";
		cin >> choice;
		switch (choice) {
		case 1:
			registerAdmin();
			return false;
		case 2:
			
				return login1();
			

		case 0:
			cout << "Exiting" << endl;
			return false;
		default:
			cout << "Invalid choice." << endl;
			return false;
		}
	}
};

Admin A;
// all user registering and logging 
class User {
private:
	string username;
	string password;
public:
	void clearScreen() {
		cout << "\x1B[2J\x1B[1;1H";
	}
	void continue_user() {

		int x;
		cout << " coutinue ?" << endl;
		cout << " 1 . Yes " << endl;
		cout << " 2 . No " << endl;
		cin >> x;
		if (x == 1) {
			Customer_page();
		}
		else if (x == 2) {
			clearScreen();
		}
		else {
			cout << " Invalid input " << endl;
			continue_user();
		}
	}
	void registercustomer() {
		ofstream file("Customers_info.txt", ios::app);
		cout << "--- User Registration ---\n";
		cout << "Enter New Username: " << endl;
		cin >> username;
		cout << "Enter New Password: " << endl;
		cin >> password;
		file << username << " " << password << endl;
		file.close();
		clearScreen();
		cout << "Registration Successful. you can log in now " << endl;
		
	}

	bool login() {
		ifstream file("Customers_info.txt");
		string u, p;
		cout << "Username: ";
		cin >> username;

		cout << "Password: ";
		cin >> password;
		while (file >> u >> p) {
			if (u == username && p == password) {
				file.close();
				clearScreen();
				cout << "Customer  Login Successfully " << "Welcome " << username << endl;
				Customer_page();
				return true;


			}
		}
		
		file.close();
		cout << " invalid username or password " << endl;
		return false;
		
	}

	bool Customer_Menue() {
	
		int choice;
		cout << " ====  Customer Menu === " << endl;;
		cout << "1. User Registration " << endl;
		cout << "2. Login" << endl;
		cout << "0. Exit" << endl;
		cout << "Enter choice - >  ";
		cin >> choice;
		switch (choice) {
		case 1:
			registercustomer();
			return false;
		case 2:
				return login();
		case 0:
			cout << "exting" << endl;
			return false;
		default:
			cout << "invalid choise" << endl;
			return false;
		}
	}
	void Customer_page() {


		int userchoice;
		cout << " ===   Welcome To Health Pharmacy  " << " ===  " << endl;
		cout << "                        " << endl;
		cout << "1 . List Avilable Stock Medicines " << endl;
		cout << "                        " << endl;
		cout << "2 . Purchase Stock Medicine  " << endl;
		cout << "                        " << endl;
		cout << "3 . Search Stock Medicines " << endl;
		cout << "                        " << endl;
		cout << "4 .  View Cart        " << endl;
		cout << "                        " << endl;
		cout << "5 . Report Issue " << endl;
		cout << "                        " << endl;
		cout << "6 . Exit  to Main Page" << endl;
		cout << "                        " << endl;
		cin >> userchoice;
		switch (userchoice)
		{
		case 1:
			I.viewstock();
			continue_user();
			//	Add_To_Inventory();

				////List_of_Medicine();
			
		case 2:
			I.purchase_stock();
			continue_user();
			//viewStudents();
			//U.purchase_med();
			
		case 3:
			I.searchstock();
			continue_user();
			//U.search_stock_med();
			
		case 4:
			I.viewcart();
			continue_user();
			//.View_Cart();
			
		case 5:
			I.ReportIsuee();
			continue_user();
		case 6:
			Mainpage();

		default:
			break;
		}


	}
};

User U;
// main page / global function to be accessed in all classes to navigate between user and admins.
void Mainpage() {
	while (true) {
		cout << "  === Main Page === " <<endl;
		cout << "1. Admin" <<endl;
		cout << "2. User" << endl;
		cout << "3. Exit" << endl;
		cout << " Enter Your Choice - >  ";
		int choice;
		cin >> choice;
		if (choice == 1) {
			A.Admin_Menu();
		}
		else if (choice == 2) {
			U.Customer_Menue();
		}
		else if (choice == 3) {
			cout << " Thanks For Everything" << endl;
			return;

		}
		else {
			cout << "Invalid choice." <<endl;
		}
	}
}


	

int main() {
	Mainpage();

	
	

		return 0;
	}



	