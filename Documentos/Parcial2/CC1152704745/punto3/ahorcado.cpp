#include "ahorcado.h"

// class constructor, text files with words and ASCII text art are loaded here
hanged::hanged() {
	// initialize hanged status to 0
	stat = 0;

	// generate an array of integers from 0 to 7 and arrange them in a random order
	// this is to play the available words, stored in text_files/hanged_words.txt,
	// in a random order as well
	int nums[8] = {0,1,2,3,4,5,6,7};
	random_shuffle(std::begin(nums), std::end(nums));

	for (int i = 0; i < 8; i++){
		word_order[i] = nums[i];
	}
}

// function to play the game
void hanged::play_game() {
	game_pres();
	
	// the variable "playing_word" stores the line number to be read on the file that
	// contains the playable words. there is one word per line
	word_order_index = 0;
	
	while (play) {
		game_step();
	}
}

// ______________ PRIVATE FUNCTIONS _______________

// function to print the game presentation and start or get out of the game
void hanged::game_pres() {
	cout << "--------------- Welcome to HANGED-MAN ---------------" << endl;
	cout << "<To play, press ENTER, otherwise, write q+ENTER> ";	

	// create opt string to store player option
	string opt;
	// read player input with getline
	std::getline(cin, opt);
	if (opt.empty()) {
		play = true;	
	}
	else if( opt == "q" ) {
		play = false;
	}
}

// function to read the n-th line of a file
string hanged::r_nline(int n_line) {
	// read the file where the word list os stored
	string fname_words = "text_files/hanged_words.txt";
	wlist.open(fname_words);

	string word_n_clue;

	for (int i = 0; i < n_line; i++ ){
		getline(wlist,word_n_clue);
	}
	
	wlist.close();

	return word_n_clue;
}

// function to split the guess word from the clue
string hanged::split_wordclue_word(string sw_clue) {
	int split_pos = sw_clue.find(",");

	string word = sw_clue.substr(0,split_pos);

	return word;
}

string hanged::split_wordclue_clue(string sw_clue) {
	int split_pos = sw_clue.find(",");

	string clue = sw_clue.substr(split_pos+1,sw_clue.length());

	return clue;
}

// function to find the places where a letter is repeated in a string
vector<int> hanged::where_are_letters(string word, char lett) {
	vector<int> w_pos;

	// the places where the letter is found in the string are stored in a vector
	for (int i = 0; i < word.length(); i++) {
		if (word.at(i) == lett) {
			w_pos.push_back(i);
		}	
	}

	return w_pos;
}

void hanged::draw_hanged(int stats) {
	hanged_level.open("text_files/hanged_draws/h"+to_string(stats)+".txt");

	// print all contents in file
	string hline;
	while (getline(hanged_level,hline)) {
		cout << hline << endl;
	}

	hanged_level.close();
}

// function to play another game, with a new word
void hanged::new_game() {
	cout << "Play again? " << endl;
	cout << "<To play, type Y, otherwise, type anything> ";	

	char op;
	cin >> op;

	if (op == 'Y') {
		play = true;
		stat = 0;
		word_order_index += 1;
	}
	else {
		play = false;
	}

	if (word_order_index == 9) {
		play = false;
	}
}

// funtion to run a game step. This function prints the hanged-man status, shows and updates
// the guessed words, takes the player input of guesses. The hanged man status is 
// characteried by the number of the file name, via the "stat" variable. For example, if
// stat = 4, this means that the player hast wrongfully guessed 3 letters.

void hanged::game_step() {
	if (stat == 0) {
		// print hanged man status based on the "stat" member variable
		draw_hanged(stat);
		
		// the playing_word-th line of the playing words file is read	
		playing_word = word_order[word_order_index]; 
		string w_n_clue = r_nline(playing_word);
		curr_wc_word = split_wordclue_word(w_n_clue); 
		curr_wc_clue = split_wordclue_clue(w_n_clue);

		// get the length of the word to guess
		curr_wlen = curr_wc_word.length();
		
		// when the game starts, stat = 0, and the word must be guessed. For every letter
		// on the word, there is a "_"	
		cout << "Guess the word! ";		
		guess_word = "";
		for (int i = 0; i < curr_wlen; i++) {
			guess_word += "_";
		}
		cout << guess_word << endl;
		stat = 1;
	}
	else {
		// make a guess of a letter on a word
		char guess;
		
		cout << "Your guess: ";
		cin >> guess;
		
		vector<int> w_places = where_are_letters(curr_wc_word, guess);
			
		// if the guess was successful, w_places size is greater than zero. If this is 
		// the case, stat raises by one, and a "life" is lost. Then, a new part of the
		// hanged man is drawn
		if (w_places.size() == 0) {
			stat += 1;
		}
		else {
			cout << "Guessed a letter!" << endl;
		}
		draw_hanged(stat-1);			

		// if 5 lives have been lost, a clue is displayed
		if (stat == 5) {
			cout << "A little clue: ";
			cout << curr_wc_clue << endl;
		}	

		// replace the guesses into the guess word
		cout << "Guess the word! ";
		for (int i = 0; i < w_places.size(); i++) {
			guess_word[w_places[i]] = guess;
		}
		cout << guess_word << endl;

		// if one counts the number of '_' characters on "guess_word", the number
		// of missing characters is obtainded
		vector<int> nw_places = where_are_letters(guess_word, '_');
		int miss_chars = nw_places.size();

		// if miss_chars is 0 before stat is 9, the player wins, otherwise
		// the player loses
		if (miss_chars > 0) {
			if (stat == 9) {
				cout << "You have lost!" << endl;
				new_game();
			}
		}
		else if (stat < 9) {
			cout << "You have won!" << endl;
			new_game();
		}
	}
}	
