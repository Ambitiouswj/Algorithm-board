(1)��x^y%mod
int ksm(int x, int y, int mod) {
    int ans = 1;
    while (y) {
        if(y & 1) ans = ans * x % mod;
        y >>= 1;
        x = x * x % mod;
    }
    return ans;
}
(2)�������Ԫ����
//ksm����ͬ(1)
int inv(int x) {
    return ksm(x, mod - 2, mod);
}
