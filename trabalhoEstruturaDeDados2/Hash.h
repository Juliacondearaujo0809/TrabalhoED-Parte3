#ifndef TRABALHOESTRUTURADEDADOS2_HASH_H
#define TRABALHOESTRUTURADEDADOS2_HASH_H

#include <fstream>
#include <string.h>
#include "No.h"

using namespace std;
using std::string;

class Hash {
private:
    No** elementos;
    int capacidade;
public:
    Hash(int cap);
    ~Hash();
    void insere(string chave, string valor, string texto);
    string recupera(string chave);
    No* transformaEmVetor(int quantidade, int *aux);
};

#endif //TRABALHOESTRUTURADEDADOS2_HASH_H
