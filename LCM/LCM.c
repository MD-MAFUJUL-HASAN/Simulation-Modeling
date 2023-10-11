#include<stdio.h>
int nextRandom(int x,int a,int c,int m)
{
    int xi;
    xi = (a*x+c)%m;
    return xi;
}
int main()
{
    int i,n,a,x,c,m;
    printf("Enter the value of seed X :");
    scanf("%d",&x);
    printf("Enter the value of seed a :");
    scanf("%d",&a);
    printf("Enter the value of seed c :");
    scanf("%d",&c);
    printf("Enter the value of seed m :");
    scanf("%d",&m);
    printf("Enter the value of seed N :");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        x = nextRandom(x,a,c,m);
        double r = (double) x / (double) m;
        printf("Next Random = %f\n",r);
    }
    return 0;
}
