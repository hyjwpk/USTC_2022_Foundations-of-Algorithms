/*给定一个字符串s，请判断是否可以通过由它的一个子串重复多次构成。若能，则输出该子串（最短的），否则输出-1。*/

#include <iostream>
#include <string>

using namespace std;

int main(){
    string s;
    cin >> s;
    int n = (s + s).find(s, 1);
    if (n != s.length()) {
        cout << s.substr(0, n);
    } else {
        cout << -1;
    }
}