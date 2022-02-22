#include <iostream>

using namespace std;

/*
 * TODO:���帨���ṹ��Element�洢��̱߼�
 * �ýṹ�庬����������Ԫ�ش�����̱ߵ�Ȩֵlowcost���ڽӵ�adjvex
 *
 */
struct Element
{
    int lowcost, adjvex;
};
/*
 * TODO����С������Prim�㷨
 * ������������ G= ( V, E) ��һ��������ͨ��,��G����С��������Ӧ�����������Ե�
 *          ̰�ķ���Prim�㷨����⡣���������k�Ͷ�Ӧ��Ȩֵ�����¸�ʽ��
 *             cout<<shortEdge[k].adjvex<<"--"<<k<<endl;
 * ����˵����       arc: �洢ͼ�и��ߵĴ��۶�ά���飬int**����
 *                   w: ���㣬int����
 *                   n: �����С��int����
 * ����ֵ˵������
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
    //����: arc[n][n] �洢ͼ�и��ߵĴ���
    int n;
    cout<<"�������άnxn�����С n:"<<endl;
    cin>>n;
    int **arc;
    arc = new int *[n];
    for (int i = 0; i < n; i++)
    {
        arc[i] = new int[n];
    }
    //ͼ�и��ߵĴ���, 100����������
    cout<<"������ͼ�и��ߵĴ���, 100����������:"<<endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin>>arc[i][j];
        }
    }
    //���: ��С������
    cout<<"��С�������Ľ�Ϊ:"<<endl;
    Prim(arc, 0, n);
    //�ͷ��ڴ棺
    for(int i = 0; i < n; ++i)
        delete[] arc[i];
    delete[] arc;
    system("pause");
    return 0;
}
