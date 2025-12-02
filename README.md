# CSC215 Project
## Project Description: Bank Account Management System
This project involves developing an ATM system for a bank. The system enables
users to perform various banking operations, withdraw and deposit money. The
system should track transaction statistics for each account. The data to be stored
in a text file.
This project is to be completed in groups of 3 students (No more No less). Each
team should have a leader, the leader responsibility is to submit the work on
behalf of the team, please when submitting the project to LMS, make sure you
write the team members names and IDs, only one student submits the project for
his group.
## Provided Data:
### Account as struct:
- Account Number as long integer (unique number).
- Balance as double.
- Account holder name as string.
- email as string (check the format of the email).
- Number of operations.
- Array of operations.
### Operation as struct:
- Operation as char, w for withdraw and d for deposit.
- Amount of the operation as double.
### Provided Services:
1. Add Account: The account must have complete data (Number, holder name,
balance 200 SR as minimum, number of operations 0, create array of operation
with 300 as size.
2. Update Account: Existing account in the text file can be updated with new
information, update only account number or holder name. Make sure the account
number is unique.
3. Delete Account by account number: Users can delete account from the system
text file based on the account number.
4. Delete Accounts by holder name: Users can delete all accounts from the
system text file related to a holder name.
5. Search Account by number: Users can search for account by account number
to retrieve their details.
6. Search Account by holder name: Users can search for account by holder name
to retrieve their details in an array of accounts.
7. Display All Accounts: The system provides an option to display all accounts
stored in the account text file.
8. Add operation: The system provides an option to add operation (deposit D,
withdraw W), the operation could be capitol or small, do not forget to update
information in the account.
9. Display a specific operation done for an account, the user will enter the account
number and operation (W or D).
Data Validation: before saving a record to the account text file, a record criteria
must be met
1. Name Validation: The system must validate the holder name to ensure that
only alphabetical characters are accepted.
2. Email Address Validation: Similarly, the system validates email addresses to
ensure they follow the correct format (e.g., example@email.com). It checks for
the presence of "@" and "." symbols in the email address.
3. Amount Validation: The system must accept only positive (0 not allowed)
amount for deposit or withdraw.
Project Implementation:
The project will involve creating structures to represent account information,
implementing functions for adding, updating, deleting, searching, and displaying
accounts. Data validation logic will be integrated into the functions for adding and
updating accounts to ensure the integrity of the stored data.

File handling
operations must be used to save and retrieve account records from a text file,
providing persistence to the accounts data.

By completing this project, students will gain practical experience in C
programming, file handling, data validation techniques, and basic data structure
manipulation. They will develop a deeper understanding of managing data in real-
world applications and enhance their problem-solving skills.
Project Submission Guidelines:
As part of the Bank Account Management System project, you are required to
submit both the source code and a report detailing the functionality of each
function along with a sample run demonstrating the usage of all services
provided. 
### Below are the submission guidelines:
1. Source Code: You must submit the complete source code of your Bank Account
Management System implemented in C programming language. Ensure that the
code is well-commented, following best coding practices, and is properly
organized for readability and maintainability.
2. Report: Prepare a detailed report that describes each function implemented in
your project. 
#### The report should include:
- A cover page: containing course code, section, names and IDs of
group members.
- Introduction: Briefly describe the purpose and features of the Bank
Account Management System project.
- Function Descriptions: Provide a detailed explanation of each
function implemented in your project. Describe the purpose of each
function, its parameters, return type (if any), and the logic behind its
implementation.
- Data Validation: Explain the data validation techniques used in the
project, specifically focusing on holder name validation and email
address validation.
- File Handling: Describe how file handling operations are
implemented to save and retrieve account records from a text file.
- Sample Run: Include a sample run of your program demonstrating
the usage of all services provided by the Bank Account Management
System. This should cover adding accounts, updating accounts,
deleting accounts, searching accounts, and displaying all accounts.
- Submission Format: Submit both the source code files (.c and .h files)
and the report document (in PDF format) through the LMS.
- Deadline: Ensure that your submission is made before the deadline
specified. Late submissions may incur penalties as per the course
policy.
- Evaluation Criteria: Your project will be evaluated based on the
completeness of functionality, code quality, adherence to coding
standards, clarity of the report, and correctness of the sample run.
- Academic Integrity: Remember to uphold academic integrity
throughout the development and submission process. Plagiarism or
unauthorized collaboration with peers is strictly prohibited.
