#include "head.h"
///////////////////////////////////////////////////////////////////////////
//�ڽӱ����ʽ�洢�ṹ�����������
void CreateAdj(AdjGraph *&G, int A[MAXV][MAXV], int n, int e)
{
    int i, j;
    ArcNode *p;
    G = (AdjGraph *)malloc(sizeof(AdjGraph));
    for (i = 0; i < n; i++)
        G->adjlist[i].firstarc = NULL;

    for (i = 0; i < n; i++)
        for (j = n - 1; j >= 0; j--)
            if (A[i][j] != 0 && A[i][j] != INF)
            {
                p = (ArcNode *)malloc(sizeof(ArcNode));
                p->adjvex = j;
                p->weight = A[i][j];
                p->nextarc = G->adjlist[i].firstarc;
                G->adjlist[i].firstarc = p;
            }
    G->n = n;
    G->e = e;
}

void DispAdj(AdjGraph *G) //����ڽӱ�G
{
    int i;
    ArcNode *p;
    for (i = 0; i < G->n; i++)
    {
        p = G->adjlist[i].firstarc;
        printf("%3d: ", i);
        while (p != NULL)
        {
            if (p->weight != 2147483647) //2147483647
                printf("%3d[%d]��", p->adjvex, p->weight);
            p = p->nextarc;
        }
        printf("��\n");
    }
}

void DestroyAdj(AdjGraph *&G) //�����ڽӱ�
{
    int i;
    ArcNode *pre, *p;
    for (i = 0; i < G->n; i++) //ɨ�����еĵ�����
    {
        pre = G->adjlist[i].firstarc; //pָ���i����������׽��
        if (pre != NULL)
        {
            p = pre->nextarc;
            while (p != NULL) //�ͷŵ�i������������б߽��
            {
                free(pre);
                pre = p;
                p = p->nextarc;
            }
            free(pre);
        }
    }
    free(G); //�ͷ�ͷ�������
}

/////////////////////////////////////////////////////////////////////
//�����������㷨������������
//�ڽӱ����ʽ������ȱ����㷨
void DFS(AdjGraph *G, int v)
{
    ArcNode *p;
    visited[v] = 1;
    printf("%d ", v);
    p = G->adjlist[v].firstarc;
    while (p != NULL) //Ϊ�˰�p��ָ�������ڵ�ȫ������
    {
        if (visited[p->adjvex] == 0)
            DFS(G, p->adjvex);
        p = p->nextarc;
    }
}
//�ڽӱ����ʽ������ȱ����㷨
void BFS(AdjGraph *G, int v)
{
    int w, i;
    ArcNode *p;
    SqQueue *qu;
    InitQueue(qu);
    int visited[MAXV];

    for (i = 0; i < G->n; i++)
        visited[i] = 0;

    printf("%2d", v);
    visited[v] = 1;

    enQueue(qu, v);

    while (!QueueEmpty(qu))
    {
        deQueue(qu, w);
        p = G->adjlist[w].firstarc;
        while (p != NULL)
        {
            if (visited[p->adjvex] == 0)
            {
                printf("%2d", p->adjvex);
                visited[p->adjvex] = 1;
                enQueue(qu, p->adjvex);
            }
            p = p->nextarc;
        }
    }
    printf("\n");
}

/////////////////////////////////////////////////////////////////////////////////////////
//�ڽӱ�ת�����ڽӾ���ĺ���
//�ú���Ҳ���Ա��һ�������ڽӾ���ĺ���
void ListToMat(AdjGraph *G, MatGraph &g)
{
    int i;
    ArcNode *p;

    for (i = 0; i < G->n; i++) //ɨ��ÿһ��ͷ�ڵ㶥��
    {
        p = G->adjlist[i].firstarc;
        while (p != NULL) //�ҵ������Ѱ��ͷ�ڵ�ĺ�̱߽ڵ�
        {
            g.edges[i][p->adjvex] = p->weight;
            p = p->nextarc;
        }
    }
    g.n = G->n;
    g.e = G->e;
}

//����ڽӾ���ĺ���
void DispMat(MatGraph g)
{
    int i, j;
    printf("\n��ͼ�Ķ�����%d��������%d\n\n", g.n, g.e);
    for (i = 0; i < g.n; i++)
        for (j = 0; j < g.n; j++)
        {
            if (i == j)
                printf(" (%d, %d)��ȨֵΪ0 \n", i, j);
            else if (g.edges[i][j] == INF)
                printf(" (%d, %d)��ȨֵΪINF \n", i, j);
            else
                printf(" (%d, %d)��ȨֵΪ%d \n", i, j, g.edges[i][j]);
        }
}

