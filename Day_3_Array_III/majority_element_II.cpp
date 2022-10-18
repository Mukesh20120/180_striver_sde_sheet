//using unordered map

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans;
        unordered_map<int,int>m;
        for(int i=0;i<n;i++)
            m[nums[i]]++;
        
        for(auto it: m){
            if(it.second>n/3)
                ans.push_back(it.first);
        }
        return ans;
    }
};


//using voting algorithm use in majority find one element

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int>ans;
        //same as majority element as it is given n/3 then only 
        //two number is possible 
        int cnt1=0,cnt2=0,num1=-1,num2=-1;
        for(int &it: nums){
            if(num1==it)
                cnt1++;
            else if(num2==it)
                cnt2++;
            else if(cnt1==0){
                num1=it;
                cnt1++;
            }
            else if(cnt2==0){
                num2=it;
                cnt2++;
            }
            else{
                cnt1--;
                cnt2--;
            }
        }
        //we get two number as majority now check there count
        cnt1=cnt2=0;
        for(int &it: nums){
            if(num1==it)
                cnt1++;
            else if(num2==it)
                cnt2++;
        }
        //check the majority
        if(cnt1>nums.size()/3)
            ans.push_back(num1);
        if(cnt2>nums.size()/3)
            ans.push_back(num2);
        
     return ans;
    }
};