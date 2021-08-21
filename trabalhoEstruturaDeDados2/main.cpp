#include <fstream>
#include <string.h>
#include <stdio.h>
#include <time.h>
#include "Artist.h"
#include "Track.h"
#include "Hash.h"
#include <iostream>
#include <stdlib.h>

#include <cstdio>
#include <cstdlib>

using namespace std;
using std::string;


// Início do trabalho 1

Artist* lerArquivoBinArtist(char *caminho, int quantidade) {
    Artist artist;

    char origem[100];
    strcpy(origem, caminho);
    strcat(origem, "/artists.bin");

    std::ifstream inputFile(origem, std::ifstream::in | std::ifstream::binary);

    Artist *resposta = static_cast<Artist *>(malloc(quantidade * sizeof(artist)));

    inputFile.seekg(0,ios::end);
    long total = (inputFile.tellg())/sizeof(Artist);

    for (int i = 0; i < quantidade; i++) {
        int sorteio = rand() % total;
        int posicao = sorteio * sizeof(Artist);
        inputFile.seekg(posicao);
        inputFile.read((char *) &artist, sizeof(Artist));
        resposta[i] = artist;
    }

    inputFile.close();
    return resposta;
}

void gerarArquivoBinArtist(char *caminho) {
    char origem[100];
    char destino[100];

    strcpy(origem, caminho);
    strcpy(destino, caminho);

    strcat(origem, "/artists.csv");
    strcat(destino, "/artists.bin");

    std::string id;
    std::string followers;
    std::string genre;
    std::string name;
    std::string popularity;

    std::string valor;
    std::string texto;

    std::ofstream outputFile(destino, std::ifstream::out | std::ifstream::binary);

    std::ifstream inputFile(origem, std::ifstream::in);
    getline (inputFile,texto);
    getline (inputFile,texto);

    while (inputFile.good()) {

        valor = "";
        int campo = 1;
        bool aspas_abertas = false;

        for (int i = 0; i < texto.size(); i++) {
            if (texto[i] == '"') aspas_abertas = not aspas_abertas;

            if (((texto[i] == ',') && (not aspas_abertas)) || (texto[i] == '\n') || (texto[i] == '\r')) {
                if (campo == 1) id = valor;
                if (campo == 2) followers = valor;
                if (campo == 3) genre = valor;
                if (campo == 4) name = valor;
                if (campo == 5) popularity = valor;
                valor = "";
                campo++;
            } else {
                if (texto[i] != '"') {
                    valor = valor + texto[i];
                }
            }
        }
        char *cstr_id = const_cast<char *>(id.c_str());
        char *cstr_genre = const_cast<char *>(genre.c_str());
        char *cstr_name = const_cast<char *>(name.c_str());
        char *cstr_followers = const_cast<char *>(followers.c_str());
        char *cstr_popularity = const_cast<char *>(popularity.c_str());

        Artist *artist = new Artist(cstr_id, cstr_followers, cstr_genre, cstr_name, cstr_popularity);

        artist->binarySave(outputFile);

        getline (inputFile,texto);
    }

    inputFile.close();
    outputFile.close();
}

void imprimirConsoleArtists(Artist* artists) {
    for (int i = 0; i < 10; i++) {
        artists[i].printArtist();
    }
}

void gravarArquivoArtists(char* caminho, Artist* artists) {

    char destino[100];
    strcpy(destino, caminho);
    strcat(destino, "/artists.txt");

    ofstream saida;
    saida.open(destino);
    for (int i = 0; i < 100; i++) {
        artists[i].textSave(saida);
    }
    saida.close();
}

bool verificarArquivoBinArtistExistente(char *caminho) {
    FILE *entrada;
    bool resultado;

    char origem[100];

    strcpy(origem, caminho);
    strcat(origem, "/artists.bin");

    entrada = fopen(origem, "rb");
    if (entrada != NULL) {
        resultado = true;
        fclose(entrada);
    } else {
        resultado = false;
    }
    return resultado;
}


Track* lerArquivoBinTrack(char *caminho, int quantidade) {
    Track track;

    char origem[100];
    strcpy(origem, caminho);
    strcat(origem, "/tracks.bin");

    std::ifstream inputFile(origem, std::ifstream::in | std::ifstream::binary);

    int linhas = 0;

    Track *resposta = static_cast<Track *>(malloc(quantidade * sizeof(track)));

    inputFile.seekg(0,ios::end);
    long total = (inputFile.tellg())/sizeof(Track);

    for (int i = 0; i < quantidade; i++) {
        int sorteio = rand() % total;
        int posicao = sorteio * sizeof(Track);
        inputFile.seekg(posicao);
        inputFile.read((char *) &track, sizeof(Track));
        resposta[i] = track;
    }
    inputFile.close();
    return resposta;
}


