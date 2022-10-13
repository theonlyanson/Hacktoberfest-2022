#pragma warning(disable: 4996)
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <conio.h>
using namespace std;

int NUMBER_OF_ACCOUNTS, NUMBER_OF_SAV_ACCOUNTS, NUMBER_OF_CHECK_ACCOUNTS, NUMBER_OF_LOAN_ACCOUNTS;
string CURRENT_ID, CURRENT_CUSTOMER;

struct Date
{
	int day, month, year;
};

class Account {
protected:
	//data members of account class 
	double balance; Date date_Of_Depoit, date_Of_Withdraw;
	bool validAmount(double balance);
public:
	//member funtion of account class
	Account();
	Account(double balance, Date date1, Date date2);
	void setBalance(double balance);
	void setDepositDate(Date date);
	double getBalance();
	void deposit(double amount);
	void withdraw(double amount);
	double balanceEnquiry();
};

class Saving_Account : public Account
{
	double monthly_interest;
public:
	//member funtion of  Saving_Account class
	Saving_Account();
	Saving_Account(double balance, double monthly_interest, Date date1, Date date2);
	void setMonthly_interest(double monthly_interest);
	void deposit(double amount);
	void withdraw(double amount);
	double balanceEnquiry();
	void saveDetails(string ID);
};

class loan_account :public Account
{
	//data member of  Saving_Account class
	double interest_rate, principle_amount, monthly_duration, loan_balance, monthly_interest;
	Date loan_date;
	Date loan_paydate;

public:
	//member funtion of  Saving_Account class
	loan_account();
	loan_account(double principle_amount, double interest_rate, double monthly_duration, double loan_balance, double monthly_interest, Date date1, Date date2);
	void setLoanDate(Date date);
	void setLoan(double loan);
	void setDuration(double time);
	void getMonthlyInterest();
	void Loan();
	void installment();
	void saveDetails(string ID);
};
class Checking_Account : public Account {
	//member funtion of  Saving_Account class
	double credit_limit;
public:
	//member funtion of  Checking_Account class
	Checking_Account();
	Checking_Account(double balance, Date date1, Date date2);
	void setCreditLimit(double credit_limit);
	double getCreditLimit();
	void deposit(double amount);
	void withdraw(double amount);
	void saveDetails(string ID);
};

class customer {
private:
	//data member of  customer class
	string name, address, phone, email, customerID, CaccountID[50], SaccountID[50], LaccountID[50];
	Checking_Account checkingAccount[50]; Saving_Account savingAccount[50]; loan_account loanAccount[50];
	bool validName(string name);
	bool validAddress(string address);
	bool validPhone(string phone);
	bool validID(string ID);
	int no = 0;
public:
	//member funtion of  customer class
	customer();
	customer(string name, string address, string phone, string email, string customerID, string SaccountID, string LaccountID, string CaccountID);
	void setName(string name);
	void setAddress(string address);
	void setPhone(string phone);
	bool loadCustomerInfo(string ID);
	void loadCustomerAccounts(string ID);
	bool loadLoanAccount(string ID);
	bool loadSavingAccount(string ID);
	bool loadCheckingAccount(string ID);
	void addAccount(string ID1, string ID2);
	void input();
	void saveCustomers();
	void newCustomer();
	void loadCustomers();
	void updateCustomerInfo(string ID);
	void updateAccount(string ID1, string ID2);
	void delete_customer();
	void deleteAccounts(string);
	bool delete_account(string, string);
	void showRecords(string ID);
};
customer Customers[50];

//----------[Account Class body]----------
//-----------------(start)----------------
Account::Account() : balance(0) {
	date_Of_Depoit = { 0, 0, 0 };
	date_Of_Withdraw = { 0, 0, 0 };
}
// to set date of dopsit and date of withdraw
Account::Account(double balance, Date date1, Date date2) : balance(balance) {
	date_Of_Depoit = date1;
	date_Of_Withdraw = date2;
}
//check validity of amount
bool Account::validAmount(double balance) {
	if (balance > 0) {
		return true;
	}
	return false;
}
/// set balance that is entered by user

void Account::setBalance(double balance) {
	while (true) {
		bool r = validAmount(balance);
		if (r == true) {
			this->balance = balance;
			break;
		}
		else {
			cout << "You entered an invalid balance amount\nEnter the amount again: ";
			cin >> balance;
		}
	}
}
//setting date of depositing
void Account::setDepositDate(Date date) {
	this->date_Of_Depoit.day = date.day;
	this->date_Of_Depoit.month = date.month;
	this->date_Of_Depoit.year = date.year;
}
//getting balence from user
double Account::getBalance() {
	return this->balance;
}
//in this ,amount is deposited means amount is added in user existing account
void Account::deposit(double amount)
{
	this->balance = this->balance + amount;
	cout << "Amount of " << amount << " has been deposit SUCCESSFULLY in your account\n";
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);			//taking date from system
	date_Of_Depoit.day = tm.tm_mday;			//saving in date of deposit
	date_Of_Depoit.month = tm.tm_mon + 1;
	date_Of_Depoit.year = tm.tm_year + 1900;
	string ID[20], C_ID[20], type[20]; double money[20]; Date date[20];
	ifstream fin; int i = 0;
	fin.open("accountTransactions.txt");			//to read previous account transactions
	while (!fin.eof()) {
		getline(fin, C_ID[i], ','); fin.ignore();
		getline(fin, ID[i], ','); fin.ignore();
		fin >> date[i].day; fin.ignore(date[i].day, '-');
		fin >> date[i].month; fin.ignore(date[i].month, '-');
		fin >> date[i].year; fin.ignore(date[i].year, ','); fin.ignore();
		getline(fin, type[i], ','); fin.ignore(); fin >> money[i]; fin.ignore(money[i], '\n');
		i++;
	}
	fin.close();
	ofstream fout;
	fout.open("accountTransactions.txt");			//to output account transactions in txt
	for (int s = 0; s < i; s++) {
		if (s < i - 1) {
			fout << C_ID[s] << ", " << ID[s] << ", " << date[s].day << "-" << date[s].month << "-" << date[s].year << ", " << type[s] << ", " << money[s] << endl;
		}
		else {
			fout << CURRENT_CUSTOMER << ", " << CURRENT_ID << ", " << date_Of_Depoit.day << "-" << date_Of_Depoit.month << "-" << date_Of_Depoit.year << ", " << "Deposit" << ", " << amount << endl;
		}
	}
	fout.close();
}
//in this ,amount is  withdraw means amount is  minus from user amount
void Account::withdraw(double amount) {
	while (true) {
		bool r = validAmount(amount);
		if (r == true) {
			break;
		}
		else {
			cout << "The amount you entered is invalid\nEnter the amount again: ";
			cin >> amount;
		}
	}
	if (amount <= this->balance) {
		this->balance = this->balance - amount;
		cout << "Amount of " << amount << " has been withdrawn SUCCESSFULLY from your account\n";
		time_t t = time(NULL);
		struct tm tm = *localtime(&t);					//take date from system
		date_Of_Withdraw.day = tm.tm_mday;
		date_Of_Withdraw.month = tm.tm_mon + 1;
		date_Of_Withdraw.year = tm.tm_year + 1900;
		string ID[20], C_ID[20], type[20]; double money[20]; Date date[20];
		ifstream fin; int i = 0;
		fin.open("accountTransactions.txt");			//to read previous account transaction
		while (!fin.eof()) {
			getline(fin, C_ID[i], ','); fin.ignore();
			getline(fin, ID[i], ','); fin.ignore();
			fin >> date[i].day; fin.ignore(date[i].day, '-');
			fin >> date[i].month; fin.ignore(date[i].month, '-');
			fin >> date[i].year; fin.ignore(date[i].year, ','); fin.ignore();
			getline(fin, type[i], ','); fin.ignore(); fin >> money[i]; fin.ignore(money[i], '\n');
			i++;
		}
		fin.close();
		ofstream fout;
		fout.open("accountTransactions.txt");				//to output account transactions in txt
		for (int s = 0; s < i; s++) {
			if (s < i - 1) {
				fout << C_ID[s] << ", " << ID[s] << ", " << date[s].day << "-" << date[s].month << "-" << date[s].year << ", " << type[s] << ", " << money[s] << endl;
			}
			else {
				fout << CURRENT_CUSTOMER << ", " << CURRENT_ID << ", " << date_Of_Withdraw.day << "-" << date_Of_Withdraw.month << "-" << date_Of_Withdraw.year << ", " << "Widraw" << ", " << amount << endl;
			}
		}
		fout.close();
	}
	else {
		cout << "There is not enough balance in your account\n";
	}
}
double Account::balanceEnquiry() {
	return this->balance;
}
//----------[Account Class body]----------
//------------------(End)-----------------

