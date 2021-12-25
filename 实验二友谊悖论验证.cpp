//202000300393 张骏羽 大数据20.2
//2021.12.11
#include<iostream>
#include<queue>
using namespace std;

//输入邻接矩阵，输出符合友谊悖论的节点占比
double FriendshipParadox(int** graph,int n){
    int count;//满足友谊悖论的节点计数器
    int sum;//朋友的朋友数
    int d;//当前节点的朋友数量
    int f;//朋友
    queue<int> *q = new queue<int>();
    for(int i = 1;i <= n;i++){
        sum = 0;
        d = 0;
        for (int j = 1;j <= n;j++){
            if (graph[i-1][j-1] > 0)
                {
                    q->push(j);
                    d++;
                }
        }
        while(!q->empty()){
            f = q->front();
            q->pop();
            for(int j = 1;j <= n;j++)
                if(graph[f-1][j-1] > 0)
                    sum++;
        }
        if (d*d < sum)
            count++;
    }
    delete q;
    return double(count)/n;
}

//该实验应采用无向简单图
int main(){
    //n节点数 data临时数据
    int n,data;
    cout << "输入节点数目:" << endl;
    cin >> n;

    int** graph;
    cout << "输入邻接矩阵" << endl;
    //给邻接矩阵申请空间
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

    cout << "符合友谊悖论的节点占比为:" << endl;
    cout << FriendshipParadox(graph,n);

    return 0;
}
