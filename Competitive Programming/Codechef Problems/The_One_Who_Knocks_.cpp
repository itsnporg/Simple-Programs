#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int x,y;
	    cin>>x>>y;
	    if(x==y)
	    {
	        cout<<"0"<<endl;
	    }
	    else if(y>x)
	    {
	        int d=y-x;
	        if(d%2!=0)
	        {
	            cout<<"1"<<endl;
	        }
	        else{
	            d/=2;
	            if(d%2!=0)
	            {
	                cout<<"2"<<endl;
	            } else {
	                cout<<"3"<<endl;
	            }
	        }
	    }
	    else {
	        int d=x-y;
	        if(d%2==0)
	        {
	            cout<<"1"<<endl;
	        }
	        else{
	            cout<<"2"<<endl;
	        }
	    }
	}
	return 0;
}