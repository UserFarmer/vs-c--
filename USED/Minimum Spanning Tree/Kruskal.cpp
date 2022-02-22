//Kruskal算法
#include <iostream>
using namespace std;

//图的两种存储结构
#define INF 32767				//定义∞
#define	MAXV 100				//最大顶点个数
typedef char InfoType;

/*
TODO:定义一个邻接矩阵结构体,其中一个成员为int类型变量no存编号,
另一个为InfoType类型变量info存信息
*/
typedef struct
{
    int no;
    InfoType info;
} VertexType;					//顶点类型
/*
TODO:定义一个完整的图邻接矩阵类型结构体,
其中一个成员为大小为MAXV*MAXV的二维int数组edges存邻接矩阵,
两个int型变量n,e存定点数边数,一个大小为MAXV的VertexType数组vexs存信息
*/
typedef struct
{
    int edges[MAXV][MAXV];
    int e;
    int n;
    VertexType vexs[MAXV];
    
} MatGraph;						//完整的图邻接矩阵类型

//------------------------------------------------------------
//----邻接矩阵的基本运算算法----------------------------------
//------------------------------------------------------------
void CreateMat(MatGraph &g, int A[MAXV][MAXV], int n, int e) //创建图的邻接矩阵
{
	int i, j;
	g.n = n; g.e = e;
	for (i = 0; i < g.n; i++)
		for (j = 0; j < g.n; j++)
			g.edges[i][j] = A[i][j];
}
void DispMat(MatGraph g)	//输出邻接矩阵g
{
	int i, j;
	for (i = 0; i < g.n; i++)
	{
		for (j = 0; j < g.n; j++)
			if (g.edges[i][j] != INF)
				cout << g.edges[i][j] << ' ';
			else
				cout << "∞ ";
		cout << endl;
	}
}

#define MaxSize 100
typedef struct
{
	int u;			//边的起始顶点
	int v;			//边的终止顶点
	int w;			//边的权值
} Edge;

void InsertSort(Edge E[], int n) //对E[0..n-1]按递增有序进行直接插入排序
{
	int i, j;
	Edge temp;
	for (i = 1; i < n; i++)
	{
		temp = E[i];
		j = i - 1;				//从右向左在有序区E[0..i-1]中找E[i]的插入位置
		while (j >= 0 && temp.w < E[j].w)
		{
			E[j + 1] = E[j];	//将关键字大于E[i].w的记录后移
			j--;
		}
		E[j + 1] = temp;		//在j+1处插入E[i]
	}
}

/*
TODO:完成用Kruskal算法计算最小生成树的功能.
参数说明:g-图的邻接矩阵.
返回值说明:无.
输出说明：cout << "(" << u1 << ',' << v1 << "):" << E[j].w << endl;      
         u1为较大顶点号，v1为较小顶点号，E[j].w为边的权值。
*/
void Kruskal(MatGraph g)
{
    int Mark[g.n];
    int p =1;
    int min = INF;
	fill(Mark, Mark + g.n, 0);
	while(true){
        int a = -1, b = -1;
        for (int i = 0; i < g.n; ++i)
            for (int j = 0; j < g.n; ++j)
            {
				if (g.edges[i][j] != 0 && min > g.edges[i][j] && (Mark[i] == 0 || Mark[j] != Mark[i]))
				{
					min = g.edges[i][j];
                    a = i; b = j;
				}
			}
        if(a == -1) 
        return;
		cout << "(" << b << ',' << a << "):" << min << endl;

		if (Mark[a] == 0 && Mark[b] == 0) {
			Mark[a] = p;
			Mark[b] = p;
			p++;
		}
		else if(Mark[a]==0||Mark[b]==0) {
			Mark[a] = (Mark[a] + Mark[b]);
			Mark[b] = (Mark[a] + Mark[b]);
		}
		else if (Mark[a] != Mark[b]) {
			int tmp = Mark[a];
			for (int i = 0; i < g.n; i++){
				if (Mark[i] == tmp)
					Mark[i] = Mark[b];
			}
		}
		min = INF;
    }
}
int main()
{
	MatGraph g;
	int A[MAXV][MAXV] = {
			{0,28,INF,INF,INF,10,INF},
			{28,0,16,INF,INF,INF,14},
			{INF,16,0,12,INF,INF,INF},
			{INF,INF,12,0,22,INF,18},
			{INF,INF,INF,22,0,25,24},
			{10,INF,INF,INF,25,0,INF},
			{INF,14,INF,18,24,INF,0} };
	int n = 7, e = 9;

	cin >> A[0][1] >> A[1][0];

	CreateMat(g, A, n, e);
	cout << "图G的邻接矩阵:" << endl;
	DispMat(g);					//输出邻接矩阵
	cout << "Kruskal算法结果" << endl;
	Kruskal(g);
	system("pause");
	return 0;
}
