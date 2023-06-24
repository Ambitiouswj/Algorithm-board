1 vector<T>, �䳤���飬������˼��
    size()  ����Ԫ�ظ���
    empty()  �����Ƿ�Ϊ��
    clear()  ���
    front()/back()
    push_back()/pop_back()
    begin()/end()
    []
    ֧�ֱȽ����㣬���ֵ���

2 pair<T,T>
    first, ��һ��Ԫ��
    second, �ڶ���Ԫ��
    ֧�ֱȽ����㣬��firstΪ��һ�ؼ��֣�
	��secondΪ�ڶ��ؼ��֣��ֵ���

3 string���ַ���
    size()/length()  �����ַ�������
    empty()
    clear()
    substr(��ʼ�±꣬(�Ӵ�����))  �����Ӵ�
    c_str()  �����ַ��������ַ��������ʼ��ַ

4 queue<T>, ����
    size()
    empty()
    push()  ���β����һ��Ԫ��
    front()  ���ض�ͷԪ��
    back()  ���ض�βԪ��
    pop()  ������ͷԪ��

5 priority_queue<T>, ���ȶ��У�Ĭ���Ǵ����
    size()
    empty()
    push()  ����һ��Ԫ��
    top()  ���ضѶ�Ԫ��
    pop()  �����Ѷ�Ԫ��
    �����С���ѵķ�ʽ��
		priority_queue<T,vector<T>,greater<T>>

6 stack<T>, ջ
    size()
    empty()
    push()  ��ջ������һ��Ԫ��
    top()  ����ջ��Ԫ��
    pop()  ����ջ��Ԫ��

7 deque<T>, ˫�˶���
    size()
    empty()
    clear()
    front()/back()
    push_back()/pop_back()
    push_front()/pop_front()
    begin()/end()
    []

8 set<T>, map<T,T>, multiset<T>, multimap<T,T>, 
  ����ƽ��������������������̬ά����������
    size()
    empty()
    clear()
    begin()/end()
    ++, -- ����ǰ���ͺ�̣�ʱ�临�Ӷ� O(logn)

    set<T>/multiset<T>
        insert()  ����һ����
        find()  ����һ����
        count()  ����ĳһ�����ĸ���
        erase()
            (1) ������һ����x��ɾ������x   O(k + logn)
            (2) ����һ����������ɾ�����������
        lower_bound()/upper_bound()
            lower_bound(x)  ���ش��ڵ���x����С�����ĵ�����
            upper_bound(x)  ���ش���x����С�����ĵ�����
    map<T,T>/multimap<T,T>
        insert()  ���������һ��pair
        erase()  ����Ĳ�����pair���ߵ�����
        find()
        []  ע��multimap��֧�ִ˲����� ʱ�临�Ӷ��� O(logn)
        lower_bound()/upper_bound()

9 unordered_set<T>, unordered_map<T,T>, 
  unordered_multiset<T>, unordered_multimap<T,T>, ��ϣ��
    ���������ƣ���ɾ�Ĳ��ʱ�临�Ӷ��� O(1)
    ��֧�� lower_bound()/upper_bound()�� ��������++��--

10 bitset, �Rλ
    bitset<10000> s;
    ~, &, |, ^
    >>, <<
    ==, !=
    []

    count()  �����ж��ٸ�1

    any()  �ж��Ƿ�������һ��1
    none()  �ж��Ƿ�ȫΪ0

    set()  ������λ�ó�1
    set(k, v)  ����kλ���v
    reset()  ������λ���0
    flip()  �ȼ���~
    flip(k) �ѵ�kλȡ��

