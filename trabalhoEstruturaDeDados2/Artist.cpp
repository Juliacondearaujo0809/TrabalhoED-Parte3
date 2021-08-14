
#include <string.h>
#include "Artist.h"

Artist::Artist() {

}

Artist::Artist(char* id, char* followers, char* genre, char* name, char* popularity) {
    strcpy(this->id, id);
    strcpy(this->followers, followers);
    strcpy(this->genre, genre);
    strcpy(this->name, name);
    strcpy(this->popularity, popularity);
}


string Artist::getId() {
    return this->id;
}

string Artist::getName() {
    return this->name;
}

string Artist::getFollowers() {
    if ((strlen(this->followers) == 0) || (!isdigit(this->followers[0])))
        return "0";
    else
        return this->followers;
}

void Artist::printArtist() {
    cout<<"----------------------------------------------------------------"<<endl;
    cout<<"Artist:"<<endl;
    cout<<"ID--> ";
    cout<<this->id<<endl;
    cout<<"Followers--> ";
    cout<<this->followers<<endl;
    cout<<"Genres--> ";
    cout<<this->genre<<endl;
    cout<<"Name--> ";
    cout<<this->name<<endl;
    cout<<"Popularity--> ";
    cout<<this->popularity<<endl;
    cout<<"----------------------------------------------------------------"<<endl;
}

void Artist::binarySave(ofstream &OUT_FILE) {
    (OUT_FILE).write((char*)this->id, ARTIST_ID_SIZE * sizeof(char));
    (OUT_FILE).write((char*)this->followers, ARTIST_FOLLOWERS * sizeof(char));
    (OUT_FILE).write((char*)this->genre, ARTIST_GENRE_SIZE * sizeof(char));
    (OUT_FILE).write((char*)this->name, ARTIST_NAME * sizeof(char));
    (OUT_FILE).write((char*)this->popularity, ARTIST_POPULARITY * sizeof(char));
}

void Artist::textSave(ofstream &OUT_FILE) {
    OUT_FILE<<this->id<<",";
    OUT_FILE<<this->genre<<",";
    OUT_FILE<<this->name<<",";
    OUT_FILE<<this->followers<<",";
    OUT_FILE<<this->popularity<<endl;
}


int Artist::size() {
    return ((ARTIST_FOLLOWERS + ARTIST_POPULARITY + ARTIST_ID_SIZE + ARTIST_GENRE_SIZE + ARTIST_NAME)*sizeof(char));
}

