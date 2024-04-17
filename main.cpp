#include <iostream>
#include <map>
#include <string>
#include <list>
#include <algorithm>
#include <cstdio>
#include <iterator>
using namespace std;

#include "expansion.cpp"
#include "expansion2.cpp"
#include "headings.h"

string player1_action;
string player2_action;

string player1_name;
string player2_name;

int assassin_hp = 30;
int assassin_dmg = 8;
float assassin_crit_chance = 5;
int draw_init_assassin = 4;

int knight_hp = 40;
int knight_dmg = 6;
float knight_crit_chance = 10;
int draw_init_knight = 3;

int demon_hp = 35;
int demon_dmg = 7;
float demon_crit_chance = 25;
int draw_init_demon = 2;

int goblin_hp = 15;
int goblin_dmg = 10;
float goblin_crit_chance = 5;
int draw_init_goblin = 6;

int tank_hp = 50;
int tank_dmg = 5;
float tank_crit_chance = 5;
int draw_init_tank = 1;

string player1_character;   //Player 1 character
int player1_hp;   //PLAYER 1 HP
int player1_hpcap;
int player1_dmg;    //PLAYER 1 DMG
float player1_crit_chance;    //PLAYER 1 CRIT CHANCE
int player1_initiative;

string player2_character;   //Player 2 character
int player2_hp;   //PLAYER 2 HP
int player2_hpcap;
int player2_dmg;    //PLAYER 2 DMG
float player2_crit_chance;    //PLAYER 2 CRIT CHANCE
int player2_initiative;

int random1;
int random2;
int random5;
int random6;
int random7;
int random8;

int player1_def = 50;
int player2_def = 50;





void display1(string name, string character, int dmg, int hp, float crit, int hpcap) {
  crit = crit * 100;
  cout << "\e[1m" << name << "\e[0m: " << character << "; Dmg: " << dmg << "   crit_chance: " << crit
      << "%    Hp: " << hp << "/" << hpcap;
}
void display2(string name, int dmg, int hp, float crit, int hpcap) {
  crit = crit * 100;
  cout << "\e[1m" << name << "\e[0m" << "; Dmg: " << dmg << "   crit_chance: " << crit
      << "%    Hp: " << hp << "/" << hpcap << endl;
}


void combat_phase() {
  while ((player1_hp > 0)&&(player2_hp > 0)) {
    cout << "\n" << player1_name << " roll for initiative! ", getline(cin,player1_action);
    srand (time(NULL));
    random1 = rand() % 5 + 1;
    cout << random1 << endl;
    cout << player2_name << " roll for initiative! ", getline(cin,player2_action);
    srand (time(NULL));
    random2 = rand() % 5 + 1;
    cout << random2 << endl;
    cout << "\e[1m" << random1 << "\e[0m vs \e[1m" << random2 << "\e[0m" << endl;
    if (random1 > random2) {
      random3 = rand() % 100 + 1;   //Player1 def chance random
      random4 = rand() % 100 + 1;   //Player2 def chance random
      player1_start_combat(random3, random4);
    }
    else if (random1 < random2) {
      random3 = rand() % 100 + 1;   //Player1 def chance random
      random4 = rand() % 100 + 1;   //Player2 def chance random
      player2_start_combat(random3, random4);
    }
    else {
      if (player1_character != player2_character) {
        if (player1_initiative > player2_initiative) {
          random3 = rand() % 100 + 1;   //Player1 def chance random
          random4 = rand() % 100 + 1;   //Player2 def chance random
          player1_start_combat(random3, random4);
        }
        else if (player1_initiative	< player2_initiative) {
          random3 = rand() % 100 + 1;   //Player1 def chance random
          random4 = rand() % 100 + 1;   //Player2 def chance random
          player2_start_combat(random3, random4);
        }
      }
      else {
        cout << "Reroll: ", getline(cin, player1_action);
      }
    }
    display2(player1_name, player1_dmg, player1_hp, player1_crit_chance, player1_hpcap);
    display2(player2_name, player2_dmg, player2_hp, player2_crit_chance, player2_hpcap);
  }
}



