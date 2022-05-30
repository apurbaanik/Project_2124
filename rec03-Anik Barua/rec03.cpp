/*
Title: rec03
Author: Anik Barua
Version: 1.0
Date: 02-11-2022
*/

// Provided
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

// Task 1
// Define an Account struct
struct Account{
  string name;
  int accountNumber;
};

// Task 2
// Define an Account class (use a different name than in Task 1)
class BankAccount{
  friend ostream& operator<<(ostream& output, const BankAccount& account);
  public:
  BankAccount(const string& name, int accountNumber) : name(name), accountNumber(accountNumber) {}
  const string& getName() const {
	  return name;
  }
  int getAccountNumber() const {
	  return accountNumber;
  }
  private:
  string name;
  int accountNumber;
};

ostream& operator<<(ostream& output, const BankAccount& account) {
    //output << account.getName() << " " << account.getAccountNumber() << endl;
    output << account.name << " " << account.accountNumber << endl;
    return output;
}

// Task 3
// Define an Account (use a different name than in Task 1&2) and
// Transaction classes
class Transaction{
  friend ostream& operator<<(ostream& output, const Transaction& transition);
  public:
  Transaction(const string& transaction, int amount) : transaction(transaction), amount(amount) {}

  const string& getTransaction() const {
	  return transaction;
  }

  int getAmount() const {
	  return amount;
  }

  private:
  string transaction;
  int amount;
};

ostream& operator<<(ostream& output, const Transaction& transition) {
  output << transition.transaction << " " << transition.amount << endl;
  return output;
}

class MainAccount{
  friend ostream& operator<<(ostream& output, const MainAccount& mainAccount);
  public:
  MainAccount(const string& name, int accountNumber) : name(name), accountNumber(accountNumber), balance(0) {}

  void deposit(int amount){
    balance += amount;
    transactions.emplace_back("deposit", amount);
  }

   void withdrawal(int amount){
    if(balance >= amount){
      balance -= amount;
      transactions.emplace_back("withdrawal", amount);
    } else {
      cout << "Account# " << accountNumber << " has only " << balance << ". Insufficient for withdrawal of " << amount << ".\n";
    }
  }

  int getAccountNumber() const {
	  return accountNumber;
  }
  
  private:
  string name;
  int accountNumber;
  vector<Transaction> transactions;
  int balance;
}; 

ostream& operator<<(ostream& output, const MainAccount& mainAccount) {
  output << mainAccount.name << " " << mainAccount.accountNumber 
  << ":\n";
  for (const Transaction& transaction : mainAccount.transactions) {
    //output << x.getTransaction() << " " << x.getAmount() << endl;
    output << "   " << transaction;
  }
  output << "\n";
  return output;
}

// Task 4
// Define an Account with a nested public Transaction class
// (use different names than in the previous Tasks)

class NewAccount{
  friend ostream& operator<<(ostream& output, const NewAccount& mainAccount);
public:
  class NewTransaction{
  friend ostream& operator<<(ostream& output, const NewAccount::NewTransaction& transition);
  public:
  NewTransaction(const string& transaction, int amount) : transaction(transaction), amount(amount) {}

  const string& getTransaction() const {
	  return transaction;
  }

  int getAmount() const {
	  return amount;
  }

  private:
  string transaction;
  int amount;
};

  NewAccount(const string& name, int accountNumber) : name(name), accountNumber(accountNumber), balance(0) {}

  void deposit(int amount){
    balance += amount;
    transactions.emplace_back("deposit", amount);
  }

   void withdrawal(int amount){
    if(balance >= amount){
      balance -= amount;
      transactions.emplace_back("withdrawal", amount);
    } else {
      cout << "Account# " << accountNumber << " has only " << balance << ". Insufficient for withdrawal of " << amount << ".\n";
    }
  }

  int getAccountNumber() const {
	  return accountNumber;
  }
  
  private:
  string name;
  int accountNumber;
  vector<NewTransaction> transactions;
  int balance;
}; 

ostream& operator<<(ostream& output, const NewAccount& mainAccount) {
  output << mainAccount.name << " " << mainAccount.accountNumber 
  << ":\n";
  for (const NewAccount::NewTransaction& transaction : mainAccount.transactions) {
    output << "   " << transaction;
  }
  output << "\n";
  return output;
}

ostream& operator<<(ostream& output, const NewAccount::NewTransaction& transition) {
  output << transition.transaction << " " << transition.amount << endl;
  return output;
}

// Task 5
// Define an Account with a nested private Transaction class
// (use different names than in the previous Tasks)

