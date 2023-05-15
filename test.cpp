#include "test.hpp"
#include "bank_system.hpp"
#include <iostream>

void test_bank()
{
    BankSystem bank;

    bank.create_customer("Anna", "Main St", "anna@gmail.com", 1);
    bank.create_account(1, 10, 1100.0);
    bank.deposit(1, 10, 300.0);
    bank.withdraw(1, 10, 200.0);
    bank.get_customer_info(1);
    std::cout << "Total balance: " << bank.get_total_balance() << std::endl;

    std::cout << std::endl;

    bank.create_customer("John", "Main St1", "john@gmail.com", 2);
    bank.create_account(2, 2, 2000.0);
    bank.deposit(2, 2, 600.0);
    bank.withdraw(2, 2, 100.0);
    bank.get_customer_info(2);
    std::cout << "Total balance: " << bank.get_total_balance() << std::endl;
}