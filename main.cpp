#include <iostream>
#include <pqxx/pqxx>

#include "exerciser.h"

#include <fstream>
#include <string>
#include <sstream>

using namespace std;
using namespace pqxx;


void execSqlCode(string sqlCode, connection *C){
  work W(*C);
  W.exec(sqlCode);
  W.commit();
}

void dropTables(connection *C){
  //drop tables that may already exist
  string sqlCode1 = "DROP TABLE IF EXISTS PLAYER CASCADE;";
  execSqlCode(sqlCode1, C);
  string sqlCode2 = "DROP TABLE IF EXISTS TEAM CASCADE;";
  execSqlCode(sqlCode2, C);
  string sqlCode3 = "DROP TABLE IF EXISTS STATE CASCADE;";
  execSqlCode(sqlCode3, C);
  string sqlCode4 = "DROP TABLE IF EXISTS COLOR CASCADE;";
  execSqlCode(sqlCode4, C);
}

void createTables(const char * fileName, connection * C){
  string sqlCodes;
  string line;
  ifstream myfile(fileName);
  if(myfile.is_open()){
    while(getline(myfile, line)){
      sqlCodes += line;
    }
    myfile.close();
    execSqlCode(sqlCodes, C);
  }else{
    cerr<<"createTables: Unable to open file."<<endl;
    return;
  }
}

//Read information from the source text files and add rows to each table as appropriate:
void addColorData(const char * fileName, connection * C){
  int colorId;
  string line;
  //color name
  string name;
  ifstream myfile(fileName);
  if (myfile.is_open()){
    while(getline(myfile, line)){
      stringstream ss;
      ss << line;
      ss >> colorId >> name;
      add_color(C, name);
    }
    myfile.close();
  }else{
    cerr<<"addColorData: Unable to open file."<<endl;
    return;
  }
}

void addStateData(const char * fileName, connection *C){
  int stateId;
  string line;
  //state name
  string name;
  ifstream myfile(fileName);
  if (myfile.is_open()){
    while(getline(myfile, line)){
      stringstream ss;
      ss << line;
      ss >> stateId >> name;
      add_state(C, name);
    }
    myfile.close();
  }else{
    cerr<<"addColorData: Unable to open file."<<endl;
    return;
  }
}

void addTeamData(const char * fileName, connection *C){
  int teamId, stateId, colorId, wins, losses;
  string line;
  //team name:
  string name;
  ifstream myfile(fileName);
  if(myfile.is_open()){
    while(getline(myfile, line)){
      stringstream ss;
      ss << line;
      ss >> teamId >> name >> stateId >> colorId >> wins >> losses;
      add_team(C, name, stateId, colorId, wins, losses);
    }
    myfile.close();
  }else{
    cerr<<"addTeamData: Unable to open file."<<endl;
    return;
  }
}

void addPlayerData(const char * fileName, connection *C){
  string line;
  string firstName, lastName;
  int playerId, teamId, uniformNum, mpg, ppg, rpg, apg;
  double spg, bpg;
  ifstream myfile(fileName);
  if(myfile.is_open()){
    while(getline(myfile, line)){
      stringstream ss;
      ss << line;
      ss >> playerId >> teamId >> uniformNum >> firstName >> lastName >> mpg >> ppg >> rpg >> apg >> spg >> bpg;
      add_player(C, teamId, uniformNum, firstName, lastName, mpg, ppg, rpg, apg, spg, bpg);
    }
    myfile.close();
  }else{
    cerr<<"addPlayerData: Unable to open file."<<endl;
    return;
  }
}


int main (int argc, char *argv[]) 
{

  //Allocate & initialize a Postgres connection object
  connection *C;

  try{
    //Establish a connection to the database
    //Parameters: database name, user name, user password
    C = new connection("dbname=ACC_BBALL user=postgres password=passw0rd");
    if (C->is_open()) {
      //cout << "Opened database successfully: " << C->dbname() << endl;
    } else {
      cout << "Can't open database" << endl;
      return 1;
    }
  } catch (const std::exception &e){
    cerr << e.what() << std::endl;
    return 1;
  }


  //TODO: create PLAYER, TEAM, STATE, and COLOR tables in the ACC_BBALL database
  //      load each table with rows from the provided source txt files
  dropTables(C);
  createTables("createTables.sql", C);
  addColorData("color.txt", C);
  addStateData("state.txt", C);
  addTeamData("team.txt", C);
  addPlayerData("player.txt", C);

  exercise(C);


  //Close database connection
  C->disconnect();

  return 0;
}


