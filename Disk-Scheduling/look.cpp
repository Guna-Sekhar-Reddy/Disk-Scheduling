//disk scheduling using look 

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
	

	int mid,min,max;
	mid=(cyl[0]+cyl[c-1])/2;
	
	min=max=0;
	for(int i=0;i<n;i++)								//finding min and max in requests
	{
		if(p[min].cno>=p[i].cno)
		{
			min=i;
		}
		
		if(p[max].cno<=p[i].cno)
		{
			max=i;
		}
	}
	cout<<"min is "<<p[min].cno<<endl;
	cout<<"max is "<<p[max].cno<<endl;
	cout<<"mid is "<<mid<<endl;
	
	if(d<mid)											//if initial cylinder is less(left) than middle one
	{
	
		for(int i=d;i>=p[min].cno;i--)
		{
			for(int j=0;j<n;j++)
			{
				if(p[j].flag==0 and p[j].cno==cyl[i])
				{
					p[j].flag=1;
				}
			}
			sum++;
			if(i==p[min].cno)					//last one
			{
				cout<<"entered inner if"<<endl;
				int k=0;
				while(k<=p[max].cno)
				{
					for(int j=0;j<n;j++)
					{
						if(p[j].flag==0 and p[j].cno==cyl[k])
						{
							p[j].flag=1;
						}
					}
					sum++;
					cout<<"....in inner for sum is "<<sum<<" k value is "<<k<<endl;
					k++;
				}
			}
			cout<<"in if cond i value "<<i<<" sum "<<sum<<endl;
		}
			
	}
	
	else														//if initial cylinder in more(right) than middle one
	{
		for(int i=d;i<=p[max].cno;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(p[j].flag==0 and p[j].cno==cyl[i])
				{
					p[j].flag=1;
				}
			}
			sum++;
			
			if(i==p[max].cno)					//last one
			{
				for(int k=p[max].cno;k>=p[min].cno;k--)
				{
					for(int j=0;j<n;j++)
					{
						if(p[j].flag==0 and p[j].cno==cyl[k])
						{
							p[j].flag=1;
						}
					}
					sum++;
					cout<<"....in inner for sum is "<<sum<<" k value is "<<k<<endl;
				}
			}
			cout<<"in if cond i value "<<i<<" sum "<<sum<<endl;
		}
	}
	sum = sum -2;		//2 times sum incremented unnecessarly 
	cout<<"seek units are "<<sum<<endl;
	cout<<"total seek time is "<<sum*time<<endl;
}