void gerarArquivoBinTrack(char *caminho) {
    char origem[100];
    char destino[100];

    strcpy(origem, caminho);
    strcpy(destino, caminho);

    strcat(origem, "/tracks.csv");
    strcat(destino, "/tracks.bin");

    std::string id;
    std::string name;
    std::string artist;
    std::string id_artist;
    std::string release_date;
    std::string isExp;
    std::string popularity;
    std::string duration;
    std::string key;
    std::string mode;
    std::string time_signature;
    std::string speechiness;
    std::string acousticness;
    std::string instrumentalness;
    std::string liveness;
    std::string valence;
    std::string tempo;
    std::string loudness;
    std::string danceability;
    std::string energy;


    std::string valor;
    std::string texto;

    std::ofstream outputFile(destino, std::ifstream::out | std::ifstream::binary);

    std::ifstream inputFile(origem, std::ifstream::in);
    getline (inputFile,texto);
    getline (inputFile,texto);

    while (inputFile.good()) {

        valor = "";
        int campo = 1;
        bool aspas_abertas = false;

        for (int i = 0; i < texto.size(); i++) {
            if (texto[i] == '"') aspas_abertas = not aspas_abertas;

            if (((texto[i] == ',') && (not aspas_abertas)) || (texto[i] == '\n') || (texto[i] == '\r')) {
                if (campo == 1) id = valor;
                if (campo == 2) name = valor;
                if (campo == 3) popularity = valor;
                if (campo == 4) duration = valor;
                if (campo == 5) isExp = valor;
                if (campo == 6) artist = valor;
                if (campo == 7) id_artist = valor;
                if (campo == 8) release_date = valor;
                if (campo == 9) danceability = valor;
                if (campo == 10) energy = valor;
                if (campo == 11) key = valor;
                if (campo == 12) loudness = valor;
                if (campo == 13) mode = valor;
                if (campo == 14) speechiness = valor;
                if (campo == 15) acousticness = valor;
                if (campo == 16) instrumentalness = valor;
                if (campo == 17) liveness = valor;
                if (campo == 18) valence = valor;
                if (campo == 19) tempo = valor;
                if (campo == 20) time_signature = valor;
                valor = "";
                campo++;
            } else {
                if (texto[i] != '"') {
                    valor = valor + texto[i];
                }
            }
        }

        char *cstr_id = const_cast<char *>(id.c_str());
        char *cstr_name = const_cast<char *>(name.c_str());
        char *cstr_artist = const_cast<char *>(artist.c_str());
        char *cstr_id_artist = const_cast<char *>(id_artist.c_str());
        char *cstr_release_date = const_cast<char *>(release_date.c_str());
        char *cstr_isExp = const_cast<char *>(isExp.c_str());
        char *cstr_popularity = const_cast<char *>(popularity.c_str());
        char *cstr_duration = const_cast<char *>(duration.c_str());
        char *cstr_key = const_cast<char *>(key.c_str());
        char *cstr_mode = const_cast<char *>(mode.c_str());
        char *cstr_time_signature = const_cast<char *>(time_signature.c_str());
        char *cstr_speechiness = const_cast<char *>(speechiness.c_str());
        char *cstr_acousticness = const_cast<char *>(acousticness.c_str());
        char *cstr_instrumentalness = const_cast<char *>(instrumentalness.c_str());
        char *cstr_liveness = const_cast<char *>(liveness.c_str());
        char *cstr_valence = const_cast<char *>(valence.c_str());
        char *cstr_tempo = const_cast<char *>(tempo.c_str());
        char *cstr_loudness = const_cast<char *>(loudness.c_str());
        char *cstr_danceability = const_cast<char *>(danceability.c_str());
        char *cstr_energy = const_cast<char *>(energy.c_str());

        Track *track = new Track(cstr_id, cstr_name, cstr_artist, cstr_id_artist, cstr_release_date,
                                 cstr_isExp, cstr_popularity, cstr_duration,
                                 cstr_danceability, cstr_energy, cstr_key,
                                 cstr_loudness, cstr_mode,
                                 cstr_speechiness, cstr_acousticness, cstr_instrumentalness,
                                 cstr_liveness, cstr_valence, cstr_tempo, cstr_time_signature);

        track->binarySave(outputFile);

        getline (inputFile,texto);
    }

    inputFile.close();
    outputFile.close();
}

void imprimirConsoleTracks(Track* tracks) {
    for (int i = 0; i < 10; i++) {
        tracks[i].printTrack();
    }
}

void gravarArquivoTracks(char* caminho, Track* tracks) {

    char destino[100];
    strcpy(destino, caminho);
    strcat(destino, "/tracks.txt");

    ofstream saida;
    saida.open(destino);
    for (int i = 0; i < 100; i++) {
        tracks[i].textSave(saida);
    }
    saida.close();
}

bool verificarArquivoBinTrackExistente(char *caminho) {
    FILE *entrada;
    bool resultado;

    char origem[100];

    strcpy(origem, caminho);
    strcat(origem, "/tracks.bin");

    entrada = fopen(origem, "rb");
    if (entrada != NULL) {
        resultado = true;
        fclose(entrada);
    } else {
        resultado = false;
    }
    return resultado;
}


void trabalho1(int argc, char *argv[ ]) {

    char* caminho = argv[1];

    int tipo;
    printf("Digite 1=Artist / 2=Track: ");
    scanf("%d", &tipo);

    int saida;
    printf("Digite 1=Console / 2=Arquivo: ");
    scanf("%d", &saida);
    int quantidade;
    if (saida == 2) {
        quantidade = 100;
    }
    else {
        quantidade = 10;
    }

    if (tipo == 1) {
        if (!verificarArquivoBinArtistExistente(caminho)) {
            gerarArquivoBinArtist(caminho);
        }
        Artist *artists = lerArquivoBinArtist(caminho, quantidade);
        if (saida == 1) {
            imprimirConsoleArtists(artists);
        } else {
            if (saida == 2) {
                gravarArquivoArtists(caminho, artists);
            }
        }
    } else {
        if (tipo == 2) {
            if (!verificarArquivoBinTrackExistente(caminho)) {
                gerarArquivoBinTrack(caminho);
            }
            Track *tracks = lerArquivoBinTrack(caminho, quantidade);
            if (saida == 1) {
                imprimirConsoleTracks(tracks);
            } else {
                if (saida == 2) {
                    gravarArquivoTracks(caminho, tracks);
                }
            }
        }
    }

}

// Fim do trabalho 1


// Início do trabalho 2

// Heap sort

void organizaHeap(Artist* vetor, int tamVetor, int i, unsigned int *trocas, unsigned int *comparacoes)
{
    int maior = i;
    int esquerda = 2 * i + 1;
    int direita = 2 * i + 2;

    (*comparacoes)++;
    if (esquerda < tamVetor && stof(vetor[esquerda].getFollowers()) > stof(vetor[maior].getFollowers())) {
        maior = esquerda;
    }

    (*comparacoes)++;
    if (direita < tamVetor && stof(vetor[direita].getFollowers()) > stof(vetor[maior].getFollowers())) {
        maior = direita;
    }

    (*comparacoes)++;
    if (maior != i) {
        swap(vetor[i], vetor[maior]);
        (*trocas)++;
        organizaHeap(vetor, tamVetor, maior, trocas, comparacoes);
    }
}

