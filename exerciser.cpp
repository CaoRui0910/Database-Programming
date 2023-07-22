#include "exerciser.h"

void exercise(connection *C)
{
    query1(C, 1, 35, 40, 0, 5, 19, 0, 0, 20, 0, 2, 4, 0, 0.8, 1.6, 0, 0.4, 3.5);
    //  cout<< "query 2 *******************" << endl;
    query2(C, "Green");
    //  cout<< "query 3 *******************" << endl;
    query3(C, "Duke");
    //  cout<< "query 4 *******************" << endl;
    query4(C, "KY", "LightBlue");
    //
    query5(C, 6);

    query1(C, 1, 35, 40, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
    query1(C, 1, 35, 40, 0, 0, 0, 0, 1, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0);
    query1(C, 0, 35, 40, 1, 9, 19, 0, 5, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0);
    query1(C, 0, 35, 40, 0, 0, 0, 1, 1, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0);
    query1(C, 1, 35, 40, 0, 0, 0, 1, 1, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0);

    query2(C, "Green");
    query2(C, "LightBlue");
    query2(C, "Orange");

    query3(C, "Duke");
    query3(C, "Clemson");
    query3(C, "UNC");
    query3(C, "FloridaState");

    query4(C, "NC", "Red");
    query4(C, "VA", "DarkBlue");
    query4(C, "MA", "Gold");

    query5(C, 12);
    query5(C, 10);


    /*
    query1(C, 1, 35, 40, 0, 0, 0, 1, 1, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0);
    query2(C, "Green");
    query2(C, "LightBlue");
    query3(C, "Duke");
    query3(C, "Clemson");
    query4(C, "NC", "Red");
    query4(C, "VA", "DarkBlue");
    query5(C, 12);
    query5(C, 10);

    */
}
