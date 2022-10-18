class Solution{
public:
    vector<int> minPartition(int N)
    {
       int arr[]={1,2,5,10,20,50,100,200,500,2000};
       int n=sizeof(arr)/sizeof(int);
       vector<int>ans;
       while(N){
           int i=0;
           while(i<n && N>=arr[i]){
               i++;
           }
           i--;
           int cnt=N/arr[i];
           N-=cnt*arr[i];
           while(cnt--){
               ans.push_back(arr[i]);
           }
       }
       return ans;
    }
};