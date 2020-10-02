#include <bits/stdc++.h>
using namespace std;

int main(){

    char *a = "asdf\0";
    string s = string(a);
    cout << s << " " << s.size() << endl;
    cout << string(a) << endl;
    return 0;
}