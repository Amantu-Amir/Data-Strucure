class Solution {
public:
    void max_heapify(int n, vector<int>& v, int root) {
        int idx = root, L = root * 2, R = root * 2 + 1;
        if (L < n and v[idx] < v[L]) idx = L;
        if (R < n and v[idx] < v[R]) idx = R;
        if (idx != root) {
            int temp = v[idx];
            v[idx] = v[root];
            v[root] = temp;
            max_heapify(n, v, idx);
        }
    }
    void heap_sort(vector<int>& v) {
        int n = v.size();
        for (int i = n / 2; i >= 0; i--) {
            max_heapify(n, v, i);
        }
        for (int i = n - 1; i > 0; i--) {
            int temp = v[i];
            v[i] = v[0];
            v[0] = temp;
            max_heapify(--n, v, 0);
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        heap_sort(nums);
        return nums;
    }
};

