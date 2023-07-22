from sqlalchemy.ext.declarative import declarative_base
from sqlalchemy import *

Base = declarative_base()

# define Color class
class Color(Base):
    # __tablename__ = 'COLOR'
    # COLOR_ID = Column(Integer, primary_key=True)
    # NAME = Column(String)
    __tablename__ = 'color'
    color_id = Column(Integer, primary_key=True)
    name = Column(String)

# define State class
class State(Base):
    # __tablename__ = 'STATE'
    # STATE_ID = Column(Integer, primary_key=True)
    # NAME = Column(String)
    __tablename__ = 'state'
    state_id = Column(Integer, primary_key=True)
    name = Column(String)

# define Team class
class Team(Base):
    # __tablename__ = 'TEAM'
    # TEAM_ID = Column(Integer, primary_key=True)
    # NAME = Column(String)
    # STATE_ID = Column(Integer, ForeignKey('STATE.STATE_ID'))
    # COLOR_ID = Column(Integer, ForeignKey('COLOR.COLOR_ID'))
    # WINS = Column(Integer)
    # LOSSES = Column(Integer)
    __tablename__ = 'team'
    team_id = Column(Integer, primary_key=True)
    name = Column(String)
    state_id = Column(Integer, ForeignKey('state.state_id'))
    color_id = Column(Integer, ForeignKey('color.color_id'))
    wins = Column(Integer)
    losses = Column(Integer)

# define Player class
class Player(Base):
    # ??????????????????????????????
    # __tablename__ = 'PLAYER'
    # PLAYER_ID = Column(Integer, primary_key=True)
    # TEAM_ID = Column(Integer, ForeignKey('TEAM.TEAM_ID'))
    # UNIFORM_NUM = Column(Integer)
    # FIRST_NAME = Column(String)
    # LAST_NAME = Column(String)
    # MPG = Column(Integer)
    # PPG = Column(Integer)
    # RPG = Column(Integer)
    # APG = Column(Integer)
    # SPG = Column(Double)
    # BPG = Column(Double)
    #team = relationship("Team", back_populates="players")

    __tablename__ = 'player'
    player_id = Column(Integer, primary_key=True)
    team_id = Column(Integer, ForeignKey('team.team_id'))
    uniform_num = Column(Integer)
    first_name = Column(String)
    last_name = Column(String)
    mpg = Column(Integer)
    ppg = Column(Integer)
    rpg = Column(Integer)
    apg = Column(Integer)
    spg = Column(Double)
    bpg = Column(Double)