#ifndef managementH
#define managementH

typedef struct
{
    char op;
    double amount;
} Operation;

typedef struct
{
    long accNum;
    double Balance;
    char accHolderName[100];
    char email[100];
    int numOfOps;
    Operation Operations[300];
} Account;






#endif