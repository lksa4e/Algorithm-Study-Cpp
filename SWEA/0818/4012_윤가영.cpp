#include <iostream>
#include <vector>
#include <cstring>
#include <vector>

using namespace std;

int N,ans;
int arr[17][17] = {0,};
int recipe[17] = {0,};

void init(){
    ans = 987654321;
    memset(recipe, 0, sizeof(recipe));
}

int cal(){
    vector<int> a,b;
    for(int i=0; i<N; i++)  recipe[i]?a.push_back(i):b.push_back(i);
    
    int asum = 0;
    int bsum = 0;
    for(int i=0; i<N/2-1; i++){
        for(int j=i+1; j<N/2; j++){
            asum += arr[a[i]][a[j]] + arr[a[j]][a[i]];
            bsum += arr[b[i]][b[j]] + arr[b[j]][b[i]];
        }
    }
    return abs(asum - bsum);
}


void comb(int idx, int cnt){
    if(cnt == N/2){
        ans = min(ans,cal());
        return;
    }

    for(int i=idx+1; i<N; i++){
        recipe[i] = 1;
        comb(i, cnt+1);
        recipe[i] = 0;
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin>>T;
    for(int t=1; t<=T; t++){
        cin>>N;
        for(int i=0; i<N; i++)
            for(int j=0; j<N; j++)
                cin>>arr[i][j];
        init();
        comb(-1,0);
        
        cout<<"#"<<t<<" "<<ans<<"\n";
    }
}