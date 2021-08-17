#include <iostream>

using namespace std;

int N, arr[129][129]={0,}, result[2]={0,};

int check(int y, int x, int n){
    bool flag = true;
    for(int i=y; i<y+n; i++){
        for(int j=x; j<x+n; j++){
            if(arr[i][j] == 0){
                flag = false;
                break;
            }
        }
    }
    if(flag)
        return 1;

    flag = true;
    for(int i=y; i<y+n; i++){
        for(int j=x; j<x+n; j++){
            if(arr[i][j] == 1){
                flag = false;
                break;
            }
        }
    }
    if(flag)
        return 2;

    return 0;
}

void devide(int y, int x, int n){
    if(n == 1){
        if(arr[y][x]==0) result[1]++;
        else result[0]++;
        return;
    }

    int next = check(y,x,n);
    if(next == 1){
        result[0]++;
        return;
    }
    if(next == 2){
        result[1]++;
        return;
    }

    devide(y,x,n/2);
    devide(y,x+n/2,n/2);
    devide(y+n/2,x,n/2);
    devide(y+n/2,x+n/2,n/2);
}



int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>N;
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            cin>>arr[i][j];

    devide(0,0,N);

    cout<<result[1]<<"\n"<<result[0]<<"\n";
    return 0;
}

