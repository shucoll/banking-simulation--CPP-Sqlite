#include<iostream>
#include<stdio.h>
#include<string.h>
#include <sqlite3.h>

using namespace std;

class Bank{
    long acno,bal;
    string fnm,lnm, acctype;
    int custID;
public:
    Bank() {
        acno = 0;
        bal = 0;
    }
    void setdata(long,float,string, string,string); //To set the data given by user
    void saveNewData(); //To save the data to a database
    void retriveData(); //To get the data from database
    void updateData();  //To update data from database (wthdraw/deposit amount)
    int  openIDCheck(); //To check if a passed account number to checkout exists
    void deposit();     //To revieve diposit amount 
    void withdraw();    //To recieve withdraw amount
    void display();     //To display acount info
};


void Bank::setdata(long accno,float baln,string fnme,string lnme, string accntype) {

    acno = accno;
    bal = baln;
    fnm = fnme;
    lnm = lnme;
    acctype = accntype;
}


void Bank::saveNewData() {
    sqlite3* DB;
    sqlite3_stmt* st;
    
    int exit = sqlite3_open("Bank.db", &DB); 
    if ( exit != SQLITE_OK) {
        cout<< "Couldnt Open database."<<endl;
    }
    else {
        string query = "SELECT * FROM PERSON;";     
    
    
        string sql = "INSERT INTO PERSON(AccNumber,FNAME,LNAME,AccType,Balance) VALUES (?,?,?,?,?);";

        exit=sqlite3_prepare(DB, sql.c_str(), -1, &st, NULL);
        if (exit == SQLITE_OK) {
            sqlite3_bind_int(st, 1, acno);
            sqlite3_bind_text(st, 2, fnm.c_str(), fnm.length(), SQLITE_TRANSIENT);
            sqlite3_bind_text(st, 3, lnm.c_str(), lnm.length(), SQLITE_TRANSIENT);
            sqlite3_bind_text(st, 4, acctype.c_str(), acctype.length(), SQLITE_TRANSIENT);
            sqlite3_bind_int(st, 5, bal);
            sqlite3_step(st);

            cout << "Records created Successfully!" <<endl; 

            int last_id = sqlite3_last_insert_rowid(DB);
            printf("The ID of the last inserted customer data is %d\n", last_id);
        }
        else {
            
            fprintf(stderr, "Failed to execute statement: %s\n", sqlite3_errmsg(DB));
        }

        sqlite3_finalize(st);
        sqlite3_close(DB); 
    }
}

void Bank::retriveData() {
    int id;
	cout<<"Enter ID"<<endl;
	cin>>id;

	sqlite3* DB; 
	sqlite3_stmt* st;
	int exit = 0; 
	exit = sqlite3_open("Bank.db", &DB); 
	string data("CALLBACK FUNCTION"); 

	string sql= "SELECT * FROM PERSON WHERE ID = ?;"; 

	exit=sqlite3_prepare_v2(DB, sql.c_str(), -1, &st, 0);

	if (exit == SQLITE_OK) {
        sqlite3_bind_int(st, 1, id);
    } else {
        
        fprintf(stderr, "Failed to execute statement: %s\n", sqlite3_errmsg(DB));
    }
	
	
	int step = sqlite3_step(st);
    
    if (step == SQLITE_ROW) {
        
        printf("ID:  %d\n", sqlite3_column_int(st, 0));
        printf("Account No:  %d\n", sqlite3_column_int(st, 1));
        printf("First Name:  %s\n", sqlite3_column_text(st, 2));
		printf("Last Name:  %s\n", sqlite3_column_text(st, 3));
		printf("Account Type:  %s\n", sqlite3_column_text(st, 4));
		printf("Balance:  %d\n\n", sqlite3_column_int(st, 5));

	}
	else cout<<"Record not found"<<endl;
	
	sqlite3_finalize(st);
	sqlite3_close(DB);
}



void Bank::display() {
    if(acno == 0) {
        cout<<"No data to display"<<endl;
        return;
    }
    cout<<endl<<"--Customer Info--"<<endl;
    cout<<"Accout No: "; cout<<acno<<endl;
    cout<<"First Name: "; cout<<fnm<<endl;
    cout<<"Last Name: "; cout<<lnm<<endl;
    cout<<"Account type: "; cout<<acctype<<endl;
    cout<<"Initial deposit: "; cout<<bal<<endl;
}


