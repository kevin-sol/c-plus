#include<iostream>
#include<math.h>
using namespace std;

int main(int argc, char const *argv[])
{
	double n,d=0,sum=0;
	cin>>n;
	double *a=new double[1000];
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
	}
	for (int i = 0; i < n; ++i)
	{
		sum+=a[i];
	}
	double adverage=sum/n;
	for (int i = 0; i < n; ++i)
	{
		d+=(a[i]-adverage)*(a[i]-adverage);
	}
	d=d/n;
	double *fa=new double[1000];
	for (int i = 0; i < n; ++i)
	{
		fa[i]=(a[i]-adverage)/pow(d,0.5);
	}
	for (int i = 0; i < n; ++i)
	{
		printf("%f\n",fa[i]);
	}
	//system("pause");
	return 0;
}