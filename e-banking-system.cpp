//e-Banking System
//By Vishal Jakhar

#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>
using namespace std;


string generateOTP(){
    srand(time(0));
    string otp;
    int randomNum;

    for(int i = 0; i < 4; i++){
        randomNum = rand() % 9;
        otp += to_string(randomNum);
    }
    
    return otp;
}

double deposit(double balance){
    double added = 0;
    cout << "enter the amount to be deposited: $";
    cin >> added;
    cout << "amount deposited." << endl;
    return balance+added;
}

double withdraw(double balance, string otp){
    double deducted = 0;
    string oneTimePass;
    string failed = "wrong otp.";

    cout << "enter the amount to be withdrawn: $";
    cin >> deducted;
    cout << "enter otp: ";
    cin >> oneTimePass;
    if(oneTimePass == otp){
        cout << "amount withdrawn." << endl;
        return balance-deducted;
    }
    else cout << "wrong otp. Transaction failed." << endl;
    return balance;
}

void checkBalance(double balance){
    cout << "balance: $" << balance << endl;
}

int main(){
    double balance = 0;
    int command;

    cout << "1. check balance." << endl
         << "2. deposit amount." << endl
         << "3. withdraw amount." << endl
         << "4. exit." << endl;
    
    while(true){
        cout << "enter a command: ";
        cin >> command;

        if(command == 0){
            cout << "1. check balance." << endl
                 << "2. deposit amount." << endl
                 << "3. withdraw amount." << endl
                 << "4. exit." << endl;
        }
        else if(command == 1){
            checkBalance(balance);
        }
        else if(command == 2){
            balance = deposit(balance);
        }
        else if(command == 3){
            string otp = generateOTP();
            cout << "Your OTP for transaction is: " << otp << endl;
            balance = withdraw(balance, otp);
        }
        else if(command == 4){
            cout << "Thank you.";
            break;
        }
        else {
            cout << "invalid command. Enter 0 to view the menu again." << endl;
        }
    }

    return 0;
}
