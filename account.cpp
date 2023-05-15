#include "account.hpp"
#include <iostream>

double Account::get_balance() const
{
    return m_balance;
}

int Account::get_account_num() const
{
    return m_account_num;
}

void Account::get_account_info() const
{
    std::cout << "Account Balance: " << this->get_balance() << std::endl;
    std::cout << "Account Number: "  << this->get_account_num() << std::endl;
}

void Account::deposit(const double amount) 
{
    m_balance += amount;
}

bool Account::withdraw(const double amount) 
{
    if (m_balance >= amount) {
        m_balance -= amount;
        return true;
    }
    return false;
}
