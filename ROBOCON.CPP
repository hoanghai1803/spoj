#include <bits/stdc++.h>                                       
                                                               
using namespace std;                                           
                                                               
#define TASK "ROBOCON"                                         
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

const int N = 5e2 + 5;

int n, k;
int i, j;
int res;
bool stone[N][N];
bool availX[N][N], availY[N][N];

vector<ii> borX, borY;
vector<ii> newX, newY;

itr(ii) it;

void Init() {
    SET_ARR(stone, false);
    SET_ARR(availX, true);
    SET_ARR(availY, true);
    scanf("%d%d", &n, &k);
    borX.push_back(ii(1, 1));
    borY.push_back(ii(1, n));
    while(k--) {
        scanf("%d%d", &i, &j);
        stone[i][j] = true;
    }
}

inline bool Valid(int i, int j) {
    return(i && i <= n && j && j <= n && !stone[i][j]);
}

void Find() {
    FOR(Step, 1, 3 * n) {
        IT(it, borX)
            FOR(x, 0, 1)
                FOR(y, 0, 1)
                    if(x || y) {
                    i = it->ST + x;
                    j = it->ND + y;
                    if(!Valid(i,j)) continue;
                    if(!availX[i][j]) continue;
                    newX.push_back(ii(i, j));
                    availX[i][j] = false;
                }
        IT(it, borY)
            FOR(x, 0, 1)
                FOR(y, -1, 0)
                    if(x || y) {
                        i = it->ST + x;
                        j = it->ND + y;
                        if(!Valid(i, j)) continue;
                        if(!availX[i][j]) {
                            printf("%d", Step);
                            exit(0);
                        }
                        if(!availY[i][j]) continue;
                        newY.push_back(ii(i,j));
                        availY[i][j] = false;
                    }
        borX = newX, newX.clear();
        borY = newY, newY.clear();
        IT(it, borX) availX[it->ST][it->ND] = true;
        IT(it, borY) availY[it->ST][it->ND] = true;
    }
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen(input_file,"r",stdin);
        freopen(output_file,"w",stdout);
    #endif
    Init();
    Find();
}
