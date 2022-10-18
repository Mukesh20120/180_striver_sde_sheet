//brute force approach 1 using extra space

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int>extra(m+n);
        int i=0,j=0,k=0;
        while(i<m && j<n){
            if(nums1[i]<nums2[j])
                extra[k++]=nums1[i++];
            else 
                extra[k++]=nums2[j++];
        }
        for(;i<m;i++)
            extra[k++]=nums1[i];
        for(;j<n;j++)
            extra[k++]=nums2[j];
        
        for(int i=0;i<m+n;i++)
            nums1[i]=extra[i];
    }
};

//optimal solution
//we will start checking from the last and place in first array
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=m-1;
        int j=n-1;
        int k=m+n-1;
        while(i>=0 && j>=0){
            if(nums1[i]>nums2[j])
                nums1[k--]=nums1[i--];
            else
                nums1[k--]=nums2[j--];
        }
        
        while(j>=0)
            nums1[k--]=nums2[j--];
    }
};