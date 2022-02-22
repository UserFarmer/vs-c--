#include <iostream>

using namespace std;

/*
 * TODO:定义辅助结构体Element存储最短边集
 * 该结构体含有两个整型元素代表最短边的权值lowcost和邻接点adjvex
 *
 */
struct Element
{
    int lowcost, adjvex;
};
/*
 * TODO：最小生成树Prim算法
 * 功能描述：设 G= ( V, E) 是一个无向连通网,求G的最小生成树。应用最近顶点策略的
 *          贪心法（Prim算法）求解。在输出顶点k和对应的权值按以下格式：
 *             cout<<shortEdge[k].adjvex<<"--"<<k<<endl;
 * 参数说明：       arc: 存储图中各边的代价二维数组，int**类型
 *                   w: 顶点，int类型
 *                   n: 数组大小，int类型
 * 返回值说明：空
*/
void Prim(int** arc, int w, int n)
{
    Element shortEdge[6];
    int v = -1;
    int min;
    for (int i = 0; i < n; i++) {

        shortEdge[i].lowcost = arc[w][i];
        shortEdge[i].adjvex = w;
    }

    shortEdge[w].lowcost = 0;

    for (int i = 1; i < n; i++) {
        min = 101;

        for (int j = 0; j < n; j++) {
            if (shortEdge[j].lowcost < min && shortEdge[j].lowcost != 0) {
                v = j;
                min = shortEdge[j].lowcost;
            }
        }
        cout << shortEdge[v].adjvex << "--" << v << endl;
        shortEdge[v].lowcost = 0;
        for (int j = 0; j < n; j++) {
            if (arc[v][j] < shortEdge[j].lowcost) {
                shortEdge[j].lowcost = arc[v][j];
                shortEdge[j].adjvex = v;
            }
        }
    }
}

int main( )
{
    //输入: arc[n][n] 存储图中各边的代价
    int n;
    cout<<"请输入二维nxn数组大小 n:"<<endl;
    cin>>n;
    int **arc;
    arc = new int *[n];
    for (int i = 0; i < n; i++)
    {
        arc[i] = new int[n];
    }
    //图中各边的代价, 100代表最大代价
    cout<<"请输入图中各边的代价, 100代表最大代价:"<<endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin>>arc[i][j];
        }
    }
    //输出: 最小生成树
    cout<<"最小生成树的解为:"<<endl;
    Prim(arc, 0, n);
    //释放内存：
    for(int i = 0; i < n; ++i)
        delete[] arc[i];
    delete[] arc;
    return 0;
}
