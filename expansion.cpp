#include "headings.h"

int random3;
int random4;

string to_lower(string unfinished) {
  transform(unfinished.begin(), unfinished.end(), unfinished.begin(), [](unsigned char c) {return tolower(c);});
  return unfinished;
}


int player1_start_combat() {
  cout player1_name << " action: ", cin player1_action;
  player1_action = to_lower(player1_action);
  if (player1_action = "attack") {
    random3 = rand() % 100 + 1;
    if (player1_def >= random3) {
      cout << "Player 1 Blockes Attack!" << endl;
    }
    else if (player1_def < random3) {
      cout << Player 1 takes << player2_dmg << endl;
      player1_hp = player1_hp - player2_dmg;
    }
  }
}


int player1_start_combat(int random3, int random4) {
  cout << player1_name << " action: ", cin >> player1_action;
  player1_action = to_lower(player1_action);
  cout << player2_name << " action: ", cin >> player2_action;
  player2_action = to_lower(player2_action);

  if ((player1_action == "attack")&&(player2_action == "attack")) {
    cout << player1_name << " defense: " << random3 << endl;
    if (random3 < player1_def) {
      cout << player1_name << " blockes attack!" << endl;
    }
    else {
      player1_hp = player1_hp - player2_dmg;
      cout << player1_name << " takes " << player2_dmg << " dmg" << endl;
    }
    cout << player2_name << " defense: " << random4 << endl;
    if (random4 < player2_def) {
      cout << player2_name << " blockes attack!" << endl;
    }
    else {
      player2_hp = player2_hp - player1_dmg;
      cout << player2_name << " takes " << player1_dmg << " dmg" << endl;
    }
  }
  else if ((player1_action == "attack")&&(player2_action != "attack")) {
    cout << player2_name << " fails to attack!" << endl;
    cout << player2_name << " defense: " << random4 << endl;
    if (random4 < player2_def) {
      cout << player2_name << " blockes attack!" << endl;
    }
    else {
      player2_hp = player2_hp - player1_dmg;
      cout << player2_name << " takes " << player1_dmg << " dmg" << endl;
    }
  }
  else if ((player1_action != "attack")&&(player2_action == "attack")) {
    cout << player1_name << " fails to attack!" << endl;
    cout << player1_name << " defense: " << random3 << endl;
    if (random3 < player1_def) {
      cout << player1_name << " blockes attack!" << endl;
    }
    else {
      player1_hp = player1_hp - player2_dmg;
      cout << player1_name << " takes " << player2_dmg << " dmg" << endl;
    }
  }
  return 0;
}
int player2_start_combat(int random3, int random4) {  
  cout << player2_name << " action: ", cin >> player2_action;
  player2_action = to_lower(player2_action);
  cout << player1_name << " action: ", cin >> player1_action;
  player1_action = to_lower(player1_action);

  random3 = rand() % 100 + 1;   //Player1 def chance random
  random4 = rand() % 100 + 1;   //Player2 def chance random

  if ((player1_action == "attack")&&(player2_action == "attack")) {
    cout << player2_name << " defense: " << random4 << endl;
    if (random4 < player2_def) {
      cout << player2_name << " blockes attack!" << endl;
    }
    else {
      player2_hp = player2_hp - player1_dmg;
      cout << player2_name << " takes " << player1_dmg << " dmg" << endl;
    }    
    cout << player1_name << " defense: " << random3 << endl;
    if (random3 < player1_def) {
      cout << player1_name << " blockes attack!" << endl;
    }
    else {
      player1_hp = player1_hp - player2_dmg;
      cout << player1_name << " takes " << player2_dmg << " dmg" << endl;
    }
  }
  else if ((player1_action == "attack")&&(player2_action != "attack")) {
    cout << player2_name << " fails to attack!" << endl;
    cout << player2_name << " defense: " << random4 << endl;
    if (random4 < player2_def) {
      cout << player2_name << " blockes attack!" << endl;
    }
    else {
      player2_hp = player2_hp - player1_dmg;
      cout << player2_name << " takes " << player1_dmg << " dmg" << endl;
    }
  }
  else if ((player1_action != "attack")&&(player2_action == "attack")) {
    cout << player1_name << " fails to attack!" << endl;
    cout << player1_name << " defense: " << random3 << endl;
    if (random3 < player1_def) {
      cout << player1_name << " blockes attack!" << endl;
    }
    else {
      player1_hp = player1_hp - player2_dmg;
      cout << player1_name << " takes " << player2_dmg << " dmg" << endl;
    }
  }
  return 0;
}
