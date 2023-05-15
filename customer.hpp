#ifndef CUSTOMER_HPP
#define CUSTOMER_HPP

#include "account.hpp"
#include "string"
#include <vector>

class Customer
{
public:
     Customer(const std::string& name, const std::string& address, const std::string& contact_info, const int id)
        : m_name(name)
        , m_address(address)
        , m_contact_info(contact_info)
        , m_id(id)
    {
    }

    ~Customer()
    {
        m_accounts.clear();
    }

public:
    //getters
    std::string get_name() const;
    std::string get_address() const;
    std::string get_contact() const;
    int get_id() const;
    const std::vector<Account*>& get_accounts() const;
    void get_info() const;
    //
    void create_account(const int account_num, const double initial_balance = 0.0);
    bool deposit(const int account_num, const double amount);
    bool withdraw(const int account_num, const double amount); 

private:
    std::string m_name;
    std::string m_address;
    std::string m_contact_info;
    int m_id;
    std::vector<Account*> m_accounts;
};

#endif  // CUSTOMER_HPP