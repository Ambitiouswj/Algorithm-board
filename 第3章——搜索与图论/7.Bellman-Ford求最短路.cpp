�����߼�
1 d[1] = 0, d[2 ~ n] = INF;
2 for (i: 1 ~ k)
	 for (j: 1 ~ m) //����ÿ����
		d[b] = min(d[b], d[a] + w)
����ʵ��
//ʹ�ýṹ���ߣ���a��bȨ��Ϊw�ı�
struct Edge {
    int a, b, w;
}e[M];
int n, m, k; //n����m���ߣ��󲻳���k���ߵ����·
int d[N],bp[N]; //bp������һ�εĽ����������������

int ford() {
    memset(d, INF, sizeof(d)); //��ʼ��
    d[1] = 0;
    for (int i = 1; i <= k; i++) {
        memcpy(bp, d, sizeof(d));//����|��ֹ��������
        for (int j = 1; j <= m; j++)  { //����ÿ����
            int a = e[j].a, b = e[j].b, w = e[j].w;
            d[b] = min(d[b], bp[a] + w);
        }
    }
    return d[n]; //�� d[n] > INF / 2:�����·
}
