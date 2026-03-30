# 💊 Pharmacy Inventory Management System (C++)

A simple console-based Pharmacy Management System developed in C++ using Object-Oriented Programming (OOP).
This project helps manage medicines, stock, users, and admin operations using file handling.

# 📌 Features
# 👨‍💼 Admin Side
Register & Login system
Add new medicines to inventory
Remove medicines from inventory
View all medicines
Search medicines
Add stock quantity
Remove stock quantity
View stock details
View customer reports
# 👤 User (Customer) Side
Register & Login system
View available medicines
Search medicines
Purchase medicines (add to cart)
View cart
Send report/feedback to admin
🧠 Concepts Used
Object-Oriented Programming (OOP)
Classes & Objects
Encapsulation
File Handling (fstream)
String Manipulation (stringstream)
Menu-driven programming
Basic Data Persistence using .txt files
# 📂 Files Used
File Name	Purpose
MyMedicines.txt	Stores medicine inventory
Mystock.txt	Stores updated stock
MyCart.txt	Stores user cart items
Admin_info.txt	Stores admin credentials
Customers_info.txt	Stores user credentials
Report.txt	Stores user reports
# ⚙️ How to Run

Clone the repository:

git clone https://github.com/your-username/pharmacy-management-system.git

Navigate to the project folder:

cd pharmacy-management-system

Compile the code:

g++ Pharmacy_inventory_Managment_system_by_class.cpp -o pharmacy

Run the program:

./pharmacy
# 🖥️ Sample Menu
=== Main Page ===
1. Admin
2. User
3. Exit
# ⚠️ Known Issues / Improvements
File naming inconsistency (MyMedicines.txt vs Mystock.txt)
No data validation for inputs
Passwords are stored in plain text (not secure)
UI can be improved
No database integration (currently uses text files)
# 🚀 Future Enhancements
Use a database (MySQL / SQLite)
Add GUI (Qt or Web-based interface)
Improve security (password hashing)
Add billing system
Add expiry date alerts
# 👨‍💻 Author

Kaleb Asfaw

📄 License

This project is open-source and available under the MIT License.
