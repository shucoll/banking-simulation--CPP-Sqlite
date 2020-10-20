#include<iostream>
#include<string>
#include<sstream>
#include<fstream>

using namespace std;

class userInfo {
    public:
    string fname;
    string lname;
    int age;
    string phNo;
    int uId;
    string occup;

};

class server {
    public:
    void getInfo();
    void putInfo();
};

void server::putInfo() {
    userInfo ufo;
    
    FILE *iuf;
    iuf=fopen("Ids.txt","rb");
    if(iuf) {
       fseek(iuf,-10,SEEK_END);
       int exID;
       fscanf(iuf,"%d",&exID);
       cout<<"number "<<exID<<endl;



        stringstream ss;
        ss<<exID;
        string chID=ss.str();        
        cout<<"string "<<chID<<endl;

        fstream ouf;
        ouf.open(chID,ios::out);
        if(ouf.is_open()) {
            cout<<"Enter User first name"<<endl;
            //ufo.getFName();
            cin>>ufo.fname;
            cout<<"Enter age"<<endl;
            cin>>ufo.age;
            ouf<<ufo.fname<<endl;
            ouf<<ufo.age<<endl;
        }
        else cout<<"Cant write"<<endl;
    }
    else cout<<"Cant read"<<endl;
}

int main() {
    server st;
    st.putInfo();
}