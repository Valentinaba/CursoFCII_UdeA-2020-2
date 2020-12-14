#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

namespace Ahorcado
{
    vector<string> Split(string(*));
    string Select_a_Word(vector<string>);
    void make_a_guess(string, string(*),char,int(*),int(*));
    void try_a_word(string,string(*),string,int(*),int(*));
}