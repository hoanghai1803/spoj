#include <bits/stdc++.h>
 
using namespace std;
 
#define TASK "NKINV"
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
#define FORU(i,a,b) for (int i=(a); i<=(b); i++)
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
 
const int Max_n = 6e4 + 4;
const int Max_a = 6e4 + 4;

int n, a;
int F[Max_n];
int res = 0;

void Update(int p) {
	for(int i = p; i < Max_a; i += i & -i) F[i]++;
}

void Get(int p) {
	for(int i = p; i; i -= i & -i) res += F[i];
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen(input_file, "r", stdin);
        freopen(output_file, "w", stdout);
    #endif	
    scanf("%d", &n);
    FORU(i, 1, n) {
    	scanf("%d", &a);
    	Get(Max_a - a - 1);
    	Update(Max_a - a);
    }
    printf("%d", res);
}