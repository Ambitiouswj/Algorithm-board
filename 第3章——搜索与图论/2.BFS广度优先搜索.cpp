�������
1 ��ʼ״̬���
2 ѭ��while(que.size()) ȡ����ͷ������չ
���� ���Թ�
����һ��N*M�Ķ�ά�������飬������ʾһ���Թ���������ֻ����0��1������0��ʾ�����ߵ�·��1��ʾ����ͨ����ǽ�ڡ�
�������һ����λ�����Ͻ�(1, 1)������֪����ÿ�ο������ϡ��¡���������һ�������ƶ�һ��λ�á�
���ʣ����˴����Ͻ��ƶ������½�(n, m)����������Ҫ�ƶ����ٴΡ�
���ݱ�֤(1, 1)����(n, m)��������Ϊ����һ�����ٴ���һ��ͨ·��
#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;

typedef pair<int, int> PII;
const int N = 110;
PII que[N*N]; //����ģ�����
int hh, tt;
int n, m ,p[N][N], d[N][N];
int dx[] = {0, 1, 0, -1}, dy[]={1, 0, -1, 0};

bool check(int x1, int y1) {
return (x1 >= 1 && x1 <= n && y1 >= 1 && y1 <= m
		&& p[x1][y1] == 0 && d[x1][y1] == -1);
}

int bfs() {
    memset(d, -1, sizeof(d));
    hh = 0, tt = -1;
    que[++tt] = {1, 1};
    d[1][1] = 0;
    while (hh <= tt) {
        PII tp = que[hh++]; //ȡ��ͷ
        for (int i = 0; i < 4; i++) {
            int x1 = tp.x + dx[i], y1 = tp.y + dy[i];
            if (check(x1, y1)) {
                d[x1][y1] = d[tp.x][tp.y] + 1;
                que[++tt] = {x1, y1};
            }
        }
    }
    return d[n][m];
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> p[i][j];

    cout << bfs() << endl;
    return 0;
}
