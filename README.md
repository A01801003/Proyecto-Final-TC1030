# Proyecto-Final-TC1030
This is our team's final project for the Object Oriented Programming class. We created a program that can display and manage information concerning different types of videos. For easier implementation we made use of object oriented programming practices such as dividing the code in headers and c++ files, use of inheritance, polymorphism and operator overloading. The user interacts with the program through the terminal with standard inputs and outputs.

The program reads dataBase.txt to extract the information of the videos. If modifying this file make sure to add videos using the same format as the other ones.
movie (ID) (title) (duration) (genre) (rating)
series (ID) (title) (genre)
episode (ID) (title) (season) (duration) (rating)

to compile run:
g++ main.cpp Episode.cpp Movie.cpp Series.cpp Video.cpp VideoEngine.cpp Genre.cpp -o executable

to execute the code run:
.\executable.exe