//�ڽӾ���ת�����ڽӱ�
void MatToList(MatGraph g, AdjGraph *&G)
{
    int i, j;
    ArcNode *p;
    G = (AdjGraph *)malloc(sizeof(AdjGraph));
    for (i = 0; i < g.n; i++)
        G->adjlist[i].firstarc = NULL;

    for (i = 0; i < g.n; i++)
        for (j = g.n - 1; j >= 0; j--)
            if (g.edges[i][j] != 0 && g.edges[i][j] != INF) //&& g.edges[i][j] != -1
            {
                p = (ArcNode *)malloc(sizeof(ArcNode));
                p->adjvex = j;
                p->weight = g.edges[i][j];
                p->nextarc = G->adjlist[i].firstarc;
                G->adjlist[i].firstarc = p;
            }
    G->n = g.n;
    G->e = g.e;
}

////////////////////////////////////////////////////////////////////////////
//�����ǹ�����С�������������㷨���ɲο��̲�p279

//Prim �㷨����������
void Prim(MatGraph g, int v)
{
    int lowcost[MAXV];
    int MIN;
    int closest[MAXV], i, j, k;

    for (i = 0; i < g.n; i++)
    {
        lowcost[i] = g.edges[v][i];
        closest[i] = v;
    }
    for (i = 1; i < g.n; i++)
    {
        MIN = INF;
        for (j = 0; j < g.n; j++)
            if (lowcost[j] != 0 && lowcost[j] < MIN)
            {
                MIN = lowcost[j];
                k = j; //��¼����Ľڵ�ı��
            }
        printf("��(%d,%d)ȨΪ��%d\n", closest[k], k, MIN);
        lowcost[k] = 0;

        for (j = 0; j < g.n; j++)
            if (lowcost[j] != 0 && g.edges[k][j] < lowcost[j])
            {
                lowcost[j] = g.edges[k][j];
                closest[j] = k;
            }
    }
}

// ��������
void InsertSort(Edge arr[MAXV], int length)
{
    for (int i = 1; i < length; i++)
    {
        int j;
        if (arr[i].w < arr[i - 1].w)
        {
            int temp = arr[i].w;
            Edge Temp = arr[i];
            for (j = i - 1; j >= 0 && temp < arr[j].w; j--) //�ҵ���Բ����ϵľ���ǰ��
            {
                arr[j + 1] = arr[j];
            }
            arr[j + 1] = Temp;
        }
    }
}
////////////////////////////
//��³ʲ�����㷨������С������
void Kruskal(MatGraph g)
{
    int i, j, ul, vl, sn1, sn2, k;
    int vset[MAXV];
    Edge E[MaxSize]; //���ͼ�е����еıߵ���Ϣ
    k = 0;           //e��������±��0��ʼ

    for (i = 0; i < g.n; i++)
        for (j = 0; j < g.n; j++) //for (j = 0; j <= i; j++) ||ע��|| �����������Ȩͼ���㷨������ͼ��Ҫ�ʵ��޸���ע��
            if (g.edges[i][j] != 0 && g.edges[i][j] != INF)
            {
                E[k].u = i;
                E[k].v = j;
                E[k].w = g.edges[i][j];
                k++;
            }

    InsertSort(E, g.e); //���뷨����

    for (i = 0; i < g.n; i++) //���츨������
        vset[i] = i;          //�÷��÷�
    k = 1;
    j = 0;

    while (k < g.n)
    {
        ul = E[j].u;
        vl = E[j].v;
        sn1 = vset[ul];
        sn2 = vset[vl];

        if (sn1 != sn2)
        {
            printf(" (%d,%d): %d\n", ul, vl, E[j].w);
            k++;
            for (i = 0; i < g.n; i++) //��ֹ���ظ����룬�������ú�ͻ����sn1=sn2����������ⱻ�ظ�����
                if (vset[i] == sn2)
                    vset[i] = sn1;
        }
        j++;
    }
}

///////////////////////////////////////////////////////////////////////////
//���������·���Ļ����㷨
///�ɲο��̲�p290

