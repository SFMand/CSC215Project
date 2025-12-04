#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "accman.h"

/*            WE NEED TO SEPERATE IT INOT HEADER FILES             */

Account accounts[1000];
int accCount = 0;

int findAccByNum(long accNo)
{
    int i;
    for (i = 0; i < accCount; i++)
    {
        if (accounts[i].accNum == accNo)
            return i;
    }
    return -1;
}
/* method to write everything to the text file after modifying the accounts array*/
int SaveAccountsInFile(const char *txtfile)
{

    FILE *f;
    f = fopen(txtfile, "w");
    if (f == NULL)
        return 0;

    int i;
    for (i = 0; i < accCount; i++)
    {
        fprintf(f, "%ld\n", accounts[i].accNum);
        fprintf(f, "%s\n", accounts[i].accHolderName);
        fprintf(f, "%lf\n", accounts[i].Balance);
        fprintf(f, "%s\n", accounts[i].email);
        fprintf(f, "%d\n", accounts[i].numOfOps);

        int j;
        for (j = 0; j < accounts[i].numOfOps; j++)
        {
            fprintf(f, "%c\n", accounts[i].Operations[j].op);
            fprintf(f, "%lf\n", accounts[i].Operations[j].amount);
        }
    }
    fclose(f);
    return 1;
}

void addAccount(const char *txtfile)
{
    Account a;
    int valid;
    do
    {
        printf("Enter your Account Number:");
        scanf("%ld", &a.accNum);
        clearinputbuffer();
        valid = isValidNumber(a.accNum); /* check if the account number is unique*/
    } while (!valid);

    do
    {
        printf("Enter your Account Name:");
        fgets(a.accHolderName, sizeof(a.accHolderName), stdin);
        removeNewline(a.accHolderName);
        valid = isValidName(a.accHolderName); /* check if the account name is valid*/
    } while (!valid);

    do
    {
        printf("Enter your Account Balance:");
        scanf("%lf", &a.Balance);
        clearinputbuffer();
        valid = isValidBalance(a.Balance); /* check if the account balance is valid*/
    } while (!valid);

    do
    {
        printf("Enter your Account Email:");
        scanf("%s", a.email);
        clearinputbuffer();
        valid = isValidEmail(a.email); /* check if the account email is valid*/
    } while (!valid);
    a.numOfOps = 0;
    accounts[accCount] = a;
    accCount++;

    /* Save all accounts in file */
    SaveAccountsInFile(txtfile);

    printf("Account added successfully\n");
}

void UpdateAccount(const char *txtfile)
{
    int choice;
    long accN;
    printf("Account information update\n");

    printf("Enter the account number you want to update: ");
    scanf("%ld", &accN);
    clearinputbuffer();
    /* Find the account in the array */
    int index;
    if ((index = findAccByNum(accN)) >= 0)
    {
        printf("Do you want to update the :\n1-Account Number\n2-Account Name");
        scanf("%d", &choice);
        clearinputbuffer();
        if (choice == 1)
        {
            long newNum;
            do
            {
                printf("Enter the new account number: ");
                scanf("%ld", &newNum);
                clearinputbuffer();
            } while (!isValidNumToUpdate(newNum, accounts[index].accNum));
        }

        else if (choice == 2)
        {
            char newName[100];

            do
            {
                printf("Enter the new name: ");
                fgets(newName, sizeof(newName), stdin);
                removeNewline(newName);
            } while (!isValidName(newName));

            strcpy(accounts[index].accHolderName, newName);
            printf("Holder name updated successfully.\n");
        }

        else
        {
            printf("Invalid choice.\n");
            return;
        }

        /* Save all accounts in file */
        SaveAccountsInFile(txtfile);
    }
    else if (index == -1)
    {
        printf("Account not found\n");
        return;
    }
}

void deleteByAccountNumber(const char *txtfile)
{
    long accNum;
    int index, i;

    printf("Enter account number to delete: ");
    scanf("%ld", &accNum);
    clearinputbuffer();
    /* Find the account */
    if ((index = findAccByNum(accNum) >= 0))
    {
        /* Shift all accounts to the left */
        for (i = index; i < accCount - 1; i++)
        {
            accounts[i] = accounts[i + 1];
        }

        accCount--;
        /* Save all accounts in file */
        SaveAccountsInFile(txtfile);

        printf("Account deleted successfully\n");
    }
    else if (index == -1)
    {
        printf("Account not found\n");
        return;
    }
}

