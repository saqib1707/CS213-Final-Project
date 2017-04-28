#include <iostream>
#include <cstring>
#include <string>
using namespace std;
#ifndef test

class Bus{
public:
	int busID[3];    // number-plate
	int bus_max_capacity;
	int bus_present_capacity;
	char source_node[3];
	char destination_node[3] = "000";
	int avg_velocity = 30;            // in km/hr
	bool active;
	char node_last_visited[3];
	float bus_stop_time;          // will depend on the number of people at that particular bus-stop
	string route[10];         // an array of a sequence of nodes
	static int no_of_buses;

	// member functions declared
	// when the bus reaches a particular stop it should update the bus_capacity, bus_last_node and 
	// will wait for unit_stop_time*no_of_people_at_that_stop

	void update_bus_parameters(char stop_node[]){   // when to update bus parameters will be called 
													// by the bus_arrival function in node class
		node_last_visited = stop_node;
	}

	// this function will return the next node ID of the bus
	void get_next_node(node_last_visited, route){
		for(int i=0;i<length(route);i++){          // how to get the length of a string object
			if(strcmp(route[i], node_last_visited)){
				return route[i+1];
			}
		}
	}

	int get_distance(last_node, route){
		next_node = get_next_node(last_node, route);
		if(strcmp(last_node, "H12") && strcmp(next_node, "H07")){
			return distance[0];   // problem here since we don't have access to the distance array here
		}
	}
	/*
	void move_bus(){
		//time_to_next_node = (get_distance(node_last_visited, route)/avg_velocity)*scale;
		time_to_next_node = 2;  // in mins
		stop_time = 0.5;
		//sleep(time_to_next_node);  // can't use sleep here since other functionalities are going on
	}
	*/
};

#endif