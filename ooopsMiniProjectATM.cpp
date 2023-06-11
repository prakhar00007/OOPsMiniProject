#include <iostream>
#include <string>
#include <conio.h>

using namespace std;

class atm
{
private:
    long int accountNumber;
    string userName;
    int pinNumber;
    double balance;
    string mobileNumber;

public:
    void setData(long int accountNumber_a, string userName_a, int pinNumber_a, double balance_a, string mobileNumber_a) // Setter function to set data in private variables of class atm 
    {
        accountNumber = accountNumber_a;
        userName = userName_a;
        pinNumber = pinNumber_a;
        balance = balance_a;
        mobileNumber = mobileNumber_a;
    }

    long int getAccountNumber() // Getter function to get data from private variables of class atm
    {
        return accountNumber;
    }

    string getUserName() // Getter function to get data from private variables of class atm
    {
        return userName;
    }

    int getPinNumber() // Getter function to get data from private variables of class atm
    {
        return pinNumber;
    }

    double getBalance() // Getter function to get data from private variables of class atm
    {
        return balance;
    }

    string getMobileNumber() // Getter function to get data from private variables of class atm
    {
        return mobileNumber;
    }
};

int main()
{
    int choice = 0; // For selecting options in the ATM
    int enterPin;  // To take input of pin number
    long int enterAccountNumber;  // To take input of account number
    atm user1;  // Object of class atm
    user1.setData(1234567, "Prakhar", 1234, 10000, "9939792643");  // Setting data in the object user1 

    bool isLoggedIn = false;        // To check if user is logged in or not 

    while (1)  // Infinite loop to keep the user logged in until he/she chooses to exit
    {
        cout << "****Welcome to ATM*****" << endl;  
        cout << "Enter Your Account Number: ";
        cin >> enterAccountNumber;  // Taking input of account number from user

        // Check if account number is valid 
        if (enterAccountNumber == user1.getAccountNumber())  
        {
            cout << "Enter Your Pin Number: ";
            cin >> enterPin;

            // Check if pin number is valid
            if (enterPin == user1.getPinNumber())
            {
                isLoggedIn = true;
                break; // Break out of the login loop
            }
            else
            {
                cout << "Invalid Pin Number" << endl;
            }
        }
        else
        {
            cout << "Invalid Account Number" << endl;
            break; // Break out of the login loop
        }
    }

    if (isLoggedIn)  // If user is logged in then only show the options 
    {
        while (1)
        {
            double amount = 0;
            string oldMobileNumber, newMobileNumber;

            cout << "****Welcome to ATM*****" << endl;
            cout << "Select Options" << endl;
            cout << "1. Check Balance" << endl;
            cout << "2. Cash Withdraw" << endl;
            cout << "3. Show User Details" << endl;
            cout << "4. Update Mobile Number" << endl;
            cout << "5. Exit" << endl;
            cin >> choice;


            switch (choice)  // Switch case to select the options
            {
              case 1:
        cout << "Your Bank balance is: " << user1.getBalance() << endl;
        break;

    case 2:
        cout << "Enter the amount to withdraw: ";
        cin >> amount;
        if (amount > 0 && amount <= user1.getBalance()) // Check if amount is valid
        {
            user1.setData(user1.getAccountNumber(), user1.getUserName(), user1.getPinNumber(), user1.getBalance() - amount, user1.getMobileNumber());
            cout << "Please collect your cash" << endl;
            cout << "Available balance is: " << user1.getBalance() << endl;
        }
        else
        {
            cout << "Invalid amount" << endl;
        }
        break;

    case 3:
        cout << "User Details are: " << endl;
        cout << "Account Number: " << user1.getAccountNumber() << endl;
        cout << "User Name: " << user1.getUserName() << endl;
        cout << "Balance: " << user1.getBalance() << endl;
        cout << "Mobile Number: " << user1.getMobileNumber() << endl;
        break;

    case 4:
        cout << "Enter old mobile number: ";
        cin >> oldMobileNumber;
        if (oldMobileNumber == user1.getMobileNumber())  // Check if old mobile number is valid
        {
            cout << "Enter new mobile number: ";
            cin >> newMobileNumber;
            user1.setData(user1.getAccountNumber(), user1.getUserName(), user1.getPinNumber(), user1.getBalance(), newMobileNumber);
            cout << "Mobile Number Updated Successfully" << endl;
        }
        else
        {
            cout << "Incorrect old mobile number" << endl;
        }
        break;

    case 5:
        cout << "Thank You for using our ATM" << endl;  // Exit message
        isLoggedIn = false;
        break;

    default:
        cout << "Enter Valid Choice" << endl;
        break;
}
            if (!isLoggedIn)
            {
                break; // Break out of the main loop
            }
        }
    }

    return 0;  
}
