#include <bits/stdc++.h>

using namespace std;

#define TASK "BIGNUM"
#define input_file TASK".INP"
#define output_file TASK".OUT"

#define ST first
#define ND second
#define itr(t) vector<t>::iterator
#define ritr(t) vector<t>::reverse_iterator
#define IT(i,v) for (i=v.begin();i!=v.end();i++)
#define RIT(i,v) for (i=v.rbegin();i!=v.rend();i++)
#define MAX_HEAP(t) priority_queue<t>
#define MIN_HEAP(t) priority_queue<t,vector<t>,greater<t> >
#define FOR(i,a,b) for (long long i=(a); i<=(b); i++)
#define FORD(i,a,b) for (long long i=(a); i>=(b); i--)
#define abs(x) ((x)>0?(x):-(x))
#define max3(a,b,c) max((a),max((b),(c)))
#define min3(a,b,c) min((a),min((b),(c)))
#define SET_ARR(a,v) memset(a,v,sizeof(a))
#define ALL(x) (x).begin(),(x).end()

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;

string a, b;

void STANDARDIZE(string &a, string &b) {
    string tmp = "";
    if(a.length() > b.length()) {
        FOR(i, 1, a.length() - b.length()) tmp += "0";
        b = tmp + b;
    }
    if(b.length() > a.length()) {
        FOR(i, 1, b.length() - a.length()) tmp += "0";
        a = tmp + a;
    }
}

string ADD(string a, string b) {
    int sum, carry = 0;
    string ret = "";
    STANDARDIZE(a,b);
    FORD(i, a.length() - 1, 0) {
        sum = (a[i] - '0') + (b[i] - '0') + carry;
        carry = sum / 10;
        ret += sum % 10 + '0';
    }
    if(carry) ret += "1";
    while(ret.length() > 1 && ret[ret.length() - 1] == '0') ret.erase(ret.length() - 1, 1);
    reverse(ALL(ret));
    return ret;
}

string SUB(string a, string b) {
    if(a == b) return "0";
    string sign = "", ret = "";
    int s, borrow = 0;
    STANDARDIZE(a, b);
    if(b > a) {           
        swap(a, b); sign = "-";
    }
    FORD(i, a.length() - 1, 0) {
        s = a[i] - b[i] - borrow;
        if(s < 0) s += 10, borrow = 1; else borrow = 0;
        ret += s + '0';
    }
    while(ret.length() > 1 && ret[ret.length() - 1] == '0') ret.erase(ret.length() - 1, 1);
    ret += sign;
    reverse(ALL(ret));
    return ret;
}

string MUL1(string a, int b) {
    int carry = 0, s;
    string ret = "", tmp;
    FORD(i, a.length() - 1, 0) {
        s = (a[i] - '0') * b + carry;
        carry = s / 10;
        ret += s % 10 + '0';
    }
    if(carry) tmp = to_string(carry); else tmp = "";
    reverse(ALL(tmp));
    ret += tmp;
    reverse(ALL(ret));
    return ret;
}

string MUL2(string a, string b) {
    string ret = "", tmp;
    int m = -1;
    FORD(i, a.length() - 1, 0) {
        m += 1;
        tmp = MUL1(b, a[i] - '0');
        FOR(j, 1, m) tmp += "0";
        ret = ADD(tmp, ret);
    }
    return ret;
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen(input_file,"r",stdin);
        freopen(output_file,"w",stdout);
    #endif
    cin >> a >> b;
    cout << ADD(a,b) << endl;
    cout << SUB(a,b) << endl;
    cout << MUL2(a,b);
}