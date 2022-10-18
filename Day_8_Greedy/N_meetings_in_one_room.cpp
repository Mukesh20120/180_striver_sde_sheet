//think is as a straigh line put all the value in straigt line
//two concept remember 
//if we want to find non overlap we sort according to ending time
//if we want to find overlpap then sort according to starting time



static bool cmp(vector<int>&a,vector<int>&b){
    if(a[1]==b[1])
      return a[2]<b[2];
      
    return a[1]<b[1];
}
class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
        //question boil donw to we have to find the non overlap
        vector<vector<int>>mtg(n,vector<int>(3));
        for(int i=0;i<n;i++){
         mtg[i][0]=start[i];
         mtg[i][1]=end[i];
         mtg[i][2]=i;
        }
        //sorting according to end time
        sort(mtg.begin(),mtg.end(),cmp);
       
        int ans=1;
        int en=mtg[0][1];
        for(int i=1;i<n;i++){
            if(mtg[i][0]>en){
                ans++;
                en=mtg[i][1];
            }
        }
        return ans;
    }
};