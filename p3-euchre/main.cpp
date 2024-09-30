//

//  main.cpp
#include <iostream>
#include "Player.hpp"
#include "Card.hpp"
#include "Pack.hpp"
#include<vector>
#include <cassert>
#include <array>
#include "euchre.cpp"
#include <fstream>

using namespace std;
int main(int argc, const char * argv[]) {

        cout << argv[4] << " " << argv[5];

        if(argc != 12){

            cout << "Usage: euchre.exe PACK_FILENAME [shuffle|noshuffle] "

            << "POINTS_TO_WIN NAME1 TYPE1 NAME2 TYPE2 NAME3 TYPE3 "

            << "NAME4 TYPE4" << endl;

            return 1;

            

        }

        

        if (*argv[4] < 0 || *argv[4] > 100){

            cout << "Usage: euchre.exe PACK_FILENAME [shuffle|noshuffle] "

            << "POINTS_TO_WIN NAME1 TYPE1 NAME2 TYPE2 NAME3 TYPE3 "

            << "NAME4 TYPE4" << endl;

            return 2;

        }

        if(!strcmp(argv[2], "noshuffle") && !strcmp(argv[2], "shuffle")){

            cout << "Usage: euchre.exe PACK_FILENAME [shuffle|noshuffle] "

            << "POINTS_TO_WIN NAME1 TYPE1 NAME2 TYPE2 NAME3 TYPE3 "

            << "NAME4 TYPE4" << endl;

            return 3;

        }

        if((strcmp(argv[5], "Simple") && !strcmp(argv[5], "Human")) || (!strcmp(argv[7], "Simple") && !strcmp(argv[7], "Human")) || (!strcmp(argv[9], "Simple") && !strcmp(argv[9], "Human"))) {

            cout << "Usage: euchre.exe PACK";
            }
}