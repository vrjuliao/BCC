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

struct Tree {
    char val;
    Tree *left;
    Tree *right;
};

Tree* mount_tree(const string &postfix, unordered_map<char,int> &infix_pos, int &pf_index, int l, int  r){
    if(l>r) return nullptr;

    Tree *root = new Tree();
    root->val = postfix[pf_index];
    int pos = infix_pos[postfix[pf_index]];
    ++pf_index;
    root->left = mount_tree(postfix, infix_pos, pf_index, l, pos-1);
    root->right = mount_tree(postfix, infix_pos, pf_index, pos+1, r);
    return root;
}

void print_postfix(Tree *root){
    if(!root) return;
    print_postfix(root->left);
    print_postfix(root->right);
    cout << root->val;
    delete root;
}

void solve (const string &postfix, const string &infix) {
    unordered_map<char,int> infix_pos;
    for(int i=0; i<infix.size(); ++i){
        infix_pos[infix[i]] = i;
    }
    int pf_index = 0;
    Tree *root = mount_tree(postfix, infix_pos, pf_index, 0, infix.size()-1);
    print_postfix(root);
    cout << endl;
}

int main (void) {_

    int rounds;
    cin >> rounds;
    int trash;
    string postfix, infix;
    while(rounds--){
        cin >> trash >> postfix >> infix;
        solve(postfix, infix);
    }
	return 0;
}