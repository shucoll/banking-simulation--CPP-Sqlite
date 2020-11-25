#include<iostream>
#include<sstream>
#include<string>

using namespace std;


class Menus {
    
    public:
    int checkInput(string chM);
    int menu1(int,int);
    int menu2(int,int);
    int menu3(int);
    int menu4();

};


int Menus::checkInput(string chM) {

    for (int i = 0; i < chM.length(); i++) {
        if (isdigit(chM[i]) == false) 
            return -1;
    }

    int ipM = 0;     
    stringstream ss(chM);
    ss >> ipM;
    return ipM; 
}


int Menus:: menu1(int Qrem,int SerCus) {

    string chM;
    cout<<endl<<"           *----Main Menu----*"<<endl;
    cout<<"           Customers in queue "<<Qrem<<endl;
    cout<<"           Customer at service "<<SerCus<<endl;
    cout<<"           1. Add customer and begin simulaiton"<<endl;
    cout<<"           0. End Services (Terminate program)"<<endl;
    cout<<"           Enter your choice 1/0"<<endl;
    cin>>chM;
    int ipM=checkInput(chM);
    return ipM;
}



int Menus:: menu2(int Qrem, int SerCus) {

    string chC;
    cout<<endl<<"           *----Customer Service Menu----*"<<endl;
    cout<<"           Customers in queue "<<Qrem<<endl;
    cout<<"           Customer at service "<<SerCus<<endl;
    cout<<"           1. Add new customer"<<endl;
    cout<<"           For service to customer "<<SerCus<<endl;
    cout<<"                   2. Create Account"<<endl;
    cout<<"                   3. Check an existing Account"<<endl;
    cout<<"           4. Invok Report Generator"<<endl;
    cout<<"           0. End Services (Terminate program)"<<endl;
    cout<<"           Enter your choice 1/2/3/4/0"<<endl;
    cin>>chC;
    int ipC=checkInput(chC);
    return ipC;
}


int Menus:: menu3(int SerCus) {

    string chU;
    cout<<endl<<"           *----Account Check Menu----*"<<endl;
    cout<<"           1. View Data"<<endl;
    cout<<"           2. Withdraw"<<endl;
    cout<<"           3. Deposit"<<endl;
    cout<<"           4. Finish service for customer "<<SerCus<<endl;
    cout<<"           0. End Services (Terminate program)"<<endl;
    cout<<"           Enter your choice 1/2/3/4/0"<<endl;
    cin>>chU;
    int ipC=checkInput(chU);
    return ipC;
}

int Menus:: menu4() {

    string chR;
    cout<<endl<<"           *----Report Generator Menu----*"<<endl;
    cout<<"           1. View report table"<<endl;
    cout<<"           2. Get average service time"<<endl;
    cout<<"           3. Get average waiting time of customers"<<endl;
    cout<<"           4. Get average waiting time of customers who wait"<<endl;
    cout<<"           5. Get probability of server being ideal"<<endl;
    cout<<"           0. End program"<<endl;
    cout<<"           Enter your choice 1/2/3/4/5/0"<<endl;

    cin>>chR;
    cout<<endl;
    int ipR=checkInput(chR);
    return ipR;
}



