#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<vector>
#include<math.h>
#include<queue>
#include<deque>
#include<stack>
#include<algorithm>
#include<iterator>
#include<map>
#include<unordered_map>
#include<set>
#include<unordered_set>
#define lli long long int
#define mp make_pair
#define ULTRA_INSTINCT ios_base::sync_with_stdio(false); cin.tie(0)
#define PI  3.141592653589793
#define fo(i,n) for(lli i=0;i<(n);i++)
#define FO(i,x,n) for(lli i=(x);i<(n);i++)
#define pb push_back
#define FI first
#define SE second
#define vi vector<lli>
#define pi pair<lli,lli>
#define vii vector<pi >
#define Endl endl
#define ITA 200005
#define ROH 100005
using namespace std;
lli mod = 1e9 +7,test; 
lli max(lli a,lli b){return a>b?a:b;}
lli min(lli a,lli b){return a>b?b:a;}

lli gcd(lli a, lli b) { 
   if (b == 0) return a; 
   return gcd(b, a % b);  
} 
lli n,m,t;

double f(lli here){
    if(here < 0){return -1;}
    lli f1 = here/2 +1 , f2 = here / 2;
    double temp = (double) (f1*n + f2*m);
    temp /= (double)here;
    return temp;
}



void solve(){
lli n;
cin>>n;
vi a(n);
fo(i,n) cin>>a[i];
vi b(n);
vi c(n);
lli ans = 0;
fo(i,n){
    lli j = i+1;
    lli here =0,maxi = 0;
    while(j<n && a[j] < a[i]){
        here += a[j]; 
        maxi = max(maxi , here);
        j++;
    }
    b[i] = maxi;
}
for(lli i = n-1;i>=0;i--){
    lli j = i+1;
    lli sum = 0;
    while(j < n && a[j] <= a[i]){
        sum += a[j];
        if(a[j] == a[i]){
            b[i] =max(sum + b[j] , b[i]);
            break;
        }
        j++;
    }
}
fo(i,n){
    lli j = i-1 , here = 0 , maxi = 0;
    while(j>=0 && a[j] < a[i]){
        here += a[j];
        // cout<<"at "<<j<<" for "<<i<<"here = "<<here<<endl;
        maxi = max(maxi , here);
        j--;
    }
    c[i] = maxi;
}
fo(i,n){
    lli j = i-1,sum = 0;
    while(j>=0 && a[j] <= a[i]){
        sum +=a[j];
        if(a[j] == a[i]){
            c[i] = max(sum+ c[j] , c[i]);
            break;
        }
        j--;
    }
}
// fo(i,n){
//     cout<<b[i]<<" ";
// }cout<<Endl;

// fo(i,n){
//     cout<<c[i]<<" ";
// }cout<<Endl;
fo(i,n){
    ans = max(ans , b[i] + c[i]);
}

cout<<ans<<Endl;


}

int main(){
    ULTRA_INSTINCT;
    lli t =1;
    // cin>>t;
    fo(i,t){
        solve();
    }
    return 0;

}