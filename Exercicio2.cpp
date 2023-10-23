#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <fstream>
#include <algorithm>

using namespace std;

class Usuario;
class Tweet;

class Tweet {
private:
    Usuario* autor;           
    string conteudo;          
    time_t data_criacao;      

public:
    Tweet(Usuario* autor, const string& conteudo) 
        : autor(autor), conteudo(conteudo), data_criacao(time(nullptr)) {}

    Usuario* get_autor() const { return autor; }
    string get_conteudo() const { return conteudo; }
    time_t get_data_criacao() const { return data_criacao; }
};

