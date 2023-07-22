from sqlalchemy import *
from sqlalchemy.orm import sessionmaker
from classes_def import *
from query_funcs import *
# create engine and session
# ???????????????????????????????
engine = create_engine("postgresql+psycopg2://postgres:passw0rd@0.0.0.0:5432/ACC_BBALL", echo=True)
Session = sessionmaker(bind=engine)
session = Session()

# Base = declarative_base()

print('Query 1--1:')
query1(session, 1, 35, 40, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
print('Query 1--2:')
# 130 10 32 Steve Vasturia 35 13 4 3 1.2 0.1
query1(session, 1, 35, 40, 0, 0, 0, 1, 1, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0);

print('Query 2--1:')
# Miami
query2(session, "Green");
print('Query 2--2:')
# UNC
query2(session, "LightBlue");

print('Query 3--1:')
# Luke Kennard
# Jayson Tatum
# Grayson Allen
# Frank Jackson
# Amile Jefferson
# Matt Jones
# Harry Giles
# Chase Jeter
# Antonio Vrankovic
# Jack White
# Javin DeLaurier
# Marques Bolden
# Justin Robinson
# Nick Pagliuca
# Brennan Besser
query3(session, "Duke");
print('Query 3--2:')
# Jaron Blossomgame
# Shelton Mitchell
# Avry Holmes
# Marcquise Reed
# Elijah Thomas
# Donte Grantham
# Gabe DeVoe
# Sidy Djitte
# Scott Spencer
# Legend Robertin
# Isaac Fields
# Ty Hudson
# Lyles Davis
# Riley McGillan
query3(session, "Clemson");

print('Query 4--1:')
# Dennis SmithJr. 4
# Terry Henderson 3
# Maverick Rowan 24
# Abdul-Malik Abu 0
# Torin Dorn 2
# Omer Yurtseven 14
# Ted Kapita 23
# Markell Johnson 11
# BeeJay Anya 21
# Shaun Kirk 22
# Chris CorchianiJr. 13
# Tucker Thompson 42
# Darius Hicks 5
# Chris Brickhouse 15
query4(session, "NC", "Red");
print('Query 4--2:')
query4(session, "VA", "DarkBlue");


print('Query 5--1:')
# Andrew WhiteIII UNC 14
# Tyler Lydon UNC 14
# Tyus Battle UNC 14
# John Gillon UNC 14
# Taurean Thompson UNC 14
# DaJuan Coleman UNC 14
# Tyler Roberson UNC 14
# Frank Howard UNC 14
# Paschal Chukwu UNC 14
# Ray Featherston UNC 14
# Doyin Akintobi-Adeyeye UNC 14
# Adrian Autry UNC 14
# Ky Feldman UNC 14
# Shaun Belbey UNC 14
# Mike Sutton UNC 14
# Evan Dourdas UNC 14
# Jonathan Radner UNC 14
query5(session, 12);
print('Query 5--2:')
query5(session, 10);

print('Test Finish')

session.close()