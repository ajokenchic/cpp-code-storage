#include <iostream>
using namespace std;

bool gettoken(const string& src, char ch, int idx, string& dest) {
    int s = 0;
    int t;
    for (int i = 0; i < idx; i++)
    {
        t = src.find(ch, s);
        if (t == string::npos) return false;
        s = t + 1;
    }
    t = src.find(ch, s);
    if (t == string::npos) dest = src.substr(s);
    dest = src.substr(s, t - s);
    return true;
}
int main() {
    string test = "가지,상추,취나물,연근,두릅,엉겅퀴,시금치,무순,느타리버섯,coriander";
    string dst;
    if (gettoken(test, ',', 9, dst)) printf("%s ", dst.c_str());
    //                  (읽을 스트링,찾으려는 글자,글자가 n번째 나온 이후의 ,스트링배열을 dst에 저장.)
    else printf("Nothing!");
}