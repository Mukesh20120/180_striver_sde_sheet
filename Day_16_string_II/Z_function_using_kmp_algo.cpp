void build_lsp(vector<int>&lsp,string &p,int m){
    //the first index is always 0
    lsp[0]=0;//no need to do as we initilize if with 0 in previous function
    int len=0,i=1;
    while(i<m){
        //we have two case 
        if(p[i]==p[len]){
          len++;
            lsp[i]=len;
            i++;
        }
        else{
            //here we have again two case
            if(len!=0){
                len=lsp[len-1];
            }
            else{
                lsp[i]=0;//don't need to do as we initilized it in previous
                i++;
            }
        }
    }
}

int zAlgorithm(string s, string p, int n, int m)
{
    //make a lsp table from pattern
	vector<int>lsp(m,0);
    build_lsp(lsp,p,m);
    //now we need to traverse through the s and check pattern
    int i=0,j=0;
    int ans=0;
    while(n-i>=m-j){
        //here we check if character match
        if(s[i]==p[j]){
            i++;
            j++;
        }
        //check if j is at the end then we find the pattern
        if(j==m){
            ans++;
           j=lsp[j-1];
        }
        else if(i<n && s[i]!=p[j]){
            if(j!=0)
                j=lsp[j-1];
            else
                i++;
        }
    }
    return ans;
}