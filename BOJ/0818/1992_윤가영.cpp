#include <iostream>
#include <string>
#include <vector>

using namespace std;

int N, arr[65][65] = {0,};
vector<char> v;

bool check(int y, int x, int size){
    int target = arr[y][x];
    for(int i=y; i<y+size; i++)
        for(int j=x; j<x+size; j++)
            if(target != arr[i][j])
                return false;
    return true;
}

void quadTree(int y, int x, int size){
    if(check(y, x, size)){
        v.push_back(arr[y][x]);
        return;
    }

    int next = size/2;

    v.push_back('(');
    
    quadTree(y,x,next);
    quadTree(y,x+next,next);
    quadTree(y+next,x,next);
    quadTree(y+next,x+next,next);

    v.push_back(')');
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>N;
    for(int i=0; i<N; i++){
        string str;
        cin>>str;

        for(int j=0; j<str.size(); j++)
            arr[i][j] = str[j];
    }

    quadTree(0,0,N);

    for(int i=0; i<v.size(); i++)
        cout<<v[i];
    cout<<"\n";
    return 0;
}

