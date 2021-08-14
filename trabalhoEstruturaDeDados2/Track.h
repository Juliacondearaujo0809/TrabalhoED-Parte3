#ifndef C0A4E5D4_463B_41BC_8C19_A1A6EC2BAF03
#define C0A4E5D4_463B_41BC_8C19_A1A6EC2BAF03

#include <iostream>
#include <string>

#include "const.h"
#include <fstream>

using namespace std;

class Track{

private:
    char id[TRACK_ID];
    char name[TRACK_NAME];
    char artist[TRACK_ARTIST_NAME];
    char id_artist[TRACK_ARTIST_ID_SIZE];
    char release_date[TRACK_DATE];
    char isExp[TRACK_ISEXP];
    char popularity[TRACK_POPULARITY];
    char duration[TRACK_DURATION];
    char key[TRACK_KEY];
    char mode[TRACK_MODE];
    char time_signature[TRACK_TIME_SIGNATURE];
    char speechiness[TRACK_SPEECHINESS];
    char acousticness[TRACK_ACOUSTICNESS];
    char instrumentalness[TRACK_INSTRUMENTALNESS];
    char liveness[TRACK_LIVENESS];
    char valence[TRACK_VALENCE];
    char tempo[TRACK_TEMPO];
    char loudness[TRACK_LOUDNESS];
    char danceability[TRACK_DANCEABILITY];
    char energy[TRACK_ENERGY];

public:
    Track();

    Track(char *id, char *name, char *artist, char *id_artist, char *release_date, char *isExp, char *popularity,
          char *duration, char *danceability, char *energy, char *key, char *loudness, char *mode, char *speechiness,
          char *acousticness, char *instrumentalness, char *liveness, char *valence, char *tempo, char *time_signature);

    string getIdArtist();

    string getArtist();

    string getId();

    string getName();

    string getPopularity();

    void printTrack();

    void binarySave(ofstream &OUT_FILE);

    void textSave(ofstream &OUT_FILE);

    int size();

};

#endif