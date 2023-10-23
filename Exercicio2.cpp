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

//INICIO DA PARTE DE GABRIEL

//FIM DA PARTE DE GABRIEL

//INICIO DA PARTE DE GREGUE

// FIM DA PARTE DE GREGUE

    // Função para buscar um usuario pelo nome de usuario
    Usuario* buscar_usuario(const string& nome_usuario) const {
        for (auto& user : usuarios) {
            if (user->get_nome_usuario() == nome_usuario) return user;
        }
        return nullptr;
    }

    // Getters
    vector<Usuario*> listar_usuarios() const { return usuarios; }
    vector<Tweet*> listar_tweets() const { return tweets; }

    // Função para salvar dados em arquivo
    void salvar_dados(const string& filename) {
        ofstream file(filename);
        for (auto& user : usuarios) {
            file << user->get_nome_usuario() << " " << user->get_nome() << endl;
        }
        file.close();
    }

    // Função para recuperar dados de arquivo
    void recuperar_dados(const string& filename) {
        ifstream file(filename);
        string nome_usuario, nome;
        while (file >> nome_usuario >> nome) {
            registrar_usuario(nome_usuario, nome);
        }
        file.close();
    }
};

//INICIO DA PARTE DE KAYQUE 

//FIM DA PARTE DE KAYQUE
