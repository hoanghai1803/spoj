#include <bits/stdc++.h>                                       
                                                               
using namespace std;                                           
                                                               
#define TASK "TAYTRUC"                                         
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

const int N = 1e4 + 4;

int n, m;
int x[N];
int F[N];

void Init() {
    scanf("%d%d", &n, &m);
    FOR(i, 1, n) {
        scanf("%d", &x[i]);
        x[i] += x[i - 1];
    }
}

void DP() {
    FORD(i, n, 1) {
        F[i] = F[i + 1];
        FOR(j, 1, m)
            if(i + 2 * j <= n + 1) F[i] = max(F[i], x[i + j - 1] - x[i - 1] + F[i + 2 * j]);
    }
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen(input_file,"r",stdin);
        freopen(output_file,"w",stdout);
    #endif
    Init();
    DP();
    printf("%d", F[1]);
}
