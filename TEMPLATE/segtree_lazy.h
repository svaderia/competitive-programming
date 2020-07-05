//Segment tree operations: Range update(Lazy propagation) and Range Query

typedef long long int lli;
typedef vector<lli> vli;

struct node{
    lli data;
    lli lazy;
    bool push;

    void init(){
        lazy = 0;
        push = 0;
    }

    void assign(lli val){
        data = val;
    }
}typedef node;

vector<node> seg;
int N;
vli arr;

//Complexity: O(1)
//Stores what info. segment[i..j] should store
node merge(node &left, node &right){
    node id;
    id.data = left.data + right.data; // merge operation
    return id;
}

//Lazy propagation
void propagate(int id, int l, int r) {
    if (seg[id].push) {

        seg[id].data += seg[id].lazy; // push operation

        int left = 2 * id, right = left + 1;
        if (r - l >= 2) {
            seg[left].push = true;
            seg[right].push = true;
            seg[left].lazy += seg[id].lazy;
            seg[right].lazy += seg[id].lazy;
        }
        seg[id].init();
    }
}

//Complexity: O(n)
void build(int id = 1, int l = 0, int r = N) {
    seg[id].init();
    if (r - l < 2) {
        //base case : leaf node information to be stored here
        seg[id].assign(arr[l]);
        return ;
    }
    int mid = (l + r) / 2;
    int left = 2 * id, right = left + 1;
    build(left, l, mid);
    build(right, mid, r);
    seg[id] = merge(seg[left], seg[right]);
}

//Complexity: O(log n)
void update(int x, int y, int val, int id = 1, int l = 0, int r = N) {
    propagate(id, l, r);
    if (r <= x || y <= l) {
        return ;
    }
    if (x <= l && r <= y) {
        //base case : leaf node information to be stored here
        seg[id].lazy += val;
        seg[id].push = true;
        propagate(id, l, r);
        return ;
    }
    int mid = (l + r) / 2;
    int left = 2 * id, right = left + 1;
    update(x, y, val, left, l, mid);
    update(x, y, val, right, mid, r);
    seg[id] = merge(seg[left], seg[right]);
}

//Complexity: O(log n)
node query(int x, int y, int id = 1, int l = 0, int r = N) {
    propagate(id, l, r);
    if(r <= x || y <= l){ // No overlap, return useless
        node id;
        id.init();
        id.assign(0);
        return id;
    }

    if(x <= l && r <= y){ // overlap
        return seg[id];
    }

    int mid = (l + r) / 2;
    int left = 2 * id, right = left + 1;
    node a = query(x,  y, left, l, mid);
    node b = query(x, y, right, mid, r);
    return merge(a, b);
}
