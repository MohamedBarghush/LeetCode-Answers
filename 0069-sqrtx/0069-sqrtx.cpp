class Solution {
public:
    int binary_search (int min, int max, int target) {
        int mid = min + (max - min) / 2;
         if (mid <= target / mid && (mid + 1) > target / (mid + 1)) {
            return mid;
        } else if (mid > target / mid) {
            return binary_search(min, mid - 1, target);
        } else {
            return binary_search(mid + 1, max, target);
        }
    }
    int mySqrt(int x) {
        if (x < 2) return x; // base case
        return binary_search(0, x, x);
    }
};