//----------[Saving Account Class body]----------
//---------------------(start)-------------------
Saving_Account::Saving_Account() : monthly_interest(0) {				//definition of default constructor
	this->balance = 0;
	date_Of_Depoit = { 0, 0, 0 };
	date_Of_Withdraw = { 0, 0, 0 };
}
//setting  balance ,date of deposit and date of withdraw
Saving_Account::Saving_Account(double balance, double monthly_interest, Date date1, Date date2) : monthly_interest(monthly_interest) {
	this->balance = balance;
	date_Of_Depoit = date1;
	date_Of_Withdraw = date2;
}
//setting monthly interest
void Saving_Account::setMonthly_interest(double monthly_interest) {
	this->monthly_interest = monthly_interest;
}
void Saving_Account::deposit(double amount) 
{
	this->balance = this->balance + amount;
	cout << "Amount of " << amount << " has been deposit SUCCESSFULLY in your account\n";
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);				//taking date from system
	date_Of_Depoit.day = tm.tm_mday;
	date_Of_Depoit.month = tm.tm_mon + 1;
	date_Of_Depoit.year = tm.tm_year + 1900;

	ifstream fin; int i = 0;
	
	// -------------------------------
	string ID[20], C_ID[20], type[20]; double money[20]; Date date[20];
	//--------------------------
	
	fin.open("accountTransactions.txt");//to read and write account transactions in txt file
	
	while (!fin.eof())
	{
		getline(fin, C_ID[i], ','); 
		fin.ignore();
		getline(fin, ID[i], ','); 
		fin.ignore();
		fin >> date[i].day; 
		fin.ignore(date[i].day, '-');
		fin >> date[i].month; 
		fin.ignore(date[i].month, '-');
		fin >> date[i].year; 
		fin.ignore(date[i].year, ','); 
		fin.ignore();
		
		getline(fin, type[i], ','); 
		fin.ignore(); 
		fin >> money[i]; 
		fin.ignore(money[i], '\n');
		i++;
	}
	fin.close();
	
	ofstream fout;
	fout.open("accountTransactions.txt");
	for (int s = 0; s < i; s++) {
		if (s < i - 1) {
			fout << C_ID[s] << ", " << ID[s] << ", " << date[s].day << "-" << date[s].month << "-" << date[s].year << ", " << type[s] << ", " << money[s] << endl;
		}
		else {
			fout << CURRENT_CUSTOMER << ", " << CURRENT_ID << ", " << date_Of_Depoit.day << "-" << date_Of_Depoit.month << "-" << date_Of_Depoit.year << ", " << "Deposit" << ", " << amount << endl;
		}
	}
	fout.close();
}
//setting monthly interest
void Saving_Account::withdraw(double amount) {
	int duration;
	this->monthly_interest = 6;
	while (true) {
		bool r = validAmount(amount);
		if (r == true) {
			break;
		}
		else {
			cout << "The ammount you entered is invalid\nEnter the amount again: ";
			cin >> amount;
		}
	}
	time_t t = time(NULL);				//taking date from system
	struct tm tm = *localtime(&t);
	date_Of_Withdraw.day = tm.tm_mday;
	date_Of_Withdraw.month = tm.tm_mon + 1;
	date_Of_Withdraw.year = tm.tm_year + 1900;
	if (date_Of_Withdraw.year == date_Of_Depoit.year) {
		duration = date_Of_Withdraw.month - date_Of_Depoit.month;
	}
	else if (date_Of_Withdraw.year > date_Of_Depoit.year && date_Of_Withdraw.month == 1 && date_Of_Depoit.month == 12) {
		duration = (12 * (date_Of_Withdraw.year - date_Of_Depoit.year)) + 1;
	}
	else if (date_Of_Withdraw.year > date_Of_Depoit.year && date_Of_Withdraw.month != 1 && date_Of_Depoit.month != 12) {
		duration = (12 * (date_Of_Withdraw.year - date_Of_Depoit.year)) + date_Of_Withdraw.month - date_Of_Depoit.month;
	}
	this->balance = this->balance + ((this->balance * this->monthly_interest * duration) / 100);				//add monthly interest in balance
	if (amount <= this->balance) {
		this->balance = this->balance - amount;
		cout << "Amount of " << amount << " has been withdraw SUCCESSFULLY from your account\n";
		
		ifstream fin;
		int i = 0;
		
		string ID[20], C_ID[20], type[20]; double money[20]; Date date[20];
		fin.open("accountTransactions.txt");
		while (!fin.eof()) {																//to read and write account transactions in txt file
			getline(fin, C_ID[i], ','); fin.ignore();
			getline(fin, ID[i], ','); fin.ignore();
			fin >> date[i].day; fin.ignore(date[i].day, '-');
			fin >> date[i].month; fin.ignore(date[i].month, '-');
			fin >> date[i].year; fin.ignore(date[i].year, ','); fin.ignore();
			getline(fin, type[i], ','); fin.ignore(); fin >> money[i]; fin.ignore(money[i], '\n');
			i++;
		}
		fin.close();
		
		ofstream fout;
		fout.open("accountTransactions.txt");
		for (int s = 0; s < i; s++) {
			if (s < i - 1) {
				fout << C_ID[s] << ", " << ID[s] << ", " << date[s].day << "-" << date[s].month << "-" << date[s].year << ", " << type[s] << ", " << money[s] << endl;
			}
			else {
				fout << CURRENT_CUSTOMER << ", " << CURRENT_ID << ", " << date_Of_Withdraw.day << "-" << date_Of_Withdraw.month << "-" << date_Of_Withdraw.year << ", " << "Withdraw" << ", " << amount << endl;
			}
		}
		fout.close();
	}
	else {
		cout << "There is not enough balance in your account\n";
	}
}
double Saving_Account::balanceEnquiry() {
	return this->balance;
}
//this funtion basically setting detalis of saving account in text.file
void Saving_Account::saveDetails(string ID) {
	int i = 0;
	time_t t = time(NULL);				//taking date from system
	struct tm tm = *localtime(&t);
	string CustomerID[20], AccountID[20], Type[20];
	double balance[20], CLorIR[20], PAmount[20], time[20];
	Date date[20];
	ifstream fin;
	fin.open("Customers Accounts.txt");
	while (!fin.eof()) {
		if (i > 0) {
			fin.ignore();
		}
		getline(fin, CustomerID[i], ',');
		fin.ignore();
		getline(fin, AccountID[i], ',');
		fin.ignore();
		getline(fin, Type[i], ',');
		fin.ignore();
		fin >> balance[i];
		fin.ignore(balance[i], ',');
		fin.ignore();
		fin >> date[i].day;
		fin.ignore(date[i].day, '-');
		fin >> date[i].month;
		fin.ignore(date[i].month, '-');
		fin >> date[i].year;
		fin.ignore(date[i].year, ',');
		fin.ignore();
		fin >> CLorIR[i];
		fin.ignore(CLorIR[i], ',');
		fin.ignore();
		fin >> PAmount[i];
		fin.ignore(PAmount[i], ',');
		fin.ignore();
		fin >> time[i];
		i++;
	}
	fin.close();

	for (int s = 0; s < i - 1; s++) {
		if (ID == AccountID[s]) {					//if account id match store current balance and date passed by object in text file
			balance[s] = this->balance;
			date[s].day = tm.tm_mday;
			date[s].month = tm.tm_mon + 1;
			date[s].year = tm.tm_year + 1900;
		}
	}
	ofstream fout;
	fout.open("Customers Accounts.txt");
	//set information to text.file
	for (int s = 0; s < i - 1; s++) {
		fout << CustomerID[s] << ", " << AccountID[s] << ", " << Type[s] << ", " << balance[s] << ", " << date[s].day << "-" << date[s].month << "-" << date[s].year << ", " << CLorIR[s] << ", " << PAmount[s] << ", " << time[s] << endl;
	}
	fout.close();
}
//----------[Saving Account Class body]----------
//---------------------(End)---------------------

//----------[Loan Account Class body]----------
//--------------------(start)------------------
loan_account::loan_account() :principle_amount(0), interest_rate(0), monthly_duration(0), loan_balance(0), monthly_interest(0) {
	this->balance = 0;
	this->date_Of_Depoit = { 0, 0, 0 };
	this->date_Of_Withdraw = { 0, 0, 0 };
	loan_date = { 0, 0, 0 };
	loan_paydate = { 0, 0, 0 };
};
//it get loan date and pay_loan date
loan_account::loan_account(double principle_amount, double interest_rate, double monthly_duration, double loan_balance, double monthly_interest, Date date1, Date date2) :principle_amount(principle_amount), interest_rate(interest_rate), monthly_duration(monthly_duration), loan_balance(loan_balance), monthly_interest(monthly_interest) {
	this->balance = principle_amount;
	this->date_Of_Depoit = date1;
	this->date_Of_Withdraw = date2;
	loan_date = date1;
	loan_paydate = date2;
}
//monthly loan duration
void loan_account::setDuration(double time) {
	monthly_duration = time;
}
//getting loan date
void loan_account::setLoanDate(Date date) {
	loan_date.day = date.day;
	loan_date.month = date.month;
	loan_date.year = date.year;
}
//setting loan date
void loan_account::setLoan(double loan) {
	this->loan_balance = ((loan * 8 * 2) / 100) + loan;
}
//setting monthly interest rate
void loan_account::getMonthlyInterest() {
	this->monthly_interest = this->loan_balance / 24;
}
void loan_account::Loan()
{
	double amount;
	cout << "How much loan do you want to borrow? ";
	cin >> amount;
	char c;

	this->principle_amount = amount;
	interest_rate = principle_amount * 8 * 2;				//calculating interest rate of loan
	interest_rate /= 100;
	loan_balance = principle_amount + interest_rate;

	cout << "You have to pay " << loan_balance << " PKR within 2 years having 8% interest \nIf Agree press Y otherwise N (Y/N) : ";
label:
	cin >> c;

	if (c == 'Y' || c == 'y')
	{
		cout << "Loan has been deposited in your account.\n";

		time_t t = time(NULL);					//taking date from system
		struct tm tm = *localtime(&t);
		loan_date.day = tm.tm_mday;
		loan_date.month = tm.tm_mon + 1;
		loan_date.year = tm.tm_year + 1900;

		balance += amount;
		monthly_duration = 24;			//duration in months

		monthly_interest = loan_balance / 24;				//installment to be paid in a month
		cout << monthly_interest << " PKR will be depited from your account each month.\n";
		string ID[20], C_ID[20], type[20]; double money[20]; Date date[20];
		ifstream fin; int i = 0;
		fin.open("accountTransactions.txt");		//to read previous account transaction
		while (!fin.eof()) {
			getline(fin, C_ID[i], ','); fin.ignore();
			getline(fin, ID[i], ','); fin.ignore();
			fin >> date[i].day; fin.ignore(date[i].day, '-');
			fin >> date[i].month; fin.ignore(date[i].month, '-');
			fin >> date[i].year; fin.ignore(date[i].year, ','); fin.ignore();
			getline(fin, type[i], ','); fin.ignore(); fin >> money[i]; fin.ignore(money[i], '\n');
			i++;
		}
		fin.close();
		ofstream fout;
		fout.open("accountTransactions.txt");		//to output account transaction
		for (int s = 0; s < i; s++) {
			if (s < i - 1) {
				fout << C_ID[s] << ", " << ID[s] << ", " << date[s].day << "-" << date[s].month << "-" << date[s].year << ", " << type[s] << ", " << money[s] << endl;
			}
			else {
				fout << CURRENT_CUSTOMER << ", " << CURRENT_ID << ", " << loan_date.day << "-" << loan_date.month << "-" << loan_date.year << ", " << "Loan" << ", " << loan_balance << endl;
			}
		}
		fout.close();
	}

	else if (c == 'N' || c == 'n')			//if user don't agree with loan to be paid back
	{
		cout << "Your answer has been recorded.\n";
		principle_amount = 0;
		interest_rate = 0;
		loan_balance = 0;
	}

	else
	{
		cout << "Invalid Entry\nEnter Again: ";
		goto label;
	}

}
//it is installement of laon according to month
void loan_account::installment()
{
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);					//taking date from system
	loan_paydate.day = tm.tm_mday;
	loan_paydate.month = tm.tm_mon + 1;
	loan_paydate.year = tm.tm_year + 1900;
	if (loan_paydate.year == loan_date.year and loan_paydate.month - loan_date.month == 1 or loan_paydate.year > loan_date.year and (loan_date.month == 12 and loan_paydate.month == 1)) {
		if (monthly_duration == 0)
			cout << "All monthly installments has been debited.\n";
		else
		{
			if (balance > monthly_interest) {			//if you have balance to pay monthly installment
				balance -= monthly_interest;
				loan_balance -= monthly_interest;
				monthly_duration--;
				cout << "\nMonthly installment of this month has been depited.";
				cout << "\nYour Remaining balance is " << balance << " PKR and the remaining loan is " << loan_balance << " PKR." << endl;
				loan_date.day = loan_paydate.month;
				loan_date.month = loan_paydate.month;
				loan_date.year = loan_paydate.year;
				string ID[20], C_ID[20], type[20]; double money[20]; Date date[20];
				ifstream fin; int i = 0;
				fin.open("accountTransactions.txt");		//to read previous account transaction
				while (!fin.eof()) {
					getline(fin, C_ID[i], ','); fin.ignore();
					getline(fin, ID[i], ','); fin.ignore();
					fin >> date[i].day; fin.ignore(date[i].day, '-');
					fin >> date[i].month; fin.ignore(date[i].month, '-');
					fin >> date[i].year; fin.ignore(date[i].year, ','); fin.ignore();
					getline(fin, type[i], ','); fin.ignore(); fin >> money[i]; fin.ignore(money[i], '\n');
					i++;
				}
				fin.close();
				ofstream fout;
				fout.open("accountTransactions.txt");		//to output account transaction
				for (int s = 0; s < i; s++) {
					if (s < i - 1) {
						fout << C_ID[s] << ", " << ID[s] << ", " << date[s].day << "-" << date[s].month << "-" << date[s].year << ", " << type[s] << ", " << money[s] << endl;
					}
					else {
						fout << CURRENT_CUSTOMER << ", " << CURRENT_ID << ", " << loan_paydate.day << "-" << loan_paydate.month << "-" << loan_paydate.year << ", " << "Installment" << ", " << monthly_interest << endl;
					}
				}
				fout.close();
			}
			else
			{
				cout << "Your account is out of balance\nYou still have " << loan_balance << " PKR of loan remaining\n";
			}
		}
	}

}
//this funtion basically setting detalis of loan class in text.file

