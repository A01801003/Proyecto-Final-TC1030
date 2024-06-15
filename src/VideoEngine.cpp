#include "VideoEngine.h"

void VideoEngine::printMovies() {
    for (Movie movie : movies_) {
        cout << movie.getTitle() << " (" << genreToString(movie.getGenre()) << ") - " << movie.getRating() << "/5" << " - " << movie.getLength() << endl;
    }
}

void VideoEngine::printSeries() {
    for (Series series : series_) {
        cout << series.getTitle() << " (" << genreToString(series.getGenre()) << ") " << series.getRating() << endl;
        for (Episode episode : series.getEpisodes()) {
            cout << "  " << episode.getTitle() << " - " << episode.getRating() << "/5" << " - season " << episode.getSeason() << " - " << episode.getLength() << endl;
        }
    }
}

vector<string> VideoEngine::split(string& str, char delimiter) {
    vector<string> tokens;
    stringstream ss(str);
    string token;
    while (getline(ss, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

void VideoEngine::loadVideos(string filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error opening file." << endl;
    }

    string line;
    string videoType;
    while (getline(file, line)) {
        // Skip empty lines
        if (line.empty()) {
            continue;
        }

        // Split the line into tokens based on spaces
        vector<string> tokens = split(line, ' ');
        // Process the tokens
        if (tokens[0] == "movie") {
            int ID = stoi(tokens[1]);
            string title = tokens[2];
            string duration = tokens[3];
            string genreStr = tokens[4];
            float rating = stof(tokens[5]);
            Movie movie(ID, title, rating, duration, stringToGenre(genreStr));
            movies_.push_back(movie);
        } else if (tokens[0] == "series") {
            int ID = stoi(tokens[1]);
            string title = tokens[2];
            string genreStr = tokens[3];
            Series series(ID, title, stringToGenre(genreStr));
            series_.push_back(series);
        } else if (tokens[0] == "episode") {
            int ID = stoi(tokens[1]);
            string title = tokens[2];
            int season = stoi(tokens[3]);
            string duration = tokens[4];
            float rating = stof(tokens[5]);
            Episode episode(ID, title, season, duration, rating);
            series_.back() + episode;
        }
    }

    file.close();
}

void VideoEngine::filterVideosByGenre(string genre) {
    for (Movie movie : movies_) {
        if (genreToString(movie.getGenre()) == genre) {
            cout << movie.getTitle() << " (" << genreToString(movie.getGenre()) << ") - " << movie.getRating() << "/5" << " - " << movie.getLength() << endl;
        }
    }

    for (Series series : series_) {
        if (genreToString(series.getGenre()) == genre) {
            cout << series.getTitle() << " (" << genreToString(series.getGenre()) << ") " << series.getRating() << endl;
            for (Episode episode : series.getEpisodes()) {
                cout << "  " << episode.getTitle() << " - " << episode.getRating() << "/5" << " - season " << episode.getSeason() << " - " << episode.getLength() << endl;
            }
        }
    }
}

void VideoEngine::filterVideosByRating(float rating) {
    for (Movie movie : movies_) {
        if (movie.getRating() == rating) {
            cout << movie.getTitle() << " (" << genreToString(movie.getGenre()) << ") - " << movie.getRating() << "/5" << " - " << movie.getLength() << endl;
        }
    }

    for (Series series : series_) {
        for (Episode episode : series.getEpisodes()) {
            if (episode.getRating() == rating) {
                cout << series.getTitle() << " (" << genreToString(series.getGenre()) << ") " << series.getRating() << endl;
                cout << "  " << episode.getTitle() << " - " << episode.getRating() << "/5" << " - season " << episode.getSeason() << " - " << episode.getLength() << endl;
            }
        }
    }
}

void VideoEngine::filterEpisodesByRating(string seriesTitle, float rating) {
    for (Series series : series_) {
        if (series.getTitle() == seriesTitle) {
            cout << series.getTitle() << " (" << genreToString(series.getGenre()) << ") " << series.getRating() << endl;
            for (Episode episode : series.getEpisodes()) {
                if (episode.getRating() == rating) {
                    cout << "  " << episode.getTitle() << " - " << episode.getRating() << "/5" << " - season " << episode.getSeason() << " - " << episode.getLength() << endl;
                }
            }
        }
    }
}

void VideoEngine::rateVideo(string title, float rating) {
    for (Movie& movie : movies_) {
        if (movie.getTitle() == title) {
            movie.setRating(rating);
            return;
        }
    }

    for (Series& series : series_) {
        for (Episode& episode : series.getEpisodes()) {
            if (episode.getTitle() == title) {
                episode.setRating(rating);
                return;
            }
        }
    }
}

void VideoEngine::filterMoviesByRating(float rating) {
    for (Movie movie : movies_) {
        if (movie.getRating() == rating) {
            cout << movie.getTitle() << " (" << genreToString(movie.getGenre()) << ") - " << movie.getRating() << "/5" << " - " << movie.getLength() << endl;
        }
    }
}