template <typename T>
T inverse(T a, T m) {
  T u = 0, v = 1;
  while (a != 0) {
    T t = m / a;
    m -= t * a; swap(a, m);
    u -= t * v; swap(u, v);
  }
  assert(m == 1);
  return u;
}

int mul(int a, int b){
    return (1LL * a * b) % M;
}

int pow(int a, int b){
    int res = 1;
    while(b){
        if(b&1){
            res = mul(res, a);
        }
        a = mul(a, a);
        b >>= 1;
    }
    return res;
}

int choose(int n, int k){
    vector<int> fact(n+1, 1);
    for(int i=1; i<=n; i++){
        fact[i] = mul(fact[i-1], i);
    }
    return mul(fact[n], mul(pow(fact[k], M-2), pow(fact[n-k], M-2)));
}
