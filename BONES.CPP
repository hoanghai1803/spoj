#include <bits/stdc++.h>                                       
                                                               
using namespace std;                                           
                        
#define TASK "BONES"                                        
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

const int N = 88;

int a, b, c, res, Max;
int Count[N];

int main() {
    #ifndef ONLINE_JUDGE
        freopen(input_file,"r",stdin);
        freopen(output_file,"w",stdout);
    #endif
    scanf("%d%d%d", &a, &b, &c);
    FOR(i, 1, a)
        FOR(j, 1, b)
            FOR(k, 1, c) Count[i + j + k]++;
    Max = Count[3], res = 3;
    FOR(i, 4, a + b + c)
        if(Count[i] > Max) Max = Count[i], res = i;
    printf("%d", res);
}
