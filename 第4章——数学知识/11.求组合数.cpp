(1)���ƣ�DP˼�룬ʱ�临�Ӷȣ�O(n ^ 2)
//��ͨDP
int cnm(int n, int m) {
    if (m ==0 || m == n) return 1;
    if (m == 1) return n;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= i; j++) {
            if (!j) c[i][j] = 1;
            else c[i][j] = c[i - 1][j] + c[i - 1][j - 1]; //��ʱȡģ
        }
    }
    return c[n][m];
}
//���������Ż�ΪһάDP
int cnm(int n, int m) {
    if (m ==0 || m == n) return 1;
    if (m == 1) return n;
    for (int i = 0; i <= n; i++) {
        for (int j = min(i, m); j >= 0; j--) {
            if (i == j || j == 0) c[j] = 1;
            else c[j] = c[j] + c[j - 1]; //��ʱ��Ҫȡģ
        }
    }
    return c[m];
}
(2) Ԥ����׳ˣ�ʱ�临�Ӷȣ�O(n * log n)
int f[N], vf[N]; //�洢�׳˺ͽ׳˵���Ԫ
void fac() {
    f[0] = vf[0] = 1;
    for (int i = 1; i < N; i++) {
        f[i] = (f[i - 1] % mod * i % mod) % mod;
        vf[i] = vf[i - 1] * inv(i) % mod; //invΪ��Ԫ�����������ݡ�
    }
}

int cnm(int n, int m) {
    return f[n] * vf[m] % mod * vf[n - m] % mod;
}
(3) Lacus����ʱ�临�Ӷȣ�O(n * log n)������С��Ԥ����׳�
int cnm(int n, int m) {
    if (n < m) return 0;
    int ans = 1;
    for (int i = 1, j = n; i <= m; i++, j--) {
        ans = (ans % mod * j % mod) % mod;
        ans = ans * inv(i) % mod;
    }
    return ans;
}

int lucas(int n, int m) {
    if (n < mod && m < mod) return cnm(n, m);
    return cnm(n % mod, m % mod) * lucas(n / mod, m / mod) % mod;
}
