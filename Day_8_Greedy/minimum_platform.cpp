//don't think of overlap and non overlap there is also other approach
//sorting the array finding platform required as train arrived and train left

class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
    	// Your code here
    	sort(arr,arr+n);
    	sort(dep,dep+n);
    	
    	int ans=1,cur=1;
    	int i=1,j=0;
    	while(i<n && j<n){
    	    if(arr[i]<=dep[j]){
    	        cur++;
    	        i++;
    	    }
    	    else if(arr[i]>dep[j]){
    	        cur--;
    	        j++;
    	    }
    	    
    	    ans=max(cur,ans);
    	}
    	return ans;
    }
};
