/* (1)������ */
// �ڽӱ�洢
const int N = 1e5 + 3;
int h[N], e[N], ne[N], idx = 0;

// ����
void insert(int x) {
    int k = (x % N + N) % N;
    e[idx] = x;
    ne[idx] = h[k];
    h[k] = idx;
    idx++;
}

// ����
bool find(int x) {
    int k = (x % N + N) % N;
    for (int i = h[k]; i != -1; i = ne[i]) {
        if (e[i] == x) return true;
    }
    return false;
}

/* (2)����Ѱַ�� */
const int N = 2e5 + 3, null = 0x3f3f3f3f;
int h[N];

// ����
void insert(int x) {
    h[find(x)] = x;
}

// ����
int find(int x) {
    int k = (x % N + N) % N;
    while (h[k] != null && h[k] != x) {
        k++;
        if (k == N) k = 0;
    }
    return k;
}
