#include<bits/stdc++.h>

using namespace std;

string n;
int m1,m2;

bool num[10][5][5]={
    {
        {1,1,1,1,1},
        {1,0,0,0,1},
        {1,0,0,0,1},
        {1,0,0,0,1},
        {1,1,1,1,1},
    },
    {
        {0,0,0,0,1},
        {0,0,0,0,1},
        {0,0,0,0,1},
        {0,0,0,0,1},
        {0,0,0,0,1},
    },
    {
        {1,1,1,1,1},
        {0,0,0,0,1},
        {1,1,1,1,1},
        {1,0,0,0,0},
        {1,1,1,1,1},
    },
    {
        {1,1,1,1,1},
        {0,0,0,0,1},
        {1,1,1,1,1},
        {0,0,0,0,1},
        {1,1,1,1,1},
    },
    {
        {1,0,0,0,1},
        {1,0,0,0,1},
        {1,1,1,1,1},
        {0,0,0,0,1},
        {0,0,0,0,1},
    },
    {
        {1,1,1,1,1},
        {1,0,0,0,0},
        {1,1,1,1,1},
        {0,0,0,0,1},
        {1,1,1,1,1},
    },
    {
        {1,1,1,1,1},
        {1,0,0,0,0},
        {1,1,1,1,1},
        {1,0,0,0,1},
        {1,1,1,1,1},
    },
    {
        {1,1,1,1,1},
        {0,0,0,0,1},
        {0,0,0,0,1},
        {0,0,0,0,1},
        {0,0,0,0,1},
    },
    {
        {1,1,1,1,1},
        {1,0,0,0,1},
        {1,1,1,1,1},
        {1,0,0,0,1},
        {1,1,1,1,1},
    },
    {
        {1,1,1,1,1},
        {1,0,0,0,1},
        {1,1,1,1,1},
        {0,0,0,0,1},
        {1,1,1,1,1},
    },
};

char out[2000][2000];

void fillblock(int x,int y,int m1,int m2,char nm){
    for(int i=x;i<x+m1;i++){
        for(int j=y;j<y+m2;j++)
        {
            out[i][j]=nm;

        }
    }
}

void fillnum(int y,int x,int m1,int m2,char nm){
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
            if(num[nm-'0'][i][j]){
                fillblock(x+i*m1,y+j*m2,m1,m2,nm);
            }
        }
    }
}

int main(){
    cin>>n>>m1>>m2;
    int cc=0;
    for(int i=0;i<n.size();i++,cc+=6*m2)
    {
        fillnum(cc,0,m1,m2,n[i]);
    }
    for(int i=0;i<5*m1;i++)
    {
        for(int j=0;j<cc;j++)
        {
                printf("%c",out[i][j]);
        }
        printf("\n");
    }
}
