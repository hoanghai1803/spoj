#include <bits/stdc++.h>                                       
                                                               
using namespace std;                                           
                                                               
#define TASK "NKCARD"                                      
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

const int N = 1e6 + 6;

int Next[N], Prev[N];
char x;
int m,k;

inline void SetLink(int a,int b) {
    Next[a] = b, Prev[b] = a;
}

void Init() {
    scanf("%d%d", &m, &k);
    k++;
    FOR(i, 0, m) SetLink(i, i + 1);
}

inline void Shuffle(char x) {
    int tmp;
    if(x == 'A') {
        k = Next[k], tmp = Next[0];
        SetLink(Prev[m + 1], tmp);
        SetLink(0, Next[tmp]);
        SetLink(tmp, m + 1);
    }
    if(x == 'B') {
        k = Next[k], tmp = Next[Next[0]];
        SetLink(Prev[m + 1], tmp);
        SetLink(Next[0], Next[tmp]);
        SetLink(tmp, m + 1);
    }
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen(input_file,"r",stdin);
        freopen(output_file,"w",stdout);
    #endif
    Init();
    do {
        scanf("%c",&x);
        Shuffle(x);
    }
    while(x != '.');
    printf("%d %d %d", Prev[k] - 1, k - 1, Next[k] - 1);
}
