#ifndef DBCBE8CF_4DDC_4C09_8FE8_5D2EC2CEE13A
#define DBCBE8CF_4DDC_4C09_8FE8_5D2EC2CEE13A

#include <iostream>
#include <string>

#include "const.h"
#include <fstream>

using namespace std;

class Artist {
private:
    char id[ARTIST_ID_SIZE];
    char followers[ARTIST_FOLLOWERS];
    char genre[ARTIST_GENRE_SIZE];
    char name[ARTIST_NAME];
    char popularity[ARTIST_POPULARITY];

public:
    Artist();

    Artist(char* id, char* followers, char* genre, char* name, char* popularity);

    string getId();

    string getName();

    string getFollowers();

    void printArtist();

    void binarySave(ofstream &OUT_FILE);

    void textSave(ofstream &OUT_FILE);

    int size();

    };

#endif