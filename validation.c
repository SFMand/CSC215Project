#include <stdio.h>
#include "accman.h"

/*clears the '\n' so we can use fgets to read names with spaces, because otherwise fgets will read empty names since it stops at '\n' , '\n' comes from the scanf before the fgets */
void clearinputbuffer()
{
    int c;
    c = getchar();
    while (c != '\n' && c != EOF)
    {
        c = getchar();
    }
}
void removeNewline(char *str)
{
    int i = 0;
    if (str == NULL)
        return;
    while (str[i] != '\0')
    {
        if (str[i] == '\n')
        {
            str[i] = '\0';
            return;
        }
        i++;
    }
}

int isValidNumber(long accNum)
{

    /* Check if another account has this number */
    int i;
    for (i = 0; i < accCount; i++)
    {
        if (accounts[i].accNum == accNum)
        {
            printf("Account number is already taken");
            return 0;
        }
    }
    return 1; /* Valid */
}

int isValidNumToUpdate(long newNum, long oldNum)
{
    int i;

    /* If the new number is the same as the old number, it's valid */
    if (newNum == oldNum)
        return 1;

    /* Check if another account has this number */
    for (i = 0; i < accCount; i++)
    {
        if (accounts[i].accNum == newNum)
        {
            printf("Account number is already taken\n");
            return 0;
        }
    }

    return 1; /* Valid */
}
int isValidName(const char *name)
{
    if (name == NULL)
    {
        printf("name is empty");
        return 0;
    }
    if (name[0] == '\0')
        return 0;
    int i = 0;
    while (name[i] != '\0')
    {
        char c = name[i];
        if (!((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c == ' ')))
            return 0;
        i++;
    }
    return 1;
}
int isValidEmail(const char *email)
{
    if (email == NULL)
    {
        printf("email is empty\n");
        return 0;
    }
    if (email[0] == '\0')
        return 0;
    const char *at;
    const char *dot;
    at = NULL;
    const char *p = email;
    while (*p != '\0')
    {
        if (*p == '@')
        {
            at = p;
            break;
        }
        p++;
    }
    if (at == NULL)
        return 0;
    if (at == email)
        return 0; /*check if @ is the first character*/
    dot = at + 1;
    while (*dot != '\0' && *dot != '.')
        dot++;
    if (*dot == '\0')
        return 0;
    if (dot == at + 1)
    {
        printf("the dot '.' cannot be right after the @, must have @gmail or @hotmail etc. before the dot.\n");
        return 0;
    }
    int countAfterDot = 0;
    const char *q = dot + 1;
    while (*q != '\0')
    { /*to ensure having atleast 2 chars after the dot , like .sa or .com etc.*/
        countAfterDot++;
        q++;
    }
    if (countAfterDot < 2)
    {
        printf("must have at least 2 characters after the dot, for example .sa or .com etc.\n");
        return 0;
    }
    return 1;
}
int isValidBalance(double balance)
{
    if (balance >= 200)
        return 1;
    else
        return 0;
}
int isPositiveAmount(double amount)
{
    return amount > 0.0;
}
