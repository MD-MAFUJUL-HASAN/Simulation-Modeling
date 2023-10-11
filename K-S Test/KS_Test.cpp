#include<bits/stdc++.h>

using namespace std;

int main()
{
    float numbers[20];
    float ratio[20],ratiominus[20];
    float Dplus[20],Dminus[20];
    float DplusMax,DminusMax;
    float D,Dalpha;
    int i,j,n;

    cout<<"How Many Numbers for Test = ";
    cin>>n;
    cout<<"Enter "<<n<<" Numbers"<<endl;
    for(i=0;i<n;i++)
    {
        cout<<"Enter "<<(i+1)<<" numbers = ";
        cin>>numbers[i];
    }

    //sort the numbers in ascending order
    sort(numbers, numbers+n);

    for(i=0;i<n;i++)
    {
        j = i+1;
        ratio[i] = (float) j/n;
        ratiominus[i] = (float) i/n;
        Dplus[i] = ratio[i] - numbers[i];
        Dminus[i] = numbers[i] - ratiominus[i];
    }
    cout<<endl<<endl;

    //print headers
    cout<<setw(10)<<"i";
    for(i=1;i<=n;i++)
    {
        cout<<setw(10)<<i;
    }
    cout<<endl;
    cout<<setw(10)<<"R(i)";
    for(i=0;i<n;i++)
    {
        cout<<setw(10)<<numbers[i];
    }
    cout<<endl;
    cout<<setw(10)<<"i-/n";
    for(i=0;i<n;i++)
    {
        cout<<setw(10)<<setprecision(2)<<ratio[i];
    }
    cout<<endl;
    cout<<setw(10)<<"D+";
    for(i=0;i<n;i++)
    {
        cout<<setw(10)<<setprecision(2)<<Dplus[i];
    }
    cout<<endl;
    cout<<setw(10)<<"D-";
    for(i=0;i<n;i++)
    {
        cout<<setw(10)<<setprecision(2)<<Dminus[i];
    }
    cout<<endl;

    DplusMax = Dplus[0];
    DminusMax = Dminus[0];

    for(i=1;i<n;i++)
    {
        if(Dplus[i] > DplusMax)
        {
            DplusMax = Dplus[i];
        }
        if(Dminus[i] > DminusMax)
        {
            DminusMax = Dminus[i];
        }
    }

    cout<<"D+ max = "<<DplusMax<<endl;
    cout<<"D- max = "<<DminusMax<<endl;
    D = max(DplusMax,DminusMax);
    cout<<"D = max(" <<DplusMax<<", "<<DminusMax<<") = "<<D<<endl;

    cout<<"Enter the tabulated value (D Alpha) = ";
    cin>>Dalpha;

    if(D<Dalpha)
        cout<<"The test is accepted."<<endl;
    else
        cout<<"The test is rejected."<<endl;

    return 0;
}
