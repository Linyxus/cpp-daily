#include <iostream>
#include <string>
using namespace std;

string skim_spaces_before(const string &str)
{
    for (auto i = str.begin(); i != str.end(); i++) {
        if (*i != ' ')  return string(i, str.end());
    }

    return string();
}

int find_match_bracket(const string &str) // str: a string begins with [
{
    int cnt = 0;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '[') cnt++;
        if (str[i] == ']' && --cnt == 0) return i;
    }
    return -1;
}

int eval(const string &s)
{
    string str = skim_spaces_before(s);
    if (str.empty()) {
        return 0;
    }

    if (str[0] == 'F' || str[0] == 'B') {
        int coe = str[0] == 'F' ? 1 : -1;
        int cur = 3;
        char ch = str[cur];
        int d = 0;
        while (ch <= '9' && ch >= '0') {
            d = d * 10 + ch - '0';
            ch = str[++cur];
        }

        return coe * d + eval(string(str.begin() + cur, str.end()));
    }
    else { // REPEAT
        int cur = 7;
        char ch = str[cur];
        int d = 0;
        while (ch <= '9' && ch >= '0') {
            d = d * 10 + ch - '0';
            ch = str[++cur];
        }
        int sub_begin = cur + 1;
        int sub_end = find_match_bracket(string(str.begin()+cur, str.end())) + cur;
        int dist = eval(string(str.begin() + sub_begin, str.begin() + sub_end));
        return d * dist + eval(string(str.begin() + sub_end + 1, str.end()));
    }
}

int abs(int x)
{
    return x > 0 ? x : -x;
}

int main()
{
    string str;
    getline(cin, str);
    cout << abs(eval(str)) << endl;

    return 0;
}
