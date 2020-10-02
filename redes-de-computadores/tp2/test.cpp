#include <bits/stdc++.h>
#include <errno.h>
using namespace std;

int main(){

    const char *c = "ssssssssssss";
    try{
        stoi(c);
    } catch (exception const &e){
        cout << "error: " << e.what() << endl;
    } catch (string &s){
        cout << s << endl;
    } catch (int &s){
        cout << s << endl;
    }

    return 0;
}