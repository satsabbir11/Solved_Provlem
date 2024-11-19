int lnds[MAX];
int LNDS(int n) {  
lnds[1]=arr[1]; //1 base index
int len = 1 ;
for(int i = 2; i<=n;i++)  { 
if(arr[i]>=lnds[len])
lnds [++ len] = arr [i];
else{
int j=upper_bound(lnds+1,lnds+len+ 1,arr[i])-lnds;
lnds [j] = arr [i];  }   }
return len; }