void loan_account::saveDetails(string ID) {
	int i = 0;
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	string CustomerID[20], AccountID[20], Type[20];
	double balance[20], CLorIR[20], PAmount[20], time[20];
	Date date[20];
	ifstream fin;
	fin.open("Customers Accounts.txt");			//read information from customer id
	while (!fin.eof()) {
		if (i > 0) {
			fin.ignore();
		}
		getline(fin, CustomerID[i], ',');
		fin.ignore();
		getline(fin, AccountID[i], ',');
		fin.ignore();
		getline(fin, Type[i], ',');
		fin.ignore();
		fin >> balance[i];
		fin.ignore(balance[i], ',');
		fin.ignore();
		fin >> date[i].day;
		fin.ignore(date[i].day, '-');
		fin >> date[i].month;
		fin.ignore(date[i].month, '-');
		fin >> date[i].year;
		fin.ignore(date[i].year, ',');
		fin.ignore();
		fin >> CLorIR[i];
		fin.ignore(CLorIR[i], ',');
		fin.ignore();
		fin >> PAmount[i];
		fin.ignore(PAmount[i], ',');
		fin.ignore();
		fin >> time[i];
		i++;
	}
	fin.close();

	for (int s = 0; s < i - 1; s++) {
		if (ID == AccountID[s]) {
			balance[s] = this->balance;
			date[s].day = tm.tm_mday;
			date[s].month = tm.tm_mon + 1;
			date[s].year = tm.tm_year + 1900;
			time[s] = this->monthly_duration;
			PAmount[s] = this->loan_balance;
		}
	}
	ofstream fout;					///write details in customer account txt file
	fout.open("Customers Accounts.txt");
	for (int s = 0; s < i - 1; s++) {
		fout << CustomerID[s] << ", " << AccountID[s] << ", " << Type[s] << ", " << balance[s] << ", " << date[s].day << "-" << date[s].month << "-" << date[s].year << ", " << CLorIR[s] << ", " << PAmount[s] << ", " << time[s] << endl;
	}
	fout.close();
}
//----------[Loan Account Class body]----------
//--------------------(End)--------------------

//----------[Checking_Account Class body]----------
//---------------------(start)---------------------
Checking_Account::Checking_Account() {
	this->balance = 0;
	this->credit_limit = 50000;
	this->date_Of_Depoit = { 0, 0, 0 };
	this->date_Of_Withdraw = { 0, 0, 0 };
}
//check date of depositand withdraw,and also there is credit limit
Checking_Account::Checking_Account(double balance, Date date1, Date date2) {
	this->balance = balance;
	this->credit_limit = 50000;
	this->date_Of_Depoit = date1;
	this->date_Of_Withdraw = date2;
}
//checking validity of credit limit
void Checking_Account::setCreditLimit(double credit_limit) {
	while (true) {
		bool r = validAmount(credit_limit);
		if (r == true) {
			this->credit_limit = credit_limit;
			break;
		}
		else {
			cout << "You have entered an invalid credit limit\nEnter again: ";
			cin >> credit_limit;
		}
	}
}
//getting credit limit 
double Checking_Account::getCreditLimit() {
	return this->credit_limit;
}
//when user enter amount for deposit and if the amount entered by user is less than credit limit, than add (credit limit + amount enter by user for deposit)
// and if amount is greter than credit limit than further operation

void Checking_Account::deposit(double amount) {
	while (true) {
		bool r = validAmount(amount);
		if (r == true) {
			if (this->credit_limit < 50000) {
				this->credit_limit = this->credit_limit + amount;
				if (this->credit_limit > 50000) {
					this->balance = this->balance + (this->credit_limit - 50000);
					cout << "Deposit SUCCESSFUL\n" << (this->credit_limit - 50000) << " PKR has been added to your total balance";
					this->credit_limit = 50000;
					cout << " & your credit limit is back to " << this->credit_limit << " PKR\n";
				}
				else {
					cout << "Deposit SUCCESSFUL\nCurrent blance is still " << this->balance << " PKR  but now your credit limit is " << this->credit_limit << " PKR\n";
				}
			}
			else {
				this->balance = this->balance + amount;
			}
			time_t t = time(NULL);
			struct tm tm = *localtime(&t);				//taking date rom system
			date_Of_Depoit.day = tm.tm_mday;
			date_Of_Depoit.month = tm.tm_mon + 1;
			date_Of_Depoit.year = tm.tm_year + 1900;
			string ID[20], C_ID[20], type[20]; double money[20]; Date date[20];
			ifstream fin; int i = 0;
			fin.open("accountTransactions.txt");		//to read and write account transactions in txt file
			while (!fin.eof()) {
				getline(fin, C_ID[i], ','); fin.ignore();
				getline(fin, ID[i], ','); fin.ignore();
				fin >> date[i].day; fin.ignore(date[i].day, '-');
				fin >> date[i].month; fin.ignore(date[i].month, '-');
				fin >> date[i].year; fin.ignore(date[i].year, ','); fin.ignore();
				getline(fin, type[i], ','); fin.ignore(); fin >> money[i]; fin.ignore(money[i], '\n');
				i++;
			}
			fin.close();
			ofstream fout;
			fout.open("accountTransactions.txt");
			for (int s = 0; s < i; s++) {
				if (s < i - 1) {
					fout << C_ID[s] << ", " << ID[s] << ", " << date[s].day << "-" << date[s].month << "-" << date[s].year << ", " << type[s] << ", " << money[s] << endl;
				}
				else {
					fout << CURRENT_CUSTOMER << ", " << CURRENT_ID << ", " << date_Of_Depoit.day << "-" << date_Of_Depoit.month << "-" << date_Of_Depoit.year << ", " << "Deposit" << ", " << amount << endl;
				}
			}
			fout.close();
			break;
		}
		else {
			cout << "You entered an invalid amount\nEnter again: ";
			cin >> amount;
		}
	}
}
//when user withdraw  amount from bank and if the amount entered by user is more than 
//thier current balance then remaining balance get from creit limit

void Checking_Account::withdraw(double amount) {
	double temp;
	while (true) {
		bool r = validAmount(amount);
		if (r == true) {
			if (amount > this->balance) {
				temp = amount - this->balance;
				if (temp > this->credit_limit) {
					cout << amount << " PKR exceeds your balance & credit limit\n";
					break;
				}
				else {
					this->credit_limit = this->credit_limit - temp;
					cout << amount << " PKR is withdrew SUCCESSFULLY\n";
				}
			}
			else {
				this->balance = this->balance - amount;
				cout << amount << " PKR is withdrew SUCCESSFULLY\n";
			}
			time_t t = time(NULL);
			struct tm tm = *localtime(&t);
			date_Of_Withdraw.day = tm.tm_mday;
			date_Of_Withdraw.month = tm.tm_mon + 1;
			date_Of_Withdraw.year = tm.tm_year + 1900;
			string ID[20], C_ID[20], type[20]; double money[20]; Date date[20];
			ifstream fin; int i = 0;
			fin.open("accountTransactions.txt");
			while (!fin.eof()) {
				getline(fin, C_ID[i], ','); fin.ignore();
				getline(fin, ID[i], ','); fin.ignore();
				fin >> date[i].day; fin.ignore(date[i].day, '-');
				fin >> date[i].month; fin.ignore(date[i].month, '-');
				fin >> date[i].year; fin.ignore(date[i].year, ','); fin.ignore();
				getline(fin, type[i], ','); fin.ignore(); fin >> money[i]; fin.ignore(money[i], '\n');
				i++;
			}
			fin.close();
			ofstream fout;
			fout.open("accountTransactions.txt");
			for (int s = 0; s < i; s++) {
				if (s < i - 1) {
					fout << C_ID[s] << ", " << ID[s] << ", " << date[s].day << "-" << date[s].month << "-" << date[s].year << ", " << type[s] << ", " << money[s] << endl;
				}
				else {
					fout << CURRENT_CUSTOMER << ", " << CURRENT_ID << ", " << date_Of_Withdraw.day << "-" << date_Of_Withdraw.month << "-" << date_Of_Withdraw.year << ", " << "Withdraw" << ", " << amount << endl;
				}
			}
			fout.close();
			break;
		}
		else {
			cout << "You entered an invalid amount\nEnter again: ";
			cin >> amount;
		}
	}
}
//this funtion basically setting detalis of checking account in text.file

