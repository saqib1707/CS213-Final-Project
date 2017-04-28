#include <iostream>
#include "bus_lib.h"
#include "node_lib.h"
using namespace std;


void feeding_nodes(Node node_array[], int lineNumber=2, int lineNumberSought=11) 
{
    string line, csvItem;
    ifstream myfile("time_table.csv");    // you may get it as argument

    if (myfile.is_open()) {
        while (getline(myfile,line)) 
        {
            lineNumber++;
            string word[20];
            int p=0;
            istringstream myline(line);
            while(getline(myline, csvItem, ','))
            {
               //csvItem stores the value of the cell  
               word[p]=csvItem;
               p++;
            }
            calculate_hash(string word);
        }
        myfile.close();
    }
    return 0;
}
    
void calculate_hash(Node node_array[], string word)   // word[0] = 'h12'
{
    //node bus_stop[30];
    int i=0, j=0;
    char a[word[0].size()+1];
    strcpy(a, word[0].c_str());
    int hash_key=a[j];
    int hash_code=0;
    while(a[j]!=' ')
    {
    	j++;
    	hash_key=hash_key+int(a[j]);
        if(j==2){    
            hash_code=hash_key%29;
        }
    }
    for(int k=1;k<=7;k++)
    {       
        int d=0;
        stringstream convert(word[k]);
        convert>>d;
        // realting to number of people at different nodes at different times
		node_array[hash_code].slots[k-1]=d;
    	// initializing the nodeID with a string of length 3 e.g, h12
    	node_array[hash_code].nodeID = word[k];
    }
}
    
void feeding_buses(Bus buses[]){

    string line;
    ifstream bus_file('bus_data.txt');
    if (bus_file.is_open()){
        int bus_count = 0;
        while(getline(bus_file, line)){
            int j=0;
            int b=0;
            do
            {
                if(j>=0 && j<=2)
                {
                    b += int(line[j])*10^(2-j);
                    if(j==2)    
                        buses[bus_count].busID=b;
                }
                b = 0;
                if(j>=4 && j<=5)        // assuming max_capacity is a two digit number                   
                {
                    b +=int(line[j])*10^(5-j);
                    if(j==5)
                        buses[bus_count].bus_max_capacity=int(line[j]);         
                }
                if(j>=7 && j<=9)    
                {
                    buses[bus_count].source_node[j-7]=line[j];
                }
            }while(a[++j]!=' ');
            bus_count++;
        }
    }
    else{
        cout<<"Unable to open file\n";
    }
}
// Since update_distance is not required right now.
/*    
    void update_distance(){
        cout<<"Update distances of adjacent stops"
        for(int i=0;i<11;i++){
            cin>>distance[i];
        }
    }
*/

template<class T>
class graph{
	vector<list<T> > vectorList;

public:
void createGraphNodes(int a, T*);
void addEdge(T, T);
void removeEdge(T, T);
void printOutgoing();
void printIncoming();

}; //End of class


template<class T>

void graph<T>::createGraphNodes(int a, T vertex[]){
	vectorList.resize(a);
	int arrayIndex = 0;

	for(typename vector<list<T> >::iterator vectorIterator = vectorList.begin();
		vectorIterator != vectorList.end();vectorIterator++, arrayIndex++){
		(*vectorIterator).push_back(vertex[arrayIndex]);
	}

} //End of function

template<class T>
void graph<T>::addEdge(T source, T destination){
	//Iterate through the ‘vectorList’ for adding an edge
	for(typename vector<list<T> >::iterator vectorIterator = vectorList.begin();
		vectorIterator != vectorList.end();vectorIterator++){
		typename list<T>::iterator listIterator = (*vectorIterator).begin();
		if ( (*listIterator) == source ) { //source node found
			(*vectorIterator).push_back(destination); //Edge added
		}
	} //End of for
} //End of function

