#include "query_funcs.h"


void add_player(connection *C, int team_id, int jersey_num, string first_name, string last_name,
                int mpg, int ppg, int rpg, int apg, double spg, double bpg)
{
    stringstream sqlCode;
    work W(*C);
    sqlCode << "INSERT INTO PLAYER (TEAM_ID, UNIFORM_NUM, FIRST_NAME, LAST_NAME, MPG, PPG, RPG, APG, SPG, BPG) VALUES ("
    << team_id << ", " << jersey_num << ", " << W.quote(first_name) << ", " << W.quote(last_name) << ", " << mpg << ", " 
    << ppg << ", " << rpg << ", " << apg << ", " << spg << ", " << bpg << ");";
    W.exec(sqlCode.str());
    W.commit();
}


void add_team(connection *C, string name, int state_id, int color_id, int wins, int losses)
{
    stringstream sqlCode;
    work W(*C);
    sqlCode << "INSERT INTO TEAM (NAME, STATE_ID, COLOR_ID, WINS, LOSSES) VALUES ("
    << W.quote(name) << ", " << state_id << ", " << color_id << ", " << wins << ", " << losses << ");";
    W.exec(sqlCode.str());
    W.commit();

}


void add_state(connection *C, string name)
{
    stringstream sqlCode;
    work W(*C);
    sqlCode << "INSERT INTO STATE (NAME) VALUES (" << W.quote(name) << ");";
    W.exec(sqlCode.str());
    W.commit();

}


void add_color(connection *C, string name)
{
    stringstream sqlCode;
    work W(*C);
    sqlCode << "INSERT INTO COLOR (NAME) VALUES (" << W.quote(name) << ");";
    W.exec(sqlCode.str());
    W.commit();

}

/*
 * All use_ params are used as flags for corresponding attributes
 * a 1 for a use_ param means this attribute is enabled (i.e. a WHERE clause is needed)
 * a 0 for a use_ param means this attribute is disabled
 */
//Use BETWEEN AND??????????
void query1(connection *C,
	    int use_mpg, int min_mpg, int max_mpg,
        int use_ppg, int min_ppg, int max_ppg,
        int use_rpg, int min_rpg, int max_rpg,
        int use_apg, int min_apg, int max_apg,
        int use_spg, double min_spg, double max_spg,
        int use_bpg, double min_bpg, double max_bpg)
{
    stringstream query1Code;
    query1Code << "SELECT * FROM PLAYER";
    int numOfCondition = 0;
    if (use_mpg) {
        if (numOfCondition == 0){
            query1Code << " WHERE ";
        }else{
            query1Code << " AND ";
        }
        query1Code << "MPG" << " >= " << min_mpg << " AND " << "MPG" << " <= " << max_mpg;
        numOfCondition++;
    }
    if (use_ppg) {
        if (numOfCondition == 0){
            query1Code << " WHERE ";
        }else{
            query1Code << " AND ";
        }
        query1Code << "PPG" << " >= " << min_ppg << " AND " << "PPG" << " <= " << max_ppg;
        numOfCondition++;
    }
    if (use_rpg) {
        if (numOfCondition == 0){
            query1Code << " WHERE ";
        }else{
            query1Code << " AND ";
        }
        query1Code << "RPG" << " >= " << min_rpg << " AND " << "RPG" << " <= " << max_rpg;
        numOfCondition++;
    }
    if (use_apg) {
        if (numOfCondition == 0){
            query1Code << " WHERE ";
        }else{
            query1Code << " AND ";
        }
        query1Code << "APG" << " >= " << min_apg << " AND " << "APG" << " <= " << max_apg;
        numOfCondition++;
    }
    if (use_spg) {
        if (numOfCondition == 0){
            query1Code << " WHERE ";
        }else{
            query1Code << " AND ";
        }
        query1Code << "SPG" << " >= " << min_spg << " AND " << "SPG" << " <= " << max_spg;
        numOfCondition++;
    }
    if (use_bpg) {
        if (numOfCondition == 0){
            query1Code << " WHERE ";
        }else{
            query1Code << " AND ";
        }
        query1Code << "BPG" << " >= " << min_bpg << " AND " << "BPG" << " <= " << max_bpg;
        numOfCondition++;
    }
    query1Code << ";";
    nontransaction N(*C);
    result R(N.exec(query1Code.str()));
    cout << "PLAYER_ID TEAM_ID UNIFORM_NUM FIRST_NAME LAST_NAME MPG PPG RPG APG SPG BPG" << endl;
    //The precision after the decimal point of the SPG, BPG should be 1????????????????????????????????
    for (result::iterator i = R.begin(); i != R.end(); ++i) {
        cout << i[0].as<int>() << " " << i[1].as<int>() << " " << i[2].as<int>() << " " << i[3].as<string>()
        << " " << i[4].as<string>() << " " << i[5].as<int>() << " " << i[6].as<int>() << " "<<i[7].as<int>() 
        << " " << i[8].as<int>() << " " << fixed << setprecision(1) << i[9].as<double>() << " " << i[10].as<double>() << endl;
    }
}


