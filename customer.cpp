#include "customer.hpp"
#include <iostream>

std::string Customer::get_name() const 
{
    return m_name;
}

std::string Customer::get_address() const 
{
    return m_address;
}


std::string Customer::get_contact() const 
{
    return m_contact_info;
}

int Customer::get_id() const 
{
    return m_id;
}

const std::vector<Account*>& Customer::get_accounts() const
{
    return m_accounts;
}

void Customer::get_info() const
{
    std::cout << "Customer Name: " << this->get_name() << std::endl;
    std::cout << "Customer Address: " << this->get_address() << std::endl;
    std::cout << "Customer Contact Info: " << this->get_contact() << std::endl;
    std::cout << "Customer ID: " << this->get_id() << std::endl;
}

void Customer::create_account(const int account_num, const double initial_balance) 
{
    Account* account = new Account(account_num, initial_balance);
    m_accounts.push_back(account);
}

bool Customer::deposit(const int account_num, const double amount) 
{
    for (auto& account : m_accounts) {
        if (account->get_account_num() == account_num) {
            account->deposit(amount);
            return true;
        }
    }
    return false;
}

bool Customer::withdraw(const int account_num, const double amount) 
{
    for (auto& account : m_accounts) {
        if (account->get_account_num() == account_num) {
            return account->withdraw(amount);
        }
    }
    return false;
}