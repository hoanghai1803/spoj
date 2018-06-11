#include <bits/stdc++.h>                                       
                                                               
using namespace std;                                           
                                                               
#define TASK "M3TILE"                                          
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

const int N = 33;

int n;
ll F[N];

int main() {
    #ifndef ONLINE_JUDGE
        freopen(input_file,"r",stdin);
        freopen(output_file,"w",stdout);
    #endif
    F[0] = 1, F[2] = 3, F[4] = 11;
    FOR(i, 5, 30) F[i] = 4 * F[i - 2] - F[i - 4];
    while(1) {
        scanf("%d", &n);
        if(n == -1) break;
        printf("%lld\n", F[n]);
    }
}
