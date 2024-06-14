#ifndef MOVIE_H
#define MOVIE_H

#include "Video.h"

class Movie : public Video
{
  private:
    string length_;
    Genre genre_;
    float rating_;
  public:
    Movie(int ID, string title, float rating, string length, Genre genre);
    float getRating() override;
    string getLength();
    Genre getGenre();
    void setRating(float rating);
};

#endif