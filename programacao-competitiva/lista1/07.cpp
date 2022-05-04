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

void solve (int operations) {
    int  op, data;
    bool data_st[] = {true, true, true};
    priority_queue<int, vector<int>, less<int>> pq;
    queue<int> qu;
    stack<int> st;

    while(operations--){
        cin >> op >> data;
        if(op == 1){
            pq.push(data);
            qu.push(data);
            st.push(data);
        } else {
            data_st[0] &= (pq.top() == data);
            data_st[1] &= (qu.front() == data);
            data_st[2] &= (st.top() == data);
            pq.pop();
            qu.pop();
            st.pop();
        }
    }
    if(data_st[0]){
        if(data_st[1] || data_st[2]){
            cout << "not sure" << endl;
        } else {
            cout << "priority queue" << endl;
        }
    } else if(data_st[1]){
        if (data_st[2]) {
            cout << "not sure" << endl;
        } else {
            cout << "queue" << endl;
        }
    } else if(data_st[2]){
        cout << "stack" << endl;
    } else {
        cout << "impossible" << endl;
    }
}

int main (void) {_

    int operations;
    while(cin >> operations){
        solve(operations);
    }
	return 0;
}