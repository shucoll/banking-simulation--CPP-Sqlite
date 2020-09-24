#include<iostream>
#include<stdio.h>
#include<string.h>

using namespace std;

class bank
{
    int acno;
    char nm[100], acctype[100];
    float bal;
    int custID;
public:
    void setdata(int,float,int,char*,char*);
    void checkID(int,int);
    int openIDCheck(int,int);
    void deposit();
    void withdraw();
    void display();
};

void bank::setdata(int accno,float baln,int custmID, char* nme, char* accntype) {
    acno=accno;
    bal=baln;
    custID=custmID;
    strcpy(nm,nme);
    strcpy(acctype,accntype);
}

int bank::openIDCheck(int IDC, int IDI) {
    if(this->acno==IDC || this->custID==IDI) return 1;
    else return 0;
}

void bank::checkID(int ID,int cho){
    if(cho==1)
        {
        if(this->custID == ID)
            {
            this->display();
            cout<<"\n What do you want ? ";
            cout<<"\n 1. To deposit money ";
            cout<<"\n 2. To withdraw money ";
            cout<<"\n 3. To Exit \n";
            cout<<"\n Choose your option 1 , 2 or 3 :";
            int t ;
            cin>>t;
            switch(t)
            {
            case 1 :
                {
                    this->deposit();
                    break;
                }
            case 2 :
                {
                    this->withdraw();
                    break;
                }
            }
        }
}
    else if(cho==2)
    {
       if(this->acno == ID)
       {
            this->display();
            cout<<"\n What do you want ? ";
            cout<<"\n 1. To deposit money ";
            cout<<"\n 2. To withdraw money \n ";
            cout<<"\n 3. To Exit \n";
            cout<<"\n Choose your option 1 , 2 or 3 :";
            int p ;
            cin>>p;
            switch(p)
            {
            case 1 :
                {
                    this->deposit();
                    break;
                }
            case 2 :
                {
                    this->withdraw();
                    break;
                }
            } } }
}
void bank::deposit()
{
        int damt1;
        cout<<"\n Enter Deposit Amount = ";
        cin>>damt1;
        bal+=damt1;
        cout<<"\n Total Balance "<<bal<<endl;
}
void bank::withdraw()
{
      int wamt1;
        cout<<"\n Enter Withdraw Amount = ";
        cin>>wamt1;
        if(wamt1>bal)
               {
                cout<<"\n Cannot Withdraw Amount";
               }
        else
              {
                bal-=wamt1;
              }
        cout<<"\n Remaining balance "<<bal<<endl;
}
void bank::display()
{
        cout<<"\n Accout No. : "<<acno;
        cout<<"\n Name : "<<nm;
        cout<<"\n Account Type : "<<acctype;
        cout<<"\n Total Balance : "<<bal;
        cout<<"\n";
}
int main()
{       int n;
        cout<<"\n How many bank account you want to store in your bank ? \n";
        cin>>n;
        int i=0,j=0,k=0,d=0,c=0;
        int id;
        int cho1,cho2;
        int acno,custID;
        char nm[100], acctype[100];
        float bal;
        bank b[2];
        do{
            cout<<"\n 1. Do you want to create an account ? ";
            cout<<"\n 2. Do you want to check your customer id ? ";
            cout<<"\n Enter your option 1 or 2 ... ";
            cin>>cho1;
            switch(cho1) {
                case 1:
                if ((d+1)>n)
                        {
                           cout<<"\n BANK CANNOT OPEN ANY OTHER ACCOUNT, HIGHEST LIMIT REACHED \n";
                           cout<<"\n YOU CAN ONLY CHECK ACCOUNTS \n";
                           break;
                        }
                else
                {
                     if(i==0)
                       {
                        cout<<"\n Enter Details: \n";
                        cout<<"Enter customer ID ";
                        cin>>custID;
                        cout<<"Enter Accout No. ";
                        cin>>acno;
                        cout<<"Enter name : ";
                        cin>>nm;
                        cout<<"Enter Account type : ";
                        cin>>acctype;
                        cout<<"How much money you want to add as initial balance : ";
                        cin>>c;
                        if (c<5000)
                        {
                          cout<<"\n account cant be open ";
                          cout<<"\n Initial balance to open an account is 5000 \n";
                          continue;
                        }
                        else
                        {
                          bal= c ;
                          cout<<"\n Account opened with balance "<<bal;
                          cout<<"\n";
                        }
                        b[i++].setdata(acno,bal,custID,nm,acctype);
                        d++;
                    }
                    else{
                        int check=0;
                        cout<<"\n Enter Details: \n";
                        cout<<"Enter customer ID ";
                        cin>>custID;
                        cout<<"Accout No. ";
                        cin>>acno;
                        while(j<i){
                            if(b[j++].openIDCheck(acno,custID)) {
                                check=1;
                            }
                        }
                        j=0;
                        if(check) {
                            cout<<"Cannot open account. Customer ID or Account Number is already exists"<<endl;
                            break;
                        }
                        cout<<"Enter name : ";
                        cin>>nm;
                        cout<<"Account type : ";
                        cin>>acctype;
                        cout<<"How much money you want to add as initial balance : ";
                        cin>>c;
                        if (c<5000)
                        {
                          cout<<"\n account cant be open ";
                          cout<<"\n Initial balance to open an account is 5000 \n";
                          continue;
                        }
                        else
                        {
                          bal= c ;
                          cout<<"\n Account opened with balance "<<bal;
                          cout<<"\n";
                        }
                        b[i++].setdata(acno,bal,custID,nm,acctype);
                        d++;
                        if(d==n)
                        {
                            cout<<"\n THE LAST CCOUNT BANK CAN OPEN , HIGHEST LIMIT REACHED \n";
                        }
                    }
                }
                    break;

                case 2:

                    cout<<"\n    Checking option :";
                    cout<<"\n    1. Checking through Customer ID";
                    cout<<"\n    2. Checking through Account No";
                    cout<<"\n    Enter choice(1/2) : ";
                    cin>>cho2;
                    switch (cho2)
                    {
                        case 1:
                            cout<<"\n Enter customer ID : ";
                            cin>>id;
                            break;
                        case 2:
                            cout<<"Enter Acc no : ";
                            cin>>id;
                            break;
                        default:
                            cout<<"Invalid input";
                            cho2=-1;
                            break;
                    }
                    if(cho2!=-1) {
                        int check2=0;
                        do {
                            b[k++].checkID(id,cho2);
                        }while(k<n);
                        k=0;
                    }
                    break;
                default: cout<<"Invalid Input";
            }
        }while(cho1!=0);
    return 0;
}