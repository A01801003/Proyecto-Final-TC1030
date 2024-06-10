#ifndef EPISODE_H
#define EPISODE_H

#include "Video.h"

class Episode : public Video
{
  private:
    int season_;
    string length_;
    float rating_;
  public:
    Episode(int ID, string title, int season, string length_, float rating);
    float getRating() override;
    int getSeason();
    string getLength();
};

#endif