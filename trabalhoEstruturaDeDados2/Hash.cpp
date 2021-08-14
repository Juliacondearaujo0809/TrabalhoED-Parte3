
#include "Hash.h"

#include <iostream>

using namespace std;

const int PRIMO = 37;


int funcaoHash(string s, int M) {
    long h = 0;
    for (int i = 0; i < s.length(); i++) {
        h = (PRIMO * h + s[i]) % M;
    }
    return h;
}

Hash::Hash(int cap){
    elementos = new No*[cap];
    capacidade = cap;
    for (int i = 0; i < cap; i++){
        elementos[i] = NULL;
    }
}

Hash::~Hash(){
    for (int i = 0; i < capacidade; ++i){
        No* atual = elementos[i];
        while(atual != NULL){
            No* aux = atual;
            atual = atual->proximo;
            delete aux;
        }
    }
    delete[] elementos;
}

void Hash::insere(string chave, string valor, string texto){
    int hash = funcaoHash(chave,capacidade);
    if (recupera(chave) == "NOT_FOUND"){
        if (elementos[hash] == NULL){
            elementos[hash] = new No;
            elementos[hash]->chave = chave;
            elementos[hash]->valor = valor;
            elementos[hash]->texto = texto;
        }else{
            No* atual = elementos[hash];
            while(atual->proximo != NULL){
                atual = atual->proximo;
            }
            No* novo = new No;
            novo->chave = chave;
            novo->valor = valor;
            novo->texto = texto;
            atual->proximo = novo;
        }
    }else{
        elementos[hash]->valor = to_string(stoi(elementos[hash]->valor) + stoi(valor));
    }
}

string Hash::recupera(string chave){
    int hash = funcaoHash(chave,capacidade);
    if (elementos[hash] != NULL and elementos[hash]->chave == chave){
        return elementos[hash]->valor;
    }else{
        No* atual = elementos[hash];

        while (atual != NULL and atual->chave != chave){
            atual = atual->proximo;
        }

        if (atual != NULL and atual->chave == chave){
            return atual->valor;
        }else{
            return "NOT_FOUND";
        }
    }

}

No* Hash::transformaEmVetor(int quantidade, int *aux) {
    No* atual;
    No *resposta = static_cast<No *>(malloc(quantidade * sizeof(No)));

    *aux = 0;
    for (int i = 0; i < capacidade; ++i){
        atual = elementos[i];
        while (atual != NULL){
            resposta[*aux] = No(atual->chave, atual->valor, atual->texto);
            (*aux)++;
            atual = atual->proximo;
        }
    }
    return resposta;
}


