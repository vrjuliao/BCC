#include <bits/stdc++.h>
#define f first
#define s second
#define _ ios::sync_with_stdio(false);cin.tie(0);

using namespace std;

typedef long long int ll;
typedef pair<int,int> ii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int MAX = 1e5 + 10;

struct player {
    vector<int> cards;
};

unordered_map<char, int> cards_map = {
    {'A', 1}, {'2', 2}, {'3', 3}, {'4', 4}, {'5', 5},
    {'6', 6}, {'7', 7}, {'8', 8}, {'9', 9}, {'D', 10},
    {'Q', 11}, {'J', 12}, {'K', 13}
};


int pop(player &p){
    int to_pop = 0;
    for(int i=1; i<p.cards.size(); ++i){
        if(p.cards[i] > 0 && p.cards[to_pop] > p.cards[i]) {
            to_pop = i;
        }
    }
    --p.cards[to_pop];
    return to_pop;
}

void push(player &p, int card){
    ++p.cards[card];
}

bool is_winner(player &p){
    for(int card_qtt: p.cards) {
        if(card_qtt == 4) return true;
    }
    return false;
}
void show_hand(player &p){
    for(int i=1; i<p.cards.size(); ++i){
        if (p.cards[i]) {
            cout << p.cards[i] << "x" << i << ' ';
        }
    }
}

int play_round(vector<player> &players, int first){
    int size = players.size();
    cout << "player: " << first%size << " -" << endl;
    show_hand(players[first%size]);
    int to_remove = pop(players[first%size]);
    cout << "-> " << to_remove << endl;
    push(players[(first+1)%size], to_remove);
    for(int i=1; i<size; ++i){
        if(is_winner(players[(i+first)%size])) return (i+first)%size;
    show_hand(players[(i+first)%size]);
        to_remove = pop(players[(i+first)%size]);
    cout << "-> " << to_remove << endl;
        push(players[(i+first+1)%size], to_remove);
    }
    cout << "==================" << endl;

    return -1;
}

int main (void) {_
    int pqtt, start;
    cin >> pqtt >> start;
    vector<player> players = vector<player>(pqtt, player());
    for(int i=0; i<pqtt; ++i){
        string st;
        cin >> st;
        players[i].cards = vector<int>(14,0);
        players[i].cards[0] = 10;
        for(char c: st)
            ++players[i].cards[cards_map[c]];
        
    }
    --start;
    for(int i=0; i<players.size(); ++i){
        // show_hand(players[i]);
        // cout << endl;
        if(is_winner(players[i]) && i!=start){
            cout << i+1 << endl;
            return 0;
        }
    }
    // cout << "===========" << endl;
    int winner = -1;
    // int rounds = 3;
    while(winner < 0) {
        winner = play_round(players, start%pqtt);
        if(is_winner(players[start%pqtt])) winner = start%pqtt;
        ++start;
        // if(!rounds) return 0;
        // --rounds;
    }
    cout << winner+1 << endl;
	return 0;
}
