#include <bits/stdc++.h>
using namespace std;

class DepositOnlyAccount{
    public:
        virtual void deposit(double amount) = 0;
};

class WithdrawableAccount : public DepositOnlyAccount {
    public:
        virtual void withdraw(double amount) = 0;
};

class SavingAccount : public WithdrawableAccount {
    private:
        double balance;
    
    public:
        SavingAccount(){
            balance = 0;
        }

        void deposit(double amount){
            balance += amount;
            cout << "Deposited: " << amount << " in savings account. New Balance: " << balance << endl;
        }

        void withdraw(double amount){
            if(balance >= amount){
                balance -= amount;
                cout << "Withdrawn: " << amount << " from savings account. New Balance: " << balance << endl;
            } else {
                cout << "Insufficient funds in savings account!\n"; 
            }
        }

};

class CurrentAccount : public WithdrawableAccount{
    private:
        double balance;
    
    public:
        CurrentAccount(){
            balance = 0;
        }

        void deposit(double amount){
            balance += amount;
            cout << "Deposited: " << amount << " in current account. New Balance: " << balance << endl;
        }

        void withdraw(double amount){
            if(balance >= amount){
                balance -= amount;
                cout << "Withdrawn: " << amount << " from current account. New balance: " << balance << endl;
            } else {
                cout << "Insufficient funds in current account!" << endl;
            }
        }
};

class FixedTermAccount : public DepositOnlyAccount {
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
};

class BankClient{
    private:
        vector<WithdrawableAccount*> withdrawableAccounts;
        vector<DepositOnlyAccount*> depositOnlyAccounts;
    
    public:
        BankClient(vector<WithdrawableAccount*> withdrawableAccounts, vector<DepositOnlyAccount*> depositOnlyAccounts ) {
            this->withdrawableAccounts = withdrawableAccounts;
            this->depositOnlyAccounts = depositOnlyAccounts;
        }

        void processTransactions() {
            for(WithdrawableAccount* acc : withdrawableAccounts) {
                acc->deposit(1000);            
                acc->withdraw(500);
            }

            for(DepositOnlyAccount* acc : depositOnlyAccounts) {
                acc->deposit(10000);            
            }
        }
};

int main(){
    vector<WithdrawableAccount*> withdrawableAccounts;
    withdrawableAccounts.push_back(new SavingAccount());
    withdrawableAccounts.push_back(new CurrentAccount());

    vector<DepositOnlyAccount*> depositOnlyAccounts;
    depositOnlyAccounts.push_back(new FixedTermAccount());

    BankClient* client = new BankClient(withdrawableAccounts, depositOnlyAccounts);
    client->processTransactions();

    return 0;
}
