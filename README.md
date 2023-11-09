# Database-Programming
- In this project, C++ was utilized to interact with a Postgres database and implement various functions.
- Also, used ORM (SQLAlchemy and Python) to interact with a Postgres database and implement various functions.

### Table of Contents
1. [Datatbase](#Datatbase)
2. [Functions](#Functions)
3. [Notes](#Notes)
4. [ORM (SQLAlchemy and Python)](#ORM (SQLAlchemy and Python))

### Datatbase
- PLAYER (PLAYER_ID, TEAM_ID, UNIFORM_NUM, FIRST_NAME, LAST_NAME, MPG, PPG, RPG, APG, SPG, BPG)
- TEAM (TEAM_ID, NAME, STATE_ID, COLOR_ID, WINS, LOSSES)
- STATE (STATE_ID, NAME)
- COLOR (COLOR_ID, NAME)

### Functions
- query1(): show all attributes of each player with average statistics that fall between the min and max (inclusive) for each enabled statistic
- query2(): show the name of each team with the indicated uniform color
- query3(): show the first and last name of each player that plays for the indicated team, ordered from highest to lowest ppg (points per game)
- query4(): show uniform number, first name and last name of each player that plays in the indicated state and wears the indicated uniform color
- query5(): show first name and last name of each player, and team name and number of wins for each team that has won more than the indicated number of games


### Notes
- Database source text files: player.txt, team.txt, state.txt, color.txt.
- main.cpp: The main function. This file implement code which will setup the database on each execution of the program. Specifically, it drop (if needed) and add each table to the database (named ACC_BBALL), and then read information from the source text files and add rows to each table as appropriate.
- query_funcs.h and query_funcs.cpp: implement functions to interact with the database.
- exerciser.h and exerciser.cpp: add code in the exercise() function to test query functions. The exercise() function is called from main() after the database is initialized.


### ORM (SQLAlchemy and Python)
- Choose one ORM library (SQLAlchemy) and implement the five queries shown in the previous statement.




