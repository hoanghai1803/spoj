#include <bits/stdc++.h>                                       
                                                               
using namespace std;                                           
                                                               
#define TASK "QBSQUARE"                                        
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

const int N = 1e3 + 3;

int m, n, MAX = 0;
int a[N][N], h[N], L[N], R[N];

void Init() {
    scanf("%d%d", &m, &n);
    FOR(i, 1, m)
        FOR(j, 1, n) scanf("%d", &a[i][j]);
}

void Try(int Row, int id) {
    FOR(i, 1, n)
        if(a[Row][i] == id) h[i]++; else h[i] = 0;
    stack<int> Stack;
    Stack.push(0);
    FOR(i, 1, n) {
        while(Stack.size() > 1 && h[Stack.top()] >= h[i]) Stack.pop();
        L[i] = Stack.top();
        Stack.push(i);
    }
    while(Stack.size()) Stack.pop();
    Stack.push(n + 1);
    FORD(i, n, 1) {
        while(Stack.size() > 1 && h[Stack.top()] >= h[i]) Stack.pop();;
        R[i] = Stack.top(); 
        Stack.push(i);
    }
    FOR(i, 1, n) MAX = max(MAX, min(R[i] - L[i] - 1, h[i]));
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen(input_file,"r",stdin);
        freopen(output_file,"w",stdout);
    #endif
    Init();
    FOR(i, 1, m) Try(i, 0);
    FOR(i, 1, n) h[i] = 0;
    FOR(i, 1, m) Try(i, 1);
    printf("%d", MAX);
}
