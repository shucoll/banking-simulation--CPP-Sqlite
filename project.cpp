#include<iostream>
#include<string>
#include<chrono>
#include<vector>
#include<iomanip>

#include "LQueue.h"
#include "menus.h"
#include "bankModel.h"

using namespace std;


class Timer {
    protected:
    vector< chrono::duration<float> >avrDur;
    vector< chrono::duration<float> >dprDur;
    vector< chrono::duration<float> >serDur;
    vector< chrono::duration<float> >inQDur;
    vector< chrono::duration<float> >svrIDur;
    chrono::time_point<chrono::steady_clock>now;
    chrono::time_point<chrono::steady_clock>begin;

    vector< chrono::duration<float> >::iterator avr;
    vector< chrono::duration<float> >::iterator dpr;
    vector< chrono::duration<float> >::iterator ser;
    vector< chrono::duration<float> >::iterator inQ;
    vector< chrono::duration<float> >::iterator svrI;

    chrono::duration<float> serTotl;
    chrono::duration<float> inQTotl;
    chrono::duration<float> svrITotl;
};


class ClsMain:public Menus,private Bank,private Timer {

    int Qrem;
    int SerCus;
    int NewCus;
    Queue qe;

    public:
    ClsMain();
    int mainMenuCalc();
    int cusMenuCalc();
    void bankMenuCalc(int,int&,int&);
    void reportGenerator();
};


ClsMain::ClsMain() {
    Qrem=0;
    SerCus=0;
    NewCus=0; 
}

void ClsMain::reportGenerator() {

    cout<<"Generating report..."<<endl<<endl;

    int ipR;
    int i =1;

    int totSrv = 0, totInQ = 0;
    float avgSerT, avgQT, pobSvrIT;


    dpr = dprDur.begin();
    avr = avrDur.begin();


    while(dpr < dprDur.end() && avr < avrDur.end() ) {
        if(dpr == dprDur.begin() && avr == avrDur.begin()) {
            inQDur.push_back(begin-begin);
            svrIDur.push_back(begin-begin);
            dpr++;
            avr++;
        }
        else {
            if(*avr > *(dpr-1)) {
                svrIDur.push_back(*avr - *(dpr-1));
                inQDur.push_back(begin-begin);
            }
            else if(*avr < *(dpr-1)) {
                inQDur.push_back(*(dpr-1) - *avr);
                svrIDur.push_back(begin-begin);
                totInQ++;
            }
            dpr++;
            avr++;
        }
    }

    dpr = dprDur.begin();
    avr = avrDur.begin();
    inQ = inQDur.begin();

    while(dpr < dprDur.end() && avr < avrDur.end() && inQ < inQDur.end() ) {
        serDur.push_back(*dpr - *avr - *inQ);
        dpr++;
        avr++;
        inQ++;

        totSrv++;
    }

    cout<<"Report Generation Successful!"<<endl<<endl;


    do{

        ipR = menu4();
        switch (ipR) {

            case 1: 
                dpr = dprDur.begin();
                avr = avrDur.begin();
                inQ = inQDur.begin();
                svrI = svrIDur.begin();
                ser = serDur.begin();
                i=1;

                cout<<endl<<"    Customer   "<<"Arrival Time   "<<"Service Time   "<<"Departure Time   "<<"Time in queue   "<<"Server ideal"<<endl;

                while(inQ<inQDur.end() && svrI<svrIDur.end() && ser < serDur.end() && dpr < dprDur.end() && avr < avrDur.end() ) {

                    cout<<"        "<<i<<"\t"
                    <<fixed<<setprecision(2)<<(*avr).count()<<"\t\t"
                    <<fixed<<setprecision(2)<<(*ser).count()<<"\t\t"
                    <<fixed<<setprecision(2)<<(*dpr).count()<<"\t\t"
                    <<fixed<<setprecision(2)<<(*inQ).count()<<"\t\t"
                    <<fixed<<setprecision(2)<<(*svrI).count()<<endl;


                    inQ++;
                    svrI++;
                    ser++;
                    dpr++;
                    avr++;

                    i++;
                }
            break;

            case 2:
                avgSerT = 0;
                serTotl = begin - begin;
                for(ser = serDur.begin(); ser < serDur.end(); ser++) {
                    serTotl += *ser;
                }

                avgSerT = serTotl.count()/totSrv;
                cout<<"Average Service time is: "<<avgSerT<<endl;

            break;

            case 3:
                avgQT = 0;
                inQTotl = begin - begin;
                for(inQ = inQDur.begin(); inQ<inQDur.end(); inQ++) {
                    inQTotl += *inQ;
                }

                avgQT = inQTotl.count()/totSrv;
                cout<<"Average waiting time of customers: "<<avgQT<<endl;
            break;

            case 4:
                avgQT = 0;
                inQTotl = begin - begin;
                for(inQ = inQDur.begin(); inQ<inQDur.end(); inQ++) {
                    inQTotl += *inQ;
                }

                avgQT = inQTotl.count()/totInQ;
                cout<<"Average waiting time for customers who wait: "<<avgQT<<endl;
            break;

            case 5:
                pobSvrIT = 0;
                svrITotl = begin - begin;
                for(svrI = svrIDur.begin(); svrI<svrIDur.end(); svrI++) {
                    svrITotl += *svrI;
                }

                pobSvrIT = svrITotl.count() / dprDur.back().count();
                cout<<"Probability of ideal time of server is "<<pobSvrIT<<endl;

            break;


            case 0:
            break;

            default:
            cout<<"Invalid Input"<<endl;
        }

    }while(ipR != 0);

}

