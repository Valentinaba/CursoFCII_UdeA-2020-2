#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using std::vector;
using std::ifstream;
using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::to_string;
using std::getline;
using std::random_shuffle;

#ifndef AHORCADO_H
#define AHORCADO_H

class hanged {
	public:
	hanged();
	void play_game();

	private:
	int stat;
	ifstream wlist;
	ifstream hanged_level;
	bool play;
	int word_order[8];
	int playing_word;
	string guess_word;
	int curr_wlen;
	string curr_wc_word;
	string curr_wc_clue;
	int word_order_index;

	void terminal_flush_test();	
	void game_pres();
	void game_step();
	string r_nline(int);
	string split_wordclue_word(string);
	string split_wordclue_clue(string);
	vector<int> where_are_letters(string,char);
	void draw_hanged(int);
	void new_game();
};

#endif
