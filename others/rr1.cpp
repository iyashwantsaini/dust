#include<iomanip>
#include<iostream>
#include<conio.h>
#include<list>
using namespace std;
class roundrobin//class representing round robin scheduling
{
	int *rq;//request times
	int	n;//number of processes
	int	q;//time quantum
	int	*w;//wait times
	int	*t;//turn-around times
	int *a;//arrival times
	list<int> order;
public:
	roundrobin(void);
	~roundrobin(void);
	int read();//read input from the user
	void calc();//to calculate turn-around and wait times of all processes and the ordering
	void display();
};
roundrobin::roundrobin(void)
{
	rq=w=t=NULL;
}

roundrobin::~roundrobin(void)
{
	if(rq!=NULL)
	{
		delete[] rq;
		delete[] w;
		delete[] t;
		delete[] a;
	}
}
int roundrobin::read()//read input from the user
{
	int i;
	cin>>n;
	if(rq!=NULL)
	{
		delete[] rq;
		delete[] w;
		delete[] t;
	}
	try
	{
		rq=new int[n];
		w=new int[n];
		t=new int[n];
		a=new int[n];
	}
	catch(bad_alloc &ba)
	{
		cerr<<ba.what()<<endl;
		exit(1);
	}
	int x;
	for(i=0;i<n;i++)
	{	
		cin>>x;
		cin>>a[i];
		cin>>rq[i];
		w[i]=t[i]=0;
	}
	q=1;
	return 1;
}
void roundrobin::calc()//to calculate turn-around and wait times of all processes and the ordering
{
	int j=0;
	int	time;
	int k;
	int i;
	int *r;//remaining times
	try
	{
		r=new int[n];
	}
	catch(bad_alloc &ba)
	{
		cerr<<ba.what()<<endl;
		exit(1);
	}
	for(i=0;i<n;i++)	r[i]=rq[i];
	bool f=false;//flag to indicate whether any process was scheduled as i changed from 0 to n-1 in the next for loop
	int sp=0;//time spent
	for(i=0;j<n;i=(i+1)%n)//while there are uncompleted processes
	{
		if(r[i]>0&&sp>=a[i])//find the next uncompleted process which has already or just arrived
		{
			f=true;
			if(r[i]<=q)//if the process requests for time less than the quantum
				time=r[i];//time to be alloted in this turn is the complete requested time
			else	time=q;//else, it is the quantum time
			//schedule the process
			t[i]+=time,r[i]-=time,order.push_back(i+1);
			if(r[i]==0)	j++;//if the process has got completed, increment j
			for(k=0;k<n;k++)
				if(r[k]!=0&&k!=i&&a[k]<sp+time)//for all other arrived processes incompleted after scheduling this process
					if(!(a[k]<=sp))//if they arrived while scheduling this process
						w[k]+=sp+time-a[k],t[i]+=sp+time-a[k];//account for the time they spent waiting while the process was being scheduled
					else
						w[k]+=time,t[k]+=time;//add time to their wait times and turn-around times
			sp+=time;
			continue;
		}
		if(i==n-1)
		{
			if(!f)
			//now there are no more arrived processes to be scheduled
			//so change sp to the arrival time of next arriving process
			{
				int it;
				int diff=0;//diff between present time spent and arrivaltime of next arriving process
				for(it=0;it<n;it++)
					if(sp<a[it])//if process has'nt yet arrived
					{
						if(diff==0)	diff=a[it]-sp;
						else if(diff>a[it]-sp)	diff=a[it]-sp;
					}
				sp+=diff;
			}
			f=false;
		}
	}
	delete[] r;
}
void roundrobin::display()
{
	int i;
	float tav=0;//average turn-around time
	float wav=0;//average wait time			
	for(i=0;i<n;i++)
		tav+=t[i],wav+=w[i];
	tav/=n,wav/=n;
	list<int>::iterator oi;		
	for(oi=order.begin();oi!=order.end();oi++)
		cout<<*oi<<" ";
}

int main()
{
	roundrobin r;
	r.read();
	r.calc();
	r.display();
	_getch();
}