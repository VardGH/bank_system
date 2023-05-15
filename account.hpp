#ifndef ACCOUNT_HPP
#define ACCOUNT_HPP

class Account {
public:
    Account(int account_num, double balance = 0.0) 
        : m_account_num(account_num)
        , m_balance(balance)
    {
    }

public:
    //getters
    double get_balance() const;
    int get_account_num() const;
    void get_account_info() const;
    //
    void deposit(const double amount);
    bool withdraw(const double amount);

private:
    int m_account_num;
    double m_balance;
};

#endif // ACCOUNT_HPP