void deleteByHolderName(const char *txtfile)
{
    char name[100];
    int i, j;
    int found = 0;

    printf("Enter holder name to delete all related accounts: ");
    fgets(name, sizeof(name), stdin);
    removeNewline(name);

    for (i = 0; i < accCount; i++)
    {
        if (strcmp(accounts[i].accHolderName, name) == 0)
        {
            found = 1;

            /* Shift all accounts to the left  */
            for (j = i; j < accCount - 1; j++)
            {
                accounts[j] = accounts[j + 1];
            }

            accCount--;
            i--; /* we decrement the i to check the element after the element we deleted*/
        }
    }

    if (!found)
    {
        printf("No accounts found with that holder name\n");
        return; /*to leave the method*/
    }

    /* Save all accounts in file */
    SaveAccountsInFile(txtfile);
    printf("All accounts with this name deleted successfully\n");
}

void searchByAccountNumber()
{
    long accNum;

    printf("Enter account number to search: ");
    scanf("%ld", &accNum);
    clearinputbuffer();
    int i;

    if ((i = findAccByNum(accNum)) >= 0)
    {
        /* we found the account */

        printf("\n=== Account Details ===\n");
        printf("Account Number: %ld\n", accounts[i].accNum);
        printf("Holder Name: %s\n", accounts[i].accHolderName);
        printf("Balance: %.2lf\n", accounts[i].Balance);
        printf("Email: %s\n", accounts[i].email);
        printf("Num of Ops: %d\n", accounts[i].numOfOps);

        if (accounts[i].numOfOps > 0)
        {
            printf("Operations:\n");
            int j;
            for (j = 0; j < accounts[i].numOfOps; j++)
            {
                printf("#%d: %c  %.2lf\n", j + 1, accounts[i].Operations[j].op, accounts[i].Operations[j].amount);
            }
        }
        else
        {
            printf("This account has no operations\n");
        }

    }

    else if (i == -1)
    {
        printf("Account not found\n");
    }
}

