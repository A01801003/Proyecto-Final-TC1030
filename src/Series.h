#ifndef SERIES_H
#define SERIES_H

#include "Video.h"
#include "Episode.h"
#include "Genre.h"
#include <vector>

class Series : public Video
{
  private:
    vector<Episode> episodes_;
    Genre genre_;
  public:
    Series(int ID, string title, Genre genre);
    float getRating() override;
    Genre getGenre();
    vector<Episode> getEpisodes();
    void addEpisode(Episode episode);
};

#endif