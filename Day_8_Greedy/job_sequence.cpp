//abdul bari greedy algorithm playlist job sequence question explaination

static bool cmp(Job &j1, Job &j2){
    return j1.profit>j2.profit;
}

class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
     vector<int>dead(101,-1);
      //sort accoding to profit
      sort(arr,arr+n,cmp);
      for(int i=0;i<n;i++){
          int j=arr[i].dead-1;
          while(j>=0 && dead[j]!=-1){
              j--;
          }
          if(j>=0)
           dead[j]=arr[i].profit;
      }
      int tj=0;
      int tp=0;
      for(int i=0;i<=100;i++){
          if(dead[i]!=-1){
              tj++;
              tp+=dead[i];
          }
      }
      return {tj,tp};
    } 
};