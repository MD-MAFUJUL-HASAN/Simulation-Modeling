#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, observed[20],i,N,Expected;
    float Calculation[20],final,critical;
    N=0;
    final=0.00;

    //getting observed frequency

    cout<<"How many classes :?"<<endl;
    cin>>n;
    cout<<"Enter the observed frequency:"<<endl;
    for(i=0; i<n; i++)
    {
        cout<<"Enter observed frequency of "<<i+1<<"th number: "<<endl;
        cin>>observed[i];
    }



    //calculation of N(total frequency), Calculation(((Oi-Ei)^2/Ei)),final(?)

    for(i=0; i<n; i++)
    {
        N=N+observed[i];
    }
    Expected=N/n;
    for(i=0; i<n; i++)
    {
        Calculation[i]=(float)((observed[i]-Expected)*(observed[i]-Expected))/Expected;
        final=final+Calculation[i];
    }


    //display in tabulated format

    cout<<setw(5)<<"S.No";
    cout<<setw(5)<<"Oi";
    cout<<setw(5)<<"Ei";
    cout<<setw(22)<<"((Oi-Ei)*(Oi-Ei))/Ei"<<endl;
    for(i=0; i<n; i++)
    {
        cout<<setw(5)<<i+1;
        cout<<setw(5)<<observed[i];
        cout<<setw(5)<<Expected;
        cout<<setw(10)<<setprecision(2)<<Calculation[i]<<endl;
    }
    cout<<"-------------------------------------------------------"<<endl;
    cout<<setw(10)<<N;
    cout<<setw(15)<<final;
    cout<<endl;


    //compare tabulated and calculated value and conclude if Ho is accepted.

    cout<<endl;
    cout<<"Enter the critical value:"<<endl;
    cin>>critical;
    if(final<critical)
    {
        cout<<"The test is accepted"<<endl;
    }
    else
    {
        cout<<"The test is rejected"<<endl;
    }
    return(0);
}
