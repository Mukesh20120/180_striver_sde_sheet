#include <bits/stdc++.h> 
#define ll long long

ll merge(ll *arr,ll *temp,int l,int mid,int h){
    int i=l,j=mid,k=l;
    ll inv=0;
    //i go up to mid-1 and from mid to h other list
    while(i<=mid-1 && j<=h){
        if(arr[i]<=arr[j])
             temp[k++]=arr[i++];
        else{
            temp[k++]=arr[j++];
            inv+=mid-i;
        }
    }
    //remain list add in temp
    while(i<=mid-1){
        temp[k++]=arr[i++];
    }
    while(j<=h){
        temp[k++]=arr[j++];
    }
    //copy back sorted list in array
    for(int a=l;a<=h;a++)
        arr[a]=temp[a];
    
    return inv;
}

ll mergesort(ll *arr,ll *temp,int l,int h){
    ll mid,inv=0;
    if(l<h){
        mid=(h+l)>>1;
        //calling recursively
       inv+=mergesort(arr,temp,l,mid);
       inv+=mergesort(arr,temp,mid+1,h);
        //merge the list
        inv+=merge(arr,temp,l,mid+1,h);
    }
    return inv;
}

long long getInversions(long long *arr, int n){
    // Write your code here.
    
    //make a new array for store the sorted list 
    //declare dynamice arry
    ll *temp=new ll[n];
    
    //call mergesort
    //array,temp,start,end
    return mergesort(arr,temp,0,n-1);
}