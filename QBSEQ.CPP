#include <bits/stdc++.h>                                       
                                                               
using namespace std;                                           
                                                               
#define TASK "QBSEQ"                                           
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

const int oo = 1e4 + 4;
const int N = 1e3 + 3;
const int NN = 55;

int n, k;
int a[N];
int F[N][NN];

inline int Sub(int x, int y) {
    int res = (x - y) % k;
    return (res >= 0) ? (res) : (res + k);
}

void DP() {
    FOR(i, 0, n)
        FOR(j, 0, k - 1) F[i][j] = +oo;
    F[0][0] = 0;
    FOR(i, 1, n)
        FOR(j, 0, k - 1)
            F[i][j] = min(F[i - 1][j], 1 + F[i - 1][Sub(j, a[i])]);
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen(input_file,"r",stdin);
        freopen(output_file,"w",stdout);
    #endif
    scanf("%d%d", &n, &k);
    FOR(i, 1, n) scanf("%d", &a[i]);
    DP();
    int Sum = 0;
    FOR(i, 1, n) Sum += a[i], Sum %= k;
    printf("%d", n - F[n][Sum]);
}