int main() {    //PvP TURN-BASED STRATEGY GAME
  cout << "Player 1 choose name: ", getline(cin, player1_action);
  cout << "\nPlayer 2 choose name: ", getline(cin, player2_action);
  player1_name = player1_action;
  player2_name = player2_action;
  cout << "\nPlayable characters \e[1mKnight, Assassin, Demon, Tank, Goblin\e[0m" << endl;
  cout << "Player 1 choose character: ", getline(cin, player1_action);
  cout << "\nPlayable characters \e[1mKnight, Assassin, Demon, Tank, Goblin\e[0m" << endl;
  cout << "Player 2 choose character: ", getline(cin, player2_action);
  player1_action = to_lower(player1_action);
  player2_action = to_lower(player2_action);
  if (player1_action == "assassin") {
    player1_character = "Assassin";
    player1_hp = assassin_hp;
    player1_hpcap = assassin_hp;
    player1_dmg = assassin_dmg;
    player1_crit_chance = assassin_crit_chance;
    player1_initiative = draw_init_assassin;
  }
  else if (player1_action == "knight") {
    player1_character = "Knight";
    player1_hp = knight_hp;
    player1_hpcap = knight_hp;
    player1_dmg = knight_dmg;
    player1_crit_chance = knight_crit_chance;
    player1_initiative = draw_init_knight;
  }
  else if (player1_action == "demon") {
    player1_character = "Demon";
    player1_hp = demon_hp;
    player1_hpcap = demon_hp;
    player1_dmg = demon_dmg;
    player1_crit_chance = demon_crit_chance;
    player1_initiative = draw_init_demon;
  }
  else if (player1_action == "goblin") {
    player1_character = "Goblin";
    player1_hp = goblin_hp;
    player1_hpcap = goblin_hp;
    player1_dmg = goblin_dmg;
    player1_crit_chance = goblin_crit_chance;
    player1_initiative = draw_init_goblin;
  }
  else if (player1_action == "tank") {
    player1_character = "Tank";
    player1_hp = tank_hp;
    player1_hpcap = tank_hp;
    player1_dmg = tank_dmg;
    player1_crit_chance = tank_crit_chance;
    player1_initiative = draw_init_tank;
  }
  else {
    player1_character = "peasant";
    player1_hp = 1;
    player1_hpcap = 1;
    player1_dmg = 1;
    player1_crit_chance = 1;  
    player1_initiative = 5;
  }
  if (player2_action == "assassin") {
    player2_character = "Assassin";
    player2_hp = assassin_hp;
    player2_hpcap = assassin_hp;
    player2_dmg = assassin_dmg;
    player2_crit_chance = assassin_crit_chance;
    player2_initiative = draw_init_assassin;
  }
  else if (player2_action == "knight") {
    player2_character = "Knight";
    player2_hp = knight_hp;
    player2_hpcap = knight_hp;
    player2_dmg = knight_dmg;
    player2_crit_chance = knight_crit_chance;
    player2_initiative = draw_init_knight;
  }
  else if (player2_action == "demon") {
    player2_character = "Demon";
    player2_hp = demon_hp;
    player2_hpcap = demon_hp;
    player2_dmg = demon_dmg;
    player2_crit_chance = demon_crit_chance;
    player2_initiative = draw_init_demon;
  }
  else if (player2_action == "goblin") {
    player2_character = "Goblin";
    player2_hp = goblin_hp;
    player2_hpcap = goblin_hp;
    player2_dmg = goblin_dmg;
    player2_crit_chance = goblin_crit_chance;
    player2_initiative = draw_init_goblin;
  }
  else if (player2_action == "tank") {
    player2_character = "Tank";
    player2_hp = tank_hp;
    player2_hpcap = tank_hp;
    player2_dmg = tank_dmg;
    player2_crit_chance = tank_crit_chance;
    player2_initiative = draw_init_tank;
  }
  else {
    player2_character = "peasant";
    player2_hp = 1;
    player2_hpcap = 1;
    player2_dmg = 1;
    player2_crit_chance = 1;  
    player2_initiative = 5;
  }
    cout << "Player1: ";
    display1(player1_name, player1_character, player1_dmg, player1_hp, player1_crit_chance, player1_hpcap);
    cout << "\n\e[1m VS \e[0m \nPlayer2: ";
    display1(player2_name, player2_character, player2_dmg, player2_hp, player2_crit_chance, player2_hpcap);

  while(true) {
    combat_phase();
    upgrade_phase();
    player1_hp = player1_hpcap;
    player2_hp = player2_hpcap;
    cout << "Player1: ";
    display1(player1_name, player1_character, player1_dmg, player1_hp, player1_crit_chance, player1_hpcap);
    cout << "\n\e[1m VS \e[0m \nPlayer2: ";
    display1(player2_name, player2_character, player2_dmg, player2_hp, player2_crit_chance, player2_hpcap);
  }
  cout << "END!";
  return 0;
}



