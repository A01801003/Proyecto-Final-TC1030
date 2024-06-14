#ifndef VIDEOENGINE_H
#define VIDEOENGINE_H

#include "Video.h"
#include "Movie.h"
#include "Series.h"
#include "Genre.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

class VideoEngine
{
  private:
    vector<Movie> movies_;
    vector<Series> series_;
  public:
    void printMovies();
    void printSeries();
    void printByTitle(string title);
    vector<string> split(string& str, char delimiter);
    void loadVideos(string filename);
    void filterVideosByGenre(string genre);
    void filterVideosByRating(float rating);
    void filterEpisodesByRating(string seriesTitle, float rating);
    void rateVideo(string title, float rating);
    void filterMoviesByRating(float rating);
};

#endif