void Checking_Account::saveDetails(string ID) {
	int i = 0;
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	string CustomerID[20], AccountID[20], Type[20];
	double balance[20], CLorIR[20], PAmount[20], time[20];
	Date date[20];
	ifstream fin;
	fin.open("Customers Accounts.txt");		//to read and write account's details  in txt file
	while (!fin.eof()) {
		if (i > 0) {
			fin.ignore();
		}
		getline(fin, CustomerID[i], ',');
		fin.ignore();
		getline(fin, AccountID[i], ',');
		fin.ignore();
		getline(fin, Type[i], ',');
		fin.ignore();
		fin >> balance[i];
		fin.ignore(balance[i], ',');
		fin.ignore();
		fin >> date[i].day;
		fin.ignore(date[i].day, '-');
		fin >> date[i].month;
		fin.ignore(date[i].month, '-');
		fin >> date[i].year;
		fin.ignore(date[i].year, ',');
		fin.ignore();
		fin >> CLorIR[i];
		fin.ignore(CLorIR[i], ',');
		fin.ignore();
		fin >> PAmount[i];
		fin.ignore(PAmount[i], ',');
		fin.ignore();
		fin >> time[i];
		i++;
	}
	fin.close();

	for (int s = 0; s < i - 1; s++) {
		if (ID == AccountID[s]) {
			balance[s] = this->balance;
			date[s].day = tm.tm_mday;
			date[s].month = tm.tm_mon + 1;
			date[s].year = tm.tm_year + 1900;
			CLorIR[s] = this->credit_limit;
		}
	}
	ofstream fout;
	fout.open("Customers Accounts.txt");
	for (int s = 0; s < i - 1; s++) {
		fout << CustomerID[s] << ", " << AccountID[s] << ", " << Type[s] << ", " << balance[s] << ", " << date[s].day << "-" << date[s].month << "-" << date[s].year << ", " << CLorIR[s] << ", " << PAmount[s] << ", " << time[s] << endl;
	}
	fout.close();
}
//----------[Checking Account Class body]----------
//----------------------(End)----------------------

//----------[customer Class body]------------------
//-----------------(start)-------------------------

