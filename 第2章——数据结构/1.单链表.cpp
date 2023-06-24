// head:ͷ�ڵ�,e:�洢Ԫ��,ne:�洢�±�
int head, e[N], ne[N], idx;

// ��ʼ��
void init() {
    head = -1;
    idx = 0;
}

// ��ͷ������һ����
void insertByHead(int x) {
    e[idx] = x;
    ne[idx] = head;
    head = idx;
    idx++;
}

// �ڵ�k����������룬����k-1
void insertBehind(int k, int x) {
    e[idx] = x;
    ne[idx] = ne[k];
    ne[k] = idx;
    idx++;
}

// ɾ����k���������������k-1
void deleteBehind(int k) {
    ne[k] = ne[ne[k]];
}

// ��ӡ���
void print() {
    for (int i = head; i != -1; i = ne[i])
        printf("%d ", e[i]);
    printf("\n");
}
