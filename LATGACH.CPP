#include <bits/stdc++.h>

using namespace std;

#define TASK "LATGACH"
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
#define FOR(i,a,b) for (int i=(a); i<=(b); i++)
#define FORD(i,a,b) for (int i=(a); i>=(b); i--)
#define FORS(i,a,b,d) for (int i=(a); i!=(b); i+=(d))
#define abs(x) ((x)>=0?(x):-(x))
#define sqr(x) (x)*(x)
#define max3(a,b,c) max((a),max((b),(c)))
#define min3(a,b,c) min((a),min((b),(c)))
#define SET_ARR(a,v) memset(a,v,sizeof(a))
#define ALL(x) (x).begin(),(x).end()

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef pair<double,double> dd;
typedef pair<double,dd> ddd;

const int N = 1e2 + 2;

int t, Max = 0;
string F[N];
int x[N];

string Add(string a, string b) {
    string tmp = "";
    if(a.length() < b.length()) {
        FOR(i, 1, b.length() - a.length()) tmp += "0";
        a = tmp + a;
    }
    if(b.length() < a.length()) {
        FOR(i, 1, a.length() - b.length()) tmp += "0";
        b = tmp + b;
    }
    string ret = "";
    int sum, carry = 0;
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

int main() {
    #ifndef ONLINE_JUDGE
        freopen(input_file,"r",stdin);
        freopen(output_file,"w",stdout);
    #endif
    F[0] = F[1] = "1";
    scanf("%d", &t);
    FOR(i, 1, t) {
        scanf("%d", &x[i]);
        if (x[i] > Max) Max = x[i];
    }
    FOR(i, 2, Max) F[i] = Add(F[i-1], F[i-2]);
    FOR(i, 1, t) cout << F[x[i]] << endl; 
}
