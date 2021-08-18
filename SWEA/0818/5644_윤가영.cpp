#include <iostream>
#include <map>
#include <math.h>
#include <vector>

using namespace std;

typedef struct{
    int y;
    int x;
    int c;
    int p;
}BC;

int m,a;

map <int, BC> bc; //bc의 정보를 담은 맵
vector<int> flagA, flagB;
vector<int> A,B;

int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};


void init_(){
    bc.clear();
    A.clear();
    B.clear();
}

bool check(int k, int y1, int x1){
    if(bc[k].c >= abs(bc[k].y - y1) + abs(bc[k].x - x1))
        return true;
    return false;
}

int max_total(){
    int total = 0;
    int Asize = flagA.size();
    int Bsize = flagB.size();
    
    if(Asize == 0){
        for(int i=0; i<Bsize; i++)
            total = max(total, bc[flagB[i]].p);
    }
    else if(Bsize == 0){
        for(int i=0; i<Asize; i++)
            total = max(total, bc[flagA[i]].p);
    }
    else if(Asize!=0 && Bsize!=0){
        for(int i=0; i<Asize; i++){       
            for(int j=0; j<Bsize; j++){
                if(flagA[i] == flagB[j])
                    total = max(total,bc[flagA[i]].p);
                else
                    total = max(total,bc[flagA[i]].p + bc[flagB[j]].p);
            }
        }
    }
    
    flagA.clear();
    flagB.clear();
    return total;
}


int simulator(int Ay, int Ax, int By, int Bx){ 
    int ans = 0;

    for(int i=0; i<=m; i++){  
        
        //현재 위치에 bc있는지 체크
        for(int j=0; j<a; j++){
            if(check(j,Ay,Ax))
                flagA.push_back(j);
            if(check(j,By,Bx))
                flagB.push_back(j);
        }

        //최대값 업데이트
        ans += max_total();
       
       if(i == m) break;

        //좌표 업데이트
        Ay += dy[A[i]-1];
        Ax += dx[A[i]-1];
        By += dy[B[i]-1];
        Bx += dx[B[i]-1];
    }    
    return ans;
}

int main(){
    int test_case;
    cin>>test_case;
    for(int T=1; T<=test_case; T++){
        cin>>m>>a;
        for(int i=0; i<m; i++){
            int t;
            cin>>t;
            A.push_back(t);
        }
        for(int i=0; i<m; i++){
            int t;
            cin>>t;
            B.push_back(t);
        }
        for(int i=0; i<a; i++){
            BC Bc;
            cin>>Bc.x>>Bc.y>>Bc.c>>Bc.p;
            bc[i] = Bc;
        }

        cout<<"#"<<T<<" "<<simulator(1,1,10,10)<<endl;
        init_();
    }

}