void heapSort(Artist* vetor, int tamVetor, unsigned int *trocas, unsigned int *comparacoes)
{
    for (int i = tamVetor / 2 - 1; i >= 0; i--)
        organizaHeap(vetor, tamVetor, i, trocas, comparacoes);

    (*trocas) = tamVetor - 1;
    for (int i = tamVetor - 1; i > 0; i--) {
        swap(vetor[0], vetor[i]);
        organizaHeap(vetor, i, 0, trocas, comparacoes);
    }
}

// Quick Sort

int particaoQuick (Artist* vetor, int indiceInicial, int indiceFinal, unsigned int *trocas, unsigned int *comparacoes)
{
    Artist elemento1 = vetor[indiceFinal];
    int i = (indiceInicial - 1);

    for (int j = indiceInicial; j <= indiceFinal - 1; j++)
    {
        Artist elemento2 = vetor[j];
        (*comparacoes)++;
        if (stof(elemento2.getFollowers()) < stof(elemento1.getFollowers()))
        {
            i++;
            Artist troca1 = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = troca1;
            (*trocas)++;
        }
    }
    Artist troca2 = vetor[i+1];
    vetor[i+1] = vetor[indiceFinal];
    vetor[indiceFinal] = troca2;
    (*trocas)++;
    return (i + 1);
}

void quickSort(Artist* vetor, int indiceInicial, int indiceFinal, unsigned int *trocas, unsigned int *comparacoes)
{
    (*comparacoes)++;
    if (indiceInicial < indiceFinal)
    {
        int indiceParticao = particaoQuick(vetor, indiceInicial, indiceFinal, trocas, comparacoes);

        quickSort(vetor, indiceInicial, indiceParticao - 1, trocas, comparacoes);
        quickSort(vetor, indiceParticao + 1, indiceFinal, trocas, comparacoes);
    }
}

// Merge Sort

void merge(Artist* vetor, int const esquerda, int const meio, int const direita, unsigned int *trocas, unsigned int *comparacoes)
{
    auto const tamVetor1 = meio - esquerda + 1;
    auto const tamVetor2 = direita - meio;

    auto *vetorEsquerda = new Artist[tamVetor1],
         *vetorDireita = new Artist[tamVetor2];

    for (auto i = 0; i < tamVetor1; i++)
        vetorEsquerda[i] = vetor[esquerda + i];
    for (auto j = 0; j < tamVetor2; j++)
        vetorDireita[j] = vetor[meio + 1 + j];

    auto indiceVetor1 = 0,
         indiceVetor2 = 0;
    int indiceVetorMerge = esquerda;

    while (indiceVetor1 < tamVetor1 && indiceVetor2 < tamVetor2) {
        (*comparacoes)++;
        if (stoi(vetorEsquerda[indiceVetor1].getFollowers()) <= stoi(vetorDireita[indiceVetor2].getFollowers())) {
            vetor[indiceVetorMerge] = vetorEsquerda[indiceVetor1];
            indiceVetor1++;
        }
        else {
            vetor[indiceVetorMerge] = vetorDireita[indiceVetor2];
            indiceVetor2++;
        }
        indiceVetorMerge++;
    }
    while (indiceVetor1 < tamVetor1) {
        vetor[indiceVetorMerge] = vetorEsquerda[indiceVetor1];
        indiceVetor1++;
        indiceVetorMerge++;
    }
    while (indiceVetor2 < tamVetor2) {
        vetor[indiceVetorMerge] = vetorDireita[indiceVetor2];
        indiceVetor2++;
        indiceVetorMerge++;
    }
}

void mergeSort(Artist* vetor, int const inicio, int const fim, unsigned int *trocas, unsigned int *comparacoes)
{
    if (inicio >= fim)
        return;
    auto meio = inicio + (fim - inicio) / 2;
    mergeSort(vetor, inicio, meio, trocas, comparacoes);
    mergeSort(vetor, meio + 1, fim, trocas, comparacoes);
    merge(vetor, inicio, meio, fim, trocas, comparacoes);
}

void copiarVetor(Artist *vetorOriginal, Artist *vetorNovo, int tamVetor) {
    for (int i=0; i < tamVetor; i++) {
        vetorNovo[i] = vetorOriginal[i];
    }
}

void exibirCabecalhoSaida(int m, int n, string algoritmo, ofstream &saida) {
    saida << endl;
    saida << "N = " << n << endl;
    saida << "M = " << m << endl;
    saida << "Algoritmo: " << algoritmo << endl;
}

void exibirRodapeSaida(double tempo, unsigned int comparacoes, unsigned int trocas, ofstream &saida) {
    saida << "Tempo: " << tempo << " segundos" << endl;
    saida << "Comparações: " << comparacoes << endl;
    saida << "Trocas: " << trocas << endl;
}

void exibirRodapeMediasSaida(string algoritmo, long double mediaTempo, long double mediaComparacoes, long double mediaTrocas, ofstream &saida) {
    saida << " " << endl;
    saida << "Algoritmo: " << algoritmo << endl;
    saida << "Média Tempo = " << mediaTempo << " segundos" << endl;
    saida << "Média Comparações = " << mediaComparacoes << endl;
    saida << "Média trocas = " << mediaTrocas << endl;
}

