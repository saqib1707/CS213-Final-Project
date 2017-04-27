#include <iostream>
#include <bus_lib.h>
using namespace std;

struct Interface{
    Bus buses[10];
    Node node_array[10];
    int distance[11];

void feeding_nodesO(int lineNumber, int lineNumberSought) 
{
    string line, csvItem;
    ifstream myfile ("time_table.csv");
      // you may get it as argument
    if (myfile.is_open()) 
    {
        while (getline(myfile,line)) 
        {
                lineNumber++;
            //if(lineNumber == lineNumberSought) {
             //   cout << line << endl; ;
                string word[20]; 
                int p=0;
                istringstream myline(line);
                while(getline(myline, csvItem, ','))
                {
                //csvItem stores the value of the cell  
               word[p]=csvItem;
               p++;
                           //    }
                }
                feeding_nodes(string word);

        }
        myfile.close();
    }
    return 0;
}
    
void feeding_nodes(string word)
{
    node bus_stop[30];
    int i=0, j=0;
    char a[word[0].size()+1];
    strcpy(a, word[0].c_str());
    int hash_key=a[j];
    int hash_code=0;
    while(a[j]!=' ')
    {
        if(j=2) hash_key=hash_key+int(a[j]);
        {    
            j++;
            hash_code=hash_key%29;
        }
        for(int k=1;k<=7;k++)
        {       
            int d=0;
            stringstream convert(word[k]);
            convert>>d;

            bus_stop[hash_code].time[k-1]=d;      // realting to number of people at different nodes at different times
        }

    }
}
    void feeding_buses(int n)
    {
        //Bus buses[n];
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

    void update_distance(){
        cout<<"Update distances of adjacent stops"
        for(int i=0;i<11;i++){
            cin>>distance[i];
        }
    }
};




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



// Number of nodes(bus stops) and buses are fixed
int main()
{
	int clk=0;

	Bus buses[10];
    Node node_array[10];
    int distance[11];

    int Bus::no_of_buses = 10;
    int Node::no_of_nodes = 14;

    cout<<"enter bus informtion separated by underscore \n <number(2-digit)(as on the number plate)>_<capacity(only 2 digit number)(total number of people that can be accomodated)_<name of origin(3 characters)(like H12,H07 etc>";
    feeding_buses(Bus::no_of_buses);
    cout<<"format";
    feeding_nodes(Node::no_of_nodes);

    Node vertex[] = node_array;   // array of node objects
    graph<Node> g;

    g.createGraphNodes(Node::no_of_nodes,vertex);

    g.addEdge()

    // route defined
    string route[3][];
    route[0][]=['h12', 'h07', 'h05', 'h11', 'som', 'kre'];
    route[1][]=['h12', 'h07', 'h05', 'h04', 'h02', 'h01', 'lib', 'som', 'kre'];
    route[2][]=['h15', 'lib', 'som', 'kre'];
    

    while(true){	
	    clk=0;
    	if(clk%2 == 0){
	
    		for(int i=0; i<Node::no_of_nodes; i++){
    			node_array[i].student_arrival(); // function called for updation of student 
    												//at all the nodes.
    		}
		//initialise bus values
    		// calculate route weights
		int route_weight[3]={0,0,0};
		int route_wait_student[3]={0,0,0};
    		for (int i=0;i<3;i++){
			
    			for(int j=0; j<sizeof(route[i]); j++){
			if strcmp(route[i],node_arr[j])==0
			{route_wt[i]+=route[i].wieght; route[i].wait_student+=route[i].num_wait;
    			}
    		}
			
			//Saqib code here
			
			clk++;
			

    	}
    }

}
