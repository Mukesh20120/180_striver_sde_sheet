//other brute force solution using two loop calculate individual
//better approach use hash map
//optimal approach using voting algorithm
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int prev=0,cnt=0;
        for(int &it: nums){
            if(cnt==0){
                prev=it;
                cnt=1;
            }
            else if(prev==it)
                cnt++;
            else
                cnt--;
        }
        return prev;
    }
};