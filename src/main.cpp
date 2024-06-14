#include <iostream>
#include "VideoEngine.h"

using namespace std;

void displayMenu() {
    cout << "\nMenu:\n";
    cout << "1. Show all movies\n";
    cout << "2. Show all series\n";
    cout << "3. Show videos with a specific rating or genre\n";
    cout << "4. Show episodes of a specific series with a specific rating\n";
    cout << "5. Show movies with a specific rating\n";
    cout << "6. Rate a video\n";
    cout << "7. Exit\n";
    cout << "Enter your choice: ";
}

int main() {
    VideoEngine engine;
    engine.loadVideos("dataBase.txt");
    
    int choice;
    while (true) {
        displayMenu();
        cin >> choice;

        if (choice == 7) {
            break;
        }

        switch (choice) {
            case 1:
                engine.printMovies();
                break;
            case 2:
                engine.printSeries();
                break;
            case 3: {
                string genreOrRating;
                cout << "Enter genre or rating (input a genre name or a float from 0 to 5): ";
                cin >> genreOrRating;
                if (genreOrRating == "Drama" || genreOrRating == "Mystery" || genreOrRating == "Action") {
                    engine.filterVideosByGenre(genreOrRating);
                } else {
                    float rating = stof(genreOrRating);
                    engine.filterVideosByRating(rating);
                }
                break;
            }
            case 4: {
                string seriesTitle;
                float rating;
                cout << "Enter series title: ";
                cin.ignore();
                getline(cin, seriesTitle);
                cout << "Enter rating: ";
                cin >> rating;
                engine.filterEpisodesByRating(seriesTitle, rating);
                break;
            }
            case 5: {
                float rating;
                cout << "Enter rating: ";
                cin >> rating;
                engine.filterMoviesByRating(rating);
                break;
            }
            case 6: {
                try {
                    string title;
                    float rating;
                    cout << "Enter title of the video: ";
                    cin.ignore();
                    getline(cin, title);
                    cout << "Enter rating: ";
                    cin >> rating;
                    if (rating > 5 || rating < 0) {
                        throw invalid_argument("Invalid rating. Rating should be between 0 and 5.");
                    } else {
                        engine.rateVideo(title, rating);
                    }

                } catch (const std::exception& e) {
                    std::cerr << e.what() << '\n';
                }
                break;
            }
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
        cout << "Type y to continue: ";
        
        try {
            string input;
            cin >> input;
            if (input != "y") {
                throw invalid_argument("Invalid input. Exiting the program.");
            }
        } catch (const std::exception& e) {
            std::cerr << e.what() << '\n';
            break;
        }
    }
    return 0;
}