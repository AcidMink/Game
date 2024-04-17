#include "headings.h"

int random3;
int random4;

string to_lower(string unfinished) {
  transform(unfinished.begin(), unfinished.end(), unfinished.begin(), [](unsigned char c) {return tolower(c);});
  return unfinished;
}


void player1_start_combat() {
  cout player1_name << " action: ", cin player1_action;
  player1_action = to_lower(player1_action);
  if (player1_action = "attack") {
    random3 = rand() % 100 + 1;
    if (player2_def >= random3) {
      cout << "Player 2 Blockes Attack!" << endl;
    }
    else if (player2_def < random3) {
      cout << Player 2 takes << player1_dmg << endl;
      player2_hp = player2_hp - player1_dmg;
    }
  }
  else {cout << "Player1 Fails to Attack!" << endl;}
  
  if (player2_hp <= 0) {
    cout << "Player 2 loses" << endl;
  }
  else if (player2_hp > 0) {
    cout player2_name << " action: ", cin player2_action;
    player2_action = to_lower(player2_action);
    if (player2_action = "attack") {
      random4 = rand() % 100 + 1;
      if (player1_def >= random4) {
      cout << "Player 1 Blockes Attack!" << endl;
      }
      else if (player1_def < random3) {
        cout << Player 1 takes << player2_dmg << endl;
        player1_hp = player1_hp - player2_dmg;
      }
    }
    else {cout << "Player 2 Fails to Attack!" << endl;}
  }
}
void player2_start_combat() {
  cout player2_name << " action: ", cin player2_action;
  player2_action = to_lower(player2_action);
  if (player2_action = "attack") {
    random4 = rand() % 100 + 1;
    if (player1_def >= random4) {
      cout << "Player 1 Blockes Attack!" << endl;
    }
    else if (player1_def < random3) {
      cout << Player 1 takes << player2_dmg << endl;
      player1_hp = player1_hp - player2_dmg;
    }
  }
  else {cout << "Player 2 Fails to Attack!" << endl;}
  
  if (player1_hp <= 0) {
    cout << "Player 1 loses" << endl;
  }
  else if (player1_hp > 0) {
    cout player1_name << " action: ", cin player1_action;
    player1_action = to_lower(player1_action);
    if (player1_action = "attack") {
      random3 = rand() % 100 + 1;
      if (player2_def >= random3) {
      cout << "Player 2 Blockes Attack!" << endl;
      }
      else if (player2_def < random3) {
        cout << Player 2 takes << player1_dmg << endl;
        player2_hp = player2_hp - player1_dmg;
      }
    }
    else {cout << "Player 1 Fails to Attack!" << endl;}
  }
}
