#include "headings.h"
using namespace std;

void shop1(string action) {
  if (action == "hp") {
    cout << player1_hp;
    player1_hp += 5;
    cout << "=>" << player1_hp << endl;
    player1_hpcap += 5;
  }
  else if (action == "dmg") {
    cout << player1_dmg;
    player1_dmg++;
    cout << "=>" << player1_dmg << endl;
  }
  else if (action == "crit") {
    cout << player1_crit_chance;
    player1_crit_chance += 2;
    cout << "=>" << player1_crit_chance << endl;
  }
  else if (action == "defence") {
    cout << player1_def;
    player1_def++;
    cout << "=>" << player1_def << endl;
  }
}
void shop2(string action) {
  if (action == "hp") {
    cout << player2_hpcap;
    player2_hpcap += 5;
    cout << "=>" << player2_hpcap << endl;
  }
  else if (action == "dmg") {
    cout << player2_dmg;
    player2_dmg++;
    cout << "=>" << player2_dmg << endl;
  }
  else if (action == "crit") {
    cout << player2_crit_chance;
    player2_crit_chance += 2;
    cout << "=>" << player2_crit_chance << endl;
  }
  else if (action == "defence") {
    cout << player2_def;
    player2_def++;
    cout << "=>" << player2_def << endl;
  }
}
void upgrade_phase() {
  cout << player1_name << endl;    
  cout << "\n\e[1mSHOP\e[0m↓↓↓↓" << endl;
  cout << "\e[1m Health+, Dmg+, Crit+, Defence+ \e[0m" << endl;
  cout << " +5 Hp, +1 Dmg, +2% Crit, +1 Def" << endl;
  cout << player1_name << ": ", getline(cin, player1_action);
  cout << endl;
  player1_action = to_lower(player1_action);
  shop1(player1_action);
  cout << player2_name << ": ", getline(cin, player2_action);
  cout << endl;
  player2_action = to_lower(player2_action);
  shop2(player2_action);
}
