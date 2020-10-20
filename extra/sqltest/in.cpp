#include <iostream> 
#include <sqlite3.h> 
#include <string> 

  
using namespace std; 

class info {
    public:
    string name;
    string surname;
    int age;
    string address;
};
  
static int callback(void* data, int argc, char** argv, char** azColName) 
{ 
    int i; 
    fprintf(stderr, "%s: ", (const char*)data); 
  
    for (i = 0; i < argc; i++) { 
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL"); 
    } 
  
    printf("\n"); 
    return 0; 
} 
  
int main() 
{ 
    info ifo;

    cout<<"Enter name"<<endl;
    getline(cin,ifo.name);
    cout<<"Enter surname"<<endl;
    cin>>ifo.surname;
    cout<<"Enter age"<<endl;
    cin>>ifo.age;
    cout<<"Enter address"<<endl;
    cin>>ifo.address;

    cout<<"name is"<<ifo.name<<endl;
    sqlite3* DB;
    sqlite3_stmt* st;
    
    int exit = sqlite3_open("example.db", &DB); 
    if ( exit != SQLITE_OK) {
        cout<< "Couldnt Open database."<<endl;
    }
    else {
        //string query = "SELECT * FROM PERSON;";     
    
    
        string sql = "INSERT INTO PERSON(NAME,SURNAME,AGE,ADDRESS) VALUES (?,?,?,?);";

        exit=sqlite3_prepare(DB, sql.c_str(), -1, &st, NULL);
        if (exit == SQLITE_OK) {
            sqlite3_bind_text(st, 1, ifo.name.c_str(), ifo.name.length(), SQLITE_TRANSIENT);
            sqlite3_bind_text(st, 2, ifo.surname.c_str(), ifo.surname.length(), SQLITE_TRANSIENT);
            sqlite3_bind_int(st, 3, ifo.age);
            sqlite3_bind_text(st,4, ifo.address.c_str(), ifo.address.length(), SQLITE_TRANSIENT);
            sqlite3_step(st);

            cout << "Records created Successfully!" <<endl; 

            int last_id = sqlite3_last_insert_rowid(DB);
            printf("The last Id of the inserted row is %d\n", last_id);
        }
        else {
            
            fprintf(stderr, "Failed to execute statement: %s\n", sqlite3_errmsg(DB));
        }

        sqlite3_finalize(st);
        sqlite3_close(DB); 
    }
    
    cout<<"After closing"<<endl;
    return 0; 
}  