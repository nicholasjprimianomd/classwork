/**********************************************************************
 * Project 3: Bulls and Cows
 *
 * This program is a guessing game the asks the user to guess randomly
 * generated numbers.  The computer gives the user hints in the from of
 * bulls and cows.  Specific instructions about gameplay are provided
 * as well.
 *
 * Author: Nicholas J. Primiano <nprimiano@fordham.edu>
 * Date: 5 March 2013
 *
 **********************************************************************/
//include standard libraries
#include <bjarne/std_lib_facilities.h>

void offer_help();  //funtion to provide instrutions for the user
bool play_one_game(vector<int> solution); //funtion that runs the game
//funtion that checks if given input is a cow or neither a bull or a cow
bool check_cows(vector<int> solution, vector<int> guess_solution, int k, int game_length);
//The usual main funtion
int main(){
    vector<int> solution;  //solution funtion to be passed into play_one_game
    int help;  //variable to check if the users requests help
    /*variable to check if the user wants to play again after winning
      a game*/
    int play_again;  
    
    //asks the user if he or she needs instrutions before playing
    cout << "Need help? (0/1)? " << endl;  					   
    cin >> help;
    if(cin.fail()){  //general bad input check
	error("Bad input.");
    }
    if (help == 1)
	offer_help();  //runs funtion to provide instrutions
    else if (help == 0){  
	play_one_game(solution);  ///runs the game with no instructions
    }
    else
	cout << "Bad input." << endl;  //general bad input check

    //Congratulator message whenplay_one_game retruns true
    cout << "Congratulations." << endl;  
    
    while(true){  //loop to chek if the player wants to play again
	cout << "Play again (0/1)? ";
	cin >> play_again;
	if(cin.fail()){  //general bad input check
	    error("Bad input.");
	}
	if (play_again == 1)
	    play_one_game(solution);
	else if (play_again == 0)
            //closes program if the user no longer wants to play
	    return 0;   
	else
	    cout << "Bad input." << endl;  //general badinput check
    }
}

//play_one_game definition
bool play_one_game(vector<int> solution){

    int bull = 0;  //current number of bulls
    int cow = 0;  //current number of cows
    int guess = 0;  //current guess value
    int check_play = 0;  //
    int guess_count = 1;  //current number of guesses in one game
    const int game_length = 4;  //number of solutions and guesses
    const int range = 9;  //range of number to guess between
    //vector to hold possible cows to be passed to a checking funtion
    vector<int> cows; 
		      

    srand(time(0));  //seed random number generator
    //generate random numbers for solution
    for(int i = 0; i < game_length; ++i) {  	 
	int random = 0;
	random = rand() % 10;
        //push_back random number to solution vector
	solution.push_back(random);
    }

    cout << "Solution: " << endl; //for debugging
    for(int j = 0; j < game_length; ++j){
	cout << solution[j] << " ";
    }

    cout << endl; 
//infinite loop until the user gives up or guesses correctly
    while(true){ 
	vector<int> guess_solution; // vetor to hold current user guesses
	cout << "Guess # " << guess_count << ":" << endl;
	for(int j = 0; j < game_length; ++j){   	    
	    cin >> guess;
	    if(cin.fail()){ //general bad input check
		error("Bad input.");
	    }
	    // determines if the user entered an out of range integer
	    if(guess > range){
		error("Out of range. Enter a an integer between 0 and 9.");
	    }
	    //quites and prints solution if the user enters a negative number
	    if(guess < 0){
	        cout << "Too bad! " << "Solution was "; 
		for(int j = 0; j < game_length; ++j){
		    cout << solution[j] << " ";  //prints solution
		}
		cout << endl;
		exit(EXIT_SUCCESS); //closes program
	    }
	    //adds acceptable guess to guess vector
	    guess_solution.push_back(guess);
	    //determines if the user entered extra numbers
	    if(guess_solution.size() > game_length){
		error("Out of range. Too many guesses");
	    }
	}
	//check for bulls then determine possible cows
	for(int k = 0; k < game_length; ++k){
	    if(solution[k] == guess_solution[k])
		++bull;  
	    else{
		check_cows(solution, guess_solution, k, game_length);
		//if check_cow function is true add one cow
		if(check_cows(solution, guess_solution, k, game_length) == true)
		    ++cow;
	    } 
	}
	//add to the total number of guess rounds in a single game
	++guess_count;
	//print current bulls and cows to the screen
	cout << bull << " bulls , " << cow << " cows" << endl;
	
        /*when all bulls are guessed return true and continue
	  executing main()*/
	if(bull == game_length){
	    return true;
	}
	//if not all bulls are guessed reset bull and cow counts to zero
	else if(bull < game_length){
	    bull = 0;
	    cow = 0;
	}
    }
}

//funtion to offer instrutions to the user
void offer_help(){
    //print instructions to the screen
    cout << "Help." << endl;
    //initialze soluton vector to be passed into play_one_game funtion
    vector<int> solution;
    //run play_one_game after providing instructions 
    play_one_game(solution);
}

//funtion ot determine if a possible cow is a cow
bool check_cows(vector <int> solution, vector<int> guess_solution, int k, int game_length){
    //if a possible cow is a cow return true, if not return false
    for (int i = 0; i < game_length; ++i){  
	if (guess_solution[k] == solution[i])
	    return true;
    }
    return false;
}
