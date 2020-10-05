#include<iostream>
#include<stdio.h>
#include<string.h>

using namespace std;

class bank
{
    long acno,bal;
    char nm[100], acctype[50];
    int custID;
public:
    bank() {
        acno = 0;
        bal = 0;
    }
    void setdata(long,float,char*,char*); //To set the data given by user
    void saveNewData(); //To save the data to a database
    void retriveData(); //To get the data from database
    void updateData();  //To update data from database (wthdraw/deposit amount)
    int  openIDCheck(); //To check if a passed account number to checkout exists
    void deposit();     //To revieve diposit amount 
    void withdraw();    //To recieve withdraw amount
    void display();     //To display acount info
};

void bank::setdata(long accno,float baln,char* nme, char* accntype) {
    acno=accno;
    bal=baln;
    strcpy(nm,nme);
    strcpy(acctype,accntype);
}

void bank::display() {
    if(acno == 0) {
        cout<<"No data to display"<<endl;
        return;
    }
    cout<<endl<<"--Customer Info--"<<endl;
    cout<<"Accout No: "; cout<<acno<<endl;
    cout<<"Name: "; cout<<nm<<endl;
    cout<<"Account type: "; cout<<acctype<<endl;
    cout<<"Initial deposit: "; cout<<bal<<endl;
}