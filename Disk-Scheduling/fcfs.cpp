//disk scheduling using fcfs

#include<iostream>

using namespace std;

int main()
{
	int n,c,d,sum=0;		//n->n0; of requests, c-> no; of cylinders; d->first disk; sum-> seek units;
	float time;
	
	cout<<"enter time(ms) for each unit of move from cylinder to adjacent cylinder"<<endl;
	cin>>time;
	cout<<"Enter the number of cylinders"<<endl;
	cin>>c;
	
	cout<<"enter the number of process requests"<<endl;
	cin>>n;
	
	cout<<"enter the current disk position"<<endl;
	cin>>d;
	
	int cyl[c];
	
	for(int i=0;i<c;i++)		//entering cylinder numbers 
	{
		cyl[i]=i;
	}
	
	int pro[n];
	
	cout<<"enter the process cylinder numbers"<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>pro[i];
	}
	
	for(int i=0;i<n;i++)
	{
		
		if(cyl[d]==pro[i])
		{
			sum=sum;
		}
		
		if(cyl[d]>pro[i])
		{
			for(int j=d; j>0; j--)
			{	
				if(cyl[j]==pro[i])
				{
					break;
				}
				d--;
				sum++;
			}
		}
		
		else if(cyl[d] < pro[i])
		{
			for(int j=d;j<c;j++)
			{	
				if(cyl[j]==pro[i])
				{
					break;
				}
				d++;
				sum++;
			}
		}
		
//		cout<<"d values is "<<d<<endl;
//		cout<<"sum values is "<<sum<<endl;
	}
	
	cout<<"total seek time is "<<sum*time<<endl;
}
