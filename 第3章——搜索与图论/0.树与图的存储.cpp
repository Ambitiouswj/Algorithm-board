����ͼ�Ĵ洢
����ͼ==˫������ͼ // ��������໥�ı�
��==�޻���ͨͼ

1. ����ͼ���ڽӾ���
// g[i][j]��ʾ��i��j��һ�������
bool g[N][N]; // �洢0|1���ɴ�򲻿ɴ�
int g[N][N]; // �洢��Ȩ
// ��ʼ��
for (int i = 1; i <= n; i++)
	for (int j = 1; j <= n; j++)
		if (i == j) g[a][b] = 0;
		else g[a][b] = INF;
// ��Ӵ�a��b�ıߣ���ȨΪc
g[a][b] = c;

2. ϡ��ͼ���ڽӱ�
// ����ģ������
int h[N];
int e[M], w[M], ne[M], idx;
// ��ʼ��
memset(h, -1, sizeof(h));
// ���һ��p��x�ıߣ���ȨΪc
e[idx] = x;
w[idx] = c;
ne[idx] = h[p];
h[p] = idx++;

3. vector��ͼ
vector<int> g[N];
vector<pair<int, int>> g[N];
// ���u��v�ı�
g[u].push_back(v);
// ���u��vȨֵΪw�ı�
g[u].push_back({v, w});
