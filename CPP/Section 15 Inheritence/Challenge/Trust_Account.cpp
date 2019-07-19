#include "Trust_Account.h"

Trust_Account::Trust_Account(std::string name, double balance, double int_rate)
    :Savings_Account(name,balance,int_rate),withdraw_count {0}{
        
}

bool Trust_Account::deposit(double amount){
    double temp {amount};
    amount += amount * (int_rate/100);
    if(temp > 5000)
        amount += 50.0;
    return Savings_Account::deposit(amount);
}

bool Trust_Account::withdraw(double amount){
    if(withdraw_count >= max_withdrawl_limit || amount > balance*percent_withdrawl_limit/100)
        return false;
    else{
        withdraw_count++;
        return Account::withdraw(amount);
    }
}
std::ostream &operator<<(std::ostream &os, const Trust_Account &account) {
    os << "[Checking_Account: " << account.name << ": " << account.balance << ", " << account.int_rate << "%]";
    return os;
}