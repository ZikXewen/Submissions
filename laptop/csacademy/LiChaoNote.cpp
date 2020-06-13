void add(line nw){
    int l = 0, r = N;
    while(l <= r){
        int m = (l + r) >> 1;
        if(nw(m) < tr[m](m)) swap(nw, tr[m]);
        if(nw(l) < tr[m](l)) r = m - 1;
        else if(nw(r) < tr[m](r)) l = m + 1;
        else break;
    }
}
long gt(int x, long ret = INF){
    int l = 0, r = N;
    while(l <= r){
        int m = (l + r) >> 1;
        ret = min(ret, tr[m](x));
        if(x < m) r = m - 1;
        else if(x > m) l = m + 1;
        else break;
    }
    return ret;
}