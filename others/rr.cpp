#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>

// 6
// 1 0 4
// 2 1 5
// 3 2 2
// 4 3 1
// 5 4 6
// 6 6 3

using namespace std;

class Process{
	public:
		int process_id;
		int arrival_time;
		int burst_time;
		int remaining_time;
		int completion_time = 0;
		int turn_around_time = -1;
		int waiting_time = -1;
		
		Process(int p_id, int a_time, int b_time){
			this->process_id = p_id;
			this->arrival_time = a_time;
			this->burst_time = b_time;
			this->remaining_time = this->burst_time;
		}
		
		bool operator!=(Process& p){
			if (this->process_id == p.process_id) return false;
			return true;
		}
};

int main(){

   int n;
   cin>>n;
   int process_id[n]={0};
	int arrival_time[n]={0};
	int burst_time[n]={0};
   for(int i=0;i<n;i++){
      cin>>process_id[i];
      cin>>arrival_time[i];
      cin>>burst_time[i];
   }
   int tq=1;

	vector<Process> process_list;
	
	queue<Process*> ready_queue;
	vector<Process> gantt;


	Process idle(-1,0,0);


	for(int i=0; i<n; i++)
		process_list.push_back(Process(process_id[i], arrival_time[i], burst_time[i]));

// Bubble sort on arrival_time:
	for(int i=0; i<n; i++)
		for (int j=1; j<n-i; j++)
			if (process_list.at(j).arrival_time < process_list.at(j-1).arrival_time){
				Process temp = process_list.at(j);
				process_list.at(j) = process_list.at(j-1);
				process_list.at(j-1)= temp;
			}
			
	if(process_list.at(0).arrival_time > 0)
		idle.completion_time = process_list.at(0).arrival_time;	
	
	
	gantt.push_back(idle);
	
	ready_queue.push(&process_list.at(0));
	
	while( !ready_queue.empty() ){
		Process* current = ready_queue.front();
		ready_queue.pop();
		

		if(current->remaining_time <= tq){
			current->completion_time = gantt.back().completion_time + current->remaining_time;
			current->remaining_time = 0;
		}
		else{
			current->completion_time = gantt.back().completion_time + tq;
			current->remaining_time = current->remaining_time - tq;
		}
		
		
		for(Process& p: process_list){
			if(p.arrival_time > gantt.back().completion_time && p.arrival_time <= current->completion_time ){
				ready_queue.push(&p);
			}
		}
		
		if(current->remaining_time != 0)
			ready_queue.push(current);
		
		gantt.push_back(*current);

		if (ready_queue.empty() )
			for (Process& p: process_list)
				if(p.remaining_time != 0 ){
					idle.arrival_time = gantt.back().completion_time;
					idle.completion_time = p.arrival_time;
					gantt.push_back(idle);
					ready_queue.push(&p);
					break;
				}
		
	}

	for (Process& p: gantt)
		if (p.process_id == -1){
			if (p.completion_time != 0)
				printf("");
		}
		else{
			printf("%d ", p.process_id);
      }
		
	return 0;
}