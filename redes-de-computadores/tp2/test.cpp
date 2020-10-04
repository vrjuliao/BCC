#include <bits/stdc++.h>
#include <errno.h>
#include <istream>

using namespace std;

struct Link {
    std::string ipaddress;
    std::string port;
};

int main(){
    
    std::vector<Link> links = std::vector<Link>();
    // std::ifstream in("in.txt");
    // std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
    // std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
    std::string s1, s2;
    while(std::cin >> s1){
        std::cin >> s2;
        links.push_back(Link{s1, s2});
    }

    for(int i=0; i<links.size(); i++){
        cout << links[i].ipaddress << " " << links[i].port << endl;
    }
    

    return 0;
}