//�ҿ�˹�����㷨���£�vΪԴ���ţ���
void Dijkstra(MatGraph g, int v)
{
    int dist[MAXV], path[MAXV];
    int s[MAXV]; //s[i]=1��ʾ����i��s�У�s
    int mindis, i, j, u;
    for (i = 0; i < g.n; i++)
    {
        dist[i] = g.edges[v][i]; //�����ʼ��
        s[i] = 0;                //s[]�ÿ�
        if (g.edges[v][i] < INF) //·����ʼ��
            path[i] = v;         //����v��i�б�ʱ
        else
            path[i] = -1; //����v��iû��ʱ
    }
    s[v] = 1; //Դ��v����S��
    path[v] = 0;
    for (i = 0; i < g.n - 1; i++) //ѭ��n-1��
    {
        mindis = INF;
        for (j = 0; j < g.n; j++)
            if (s[j] == 0 && dist[j] < mindis)
            {
                u = j;
                mindis = dist[j];
            }
        s[u] = 1;                 //����u����S��
        for (j = 0; j < g.n; j++) //�޸Ĳ���s�еĶ���ľ���
            if (s[j] == 0)
                if (g.edges[u][j] < INF &&
                    dist[u] + g.edges[u][j] < dist[j])
                {
                    dist[j] = dist[u] + g.edges[u][j];
                    path[j] = u;
                }
    }
    //Dispath(dist, path, s, g.n, v); //������·��
    Dispath(g, dist, path, s, v);
}
//����Ӷ���v������������̵�·��
void Dispath(MatGraph g, int dist[], int path[], int s[], int v)
{
    int i, j, k;
    int apath[MAXV], d;

    for (i = 0; i < g.n; i++)
        if (s[i] == 1 && i != v)
        {
            printf("�Ӷ���%d������%d��·������Ϊ��%d\t·��Ϊ��", v, i, dist[i]);
            d = 0;
            apath[d] = i;
            k = path[i];

            if (k == -1)
                printf("��·��\n");
            else
            {
                while (k != v)
                {
                    d++;
                    apath[d] = k;
                    k = path[k];
                }
                d++;
                apath[d] = v;
                printf("%d", apath[d]);
                for (j = d - 1; j > 0; j--)
                    printf(".%d", apath[j]);
                printf("\n");
            }
        }
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////
//���������㷨
//ÿ�Զ���֮������·��
//��������������һ������Ȩֵ�������������ͼ����ÿһ�Զ���i��j���������i�붥��j֮������·�������·�����ȡ�
/*��1���ö�ά����A�洢���·�����ȣ�
   Ak[i][j]��ʾ���Ƕ���0~k��ó���i?j�����·�����ȡ�
   An-1[i][j]��ʾ���յ�i?j�����·�����ȡ�

//��2���ö�ά����path������·��
pathk[i][j]��ʾ���Ƕ���0~k��ó���i?j�����·����
pathn-1[i][j]��ʾ����i?j�����·����
*/
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
//////////////////////////////////////////////////////////////////////////////
//���������㷨
void TopSort(AdjGraph *G) //���������㷨
{
    int i, j;
    int St[MAXV], top = -1; //ջSt��ָ��Ϊtop
    ArcNode *p;
    for (i = 0; i < G->n; i++) //����ó�ֵ0
        G->adjlist[i].count = 0;
    for (i = 0; i < G->n; i++) //�����ж�������
    {
        p = G->adjlist[i].firstarc;
        while (p != NULL)
        {
            G->adjlist[p->adjvex].count++;
            p = p->nextarc;
        }
    }
    for (i = 0; i < G->n; i++) //�����Ϊ0�Ķ����ջ
        if (G->adjlist[i].count == 0)
        {
            top++;
            St[top] = i;
        }
    while (top > -1) //ջ����ѭ��
    {
        i = St[top];
        top--;                      //��ջһ������i
        printf("%d ", i);           //����ö���
        p = G->adjlist[i].firstarc; //�ҵ�һ���ڽӵ�
        while (p != NULL)           //������i�ĳ����ڽӵ����ȼ�1
        {
            j = p->adjvex;
            G->adjlist[j].count--;
            if (G->adjlist[j].count == 0) //�����Ϊ0���ڽӵ��ջ
            {
                top++;
                St[top] = j;
            }
            p = p->nextarc; //����һ���ڽӵ�
        }
    }
}