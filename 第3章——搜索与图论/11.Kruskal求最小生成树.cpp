�����߼�
1 ���б�Ȩ�ش�С��������
2 �������б�
	�ҵ����˵�ĸ��ڵ�
	if(fa!=fb)
		b������ͨ��
		���½��
����ʵ��
int p[N]; //���鼯
//�ṹ����
struct Edge {
    int a, b, w;
}e[M];
//���ձ�Ȩ������
bool cmp(Edge& e1, Edge& e2) { return e1.w < e2.w; }
//��ʼ�����鼯
void init() {
    for(int i = 1; i <= n; i++) p[i] = i;
}
//���Ҹ��ڵ�+·��ѹ��
int find(int x) {
    if (x != p[x]) p[x] = find(p[x]);
    return p[x];
}
int kruskal() {
    int ans = 0, cnt = 0; //cnt:��ͨ���ڱߵ�����
    sort(e + 1, e + 1 + m, cmp); //����Ȩ�ش�С��������
    for (int i = 1; i <= m; i++) { //����ÿ����
        int a = e[i].a, b = e[i].b, w = e[i].w;
        int fa = find(a), fb = find(b);
        if (fa != fb) {
            p[fa] = fb; //������ͨ��
            ans += w;
            cnt++;
        }
    }
    if (cnt < n - 1) return INF; //��ͨ���ڱ���<n-1�����ͼ����ͨ������С������
    else return ans;
}
