//brute force

class Solution {
public:
    int reversePairs(vector<int>& nums) {
        //brute force
        int n=nums.size();
        int ans=0;
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                if(nums[i]>2*nums[j])
                    ans++;
            }
        }
        return ans;
    }
};
//optimal solution same as inversion little bit modification

class Solution {
public:
    int merge(vector<int>&nums,int l,int mid,int h){
        //count the number of greater value
        int cnt=0;
        int j=mid+1,i;
        for(i=l;i<=mid;i++){
            while(j<=h && nums[i]>2LL*nums[j]){
                j++;
            }
            cnt+=j-(mid+1);
        }
        //now same all merge sort
        vector<int>temp;
         i=l;
        j=mid+1;
        while(i<=mid && j<=h){
            if(nums[i]<nums[j])
                temp.push_back(nums[i++]);
            else
                temp.push_back(nums[j++]);
        }
        //remain 
        while(i<=mid){
            temp.push_back(nums[i++]);
        }
        while(j<=h){
            temp.push_back(nums[j++]);
        }
        //copy back all the temp element in nums
        for(int a=l;a<=h;a++)
            nums[a]=temp[a-l];
        
        return cnt;
    }
    int mergesort(vector<int>&nums,int l,int h){
        int mid,cnt=0;
        if(l<h){
            mid=(l+h)>>1;
            cnt+=mergesort(nums,l,mid);
            cnt+=mergesort(nums,mid+1,h);
            cnt+=merge(nums,l,mid,h);
        }
        return cnt;
    }
    
    int reversePairs(vector<int>& nums) {
        //modification of inversion 
       return mergesort(nums,0,nums.size()-1);
    }
};