void trabalho2ordenacao(int argc, char *argv[ ], bool teste) {

    char *caminho = argv[1];

    if (!verificarArquivoBinArtistExistente(caminho)) {
        gerarArquivoBinArtist(caminho);
    }
    int qtdeValoresN;
    int maxM;
    int qtdeRegistros[5];

    if (teste) {
        qtdeValoresN = 1;
        qtdeRegistros[0] = 100;
        maxM = 1;
    }
    else {
        char origem[100];
        strcpy(origem, caminho);
        strcat(origem, "/sort.dat");

        std::ifstream inputFile(origem, std::ifstream::in);

        if (inputFile.fail()) {
            cout << "Arquivo sort.dat não encontrado";
            return;
        }

        inputFile.seekg(0, ios::end);
        qtdeValoresN = (inputFile.tellg()) / sizeof(int);
        inputFile.seekg(0, ios::beg);

        std::string texto;
        getline(inputFile, texto);
        maxM = stoi(texto);

        int linha = 0;
        getline(inputFile, texto);
        while (inputFile.good()) {
            qtdeRegistros[linha] = stoi(texto);
            linha++;
            getline(inputFile, texto);
        }
        inputFile.close();
    }

    char destino[100];
    strcpy(destino, caminho);
    if (teste) {
        strcat(destino, "/teste.txt");
    }
    else {
        strcat(destino, "/saida.txt");
    }
    ofstream saida;
    saida.open(destino);

    long double tempo;
    unsigned int comparacoes;
    unsigned int trocas;
    clock_t startTime;

    string algoritmos[3] = {"Merge Sort", "Heap Sort", "Quick Sort"};

    for (int i=0; i < qtdeValoresN; i++) {

        long double tempoTotal[3]        = {0.0, 0.0, 0.0};
        unsigned int comparacoesTotal[3] = {0, 0, 0};
        unsigned int trocasTotal[3]      = {0, 0, 0};

        int vetorOriginal[qtdeRegistros[i]];
        int tamVetor = sizeof(vetorOriginal) / sizeof(vetorOriginal[0]);

        Artist *vetor = static_cast<Artist *>(malloc(tamVetor * sizeof(Artist)));

        for (int m = 0; m < maxM; m++) {

            Artist *vetorOriginal = lerArquivoBinArtist(caminho, qtdeRegistros[i]);

            for (int a=0; a<3; a++) {
                copiarVetor(vetorOriginal, vetor, tamVetor);
                exibirCabecalhoSaida(m + 1, qtdeRegistros[i], algoritmos[a], saida);
                comparacoes = 0;
                trocas = 0;
                startTime = clock();
                if (a == 0)
                    mergeSort(vetor, 0, tamVetor - 1, &trocas, &comparacoes);
                if (a == 1)
                    heapSort(vetor, tamVetor, &trocas, &comparacoes);
                if (a == 2)
                    quickSort(vetor, 0, tamVetor - 1, &trocas, &comparacoes);
                tempo =  double(clock() - startTime) / (double) CLOCKS_PER_SEC;
                exibirRodapeSaida(tempo, comparacoes, trocas, saida);
                tempoTotal[a] += tempo;
                comparacoesTotal[a] += comparacoes;
                trocasTotal[a] += trocas;
            }
        }

        for (int a=0; a<3; a++) {
            exibirRodapeMediasSaida(algoritmos[a],
                                    tempoTotal[a] / maxM,
                                    comparacoesTotal[a] / maxM,
                                    trocasTotal[a] / maxM,
                                    saida);
        }
    }
    saida.close();
}

void mergeSortDescrescente(No* vetor, int const esquerda, int const meio, int const direita)
{
    auto const tamVetor1 = meio - esquerda + 1;
    auto const tamVetor2 = direita - meio;

    auto *vetorEsquerda = new No[tamVetor1],
            *vetorDireita = new No[tamVetor2];

    for (auto i = 0; i < tamVetor1; i++)
        vetorEsquerda[i] = vetor[esquerda + i];
    for (auto j = 0; j < tamVetor2; j++)
        vetorDireita[j] = vetor[meio + 1 + j];

    auto indiceVetor1 = 0,
            indiceVetor2 = 0;
    int indiceVetorMerge = esquerda;

    while (indiceVetor1 < tamVetor1 && indiceVetor2 < tamVetor2) {
        if (stoi(vetorEsquerda[indiceVetor1].getValor()) >= stoi(vetorDireita[indiceVetor2].getValor())) {
            vetor[indiceVetorMerge] = vetorEsquerda[indiceVetor1];
            indiceVetor1++;
        }
        else {
            vetor[indiceVetorMerge] = vetorDireita[indiceVetor2];
            indiceVetor2++;
        }
        indiceVetorMerge++;
    }
    while (indiceVetor1 < tamVetor1) {
        vetor[indiceVetorMerge] = vetorEsquerda[indiceVetor1];
        indiceVetor1++;
        indiceVetorMerge++;
    }
    while (indiceVetor2 < tamVetor2) {
        vetor[indiceVetorMerge] = vetorDireita[indiceVetor2];
        indiceVetor2++;
        indiceVetorMerge++;
    }
}

void ordenarMergeDecrescente(No* vetor, int const inicio, int const fim)
{
    if (inicio >= fim)
        return;
    auto meio = inicio + (fim - inicio) / 2;
    ordenarMergeDecrescente(vetor, inicio, meio);
    ordenarMergeDecrescente(vetor, meio + 1, fim);
    mergeSortDescrescente(vetor, inicio, meio, fim);
}

void trabalho2hash(int argc, char *argv[ ], bool teste) {
    char *caminho = argv[1];

    int m;
    int n;

    if (teste) {
        m = 10;
        n = 1000;
    }
    else {
        char origem[100];
        strcpy(origem, caminho);
        strcat(origem, "/hash.dat");

        std::ifstream inputFile(origem, std::ifstream::in | std::ifstream::binary);

        if (inputFile.fail()) {
            cout << "Arquivo hash.dat não encontrado";
            return;
        }
        std::string texto;

        getline (inputFile,texto);
        n = stoi(texto);

        getline (inputFile,texto);
        m = stoi(texto);

        inputFile.close();
    }

    char destino[100];
    strcpy(destino, caminho);
    ofstream saida;

    if (teste) {
        strcat(destino, "/teste.txt");
        saida.open(destino, ios::app);
        saida << endl;
        saida << "-----------------------------------------------------------------" << endl;
        saida << endl;
    }
    else {
        strcat(destino, "/saidaHash.txt");
        saida.open(destino);
    }

    Hash tabelaHash(n/2);

    Track *tracks = lerArquivoBinTrack(caminho, n);
    for (int i = 0; i < n; i++) {
         tabelaHash.insere(tracks[i].getIdArtist(), "1", tracks[i].getArtist());
     }
    int qtde = 0;
    No* vetor = tabelaHash.transformaEmVetor(n, &qtde);
    ordenarMergeDecrescente(vetor, 0, qtde - 1);
    for (int i=0; i<m; i++) {
        saida << "Artista = " << vetor[i].getTexto() << " / Qtde de Músicas = " << vetor[i].getValor();
        Hash tabelaHashMusicas(5);
        for (int j=0; j<n; j++) {
            if (tracks[j].getIdArtist() == vetor[i].getChave()) {
                tabelaHashMusicas.insere(tracks[j].getId(), tracks[j].getPopularity(), tracks[j].getName());
            }
        }
        int qtdeMusicas = 0;
        No* vetorMusicas = tabelaHashMusicas.transformaEmVetor(n, &qtdeMusicas);
        ordenarMergeDecrescente(vetorMusicas, 0, qtdeMusicas - 1);
        saida << " / Música mais popular = " << vetorMusicas[0].getTexto() << endl;
    }

    saida.close();
}

