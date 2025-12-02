#ifndef AccManagementH
#define AccManagementH

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
extern Account accounts[1000];
extern int accCount;
void clearinputbuffer();
void removeNewline(char *);

int isValidNumber(long);
int isValidNumToUpdate(long, long);
int isValidName(const char *);
int isValidEmail(const char *);
int isValidBalance(double);
int isPositiveAmount(double);




#endif