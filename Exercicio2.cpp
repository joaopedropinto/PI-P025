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

// Função principal - ponto de entrada do programa
int main() {
    // Criação de uma instância da rede social
    RedeSocial redeSocial;

    int opcao = 0;

    // Loop principal - Menu interativo para o usuario
    while (true) {
        cout << "Mini Rede Social" << endl;
        cout << "1. Registrar usuario" << endl;
        cout << "2. Postar tweet" << endl;
        cout << "3. Seguir usuario" << endl;
        cout << "4. Ver feed" << endl;
        cout << "5. Salvar dados" << endl;
        cout << "6. Recuperar dados" << endl;
        cout << "7. Sair" << endl;

        cout << "\nSelecione uma opcao: ";
        cin >> opcao;
        cin.ignore();

        // Processando a opcao escolhida pelo usuario
        switch (opcao) {
            case 1: {
                // Registrar um novo usuario
                string nome_usuario, nome;
                cout << "Nome de usuario: ";
                getline(cin, nome_usuario);
                cout << "Nome real: ";
                getline(cin, nome);
                redeSocial.registrar_usuario(nome_usuario, nome);
                cout << "usuario registrado com sucesso!\n" << endl;
                break;
            }
            case 2: {
                // Postar um novo tweet
                string nome_usuario, tweet;
                cout << "Nome de usuario: ";
                getline(cin, nome_usuario);
                Usuario* user = redeSocial.buscar_usuario(nome_usuario);
                if (user) {
                    cout << "Digite seu tweet: ";
                    getline(cin, tweet);
                    user->postar_tweet(tweet);
                    cout << "Tweet postado!\n" << endl;
                } else {
                    cout << "usuario não encontrado!\n" << endl;
                }
                break;
            }
            case 3: {
                // Seguir um usuario
                string nome_usuario, nome_seguir;
                cout << "Seu nome de usuario: ";
                getline(cin, nome_usuario);
                Usuario* user = redeSocial.buscar_usuario(nome_usuario);
                cout << "Nome de usuario que deseja seguir: ";
                getline(cin, nome_seguir);
                Usuario* user_seguir = redeSocial.buscar_usuario(nome_seguir);
                if (user && user_seguir) {
                    user->seguir(user_seguir);
                    cout << "Agora você está seguindo " << nome_seguir << "!\n" << endl;
                } else {
                    cout << "Erro ao seguir usuario!" << endl;
                }
                break;
            }
            case 4: {
                // Ver os tweets no feed
                string nome_usuario;
                cout << "Nome de usuario: ";
                getline(cin, nome_usuario);
                Usuario* user = redeSocial.buscar_usuario(nome_usuario);
                if (user) {
                    vector<Tweet*> feed = user->receber_feed();
                    cout << "--- Feed ---" << endl;
                    for (auto& tweet : feed) {
                        cout << tweet->get_autor()->get_nome() << ": " << tweet->get_conteudo() << endl;
                    }
                    cout << "\n";
                } else {
                    cout << "usuario não encontrado!" << endl;
                }
                break;
            }
            case 5: {
                // Salvar os dados no arquivo
                redeSocial.salvar_dados("dados.txt");
                cout << "Dados salvos!\n" << endl;
                break;
            }
            case 6: {
                // Recuperar os dados do arquivo
                redeSocial.recuperar_dados("dados.txt");
                cout << "Dados recuperados!\n" << endl;
                break;
            }
            case 7: {
                // Sair do programa
                return 0;
            }
            default: {
                // opcao inválida
                cout << "opcao inválida!" << endl;
                break;
            }
        }
    }

    // Terminar o programa
    return 0;
}

