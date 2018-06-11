#include <bits/stdc++.h>                                       
                                                               
using namespace std;                                           
                                                               
#define TASK "COND"                                          
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

const int N = 11;

int n;
int Fact[N + 1];
int F[N + 1][N + 1];

void SOL1() {
    Fact[1] = 1;
    FOR(i, 2, N) Fact[i] = Fact[i - 1] * i;
    while(1) {
        scanf("%d", &n);
        if(n == -1) break;
        int res = 1 + Fact[n];
        FOR(k, 2, n - 1) {
            F[0][0] = 1;
            FOR(i, 1, n)
            FOR(j, 1, k) F[i][j] = F[i - 1][j - 1] + j * F[i - 1][j];
            res += F[n][k] * Fact[k];
        }
        printf("%d\n", res);
    }
}

void SOL2() {
    Fact[1] = 1;
    FOR(i, 2, N) Fact[i] = Fact[i - 1] * i;
    F[0][0] = 1;
    FOR(i, 1, N)
        FOR(j, 1, i) F[i][j] = F[i - 1][j - 1] + j * F[i - 1][j];
    while(1) {
        scanf("%d", &n);
        if(n == -1) break;
        int res = 0;
        FOR(i, 1, n) res += F[n][i] * Fact[i];
        printf("%d\n", res);
    }
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen(input_file,"r",stdin);
        freopen(output_file,"w",stdout);
    #endif
    // SOL1();
    SOL2();
}
