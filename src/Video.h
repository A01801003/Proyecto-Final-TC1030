#ifndef VIDEO_H
#define VIDEO_H

#include "Genre.h"

class Video
{
  private:
    int ID_;
    string title_;
  public:
    Video(int ID, string title);
    virtual float getRating() = 0;
    string getTitle();
};

#endif