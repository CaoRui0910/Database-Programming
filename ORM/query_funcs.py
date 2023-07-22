from sqlalchemy import *
from classes_def import *

def query1(session, use_mpg, min_mpg, max_mpg, use_ppg, min_ppg, max_ppg, use_rpg, min_rpg, max_rpg, use_apg, min_apg, max_apg, use_spg, min_spg, max_spg, use_bpg, min_bpg, max_bpg):
    filters = []
    if use_mpg:
        filters.append(and_(Player.mpg >= min_mpg, Player.mpg <= max_mpg))
    if use_ppg:
        filters.append(and_(Player.ppg >= min_ppg, Player.ppg <= max_ppg))
    if use_rpg:
        filters.append(and_(Player.rpg >= min_rpg, Player.rpg <= max_rpg))
    if use_apg:
        filters.append(and_(Player.apg >= min_apg, Player.apg <= max_apg))
    if use_spg:
        filters.append(and_(Player.spg >= min_spg, Player.spg <= max_spg))
    if use_bpg:
        filters.append(and_(Player.bpg >= min_bpg, Player.bpg <= max_bpg))
    players = session.query(Player).filter(*filters).all()
    print("PLAYER_ID TEAM_ID UNIFORM_NUM FIRST_NAME LAST_NAME MPG PPG RPG APG SPG BPG")
    for player in players:
        print(f"{player.player_id} {player.team_id} {player.uniform_num} {player.first_name} {player.last_name} {player.mpg} {player.ppg} {player.rpg} {player.apg} {player.spg} {player.bpg}")

def query2(session, team_color):
    teams = session.query(Team).join(Color).filter(Color.name == team_color).all()
    print("NAME")
    for team in teams:
        print(f"{team.name}")


def query3(session, team_name):
    players = session.query(Player).join(Team).filter(Team.name == team_name).order_by(Player.ppg.desc()).all()
    print("FIRST_NAME LAST_NAME")
    for player in players:
        print(f"{player.first_name} {player.last_name}")

def query4(session, team_state, team_color):
    players = session.query(Player).join(Team).join(State).join(Color).filter(and_(State.name == team_state, Color.name == team_color)).all()
    print("UNIFORM_NUM FIRST_NAME LAST_NAME")
    for player in players:
        print(f"{player.uniform_num} {player.first_name} {player.last_name}")


def query5(session, num_wins):
    teams = session.query(Team).filter(Team.wins > num_wins).all()
    print("FIRST_NAME LAST_NAME NAME WINS")
    for team in teams:
        players = session.query(Player).join(Team).filter(Team.team_id == team.team_id).all()
        for player in players:
            print(f"{player.first_name} {player.last_name} {team.name} {team.wins}")