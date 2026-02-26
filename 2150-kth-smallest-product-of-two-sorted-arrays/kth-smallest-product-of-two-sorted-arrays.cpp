class Solution {
public:
    using ll = long long;

    ll findcountSmallest(vector<int>& nums1, vector<int>& nums2, ll midProd) {
        ll prodCount = 0;

        int n = nums2.size();

        for (int i = 0; i < nums1.size(); i++) {
            if (nums1[i] >= 0) {
                int l = 0;
                int r = n - 1;
                int m = -1;

                while (l <= r) {
                    int mid = l + (r - l) / 2;
                    ll prod = 1LL * nums1[i] * nums2[mid];
                    if (prod <= midProd) {
                        m = mid;
                        l = mid + 1;
                    } else {
                        r = mid - 1;
                    }
                }
                prodCount += m + 1;
            } else {
                int l = 0;
                int r = n - 1;
                int m = n;

                while (l <= r) {
                    int mid = l + (r - l) / 2;
                    ll prod = 1LL * nums1[i] * nums2[mid];
                    if (prod <= midProd) {
                        m = mid;
                        r = mid - 1;
                    } else {
                        l = mid + 1;
                    }
                }
                prodCount +=n-m;
            }
        }
        return prodCount;
    }
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2,
                                 long long k) {
        ll result = 0;

        ll l = -1e10;
        ll r = 1e10;

        while (l <= r) {
            ll midProd = l + (r - l) / 2;

            ll countSmallest = findcountSmallest(nums1, nums2, midProd);

            if (countSmallest >= k) {
                result = midProd;
                r = midProd - 1;
            } else {
                l = midProd + 1;
            }
        }
        return result;
    }
};