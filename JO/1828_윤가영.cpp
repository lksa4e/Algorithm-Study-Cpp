#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b){
    return a.first < b.first;
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin>>N;
    pair<int, int> arr[101];
    for(int i=0; i<N; i++){
        int from,to;
        cin>>from>>to;
        arr[i] = make_pair(from,to);
    }
    
    sort(arr, arr+N, cmp);

    vector<pair<int, int> > v;
    v.push_back(make_pair(arr[0].first, arr[0].second));

    int cnt = 1;
    for(int i=1; i<N; i++){
        bool flag = false;
        for(int j=0; j<v.size(); j++){
            if(arr[i].first <= v[j].second){
                flag = true;
                if(v[j].first < arr[i].first) v[j].first = arr[i].first;
                if(arr[i].second < v[j].second) v[j].second = arr[i].second;					
            }
        }
        if(!flag){
            cnt++;
            v.push_back(make_pair(arr[i].first, arr[i].second));
        }
    }

    cout<<cnt<<"\n";
    return 0;
}