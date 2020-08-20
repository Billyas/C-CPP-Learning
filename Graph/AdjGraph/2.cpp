/**
 * floyd�㷨��ʵ��
 * ��������������
 * ��INF����Ϊһ����С������
 * ��
 * 2020/5/31
*/

#include "head.h"

void Floyd(MatGraph g) //��ÿ�Զ���֮������·��
{
    int A[MAXV][MAXV];    //����A����
    int path[MAXV][MAXV]; //����path����
    int i, j, k;
    for (i = 0; i < g.n; i++)
        for (j = 0; j < g.n; j++)
        {
            A[i][j] = g.edges[i][j];
            if (i != j && g.edges[i][j] < INF)
                path[i][j] = i; //i��j����֮����һ����ʱ
            else                //i��j����֮��û��һ����ʱ
                path[i][j] = -1;
        }

    for (k = 0; k < g.n; k++) //��Ak[i][j]
    {
        for (i = 0; i < g.n; i++)
            for (j = 0; j < g.n; j++)
                if (A[i][j] > A[i][k] + A[k][j]) //�ҵ�����·��
                {
                    A[i][j] = A[i][k] + A[k][j]; //�޸�·������
                    path[i][j] = path[k][j];     //�޸����·��Ϊ��������k
                }
    }

    DispathFloyd(g, A, path);
}

void DispathFloyd(MatGraph g, int A[][MAXV], int path[][MAXV])
{
    int i, j, k, s;
    int apath[MAXV], d;

    for (i = 0; i < g.n; i++)
        for (j = 0; j < g.n; j++)
        {
            if (A[i][j] != INF && i != j)
            {
                printf("��%d��%d��·���ǣ�", i, j);
                k = path[i][j];
                d = 0;
                apath[d] = j;
                while (k != -1 && k != i)
                {
                    d++;
                    apath[d] = k;
                    k = path[i][k];
                }
                d++;
                apath[d] = i;
                printf("%d", apath[d]);

                for (s = d - 1; s >= 0; s--)
                    printf(",%d", apath[s]);
                printf("\t·������Ϊ:%d\n", A[i][j]);
            }
        }
}

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
    int B[4][4] = {
        {0, 5, INF, 7},
        {INF, 0, 4, 2},
        {3, 3, 0, 2},
        {INF, INF, 1, 0}};

    for (i = 0; i < 4; i++) //��ʼ���ڽӾ��󣬷�ֹ�쳣
        for (j = 0; j < 4; j++)
            g.edges[i][j] = B[i][j];
    g.e = 8;
    g.n = 4;

    for (i = 0; i < g.n; i++) //�ڽӾ���
        for (j = 0; j < g.n; j++)
            printf("%d %d :%d \n", i, j, g.edges[i][j]);

    printf("\nfloyd�㷨��ÿ�Զ���֮������·��\n");
    Floyd(g);

    system("pause");
    return 0;
}
