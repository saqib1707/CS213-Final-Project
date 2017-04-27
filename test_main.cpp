/*
#include <iostream>
#include <unistd.h>
#include "test.h"
using namespace std;

int main(){
	Test obj(10, 20);
	sleep(3);       // arg in seconds
	usleep(200000); // arg in microseconds
	obj.show();
	return 1;
}

*/

#include <iostream>

#include <fstream>

using namespace std;

char separator;
int test_var;

struct Spaxel {
  int array1;
  int array2;
  int red;
  int blue_o2;
  int blue_o3;
};

Spaxel whole_list [3];

int main()
{
    // Reading in the file
    ifstream myfile("sample.csv");
    Spaxel data;
    int n = 0;
    cout << data.array1<< endl;
    myfile >> data.array1; // using as a test to see if it is working
    cout << data.array1<< endl;
    while (myfile >> data.array1)
    {
        // Storing the 5 variable and getting rid of commas
        cout<<"here?"<< endl;
        // Skip the separator, e.g. comma (',')
        myfile >> separator;

        // Read in next value.
        myfile >> data.array2;

        // Skip the separator
        myfile >> separator;

        // Read in next value.
        myfile >> data.red;

        // Skip the separator, e.g. comma (',')
        myfile >> separator;

        // Read in next value.
        myfile >> data.blue_o2;

        // Skip the separator
        myfile >> separator;

        // Read in next value.
        myfile >> data.blue_o3;

        // Ignore the newline, as it is still in the buffer.
        myfile.ignore(10000, '\n');

        // Storing values in an array to be printed out later into another file
        whole_list[n] = data;
        cout << whole_list[n].red << endl;
        n++;

        }
    myfile.close();

    // Putting contents of whole_list in an output file
    //whole_list[0].red = whole_list[0].array1 = whole_list[0].array2 = 1; this was a test     and it didn't work
    ofstream output("sample_out.txt");
    for (int n=0; n<3; n++) {
        if (whole_list[n].red == 1)
            output << whole_list[n].array1 <<","<< whole_list[n].array2<< endl;
    }
    return 0;
}
