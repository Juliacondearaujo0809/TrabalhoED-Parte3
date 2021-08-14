#include <string.h>
#include "Track.h"

Track::Track() {

}

Track::Track(char *id, char *name, char *artist, char *id_artist, char *release_date, char *isExp, char *popularity,
             char *duration, char *danceability, char *energy, char *key, char *loudness, char *mode, char *speechiness,
             char *acousticness, char *instrumentalness, char *liveness, char *valence, char *tempo, char *time_signature){
    strcpy(this->id, id);
    strcpy(this->name, name);
    strcpy(this->artist, artist);
    strcpy(this->id_artist, id_artist);
    strcpy(this->release_date, release_date);
    strcpy(this->isExp, isExp);
    strcpy(this->popularity, popularity);
    strcpy(this->duration, duration);
    strcpy(this->danceability, danceability);
    strcpy(this->energy, energy);
    strcpy(this->key, key);
    strcpy(this->loudness, loudness);
    strcpy(this->mode, mode);
    strcpy(this->speechiness, speechiness);
    strcpy(this->acousticness, acousticness);
    strcpy(this->instrumentalness, instrumentalness);
    strcpy(this->liveness, liveness);
    strcpy(this->valence, valence);
    strcpy(this->tempo, tempo);
    strcpy(this->time_signature, time_signature);
}

string Track::getIdArtist() {
    return this->id_artist;
}

string Track::getArtist() {
    return this->artist;
}

string Track::getId() {
    return this->id;
}

string Track::getName() {
    return this->name;
}

string Track::getPopularity() {
    if ((strlen(this->popularity) == 0) || (!isdigit(this->popularity[0])))
        return "0";
    else
        return this->popularity;
}

void Track::printTrack(){
    cout<<"----------------------------------------------------------------"<<endl;
    cout<<"Music ID--> ";
    cout<<this->id<<endl;
    cout<<"Music Name--> ";
    cout<<this->name<<endl;
    cout<<"Music Artist--> ";
    cout<<this->artist<<endl;
    cout<<"Music Id Artist--> ";
    cout<<this->id_artist<<endl;
    cout<<"Music Release Date--> ";
    cout<<this->release_date<<endl;
    cout<<"Is the Music Explicit--> ";
    cout<<this->isExp<<endl;
    cout<<"Music Popularity--> ";
    cout<<this->popularity<<endl;
    cout<<"Music Duration (ms)--> ";
    cout<<this->duration<<endl;
    cout<<"Music Danceability--> ";
    cout<<this->danceability<<endl;
    cout<<"Music Energy--> ";
    cout<<this->energy<<endl;
    cout<<"Music Key--> ";
    cout<<this->key<<endl;
    cout<<"Music Loudness--> ";
    cout<<this->loudness<<endl;
    cout<<"Music Mode--> ";
    cout<<this->mode<<endl;
    cout<<"Music Speechiness--> ";
    cout<<this->speechiness<<endl;
    cout<<"Music Acousticness--> ";
    cout<<this->acousticness<<endl;
    cout<<"Music Instrumentalness--> ";
    cout<<this->instrumentalness<<endl;
    cout<<"Music Liveness--> ";
    cout<<this->liveness<<endl;
    cout<<"Music Valence--> ";
    cout<<this->valence<<endl;
    cout<<"Music Tempo--> ";
    cout<<this->tempo<<endl;
    cout<<"Music Time Signature--> ";
    cout<<this->time_signature<<endl;
    cout<<"----------------------------------------------------------------"<<endl;
}

void Track::binarySave(ofstream &OUT_FILE){
    (OUT_FILE).write((char*)this->id, TRACK_ID*sizeof(char));
    (OUT_FILE).write((char*)this->name, TRACK_NAME*sizeof(char));
    (OUT_FILE).write((char*)this->artist, TRACK_ARTIST_NAME*sizeof(char));
    (OUT_FILE).write((char*)this->id_artist, TRACK_ARTIST_ID_SIZE*sizeof(char));
    (OUT_FILE).write((char*)this->release_date, TRACK_DATE*sizeof(char));
    (OUT_FILE).write((char*)this->isExp, TRACK_ISEXP*sizeof(char));
    (OUT_FILE).write((char*)this->popularity, TRACK_POPULARITY*sizeof(char));
    (OUT_FILE).write((char*)this->duration, TRACK_DURATION*sizeof(char));
    (OUT_FILE).write((char*)this->danceability, TRACK_DANCEABILITY*sizeof(char));
    (OUT_FILE).write((char*)this->energy, TRACK_ENERGY*sizeof(char));
    (OUT_FILE).write((char*)this->key, TRACK_KEY*sizeof(char));
    (OUT_FILE).write((char*)this->loudness, TRACK_LOUDNESS*sizeof(char));
    (OUT_FILE).write((char*)this->mode, TRACK_MODE*sizeof(char));
    (OUT_FILE).write((char*)this->speechiness, TRACK_SPEECHINESS*sizeof(char));
    (OUT_FILE).write((char*)this->acousticness, TRACK_ACOUSTICNESS*sizeof(char));
    (OUT_FILE).write((char*)this->instrumentalness, TRACK_INSTRUMENTALNESS*sizeof(char));
    (OUT_FILE).write((char*)this->liveness, TRACK_LIVENESS*sizeof(char));
    (OUT_FILE).write((char*)this->valence, TRACK_VALENCE*sizeof(char));
    (OUT_FILE).write((char*)this->tempo, TRACK_TEMPO*sizeof(char));
    (OUT_FILE).write((char*)this->time_signature, TRACK_TIME_SIGNATURE*sizeof(char));
}

void Track::textSave(ofstream &OUT_FILE){
    OUT_FILE<<this->id<<", ";
    OUT_FILE<<this->name<<", ";
    OUT_FILE<<this->artist<<", ";
    OUT_FILE<<this->id_artist<<", ";
    OUT_FILE<<this->release_date<<", ";
    OUT_FILE<<this->isExp<<", ";
    OUT_FILE<<this->popularity<<", ";
    OUT_FILE<<this->duration<<"ms"<<", ";
    OUT_FILE<<this->danceability<<", ";
    OUT_FILE<<this->energy<<", ";
    OUT_FILE<<this->key<<", ";
    OUT_FILE<<this->loudness<<", ";
    OUT_FILE<<this->mode<<", ";
    OUT_FILE<<this->speechiness<<", ";
    OUT_FILE<<this->acousticness<<", ";
    OUT_FILE<<this->instrumentalness<<", ";
    OUT_FILE<<this->liveness<<", ";
    OUT_FILE<<this->valence<<", ";
    OUT_FILE<<this->tempo<<", ";
    OUT_FILE<<this->time_signature<<endl;
}

int Track::size(){
    return ((TRACK_ID + TRACK_ISEXP + TRACK_POPULARITY + TRACK_DURATION + TRACK_KEY + TRACK_MODE + TRACK_TIME_SIGNATURE +
    TRACK_SPEECHINESS + TRACK_ACOUSTICNESS + TRACK_INSTRUMENTALNESS + TRACK_LIVENESS + TRACK_VALENCE +
    TRACK_TEMPO + TRACK_LOUDNESS + TRACK_DANCEABILITY + TRACK_ENERGY +
    TRACK_ARTIST_NAME + TRACK_ARTIST_ID_SIZE + TRACK_DATE + TRACK_NAME)*sizeof(char));
}

