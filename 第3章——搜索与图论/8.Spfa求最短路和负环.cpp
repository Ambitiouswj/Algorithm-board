(1)��Դ���·
�����߼�
1 d[1] = 0, d[2 ~ n] = INF;
2 ��һ�������;
    while (���в���)
		ȡ����ͷ
		for (��չ��ͷ)
			j = e[i];
			��t�������·
			��t���ڶ��������
����ʵ��
int n, m;
int h[N], e[N], w[N], ne[N], idx; //�ڽӱ�
int que[N], hh, tt; //ģ�����|��Ҫ���ǿռ�����|����д�˸�ȥ����
int d[N];
bool st[N]; //���Ƿ��ڶ�����

memset(h, -1, sizeof(h));

int spfa() {
    queue<int> que;
    //��ʼ������
    memset(d, INF, sizeof(d));
    d[1] = 0; st[1] = true;
    que.push(1);//��һ�������
    while (que.size()) {
        int t=que.front(); //ȡ����ͷ
        que.pop();
        st[t] = false;
        //��չ��ͷ
        for (int i = h[t]; i != -1; i = ne[i]) {
            int j = e[i];
            if (d[j] > d[t] + w[i]) {
                d[j] = d[t] + w[i];
                if (!st[j]) { //���j���ڶ����������
                    que.push(j);
                    st[j] = true;
                }
            }
        }
    }
    return d[n]; //�� d[n] == INF�������·
}
(2)*�жϸ���
�����߼�
1 ���е����
2  while (���в���)
		ȡ����ͷ
		for (��չ��ͷ)
			j = e[i];
			��t�������·
				cnt[j]=cnt[t]+1;
					cnt[j]==n ���и���
			��t���ڶ��������
����ʵ��
int n, m;
int h[N], e[N], w[N], ne[N], idx;
int d[N], cnt[N]; //cnt[i]����i���㾭���ı���
bool st[N];

memset(h, -1, sizeof(h));

void add(int p, int x, int c) {
    e[idx] = x;
    w[idx] = c;
    ne[idx] = h[p];
    h[p] = idx++;
}

bool spfa() {
    queue<int> que;
    //���е����
    for (int i = 1; i <= n; i++) {
        que.push(i);
        st[i] = true;
    }
    while (que.size()) {
        int t = que.front(); //ȡ����ͷ
        que.pop();
        st[t] = false;
        for (int i = h[t]; i != -1; i = ne[i]) {
            int j = e[i];
            if (d[j] > d[t] + w[i]) {
                d[j] = d[t] + w[i];
                cnt[j] = cnt[t] + 1; //���¾����ı���
                //������n���ߣ������پ�����n+1���㣬���϶����ڸ���
                if (cnt[j] >= n) return true;
                if (!st[j]) {
                    que.push(j);
                    st[j] = true;
                }
            }
        }
    }
    return false;
}
