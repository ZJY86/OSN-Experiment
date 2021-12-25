//202000300393 张骏羽 大数据20.2
//2021.11.25
#include<iostream>
using namespace std;

//输入邻接矩阵graph，节点数n，要求聚集系数的节点v
double Clustering(int** graph,int n,int v){
    
    int friends = 0;//v的朋友个数
    int *who = new int[n+1];//v的朋友组成的数组，从1开始索引
    for (int i = 1;i <= n;i++)
        if (graph[v-1][i-1] > 0)
            who[++friends] = i;
    //总邻居对数
    int total = friends*(friends-1)/2;

    int FF = 0;
    //朋友的朋友是朋友的对数
    for (int i = 1;i < friends;i++)
        for (int j = i;j <= friends;j++)
            if (graph[who[i]-1][who[j]-1] > 0)
                FF++;

    return (double)FF/total;
}

double Overlapping(int** graph,int n,int v,int v1){
    int friend_A=0,friend_B=0,friend_C=0;
    int *A = new int[n+1];
    int *B = new int[n+1];
    
    for (int i = 1;i <= n;i++)
        {
            if (i == v1)
                continue;
            if (graph[v-1][i-1] > 0)
                {
                    friend_A++;
                    A[friend_A] = i;
                }
        }
    for (int i = 1;i <= n;i++)
        {
            if (i == v)
                continue;
            if (graph[v1-1][i-1] > 0)
                {
                    friend_B++;
                    B[friend_B] = i;
                }
        }

    for (int i = 1;i <= friend_A;i++)
        for (int j = 1;j <= friend_B;j++)
            if (A[i] == B[j])
                {
                    friend_C++;
                    continue;
                }

    return (double)friend_C/(friend_A+friend_B-friend_C);
}       


//该实验应采无向简单图
int main(){
    int n,data,v,v1;
    cout << "输入节点数目:" << endl;
    cin >> n;

    int** graph;
    //给邻接矩阵申请空间
    cout << "输入邻接矩阵" << endl;
    graph = new int*[n];
    for (int i = 0;i < n;i++)
        graph[i] = new int[n];

    //初始化邻接矩
    for (int i = 0;i < n;i++)
        for (int j = 0;j < n;j++)
            {
                cin >> data;
                graph[i][j] = data;
            }

    cout << "输入要计算聚集系数的节点编号:" << endl;
    cin >> v;
    cout << v << "的聚集系数为:" << Clustering(graph,n,v);
    cout << "输入要计算邻里重叠度的两个节点编号:" << endl;
    cin >> v >>  v1;
    cout << v << "," << v1 << "的邻里重叠度为:" << Overlapping(graph,n,v,v1) << endl;
}
