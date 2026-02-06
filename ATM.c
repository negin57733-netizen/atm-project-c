include <stdio.h>
#include <stdlib.h>

int main() {

    int enteredpin;
    int choice, i;
    char firstname[20];
    char lastName[20];
    double balance = 0;
    double amount;
    int pin = 1234;
    int accountActive = 0;
    double transactions[10];  
    int pinTries = 0;
    int transactionCount = 0;

    while (pinTries < 3) {
        printf("Enter PIN: ");
        scanf("%d", & enteredpin);

        if (enteredpin == pin) {
            break;
        } else {
            pinTries++;
            printf("Incorrect PIN!\n");
        }
    }

    if (pinTries == 3) {
        printf("Entering the wrong password more than the allowed number of times");
        return 0;
    }

    do {
        printf(" ATM MENU\n");
        printf("1. Create Account\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. Change PIN\n");
        printf("5. View Balance\n");
        printf("6. Transaction History\n");
        printf("7. delete account\n");
        printf("8. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        if (choice == 1) {
            if (accountActive == 1) {
                printf("Account already exists\n");
            } else {
                printf("Enter firstname: ");
                scanf("%s", firstname);

                printf("Enter Last Name: ");
                scanf("%s", lastName);

                printf("Enter Balance: ");
                scanf("%lf", &balance);

                accountActive = 1;
                transactionCount = 0;

                printf("Account creation was successful\n");
            }
        }

        else if (choice == 2) {
            if (accountActive == 0) {
                printf("No account found\n");
            } else {
                printf("amount of money to deposit: ");
                scanf("%lf", &amount);

                if (amount > 0) {
                    balance += amount;

                    if (transactionCount < 10) {
                        transactions[transactionCount++] = amount;
                    }

                    printf("Deposit successful\n");
                } else {
                    printf("it is Invalid\n");
                }
            }
        }

        else if (choice == 3) {
            if (accountActive == 0) {
                printf("No account found\n");
            } else {
                printf("Enter withdrawal amount: ");
                scanf("%lf", &amount);

                if (amount > 0 && amount <= balance) {
                    balance -= amount;

                    if (transactionCount < 10) {
                        transactions[transactionCount++] = -amount;
                    }

                    printf("harvesting was successful\n");
                } else {
                    printf("insufficient inventory\n");
                }
            }
        }

        else if (choice == 4) {
            printf("Enter current PIN: ");
            scanf("%d", &enteredpin);

            if (enteredpin == pin) {
                printf("Enter new PIN: ");
                scanf("%d", &pin);
                printf("PIN changed successfully!\n");
            } else {
                printf("Wrong PIN!\n");
            }
        }

        else if (choice == 5) {
            if (accountActive == 1) {
                printf("Current Balance: %.2lf\n", balance);
            } else {
                printf("No account found\n");
            }
        }

        else if (choice == 6) {
            if (transactionCount == 0) {
                printf("No transactions yet.\n");
            } else {
                printf("Last Transactions:\n");
                for (i = 0; i < transactionCount; i++) {
                    printf("%d: %.2lf\n", i + 1, transactions[i]);
                }
            }
        }

        else if (choice == 7) {
            if (accountActive == 0) {
                printf("No account found\n");
            } else {
                printf("Enter the PIN: ");
                scanf("%d", &enteredpin);

                if (enteredpin == pin) {
                    accountActive = 0;
                    balance = 0;
                    firstname[0] = '\0';
                    lastName[0] = '\0';

                    for (i = 0; i < 10; i++) {
                        transactions[i] = 0;
                    }
                    transactionCount = 0;

                    printf("Account deleted successfully\n");
                } else {
                    printf("Account not deleted\n");
                }
            }
        }

        else if (choice == 8) {
            printf("Exiting program safely\n");
        }

        else {
            printf("Invalid choice\n");
        }

    } while (choice != 8);

    return 0;
}
