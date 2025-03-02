// Fenwick Tree
// 1-based indexing
template <typename T>
class Fenwick{
    vector<T> bit; // TODO: include STL vector
    int n;

public:
    Fenwick(int n){
        this->n = n;
        bit.clear();
        bit.resize(n+1);
    }
    void update(int idx, T val){
        for(; idx <= n; idx += idx & -idx){
            bit[idx] += val;
        }
    }
    T query(int idx){
        T res = 0;
        for(; idx > 0; idx -= idx & -idx){
            res += bit[idx];
        }
        return res;
    }
    T query(int l, int r){
        return query(r) - query(l - 1);
    }
};