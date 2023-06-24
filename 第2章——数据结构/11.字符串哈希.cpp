const int N = 100010, q = 131;
char str[N]; // ���±�1��ʼ�洢�ַ���
ULL h[N], p[N] = {1};
int n, m;

// ��ʼ��
void init() {
    for (int i = 1; i <= n; i++) {
        p[i] = p[i - 1] * q;
        h[i] = h[i - 1] * q + str[i];
    }
}

// ����
ULL find(int l, int r) {
    return h[r] - h[l - 1] * p[r - l + 1];
}