void ClsMain::bankMenuCalc(int currAmt,int &ipR, int &ipC) {
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

int ClsMain:: mainMenuCalc() {
    int ipM;
    
    do{
        Qrem=qe.size();
        ipM = menu1(Qrem,SerCus);

        switch (ipM){
        case 1:
            SerCus = ++NewCus;
            begin = now = chrono::high_resolution_clock::now();
            avrDur.push_back(now-begin);
            
            return 1;
            //break;
        // case 2:
        //     if(NewCus>0){
        //         SerCus=qe.dequeue();
        //         return 1;
        //     }
        //     else
        //         cout<<"No customer available"<<endl;
        //     break;
        case 0:
            break;
        default:
            cout<<"Invalid input"<<endl;
        }

    }while(ipM != 0);

    return 0;
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
                    now = chrono::high_resolution_clock::now();
                    avrDur.push_back(now-begin);
                    break;
                }
                qe.enqueue(++NewCus);
                now = chrono::high_resolution_clock::now();
                avrDur.push_back(now-begin);
            break;

            case 2:
                if(SerCus>0){
                    long acno,iniBal;
                    bool check;
                    string fnm, lnm, acctype;

                    cout<<endl<<"Enter Details: "<<endl;
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
                    SerCus = qe.dequeue();  
                    now = chrono::high_resolution_clock::now();
                    dprDur.push_back(now-begin); 
                }
                else
                cout<<"No customer at service"<<endl;
            break;

            case 3:
                if(SerCus>0) {
                    int id;
                    cout<<"Enter the id of the customer: ";cin>>id;
                    setID(id);
                    bool check = retriveData();
                    long currAmt = getBal();
                    if (check) 
                        bankMenuCalc(currAmt,ipR,ipC);

                    SerCus = qe.dequeue();
                    now = chrono::high_resolution_clock::now();
                    dprDur.push_back(now-begin);
                    
                }
                else
                cout<<"No customer at service"<<endl;
            break;

            case 4:
                return ipC;

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
    int ipM,ipC;
    
    ipM = m.mainMenuCalc();

    if(ipM == 1)
    ipC = m.cusMenuCalc();

    if(ipC == 4)
    m.reportGenerator();


    return 0;
}

