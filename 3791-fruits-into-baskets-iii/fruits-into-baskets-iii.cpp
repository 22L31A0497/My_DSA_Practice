class SegmentTree {
    vector<int> tree;
    int n;
public:
    SegmentTree(vector<int>& baskets) {
        n = baskets.size();
        tree.resize(4 * n, -1);
        build(baskets, 0, n - 1, 1);
    }
    
    void build(vector<int>& baskets, int l, int r, int idx) {
        if (l == r) {
            tree[idx] = baskets[l];
            return;
        }
        int mid = l + (r - l) / 2;
        build(baskets, l, mid, idx * 2);
        build(baskets, mid + 1, r, idx * 2 + 1);
        tree[idx] = max(tree[idx * 2], tree[idx * 2 + 1]);
    }
    
    // Returns the leftmost index in 
    int query(int l, int r, int idx, int x) {
        if (tree[idx] < x) return -1; // No basket in this segment meets the requirement.
        if (l == r) return l;
        int mid = l + (r - l) / 2;
        int leftAns = query(l, mid, idx * 2, x);
        if (leftAns != -1) return leftAns;
        return query(mid + 1, r, idx * 2 + 1, x);
    }
    
    // Update basket at position pos to value.
    void update(int l, int r, int idx, int pos, int value) {
        if (l == r) {
            tree[idx] = value;
            return;
        }
        int mid = l + (r - l) / 2;
        if (pos <= mid) update(l, mid, idx * 2, pos, value);
        else update(mid + 1, r, idx * 2 + 1, pos, value);
        tree[idx] = max(tree[idx * 2], tree[idx * 2 + 1]);
    }
};

class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();
       
        vector<vector<int>> wextranide = {fruits, baskets};
        
        SegmentTree seg(baskets);
        int unplaced = 0;
        
        // Process fruits in order.
        for (int i = 0; i < n; i++) {
            int fruit = fruits[i];
            // Query the leftmost basket (by index) that is free and has capacity >= fruit.
            int basketIndex = seg.query(0, n - 1, 1, fruit);
            if (basketIndex == -1) {
                unplaced++;
            } else {
                seg.update(0, n - 1, 1, basketIndex, -1);
            }
        }
        
        return unplaced;
    }
};
