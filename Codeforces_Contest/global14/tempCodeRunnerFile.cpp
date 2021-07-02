   for(i=1;i<=n;i++)
       {
           bz=left[i]/2;
           ans+=bz;
           l-=(bz*2);
           left[i]%=2;
          
           bz=right[i]/2;
           ans+=bz;
           r-=(bz*2);
           right[i]%=2;
       }