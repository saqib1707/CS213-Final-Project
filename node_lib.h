#include <iostream>
#include <queue> 
using namespace std;

class Node{
public:
	char[3] NodeID;
	int num_wait;		            //no. of people waiting
	int slots[8];
	std::queue<int> wait_line;

	// Member functions
	void student_arrival(int s);       //s->no. of students wait_lineived
	int bus_arrival(Bus b);	          //b-> bus_id
	void update_slot_data(int a);
	int calc_weight(void);
	static int no_of_nodes;
   
};


int Node::bus_arrival(Bus b)
{ 
	if  (bus_max_capacity-bus_present_capacity)>5 getdown=rand()%5;					//using rand function to generate random numbers
	int vacant=b.current_capacity+getdown;
	for (std::queue<int>::iterator it = wait_line.begin(); it != wait_line.end(); ++it){
		if (*it<=vacant) {
			wait_line.pop(); 
			vacant=vacant-*it;
		}
	  	else {
	  		*it=*it-vacant; 
	  		vacant=0;
	  	}
	}
	return vacant;
}

void Node::student_arrival(int s){ 
	slots[i]=slot[i]+j;
	for ((std::queue<int>::iterator it = wait_line.end()-1)<5)
		wait_line.push_back(s);
  
	else{
		wait_line.pop();
		wait_line.push_back(s);
	}
}

void Node::update_slot_data(int i,int a){
	slot[i]=(slot[i]+a)/2;
}

int Node:: calc_weight(void){ 
	weight=0; i=0;
	for (std::queue<int>::iterator it = wait_line.begin(); it != wait_line.end(); ++it){
		weight=*it * i;
		i=i+2;
	}

	
	
