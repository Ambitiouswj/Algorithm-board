/* �߶���ά��������ֵ */
// �߶����ṹ��
struct SegmentTree {
    int val;
    int l, r;
}tr[N << 2];

// ����ֵ
void pushup(int u) {
    tr[u].val = max(tr[u << 1].val, tr[u << 1 | 1].val);
}

// ����
void build(int u, int l, int r) {
    tr[u].l = l, tr[u].r = r;
    if (l == r) tr[u].val = a[l];
    else {
        int mid = l + r >> 1;
        build(u << 1, l, mid);
        build(u << 1 | 1, mid + 1, r);
        pushup(u);
    }
}

// �����޸� | ��a[x]��ֵ�޸�Ϊv
void modify(int u, int x, int v) {
    if (tr[u].l == tr[u].r) tr[u].val = v;
    else {
        int mid = tr[u].l + tr[u].r >> 1;
        if (x <= mid) modify(u << 1, x, v);
        else modify(u << 1 | 1, x, v);
        pushup(u);
    }
}

// �����ѯ
int query(int u, int l, int r) {
    if (l <= tr[u].l && r >= tr[u].r) return tr[u].val; // [l,r]�����˵�ǰ����
    int mid = l + r >> 1;
    int v = 0;
    if (l <= mid) v = max(v, query(u << 1, l, r)); // ���ӽڵ����ص�
    if (r > mid) v = max(v, query(u << 1 | 1, l, r)); // ���ӽڵ����ص�
    return v;
}

/* �߶�����֣����ӳٱ�� */
// �߶����ṹ��
struct SegmentTree {
    int sum;
    int lazy;
    int l, r;
}tr[N << 2];

// ���º�
void pushup(int u) {
    tr[u].sum = tr[u << 1].sum + tr[u << 1 | 1].sum;
}

// ����
void build(int u, int l, int r) {
    tr[u].l = l, tr[u].r = r;
    if (l == r) tr[u].sum = a[l];
    else {
        int mid = l + r >> 1;
        build(u << 1, l, mid);
        build(u << 1 | 1, mid + 1, r);
        pushup(u);
    }
}

// �ӳٱ�����´���
void pushdown(int u) {
    if (tr[u].lazy) { // �ڵ�u�����
        // ���������ӽڵ�
        tr[u << 1].sum += tr[u].lazy * (tr[u << 1].r - tr[u << 1].l + 1);
        tr[u << 1 | 1].sum += tr[u].lazy * (tr[u << 1 | 1].r - tr[u << 1 | 1].l + 1);
        // �������ӽڵ�����ӳٱ��
        tr[u << 1].lazy += tr[u].lazy;
        tr[u << 1 | 1].lazy += tr[u].lazy;
        tr[u].lazy = 0;
    }
}

// �����޸� | ��[l, r]��ֵ����c
void modify(int u, int l, int r, int c){
    if (l <= tr[u].l && r >= tr[u].r) { // ��ȫ����
        tr[u].sum += c * (tr[u].r - tr[u].l + 1); // ���½ڵ���Ϣ
        tr[u].lazy += c; // �����ӳٱ��
    } else {
        pushdown(u); // �´��ӳٱ��
        int mid = tr[u].l + tr[u].r >> 1;
        if (l <= mid) modify(u << 1, l, r, c);
        if (r > mid) modify(u << 1 | 1, l, r, c);
        pushup(u);
    }
}

// �����ѯ | [l, r]�����
int query(int u, int l, int r) {
    if (l <= tr[u].l && r >= tr[u].r) return tr[u].sum; // [l, r]�����˵�ǰ����
    pushdown(u); // �´��ӳٱ��
    int mid = tr[u].l + tr[u].r >> 1;
    int ans = 0;
    if (l <= mid) ans += query(u << 1, l, r); // ���ӽڵ����ص�
    if (r > mid) ans += query(u << 1 | 1, l, r); // ���ӽڵ����ص�
    return ans;
}