// Assumptions- Number of nodes(bus stops) and buses are fixed
int main()
{
	int clk=0;

	Bus buses[10];
    Node node_array[10];
    int distance[11];

    int Bus::no_of_buses = 10;
    int Node::no_of_nodes = 14;
    
    feeding_buses(buses);     // buses objects are passed by reference

    feeding_nodes(node_array);    // for initialising all the nodes; node_array is passed
    								// by reference.

    Node vertex[] = node_array;   // array of node objects
    graph<Node> g;

    g.createGraphNodes(Node::no_of_nodes,vertex);

    g.addEdge(node_array[0], node_array[1]);
    g.addEdge(node_array[1], node_array[2]);
    g.addEdge(node_array[2], node_array[3]);
    g.addEdge(node_array[3], node_array[4]);
    g.addEdge(node_array[4], node_array[5]);
    g.addEdge(node_array[2], node_array[9]);
    g.addEdge(node_array[9], node_array[8]);
    g.addEdge(node_array[8], node_array[7]);
    g.addEdge(node_array[7], node_array[15]);
    g.addEdge(node_array[7], node_array[10]);
    g.addEdge(node_array[6], node_array[10]);
    g.addEdge(node_array[10], node_array[4]);

    // route defined
    string route[3][];
    route[0][]=['h12', 'h07', 'h05', 'h11', 'som', 'kre'];
    route[1][]=['h12', 'h07', 'h05', 'h04', 'h03', 'h01', 'lib', 'som', 'kre'];
    route[2][]=['h15', 'lib', 'som', 'kre'];
    

    while(true){	
	   	//clk=0;     clock is already defined zero
    	if(clk%2 == 0){
			for(int i=0; i<Node::no_of_nodes; i++){
    			node_array[i].student_arrival();     // function called for updation of student 
    												// at all the nodes.
    		}
    		// calculate route weights
<<<<<<< HEAD
			if (clk==0){
				int route_wt[3]={0,0,0};
				int route_wait_student[3]={0,0,0};
		    	for (int i=0;i<3;i++){
					for(int j=0; j<sizeof(route[i]); j++){
						for(int k=0;k<sizeof(node_array);k++){
							if (strcmp(route[i][j],node_array[k].nodeID) == 0){
								route_wt[i] += node_array[k].calc_weight();
								route_wait_student[i] += node_array[k].num_wait;
		    				}
		    			}
					}	
				}
			}
		//Saqib code here   //note capacity =b1.cap+b2.cap+b3.cap
		clk++;
=======

	if (clk==0){	int route_wt[3]={0,0,0};
		int route_wait_student[3]={0,0,0};
    		for (int i=0;i<3;i++){
			
    			for(int j=0; j<sizeof(route[i]); j++)
			{
				for(int k=0;k<sizeof(node_arr);k++
				    {
			if strcmp(route[i][j],node_arr[k])==0
			{route_wt[i]+=route[i][j].wieght; route_wait_student[i]+=route[i][j].num_wait;
    			}
    		}
			}	
		}
		    
		    //Saqib code here   //note capacity =b1.cap+b2.cap+b3.cap
		void merge(int route_wt[], int l=0, int m, int r=sizeof(route_wt)-1
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
 
    /* create temp route_wtays */
    int L[n1], R[n2];
 
    /* Copy data to temp route_wtays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = route_wt[l + i];
    for (j = 0; j < n2; j++)
        R[j] = route_wt[m + 1+ j];
 
    /* Merge the temp route_wtays back into route_wt[l..r]*/
    i = 0; // Initial index of first subroute_wtay
    j = 0; // Initial index of second subroute_wtay
    k = l; // Initial index of merged subroute_wtay
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            route_wt[k] = L[i];
            i++;
        }
        else
        {
            route_wt[k] = R[j];
            j++;
        }
        k++;
    }
 
    /* Copy the remaining elements of L[], if there
       are any */
    while (i < n1)
    {
        route_wt[k] = L[i];
        i++;
        k++;
    }
 
    /* Copy the remaining elements of R[], if there
       are any */
    while (j < n2)
    {
        route_wt[k] = R[j];
        j++;
        k++;
    }
}
 
/* l is for left index and r is right index of the
   sub-route_wtay of route_wt to be sorted */
void mergeSort(int route_wt[], int l, int r)
{
    if (l < r)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l+(r-l)/2;
 
        // Sort first and second halves
        mergeSort(route_wt, l, m);
        mergeSort(route_wt, m+1, r);
 
        merge(route_wt, l, m, r);
    }
}



		
		
			
	clk++;

>>>>>>> 69d6ff69a37b265fcf29ace16a2e732c3040f9ba
    	}
    }
    return 1;
}