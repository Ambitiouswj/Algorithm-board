// son[i][j]: ��i���ڵ��£��ַ�j��λ��
// cnt[]: �Ե�ǰ�ڵ�Ϊ�յ���ַ�������
int son[N][26],cnt[N],idx;

//����
void insert(string str) {
    int p = 0; //��0�Žڵ㿪ʼ
    for (int i = 0; i < str.size(); i++) {
        int u = str[i] - 'a'; // ��a~zӳ�䵽0~25
        if (!son[p][u]) // �����ڽڵ�����ڵ�
            son[p][u] = ++idx;
        p = son[p][u]; // ����������
    }
    cnt[p]++; // ��¼����
}

// ѯ��
int query(string str) {
    int p = 0;
    for (int i = 0; i < str.size(); i++)
    {
        int u = str[i] - 'a';
        if (!son[p][u]) // û�иýڵ㣬����0
            return 0;
        p = son[p][u];
    }
    return cnt[p]; // ���ظýڵ��β���ַ�������
}
