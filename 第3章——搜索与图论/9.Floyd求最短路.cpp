�����߼�
1 ��ʼ��
	for (i: 1 ~ n)
		for (j: 1 ~ n)
			if (i == j) d[i,j] = 0;
			else d[i,j] = INF;
2 �����·
	for (k: 1 ~ n)
		for (i: 1 ~ n)
			for (j: 1 ~ n)
				d[i,j] = min(d[i,j], d[i,k] + d[k,j]);
����ʵ��
int d[N][N]; //�ڽ�(����)����
//��ʼ�������Լ�����Ϊ0������ΪINF
void init() {
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (i == j) d[i][j] = 0;
            else d[i][j] = INF;
}
//����DP˼��
void floyd() {
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
}
ѯ�ʣ�a -> b ,d[a][b]Ϊa��b�����·
        d[a][b] > INF/2 �����·
