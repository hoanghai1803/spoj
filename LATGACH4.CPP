#include <bits/stdc++.h>                                       
                                                               
using namespace std;                                           
                                                               
#define TASK "LATGACH4"                                        
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

const int M = 111539786;

int T, n;

struct Matrix {
    ll item[2][2];
    Matrix operator * (Matrix);
} Base, First;

inline Matrix Matrix::operator * (Matrix a) {
    Matrix ret;
    FOR(i, 0, 1)
        FOR(j, 0, 1) {
            ret.item[i][j] = 0;
            FOR(k, 0, 1)
                ret.item[i][j] += item[i][k]*a.item[k][j], ret.item[i][j] %= M;
        }
    return ret;
}

inline Matrix Pow(ll n) {
    if (n == 1) return Base;
    Matrix tmp = Pow(n / 2);
    if (n & 1) return (tmp * tmp * Base);
    return (tmp * tmp);
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen(input_file,"r",stdin);
        freopen(output_file,"w",stdout);
    #endif
    First = {1, 1, 
             0, 0};
    Base = {0, 1, 
            1, 1};
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &n);
        if (n == 1) printf("1\n");
        else printf("%lld\n", (First * Pow(n - 1)).item[0][1]);
    }
}
