#include "Episode.h"

Episode::Episode(int ID, string title, int season, string length, float rating) : Video(ID, title), season_(season), rating_(rating), length_(length) {}

float Episode::getRating() {
    return rating_;
}

int Episode::getSeason() {
    return season_;
}

string Episode::getLength() {
    return length_;
}

void Episode::setRating(float rating) {
    rating_ = rating;
}