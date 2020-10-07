#include<iostream>
#include<string>

#include "LQueue.h"
#include "Menus.h"
#include "BankModel.h"

using namespace std;

class clsMain {
    int Qrem;
    int SerCus;
    int NewCus;
    Queue qe;
    Menus mu;
    Bank bk;

    public:
    void mainMenuCalc();
    int cusMenuCalc();

};

void clsMain:: mainMenuCalc() {
    Qrem=0;
    SerCus=0;
    NewCus=0; 
    int ipM;
    
    do{
        Qrem=qe.size();
        ipM = mu.menu1(Qrem,SerCus);

        switch (ipM){
        case 1:
            qe.enqueue(++NewCus);
            break;
        case 2:
            if(NewCus>0){
                SerCus=qe.dequeue();
                ipM=cusMenuCalc();
            }
            else
                cout<<"No customer available"<<endl;
            break;
        case 0:
            break;
        default:
            cout<<"Invalid input"<<endl;
        }

    }while(ipM != 0);
}

int clsMain::cusMenuCalc() {
    int ipC;
    do {
        Qrem=qe.size();
        ipC=mu.menu2(Qrem,SerCus);
        switch(ipC){
        case 1:
            if (Qrem==0 && SerCus==0) {
                SerCus = ++NewCus;
                break;
            }
            qe.enqueue(++NewCus);
            break;
        case 2:
            if(SerCus>0){
                long acno,iniBal;
                string fnm, lnm, acctype;
                SerCus=qe.dequeue();
                cout<<endl<<"Enter Details: "<<endl;
                cout<<"Enter Accout No: "; cin>>acno;
                cout<<"Enter first name: "; cin>>fnm;
                cout<<"Enter last name: "; cin>>lnm;
                cout<<"Enter Account type: "; cin>>acctype;
                cout<<"Enter initial deposit: "; cin>>iniBal;
                if (iniBal<5000){
                  cout<<"Account can't be open "<<endl;
                  cout<<"Initial balance to open an account is 5000 "<<endl;
                }
                else{
                  cout<<"Account opened with balance "<<iniBal<<endl;
                  bk.setdata(acno,iniBal,fnm,lnm,acctype);
                  bk.display();
                  bk.saveNewData();
                }   
            }
            else
                cout<<"No customer at service"<<endl;
            break;
        case 3:
            if(SerCus>0) {
                SerCus = qe.dequeue();
                bk.retriveData();
            }
            else
                cout<<"No customer at service"<<endl;
            break;
        case 0:
            break;
        default:
            cout<<"Invalid input"<<endl;
        }
        
    }while(ipC != 0);

    return ipC;
}

int main() {
    clsMain m;
    m.mainMenuCalc();

    return 0;
}

