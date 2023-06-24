//STLģ��
���ȶ��У� priority_queue<T> //Ĭ��Ϊ�����
����С���ѣ� priority_queue<T,vector<T>,greater<T>>

//ģ���|С����Ϊ��
1.����һ������heap[++tt]=x; up(tt);
2.����Сֵ��heap[1];
3.ɾ����Сֵ��heap[1]=heap[tt]; tt--; down(1);
4.ɾ����k���ڵ㣺head[k]=heap[tt]; tt--; down(k); up(k);
5.����k���ڵ����ָ�Ϊx��heap[k]=x; down(k); up(k);
int n, tt, h[N]; //tt:��������Ԫ�ظ���

// ��ʼ���ѣ�O(n)
void init() {
    for (int i = n / 2; i > 0; i--) down(i);
}

// ����Ԫ�أ�O(log n)
void insert(int x) {
    //�Ӷѵײ���Ȼ��up
    h[++tt] = x;
    up(tt);
}

// ���ϵ���
void up(int p) {
    while (p > 1) {
        if (h[p] > h[p / 2]) {
            swap(h[p], h[p / 2]);
            p /= 2;
        }
        else break;
    }
}

// ���µ���
void down(int p) {
    int s = p * 2;
    while (s <= tt) {
        if (s < tt && h[s] < h[s + 1]) s++;
        if (h[s] > h[p]) {
            swap(h[s], h[p]);
            p = s; s = p * 2;
        }
        else break;
    }
}

// ɾ�����ڵ㣺��β�ڵ㸲�Ǹ��ڵ㣬�����µ���
void extract() {
    h[1] = h[tt--];
    down(1);
}

// ɾ����k���ڵ㣺 ��β�ڵ㸲�ǵ�k���ڵ㣬�����ϻ��µ���
void remove(int k) {
    h[k] = h[tt--];
    up(k); down(k);
}

// ����k���ڵ����ָ�Ϊx
void alter(int k, int x) {
    h[k] = x;
    up(k); down(k);
}
