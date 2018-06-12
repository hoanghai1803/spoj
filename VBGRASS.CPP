#include <bits/stdc++.h>                                       
                                                               
using namespace std;                                           
                                                               
#define TASK "VBGRASS"                                         
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
#define abs(x) ((x)>0?(x):-(x))                                
#define max3(a,b,c) max((a),max((b),(c)))                      
#define min3(a,b,c) min((a),min((b),(c)))                      
#define SET_ARR(a,v) memset(a,v,sizeof(a))                     
#define ALL(x) (x).begin(),(x).end()                           
                                                               
typedef long long ll;                                          
typedef unsigned long long ull;                                
typedef pair<int,int> ii;                                      
typedef pair<int,ii> iii;                                      

const int N = 1e2 + 2;

int R, C, Count = 0;
char s[N][N];
bool Free[N][N];

void Init() {
    scanf("%d%d", &R, &C);
    FOR(i, 1, R) scanf("%s", s[i] + 1);
    FOR(i, 1, R)
        FOR(j, 1, C) Free[i][j] = true;
}

inline void Check(int i, int j) {
    if (s[i][j] == '#' && Free[i][j]) {
        Count++;
        if (j + 1 <= C && s[i][j + 1] == '#' && Free[i][j + 1]) {
            Free[i][j + 1] = false;
            return;
        }
        if (i + 1 <= R && s[i + 1][j] == '#' && Free[i + 1][j]) Free[i + 1][j] = false;
    }
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen(input_file,"r",stdin);
        freopen(output_file,"w",stdout);
    #endif
    Init();
    FOR(i, 1, R)
        FOR(j, 1, C) Check(i, j);
    printf("%d", Count);
}
