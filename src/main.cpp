#include <iostream>
#include "VideoEngine.h"

using namespace std;

int main() {
    /*
    TODO: USER INTERFACE
    
    Load data file.
    Show the videos with a specific rating or from a specific genre.
    Show the episodes of a specific series with a specific rating.
    Show the movies with a specific rating.
    Rate a video.
    Ask for the title to rate.
    Ask for the rating.
    Exit
    */
    VideoEngine engine;
    engine.loadVideos("dataBase.txt");
    engine.printMovies();
    engine.printSeries();
    return 0;
}