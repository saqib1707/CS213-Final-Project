#include <iostream>
#include <queue> 
#include <deque>
using namespace std;

class Node{
public:
	char[3] nodeID;
	int num_wait;		            //no. of people waiting
	int slots[9];
	std::deque<int> wait_line;
	static int no_of_nodes;

	// Member functions
	void student_arrival(int s);       //s->no. of students wait_lineived
	int bus_arrival(Bus b);	          //b-> bus_id
	void update_slot_data(int a);
	int calc_weight(void);
 
    //to define static members - routes
};


int node::bus_arrival(Bus b)
{ 
	int vacant=b.current_capacity+b.get down;
	for (std::deque<int>::iterator it = wait_line.begin(); it != wait_line.end(); ++it){
		if (*it<=vacant) {
			wait_line.pop(); 
			vacant=vacant-*it;
		}
	  	else {
	  		*it=*it->vacant; 
	  		vacant=0;
	  	}
	}
	return vacant;
}

void node::student_arrival(int s){ 
	slots[i]=slot[i]+j;
	for ((std::deque<int>::iterator it = wait_line.end()-1)<5)
		wait_line.push_back(s);
  
	else{
		wait_line.pop();
		wait_line.push_back(s);
	}
}

void node::update_slot_data(int a){
	slot[i]=(slot[i]+a)/2;
}

int node:: calc_weight(void){ 
	weight=0; i=0;
	for (std::deque<int>::iterator it = wait_line.begin(); it != wait_line.end(); ++it){
		weight=*it * i;
		i=i+2;
	}
}
