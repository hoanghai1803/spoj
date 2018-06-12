#include <bits/stdc++.h>                                       
                                                               
using namespace std;                                           
                                                               
#define TASK "QBPAL"                                         
#define input_file TASK".INP"                                 
#define output_file TASK".OUT"                                
                                                               
#define SC scanf                                               
#define PR printf                                             
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

const int N = 2e2 + 2;

string s, F[N][N];

void Standardize(string &a, string &b) {
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

string Add(string a, string b) {
    int sum, carry = 0;
    string ret = "";
    Standardize(a,b);
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

string Sub(string a, string b) {
    if(a == b) return "0";
    string sign = "", ret = "";
    int s, borrow = 0;
    Standardize(a, b);
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

void DP(int n) {
    int i, j;
    FOR(i, 0, n) F[i][i] = "1", F[i + 1][i] = "0";
    FOR(j, 1, n)
        FOR(i, 0, n - j) {
            F[i][i + j] = Sub(Add(F[i + 1][i + j], F[i][i + j - 1]), F[i + 1][i + j - 1]);
            if (s[i] == s[i + j])
               F[i][i + j] = Add(Add(F[i][i + j], F[i + 1][i + j - 1]), "1");
        }
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen(input_file,"r",stdin);
        freopen(output_file,"w",stdout);
    #endif
    ios_base::sync_with_stdio(0);
    cin >> s;
    if (s != "") {
        DP(s.length() - 1);
        cout << F[0][s.length() - 1];
    }
    else cout << 0;
}
