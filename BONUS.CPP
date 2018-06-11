#include <bits/stdc++.h>                                       
                                                               
using namespace std;                                           
                                                               
#define TASK "BONUS"                                           
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

const int N = 1e3 + 3;

int n, k;
int a[N][N];
int S[N][N];
int Max = 0;

int main() {
    #ifndef ONLINE_JUDGE
        freopen(input_file,"r",stdin);
        freopen(output_file,"w",stdout);
    #endif
    scanf("%d%d", &n, &k);
    FOR(i, 1, n)
        FOR(j, 1, n) {
            scanf("%d", &a[i][j]);
            S[i][j] = S[i - 1][j] + S[i][j - 1] - S[i - 1][j - 1] + a[i][j];
            if(i > k) S[i][j] -= a[i - k][j];
            if(j > k) S[i][j] -= a[i][j - k];
            if(i > k && j > k) S[i][j] += a[i - k][j - k];
            Max = max(Max, S[i][j]);
        }
    printf("%d", Max);
}
