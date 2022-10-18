class Solution {
public:
    // static bool cmp(vector<int>&a,vector<int>&b){
    //     if(a[1]==b[1])
    //         return a[0]<b[0];
    //     return a[1]<b[1];
    // }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>ans;
        int n=intervals.size();
        //sort the intervals according to there ending time
        sort(intervals.begin(),intervals.end());
        
        int st=intervals[0][0];
        int en=intervals[0][1];
        //traverse through intervals
        for(int i=1;i<n;i++){
            if(intervals[i][0]<=en)
                en=max(en,intervals[i][1]);
            else{
                ans.push_back({st,en});
                st=intervals[i][0];
                en=intervals[i][1];
            }
        }
        ans.push_back({st,en});
        
        return ans;
    }
};