void trabalho2teste(int argc, char *argv[ ]) {
    trabalho2ordenacao(argc, argv, true);
    trabalho2hash(argc, argv, true);
}

void gerarArquivosDat(int argc, char *argv[ ]) {
    char *caminho = argv[1];

    char origemHash[100];
    strcpy(origemHash, caminho);
    strcat(origemHash, "/hash.dat");

    std::ofstream outputFileHash(origemHash, std::ifstream::out | std::ifstream::binary);

    outputFileHash << to_string(10000) << endl;
    outputFileHash << to_string(30) << endl;

    outputFileHash.close();

    char origemSort[100];
    strcpy(origemSort, caminho);
    strcat(origemSort, "/sort.dat");

    std::ofstream outputFileSort(origemSort, std::ifstream::out | std::ifstream::binary);

    outputFileSort << to_string(3) << endl;
    outputFileSort << to_string(10) << endl;
    outputFileSort << to_string(50) << endl;
    outputFileSort << to_string(100) << endl;
    outputFileSort << to_string(500) << endl;
    outputFileSort << to_string(800) << endl;

    outputFileSort.close();
}

void trabalho2(int argc, char *argv[ ]) {

    gerarArquivosDat(argc, argv);

    int opcao;
    printf("Digite 1=Ordenacao / 2=Hash / 3=Teste: ");
    scanf("%d", &opcao);

    if (opcao == 1) {
        trabalho2ordenacao(argc, argv, false);
    }
    else {
        if (opcao == 2) {
            trabalho2hash(argc, argv, false);
        }
        else {
            if (opcao == 3) {
                trabalho2teste(argc, argv);
            }
        }
    }
}

// Fim do trabalho 2


// Inicio trabalho 3

enum Color {RED, BLACK};

struct Node
{
    string artistName;
    string artistId;
    int position;

    bool color;
    Node *left, *right, *parent;

//Construtor

    Node(string artistName, string artistId, int position)
    {
        this->artistName = artistName;
        this->artistId = artistId;
        this->position = position;
        left = right = parent = NULL;
        this->color = RED;
    }
};

//Classe para representar a árvore vermelha-preta

class RBTree
{
private:
    Node *root;
protected:
    void rotateLeft(Node *&, Node *&);
    void rotateRight(Node *&, Node *&);
    void fixViolation(Node *&, Node *&);
public:
    // Construtor
    RBTree() { root = NULL; }
    void insert(string artistName, string artistId, int &position);
    void inorder();
    Node* getRoot();
};

Node* RBTree::getRoot() {
    return root;
}

// Função recursiva para pecorrer em ordem

void inorderHelper(Node *root)
{
    if (root == NULL)
        return;

    inorderHelper(root->left);
    cout << root->artistName << endl;
    inorderHelper(root->right);
}

// função para inserir um nó com a chave fornecida
Node* BSTInsert(Node* root, Node *pt)
{
    // se a arvore estiver vazia retornar um novo nó
    if (root == NULL)
        return pt;

    // Caso contrário, volte a descer na árvore
    if (pt->artistName < root->artistName)
    {
        root->left  = BSTInsert(root->left, pt);
        root->left->parent = root;
    }
    else
    {
        root->right = BSTInsert(root->right, pt);
        root->right->parent = root;
    }

    // retorna o ponteiro do nó
    return root;
}

void RBTree::rotateLeft(Node *&root, Node *&pt)
{
    Node *pt_right = pt->right;

    pt->right = pt_right->left;

    if (pt->right != NULL)
        pt->right->parent = pt;

    pt_right->parent = pt->parent;

    if (pt->parent == NULL)
        root = pt_right;

    else if (pt == pt->parent->left)
        pt->parent->left = pt_right;

    else
        pt->parent->right = pt_right;

    pt_right->left = pt;
    pt->parent = pt_right;
}

void RBTree::rotateRight(Node *&root, Node *&pt)
{
    Node *pt_left = pt->left;

    pt->left = pt_left->right;

    if (pt->left != NULL)
        pt->left->parent = pt;

    pt_left->parent = pt->parent;

    if (pt->parent == NULL)
        root = pt_left;

    else if (pt == pt->parent->left)
        pt->parent->left = pt_left;

    else
        pt->parent->right = pt_left;

    pt_left->right = pt;
    pt->parent = pt_left;
}

