(1)��ͨDijkstra��ʱ�临�Ӷȣ��������ڳ���ͼ
�����߼�
1 d[1] = 0, d[2 ~ n] = INF;
2 for (i: 1 ~ n) //ÿ��ѭ��ȷ����㵽һ�������̾���
	t������st�У��Ҿ�������ĵ� //ÿ���ҵ�ǰ�����δȷ�����·�ĵ�
	��t����s
	��t���µ������ľ���
����ʵ��
int n, m;   //����������
int g[N][N];//�ڽӾ���洢����ͼ
int d[N];   //��̾���
bool st[N]; //�õ��Ƿ��������·

//��ʼ���е�֮�䶼û�б�
memset(g, INF, sizeof(g));

int dijkstra() {
    //��ʼ�����е㵽1����ΪINF
    memset(d, INF, sizeof(d));
    d[1] = 0;//��һ����Ϊ0
    for (int i = 1; i <= n; i++) {
        int t = -1;
        //ÿ���ҳ�����1����ĵ㲢���������·
        for (int j = 1; j <= n; j++) {
            if (!st[j] && (t == -1 || d[t] > d[j]))
                t = j;
        }
        st[t] = true;
        //�øõ�ȥ��ĵ������ɴ�ĵ�ľ���
        for (int j = 1; j <= n; j++)
            d[j] = min(d[j], d[t] + g[t][j]);
    }
    return d[n]; //�� d[n]==INF���������·
}
(2)���Ż�Dijkstra��ʱ�临�Ӷȣ���������ϡ��ͼ
�����߼�
1 d[1] = 0, d[2 ~ n] = INF;
2 ��һ�������
3 while (�Ѳ�Ϊ��)
	 ȡ�Ѷ�������
	 ����ȷ�����·��continue
	 ��չ�Ѷ�
	 �������·�����
����ʵ��
typedef pair<int,int> PII; //first:��1�ľ���|second:����
int n, m;  //����������
int h[N], e[M], w[M], ne[M], idx; //�ڽӱ�洢ϡ��ͼ
int d[N];
bool st[N];

memset(h, -1, sizeof(h));

int dijkstra() {
    //��ʼ���е㵽1����ΪINF
    memset(d, INF, sizeof(d));
    d[1] = 0;
    //����PII��С����|first:��1�ľ��룬second:����
    priority_queue<PII,vector<PII>,greater<PII>> que;
    //��һ�������
    que.push({0, 1});
    while (hp.size()) {
        //ȡ���Ѷ�
        PII t = que.top();
        que.pop();
        int u = t.second, dist = t.first;
        //����Ѿ�ȷ����ֱ����һ��
        if (st[u])   continue;
        st[u] = true; //Ϊtrue
        for (int i = h[u]; i != -1; i = ne[i]) {
            int j = e[i];
            if (d[j] > dist + w[i]) {
                d[j] = dist + w[i];
                //���
                que.push({d[j], j});
            }
        }
    }
    return d[n]; //�� d[n]==INF���������·
}
