class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int,int>>arr;
        for(int i=0;i<nums1.size();i++)arr.push_back({nums2[i],nums1[i]});
        long long ans=0,sum=0;
        priority_queue<int>pq;
        sort(arr.rbegin(),arr.rend());
        for(int i=0;i<k-1;i++){
            sum+=arr[i].second;
            pq.push(-arr[i].second);
        }
        for(int i=k-1;i<nums1.size();i++){
            sum+=arr[i].second;
            pq.push(-arr[i].second);
            ans=max(ans,sum*arr[i].first);
            sum+=pq.top();
            pq.pop();
        }
        return ans;
    }
};
