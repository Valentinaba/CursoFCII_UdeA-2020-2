#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <cstdlib>
#include <ctime>

using namespace std;

class p_ahorcado


{
 public:
  void play(void);
 private:
  string letter_player;
  string word_player;
  string print_word;
  string letters_from_player;
  int n_err;
  int acierto;
  string read_word(void);
  void is_letter_in_word(const string);
  void is_valid_letter(void);
  void is_valid_word(const int);
  bool is_the_word(const string);
  void encabezado(void) const;

};
