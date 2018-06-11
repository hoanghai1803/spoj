#include <bits/stdc++.h>                                       
                                                               
using namespace std;                                           
                                                               
#define TASK "CRECT"                                           
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
#define FOR(i,a,b) for (int i=(a); i<=(b); i++)               
#define FORD(i,a,b) for (int i=(a); i>=(b); i--)              
#define abs(x) ((x)>0?(x):-(x))                                
#define max3(a,b,c) max((a),max((b),(c)))                    
#define min3(a,b,c) min((a),min((b),(c)))                   
#define SET_ARR(a,v) memset(a,v,sizeof(a))                    
                                                            
typedef long long ll;                                          
typedef unsigned long long ull;                               
typedef pair<int,int> ii;                                      
typedef pair<int,ii> iii;                                      

const int N = 5e2 + 2;

int m, n;
ll F[N];
int h[N], L[N];
char s[N][N];
ll Sum = 0;

namespace SOL1 {
    inline void Sweep(int i, int X, int Y, int Z, int t) {
        FOR(j, 1, n) h[j] = (h[j] + 1) * (s[i][j] == X || s[i][j] == Y || s[i][j] == Z);
        stack<int> Stack;
        Stack.push(0);
        FOR(j, 1, n) {
            while(Stack.size() > 1 && h[Stack.top()] >= h[j]) Stack.pop();
            L[j] = Stack.top();
            Stack.push(j);
        }
        FOR(j, 1, n) F[j] = h[j] * (j * 1LL - L[j]) + F[L[j]], Sum += F[j] * t;
    }

    inline void Reset() {
        FOR(i, 1, n) h[i] = 0;
    }

    void MAIN() {
        FOR(x, 'A', 'C')
            FOR(y, x+1, 'D')
                FOR(z, y+1, 'E') {
                    FOR(i, 1, m) Sweep(i, x, y, z, 1); Reset();
                    FOR(i, 1, m) Sweep(i, x, y, 0, -1); Reset();
                    FOR(i, 1, m) Sweep(i, y, z, 0, -1); Reset();
                    FOR(i, 1, m) Sweep(i, z, x, 0, -1); Reset();
                    FOR(i, 1, m) Sweep(i, x, 0, 0, 1); Reset();
                    FOR(i, 1, m) Sweep(i, y, 0, 0, 1); Reset();
                    FOR(i, 1, m) Sweep(i, z, 0, 0, 1); Reset();
                }
        printf("%lld", Sum);
    }
}

namespace SOL2 {
    inline void Sweep(int i, int X, int Y, int Z, int t) {
        FOR(j, 1, n) h[j] = (h[j] + 1) * (s[i][j] == X || s[i][j] == Y || s[i][j] == Z);
        stack<int> Stack;
        Stack.push(0);
        FOR(j, 1, n) {
            while (Stack.size() > 1 && h[Stack.top()] >= h[j]) Stack.pop();
            L[j] = Stack.top();
            Stack.push(j);
        }
        FOR(j, 1, n) F[j] = h[j] * (j * 1LL - L[j]) + F[L[j]], Sum += F[j] * t;
    }

    inline void Reset() {
        FOR(i, 1, n) h[i] = 0;
    }

    void MAIN() {
        FOR(x, 'A', 'C')
            FOR(y, x + 1, 'D')
                FOR(z, y + 1, 'E') {
                    FOR(i, 1, m) Sweep(i, x, y, z, 1);
                    Reset();
                }
        FOR(x, 'A', 'D')
            FOR(y, x+1, 'E') {
                FOR(i, 1, m) Sweep(i, x, y, 0, -3);
                Reset();
            }
        FOR(x, 'A', 'E') {
            FOR(i, 1, m) Sweep(i, x, 0, 0, 6);
            Reset();
        }
        printf("%lld", Sum);
    }
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen(input_file, "r", stdin);
        freopen(output_file,"w",stdout);
    #endif
    scanf("%d%d", &m, &n);
    FOR(i, 1, m) scanf("%s", s[i] + 1);
    SOL1::MAIN();
    // SOL2::MAIN();
}