//this funtion basically setting detalis of checking account in text.file
bool customer::validName(string name) {
	int s = 0;
	while (name[s] != 0) {
		if (s >= 0 and (name[s] >= 'A' and name[s] <= 'Z' or name[s] >= 'a' and name[s] <= 'z' or name[s] == ' ')) {
			s++;
		}
		else {
			return false;
		}
	}
	return true;
}
//getting address and also check its validity
bool customer::validAddress(string address) {
	int s = 0;
	while (address[s] != 0) {
		if (s >= 0 and (address[s] >= 'A' and address[s] <= 'Z' or address[s] >= 'a' and address[s] <= 'z' or address[s] >= '0' and address[s] <= '9' or address[s] == ',' or address[s] <= ' ')) {
			s++;
		}
		else {
			return false;
		}
	}
	if (s > 5) {
		return true;
	}
	else {
		return false;
	}
}
//getting phone_no and also check its validity
bool customer::validPhone(string phone) {
	int s = 0;
	while (phone[s] != 0) {
		if (s == 0 and phone[s] == '0' or s >= 1 and phone[s] >= '0' and phone[s] <= '9') {
			s++;
		}
		else {
			return false;
		}
	}
	if (phone.size() > 10) {
		return true;
	}
	else {
		return false;
	}
}
//getting phone_no and also check its validity
bool customer::validID(string ID) {
	int s = 0;
	while (ID[s] != 0) {
		if (ID[s] >= '0' and ID[s] <= '9') {
			s++;
		}
		else {
			return false;
		}
	}
	if (ID.size() >= 6) {
		return true;
	}
	else {
		return false;
	}
}
customer::customer() : name(""), address(""), phone(""), email(""), customerID("000000") {
	for (int s = 0; s < 50; s++) {
		this->SaccountID[s] = "0000000";
		this->CaccountID[s] = "0000000";
		this->LaccountID[s] = "0000000";
	}
}
customer::customer(string name, string address, string phone, string email, string customerID, string SaccountID, string LaccountID, string CaccountID) : name(name), address(address), phone(phone), email(email), customerID(customerID) {
	for (int s = 0; s < 50; s++) {
		this->SaccountID[s] = SaccountID;
		this->CaccountID[s] = CaccountID;
		this->LaccountID[s] = LaccountID;
	}
}
//getting name and also check its validity
void customer::setName(string name) {
	while (true) {
		bool r = validName(name);
		if (r == true) {
			this->name = name;
			break;
		}
		else {
			cout << "The name you entered is invalid\nEnter your name again: ";
			getline(cin, name);
		}
	}
}
//getting address and also check its validity
void customer::setAddress(string address) {
	while (true) {
		bool r = validAddress(address);
		if (r == true) {
			this->address = address;
			break;
		}
		else {
			cout << "The address you entered is invalid\nEnter your address again: ";
			getline(cin, address);
		}
	}
}
//getting phone and also check its validity 
void customer::setPhone(string phone) {
	while (true) {
		bool r = validPhone(phone);
		if (r == true) {
			this->phone = phone;
			break;
		}
		else {
			cout << "The phone number you entered is invalid\nEnter your phone number again: ";
			getline(cin, phone);
		}
	}
}
//this funtion basically setting detalis of customer account in text.file
bool customer::loadCustomerInfo(string ID) {

	for (int s = 0; s < no; s++) {
		if (ID == Customers[s].customerID) {
			this->customerID = ID; this->name = Customers[s].name; this->phone = Customers[s].phone; this->email = Customers[s].email; this->address = Customers[s].address;
			return true;
		}
	}
	return false;
}
//this funtion basically setting detalis of of laon in text.file
void customer::loadCustomerAccounts(string ID) {
	int i = 0;
	string CustomerID[20], AccountID[20], Type[20];
	double balance[20], CLorIR[20], PAmount[20], time[20];
	Date date[20];
	ifstream fin;
	fin.open("Customers Accounts.txt");				//read detils from customer accounts txt file
	while (!fin.eof()) {
		if (i > 0) {
			fin.ignore();
		}
		getline(fin, CustomerID[i], ',');
		fin.ignore();
		getline(fin, AccountID[i], ',');
		fin.ignore();
		getline(fin, Type[i], ',');
		fin.ignore();
		fin >> balance[i];
		fin.ignore(balance[i], ',');
		fin.ignore();
		fin >> date[i].day;
		fin.ignore(date[i].day, '-');
		fin >> date[i].month;
		fin.ignore(date[i].month, '-');
		fin >> date[i].year;
		fin.ignore(date[i].year, ',');
		fin.ignore();
		fin >> CLorIR[i];
		fin.ignore(CLorIR[i], ',');
		fin.ignore();
		fin >> PAmount[i];
		fin.ignore(PAmount[i], ',');
		fin.ignore();
		fin >> time[i];
		i++;
	}
	fin.close();
	int a = 0, b = 0, c = 0;
	for (int s = 0; s < i - 1; s++) {
		if (ID == CustomerID[s]) {				//if type is saving load info in saving account 
			if (Type[s] == "Saving") {
				this->SaccountID[a] = AccountID[s];
				savingAccount[a].setBalance(balance[s]);
				savingAccount[a].setDepositDate(date[s]);
				savingAccount[a].setMonthly_interest(CLorIR[s]);
				a++;
			}
			else if (Type[s] == "Checking") {				//if type is checking load info in checking account 
				this->CaccountID[b] = AccountID[s];
				checkingAccount[b].setBalance(balance[s]);
				checkingAccount[b].setDepositDate(date[s]);
				checkingAccount[b].setCreditLimit(CLorIR[s]);
				b++;
			}
			else if (Type[s] == "Loan") {				//if type is loan load info in loan account 
				this->LaccountID[c] = AccountID[s];
				loanAccount[c].setBalance(balance[s]);
				loanAccount[c].setLoanDate(date[s]);
				loanAccount[c].setLoan(PAmount[s]);
				loanAccount[c].getMonthlyInterest();
				loanAccount[c].setDuration(time[s]);
				c++;
			}
		}
	}
	NUMBER_OF_SAV_ACCOUNTS = a;
	NUMBER_OF_CHECK_ACCOUNTS = b;
	NUMBER_OF_LOAN_ACCOUNTS = c;
	NUMBER_OF_ACCOUNTS = NUMBER_OF_SAV_ACCOUNTS + NUMBER_OF_CHECK_ACCOUNTS + NUMBER_OF_LOAN_ACCOUNTS;
}
//load info from loan accounts array
bool customer::loadLoanAccount(string ID) {
	int flag = 0;
	for (int s = 0; s < NUMBER_OF_LOAN_ACCOUNTS; s++) {
		flag = 1;
		if (ID == this->LaccountID[s]) {
			CURRENT_ID = ID;
			while (true) {
				char op;
				system("cls");
				cout << "* * * * * * * * * * [Bank Management System] * * * * * * * * * *\n";
				cout << "- Press 1 to Deposit\n";
				cout << "- Press 2 to Withdraw\n";
				cout << "- Press 3 to Get Loan\n";
				cout << "- Press 4 to Pay installment\n";
				cout << "- Press 5 to Check blance\n";
				cout << "- Press 6 to To exit\n";
				cout << "Input: ";
				cin >> op;
				double amount;
				if (op == '1') {
					cout << "Enter the amount of money you want to deposit: ";
					cin >> amount;
					loanAccount[s].deposit(amount);
					system("pause");
				}
				else if (op == '2') {
					cout << "Enter the amount you want to withdraw: ";
					cin >> amount;
					loanAccount[s].withdraw(amount);
					system("pause");
				}
				else if (op == '3') {
					loanAccount[s].Loan();
					system("pause");
				}
				else if (op == '4') {
					loanAccount[s].installment();
					system("pause");
				}
				else if (op == '5') {
					cout << "Account Blance: " << loanAccount[s].balanceEnquiry() << " PKR " << endl;
					system("pause");
				}
				else if (op == '0') {
					loanAccount[s].saveDetails(ID);
					return true;
				}
				else {
					cout << "You entered an invalid option\nEnter again: ";
					cin >> op;
				}
			}
		}
	}
	return false;
}
bool customer::loadSavingAccount(string ID) {						//load info from saving account array
	int flag = 0;
	for (int s = 0; s < NUMBER_OF_SAV_ACCOUNTS; s++) {
		flag = 1;
		if (ID == this->SaccountID[s]) {
			CURRENT_ID = ID;
			while (true) {
				char op;
				system("cls");
				cout << "* * * * * * * * * * [Bank Management System] * * * * * * * * * *\n";
				cout << "- Press 1 to Deposit\n";
				cout << "- Press 2 to Withdraw\n";
				cout << "- Press 3 to Check blance\n";
				cout << "- Press 0 to To exit\n";
				cout << "Input: ";
				cin >> op;
				double amount;
				if (op == '1') {
					cout << "Enter the amount of money you want to deposit: ";
					cin >> amount;
					savingAccount[s].deposit(amount);
					system("pause");
				}
				else if (op == '2') {
					cout << "Enter the amount you want to withdraw: ";
					cin >> amount;
					savingAccount[s].withdraw(amount);
					system("pause");
				}
				else if (op == '3') {
					cout << "Account Blance: " << savingAccount[s].balanceEnquiry() << " PKR " << endl;
					system("pause");
				}
				else if (op == '0') {
					savingAccount[s].saveDetails(ID);
					return true;
				}
				else {
					cout << "You entered an invalid option\nEnter again: ";
					cin >> op;
				}
			}
		}
	}
	return false;
}
bool customer::loadCheckingAccount(string ID) {					//load info from checking account array
	int flag = 0;
	for (int s = 0; s < NUMBER_OF_CHECK_ACCOUNTS; s++) {
		flag = 1;
		if (ID == this->CaccountID[s]) {
			CURRENT_ID = ID;
			while (true) {
				char op;
				system("cls");
				cout << "* * * * * * * * * * [Bank Management System] * * * * * * * * * *\n";
				cout << "- Press 1 to Deposit\n";
				cout << "- Press 2 to Withdraw\n";
				cout << "- Press 3 to Check remaining Credit Limit\n";
				cout << "- Press 4 to Check blance\n";
				cout << "- Press 0 to to exit\n";
				cout << "Input: ";
				cin >> op;
				double amount;
				if (op == '1') {
					cout << "Enter the amount of money you want to deposit: ";
					cin >> amount;
					checkingAccount[s].deposit(amount);
					system("pause");
				}
				else if (op == '2') {
					cout << "Enter the amount you want to withdraw: ";
					cin >> amount;
					checkingAccount[s].withdraw(amount);
					system("pause");
				}
				else if (op == '3') {
					cout << "Remaining Credit limit: " << checkingAccount[s].getCreditLimit() << " PKR" << endl;
					system("pause");
				}
				else if (op == '4') {
					cout << "Account Blance: " << checkingAccount[s].balanceEnquiry() << " PKR " << endl;
					system("pause");
				}
				else if (op == '0') {
					checkingAccount[s].saveDetails(ID);
					return true;
				}
				else {
					cout << "You entered an invalid option\nEnter again: ";
					cin >> op;
				}
			}
		}
	}
	return false;
}
void customer::updateAccount(string ID1, string ID2) {		//update info given in accounts
	int i = 0, flag = 1;
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	string CustomerID[20], AccountID[20], Type[20];
	double balance[20], CLorIR[20], PAmount[20], time[20];
	Date date[20];
	ifstream fin;
	fin.open("Customers Accounts.txt");
	while (!fin.eof()) {
		if (i > 0) {
			fin.ignore();
		}
		getline(fin, CustomerID[i], ',');
		fin.ignore();
		getline(fin, AccountID[i], ',');
		fin.ignore();
		getline(fin, Type[i], ',');
		fin.ignore();
		fin >> balance[i];
		fin.ignore(balance[i], ',');
		fin.ignore();
		fin >> date[i].day;
		fin.ignore(date[i].day, '-');
		fin >> date[i].month;
		fin.ignore(date[i].month, '-');
		fin >> date[i].year;
		fin.ignore(date[i].year, ',');
		fin.ignore();
		fin >> CLorIR[i];
		fin.ignore(CLorIR[i], ',');
		fin.ignore();
		fin >> PAmount[i];
		fin.ignore(PAmount[i], ',');
		fin.ignore();
		fin >> time[i];
		i++;
	}
	fin.close();
	for (int s = 0; s < i - 1; s++) {
		if (ID1 == CustomerID[s] and ID2 == AccountID[s]) {
			flag = 1;
			char op;
			while (true) {
				system("cls");
				cout << "* * * * * * * * * * [Bank Management System] * * * * * * * * * *\n";
				cout << "- Press 1 to update the type of the Account\n";
				cout << "- Press 2 to update the total balance in the Account\n";
				cout << "- Press 0 to exit\n";
				cout << "Input: ";
				cin >> op;
				if (op == '1') {
					if (Type[s] == "Checking") {
						char op1;
						system("cls");
						cout << "* * * * * * * * * * [Bank Management System] * * * * * * * * * *\n";
						cout << "To what type you want to change your Checking Account to?\n";
						cout << "- Press 1 for Saving\n";
						cout << "- Press 2 for Loan\n";
						cout << "- Press 0 to go back\n";
						cout << "Input: ";
						cin >> op1;
						while (true) {
							if (op1 == '1') {
								Type[s] = "Saving";
								cout << "Account type updated\n";
								system("pause");
								break;
							}
							else if (op1 == '2') {
								Type[s] = "Loan";
								cout << "Account type updated\n";
								system("pause");
								break;
							}
							else if (op1 == '0') {
								break;
							}
							else {
								cout << "You entered an invalid option\nEnter again: ";
								cin >> op;
							}
						}
					}
					else if (Type[s] == "Saving") {
						char op1;
						system("cls");
						cout << "* * * * * * * * * * [Bank Management System] * * * * * * * * * *\n";
						cout << "To what type you want to change your Saving Account to?\n";
						cout << "- Press 1 for Checking\n";
						cout << "- Press 2 for Loan\n";
						cout << "- Press 0 to go back\n";
						cout << "Input: ";
						cin >> op1;
						while (true) {
							if (op1 == '1') {
								Type[s] = "Checking";
								cout << "Account type updated\n";
								system("pause");
								break;
							}
							else if (op1 == '2') {
								Type[s] = "Loan";
								cout << "Account type updated\n";
								system("pause");
								break;
							}
							else if (op1 == '0') {
								break;
							}
							else {
								cout << "You entered an invalid option\nEnter again: ";
								cin >> op;
							}
						}
					}
					else {
						char op1;
						system("cls");
						cout << "* * * * * * * * * * [Bank Management System] * * * * * * * * * *\n";
						cout << "To what type you want to change your Loan Account to?\n";
						cout << "- Press 1 for Checking\n";
						cout << "- Press 2 for Saving\n";
						cout << "- Press 0 to go back\n";
						cout << "Input: ";
						cin >> op1;
						while (true) {
							if (op1 == '1') {
								Type[s] = "Checking";
								cout << "Account type updated\n";
								system("pause");
								break;
							}
							else if (op1 == '2') {
								Type[s] = "Saving";
								cout << "Account type updated\n";
								system("pause");
								break;
							}
							else if (op1 == '0') {
								break;
							}
							else {
								cout << "You entered an invalid option\nEnter again: ";
								cin >> op;
							}
						}
					}
				}
				else if (op == '2') {
					system("cls");
					cout << "* * * * * * * * * * [Bank Management System] * * * * * * * * * *\n";
					cout << "Enter the amount you want to change your current Account balance to: ";
					cin >> balance[s];
					while (true) {
						if (balance[s] >= 0) {
							cout << "Account balance updated\n";
							system("pause");
							break;
						}
						else {
							cout << "You entered an invalid amount\nEnter again: ";
							cin >> balance[s];
						}
					}
				}
				else if (op == '0') {
					break;
				}
				else {
					cout << "You entered an invalid option\nEnter again: ";
					cin >> op;
				}
			}
			break;
		}
		else {
			flag = 0;
		}
	}
	if (flag == 0) {
		cout << "The Account ID you entered doesnot exist\n";
		system("pause");
		return;
	}
	ofstream xout;
	xout.open("Customers Accounts.txt");
	for (int s = 0; s < i; s++) {
		if (date[s].day > 0 and date[s].day <= 31) {
			xout << CustomerID[s] << ", " << AccountID[s] << ", " << Type[s] << ", " << balance[s] << ", " << date[s].day << "-" << date[s].month << "-" << date[s].year << ", " << CLorIR[s] << ", " << PAmount[s] << ", " << time[s] << endl;
		}
	}
	xout.close();
}
//function to add a new account 
void customer::addAccount(string ID1, string ID2) {
	int i = 0;
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	string CustomerID[20], AccountID[20], Type[20];
	double balance[20], CLorIR[20], PAmount[20], time[20];
	Date date[20];
	ifstream fin;
	fin.open("Customers Accounts.txt");				//to read details from customer accounts txt 
	while (!fin.eof()) {
		if (i > 0) {
			fin.ignore();
		}
		getline(fin, CustomerID[i], ',');
		fin.ignore();
		getline(fin, AccountID[i], ',');
		fin.ignore();
		getline(fin, Type[i], ',');
		fin.ignore();
		fin >> balance[i];
		fin.ignore(balance[i], ',');
		fin.ignore();
		fin >> date[i].day;
		fin.ignore(date[i].day, '-');
		fin >> date[i].month;
		fin.ignore(date[i].month, '-');
		fin >> date[i].year;
		fin.ignore(date[i].year, ',');
		fin.ignore();
		fin >> CLorIR[i];
		fin.ignore(CLorIR[i], ',');
		fin.ignore();
		fin >> PAmount[i];
		fin.ignore(PAmount[i], ',');
		fin.ignore();
		fin >> time[i];
		i++;
	}
	fin.close();
	for (int s = 0; s < i - 1 or ID2 == AccountID[s]; s++) {
		if (ID2 == AccountID[s]) {
			cout << "This Account ID already exists\nPlease Enter another Account ID: ";
			cin >> ID2;
			s = -1;
		}
	}
	char op;
	system("cls");
	cout << "* * * * * * * * * * [Bank Management System] * * * * * * * * * *\n";
	cout << "What type of Account you want to make\n";
	cout << "- Press 1 to Checking Account\n";
	cout << "- Press 2 to Saving Account\n";
	cout << "- Press 3 to Loan Account\n";
	cout << "- Press 0 to To exit\n";
	cout << "Input: ";
	cin >> op;
	while (true) {
		if (op == '1') {
			CustomerID[i] = ID1;
			AccountID[i] = ID2;
			cout << "Enter the amount with which you want to start your account: ";
			cin >> PAmount[i];
			balance[i] = PAmount[i];
			date[i].day = tm.tm_mday;
			date[i].month = tm.tm_mon + 1;
			date[i].year = tm.tm_year + 1900;
			CLorIR[i] = 50000;
			time[i] = -1;
			Type[i] = "Checking";
			cout << "Account created\n";
			NUMBER_OF_CHECK_ACCOUNTS++;
			ofstream xout;
			xout.open("Customers Accounts.txt");					//write details in customer accounts txt file 
			for (int s = 0; s < i; s++) {
				if (date[s].day > 0 and date[s].day <= 31) {
					xout << CustomerID[s] << ", " << AccountID[s] << ", " << Type[s] << ", " << balance[s] << ", " << date[s].day << "-" << date[s].month << "-" << date[s].year << ", " << CLorIR[s] << ", " << PAmount[s] << ", " << time[s] << endl;
				}
				else if (s == i - 1) {
					xout << CustomerID[i] << ", " << AccountID[i] << ", " << Type[i] << ", " << balance[i] << ", " << date[i].day << "-" << date[i].month << "-" << date[i].year << ", " << CLorIR[i] << ", " << PAmount[i] << ", " << time[i] << endl;
				}
			}
			xout.close();
			system("pause");
			break;
		}
		else if (op == '2') {
			CustomerID[i] = ID1;
			AccountID[i] = ID2;
			cout << "Enter the amount with which you want to start your account: ";
			cin >> PAmount[i];
			balance[i] = PAmount[i];
			date[i].day = tm.tm_mday;
			date[i].month = tm.tm_mon + 1;
			date[i].year = tm.tm_year + 1900;
			CLorIR[i] = 6;
			time[i] = -1;
			Type[i] = "Saving";
			cout << "Account created\n";
			NUMBER_OF_SAV_ACCOUNTS++;
			ofstream xout;
			xout.open("Customers Accounts.txt");
			for (int s = 0; s < i; s++) {
				if (date[s].day > 0 and date[s].day <= 31) {
					xout << CustomerID[s] << ", " << AccountID[s] << ", " << Type[s] << ", " << balance[s] << ", " << date[s].day << "-" << date[s].month << "-" << date[s].year << ", " << CLorIR[s] << ", " << PAmount[s] << ", " << time[s] << endl;
				}
				else if (s == i - 1) {
					xout << CustomerID[i] << ", " << AccountID[i] << ", " << Type[i] << ", " << balance[i] << ", " << date[i].day << "-" << date[i].month << "-" << date[i].year << ", " << CLorIR[i] << ", " << PAmount[i] << ", " << time[i] << endl;
				}
			}
			xout.close();
			system("pause");
			break;
		}
		else if (op == '3') {
			CustomerID[i] = ID1;
			AccountID[i] = ID2;
			cout << "Enter the amount with which you want to start your account: ";
			cin >> balance[i];
			PAmount[i] = 0;
			date[i].day = tm.tm_mday;
			date[i].month = tm.tm_mon + 1;
			date[i].year = tm.tm_year + 1900;
			CLorIR[i] = 8;
			time[i] = 0;
			Type[i] = "Loan";
			cout << "Account created\n";
			NUMBER_OF_LOAN_ACCOUNTS++;
			ofstream xout;
			xout.open("Customers Accounts.txt");
			for (int s = 0; s < i; s++) {
				if (date[s].day > 0 and date[s].day <= 31) {
					xout << CustomerID[s] << ", " << AccountID[s] << ", " << Type[s] << ", " << balance[s] << ", " << date[s].day << "-" << date[s].month << "-" << date[s].year << ", " << CLorIR[s] << ", " << PAmount[s] << ", " << time[s] << endl;
				}
				else if (s == i - 1) {
					xout << CustomerID[i] << ", " << AccountID[i] << ", " << Type[i] << ", " << balance[i] << ", " << date[i].day << "-" << date[i].month << "-" << date[i].year << ", " << CLorIR[i] << ", " << PAmount[i] << ", " << time[i] << endl;
				}
			}
			xout.close();
			system("pause");
			break;
		}
		else {
			cout << "You entered an invalid option\nInput again: ";
			cin >> op;
		}
	}
}
bool customer::delete_account(string ID1, string ID2)
{
	//delete customer's account
	int i = 0, count = 0;
	string CustomerID[20], AccountID[20], Type[20];
	double balance[20], CLorIR[20], PAmount[20], time[20];
	Date date[20];
	ifstream fin;
	fin.open("Customers Accounts.txt");
	while (!fin.eof())
	{
		if (i > 0)
			fin.ignore();
		getline(fin, CustomerID[i], ',');
		fin.ignore();
		getline(fin, AccountID[i], ',');
		fin.ignore();
		getline(fin, Type[i], ',');
		fin.ignore();
		fin >> balance[i];
		fin.ignore(balance[i], ',');
		fin.ignore();
		fin >> date[i].day;
		fin.ignore(date[i].day, '-');
		fin >> date[i].month;
		fin.ignore(date[i].month, '-');
		fin >> date[i].year;
		fin.ignore(date[i].year, ',');
		fin.ignore();
		fin >> CLorIR[i];
		fin.ignore(CLorIR[i], ',');
		fin.ignore();
		fin >> PAmount[i];
		fin.ignore(PAmount[i], ',');
		fin.ignore();
		fin >> time[i];
		i++;
	}
	fin.close();
	ofstream fout;						//to write new account in txt file
	fout.open("Customers Accounts.txt");
	for (int s = 0; s < i - 1; s++) {
		if (CustomerID[s] == ID1)
		{
			if (AccountID[s] == ID2)
				count++;
			else
				fout << CustomerID[s] << ", " << AccountID[s] << ", " << Type[s] << ", " << balance[s] << ", " << date[s].day << "-" << date[s].month << "-" << date[s].year << ", " << CLorIR[s] << ", " << PAmount[s] << ", " << time[s] << endl;

		}
		else
			fout << CustomerID[s] << ", " << AccountID[s] << ", " << Type[s] << ", " << balance[s] << ", " << date[s].day << "-" << date[s].month << "-" << date[s].year << ", " << CLorIR[s] << ", " << PAmount[s] << ", " << time[s] << endl;

	}
	fout.close();
	if (count > 0)
		return 1;
	else
		return 0;
}
void customer::showRecords(string ID1) {
	string ID[20], C_ID[20], type[20]; double money[20]; Date date[20];
	ifstream fin; int i = 0;
	fin.open("accountTransactions.txt");							//show account transactions to admin
	while (!fin.eof()) {
		getline(fin, C_ID[i], ','); fin.ignore();
		getline(fin, ID[i], ','); fin.ignore();
		fin >> date[i].day; fin.ignore(date[i].day, '-');
		fin >> date[i].month; fin.ignore(date[i].month, '-');
		fin >> date[i].year; fin.ignore(date[i].year, ','); fin.ignore();
		getline(fin, type[i], ','); fin.ignore(); fin >> money[i]; fin.ignore(money[i], '\n');
		i++;
	}
	fin.close();
	int count = 0;
	cout << "Account ID, Date, Type, Amount:\n";
	for (int s = 0; s < i - 1; s++) {
		if (ID1 == C_ID[s]) {
			count++;
			cout << "\t\t\t\t" << ID[s] << ", " << date[s].day << "-" << date[s].month << "-" << date[s].year << ", " << type[s] << ", " << money[s] << " PKR " << endl;
		}
	}
	if (count == 0) {
		cout << "\t\t\t\t" << "[No Record]\n";
	}
	system("pause");
}
void customer::input() {
	string ID1, ID2;
	system("cls");
	cout << "* * * * * * * * * * [Bank Management System] * * * * * * * * * *\n";
	cout << "Enter your Customer ID\n\t or\nEnter 0 to log out\nInput: ";
	cin >> ID1;
	while (true) {
		bool r = loadCustomerInfo(ID1);				//load customers info
		if (r == true) {
			loadCustomerAccounts(ID1);						// load customer accounts
			CURRENT_CUSTOMER = ID1;
			char op;
			system("cls");
			cout << "* * * * * * * * * * [Bank Management System] * * * * * * * * * *\n";
			cout << "Which account do you want to access\n";
			cout << "- Press 1 to Checking Account\n";
			cout << "- Press 2 to Saving Account\n";
			cout << "- Press 3 to Loan Account\n";
			cout << "- Press 4 to add a new Account\n";
			cout << "- Press 5 to update an of your Account\n";
			cout << "- Press 6 to delete your existing Account\n";
			cout << "- Press 7 to see all your transactions\n";
			cout << "- Press 0 to To exit\n";
			cout << "Enter 1, 2, 3 or 4 for respective options\nInput: ";
			cin >> op;
			if (op == '1') {
				system("cls");
				cout << "* * * * * * * * * * [Bank Management System] * * * * * * * * * *\n";
				cout << "Enter the Account ID\n\tor\nEnter 0 to go back:\nEnter ";
				cin >> ID2;
				while (true) {
					bool r = loadCheckingAccount(ID2);
					if (r == true or ID2 == "0") {
						break;
					}
					else {
						cout << "Account ID not available\nEnter Account ID again: ";
						cin >> ID2;
					}
				}
			}
			else if (op == '2') {
				system("cls");
				cout << "* * * * * * * * * * [Bank Management System] * * * * * * * * * *\n";
				cout << "Enter the Account ID\n\tor\nEnter 0 to go back\nEnter: ";
				cin >> ID2;
				while (true) {
					bool r = loadSavingAccount(ID2);
					if (r == true or ID2 == "0") {
						break;
					}
					else {
						cout << "Account ID not available\nEnter Account ID again: ";
						cin >> ID2;
					}
				}
			}
			else if (op == '3') {
				system("cls");
				cout << "* * * * * * * * * * [Bank Management System] * * * * * * * * * *\n";
				cout << "Enter the Account ID\n\tor\nEnter 0 to go back\nEnter: ";
				cin >> ID2;
				while (true) {
					bool r = loadLoanAccount(ID2);
					if (r == true or ID2 == "0") {
						break;
					}
					else {
						cout << "Account ID not available\nEnter Account ID again: ";
						cin >> ID2;
					}
				}
			}
			else if (op == '4') {
				system("cls");
				cout << "* * * * * * * * * * [Bank Management System] * * * * * * * * * *\n";
				cout << "Enter the Account ID you want to set: ";
				cin >> ID2;
				addAccount(ID1, ID2);
			}
			else if (op == '5') {
				system("cls");
				cout << "* * * * * * * * * * [Bank Management System] * * * * * * * * * *\n";
				cout << "Enter the Account ID you want to Update: ";
				cin >> ID2;
				updateAccount(ID1, ID2);
			}
			else if (op == '6') {
				system("cls");
				cout << "* * * * * * * * * * [Bank Management System] * * * * * * * * * *\n";
				cout << "Enter the Account ID you want to delete or 0 to exit:  ";
			ag:
				cin >> ID2;
				if (ID2 != "0")
				{
					bool h = delete_account(ID1, ID2);
					if (h == 1)
					{
						cout << "Account deleted SUCCESSFULLY." << endl;
						cout << "Press any key to continue...\n";
						getch();
					}
					else
					{
						cout << "This ID doesn't Exist .Try Again: ";
						goto ag;
					}
				}
				else
				{
					system("cls");
					cout << "* * * * * * * * * * [Bank Management System] * * * * * * * * * *\n";
					break;
				}

			}
			else if (op == '7') {
				showRecords(ID1);
			}
			else if (op == '0') {
				system("cls");
				cout << "* * * * * * * * * * [Bank Management System] * * * * * * * * * *\n";
				cout << "Enter your Customer ID\n\tor\nEnter 0 to log out\nInput: ";
				cin >> ID1;
			}
			else {
				cout << "You entered an in valid option\nEnter again: ";
				cin >> op;
			}
		}
		else if (ID1 == "0") {
			system("cls");
			cout << "* * * * * * * * * * [Bank Management System] * * * * * * * * * *\n";
			break;
		}
		else {
			cout << "There no Customer ID " << ID1 << "\nPlease enter a valid ID: ";
			cin >> ID1;
		}
	}
}
void customer::saveCustomers()
{
	ofstream fout;
	fout.open("Customer info.txt");
	for (int i = 0; i < no; i++)
	{
		if (Customers[i].customerID != "\0")
		{
			fout << Customers[i].customerID << ", " << Customers[i].name << ", ";
			fout << Customers[i].address << ", " << Customers[i].phone << ", " << Customers[i].email << " ";
			fout << endl;
		}
	}
	fout.close();
}

