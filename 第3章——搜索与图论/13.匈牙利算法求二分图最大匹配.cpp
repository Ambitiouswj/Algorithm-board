����ͼ��ƥ�䣺�Ӷ���ͼ������������ѡ���
���еı�֮��û�й�����

����ͼ��ƥ�䣺�Ӷ���ͼ������������ѡ���
���еı�֮��û�й�����
ʱ�临�Ӷȣ���һ�㲻��ﵽ
����ʵ��
int n1, n2, m;
int h[N], e[M], ne[M], idx;
int p[N]; //�ұߵ�ƥ�䵽����ߵ�����
bool st[N]; //�Ƿ�ƥ�䵽����ߵĵ�

bool find(int x) {
    //��������ߵ�ɴ�ĵ�
    for (int i = h[x]; i != -1; i = ne[i]) {
        int j = e[i];
        if (!st[j])  {//�����ûƥ�䵽��ߵĵ�
            st[j] = true;
            //��Ӧ�ұߵĵ㻹û��ƥ��|�ұߵ�����б��ƥ��
            if (!p[j] || find(p[j])) {
                p[j] = x;
                return true;
            }
        }
    }
    return false;
}
void solve() {
    memset(h, -1, sizeof(h));
    cin >> n1 >> n2 >> m;
    int a, b;
    while (m--) {
        cin >> a >> b;
        add(a, b); //ֻ������ҵı�
    }
    int ans = 0;
    for (int i = 1; i <= n1; i++) {
        memset(st, 0, sizeof(st)); //ÿ�θ���stΪfalse
        if (find(i)) ans++;
    }
    cout << ans << endl;
}

