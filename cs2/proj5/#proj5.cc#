/**********************************************************************
 *
 * Project 5: Timing Has Come Today
 *
 * Author: Nicholas Primiano <nprimiano@fordham.edu>
 * Date: 9 December 2013
 *
 * Determine time it takes in order to insert data into different 
 * containers.
 * 
 ********************************************************************/

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <list>
#include <set>
#include <vector>

using namespace std;

// inserter for timing
typedef void Inserter(const vector<double>&);
//  insert data to list
void insert_list(const vector <double>  &data);
// insert data to vector
void insert_vector(const vector <double>  &data);
// insert data to set
void insert_set(const vector <double>  &data);
//  time insertion for list, vector, and set
void insert_time(Inserter f, const vector <double> &data);
// generate random data
vector<double> gen_data(int elts);

// class to check for ordered insertion
class Larger_than {
    double v;
public:
    Larger_than(double vv):v(vv){}
    bool operator()(double x) const {return x > v;}
    
};

int main()
{   
    srand(time(0)); // initialize random number generator
    int num_elts;   //  number of random elements
    cout << "How many elements for container? ";
    // get number of random elements
    while (cin >> num_elts) { 
	if (num_elts <= 0) {
	    cout << "Asking for empty container---ignored." << endl;
	}
	else {
	    // check time it takes to fill each container
	    vector<double> data = gen_data(num_elts);
	    insert_time(insert_list, data);
	    insert_time(insert_set, data);		 
	    insert_time(insert_vector, data);
	}
	// ask for input again
	cout << "How many elements for next container? ";
    }
    cout << endl;
}

// generate num_elts random numbers in the range [0.0, 1.0),
// which are returned in a vector
vector<double> gen_data(int num_elts) 
{
    vector<double> result;
    for (int i = 0; i < num_elts; i++) {
	double datum = 1.0* rand()/RAND_MAX;
	result.push_back(datum);
    }
    return result;
}
// insert sorted data to a list
void insert_list(const vector <double> & data)
{
    cout << "Inserting for list" << endl;
    list <double> p;
    for (unsigned int i = 0; i < data.size(); i++) {
	p.insert(find_if(p.begin(), p.end(), Larger_than(i)), i);
    }
    cout << "Check: ";
    if (is_sorted(p.begin(),p.end())) {
	cout << "list is sorted" << endl;
    }
    else {
	cout << "list is not sorted" << endl;
    } 
}
// insert sorted data to a set
void insert_set(const vector <double> &data)
{
    cout << "Inserting for set" << endl;
    set <double> p;
    for (unsigned int i = 0; i < data.size(); i++) {
	p.insert(i);
    }
}
// insert sorted data to a vector
void insert_vector(const vector <double> &data)
{
    cout << "Inserting for vector" << endl;
    vector <double> p;
    for (unsigned int i = 0; i < data.size(); i++) {
	p.insert(find_if(p.begin(), p.end(), Larger_than(i)), i);
    }
    cout << "Check: ";
    if (is_sorted(p.begin(),p.end())) {
	cout << "vector is sorted" << endl;
    }
    else {
	cout << "vector is not sorted" << endl;
    } 
}

void insert_time(Inserter timer, const vector <double> &data)
{
    clock_t t1 = clock();
    if (t1 == clock_t(-1)) { // clock_t(-1) means "clock() didn’t work"
	cerr << "sorry, no clock\n";
	exit(1);
    }
    // time each insertion (list, vector, then set)
    timer(data);
    clock_t t2 = clock();
    if (t2 == clock_t(-1)) {
	cerr << "sorry, clock overflow\n";
	exit(2);
    }
    // print times
    cout << "Elapsed time: " << fixed << setprecision(2)
	 << static_cast<double>(t2 - t1)/CLOCKS_PER_SEC << " seconds\n" << endl;
}