void customer::newCustomer()
{
	cin.ignore();
	cout << "Enter your name: ";
name:
	getline(cin, Customers[no].name);
	bool namE = validName(Customers[no].name);
	if (namE == 0)
	{
		cout << "Invalid!\nEnter Again: ";
		goto name;
	}
	cout << "Enter the customer ID you want to set : ";
id:
	cin >> Customers[no].customerID;
	for (int i = 0; i < no; i++)
	{
		if (Customers[no].customerID == Customers[i].customerID)
		{
			cout << "Already Taken. Enter Again: ";
			goto id;
			break;
		}
	}
	cin.ignore();
	cout << "Email address: ";
	getline(cin, Customers[no].email);

	cout << "Phone number: ";
phone:
	getline(cin, Customers[no].phone);
	bool pHone = validPhone(Customers[no].phone);
	if (pHone == 0)
	{
		cout << "Invalid!\nEnter Again: ";
		goto phone;
	}
	cout << "Address: ";
address:
	getline(cin, Customers[no].address);
	bool AdDress = validAddress(Customers[no].address);
	if (AdDress == 0)
	{
		cout << "Invalid!\nEnter Again: ";
		goto address;
	}
	no++;
}
void customer::updateCustomerInfo(string ID) {
	int i = 0, flag = 1;
	string id[20], name[20], address[20], phone[20], email[20];
	ifstream fin;
	fin.open("Customer info.txt");
	while (!fin.eof()) {
		getline(fin, id[i], ',');
		fin.ignore();
		getline(fin, name[i], ',');
		fin.ignore();
		getline(fin, address[i], ',');
		fin.ignore();
		getline(fin, phone[i], ',');
		fin.ignore();
		getline(fin, email[i], '\n');
		i++;
	}
	fin.close();
	for (int s = 0; s < i; s++) {
		if (ID == id[s]) {
			flag = 1;
			char op;
			while (true) {					//update customer info
				system("cls");
				cout << "* * * * * * * * * * [Bank Management System] * * * * * * * * * *\n";
				cout << "What you want to update\n";
				cout << "- Press 1 for Name\n";
				cout << "- Press 2 for Address\n";
				cout << "- Press 3 for Email\n";
				cout << "- Press 4 for Phone Number\n";
				cout << "- Press 5 to update all\n";
				cout << "- Press 0 to exit\n";
				cout << "Input: ";
				cin >> op;
				if (op == '1') {
					cout << "Enter name: ";
					cin.ignore();
					getline(cin, name[s]);
					while (true) {
						bool r = validName(name[s]);
						if (r == true) {
							cout << "Name updated\n";
							system("pause");
							break;
						}
						else {
							cout << "The name you entered is in valid\nEnter again: ";
							getline(cin, name[s]);
						}
					}
				}
				else if (op == '2') {
					cout << "Enter Address: ";
					cin.ignore();
					getline(cin, address[s]);
					while (true) {
						bool r = validAddress(address[s]);
						if (r == true) {
							cout << "Address updated\n";
							system("pause");
							break;
						}
						else {
							cout << "The address you entered is in valid\nEnter again: ";
							getline(cin, address[s]);
						}
					}
				}
				else if (op == '3') {
					cout << "Enter email: ";
					cin >> email[s];
					cout << "Email updated\n";
					system("pause");
					break;
				}
				else if (op == '4') {
					cout << "Enter phone: ";
					cin >> phone[s];
					while (true) {
						bool r = validPhone(phone[s]);
						if (r == true) {
							cout << "Phone Number updated\n";
							system("pause");
							break;
						}
						else {
							cout << "The phone you entered is in valid\nEnter again: ";
							cin >> phone[s];
						}
					}
				}
				else if (op == '5') {
					cout << "Enter name: ";
					cin.ignore();
					getline(cin, name[s]);
					while (true) {
						bool r = validName(name[s]);
						if (r == true) {
							cout << "Name updated\n";
							break;
						}
						else {
							cout << "The name you entered is in valid\nEnter again: ";
							getline(cin, name[s]);
						}
					}
					cout << "Enter Address: ";
					getline(cin, address[s]);
					while (true) {
						bool r = validAddress(address[s]);
						if (r == true) {
							cout << "Address updated\n";
							break;
						}
						else {
							cout << "The address you entered is in valid\nEnter again: ";
							getline(cin, address[s]);
						}
					}
					cout << "Enter email: ";
					cin >> email[s];
					cout << "Emial updated\n";
					cout << "Enter phone: ";
					cin >> phone[s];
					while (true) {
						bool r = validPhone(phone[s]);
						if (r == true) {
							cout << "Phone updated\n";
							break;
						}
						else {
							cout << "The phone you entered is in valid\nEnter again: ";
							cin >> phone[s];
						}
					}
				}
				else if (op == '0') {
					break;
				}
			}
			break;
		}
		else {
			flag = 0;
		}
	}
	if (flag == 0) {
		cout << "This Customer ID is not available\n";
		system("pause");
		return;
	}
	ofstream fout;
	fout.open("Customer info.txt");
	for (int s = 0; s < i - 1; s++) {
		fout << id[s] << ", " << name[s] << ", " << address[s] << ", " << phone[s] << ", " << email[s] << endl;
	}
	fout.close();
}
void customer::delete_customer()
{							//delete pprevious customer
	int i;
	int count = 0;
	string ID = "i";
	while (ID != "0")
	{
		cout << "Enter the customer ID you want to delete or 0 to exit: ";
	again:
		cin >> ID;
		for (i = 0; i < no; i++)
		{
			if (ID == Customers[i].customerID)
			{
				deleteAccounts(ID);
				cout << "Your account is successfully deleted.\n";
				Customers[i].customerID = "\0"; Customers[i].name = "\0"; Customers[i].phone = "\0"; Customers[i].address = "\0"; Customers[i].email = "\0";
				count++;
			}
		}

		if (count != 0)
		{
			cout << "Press any key to continue...";
			getch();
			break;
		}
		if (count == 0 && ID != "0")
		{
			cout << "You have entered an invalid ID. Try again: ";
			goto again;
		}

	}
}
void customer::deleteAccounts(string ID)				//to delete accounts
{
	int i = 0;
	string CustomerID[20], AccountID[20], Type[20];
	double balance[20], CLorIR[20], PAmount[20], time[20];
	Date date[20];
	ifstream fin;
	fin.open("Customers Accounts.txt");
	while (!fin.eof())
	{
		if (i > 0)
			fin.ignore();
		getline(fin, CustomerID[i], ',');
		fin.ignore();
		getline(fin, AccountID[i], ',');
		fin.ignore();
		getline(fin, Type[i], ',');
		fin.ignore();
		fin >> balance[i];
		fin.ignore(balance[i], ',');
		fin.ignore();
		fin >> date[i].day;
		fin.ignore(date[i].day, '-');
		fin >> date[i].month;
		fin.ignore(date[i].month, '-');
		fin >> date[i].year;
		fin.ignore(date[i].year, ',');
		fin.ignore();
		fin >> CLorIR[i];
		fin.ignore(CLorIR[i], ',');
		fin.ignore();
		fin >> PAmount[i];
		fin.ignore(PAmount[i], ',');
		fin.ignore();
		fin >> time[i];
		i++;
	}
	fin.close();
	ofstream fout;
	fout.open("Customers Accounts.txt");
	for (int s = 0; s < i - 1; s++) {
		if (CustomerID[s] != ID)
			fout << CustomerID[s] << ", " << AccountID[s] << ", " << Type[s] << ", " << balance[s] << ", " << date[s].day << "-" << date[s].month << "-" << date[s].year << ", " << CLorIR[s] << ", " << PAmount[s] << ", " << time[s] << endl;
	}
	fout.close();
}
void customer::loadCustomers()
{					//to load all the pprevious customers
	int i = 0;
	string id[20], name[20], address[20], phone[20], email[20];

	ifstream fin;
	fin.open("Customer info.txt");
	while (!fin.eof()) {
		getline(fin, id[i], ',');
		Customers[no].customerID = id[i];
		fin.ignore();
		getline(fin, name[i], ',');
		Customers[no].name = name[i];
		fin.ignore();
		getline(fin, address[i], ',');
		Customers[no].address = address[i];
		fin.ignore();
		getline(fin, phone[i], ',');
		Customers[no].phone = phone[i];
		fin.ignore();
		getline(fin, email[i], '\n');
		Customers[no].email = email[i];
		i++;
		no++;
	}
	fin.close();
}
//----------[customer Class body]------------------
//-----------------(start)-------------------------

