void make_pi(int *arr,string p,int n);
bool findPattern(string p, string s)
{
    //make a pie table of 
    int n=p.length(); //pattern
    int m=s.length(); //string
    
    //make a pie table of pattern
    int *pi=new int[n];
    make_pi(pi,p,n);
    //now we have to check with the given string
    int i=0,j=0;
    while((m-i)>=(n-j)){
        //check character match
        if(s[i]==p[j]){
            i++;
            j++;
        }
        //check if we are at the end of the pattern
        if(j==n){
            return true;
        }
        else if(i<m && s[i]!=p[j]){
            //now here we have again two case
            if(j!=0)
                j=pi[j-1];
            else
                i++;
        }
    }
    return false;
}
void make_pi(int *arr,string p,int n){
    //first element always 0
    arr[0]=0;
    int i=1,len=0;
    while(i<n){
        //we have two case character match with previous 
        if(p[i]==p[len]){
            len++;
            arr[i]=len;
            i++;
        }
        else{
            //here we have two case 
            if(len!=0){
                //move to previous value
                len=arr[len-1];
            }
            else{
                //length is 0 store in array and move pointer
                arr[i]=0;
                i++;
            }
        }
    }
}