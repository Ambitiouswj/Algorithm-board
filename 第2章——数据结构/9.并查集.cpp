// �ж�����
p[x] == x?
// �󼯺ϱ��
while (p[x] != x) x = p[x];
// �ϲ����ϣ�x1��x���ϱ�ţ�y1��y���ϱ��
p[x] = y1; / p[y] = x1;

/* (1)��ͨ���鼯 */
//���鼯��ʼ�� | ÿ���ڵ���һ������
void init() {
    for (int i = 1; i <= n; i++) p[i] = i;
}

// ��ͨ���� + ·��ѹ��
int find(int x) {
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

// �ϲ�a,b���������ڼ���
void merge(int a, int b) {
    p[find(a)] = find(b);
}

/* (2)ά������Ԫ�ظ��� */
// ���鼯��ʼ�� | ÿ���ڵ���һ������ | ÿ������Ԫ������Ϊ1
void init() {
    for (int i = 1; i<=n; i++) {
        p[i] = i;
        s[i] = 1;
    }
}

// ��ͨ���� + ·��ѹ��
int find(int x) {
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

// �ϲ����� + �Ӻ�
void merge(int a, int b) {
    if (find(a) == find(b)) // �Ѿ���ͬһ���ϵ���
        return;
    s[find(b)] += s[find(a)];
    p[find(a)] = find(b);
}

/* (3)ά�������ڵ���� */
// ���鼯��ʼ�� | ÿ���ڵ���һ������
void init() {
    for (int i = 1; i <= n; i++) p[i] = i;
}
// ��ͨ���� + ·��ѹ�� + ����ѹ��
int find(int x) {
    if (p[x] != x) {
        int u = find(p[x]);
        d[x] += d[p[x]];
        p[x] = u;
    }
    return p[x];
}
// �ϲ����� + �Ӻ�
void merge(int a, int b) {
    if (find(a) == find(b)) // �Ѿ���ͬһ���ϵ���
        return;
    p[find(a)] = find(b);
    d[find(a)] // ������Ŀ����
}
