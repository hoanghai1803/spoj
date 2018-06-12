#include <bits/stdc++.h>                                       
                                                               
using namespace std;                                           
                                                               
#define TASK "NKTICK"                                          
#define input_file TASK".INP"                                  
#define output_file TASK".OUT"                    
                                                              
#define ST first                                               
#define ND second                                              
#define PB push_back                                           
#define PF push_front                                          
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

const int N = 6e4 + 4;

int n;
int T[N], R[N], F[N];

int main() {
    #ifndef ONLINE_JUDGE
        freopen(input_file,"r",stdin);
        freopen(output_file,"w",stdout);
    #endif
    scanf("%d", &n);
    FOR(i, 1, n) scanf("%d", &T[i]);
    FOR(i, 1, n-1) scanf("%d", &R[i]);
    F[1] = T[1];
    FOR(i, 2, n) F[i] = min(F[i - 2] + R[i - 1], F[i - 1] + T[i]);
    printf("%d", F[n]);
}
