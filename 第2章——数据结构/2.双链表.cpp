// �ֱ�洢���ݣ�ǰ�ڵ�ͺ�ڵ㣬���ýڵ�����
int e[N], l[N], r[N], idx;

// ��ʼ��
void init() {
    r[0] = 1;
    l[1] = 0;
    idx = 2;
}

// �ڵ�k������������Ҷ˲���һ����
// ����˲��룺insert(0,x)
// ���Ҷ˲��룺insert(l[1],x)
// ��k��������������룺insert(l[k+1],x)
// ��k����������Ҳ���룺insert(k+1,x)
void insertR(int k, int x) {
    e[idx] = x;
    r[idx] = r[k];
    l[idx] = k;
    l[r[k]] = idx;
    r[k] = idx;
    idx++;
}

// ɾ����k���������������k+1
void deletek(int k) {
    r[l[k]] = r[k];
    l[r[k]] = l[k];
}

// �����Ҵ�ӡ
void print() {
    for (int i = r[0]; i != 1; i = r[i])
        printf("%d ",e[i]);
}
