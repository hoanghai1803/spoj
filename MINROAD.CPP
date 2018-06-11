#include <bits/stdc++.h>                                       
                                                               
using namespace std;                                           
                                                               
#define TASK "MINROAD"                                         
#define input_file TASK".INP"                                  
#define output_file TASK".OUT"                                 
                                                               
#define X first                                               
#define Y second                                              
#define itr(t) vector<t>::iterator                             
#define ritr(t) vector<t>::reverse_iterator                    
#define IT(i,v) for (i=v.begin();i!=v.end();i++)               
#define RIT(i,v) for (i=v.rbegin();i!=v.rend();i++)            
#define MAX_HEAP(t) priority_queue<t>                          
#define MIN_HEAP(t) priority_queue<t,vector<t>,greater<t> >    
#define FOR(i,a,b) for (int i=(a); i<=(b); i++)                
#define FORD(i,a,b) for (int i=(a); i>=(b); i--)               
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

const int N = 3e5 + 5;
const int oo = INT_MAX;

int n, a, b;
ii d[N];
int Tung[N], Truc[N];

void Init() {
    scanf("%d%d%d", &n, &a, &b);
    FOR(i, 1, n) scanf("%d%d", &d[i].X, &d[i].Y);
    sort(d + 1, d + n + 1);
    d[n + 1].X = +oo;
    FOR(i, 1, n) {
        Tung[i] = Tung[i-1] + (d[i].Y == 1);
        Truc[i] = Truc[i-1] + (d[i].Y == 2);
    }
}

/* TWO POINTERS */

namespace SOL1 {
    int res = +oo;
    int L = 1, R = 2;

    void Main() {
        Init();
        for(; L <= n && R <= n; L++) {
            while(R <= n && (Tung[R] - Tung[L - 1] < a || Truc[R] - Truc[L - 1] < b)) R++;
            if(R <= n) res = min(res, d[R].X - d[L].X);
        }
        if(res == +oo) {
            printf("-1");
            return;
        }
        printf("%d", res);
    }
}

/*BINARY SEARCH */

namespace SOL2 {
    int s;
    int res = 2e9 + 5;

    bool OK(int L, int R) {
        return(Tung[R] - Tung[L - 1] >= a && Truc[R] - Truc[L - 1] >= b);
    }

    int BS(int L, int R) {
        int M;
        while(1) {
            M = (L + R) >> 1;
            if(M == L || M == R) break;
            if(OK(s, M)) R = M; else L = M;
        }
        FOR(M, L, R) 
            if(OK(s, M)) return M;
        return n+1;
    }

    void Main() {
        Init();
        for(s = 1; s <= n; s++) res = min(res, d[BS(s,n)].X - d[s].X);
        if(res > d[n].X - d[1].X){
            printf("-1");
            return;
        }
        printf("%d", res);
    }
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen(input_file,"r",stdin);
        freopen(output_file,"w",stdout);
    #endif
    // SOL1::Main();
    SOL2::Main();
}
