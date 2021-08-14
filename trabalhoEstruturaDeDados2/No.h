#ifndef TRABALHOESTRUTURADEDADOS2_NO_H
#define TRABALHOESTRUTURADEDADOS2_NO_H

#include <fstream>
#include <string.h>

using namespace std;
using std::string;

class No {
        friend class Hash;
    private:
        string chave;
        string valor;
        string texto;
        No* proximo = NULL;
    public:
        No();
        No(string chave, string valor, string texto);
        string getChave();
        string getValor();
        string getTexto();
    };

#endif //TRABALHOESTRUTURADEDADOS2_NO_H
