//Segment tree operations: Range update(Lazy propagation) and Range Query

const int MAXN = 100005;
int arr[MAXN];
int seg[4 * MAXN];
int lazy[4 * MAXN];
bool push[4 * MAXN];
int N;

//Complexity: O(1)
//Stores what info. segment[i..j] should store
int combine(int &a, int &b) {
	return max(a, b);
}

//Lazy propagation
void propagate(int id, int l, int r) {
	if (push[id]) {
		seg[id] += lazy[id];
        int left = 2 * id, right = left + 1;
		if (r - l >= 2) {
			push[left] = true;
			push[right] = true;
			lazy[left] += lazy[id];
			lazy[right] += lazy[id];
		}
		push[id] = false;
		lazy[id] = 0;
	}
}

//Complexity: O(n)
void build(int id = 1, int l = 0, int r = N) {
	push[id] = false;
	lazy[id] = 0;
	if (r - l < 2) {
		//base case : leaf node information to be stored here
		seg[id] = arr[l];
		return ;
	}
	int mid = (l + r) / 2;
    int left = 2 * id, right = left + 1;
	build(left, l, mid);
	build(right, mid, r);
	seg[id] = combine(seg[left], seg[right]);
}

//Complexity: O(log n)
void update(int x, int y, int val, int id = 1, int l = 0, int r = N) {
	propagate(id, l, r);
	if (r <= x || y <= l) {
		return ;
	}
	if (x <= l && r <= y) {
		//base case : leaf node information to be stored here
		lazy[id] += val;
		push[id] = true;
		propagate(id, l, r);
		return ;
	}
	int mid = (l + r) / 2;
    int left = 2 * id, right = left + 1;
	update(x, y, val, left, l, mid);
	update(x, y, val, right, mid, r);
	seg[id] = combine(seg[left], seg[right]);
}

//Complexity: O(log n)
int query(int x, int y, int id = 1, int l = 0, int r = N) {
	propagate(id, l, r);
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