void searchByHolderName()
{
    char name[100];
    int i;
    int found = 0;

    printf("Enter holder name to search: ");
    fgets(name, sizeof(name), stdin);
    removeNewline(name);

    printf("\n=== Accounts for Holder: %s ===\n", name);

    for (i = 0; i < accCount; i++)
    {
        if (strcmp(accounts[i].accHolderName, name) == 0)
        {
            found = 1;

            printf("\nAccount Number: %ld\n", accounts[i].accNum);
            printf("Balance: %.2lf\n", accounts[i].Balance);
            printf("Email: %s\n", accounts[i].email);
            printf("Num of Ops: %d\n", accounts[i].numOfOps);
        }
    }

    if (!found)
    {
        printf("No accounts found for this holder name.\n");
    }

    printf("==============================\n\n");
}
void displayAllAccounts()
{
    int i, j;

    if (accCount == 0)
    {
        printf("No accounts available.\n");
        return;
    }

    printf("\n===== All Accounts =====\n");

    for (i = 0; i < accCount; i++)
    {
        printf("\nAccount #%d:\n", i + 1);
        printf("Account Number: %ld\n", accounts[i].accNum);
        printf("Holder Name: %s\n", accounts[i].accHolderName);
        printf("Balance: %.2lf\n", accounts[i].Balance);
        printf("Email: %s\n", accounts[i].email);
        printf("Num of Operations: %d\n", accounts[i].numOfOps);

        if (accounts[i].numOfOps > 0)
        {
            printf("Operations:\n");
            for (j = 0; j < accounts[i].numOfOps; j++)
            {
                printf("  %c  %.2lf\n",
                       accounts[i].Operations[j].op,
                       accounts[i].Operations[j].amount);
            }
        }
        else
        {
            printf("No operations yet.\n");
        }
    }

    printf("========================\n\n");
}
void addOperation(const char *txtfile)
{
    long accNum;
    int index;
    double amount;
    char op;

    printf("Enter account number: ");
    scanf("%ld", &accNum);
    clearinputbuffer();

    index = findAccByNum(accNum);

    if (index == -1)
    {
        printf("Account not found.\n");
        return;
    }

    printf("Enter operation type (D for deposit, W for withdraw): ");
    scanf("%c", &op);
    clearinputbuffer();

    /* convert lowercase to uppercase */
    if (op >= 'a' && op <= 'z')
        op -= 32;

    if (op != 'D' && op != 'W')
    { /*not w or d*/
        printf("Invalid operation type.\n");
        return;
    }

    printf("Enter amount: ");
    scanf("%lf", &amount);
    clearinputbuffer();

    if (!isPositiveAmount(amount))
    {
        printf("Amount must be positive.\n");
        return;
    }

    /* Withdraw check */
    if (op == 'W' && amount > accounts[index].Balance)
    {
        printf("Insufficient balance.\n");
        return;
    }

    /* Apply operation */
    if (op == 'D')
        accounts[index].Balance += amount;
    else
        accounts[index].Balance -= amount;

    /* Store operation */
    accounts[index].Operations[accounts[index].numOfOps].op = op;
    accounts[index].Operations[accounts[index].numOfOps].amount = amount;
    accounts[index].numOfOps++;

    SaveAccountsInFile(txtfile);

    printf("Operation added successfully!\n");
}
void displaySpecificOperation()
{
    long accNum;
    char op;
    int index;
    int found = 0;
    int i;

    printf("Enter account number: ");
    scanf("%ld", &accNum);
    clearinputbuffer();

    index = findAccByNum(accNum);

    if (index == -1)
    {
        printf("Account not found.\n");
        return;
    }

    printf("Enter operation type to display (W or D): ");
    scanf("%c", &op);
    clearinputbuffer();

    /* convert to uppercase */
    if (op >= 'a' && op <= 'z')
        op -= 32;

    if (op != 'W' && op != 'D')
    {
        printf("Invalid operation type.\n");
        return;
    }

    printf("\n=== %c Operations for Account %ld ===\n", op, accNum);

    for (i = 0; i < accounts[index].numOfOps; i++)
    {
        if (accounts[index].Operations[i].op == op)
        {
            printf("%c  %.2lf\n",
                   accounts[index].Operations[i].op,
                   accounts[index].Operations[i].amount);
            found = 1;
        }
    }

    if (!found)
    {
        printf("No operations of this type found.\n");
    }

    printf("=============================\n\n");
}
void loadFile(const char *fileName)
{
    FILE *fptr = fopen(fileName, "r");
    Account a;
    int i;
    while (fscanf(fptr, "%ld\n", &(a.accNum)) == 1)
    {
        fscanf(fptr, "%s\n", a.accHolderName);
        fscanf(fptr, "%lf\n", &(a.Balance));
        fscanf(fptr, "%s\n", a.email);
        fscanf(fptr, "%d\n", &(a.numOfOps));

        for (i = 0; i < a.numOfOps; i++)
        {
            fscanf(fptr, "%c\n", &(a.Operations[i].op));
            fscanf(fptr, "%lf\n", &(a.Operations[i].amount));
        }
        accounts[accCount++] = a;
    }
    fclose(fptr);
}

int main()
{
    int choice;
    const char *filename = "accounts.txt";
    loadFile(filename);
    while (1)
    {
        printf("\n===== BANK ACCOUNT MANAGEMENT SYSTEM =====\n");
        printf("1. Add Account\n");
        printf("2. Update Account\n");
        printf("3. Delete Account by Number\n");
        printf("4. Delete Account by Holder Name\n");
        printf("5. Search Account by Number\n");
        printf("6. Search Account by Holder Name\n");
        printf("7. Display All Accounts\n");
        printf("8. Add Operation (Deposit / Withdraw)\n");
        printf("9. Display Specific Operation Type\n");
        printf("10. Exit\n");
        printf("Choose an option: ");

        scanf("%d", &choice);
        clearinputbuffer();

        switch (choice)
        {

        case 1:
            addAccount(filename);
            break;

        case 2:
            UpdateAccount(filename);
            break;

        case 3:
            deleteByAccountNumber(filename);
            break;

        case 4:
            deleteByHolderName(filename);
            break;

        case 5:
            searchByAccountNumber();
            break;

        case 6:
            searchByHolderName();
            break;

        case 7:
            displayAllAccounts();
            break;

        case 8:
            addOperation(filename);
            break;

        case 9:
            displaySpecificOperation();
            break;

        case 10:
            printf("Exiting program...\n");
            return 0;

        default:
            printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
