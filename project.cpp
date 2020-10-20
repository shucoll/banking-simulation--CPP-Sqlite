#include<iostream>
#include<string>

#include "LQueue.h"
#include "Menus.h"
#include "BankModel.h"

using namespace std;

class ClsMain:public Menus,private Bank {

    int Qrem;
    int SerCus;
    int NewCus;
    Queue qe;

    public:
    ClsMain();
    void mainMenuCalc();
    int cusMenuCalc();

};


ClsMain::ClsMain() {
    Qrem=0;
    SerCus=0;
    NewCus=0; 
}


void ClsMain:: mainMenuCalc() {
    int ipM;
    
    do{
        Qrem=qe.size();
        ipM = menu1(Qrem,SerCus);

        switch (ipM){
        case 1:
            qe.enqueue(++NewCus);
            break;
        case 2:
            if(NewCus>0){
                SerCus=qe.dequeue();
                //ipM=cusMenuCalc();
                return;
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

int ClsMain::cusMenuCalc() {
    int ipC,ipR;

    do {
        Qrem=qe.size();
        ipC = menu2(Qrem,SerCus);
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
                bool check;
                string fnm, lnm, acctype;

                cout<<endl<<"Enter Details: "<<endl;
                SerCus = qe.dequeue();
                do{
                    cout<<"Enter Accout No: "; 
                    cin>>acno;
                    setAcno(acno);
                    check = openAccNoCheck();
                }while(check!=true);

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
                  setdata(acno,iniBal,fnm,lnm,acctype);
                  display();
                  saveNewData();
                }   
            }
            else
                cout<<"No customer at service"<<endl;
            break;

        case 3:
            if(SerCus>0) {
                int id;
                cout<<"Enter the id of the customer: ";cin>>id;
                SerCus = qe.dequeue();
                setID(id);
                bool check = retriveData();
                long currAmt = getBal();
                if (check) {
                    do {
                        ipR = menu3(SerCus);

                        switch(ipR) {

                            case 1:
                                retriveData();
                                currAmt = getBal();
                            break;

                            case 2:
                                long wdAmt;
                                cout<<"Enter the amount to withdraw: "; cin>>wdAmt;

                                if(currAmt - wdAmt < 5000) cout<<"Can't withdraw, balance will fall below 5000"<<endl;
                                else {
                                    // withdraw and update database
                                    setBal(currAmt - wdAmt);
                                    updateData(0); 
                                    currAmt = getBal();
                                }

                            break;

                            case 3:
                                long depAmt;
                                cout<<"Enter the amount to deposit: "; cin>>depAmt;
                                // deposit and update database
                                setBal(currAmt + depAmt);
                                updateData(1); 
                                currAmt = getBal();
                            break;

                            case 4:
                            break;

                            case 0:
                                ipC = 0;
                            break;

                            default:
                            cout<<"Invalid input"<<endl;
                        }
                    }while(ipR != 0 && ipR != 4);
                }
                
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
    ClsMain m;
    m.mainMenuCalc();
    m.cusMenuCalc();

    return 0;
}