int main() { 
    // Task 1: account as struct
    //      1a
    cout << "Task1a:\n";
    ifstream reader("accounts.txt");
    if (!reader)
    {
        cerr << "Failed to open accounts.txt";
        exit(1);
    }
    string name;
    int accountNumber;
    vector<Account> accounts;
    while(reader >> name >> accountNumber){
      Account account;
      account.name = name;
      account.accountNumber = accountNumber;
      accounts.push_back(account);
    }
     
    reader.close();

    for (const Account& account1 : accounts) {
      cout << account1.name << " " << account1.accountNumber << endl;
    } 

    //      1b
    cout << "\nTask1b:\n";
    cout << "Filling vector of struct objects, using {} initialization:\n";
    accounts.clear();
    reader.open("accounts.txt");
    if (!reader)
    {
        cerr << "Failed to open accounts.txt";
        exit(1);
    }
    while(reader >> name >> accountNumber){
      Account account{name, accountNumber};
      accounts.push_back(account);
    }
    reader.close();
    for (const Account& account1 : accounts) {
      cout << account1.name << " " << account1.accountNumber << endl;
    } 

    //==================================
    // Task 2: account as class

    //      2a
    cout << "==============\n";
    cout << "\nTask2a:";
    cout << "\nFilling vector of class objects, using local class object:\n";
    vector<BankAccount> bankAccounts;
    reader.open("accounts.txt");
    if (!reader)
    {
        cerr << "Failed to open accounts.txt";
        exit(1);
    }
    while(reader >> name >> accountNumber){
      BankAccount account1 (name, accountNumber);
      bankAccounts.push_back(account1);
    }
    reader.close();
    for (const BankAccount& bankaccount1 : bankAccounts) {
      cout << bankaccount1.getName() << " " << bankaccount1.getAccountNumber() << endl;
    } 

    cout << "\nTask2b:\n";
    cout << "output using output operator with getters\n";

    for (const BankAccount& bankaccount1 : bankAccounts) {
      operator<<(cout, bankaccount1);
    }

    cout << "\nTask2c:\n";
    cout << "output using output operator as friend without getters\n";
    for (const BankAccount& bankaccount1 : bankAccounts) {
      operator<<(cout, bankaccount1);
    }

    cout << "\nTask2d:\n";
    cout << "Filling vector of class objects, using temporary class object:\n";
    bankAccounts.clear();
    reader.open("accounts.txt");
    if (!reader)
    {
        cerr << "Failed to open accounts.txt";
        exit(1);
    }
    while(reader >> name >> accountNumber){
      bankAccounts.push_back(BankAccount(name, accountNumber));
    }
    reader.close();
    for (const BankAccount& bankaccount1 : bankAccounts) {
      operator<<(cout, bankaccount1);
    }

    cout << "\nTask2e:\n";
    cout << "Filling vector of class objects, using emplace_back:\n";
    bankAccounts.clear();
    reader.open("accounts.txt");
    if (!reader)
    {
        cerr << "Failed to open accounts.txt";
        exit(1);
    }
    while(reader >> name >> accountNumber){
      bankAccounts.emplace_back(name, accountNumber);
    }
    reader.close();
    for (const BankAccount& bankaccount1 : bankAccounts) {
      operator<<(cout, bankaccount1);
    }

    cout << "==============\n";
    cout << "\nTask 3:\nAccounts and Transaction:\n";
    vector<MainAccount> mainAccounts;
    reader.open("transactions.txt");
    if (!reader)
    {
        cerr << "Failed to open transactions.txt";
        exit(1);
    }
    string line;
    int number, amount;
    while(reader >> line){
      if(line == "Account"){
        reader >> name;
        reader >> accountNumber;
        MainAccount account1 (name, accountNumber);
        mainAccounts.push_back(account1);
      }
      if(line == "Deposit"){
        reader >> number;
        reader >> amount;
        for (MainAccount& account1 : mainAccounts) {
          if(account1.getAccountNumber() == number){
            account1.deposit(amount);
            break;
          }
        }
      }
      if(line == "Withdraw"){
        reader >> number;
        reader >> amount;
        for (MainAccount& account1 : mainAccounts) {
          if(account1.getAccountNumber() == number){
            account1.withdrawal(amount);
            break;
          }
        }
      }
    }
    reader.close();
    for (const MainAccount& mainAccount1 : mainAccounts) {
      operator<<(cout, mainAccount1);
    }

    cout << "==============\n";
    cout << "\nTask 4:\nTransaction nested in public section of Account:\n";
    vector<NewAccount> newAccounts;
    reader.open("transactions.txt");
    if (!reader)
    {
        cerr << "Failed to open transactions.txt";
        exit(1);
    }
    string line2;
    int number2, amount2;
    while(reader >> line2){
      if(line2 == "Account"){
        reader >> name;
        reader >> accountNumber;
        NewAccount account1 (name, accountNumber);
        newAccounts.push_back(account1);
      }
      if(line2 == "Deposit"){
        reader >> number2;
        reader >> amount2;
        for (NewAccount& account1 : newAccounts) {
          if(account1.getAccountNumber() == number2){
            account1.deposit(amount2);
            break;
          }
        }
      }
      if(line2 == "Withdraw"){
        reader >> number2;
        reader >> amount2;
        for (NewAccount& account1 : newAccounts) {
          if(account1.getAccountNumber() == number2){
            account1.withdrawal(amount2);
            break;
          }
        }
      }
    }
    reader.close();
    for (const NewAccount& newAccount1 : newAccounts) {
      operator<<(cout, newAccount1);
    }

/*  cout << "==============\n";
    cout << "\nTask 5:\nTransaction nested in private section of Account:\n";
 */
    
}