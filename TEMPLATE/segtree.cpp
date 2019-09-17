//Segment tree operations: Point update and Range Query

const int MAXN = 100005;
int arr[MAXN];
int seg[4 * MAXN];
int N;

//Complexity: O(1)
//Stores what info. segment[i..j] should store
int combine(int &a, int &b) {
	return a + b;
}

//Complexity: O(n)
void build(int id = 1, int l = 0, int r = N){
    if(r - l < 2){
        //base case : leaf node information to be stored here
        seg[id] = arr[l];
        return;
    }

    int mid = (l + r) / 2;
    int left = 2*id, right = left + 1;
    build(left, l, mid);
    build(right, mid, r);
    seg[id] = combine(seg[left], seg[right]);
}

//Complexity: O(log n)
void update(int p, int y, int id = 1, int l = 0, int r = N){
    if(r - l < 2){ 
        //base case : leaf node information to be stored here
        seg[id] = y;
        return;
    }

    int mid = (l + r) / 2;
    int left = 2 * id, right = left + 1;
    if(p < mid){
        update(p, y, left, l, mid);
    }else{
        update(p, y, right, mid, r);
    }
    seg[id] = combine(seg[left], seg[right]);
}

//Complexity: O(log n)
int query(int x, int y, int id = 1, int l = 0, int r = N){
    if(r <= x || y <= l){ // No overlap, return useless
        return 0;
    }

    if(x <= l && r <= y){ // overlap
        return seg[id];
    }

    int mid = (l + r) / 2;
    int left = 2 * id, right = left + 1;
    int a = query(x,  y, left, l, mid);
    int b = query(x, y, right, mid, r);
    return combine(a, b);
}
