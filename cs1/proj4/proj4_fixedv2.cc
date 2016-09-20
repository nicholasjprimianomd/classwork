/**********************************************************************
 *
 * Project 4: Bulls and Cows (The Next Generation)
 *
 * Author: Nicholas J. Primiano <nprimiano@fordham.edu>
 *
 * Date: 4 April 2013
 *
 * This is a letter guessing game with several levels of difficulty.
 * The computer generates a number of random letters or vowels based
 * on user input. Then user is prompted to guess the letters or 
 * vowels in the correct order. 
 *
 **********************************************************************/

#include <bjarne/std_lib_facilities.h>

int generate_random_number(int random_range);
char generate_letters();
char generate_vowels();
int get_level();
vector<char> generate_solution(unsigned int game_length);
bool play_one_game(vector<char> &solution);
void offer_help();
vector<unsigned int> compute_incidence(vector<char> &data);
unsigned int count_cows(int bulls, vector<char> guess,
			vector<char> solution);

//classes for error handling
class Bad_data{};
class Bad_incidence{};

//top integer range of a character
const unsigned int range_top = 128;
//letter of the alphabet
const string letters =  "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
//vowels
const string vowels = "AEIOU";
//max length of solution vector
const unsigned int max_length = 4;

//usual main function
int main()
{
    try {
	offer_help();                  // offer help if needed

	bool playing = true;           // play another round?
	while (playing) {
	    //function to get the level of difficulty from the user
	    unsigned int game_length = get_level();
	    //solution vector for a single game
	    vector<char> solution = generate_solution(game_length);

	    // play the game
	    bool success = play_one_game(solution);

	    // check to play again
	    if (success) {
		// if won print congratulatory message
		cout << "Congratulations!\n"; 
	    }
	    else {
		// if loss print solution
		cout << "Too bad!  Solution was ";
		for(unsigned int i = 0; i < solution.size(); i++){
		    cout << solution[i] << " ";
		}
		cout << endl;
	    }
	    // another round?
	    cout << "\nPlay again (0/1)? ";
	    int play_again = -1;
	    if (!(cin >> play_again)) {
		throw Bad_data();
	    }
	    playing = play_again != 0;
	}
    }
    //catch blocks for bad data and bad incidence
    catch (Bad_data) { 
	cerr << "Bad input data!  I give up!\n";
	return 1;
    }
    catch (Bad_incidence) {
	cerr << "Bad incidence vector.  This can't happen!\n";
	return 2;
    }
    return 0;
}

//function to generate solution for all difficulties
vector<char> generate_solution(unsigned int game_length){

    srand(time(0));  //seed random number generator
    //vector to determine the length of the solution
    vector<unsigned int> solution_length(max_length);
    //assign length
    const unsigned int level_check = 2;
    solution_length[0] = 2;
    solution_length[1] = 3;
    solution_length[2] = 2;
    solution_length[3] = 4;
    //vector to hold randomly generated solution
    vector<char> solution;

    for(unsigned int i = 0; i < solution_length[game_length]; i++) {
	//check to generate vowels or letters
	if(game_length < level_check) {
	    solution.push_back(generate_vowels());
	}
	else{
	    solution.push_back(generate_letters());
	}
    }
    return solution;
}

int generate_random_number(int random_range)
{
    //generate random numbers for solution
    int random_number = randint(random_range);
    return random_number;
}

char generate_letters()
{
    //generate random letters using random number function
    unsigned int index = generate_random_number(letters.length());
    return letters[index];
}

char generate_vowels(){
    //generate random vowels using random number function
    unsigned int index_vowels = generate_random_number(vowels.length());
    return vowels[index_vowels];
}

int get_level(){
    //variable to store difficulty level given by the user
    int difficulty = 0;

    cout << "Level of play (beginner = 0,"
         <<"easy = 1, medium = 2, hard = 3)? ";
    if (!(cin >> difficulty)) {
	throw Bad_data();
    }
    return difficulty;
}

