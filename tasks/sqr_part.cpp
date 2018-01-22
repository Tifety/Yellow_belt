template <typename T> T Sqr(T x);

template <typename First, typename Second>
pair <First, Second> operator * (const pair <First, Second>& x1, const pair <First, Second> x2);


template <typename Key, typename Value>
map <Key, Value> operator* (map <Key, Value>& m1,const  map <Key, Value>& m2);

template <typename Item>
vector <Item> operator * (const vector <Item>& v1, const vector <Item>& v2);

template <typename Item>
vector <Item> operator * (const vector <Item>& v1, const vector <Item>& v2) {
    int size = max (v1.size(), v2.size());
    vector <Item> answer(size);
    for  (int i = 0; i < size; i ++) {
        answer[i]=v1[i]*v2[i];
    }
    return answer;
}

template <typename Key, typename Value>
map <Key, Value> operator* (map <Key, Value>& m1,const map <Key, Value>& m2) {
for (auto &item : m1) {
    if (m2.count(item.first)) {
        item.second = item.second * m2.at(item.first);
    }
}
return m1;
}


template <typename First, typename Second>
pair <First, Second> operator * (const pair <First, Second>& x1, const pair <First, Second> x2) {
    pair <First, Second> ans;
    ans.first = x1.first * x2.first;
    ans.second = x1.second * x2.second;
    return ans;
}


template <typename T>
T Sqr( T x) {
    return x * x;
}