void RBTree::fixViolation(Node *&root, Node *&pt)
{
    Node *parent_pt = NULL;
    Node *grand_parent_pt = NULL;

    while ((pt != root) && (pt->color != BLACK) &&
           (pt->parent->color == RED))
    {

        parent_pt = pt->parent;
        grand_parent_pt = pt->parent->parent;

        //O pai do pt é filho esquerdo do avô do pt
        if (parent_pt == grand_parent_pt->left)
        {

            Node *uncle_pt = grand_parent_pt->right;

            //O tio de pt também é vermelho apenas recoloração
            if (uncle_pt != NULL && uncle_pt->color ==
                                    RED)
            {
                grand_parent_pt->color = RED;
                parent_pt->color = BLACK;
                uncle_pt->color = BLACK;
                pt = grand_parent_pt;
            }

            else
            {
                //pt é filho certo de seu pai é necessária rotação para a esquerda
                if (pt == parent_pt->right)
                {
                    rotateLeft(root, parent_pt);
                    pt = parent_pt;
                    parent_pt = pt->parent;
                }

                //pt é filho esquerdo de seu pai rotação à direita necessária
                rotateRight(root, grand_parent_pt);
                swap(parent_pt->color,
                     grand_parent_pt->color);
                pt = parent_pt;
            }
        }
        //O pai do pt é a criança certa do avô do pt
        else
        {
            Node *uncle_pt = grand_parent_pt->left;

            //O tio de pt também é vermelho apenas recoloração
            if ((uncle_pt != NULL) && (uncle_pt->color ==
                                       RED))
            {
                grand_parent_pt->color = RED;
                parent_pt->color = BLACK;
                uncle_pt->color = BLACK;
                pt = grand_parent_pt;
            }
            else
            {
                //pt é filho esquerdo de seu pai rotação à direita
                if (pt == parent_pt->left)
                {
                    rotateRight(root, parent_pt);
                    pt = parent_pt;
                    parent_pt = pt->parent;
                }

                //pt é filho certo de seu pai rotação para a esquerda
                rotateLeft(root, grand_parent_pt);
                swap(parent_pt->color,
                     grand_parent_pt->color);
                pt = parent_pt;
            }
        }
    }

    root->color = BLACK;
}

// Função para inserir um novo nó com dados fornecidos

void RBTree::insert(string artistName, string artistId, int &position)
{
    Node *pt = new Node(artistName, artistId, position);

// Inserção BST normal

    root = BSTInsert(root, pt);

    // corrige as violações da arvore vermelha preta

    fixViolation(root, pt);
}

void RBTree::inorder() {
    inorderHelper(root);
}

Node* searchElement (Node *tree, string val, int *comparacoes) {

    (*comparacoes)++;
    if ((tree == NULL) || (tree->artistName == val)) {
        return tree;
    }
    else {
        (*comparacoes)++;
        if (val < tree->artistName) {
            return searchElement(tree->left, val, comparacoes);
        }
        else {
            return searchElement(tree->right, val, comparacoes);
        }
    }
}


void trabalho3ArvoreVermelhoPreta(int argc, char *argv[ ], bool teste) {
    char *caminho = argv[1];
    Artist artist;
    clock_t startTime;
    long double tempo;
    int comparacoes;

    char destino[100];
    strcpy(destino, caminho);
    strcat(destino, "/saida.txt");
    ofstream saida;
    saida.open(destino);

    RBTree tree;

    char origem[100];
    strcpy(origem, caminho);
    strcat(origem, "/artists.bin");

    std::ifstream inputFile(origem, std::ifstream::in | std::ifstream::binary);

    int i = 0;

    startTime = clock();
    while (inputFile.good()) {

        int posicao = i * sizeof(Artist);
        inputFile.read((char *) &artist, sizeof(Artist));

        tree.insert(artist.getName(), artist.getId(), posicao);

        i++;
    }
    tempo =  double(clock() - startTime) / (double) CLOCKS_PER_SEC;

    cout << "Tempo total de inserção: " << tempo << " segundos" << endl;
    saida << "Tempo total de inserção: " << tempo << " segundos" << endl;

    inputFile.close();


    if (teste) {
        string nomeArtista;

        printf("Digite um nome de artista para pesquisa: ");
        std::getline(std::cin >> std::ws, nomeArtista);

        comparacoes = 0;
        startTime = clock();
        Node* resposta = searchElement(tree.getRoot(), nomeArtista, &comparacoes);
        tempo =  double(clock() - startTime) / (double) CLOCKS_PER_SEC;

        if (resposta == NULL) {
            cout << "Artista não encontrado" << endl;
        }
        else {
            std::ifstream inputFile(origem, std::ifstream::in | std::ifstream::binary);

            Artist artist;
            inputFile.seekg(resposta->position);
            inputFile.read((char *) &artist, sizeof(Artist));
            artist.printArtist();
            cout << resposta->artistName << " - Comparações busca: " << comparacoes << endl;
            cout << resposta->artistName << " - Tempo busca: " << tempo << " segundos" << endl;
            saida << resposta->artistName << " - Comparações busca: " << comparacoes << endl;
            saida << resposta->artistName << " - Tempo busca: " << tempo << " segundos" << endl;
            inputFile.close();
        }
    }
    else {
        int quantidade = 100;
        long double somaTempo = 0;
        long int somaComparacoes = 0;

        Artist *artists = lerArquivoBinArtist(caminho, quantidade);
        for (int j=0; j < quantidade; j++) {
            comparacoes = 0;
            startTime = clock();

            Node* resposta = searchElement(tree.getRoot(), artists[j].getName(), &comparacoes);

            tempo =  double(clock() - startTime) / (double) CLOCKS_PER_SEC;
            somaTempo += tempo;
            somaComparacoes += comparacoes;

            cout << resposta->artistName << " - Comparações busca: " << comparacoes << " - Tempo busca: " << tempo << " segundos" << endl;
            saida << resposta->artistName << " - Comparações busca: " << comparacoes << " - Tempo busca: " << tempo << " segundos" << endl;
        }
        cout << "-------------------------" << endl;
        cout << "Média comparações buscas: " << somaComparacoes / quantidade << endl;
        cout << "Média tempo total buscas: " << somaTempo / quantidade  << " segundos" << endl;
        saida << "-------------------------" << endl;
        saida << "Média comparações buscas: " << somaComparacoes / quantidade << endl;
        saida << "Média tempo total buscas: " << somaTempo / quantidade  << " segundos" << endl;
    }

    saida.close();
}

// Arvore B

struct NodeAux
{
    string artistName;
    string artistId;
    int position;

    NodeAux(string artistName, string artistId, int position)
    {
        this->artistName = artistName;
        this->artistId = artistId;
        this->position = position;
    }
};

// A BTree node
class BTreeNode
{
    NodeAux **keys; // array de chaves
    int t; // numero minimo de chaves
    BTreeNode **C; // array de filhos ponteiros
    int n; // numero atual de chaves
    bool leaf; //retorna verdadeiro para nó folha

public:
    // Construtor

