#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i,n;
    double random[100];
    cout<<"Enter total number of random numbers = ";
    cin>>n;
    cout<<"Enter "<<n<<" numbers"<<endl;
    for(i=0;i<n;i++)
    {
        cout<<"Number "<<(i+1)<<" = ";
        cin>>random[i];
    }
    int up = 1;
    int run = 1;
    cout<<"Runs: "<<endl;
    for(i=1;i<n;i++)
    {
        if(up)
        {
            if(random[i] > random[i-1])
            {
                cout<<" + ";
            }
            else
            {
                up = 0;
                run++;
                cout<<" - ";
            }
        }
        else
        {
            if(random[i] < random[i-1])
            {
                cout<<" - ";
            }
            else
            {
                up = 1;
                run++;
                cout<<" + ";
            }
        }
    }
    puts("");
    double u = (2*n-1.0)/3.0;
    double sigma_square = (16*n-29.0)/90.0;
    double z = (run - u) / sqrt(sigma_square);

    cout<<"Total Run: "<<run<<endl;
    cout<<"Mean: "<<u<<endl;
    cout<<"Variance: "<<sigma_square<<endl;
    cout<<"Value of Z = "<<z<<endl;

    double critical_value, neg_critical_value;
    cout<<"Enter Critical Value: ";
    cin>>critical_value;
    neg_critical_value = -1 * critical_value;
    if(z >= neg_critical_value && critical_value >= z)
        cout<<"Null hypothesis for independence can be Accepted";
    else
        cout<<"Null hypothesis for independence can be Rejected";
    return 0;
}
