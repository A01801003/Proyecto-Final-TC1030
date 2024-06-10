#include "Genre.h"

string genreToString(Genre genre){
    switch(genre){
        case DRAMA:
            return "Drama";
        case ACTION:
            return "Action";
        case MYSTERY:
            return "Mystery";
        default:
            return "Unknown";
    }
}

Genre stringToGenre(string genre){
    if(genre == "Drama"){
        return DRAMA;
    } else if(genre == "Action"){
        return ACTION;
    } else if(genre == "Mystery"){
        return MYSTERY;
    } else {
        return UNKNOWN;
    }
}