    BTreeNode(int _t, bool _leaf);

    // Uma função de utilidade para inserir uma nova chave na subárvore enraizada com este nó. A suposição é que o nó não deve estar cheio quando esta função é chamada

    void insertNonFull(NodeAux *k);

// Uma função de utilidade para dividir o filho y deste nó. i é um índice de y no array filho C []. O filho y deve estar cheio quando esta função é chamada

    void splitChild(int i, BTreeNode *y);

    // Uma função para percorrer todos os nós em uma subárvore enraizada com este nó

    void traverse();

    // Uma função para pesquisar uma chave na subárvore enraizada com este nó.

    BTreeNode *search(string k, int *comparacoes);   // retorna nulo caso não encontre k.

    NodeAux *getNodeAux(string name);

// Tornar BTree friend para que possamos acessar membros privados desta classe nas funções BTree
    friend class BTree;
};

// A BTree
class BTree
{
    BTreeNode *root; //Ponteiro para o nó raiz
    int t;
public:
    //Construtor
    BTree(int _t)
    {  root = NULL;  t = _t; }

    //Função para percorrer a árvore
    void traverse()
    {  if (root != NULL) root->traverse(); }

    //Função para procurar uma chave na árvore
    BTreeNode* search(string k, int *comparacoes)
    {  return (root == NULL)? NULL : root->search(k, comparacoes); }

    //A função principal que insere uma nova chave nesta árvore
    void insert(NodeAux *k);
};

//Construtor
BTreeNode::BTreeNode(int t1, bool leaf1)
{
    // Copia o numero minimo de chaves
    t = t1;
    leaf = leaf1;

// Alocar memória para o número máximo de chaves possíveis e ponteiros filhos
    keys = new NodeAux *[2*t-1];
    C = new BTreeNode *[2*t];
// Inicializa o número de chaves como 0
    n = 0;
}
// Função para percorrer todos os nós em uma subárvore enraizada com este nó
void BTreeNode::traverse()
{

    // Existem n chaves e n + 1 filhos, atravessa n chaves e os primeiros n filhos
    int i;
    for (i = 0; i < n; i++)
    {
        // Se não for folha, antes de imprimir a chave [i], atravesse a subárvore com raiz no filho C [i].
        if (leaf == false)
            C[i]->traverse();
    }
    // Imprime a subárvore enraizada com o último filho
    if (leaf == false)
        C[i]->traverse();
}
// Função para pesquisar a chave k na subárvore enraizada com este nó
BTreeNode *BTreeNode::search(string k, int *comparacoes)
{

    // Encontre a primeira chave maior ou igual a k
    int i = 0;
    while (i < n && k > keys[i]->artistName) {
        i++;
        (*comparacoes)++;
    }

    (*comparacoes)++;

    // Se a chave encontrada for igual a k, retorne este nó
    if ((keys[i] != NULL) && (keys[i]->artistName == k))
        return this;

    // Se a chave não for encontrada aqui e este for um nó folha
    if (leaf == true)
        return NULL;

    // Vá para a criança apropriada
    return C[i]->search(k, comparacoes);
}

NodeAux *BTreeNode::getNodeAux(string name) {
    int i = 0;
    while (i < n) {
        if (keys[i]->artistName == name)
            return keys[i];
        i++;
    }
    return NULL;
}

// A função principal que insere uma nova chave nesta B-Tree
void BTree::insert(NodeAux *k)
{
    // Se a árvore estiver vazia
    if (root == NULL)
    {
        // Alocar memória para raiz
        root = new BTreeNode(t, true);
        root->keys[0] = k; //inserir chave
        root->n = 1; // Atualizar o número de chaves na raiz
    }
    else // Se a árvore não estiver vazia
    {
        // Se a raiz estiver cheia, a árvore cresce em altura
        if (root->n == 2*t-1)
        {
            BTreeNode *s = new BTreeNode(t, false);

            // Alocar memória para nova raiz
            s->C[0] = root;

            // Divida a raiz antiga e mova 1 chave para a nova raiz
            s->splitChild(0, root);

            // A nova raiz tem dois filhos agora.
            int i = 0;
            if (s->keys[0]->artistName < k->artistName)
                i++;
            s->C[i]->insertNonFull(k);

            //muda raiz
            root = s;
        }
        else // Se a raiz não estiver cheia, chame insertNonFull para a raiz
            root->insertNonFull(k);
    }
}

// Uma função de utilidade para inserir uma nova chave neste nó
void BTreeNode::insertNonFull(NodeAux *k)
{
    // Inicializa o índice como índice do elemento mais à direita
    int i = n-1;

    // Se este for um nó folha
    if (leaf == true)
    {

       // Encontra a localização da nova chave a ser inserida e move todas as chaves maiores para um lugar à frente
        while (i >= 0 && keys[i]->artistName > k->artistName)
        {
            keys[i+1] = keys[i];
            i--;
        }


        // Insira a nova chave no local encontrado
        keys[i+1] = k;
        n = n+1;
    }
    else // Se este nó não for folha
    {
        // Encontre o filho que terá a nova chave
        while (i >= 0 && keys[i]->artistName > k->artistName)
            i--;

        // Veja se a criança encontrada está cheia
        if (C[i+1]->n == 2*t-1)
        {
            // Se o filho estiver cheio, divida-o
            splitChild(i+1, C[i+1]);

            // Após a divisão, a chave do meio de C [i] sobe e C [i] é dividida em duas. Veja qual dos dois terá a nova chave

            if (keys[i+1]->artistName < k->artistName)
                i++;
        }
        C[i+1]->insertNonFull(k);
    }
}