class Admin {
	string username, password;
public:
	Admin() : username("0"), password("0") {}				//default constructor
	void recordsAccess() {
		string op, ID[20], C_ID[20], type[20]; double money[20]; Date date[20];
		ifstream fin; int i = 0;
		fin.open("accountTransactions.txt");				//to read pprevious account transactions
		while (!fin.eof()) {
			getline(fin, C_ID[i], ','); fin.ignore();
			getline(fin, ID[i], ','); fin.ignore();
			fin >> date[i].day; fin.ignore(date[i].day, '-');
			fin >> date[i].month; fin.ignore(date[i].month, '-');
			fin >> date[i].year; fin.ignore(date[i].year, ','); fin.ignore();
			getline(fin, type[i], ','); fin.ignore(); fin >> money[i]; fin.ignore(money[i], '\n');
			i++;
		}
		fin.close();						//this function allow you to access transactions record
		while (true) {
			system("cls");
			cout << "* * * * * * * * * * [Bank Management System] * * * * * * * * * *\n";
			cout << "- Press 1 to see the rocords of all deposits made\n";
			cout << "- Press 2 to see the rocords of all withdrawals made\n";
			cout << "- Press 3 to see the rocords of all installments paid\n";
			cout << "- Press 4 to see the rocords of all loans taken\n";
			cout << "- Press 5 to get customer balances\n";
			cout << "- press 0 to log out\n";
			cout << "Input: ";
			cin >> op;
			if (op == "1") {
				int count = 0;
				cout << "Customer ID, Account ID, Date, Type, Amount:\n";
				for (int s = 0; s < i - 1; s++) {
					if (type[s] == "Deposit") {
						count++;
						cout << "\t\t\t\t" << C_ID[s] << ", " << ID[s] << ", " << date[s].day << "-" << date[s].month << "-" << date[s].year << ", " << type[s] << ", " << money[s] << " PKR " << endl;
					}
				}
				if (count == 0) {
					cout << "\t\t\t\t[No records available]\n";
				}
				system("pause");
			}
			else if (op == "2") {
				int count = 0;
				cout << "Account ID, Date, Type, Amount:\n";
				for (int s = 0; s < i - 1; s++) {
					if (type[s] == "Withdraw") {
						count++;
						cout << "\t\t\t\t" << C_ID[s] << ", " << ID[s] << ", " << date[s].day << "-" << date[s].month << "-" << date[s].year << ", " << type[s] << ", " << money[s] << " PKR " << endl;
					}
				}
				if (count == 0) {
					cout << "\t\t\t\t[No records available]\n";
				}
				system("pause");
			}
			else if (op == "3") {
				int count = 0;
				cout << "Account ID, Date, Type, Amount:\n";
				for (int s = 0; s < i - 1; s++) {
					if (type[s] == "Instalment") {
						count++;
						cout << "\t\t\t\t" << C_ID[s] << ", " << ID[s] << ", " << date[s].day << "-" << date[s].month << "-" << date[s].year << ", " << type[s] << ", " << money[s] << " PKR " << endl;
					}
				}
				if (count == 0) {
					cout << "\t\t\t\t[No records available]\n";
				}
				system("pause");
			}
			else if (op == "4") {
				int count = 0;
				cout << "Account ID, Date, Type, Amount:\n";
				for (int s = 0; s < i - 1; s++) {
					if (type[s] == "Loan") {
						count++;
						cout << "\t\t\t\t" << C_ID[s] << ", " << ID[s] << ", " << date[s].day << "-" << date[s].month << "-" << date[s].year << ", " << type[s] << ", " << money[s] << " PKR " << endl;
					}
				}
				if (count == 0) {
					cout << "\t\t\t\t[No records available]\n";
				}
				system("pause");
			}
			else if (op == "5") {
				string ID_1;
				cout << "Enter Customer ID: ";
				cin >> ID_1;
				string CustomerID[20], AccountID[20], Type[20];
				double balance[20], CLorIR[20], PAmount[20], time[20];
				Date date[20];  ifstream fin; int i = 0;
				fin.open("Customers Accounts.txt");				//to read details from customer accounts txt 
				while (!fin.eof()) {
					if (i > 0) {
						fin.ignore();
					}
					getline(fin, CustomerID[i], ','); fin.ignore();
					getline(fin, AccountID[i], ','); fin.ignore();
					getline(fin, Type[i], ','); fin.ignore();
					fin >> balance[i]; fin.ignore(balance[i], ','); fin.ignore();
					fin >> date[i].day; fin.ignore(date[i].day, '-');
					fin >> date[i].month; fin.ignore(date[i].month, '-');
					fin >> date[i].year; fin.ignore(date[i].year, ','); fin.ignore();
					fin >> CLorIR[i]; fin.ignore(CLorIR[i], ','); fin.ignore();
					fin >> PAmount[i]; fin.ignore(PAmount[i], ','); fin.ignore();
					fin >> time[i];
					i++;
				}
				fin.close();
				double sum = 0;
				for (int s = 0; s < i - 1; s++) {
					if (ID_1 == CustomerID[s]) {
						cout << "\t\t\t\t[Account ID]: " << AccountID[s] << ", [Account balance]: " << balance[s] << " PKR\n";
						sum = sum + balance[s];
					}
					else if (s == i - 2 and sum == 0) {
						cout << "Customer ID doesn't exist\nEnter again or press 0 to exit: ";
						cin >> ID_1;
						s = -1;
					}
					else if (ID_1 == "0") {
						break;
					}
				}
				if (sum != 0) {
					cout << "[Total Balance]: " << sum << " PKR\n";
					system("pause");
				}
			}
			else if (op == "0") {
				break;
			}
			else {
				cout << "you entered invalid option\nEnter again: ";
				cin >> op;
			}
		}
	}
	void input() {
		int flag = 0;
		string users[5]{ "Musham Malik", "Arooj Fatima", "Vaniza Riaz", "Ibrahim Qureshi", "Rehan Ashraf" }, PINS[5] = { "123456", "123456", "123456", "123456", "123456" }, user, PIN;
		system("cls");
		cout << "* * * * * * * * * * [Bank Management System] * * * * * * * * * *\n";
		cout << "Enter your username: ";
		cin.ignore();
		getline(cin, user);
		cout << "Enter your PIN: ";
		cin >> PIN;
		for (int s = 0; s < 5; s++) {
			if (user == users[s] and PIN == PINS[s]) {
				flag = 1;
				recordsAccess();
				break;
			}
			else if (s == 4 and flag == 0) {
				cout << "The username or password you enter doesnot exist\nEnter again\nUsername: ";
				cin.ignore();
				getline(cin, user);
				cout << "PIN: ";
				cin >> PIN;
				s = -1;
			}
		}
	}
};

