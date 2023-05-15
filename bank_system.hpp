#ifndef BANKSYSTEM_HPP
#define BANKSYSTEM_HPP

#include "customer.hpp"
#include <vector>
#include <string>

class BankSystem {
public:
    BankSystem() {}

public:
    //getters
    double get_total_balance() const; 
    void get_customer_info(const int customer_id) const;
    const std::vector<Customer>& get_customers() const;
    //
    void create_customer(const std::string& name, const std::string& address, const std::string& contact_info, const int customer_id);
    void create_account(const int customer_id, const int account_num, const double initial_balance = 0.0);
    void deposit(const int customer_id, const int account_num, const double amount);
    void withdraw(const int customer_id, const int account_num, const double amount);

private:
    std::vector<Customer> m_customers;
};

#endif // BANKSYSTEM_HPP