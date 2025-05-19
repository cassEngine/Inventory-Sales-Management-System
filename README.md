# Inventory and Sales Management System
A simple C++ console application for managing stock inventory and recording sales transactions. Built using **Code::Blocks IDE**, employees can add products, update stock, process sales, and generate daily sales reports.

##  Project Context

This application was developed for a medium-sized retail company seeking a lightweight, console-based solution to track inventory and record daily sales. The focus is on simplicity, efficiency, and file-based data persistence without external libraries or databases.

---

## Features

### 1. Product Management
Each product includes:
- `ProductID (unique)
- `Name
- `Price
- `QuantityInStock

Supported operations:
- Add new products
- Update stock quantity
- View the list of all products

---

### 2. Sales Processing
- Employees can process customer purchases involving one or more products.
- System checks for sufficient stock and updates inventory accordingly.
- Generates a detailed **receipt** that includes:
  - List of purchased products
  - Total price
  - Timestamp of the transaction

---

### 3. Daily Sales Report
At the end of the day, a report summarizes:
- Total items sold
- Total revenue generated
- Number of sales transactions

Optionally saved as: "sales_report_YYYYMMDD.txt"

---

### 4. Persistent Storage
- **On startup**: Loads product inventory from "products.txt"
- **On exit**:
  - Saves updated inventory to "products.txt"
  - Saves the daily sales report to a dated text file

---

## 💻 Technologies Used

- **C++** (Object-Oriented Programming)
- **Code::Blocks IDE**
- File I/O using standard C++ file streams ("fstream")
- Console-based interface

---

## 📂 How to Compile and Run

1. Open the project ".cbp"  file in **Code::Blocks**
2. Build and run the project
3. Make sure "products.txt" exists in the project directory with valid entries (or the system will create one)

---

## 📄 Sample Files

- Sales_report20250518  – Stores inventory data
- sales_report_YYYYMMDD.txt – Daily sales summary with timestamp
  
---

## 🛠️ Future Improvements (Optional)

- GUI version using Qt or SFML
- Customer database
- Discount and tax calculations
- Password-protected employee access
---

## 📬 Contact

For questions or improvements, feel free to open an issue or contact me directly via LinkedIn or GitHub!

