#include <bits/stdc++.h>
using namespace std;

#define fastio			ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define sz(a) int((a).size())
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())

template<typename T> T gcd(T a, T b){return(b?__gcd(a,b):a);}
template <typename T> T lcm(T a, T b){return (a*b)/gcd(a,b); }
double tick(){static clock_t oldt,newt=clock();double diff=1.0*(newt-oldt)/CLOCKS_PER_SEC;oldt=newt;return diff;}


int main(){
    #ifndef ONLINE_JUDGE
		freopen("test", "r", stdin);
	#endif
    fastio;
    
    int T;
    cin >> T;

    while(T-- > 0){
        int N, K;
        cin >> N >> K;
        vector<string> dict2;
        map<string, int> dict;
        string temp;

        for(int i = 0; i < N; i++){
            cin >> temp;
            dict[temp] = 0;
            dict2.push_back(temp);
        }

        set<string> phrase;
        int phrase_len;
        for(int i = 0; i < K; i++){
            cin >> phrase_len;
            for( int j = 0; j < phrase_len; j++){
                cin >> temp;
                phrase.insert(temp);
            }
            tr(dict, it){
                if(present(phrase, it->first)){
                    it->second = 1;
                }
            }
        }

        tr(dict2, it){
            if(dict[*it] == 1){
                cout << "YES ";
            }else{
                cout << "NO ";
            }
        }
        cout << "\n";
    }
    // cout<<"Execution time : "<<tick()<<"\n";
    return 0;
}