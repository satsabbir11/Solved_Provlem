Others:
Decider for a point located left or right of a line:
d=(x3-x2)*(y2-y1)-(y3-y2)*(x2-x1)
Number of digits: log10(n)+1
Depth of road water: (s^2-h^2)/2h

//sum of series n/1+n/2+n/3+....n/n
ll root=sqrt(n);
for(int i=1; i<=root; i++)
sum+=n/i;
sum=(2*sum)-(root*root);


count the numbers that are
divisible by given number in a
certain range:a=2,b=3,c=7;
low=(a+b-1)/a;
high=c/a;
total=high-low+1;

Euler Constant:γ≈0.5772156649 

#Number of squares in a n*n grid:
S=(n*(n+ 1)*(2*n + 1))/6;

#Number of rectangle in a n*n grid:
R=(n+1)*n/2*(n+1)*n/2 - S;

#Total number of rectangle and square in a n*n grid:
ans=[(n^2 + n)^2]/4

#Number of squares in a n*m grid
exp:6*4
S=6*4+5*3+4*2+3*1=50

#Number of rectangles in n*m grid
R=m(m+1)n(n+1)/4

#Number of cubes in a n*n*n grid
formula:n^k-(n-2)^k
C=n*(n+1)/2*n*(n+1)/2;

#Number of boxes in a n*n*n grid:
B=(n+1)*n/2*(n+1)*n/2*(n+1)*n/2-C;

#Number of hypercube in a n^4grid:
start a loop from 1 to <=n;
HC=0;
for(i=1;i<=n;i++)
HC+=i*i*i*i;

#Number of hyper box in a n^4 grid:
HB=(n+1)*n/2*(n+1)*n/2*(n+1)*n/2*(n+1)*n/2 - HC; 
