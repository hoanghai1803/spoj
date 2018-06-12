#include <bits/stdc++.h>                                       
                                                               
using namespace std;                                          
                                                               
#define TASK "QBHEAP"                                          
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

const int N = 15e3;
const int NN = 20;

char s[NN];
int V;
int tmp;

MAX_HEAP(int) Heap, res;

int main() {
    #ifndef ONLINE_JUDGE
        freopen(input_file,"r",stdin);
        freopen(output_file,"w",stdout);
    #endif
    while(scanf("%s", &s) != EOF) {
        if(s[0] == '-') {
            if(Heap.empty()) continue;
            tmp = Heap.top();
            while(Heap.size() && Heap.top() == tmp) Heap.pop();
            continue;
        }
        if(Heap.size() >= N) continue;
        V = 0;
        FOR(i, 1, strlen(s) - 1) V = 10 * V + (s[i] - '0');
        Heap.push(V);
    }
    int cur = -1;
    while(Heap.size()) {
        if(res.empty()) {
            res.push(Heap.top());
            cur = Heap.top(), Heap.pop();
            continue;
        }
        if(Heap.top() != cur) {
            res.push(Heap.top());
            cur = Heap.top(), Heap.pop();
            continue;
        }
        Heap.pop();
    }
    printf("%d\n", res.size());
    while(res.size()) {
        printf("%d\n", res.top());
        res.pop();
    }
}