bool play_one_game(vector<char> &solution)
{
    //function to play a single game: take user guess and check answer
    unsigned int num_guesses = 0;
    bool still_guessing = true;           // still playing this game?

    while (still_guessing) {
	vector<char> guess;               // current guess
	unsigned int bulls = 0;           // number of bulls
	// check how many times the user has guessed in a game
	num_guesses++;
	//ask for user guess
	cout << "Guess #" << num_guesses <<"? ";
	//temporary guess variable
	char temp_char;
	for (unsigned int i = 0; i < solution.size(); i++) {
	    //take user input and check for quit
	    if(!(cin >> temp_char)){
		throw Bad_data();
	    }
	    if(temp_char == '?') {
		return false;
	    }
	    guess.push_back(temp_char);
	}

	// count bulls
	for (unsigned int i = 0; i < solution.size(); i++) {
	    if (guess[i] == solution[i]) {
		bulls++;
	    }
	}
	//count cows
	unsigned int cows = count_cows(bulls, guess, solution);
        //print bulls and cows for current game
	cout << "Bulls: " << bulls << ", cows: " << cows << endl;
	//check if the user won the round
	if (bulls == solution.size()) {
	    return true;
	}
    }
    return false;
}

//function to offer help if needed
void offer_help()
{
    cout << "Need help (0/1)? ";
    int need_help;
    if (!(cin >> need_help)) {
	throw Bad_data();
    }
    //print help
    if (need_help != 0) {
	cout << "\nI will generate a pattern of letters," << endl 
	     << "which will depend on the" 
	     << "level of play you choose:" << endl
	     <<"   Level 0 (beginner): Only vowels," 
	     << "with two slots to fill" << endl
	     <<"   Level 1 (easy): Only vowels," 
	     << "with three slots to fill" << endl
	     <<"   Level 2 (medium): Any" 
	     << "letter, with two slots to fill" << endl
	     <<"   Level 3 (hard): Any letter," 
	     <<" with four slots to fill " << endl
	     <<"that you choose." << endl
	     <<"You will give a series of " 
	     <<"guesses of this pattern." << endl
	     <<"Each guess that you enter will " 
	     <<"be a line containing letters," << endl
	     <<"separated by spaces, such as"<< endl 
	     <<"      E T A O" << endl
	     <<"I will respond with the "
	     <<"number of bulls and cows." << endl
	     <<"For example, if the actual " 
	     << "solution was ""A T O I""," << endl
	     <<"I'll respond" << endl
	     <<"  Bulls: 1, cows: 2" << endl
	     <<"since one guess (T) were " 
	     <<"in the correct position" << endl
	     <<"and two guesses (A and O) "
	     <<"were in incorrect positions."<< endl
	     <<"See how many guesses it" 
	     <<"takes you to get the solution!" << endl
	     << endl
	     <<"If you want to give up, type " 
	     <<"a negative number for one of" << endl
	     <<"your guesses, and we'll"
	     <<" tell you what the pattern was." << endl;
    }
}

//function to compute incidiences and check for Bad_incidence
vector<unsigned int> compute_incidence(vector<char> &data)
{
    vector<unsigned int> temp(range_top);
    for (unsigned int i = 0; i < data.size(); i++) {
        if (data[i] < 0 || data[i] >= temp.size()) {
	    throw Bad_incidence();
	}
	temp[data[i]]++;
    }
    return temp;
}

//count the number of cows in the guess
unsigned int count_cows(int bulls, vector<char> guess,
			vector<char> solution)
{
    vector<unsigned int> solution_incidence = compute_incidence(solution);
    vector<unsigned int> guess_incidence = compute_incidence(guess);   
    unsigned int total_hits = 0;
    for (unsigned int i = 0; i < solution_incidence.size(); i++) {
	total_hits += min(solution_incidence[i], guess_incidence[i]);
    }
    return total_hits - bulls;
}
