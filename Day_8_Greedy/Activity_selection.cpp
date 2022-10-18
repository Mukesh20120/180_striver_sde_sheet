//we have to sort it according to the position if ending time is equal


struct meet{
    int st,en,id;
};

class Solution
{
    static bool cmp(struct meet &a,struct meet &b){
       if(a.en==b.en)
         return a.id<b.id;
    return a.en<b.en;
    }
    public:
    //Function to find the maximum number of activities that can
    //be performed by a single person.
    int activitySelection(vector<int> start, vector<int> end, int n)
    {
        vector<meet>nums(n);
        for(int i=0;i<n;i++){
           nums[i].st=start[i];
           nums[i].en=end[i];
           nums[i].id=i;
        }
        sort(nums.begin(),nums.end(),cmp);
        
        // for(auto it: nums)
        //   cout<<it[0]<<" "<<it[1]<<endl;
        
        
        int ans=1;
        int en=nums[0].en;
        for(int i=1;i<n;i++){
            if(nums[i].st>en){
                ans++;
                en=nums[i].en;
            }
        }
        return ans;
    }
};