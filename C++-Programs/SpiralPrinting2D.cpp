#include<iostream>
using namespace std;
int main()
{
	int i,j,k,l;
	int n,m;
	cin>>n>>m;
	int arr[n][m];
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			cin>>arr[i][j];
		}
	}
	int rs=0,cs=0,re=n-1,ce=m-1;
	while(rs<=re&&cs<=ce)
	{
		for(int a=cs;a<=ce;a++)
		cout<<arr[rs][a]<<" ";
		rs++;
		for(int a=rs;a<=re;a++)
		cout<<arr[a][ce]<<" ";
		ce--;
		for(int a=ce;a>=cs;a--)
		cout<<arr[re][a]<<" ";
		re--;
		for(int a=re;a>=rs;a--)
		cout<<arr[a][cs]<<" ";
		cs++;
	}
}










