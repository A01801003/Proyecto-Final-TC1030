#ifndef GENRE_H
#define GENRE_H

#include <iostream>
using namespace std;

enum Genre{
    DRAMA,
    ACTION,
    MYSTERY,
    UNKNOWN
};

string genreToString(Genre genre);

Genre stringToGenre(string genre);

#endif