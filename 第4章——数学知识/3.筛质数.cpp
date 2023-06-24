�١��Գ���ɸ������ʱ�临�Ӷȣ�O(n * log n)
vector<int> prime; //�洢1~n֮�������
bool st[N]; //�Ƿ��Ѿ���ɸ��

void getPrime(int n) {
    for (int i = 2; i <= n; i++) {
        if (st[i]) continue;
        prime.push_back(i);
        //ɸ������
        for (int j = 2 * i; j <= n; j += i)
            st[j] = true;
    }
}
�ڡ����Ϸ�ɸ������ʱ�临�Ӷȣ�O(n * log log n)
void getPrime(int n) {
    for (int i = 2; i <= n; i++) {
        if (!st[i]) {
            prime.push_back(i);
            //ɸȥ�����ı���
            for (int j = 2 * i; j <= n; j += i)
                st[j] = true;
        }
    }
}
�ۡ����Է�ɸ������ʱ�临�Ӷȣ�O(n)
void getPrime(int n) {
    for (int i = 2; i <= n; i++) {
        if (!st[i]) prime.push_back(i);
        //ɸ�������ı���
        for (int j = 0; prime[j] <= n / i; j ++) {
            st[prime[j] * i] = true;
            //p[j]��i����С������
            if (i % prime[j] == 0) break;
        }
    }
}
