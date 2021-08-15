#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define min(a,b) ( (a) < (b) ? (a) : (b) )
#define MAX_NODE 100
#define MAX_EDGE 100
#define INF 0x7fffffff      // ��ʾ���㲻��ͨ
int degree[1005];
int tree[1005];

typedef struct
{
    int number;   // ���λ
    int cost;     // �����
    int dis;      // ����������
}Node;

typedef struct
{
    int from;     // �����
    int to;       // ���յ�
    int dis;      // �߾���
}Edge;

int n, m;                              // ��ĸ����ͱߵĸ���
int total_edge, odd_point;             // �ܱ����������
Node map[MAX_NODE][MAX_NODE];          // ����������
int point[MAX_NODE];                   // ÿ�����Ķ���
int need_add_num, min_count, edge_num; // ��Ҫ��ӱߵĸ���
Edge odd_edge[MAX_EDGE];
int point_flag[MAX_EDGE];
int min_edge[MAX_EDGE];
int tmp_edge[MAX_EDGE];
int top;
int finish_flag = 0;
int path_stack[MAX_EDGE];

int findroot(int x){               //���鼯�ķ�ʽ�ж�ͼ��ͨ��
    if(tree[x]==-1)
        return x;
    else{
        int temp = findroot(tree[x]);
        tree[x] = temp;
        return temp;
    }
}

void Floyd()
{
    // �Ƚ�i��jֱ������Ǵ�i��k����k��j������ӵĽ��k���������ѭ����
    int i,j,k;
    for (k = 1; k <= n; k++)
        for (i = 1; i <= n; i++)
            if(map[i][k].dis != INF)
            {
                for (j = 1; j < n; j++)
                    if(map[k][j].dis != INF)
                    {
                        map[i][j].dis = map[j][i].dis = min(map[i][j].dis, map[i][k].dis + map[k][j].dis);
                    }
            }
}

void search_edge(int count, int step)
{
    // ��Ȼ��ǹ�ȱ���Ѱ�����ŷ���
    // step���ڼ�¼������count��¼��̳���
    // Ѱ��·�������������У���ͨ��i����

    int i;
    if (step == need_add_num)
    {
        if (count < min_count)
        {
            for (i = 0; i < need_add_num; i++)
            {
                min_edge[i] = tmp_edge[i];
            }
            min_count = count;
        }
        return;
    }
    int a, b, c;
    for (i = 0; i < edge_num; i++)
    {
        a = odd_edge[i].from;
        b = odd_edge[i].to;
        c = odd_edge[i].dis;
        if (point_flag[a] == 1 && point_flag[b] == 1)
            // ��������δ����
        {
            point_flag[a] = point_flag[b] = 0;    // �ñ��λΪ0
            tmp_edge[step] = i;
            search_edge(count + c, step + 1);
            point_flag[a] = point_flag[b] = 1;
        }
    }
}

void dijkstra_to_add_edge(int s, int e)
{
    int i;
    int dis[MAX_NODE];       // �㵽��ʼ��s����ľ���
    int used[MAX_NODE];      // ���λ
    int pre[MAX_NODE];       // ��¼�����һ������ģ��������

    memset(used, 0, sizeof(used));   // ��ʼ��һ��
    for (i = 1; i <= n; i++)
    {
        dis[i] = INF;
    }
    dis[s] = 0;

    while (1)
    {
        int v = -1;
        for ( i = 1; i <= n; i++)
        {
            if (!used[i] && (v == -1 || dis[i] < dis[v]))
            {
                v = i;
            }
        }
        if (v == e || v == -1)
        // ����ǰ����ĩ��eʱ����v������Сʱ
            break;
        used[v] = 1;    // �޸ı��λ
        for (i = 1; i <= n; i++)
        {
            if (map[v][i].cost < INF && (dis[v] + map[v][i].cost) < dis[i])
            {
                pre[i] = v;
                dis[i] = dis[v] + map[v][i].cost;
            }
        }
    }

    int v = e;
    int pre_node = e;
    while (pre_node != s)
    {
        pre_node = pre[v];
        ++map[pre_node][v].number;    // �ӱ�
        ++map[v][pre_node].number;
    }
}


