#include <bits/stdc++.h>
using namespace std;

class Account {
    public:
        virtual void deposit(double amount) = 0;
        virtual void withdraw(double amount) = 0;
};

class SavingAccount : public Account {
    private:
        double balance;
    
    public:
        SavingAccount(){
            balance = 0;
        }

        void deposit(double amount) {
            balance += amount;
            cout << "Deposited: " << amount << " in savings account. New Balance: " << balance << endl;
        }

        void withdraw(double amount){
            if(balance >= amount){
                balance -= amount;
                cout << "Withdrawn: " << amount << " from savings account. New Balance: " << balance << endl;
            } else {
                cout << "Insufficient funds in savings account\n";
            }
        }
};

class CurrentAccount : public Account {
    private:
        double balance;
    
    public:
        CurrentAccount(){
            balance = 0;
        }

        void deposit(double amount) {
            balance += amount;
            cout << "Deposited: " << amount << " in current account. New Balance: " << balance << endl;
        }

        void withdraw(double amount){
            if(balance >= amount){
                balance -= amount;
                cout << "Withdrawn: " << amount << " from current account. New Balance: " << balance << endl;
            } else {
                cout << "Insufficient funds in current account\n";
            }
        }
};

class FixedTermAccount : public Account {
    private:
        double balance;
    
    public:
        FixedTermAccount() {
            balance = 0;
        }

        void deposit(double amount){
            balance += amount;
            cout << "Deposited: " << amount << " in fixed term account. New Balance: " << balance << endl;
        }

        void withdraw(double amount){
            throw logic_error("Withdrawal not allowed in fixed term account!");
        }
};

class BankClient{
    private:
        vector<Account*> accounts;
    
    public:
        BankClient(vector<Account*> accounts) {
            this->accounts = accounts;
        }

        void processTransactions() {
            for(Account* acc : accounts) {
                acc->deposit(1000);                     // All accounts allow deposits
                
                // Assuming all accounts support withdrawal (LSP Violation)
                try{
                    acc->withdraw(500);
                } catch (const logic_error& e){
                    cout << "Exception: " << e.what() << endl;
                }
            }
        }
};

int main(){
    vector<Account*> accounts;
    accounts.push_back(new SavingAccount());
    accounts.push_back(new CurrentAccount());
    accounts.push_back(new FixedTermAccount());

    BankClient* client = new BankClient(accounts);
    client->processTransactions();              // Throws exception when withdrawing from fixed term account

    return 0;
}