static bool cmp(Item &a,Item &b){
    return (double)a.value/(double)a.weight>(double)b.value/(double)b.weight;
}

class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        //we will will store in other array and take value/weigh profit
        sort(arr,arr+n,cmp);
        // for(auto it: nums)
        //   cout<<it[0]<<" "<<it[1]<<" "<<it[2]<<endl;
        int weight=W,i=0;
        double pro=0;
          while(weight && i<n){
              if(weight>=arr[i].weight){
                  weight-=arr[i].weight;
                  pro+=arr[i].value;
              }
              else{
                pro+=weight*(double)arr[i].value/(double)arr[i].weight;
                weight=0;
              }
              i++;
          }
          return pro;
    }
        
};
