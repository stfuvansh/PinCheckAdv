#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
int pin = 1234;
int inputPin;
int attempts = 0;
float balance = 1000.0;
float depositAmount;
float withdrawAmount;
bool checkPin(int inputPin);
void mainMenu();
void checkBalance();
void deposit();
void withdraw();
int main() {
while (attempts < 3) {
    printf("Enter your pin: ");
    scanf("%d", &inputPin);
    if (checkPin(inputPin) == true) {
        printf("Access granted.\n");
        break;
    } else {
        printf("Incorrect pin. Try again.\n");
    }
    attempts++;
}
if (attempts == 3) {
    printf("Too many incorrect attempts. Access denied.\n");
    return 0;
}
mainMenu();
return 0;
}
bool checkPin(int inputPin) {
    if (inputPin == pin) {
        return true;
    } else {
        return false;
    }
}
void mainMenu() {
    int choice = 0;
    while (choice !=4) {

        printf("Main Menu:\n");
        printf("1. Check Balance\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                checkBalance();
                break;
            case 2:
                deposit();
                break;
            case 3:
                withdraw();
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}
void checkBalance() {
    printf("Your current balance is: $%.2f\n", balance);
}
void deposit() {
    printf("Enter amount to deposit: ");
    scanf("%f", &depositAmount);
    if (depositAmount > 0) {
        balance += depositAmount;
        printf("Deposit Successful. New balance is $%.2f\n", balance);
    } else {
        printf("Please enter a valid amount.\n");
    }
}
void withdraw() {
    printf("Enter amount to withdraw: ");
    scanf("%f", &withdrawAmount);
    if (withdrawAmount > 0 && withdrawAmount <= balance) {
        balance -= withdrawAmount;
        printf("Withdrawal Successful. New balance is $%.2f\n", balance);
    } else if (withdrawAmount > balance) {
        printf("Insufficient funds.\n");
    } else {
        printf("Please enter a valid amount.\n");
    }
}