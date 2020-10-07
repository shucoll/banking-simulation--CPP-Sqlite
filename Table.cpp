#include <iostream> 
#include <sqlite3.h> 
  
int main() 
{ 
    sqlite3* DB; 
    std::string sql = "CREATE TABLE PERSON("
                      "ID INTEGER PRIMARY KEY  AUTOINCREMENT NOT NULL, "
                      "AccNumber       INT  NOT NULL, "
                      "FNAME           TEXT NOT NULL, "
                      "LNAME           TEXT NOT NULL, "
                      "AccType         TEXT NOT NULL,"
                      "Balance         INT NOT NULL);"; 
    int exit = 0; 
    exit = sqlite3_open("Bank.db", &DB); 
    char* messaggeError; 
    exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messaggeError); 
  
    if (exit != SQLITE_OK) { 
        std::cerr << "Error Create Table" << std::endl; 
        sqlite3_free(messaggeError); 
    } 
    else
        std::cout << "Table created Successfully" << std::endl; 
    sqlite3_close(DB); 

    return 0; 
}