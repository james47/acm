#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#include<set>
#include<map>
#include<queue>
#include<ctime>
#include<string>
#define maxn 10007
using namespace std;

struct Node{
    int data[2][2];
};

Node pri;

Node multi(Node a,Node b){
    Node k;
    for (int i=0;i<2;i++)
        for (int j=0;j<2;j++){
            k.data[i][j] = 0;
            for (int p=0;p<2;p++)
                k.data[i][j] =((k.data[i][j]+a.data[i][p]*b.data[p][j])%maxn+maxn)%maxn;
        }
    return k;
}

Node quick(int k){
    if (k==1) return pri;
    Node w = quick(k/2);
    w = multi(w,w);
    if (k%2==1) w = multi(w,pri);
    return w;
}

int main()
{
    int n, T, x1, x2;
    pri.data[0][0] = 4;pri.data[0][1] = -5;
    pri.data[1][0] = 0;pri.data[1][1] = 1;
    scanf("%d",&T);
    for (int t1=1;t1<=T;t1++){
                printf("Case #%d: ",t1);
                scanf("%d",&n);
                if (n<=2){
                        printf("2\n");
                        continue;
                }
                int p=(n-1);
                Node w = quick(p/2);
                x1 = ((2*w.data[0][0]+w.data[0][1])%maxn+maxn)%maxn;
                x2 = ((2*w.data[1][0]+w.data[1][1])%maxn+maxn)%maxn;
        //for (int i=0;i<3;i++){
        //    for (int j=0;j<3;j++) printf("%d ",mul.data[i][j]);
        //    cout<<endl;
        //    }
        if (p%2==1) x1 = ((2*x1-2* x2)%maxn+maxn)%maxn;
        printf("%d\n",x1);
    }
    return 0;
}
