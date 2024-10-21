#include <iostream>
#include <string>

// Interface for Bank Account
class BankAccount {
public:
    virtual void withdraw(double amount) = 0;
    virtual ~BankAccount() = default;
};

// The Real BankAccount class (actual account operations)
class RealBankAccount : public BankAccount {
private:
    double balance;

public:
    RealBankAccount(double initialBalance) : balance(initialBalance) {}

    void withdraw(double amount) override {
        if (amount <= balance) {
            balance -= amount;
            std::cout << "Withdrawal successful! New balance: " << balance << std::endl;
        } else {
            std::cout << "Insufficient balance. Current balance: " << balance << std::endl;
        }
    }

    double getBalance() const {
        return balance;
    }
};

// The Proxy class for Bank Account
class BankAccountProxy : public BankAccount {
private:
    RealBankAccount* realAccount;
    std::string pin;

    bool authenticate(const std::string& enteredPin) const {
        return enteredPin == pin;
    }

public:
    BankAccountProxy(RealBankAccount* account, const std::string& accountPin) 
        : realAccount(account), pin(accountPin) {}

    void withdraw(double amount) override {
        std::string enteredPin;
        std::cout << "Enter PIN: ";
        std::cin >> enteredPin;

        if (authenticate(enteredPin)) {
            realAccount->withdraw(amount);  // Delegate the call to the real account
        } else {
            std::cout << "Authentication failed. Cannot perform withdrawal." << std::endl;
        }
    }
};

// Client code
int main() {
    // Real bank account with initial balance
    RealBankAccount realAccount(500.0);
    
    // Proxy bank account with security control
    BankAccountProxy proxy(&realAccount, "1234");

    // Client interacts with the proxy, which controls access to the real account
    proxy.withdraw(100);  // Requires PIN authentication

    proxy.withdraw(400);  // Again requires PIN

    proxy.withdraw(200);  // Try withdrawing more than balance

    return 0;
}
