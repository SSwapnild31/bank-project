# Bank-Management-System (C++)

## ➡️ Description
+ A Bank Management System built using C++, demonstrating concepts like OOP, file handling, and and basic authentication.

## 📌 Features
+ Admin : __Login System (username & password)__
+ Admin : View/Count all accounts
+ User : Send/Deposit money
+ Create new bank accounts
+ Search account by account number
+ Check account balance
+ Display account details
+ File-based data storage (persistent data)
+ Check balance by account number
+ Some more operations

## ✒️ Tech Stack
+ Language : C++
+ Concepts Used :
    + Object-Oriented Programming (OOP)
    + File Handling (fstream)
    + Namespaces
    + Abstract Classes & Virtual Functions
    + Enum Classes
    + Structure

## 📂 Project Structure
+ __bank.cpp__  : Main source code
+ __data.dat__  : File storing account records (generated at runtime)
+ __pass__      : Contains admin login information
+ __README.md__ : Project documentation

## 🧠 Design Overview
+ Namespace: bnk
+ Core Components:
    + bank_column   :   Structure for account data
    + acc_type      :   Enum for account type (Saving / Current)
    + bank_op       :    Abstract base class for operations
    + Derived classes implement:
         + Search account
         + Check balance
         + Display account
         + Admin operations

## ▶️ How to Run
   1. Compile
         ```bash
         g++ bank.cpp -o bank
         ```
   2. Run
        ```bash
        ./bank
        ```
## 💾 File Handling
+ `data.dat` → Stores account details
+ `pass.dat` → Stores admin username & password
+ Ensures data persistence across executions

## ⚠️ Security Note
+ Passwords are stored in plain text (binary format)
+ This means:
    + Data is not human-readable directly
    + But can still be easily extracted using programs
+  ❗This is not secure for real-world applications

## 🔐 Admin Authentication
+ Admin credentials are stored in a binary file (`pass.dat`)
+ Uses istream in binary mode for reading credentials
+ Login verifies:
    + Username : `Admin`
    + Password : `Admin@123`

## 🚀 Future Enhancements
+ Encrypt passwords (hashing)
+ Add user login system
+ Transaction features (deposit/withdraw)
+ Improve input validation
+ Add GUI (Qt / Web)
+ Database integration (MySQL / SQLite)

## 📸 Sample Flow/Output
+ ADMIN
```bash
    bruce@Bruce:~/project$ ./bank
    -------------------------------
              | WELCOME |
    -------------------------------
        1.Admin  2.User  3.Exit
    -------------------------------
     Enter option : 1
     Enter Username : Admin
     Enter Password : Admin@123
    -------------------------------
               Logged In
    -------------------------------
     1.Create Acc   2.Update Acc
     3.Search Acc   4.Delete Acc
     5.Check bal    6.Display Accs
     7.Count Accs   8.Main menu
    -------------------------------
     Enter option : 7
    -------------------------------
     Total records : 3
    -------------------------------
     1.Create Acc   2.Update Acc
     3.Search Acc   4.Delete Acc
     5.Check bal    6.Display Accs
     7.Count Accs   8.Main menu
    -------------------------------
     Enter option : 8
    -------------------------------
        1.Admin  2.User  3.Exit
    -------------------------------
      Enter option : 2
    -------------------------------
     1.Search Acc   2.Check bal
     3.Send money   4.Deposit money
     5.Main menu
    -------------------------------
     Enter option : 5
    -------------------------------
        1.Admin  2.User  3.Exit
    -------------------------------
     Enter option : 3
    -------------------------------
             | THANK YOU |
    ------------------------------- 
```
+ USER
```bash
    bruce@Bruce:~/project$ ./bank
    -------------------------------
              | WELCOME |
    -------------------------------
        1.Admin  2.User  3.Exit
    -------------------------------
     Enter option : 2
    -------------------------------
     1.Search Acc   2.Check bal
     3.Send money   4.Deposit money
     5.Main menu
    -------------------------------
     Enter option : 5
    -------------------------------
        1.Admin  2.User  3.Exit
    -------------------------------
     Enter option : 3
    -------------------------------
             | THANK YOU |
    -------------------------------  
```

## 🤝 Contribution
+ Feel free to fork and improve this project.

## 📜 License
+ This project is for learning purposes.