void query2(connection *C, string team_color)
{
    stringstream query2Code;
    work W(*C);
    query2Code << "SELECT TEAM.NAME FROM COLOR, TEAM WHERE TEAM.COLOR_ID = COLOR.COLOR_ID AND COLOR.NAME = "
    << W.quote(team_color) << ";";
    W.commit();
    nontransaction N(*C);
    result R(N.exec(query2Code.str()));
    cout << "NAME" << endl;
    for (result::iterator i = R.begin(); i != R.end(); ++i) {
        cout << i[0].as<string>() << endl;
    }
}


void query3(connection *C, string team_name)
{
    stringstream query3Code;
    work W(*C);
    query3Code << "SELECT FIRST_NAME, LAST_NAME FROM PLAYER, TEAM WHERE PLAYER.TEAM_ID = TEAM.TEAM_ID AND TEAM.NAME = "
    << W.quote(team_name) << " ORDER BY PPG DESC;";
    W.commit();
    nontransaction N(*C);
    result R(N.exec(query3Code.str()));
    cout << "FIRST_NAME LAST_NAME" << endl;
    for (result::iterator i = R.begin(); i != R.end(); ++i) {
        cout << i[0].as<string>() << " " << i[1].as<string>() << endl;
    }
}


void query4(connection *C, string team_state, string team_color)
{
    stringstream query4Code;
    work W(*C);
    query4Code << "SELECT UNIFORM_NUM, FIRST_NAME, LAST_NAME FROM PLAYER, COLOR, TEAM, STATE WHERE "
    << "TEAM.COLOR_ID = COLOR.COLOR_ID AND PLAYER.TEAM_ID = TEAM.TEAM_ID AND TEAM.STATE_ID = STATE.STATE_ID AND "
    << "STATE.NAME = " << W.quote(team_state) << " AND "
    << "COLOR.NAME = " << W.quote(team_color) << ";";
    W.commit();
    nontransaction N(*C);
    result R(N.exec(query4Code.str()));
    cout << "UNIFORM_NUM FIRST_NAME LAST_NAME" << endl;
    for (result::iterator i = R.begin(); i != R.end(); ++i) {
        cout << i[0].as<int>() << " " << i[1].as<string>() << " " << i[2].as<string>() << endl;
    }
}


void query5(connection *C, int num_wins)
{
    stringstream query5Code;
    work W(*C);
    query5Code << "SELECT FIRST_NAME, LAST_NAME, NAME, WINS FROM PLAYER, TEAM WHERE "
    << "PLAYER.TEAM_ID = TEAM.TEAM_ID AND TEAM.WINS >" << num_wins << ";";
    W.commit();
    nontransaction N(*C);
    result R(N.exec(query5Code.str()));
    cout << "FIRST_NAME LAST_NAME NAME WINS" << endl;
    for (result::iterator i = R.begin(); i != R.end(); ++i) {
        cout << i[0].as<string>() << " " << i[1].as<string>() << " " << i[2].as<string>() << " " << i[3].as<int>() << endl;
    }
}