int main()
{

	customer obj; Admin obj1; char op;
	obj.loadCustomers();
	cout << "* * * * * * * * * * [Bank Management System] * * * * * * * * * *\n";
	while (true) {
		cout << "- Press 1 if you are an existing customer\n";
		cout << "- Press 2 if you are new and want to sign up\n";
		cout << "- Press 3 if you want to update your Customer Informatiom\n";
		cout << "- Press 4 if you want to delete your account\n";
		cout << "- Press 5 to login as Admin\n";
		cout << "- Press 0 to exit\n";
		cout << "Input: ";
		cin >> op;
		if (op == '1') {
			obj.input();
		}
		else if (op == '2') {
			system("cls");
			cout << "* * * * * * * * * * [Bank Management System] * * * * * * * * * *\n";
			obj.newCustomer();					//add customer
			obj.saveCustomers();					//save customer info
			cout << "New Customer added\n";
			system("cls");
			cout << "* * * * * * * * * * [Bank Management System] * * * * * * * * * *\n";
		}
		else if (op == '3') {
			string ID;
			system("cls");
			cout << "* * * * * * * * * * [Bank Management System] * * * * * * * * * *\n";
			cout << "Enter the customer ID you want to update: ";
			cin >> ID;
			obj.updateCustomerInfo(ID);
			system("cls");
			cout << "* * * * * * * * * * [Bank Management System] * * * * * * * * * *\n";
		}
		else if (op == '4')
		{
			system("cls");
			cout << "* * * * * * * * * * [Bank Management System] * * * * * * * * * *\n";
			obj.delete_customer();				//delete customer
			system("cls");
			cout << "* * * * * * * * * * [Bank Management System] * * * * * * * * * *\n";
			obj.saveCustomers();
		}
		else if (op == '5') {
			obj1.input();
			system("cls");
			cout << "* * * * * * * * * * [Bank Management System] * * * * * * * * * *\n";
		}
		else if (op == '0') {
			system("cls");
			cout << "\n- - - - - - - - - - - - - -[E X I T]- - - - - - - - - - - - - - \n";
			break;
		}
		else {
			cout << "You entered an invalid option\nInput again: ";
			cin >> op;
		}
	}
	return 0;
}
