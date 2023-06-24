����ͼ�� ͼ�в��������������㻷
ͼ�����еĵ�ɷ�Ϊ�������ϣ�
���б�ֻ����������֮�䲻�ڼ����ڲ���

����ʵ��
int n, m;
int h[N], e[M], ne[M], idx; //�ڽӱ�
int cor[N]; //δȾɫ:0����Ⱦɫ:1|2

void add(int p, int x) {
    e[idx] = x;
    ne[idx] = h[p];
    h[p] = idx++;
}
(1)DFSʵ��
bool dfs(int u, int c) {
    cor[u] = c; //Ⱦ��ɫ
    for (int i = h[u]; i != -1; i = ne[i]) {
        int j = e[i];
        //�͸��ڵ�ͬɫ|����δȾɫ��Ⱦɫʧ�ܣ�������false
        if (cor[j] == c || (!cor[j] && !dfs(j, 3 - c)))
            return false;
    }
    return true;
}
void solve() {
    memset(h, -1, sizeof(h));
    cin >> n >> m;
    int a, b;
    /*������ߴ���ʡ��*/
    //ÿ��Ⱦһ����ͨ��
    for (int i = 1; i <= n; i++) {
        if (!cor[i] && !dfs(i, 1)) {  //Ⱦɫʧ��
            cout << "No" << endl;
            return;
        }
    }
    cout << "Yes" << endl;
}
(2)BFSʵ��
bool bfs(int u) {
    queue<int> que;
    cor[u] = 1; //��ͨ���һ����Ⱦ��ɫ1
    que.push(u); //���
    while (que.size()) {
        int t = que.front(); //ȡ����ͷ
        que.pop();
        for (int i = h[t]; i != -1; i = ne[i]) {
            int j = e[i];
            if (!cor[j]) { //δȾɫ��Ⱦ�ϲ�ͬɫ�����
                cor[j] = 3 - cor[t];
                que.push(j);
            }
            else if (cor[j] == cor[t]) //ͬɫ�򷵻�false
                return false;
        }
    }
    return true;
}
void solve() {
    /*ͬ��DFS����*/
    for (int i = 1; i <= n; i++) {
        if (!cor[i] && !bfs(i)) { //Ⱦɫʧ��
            cout << "No" << endl;
            return;
        }
    }
    cout << "Yes" << endl;
}
