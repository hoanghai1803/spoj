#include <bits/stdc++.h>                                       
                                                        
using namespace std;                                           
                                                               
#define TASK "MULONE"                                          
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

int i, k, n;

string Square(int n) {
    int i, carry = 0;
    string c = " ";
    FOR(i, 1, 2 * n)
        if (i<=n) {
            c += (i + carry) % 10 + '0';
            carry = (i + carry) / 10;
        }
        else {
            c += (2 * n - i + carry) % 10 + '0';
            carry = (2 * n - i + carry) / 10;
        }
    if (c[c.length() - 1] == '0') c.erase(c.length() - 1, 1);
    reverse(ALL(c));
    return c;
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen(input_file,"r",stdin);
        freopen(output_file,"w",stdout);
    #endif
    scanf("%d", &k);
    while(k--) {
        scanf("%d", &n);
        cout << Square(n) << endl;
    }
}
