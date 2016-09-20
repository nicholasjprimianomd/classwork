/**
 * @file proj4.cc
 * \mainpage
 *
 * CISC 2200, Data Structures<br>
 * Project 4: The Banking Simulation<p>
 *
 * Queue-based simulation of a bank having only one teller. (This is
 * Programming Problem 13.6 of our text.)
 *
 * This progam reads in data about a banking queue from a text file.
 * Then it outputs:
 * <ul>
 * <li>A trace of the arrival or depature events exectued, one line per
 * event, and</li>
 * <li>Summary statistics, consisting of the number of customers and
 * the average time spent waiting in line.</li>
 * </ul>
 *
 * @author Nicholas Primiano 
 * @date   4 Apirl 2014
 *
 */

/*
 * includes
 */
#include <fstream>
#include <iostream>
#include <iomanip>
#include <queue>
#include <algorithm>

using namespace std;

/**
 * This holds the information needed for an arrival or departure event.
 */
struct Event
{
    /// arrival time
    int time;
    /// time spend serving
    int serving;
    Event(int t, int w);
};

/**
 * Two parameter consrructor for initilizing 
 * arrival time and time spend serving the 
 * customer.
 *
 * @param t arrival time
 * @param w time spent serving
 */
Event::Event(int t, int w){
    time = t;
    serving = w;    
}

/**
 * Holds arrival and departure events that haven't yet arrived at the
 * bank.
 */
struct EventList 
{
    /// number of customers served
    int count;
    /// queue of arrival and departure events
    priority_queue<Event> events;
    void fill(istream& is);
    void simulate();
};

/**
 * Less-than operator for Events.
 *
 * @param first an event
 * @param second an event
 * @return true iff the arrival time for first is later than that of second
 */ 
bool operator<(const Event &first, const Event &second)
{
    // opposite order!
    return second.time < first.time;
}

/**
 * The usual main function
 */
int main(int argc, char** argv)
    try {
	EventList eventList;
	// command-line parameter munging   
	// also fills the event list with the input data
	char* progname = argv[0];            // simplify msgs a bit
	switch (argc) {
	case 1:
	    eventList.fill(cin);
	    break;
	case 2: {
	    ifstream ifs(argv[1]);
	    if (!ifs) {
		cerr << progname << ": couldn't open " 
		     << argv[1] << endl;
		return 1;
	    }
	    eventList.fill(ifs);
	    break;
	}
	default:
	    cerr << "Usage: " << progname << " [datafile]\n";
	    return 2;
	}
	eventList.simulate();
    }
    catch (int e){
	return e;
    }

/**
 * Fill the event list from an input stream
 * 
 * @param is the input stream
 * @post the event list has been filled up
 */
void EventList::fill(istream& is)
{
    int arrival = 0;
    int time = 0;
    int most_recent_time = 0;
    Event evn(arrival, time);
    count = 0;

    while(is >> arrival >> time) {
	count++;	    	
	most_recent_time = evn.time;
	evn.time = arrival;
	evn.serving = time;
	if(most_recent_time > evn.time) {	   
	    cerr << "customer #" << count 
		 << " out of order (time = " 
		 << evn.time << ", previous time = " 
		 << most_recent_time << ")" << endl;
	    throw 3; // exit status 3
	}
	events.push(evn);
    } 
}

/**
 * Actually does the bank simulation
 *
 * @post all customer have been processed
 */
void EventList::simulate()
{
    int open_time = 0;
    int total_wait = 0;   

    while(!events.empty()) {	
	Event e = events.top();
	events.pop();
	// indicates arrival event
	if(e.serving >= 0){
	    open_time = max(e.time, open_time);
	    total_wait += open_time - e.time;
	    open_time += e.serving;
	    Event depart(open_time, -1);
	    events.push(depart);
	    cout << "Processing an arrival event at time:" 
		 << setw(5) << e.time << endl;    
	}
	else {
	    // indicates departure event
	    cout << "Processing a departure event at time:" 
		 << setw(4) << e.time  << endl;
	}
    }
    cout << endl << "Final statistics:" << endl;
    cout << setw(41) << "Total number of people processed:     "; 
    cout << count << endl;
    // cast to double to avoid intger rounding error
    cout << setw(41) << "Average amount of time spent waiting: " 
	 << (double)total_wait/count << endl;
}
 


