/** 
 * 2020/5/21
 * ����
 * ���ļ�����ʱҪע�ⲻҪ���ظ�����
 * ����Ƕ�Ӧ�ĺ���ֻ��һ��head��ͷ�ļ�
 * �����ú�����ʽ����ͷ�ļ�����
**/
/**
 * 2020/5/26
 * ������Ӳ�������prim�㷨
 * �޸����ڽӾ���ĳ�ʼ��ֵΪINF
 * ��������С·���ҿ�˹�����㷨
 * ������krustal�㷨�����������Ȩͼ��������
 * ����
*/

#include "head.h"
#include "SqQueue.cpp"
#include "AdjGraph.cpp"

int main()
{
    AdjGraph *G;
    MatGraph g;

    int n = 5, e = 6, i, j;
    int A[10][MAXV] = ////�����Ȩ����ͨͼ
        {{0, 6, INF, INF, INF},
         {INF, 0, 1, INF, INF},
         {INF, INF, 0, 3, 2},
         {INF, INF, INF, 0, INF},
         {5, INF, INF, 2, 0}};

    CreateAdj(G, A, n, e); //����ͼ���ڽӱ�
    printf("G���ڽӱ�:\n");
    DispAdj(G);

    printf("�ڽӱ��������ȱ����㷨:\n");
    DFS(G, 4);

    printf("\n�ڽӱ�Ĺ�����ȱ����㷨\n");
    BFS(G, 4);

    for (i = 0; i < 5; i++) //��ʼ���ڽӾ��󣬷�ֹ�쳣
        for (j = 0; j < 5; j++)
            g.edges[i][j] = INF;

    printf("�����ڽӱ������ڽӾ���\n");
    ListToMat(G, g);
    DispMat(g);

    printf("�����ڽӾ��������ڽӱ�\n");
    AdjGraph *H;
    MatToList(g, H);
    DispAdj(H);

    printf("\nPrim �㷨����������\n");
    Prim(g, 0);

    printf("\nKruskal �㷨����������\n");
    Kruskal(g);

    printf("\n�ҿ�˹�����㷨Ѱ����С·��\n");
    Dijkstra(g, 0);

    printf("\nfloyd�㷨��ÿ�Զ���֮������·��\n");
    Floyd(g);

    printf("\n���������㷨\n");
    TopSort(G); //���������㷨
    //DispAdj(G);

    printf("\n����ͼG���ڽӱ�\n");
    DestroyAdj(G);
    system("pause");
    return 0;
}

/////////////////////////////////////////////////////////////
//����Kruskal�㷨�������Ȩͼ�µ�������
//��ʵ������ͼʱ��Ҫ�޸Ķ�Ӧ����䣬���������Kruskal����
/* Edge E[maxsize];
    int k = 0;
    for (i = 0; i < g.n; i++)
        for (j = 0; j < g.n; j++)
            if (g.edges[i][j] != 0 && g.edges[i][j] != INF)
            {
                E[k].u = i;
                E[k].v = j;
                E[k].w = g.edges[i][j];
                k++;
            }
    InsertSort(E, g.e);
    for (i = 0; i < g.e; i++)
        printf("(%d,%d):%d\n", E[i].u, E[i].v, E[i].w);*/
////////////////////////////////////////////////////////////