// Uma função de utilidade para dividir o filho y deste nó
void BTreeNode::splitChild(int i, BTreeNode *y)
{

    // Crie um novo nó que irá armazenar (t-1) as chaves de y
    BTreeNode *z = new BTreeNode(y->t, y->leaf);
    z->n = t - 1;

    // Copia as últimas (t-1) chaves de y a z
    for (int j = 0; j < t-1; j++)
        z->keys[j] = y->keys[j+t];

    // Copia os últimos t filhos de y para z
    if (y->leaf == false)
    {
        for (int j = 0; j < t; j++)
            z->C[j] = y->C[j+t];
    }
    // Reduzir o número de chaves em y
    y->n = t - 1;


    for (int j = n; j >= i+1; j--)
        C[j+1] = C[j];

    // vincular o novo filho a esse nó
    C[i+1] = z;


    for (int j = n-1; j >= i; j--)
        keys[j+1] = keys[j];

    // Copie a chave do meio de y para este nó
    keys[i] = y->keys[t-1];

    // Aumentar a contagem de chaves neste nó
    n = n + 1;
}


void trabalho3ArvoreB(int argc, char *argv[ ], bool teste) {
    char *caminho = argv[1];
    Artist artist;
    clock_t startTime;
    long double tempo;
    int comparacoes;
    string nomeArtista;
    int ordem;
    int t[2] = {20, 200};

    ordem = 0;
    while (ordem != 1 && ordem !=2) {
        printf("Digite a ordem mínima da árvore B (1=20 / 2=200): ");
        cin >> ordem;
    }
    ordem--;

    if (teste) {
        printf("Digite um nome de artista para pesquisa: ");
        std::getline(std::cin >> std::ws, nomeArtista);
    }

    char destino[100];
    strcpy(destino, caminho);
    strcat(destino, "/saida.txt");
    ofstream saida;
    saida.open(destino);

    cout << "t = " << t[ordem] << endl;
    saida << "t = " << t[ordem] << endl;

    BTree tree(t[ordem]);

    char origem[100];
    strcpy(origem, caminho);
    strcat(origem, "/artists.bin");

    std::ifstream inputFile(origem, std::ifstream::in | std::ifstream::binary);

    int i = 0;

    startTime = clock();
    while (inputFile.good()) {

        int posicao = i * sizeof(Artist);
        inputFile.read((char *) &artist, sizeof(Artist));

        tree.insert(new NodeAux(artist.getName(), artist.getId(), posicao));

        i++;
    }
    tempo = double(clock() - startTime) / (double) CLOCKS_PER_SEC;

    cout << "Tempo total de inserção: " << tempo << " segundos" << endl;
    saida << "Tempo total de inserção: " << tempo << " segundos" << endl;

    inputFile.close();

    tree.traverse();

    if (teste) {
        comparacoes = 0;
        startTime = clock();
        BTreeNode *resposta = tree.search(nomeArtista, &comparacoes);
        tempo = double(clock() - startTime) / (double) CLOCKS_PER_SEC;

        if (resposta == NULL) {
            cout << "Artista não encontrado" << endl;
        } else {
            NodeAux *node = resposta->getNodeAux(nomeArtista);

            std::ifstream inputFile(origem, std::ifstream::in | std::ifstream::binary);

            Artist artist;
            inputFile.seekg(node->position);
            inputFile.read((char *) &artist, sizeof(Artist));
            artist.printArtist();
            cout << node->artistName << " - Comparações busca: " << comparacoes << endl;
            cout << node->artistName << " - Tempo busca: " << tempo << " segundos" << endl;
            saida << node->artistName << " - Comparações busca: " << comparacoes << endl;
            saida << node->artistName << " - Tempo busca: " << tempo << " segundos" << endl;
            inputFile.close();
        }
    } else {
        int quantidade = 100;
        long double somaTempo = 0;
        long int somaComparacoes = 0;

        Artist *artists = lerArquivoBinArtist(caminho, quantidade);
        for (int j = 0; j < quantidade; j++) {
            comparacoes = 0;
            startTime = clock();

            BTreeNode *resposta = tree.search(artists[j].getName(), &comparacoes);

            tempo = double(clock() - startTime) / (double) CLOCKS_PER_SEC;
            somaTempo += tempo;
            somaComparacoes += comparacoes;

            NodeAux *node = resposta->getNodeAux(artists[j].getName());

            cout << node->artistName << " - Comparações busca: " << comparacoes << " - Tempo busca: " << tempo
                 << " segundos" << endl;
            saida << node->artistName << " - Comparações busca: " << comparacoes << " - Tempo busca: " << tempo
                  << " segundos" << endl;
        }
        cout << "-------------------------" << endl;
        cout << "Média comparações buscas: " << somaComparacoes / quantidade << endl;
        cout << "Média tempo total buscas: " << somaTempo / quantidade << " segundos" << endl;
        saida << "-------------------------" << endl;
        saida << "Média comparações buscas: " << somaComparacoes / quantidade << endl;
        saida << "Média tempo total buscas: " << somaTempo / quantidade << " segundos" << endl;
    }
    saida.close();
}

void trabalho3(int argc, char *argv[ ]) {

    int opcao, ordem,  modo;
    bool teste;
    char* caminho = argv[1];

    if (!verificarArquivoBinArtistExistente(caminho)) {
        gerarArquivoBinArtist(caminho);
    }

    printf("Digite 1=Árvore Vermelho-Preta / 2=Árvore B: ");
    scanf("%d", &opcao);

    printf("Digite 1=Modo de Análise / 2=Modo de Teste: ");
    scanf("%d", &modo);

    if (modo == 1) {
        teste = false;
    }
    else {
        teste = true;
    }

    if (opcao == 1) {
        trabalho3ArvoreVermelhoPreta(argc, argv, teste);
    }
    else {
        if (opcao == 2) {
            trabalho3ArvoreB(argc, argv, teste);
        }
    }
}


// Menu Principal

int main(int argc, char *argv[ ]) {

    //argv[1] = "/Users/juliaaraujo/CLionProjects/dados";

    int trabalho;
    printf("Digite 1=Trabalho1 / 2=Trabalho2 / 3=Trabalho3: ");
    scanf("%d", &trabalho);

    if (trabalho == 1) {
        trabalho1(argc, argv);
    } else {
        if (trabalho == 2) {
            trabalho2(argc, argv);
        } else {
            if (trabalho == 3) {
                trabalho3(argc, argv);
            }
        }

        return 0;
    }

}
