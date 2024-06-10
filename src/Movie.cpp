#include "Movie.h"

Movie::Movie(int ID, string title, float rating, string length, Genre genre) : Video(ID, title), length_(length), genre_(genre), rating_(rating) {}

float Movie::getRating() {
    return rating_;
}

string Movie::getLength() {
    return length_;
}

Genre Movie::getGenre() {
    return genre_;
}