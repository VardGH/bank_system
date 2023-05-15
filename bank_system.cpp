#include "bank_system.hpp"
#include <iostream>

void BankSystem::get_customer_info(const int customer_id) const
{
    for (const auto& customer : m_customers) {
        if (customer.get_id() == customer_id) {
            customer.get_info();
            std::cout << "Customer Accounts: " << std::endl;
            const std::vector<Account*>& accounts = customer.get_accounts();
            for (const auto& account : accounts) {
                account->get_account_info();
            }
            return;
        }
    }
    std::cout << "Customer not found." << std::endl;
}

const std::vector<Customer>& BankSystem::get_customers() const
{
    return m_customers;
}

void BankSystem::create_customer(const std::string& name, const std::string& address, const std::string& contact_info, const int customer_id)
{
    Customer customer(name, address, contact_info, customer_id);
    m_customers.push_back(customer);
}

void BankSystem::create_account(const int customer_id, const int account_num, const double initial_balance)
{
    for (auto& customer : m_customers) {
        if (customer.get_id() == customer_id) {
            customer.create_account(account_num, initial_balance);
            return;
        }
    }
    std::cout << "Customer not found." << std::endl;
}

void BankSystem::deposit(const int customer_id, const int account_num, const double amount) 
{
    for (auto& customer : m_customers) {
        if (customer.get_id() == customer_id) {
            if (customer.deposit(account_num, amount)) {
                std::cout << "Deposit successful." << std::endl;
            } else {
                std::cout << "Account not found." << std::endl;
            }
            return;
        }
    }
    std::cout << "Customer not found." << std::endl;
}

void BankSystem::withdraw(const int customer_id, const int account_num, const double amount) 
{
    for (auto& customer : m_customers) {
        if (customer.get_id() == customer_id) {
            if (customer.withdraw(account_num, amount)) {
                std::cout << "Withdrawal successful." << std::endl;
            } else {
                std::cout << "Account not found or insufficient balance." << std::endl;
            }
            return;
        }
    }
    std::cout << "Customer not found." << std::endl;
}

double BankSystem::get_total_balance() const 
{
    double total_balance = 0.0;
    for (const auto& customer : m_customers) {
        const std::vector<Account*>& accounts = customer.get_accounts();
        for (const auto& account : accounts) {
            total_balance += account->get_balance();
        }
    }
    return total_balance;
}