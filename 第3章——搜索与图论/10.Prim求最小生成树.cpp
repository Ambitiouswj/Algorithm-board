�����߼�
1 d[1 ~ n] = INF;
2 for (i: 1 ~ n)
	tΪ��ͨ���������ͨ������ĵ�
	��t������ͨ��
	��t���������㵽��ͨ��ľ���
����ʵ��
int n, m;
int g[N][N];//�ڽӾ���
int d[N];   //����ͨ��ľ���
bool st[N]; //�õ��Ƿ�����ͨ����

int prim() {
    memset(d, INF, sizeof(d));//��ʼ�����о���ΪINF
    int ans = 0; //��ͨ��ı�Ȩ��:��С������
    for (int i = 1; i <= n; i++) {
        int t = -1;
        for (int j = 1; j <= n; j++) {
            if (!st[j] && (t == -1 || d[t] > d[j]))
                t = j;
        }
        //������ǵ�һ�����Ҿ���ΪINF�����ͼ����ͨ����������С������
        if (i > 1 && d[t] == INF) return INF;
        //���ǵ�һ���㣬����Ͼ���
        if (i > 1) ans += d[t];
        st[t] = true;//������ͨ��
        for (int j = 1; j <= n; j++)
            d[j] = min(d[j], g[t][j]);
    }
    return ans; //ans == INFʱ���򲻴�����С������
}