void extend_edge(int add_num)
{
    int i,j;
    need_add_num = add_num;
    memset(point_flag, 0, sizeof(point_flag));
    edge_num = 0;

    // �������㶼������ʱ��
    for (i = 1; i < n; i++)
    {
        if ((point[i] & 0x1) == 1)
        {
            for (j = i+1; j <= n; j++)
            {
                if ((point[j] & 0x1) == 1 && map[i][j].dis < INF)
                {
                    point_flag[i] = point_flag[j] = 1;   // ��i��j������Ϊ��Ҫ�����ӵ����
                    odd_edge[edge_num].from = i;         // �������Ϣ����odd_edge������
                    odd_edge[edge_num].to = j;
                    odd_edge[edge_num].dis = map[i][j].dis;
                    edge_num++;
                }
            }
        }
    }

    min_count = INF;    // ������Сֵ������Ƚ�
    search_edge(0, 0);
    if (min_count < INF)
    {
        int a, b;
        for (i = 0; i < need_add_num; i++)
        {
            int k = min_edge[i];
            a = odd_edge[k].from;
            b = odd_edge[k].to;
            dijkstra_to_add_edge(a, b);   // ��dijkstra�㷨��ӱߺ�������̾���
            point[a] = point[b] = 0;
        }
        odd_point -= add_num * 2;
        total_edge += add_num;
    }
    else
    {
        exit(-1);
    }

}

void search_euler_path(int s)
{
    int i;
    for (i = 1; i <= n; i++)
    {
        if (map[s][i].number > 0)
        {
            --map[s][i].number;
            --map[i][s].number;
            path_stack[top++] = i;
            if (top == (total_edge + 1))
                // �����ܱ�����1
            {
                finish_flag = 1;
                return;
            }

            search_euler_path(i);
            if (finish_flag)
                return;
            ++map[s][i].number;
            ++map[i][s].number;
            --top;
        }
    }
}


int main()
{
    int i,j;

    printf("�����붥������ͱߵ�����:\n");

    while (scanf("%d %d", &n, &m) != EOF)
    {
        memset(tree, -1, sizeof(tree));
        memset(degree, 0, sizeof(degree));
        // ��ʼ��
        memset(point, 0, sizeof(point));
        for (i = 1; i <= n; i++)
            for (j = 1; j <= n; j++)
                map[i][j].cost = map[i][j].dis = INF;
        total_edge = 0;

        // ����ͼ������
        printf("�����붥��ͱߵĹ�ϵ:\n");
        int a, b, c;
        for (i = 0; i < m; i++)
        {
            scanf("%d %d %d", &a, &b, &c);
            int tempa = findroot(a);
            int tempb = findroot(b);
            if(tempa != tempb)
                tree[tempa] = tempb;
            degree[a]++;                //����ͼ��¼����
            degree[b]++;
            map[a][b].cost = map[b][a].cost = c;
            map[a][b].dis = map[b][a].dis = c;
            map[a][b].number = map[b][a].number = 1;
            ++point[a];
            ++point[b];
            ++total_edge;
        }

        int flag = 0;
        int ans = 0;
        for(i=1; i<= n; i++){     //�ж���ͨ��
            if(tree[i]==-1)
                ans++;
        }
        for( i=1; i<=n; i++){    //�ж϶���
            if(degree[i]%2){
                flag = 1;
                break;
            }
        }
        if(ans > 1 || flag)
            {
                printf("����ŷ����·\n");
                return 0;
            }
        else
            printf("��ŷ����·\n");
        odd_point = 0;
        for ( i = 1; i <= n; i++)
            // �жϵ��Ƿ�Ϊ���
        {
            if ((point[i] & 0x1) == 1)
            {
                odd_point++;
            }
        }

        int first_id = 1;    // �����ʾֵ�λ�� 1��ΪA
        if (odd_point > 2)
            // ����������������ʱ����floyd�㷨������������֮�����·����������ӱ�
        {
            Floyd();
            extend_edge(odd_point / 2);
            // ����������һ���ߣ�����Ҫ���odd_point/2����
        }

        top = 0;
        if (odd_point == 2)
            // ������Ϊ2��ʱ�򣬴�һ������������һ�����ȥ�������ܹ��ɻ�·��ֱ���˳�����
        {
            for (i = 1; i <= n; i++)
            {
                if ((point[i] & 0x1) == 1)
                {
                    first_id = i;
                    break;
                }

            }
            if (first_id != 1)
            {
                exit(-2);
            }
        }

        path_stack[top++] = first_id;
        // ����ջ�������������ȷ�����·�߲���������
        search_euler_path(first_id);

        int vex;
        // �����·�����
        for (i = 0; i <= total_edge; i++)
        {
            vex = path_stack[i];
            printf("%d", vex);
            if (i < total_edge)
            {
                printf("->");
            }
        }
        printf("\n");
    }

    return 0;
}


