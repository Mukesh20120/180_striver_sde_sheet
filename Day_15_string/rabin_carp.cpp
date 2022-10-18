//kmp algorithm
void build_lsp(int *arr,int m,string &pat){
    //make first element 0
    arr[0]=0;
    int i=1,len=0;
    while(i<m){
        if(pat[i]==pat[len]){
            len++;
            arr[i]=len;
            i++;
        }
        else{
            if(len!=0){
                len=arr[len-1];
            }
            else{
                arr[i]=0;
                i++;
            }
        }
    }
}
vector<int> stringMatch(string &str, string &pat) {
    //we can do same with kmp algorithm
    //make lsp table of pat
    int m=pat.length();
    int n=str.length();
    int *arr=new int[m];
    build_lsp(arr,m,pat);
    //we make array 
    vector<int>ans;
    int i=0,j=0;
    while((n-i)>=(m-j)){
        if(str[i]==pat[j]){
            i++;
            j++;
        }
        if(j==m){
            ans.push_back(i-j);
            j=arr[j-1];
        }
        else if(i<n && str[i]!=pat[j]){
            if(j!=0){
                j=arr[j-1];
            }
            else{
                i++;
            }
        }
    }
    return ans;
}
