#include "Series.h"

Series::Series(int ID, string title, Genre genre) : Video(ID, title), genre_(genre) {}

float Series::getRating() {
    float totalRating = 0;
    for (Episode episode : episodes_) {
        totalRating += episode.getRating();
    }
    return totalRating / episodes_.size();
}

void Series::addEpisode(Episode episode) {
    episodes_.push_back(episode);
}

Genre Series::getGenre() {
    return genre_;
}

vector<Episode> Series::getEpisodes() {
    return episodes_;
}