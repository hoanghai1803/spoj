#include <bits/stdc++.h>                                       
                                                               
using namespace std;                                           
                                                               
#define TASK "PTRANG"                                         
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

const int oo = 1e9 + 9;
const int N = 6e3 + 6;

int n, L, s;
int a[N];
int F[N];

int main() {
    #ifndef ONLINE_JUDGE
        freopen(input_file,"r",stdin);
        freopen(output_file,"w",stdout);
    #endif
    scanf("%d%d", &n, &L);
    F[0] = 0;
    FOR(i, 1, n) {
        scanf("%d", &a[i]);
        F[i] = +oo, s = 0;
        FORD(j, i, 1) {
            s += a[j];
            if(L < s) break;
            F[i] = min(F[i], max(L - s, F[j - 1]));
        }
    }
    printf("%d", F[n]);
}
