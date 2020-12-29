# OOP2: Assoziation/Aggregation von Klassen

- has A Beziehungen zwischen Klassen

---

## Bank has Accounts

1. Create project: 04-JAVA-OOP2-bank
2. Create package: oop2 and test
3. Create class: Bank, Account in package oop2
4. Create Test-Programs test.T_Bank.java (see below) to test your classes in oop2

---

## class oop2.Account

Create a class Account with the following structure.

~~~ java
Member: 
	private int number_; 
	private String owner_; 
	private double amount_; 
Methods (consider the parameters and return values): 
	Constructor / Destructor 
	Getter and setter methods
	toString() 
	withdraw() 
	deposit() 
~~~

Write a short program **test.T_Account.java** for testing the class.

---

## class oop2.Bank

Write a class Bank and add Account as class member: 

~~~java
Members:
	private String name_; 
	private ArrayList<Account> accounts_; 

Methods (consider the parameters and return values): 
	Constructor / Destructor 
	Getter and setter methods
	toString() 
	addAccount(), delAccount()
	addInterest() 
	charges() 
~~~

---

## class test.T_Bank

Create a main program for testing the classes Account and Bank:

~~~java
package test;
import oop2.*;

public class T_Bank {
	public static void main(String[] args) {
		Bank myB= new Bank("Hofmann Unlimited");

		Account a1= new Account("Anton Hofmann",1000.0);
		Account a2= new Account("Beta Hofmann", 1000.0);
		Account a3= new Account("Gamma Hofmann",1000.0);

		myB.addAccount(a1);
		myB.addAccount(a2);
		myB.addAccount(a3);

		System.out.println( "The Bank: BEFORE calculating the charges *********" );
		System.out.println( myB.toString() );

		myB.charges(10.0);
		System.out.println( "The Bank: AFTER calculating the charges *********" );
		System.out.println( myB.toString() );

		myB.addInterest(5.0);
		System.out.println( "The Bank: AFTER adding the interest *********" );
		System.out.println( myB.toString()  );

		myB.delAccount(a3);
		System.out.println( "The Bank: AFTER deleting a3 (Gamma Hofmann) *********" );
		System.out.println( myB.toString() );

		//...
	}
}
~~~

The output should be:

~~~ bash
The Bank: BEFORE calculating the charges *********
BANK: ...Hofmann Unlimited... 
ACCOUNT: 
	owner: Anton Hofmann
	number: 1
	amount: 1000.0
ACCOUNT: 
	owner: Beta Hofmann
	number: 2
	amount: 1000.0
ACCOUNT: 
	owner: Gamma Hofmann
	number: 3
	amount: 1000.0

The Bank: AFTER calculating the charges *********
BANK: ...Hofmann Unlimited... 
ACCOUNT: 
	owner: Anton Hofmann
	number: 1
	amount: 990.0
ACCOUNT: 
	owner: Beta Hofmann
	number: 2
	amount: 990.0
ACCOUNT: 
	owner: Gamma Hofmann
	number: 3
	amount: 990.0

The Bank: AFTER adding the interest *********
BANK: ...Hofmann Unlimited... 
ACCOUNT: 
	owner: Anton Hofmann
	number: 1
	amount: 995.0
ACCOUNT: 
	owner: Beta Hofmann
	number: 2
	amount: 995.0
ACCOUNT: 
	owner: Gamma Hofmann
	number: 3
	amount: 995.0

The Bank: AFTER deleting a3 (Gamma Hofmann) *********
BANK: ...Hofmann Unlimited... 
ACCOUNT: 
	owner: Anton Hofmann
	number: 1
	amount: 995.0
ACCOUNT: 
	owner: Beta Hofmann
	number: 2
	amount: 995.0
~~~

---

## Bank with static member

Your classes Bank/Account should get a different account number for each Account.

Hint: use a static member in class Account and change Accounts constructor. 

~~~java
private static int next_account_number=0;
~~~

---

## protected members

> ATTENTION: 
For security reasons NOBODY (except class Bank) should be able
to create Accounts!

SOLUTION:

- Put Bank and Account into a package called bank.
- Make the constructor of class Account protected.
- in T_Bank.java change this code

~~~ java
Account a1= new Account("Anton Hofmann",1000.0);
Account a2= new Account("Beta Hofmann", 1000.0);
Account a3= new Account("Gamma Hofmann",1000.0);

myB.addAccount(a1);
myB.addAccount(a2);
myB.addAccount(a3);

to

myB.addAccount("Anton Hofmann",1000.0);
myB.addAccount("Betta Hofmann",1000.0);
myB.addAccount("Gamma Hofmann",1000.0);
~~~

- method addAccount() creates Account objects.

---

## Bank with logging (streams)

- Every bank transaction has to be logged.
- This Log-File can be used for backup/recovery.

- implement in class Bank:

~~~java
...
void setLogging(bool)
	// if true
	// creates logfile
	// Filename for Logging is BANK_name_DATE.log
	// (BANK-Hofmann-unlimited-2017-12-24-11-20.log)

	// if false
	// close logfile


void reset()
	// delete all accounts and 
	// reset static member Account.next_account_number;

	
int addAccount(string owner, double value)
	// write to logfile:
	// ADD:owner:value
	
	
void delAccount(string owner)
	// write to logfile:
	// DEL:owner
	

Account getAccount(int nr)

void charges(double value)
	// write to logfile:
	// FORALL:MINUS:value
	

void addInterest(double value);
	// write to logfile:
	// FORALL:PLUS:value

void deposit(string owner, value);
	// write to file
	// FORONE:owner:PLUS:value
	
void withdraw(string owner, value);
	// write to file
	// FORONE:owner:MINUS:value
	
double getSumDeposits(); // returns sum of all accounts

~~~

## Test logging: test.T_Bank_Logging.java

Test with this code:

test.T_Bank_Logging.java

~~~java
Bank myBank= new Bank("Hofmann-unlimited");
myBank.reset();
myBank.setLogging(true);

myBank.addAccount("Anton Hofmann", 100.0);
myBank.addAccount("Beta Hofmann", 200.0);
myBank.addAccount("Gamma Hofmann",300.0);

myBank.delAccount("Anton Hofmann");
myBank.addAccount("Omega Hofmann", 509.0);

myBank.addInterest(100.0);
myBank.charges(100.0);

myBank.deposit("Omega Hofmann", 1.0);
myBank.withdraw("Omega Hofmann", 10.0);

myBank.setLogging(false);

System.out.println(myBank.getSumDeposits());
~~~

~~~bash
output to console should be:
1000.00
~~~

~~~ bash
BANK-Hofmann-unlimited-2020-12-24-11-20.log
ADD:Anton Hofmann:100.00
ADD:Beta Hofmann:200.00
ADD:Gamma Hofmann:300.00
DEL:Anton Hofmann
ADD:Omega Hofmann:509.00
FORALL:PLUS:100.00
FORALL:MINUS:100.00
FORONE:Omega Hofmann:PLUS:1.00
FORONE:Omega Hofmann:MINUS:10.00
~~~

---

## Bank and recovery: test.T_Bank_Recovery.java

- This Log-File can be used for backup/recovery.

Test with this code: test.T_Bank_Recovery.java

~~~java
Bank myBank = new Bank("Hofmann-unlimited");
myBank.setLogging(false);

myBank.recovery("BANK-Hofmann-unlimited-2020-12-24-11-20.log");


System.out.println(myBank.getSumDeposits());

}
~~~

~~~ bash
output should be:
1000.00
~~~
