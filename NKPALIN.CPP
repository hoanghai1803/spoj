#include <bits/stdc++.h>                                       
                                                               
using namespace std;                                           
                                                            
#define TASK "NKPALIN"                                         
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

const int N = 2e3 + 3;

string s;
int f[N][N];
bool Mark[N];

void DP(int n) {
    FOR(j, 1, n)
        FOR(i, 0, n - j)
            if (s[i] == s[i + j]) f[i][i + j] = f[i + 1][i + j - 1];
            else f[i][i + j] = min(f[i + 1][i + j] + 1, f[i][i + j - 1] + 1);
}

void Trace(int i, int j) {
    if (i >= j) return;
    else
        if (s[i] == s[j]) Trace(i + 1, j - 1);
        else
            if (f[i][j] == f[i][j - 1] + 1) {
                Mark[j] = false;
                Trace(i, j - 1);
            }
            else {
                Mark[i] = false;
                Trace(i + 1, j);
            }
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen(input_file,"r",stdin);
        freopen(output_file,"w",stdout);
    #endif
    ios_base::sync_with_stdio(0);
    cin >> s;
    FOR(i, 0, s.length() - 1) Mark[i] = true;
    DP(s.length() - 1);
    Trace(0, s.length() - 1);
    FOR(i, 0, s.length() - 1)
        if (Mark[i] == true) cout << s[i];
}
