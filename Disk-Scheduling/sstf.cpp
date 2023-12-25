//shortet seek time first disk scheduling

#include<iostream>

using namespace std;

struct process
{
	int cno;					//	cylindr  needed by process
	int flag;
};

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
	
	struct process p[n];
	
	cout<<"enter the process cylinder numbers"<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>p[i].cno;
		p[i].flag=0;		//flag=0-> process not completed; flag=1-> process completed
	}
	
	int dif[n];
	int min;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(d==p[j].cno)
			{
				dif[j]=0;
			}
			
			else if(d > p[j].cno)
			{
				dif[j]=d-p[j].cno;
			}
			
			else if(d < p[j].cno)
			{
				dif[j]=p[j].cno-d;
			}
			
			//cout<<"difference of "<<j<<" is "<<dif[j]<<endl;
		}
		
		for(int j=0;j<n;j++)
		{
			if(p[j].flag==0)
			{
				min=j;
				break;
			}
		}
		for(int j=0;j<n;j++)
		{
			if(p[j].flag==0)
			{
				if(dif[min]>=dif[j])
				{
					min=j;
				}
			}
		}
		
		p[min].flag=1;
		sum=sum+dif[min];
		d=p[min].cno;
		//cout<<"min is "<<min<<endl;
		//cout<<"sum is "<<sum<<endl;
	}
	
	cout<<"seek units are "<<sum<<endl;
	cout<<"total seek time is "<<sum*time<<endl;
	
}
