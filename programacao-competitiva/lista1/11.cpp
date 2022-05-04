
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

struct solution {
	ll attempt, time;
};

struct team {
    ll p1, p2;
	vector<solution> solutions;
};

struct Comparator1 {
    bool operator()(const pair<team, int> &t1, const pair<team, int> &t2){
        if(t1.f.solutions.size() > t2.f.solutions.size()) return true;
        else if (t1.f.solutions.size() == t2.f.solutions.size() && t1.f.p1 < t2.f.p1) return true;
        return false;
    }
};

struct Comparator2 {
    bool operator()(const pair<team, int> &t1, const pair<team, int> &t2){
        if(t1.f.solutions.size() > t2.f.solutions.size()) return true;
        else if (t1.f.solutions.size() == t2.f.solutions.size() && t1.f.p2 < t2.f.p2) return true;
        return false;
    }
};

ll punicao(ll attempt, ll time, ll weight){
    return time + ((attempt-1)*weight);
}

void calc_team_inj(vector<pair<team, int>> &teams, ll weight){
    for(int j=0; j<teams.size(); ++j){
        ll p = 0;
        for(int i=0; i<teams[j].f.solutions.size(); ++i){
            p += punicao(teams[j].f.solutions[i].attempt, teams[j].f.solutions[i].time, weight);
        }
        teams[j].f.p2 = p;
    }
    
}

bool same_order(vector<pair<team, int>> &teams, vector<unordered_set<int>> &initial_order) {
    stable_sort(teams.begin(), teams.end(), Comparator2());
    vector<unordered_set<int>> current_order = vector<unordered_set<int>>(teams.size(), unordered_set<int>());
    int pos = 0;
    ll last_p2 = teams[0].f.p2, last_size = teams[0].f.solutions.size();
    for(int i=0; i<teams.size(); ++i) {
        if(teams[i].f.p2 != last_p2 || teams[i].f.solutions.size() != last_size){
            ++pos;
            last_p2 = teams[i].f.p2;
            last_size = teams[i].f.solutions.size();
        }
        current_order[pos].insert(teams[i].second);
    }

    for(int i=0; i<current_order.size(); ++i){
        for(int t: current_order[i]) {
            if(!initial_order[i].count(t)) return false;
        }
        // cout << "initial_order[i]: " << initial_order[i] << "    teams[i].second: " << teams[i].second << endl;
        // cout << "\t p1:  " <<  teams[i].f.p1 << "    p2: " << teams[i].f.p2 << endl;
        // cout << "\t solvedProblems:  p1: " << teams[i].f.solutions.size() << "   p2: " << teams[i].f.solutions.size() << endl;
        // if(initial_order[i] != teams[i].second) return false;
    }
    return true;
}

int bin_search_upper(vector<pair<team, int>> &teams, int l, int r, vector<unordered_set<int>> &initial_order) {
    int answer = l;
    while(l < r) {
        // cout << l << ' ' << r << endl;
        int middle = (l+r)/2;
        calc_team_inj(teams, middle);
        if(same_order(teams, initial_order)){
            answer = middle;
            l = middle+1;
        } else {
            r = middle-1;
        }
    }
    calc_team_inj(teams, answer+1);
    if(same_order(teams, initial_order))
        return answer+1;
    else
        return answer;
}

int solve_upper_bound(vector<pair<team, int>> &teams, ll r, vector<unordered_set<int>> &initial_order){
    calc_team_inj(teams, r);

    // cout << "solve upper bound start" << endl;
    while(same_order(teams, initial_order) && r < INT_MAX){
        // cout << "r " << r << endl;
        r*=2;
        calc_team_inj(teams, r);
    }
    // cout << "solve upper bound done: " << r << endl;
    if (r > INT_MAX) return -1;
    else {
        int answer = bin_search_upper(teams, r/2, r, initial_order);
        // int next_answer = answer;
        // while(next_answer != -1) {
        //     next_answer = bin_search_upper(teams, r/2, next_answer-1, initial_order)
        // }
        return answer;
    }
};

int bin_search_lower(vector<pair<team, int>> &teams, int l, int r, vector<unordered_set<int>> &initial_order) {
    int answer = r;
    while(l <= r) {
        // cout << l << ' ' << r << endl;
        int middle = (l+r)/2;
        calc_team_inj(teams, middle);
        if(same_order(teams, initial_order)){
            answer = middle;
            r = middle-1;
        } else {
            l = middle+1;
        }
    }
    calc_team_inj(teams, answer-1);
    if(same_order(teams, initial_order))
        return answer-1;
    else
        return answer;
}

int solve_lower_bound(vector<pair<team, int>> &teams, ll l, vector<unordered_set<int>> &initial_order){
    calc_team_inj(teams, l);

    // cout << "solve lower bound start" << endl;
    while(same_order(teams, initial_order) && l > 1){
        // cout << "l " << l << endl;
        l= (l/2)+ (l&1);
        calc_team_inj(teams, l);
    }
    // cout << "solve lower bound done: " << l << endl;
    if (l == 1) return 1;
    else {
        return bin_search_lower(teams, l, l*2, initial_order);
    }
};


void solve (vector<pair<team, int>> &teams) {
    stable_sort(teams.begin(), teams.end(), Comparator1());
    int upperB, lowerB;
    vector<unordered_set<int>> initial_order = vector<unordered_set<int>>(teams.size(), unordered_set<int>());
    int pos = 0;
    ll last_p1 = teams[0].f.p1, last_size = teams[0].f.solutions.size();
    for(int i=0; i<teams.size(); ++i) {
        if(teams[i].f.p1 != last_p1 || teams[i].f.solutions.size() != last_size){
            ++pos;
            last_p1 = teams[i].f.p1;
            last_size = teams[i].f.solutions.size();
        }
        initial_order[pos].insert(teams[i].second);
    }

    upperB = solve_upper_bound(teams, 40, initial_order);
    lowerB = solve_lower_bound(teams, 10, initial_order);
    cout << lowerB << ' ';
    if(upperB < 0)
        cout << '*' << endl;
    else 
        cout << upperB << endl;
}

vector<pair<team, int>> read_input(ll teams, ll rounds){
    vector<pair<team, int>> result;
    string input;
    ll attempt, time, slash_index;

    for(int i=0; i<teams; ++i){
        team T;
        T.solutions = vector<solution>();
        T.p1 = 0;
        for(int j=0; j<rounds; ++j){
            cin >> input;
            slash_index = input.find('/');
            attempt = stoi(input.substr(0, slash_index));
            time = input[slash_index+1] == '-' ? -1 : stoi(input.substr(slash_index+1));
            if(time >= 0){
                T.solutions.push_back(solution{attempt, time});
                T.p1 += punicao(attempt, time, 20);
            }
        }
        result.push_back({T, i});
    }
    return result;
}

int main (void) {_
	ll teams, rounds;
	cin >> teams >> rounds;
	while(teams && rounds) {
        vector<pair<team, int>> teams_data = read_input(teams, rounds);
        solve(teams_data);
		cin >> teams >> rounds;
	}
	return 0;
}