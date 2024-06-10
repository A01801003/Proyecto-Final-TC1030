#include "Video.h"

Video::Video(int ID, string title) : ID_(ID), title_(title) {}

string Video::getTitle() {
    return title_;
}