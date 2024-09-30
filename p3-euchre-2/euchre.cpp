#include <iostream>
#include <ostream>
#include <fstream>
#include <string>
#include <cstring>
#include "Card.hpp"
#include "Pack.hpp"
#include "Player.hpp"
using namespace std;

// class Game {
//  public:
//   Game(Pack pack, bool shuffle, int pts_to_win, vector<Player*> players)
//   :pack(pack), shuffle(shuffle), pts_to_win(pts_to_win), players(players){}
//     // void deletePlayers(){
//     //     for (size_t i = 0; i < players.size(); ++i) {
//     //       delete players[i];
//     //     }
//     // }
//     void play(){
//         team_one_pts = 0;
//         team_two_pts = 0;
//         team_one.push_back(players.at(0));
//         team_two.push_back(players.at(1));
//         team_one.push_back(players.at(2));
//         team_two.push_back(players.at(3));
//         int x = 0;
//         while (team_one_pts < pts_to_win && team_two_pts < pts_to_win){
//             //for(int x = 0; x<5; x++){
//                 cout << "Hand " << x << endl;
//                 cout << *players.at(0) << " deals"<< endl;
//                 int one_wins = 0;
//                 int two_wins = 0;
//                 int teamDealing = 0;
//                 //shuffle & deal
//                 Card upcard = shuffle_and_deal(shuffle);
//                 cout << upcard << " turned up"<< endl;
//                 Suit upcardsuit = upcard.get_suit();
//                 // make trump
//                 make_trumpGame(players, upcard, upcardsuit, teamDealing);
//                 //trick playing
//                 int leader_indx = 1;
//                 for(int i = 0 ; i< 5; i++){
//                     play_trick(one_wins, two_wins, leader_indx);
//                 }
//                 vector<Player*> winning_team;
//                 if (one_wins> two_wins){
//                     winning_team = team_one;
//                 }else{
//                     winning_team = team_two;
//                 }
//                 cout << *winning_team.at(0) << " and "
//                  << *winning_team.at(1) << " win the hand" <<endl;
//                 // scoring
//                 scoring(one_wins, two_wins, teamDealing);
//                 cout << *team_one.at(0) << " and " << *team_one.at(1) << 
//                 " have " <<team_one_pts<< " points" <<endl;
//                 cout << *team_two.at(0) << " and " << *team_two.at(1) << 
//                 " have " <<team_two_pts<< " points" <<endl << endl;
//                 new_dealer();
//             x++;
//           //  }
//         }
//         if (team_one_pts>= pts_to_win){
//             cout << *team_one.at(0) << " and "<< *team_one.at(1) << " win!"<<endl;
//         }else{
//             cout << *team_two.at(0) << " and "<< *team_two.at(1) << " win!"<<endl;
//         }
//     }



//  private:


//   Pack pack;

//   bool shuffle;

//   int team_one_pts, team_two_pts, pts_to_win;

//   std::vector<Player*> players, team_one, team_two;

//   Suit trump;

//     void scoring(int one_wins, int two_wins, int teamDealing){
//             if(one_wins >=3 && one_wins<5 && teamDealing ==1){
//                 team_one_pts++;
//             } else if(two_wins >=3 && two_wins<5 && teamDealing ==1){
//                 team_one_pts++;
//             }






//         if( (one_wins >= 3) && (one_wins < 5)&& (teamDealing == 1)){
//                     team_one_pts +=1;
//                 }else if((two_wins >= 3) && (two_wins < 5)&& (teamDealing == 2)){
//                     team_two_pts++;
//                 }else if(one_wins == 5 && teamDealing ==1){
//                     team_one_pts +=2;
//                     cout << "march!"<<endl;
//                 }else if(two_wins == 5 && teamDealing ==2){
//                     team_two_pts +=2;
//                     cout << "march!"<<endl;
//                 }else if (one_wins >=3 && teamDealing == 2){
//                     team_one_pts +=2;
//                     cout << "euchred!"<<endl;
//                 }else if(two_wins >=3 && teamDealing == 1){
//                     team_two_pts +=2;
//                     cout << "euchred!"<<endl;
//                 }
//     }

//     Card shuffle_and_deal(bool shuffle){
//         pack.reset();

//         if(shuffle == true){

//             pack.shuffle();

//         }

//         players.at(1)->add_card(pack.deal_one());
//         players.at(1)->add_card(pack.deal_one());
//         players.at(1)->add_card(pack.deal_one());
//         players.at(2)->add_card(pack.deal_one());
//         players.at(2)->add_card(pack.deal_one());
//         players.at(3)->add_card(pack.deal_one());
//         players.at(3)->add_card(pack.deal_one());
//         players.at(3)->add_card(pack.deal_one());
//         players.at(0)->add_card(pack.deal_one());
//         players.at(0)->add_card(pack.deal_one());
//         players.at(1)->add_card(pack.deal_one());
//         players.at(1)->add_card(pack.deal_one());
//         players.at(2)->add_card(pack.deal_one());
//         players.at(2)->add_card(pack.deal_one());
//         players.at(2)->add_card(pack.deal_one());
//         players.at(3)->add_card(pack.deal_one());
//         players.at(3)->add_card(pack.deal_one());
//         players.at(0)->add_card(pack.deal_one());
//         players.at(0)->add_card(pack.deal_one());
//         players.at(0)->add_card(pack.deal_one());

//         Card upcard = pack.deal_one();

//        // pack.reset();

//         return upcard;

//     }

  
//   void new_dealer(){

//     players.push_back(players.at(0));

//     players.erase(players.begin());

//     pack.reset();

//   }
//     void play_trick(int &one_wins, int &two_wins ,int &leader_indx){
//         vector<Card> cards_played;
//                     Card led = players.at(leader_indx)->lead_card(trump);
//                     cout << led << " led by " << *players.at(leader_indx) <<endl;
//                     cards_played.push_back(led);
//                     int currplayer = (leader_indx + 1)%4;
//                     for(int i = 0; i<3; i++){
//                         if(currplayer == 4){
//                             currplayer = 0;
//                         }
//                         Card played = players.at(currplayer)->play_card(led, trump);
//                         cards_played.push_back(played);
//                         cout << played << " played by " << *players.at(currplayer) <<endl;
//                         currplayer++;
//                     }
//                     Player* winner = won_round(leader_indx, led, cards_played);
//                     cout << *winner << " takes the trick"<<endl <<endl;
//                     int team = check_team(winner);
//                     if(team == 1){
//                         one_wins++;
//                     }else{
//                         two_wins++;
//                     }
//                     int winnerindx = 0;
//                     for(int a = 0; a<4; a++){
//                         if (players.at(a) == winner){
//                             winnerindx = a;
//                         }
//                     }
//                     leader_indx = winnerindx;
//     }
//     void make_trumpGame(std::vector<Player*> players, 
//     Card &upcard, Suit &orderUpSuit, int &team){

//         int round = 1;

//         int i = 1;

//         bool isDealer = false;

//         while(!players[i]->make_trump(upcard, isDealer,
//                                       round, orderUpSuit)){
//             cout << *players[i] << " passes" << endl;
//             i++;
//             if (i > 3){
//                 i = 0;
//                 isDealer = true;
//             }else{
//                 isDealer = false;
//             }
//             if (i == 1){
//                 round++ ;
//             }
            
//         }
//         team = check_team(players.at(i));
//         cout << *players[i] << " orders up " << orderUpSuit << endl << endl;
//         trump = orderUpSuit;
//         if (round == 1){
//             players[0]->add_and_discard(upcard);
//         }
//     }
   
//   Player* won_round(int &leader_indx, Card led_card, vector<Card> played_cards){

//     int highestindx =0;
//       int counter = 0;

//     Card highest = played_cards.at(0);
//     for(int  i =1; i < 4; i++){
//         if(Card_less(highest, played_cards.at(i), played_cards.at(0), trump)){
//             highest = played_cards.at(i);
//             highestindx = i;
//         }
//     }
//      // cout << played_cards[0].get_suit() << "        ";
//       for(int i = 1; i < 4; ++i){
//           if(played_cards[i].get_suit(trump) == played_cards[0].get_suit(trump) 
//           && (played_cards[i].get_suit(trump) != trump) && 
//           (played_cards[0].get_suit(trump)!= trump)){
//               //cout << played_cards[i].get_suit() << " " << i << "  ";
//               counter++;
//           }
//       }
//       //cout << counter;
//       if(counter == 0){
//           return players.at(leader_indx);
          
//       }

//     for (int i = 1; i< 4; i++){

//         if(Card_less(highest, played_cards.at(i), led_card, trump)){

//             highest = played_cards.at(i);

//             highestindx = i;

//         }

//     }

//     int winnerindx = (leader_indx + highestindx)%4;

//     Player* winner = players.at(winnerindx);

//       leader_indx = winnerindx;

//     return winner;

//     }



//   int check_team(Player* p){

//     if (p == team_one.at(0) || p == team_one.at(1)){

//         return 1;

//     }

//     return 2;

//   }

//   };
class Game {
 public:
  Game(Pack pack, bool shuffle, int pts_to_win, vector<Player*> players)
  :pack(pack), shuffle(shuffle), pts_to_win(pts_to_win), players(players){}
     void deletePlayers(){
         for (size_t i = 0; i < players.size(); ++i) {
           delete players[i];
         }
     }
    void play(){
        team_one_pts = 0;
        team_two_pts = 0;
        team_one.push_back(players.at(0));
        team_two.push_back(players.at(1));
        team_one.push_back(players.at(2));
        team_two.push_back(players.at(3));
        int x = 0;
        while (team_one_pts < pts_to_win && team_two_pts < pts_to_win){
                cout << "Hand " << x << endl;
                cout << *players.at(0) << " deals"<< endl;
                int one_wins = 0;
                int two_wins = 0;
            int teamDealing = 0;
                //shuffle & deal
                Card upcard = shuffle_and_deal(shuffle);
                cout << upcard << " turned up"<< endl;
                Suit upcardsuit = upcard.get_suit();
                // make trump
                make_trumpGame(players, upcard, upcardsuit, teamDealing);
                //trick playing
                int leader_indx = 1;
                for(int i = 0 ; i< 5; i++){
                    vector<Card> cards_played;
                    Card led = players.at(leader_indx)->lead_card(trump);
                    cout << led << " led by "
                    << *players.at(leader_indx) <<endl;
                    cards_played.push_back(led);
                    int currplayer = (leader_indx + 1)%4;
                    play_hand(currplayer, cards_played, led);
                    Player* winner = won_round(leader_indx, led, cards_played);
                    cout << *winner << " takes the trick"<<endl <<endl;
                    int team = check_team(winner);
                    check_win(team, one_wins, two_wins);
                    int winnerindx = 0;
                    winner_index(players, winner, winnerindx);
                    leader_indx = winnerindx;
                }
                vector<Player*> winning_team;
                if (one_wins> two_wins){
                    winning_team = team_one;
                }else{
                    winning_team = team_two;
                }
                cout << *winning_team.at(0) << " and "
            << *winning_team.at(1) << " win the hand" <<endl;
            
          //  cout << "one wins: " << one_wins << " two wins: " << two_wins << "team dealing: " << teamDealing;
                // scoring
                if( (one_wins >= 3) && (one_wins < 5)&& (teamDealing == 1)){
                    team_one_pts +=1;
                }else if((two_wins >= 3) && (two_wins < 5)&&
                         (teamDealing == 2)){
                    team_two_pts++;
                }else if(one_wins == 5 && teamDealing ==1){
                    team_one_pts +=2;
                    cout << "marched!"<<endl;
                }else if(two_wins == 5 && teamDealing ==2){
                    team_two_pts +=2;
                    cout << "marched!"<<endl;
                }else if (one_wins >=3 && teamDealing == 2){
                    team_one_pts +=2;
                    cout << "euchred!"<<endl;
                }else if(two_wins >=3 && teamDealing == 1){
                    team_two_pts +=2;
                    cout << "euchred!"<<endl;

                }

                cout << *team_one.at(0) << " and "
            << *team_one.at(1) << " have " <<team_one_pts
            << " points" <<endl;

                cout << *team_two.at(0)
            << " and " << *team_two.at(1) << " have "
            <<team_two_pts<< " points" <<endl << endl;

                new_dealer();

            x++;


        }

        if (team_one_pts>= pts_to_win){

            cout << *team_one.at(0) << " and "<< *team_one.at(1)
            << " win!"<<endl;

        }else{

            cout << *team_two.at(0) << " and "<< *team_two.at(1)
            << " win!"<<endl;

        }

    };



 private:


  Pack pack;

  bool shuffle;

  int team_one_pts, team_two_pts, pts_to_win;

  std::vector<Player*> players, team_one, team_two;

  int dealer_index;

  Suit trump;

    void play_hand(int &currplayer, vector<Card> &cards_played, Card led){
        
        for(int i = 0; i<3; i++){
            if(currplayer == 4){
                currplayer = 0;
            }
            Card played = players.at(currplayer)->play_card(led, trump);
            cards_played.push_back(played);
            cout << played << " played by "
            << *players.at(currplayer) <<endl;
            currplayer++;
        }
    }

    Card shuffle_and_deal(bool shuffle){
        pack.reset();

        if(shuffle == true){

            pack.shuffle();

        }

        players.at(1)->add_card(pack.deal_one());
        players.at(1)->add_card(pack.deal_one());
        players.at(1)->add_card(pack.deal_one());
        players.at(2)->add_card(pack.deal_one());
        players.at(2)->add_card(pack.deal_one());
        players.at(3)->add_card(pack.deal_one());
        players.at(3)->add_card(pack.deal_one());
        players.at(3)->add_card(pack.deal_one());
        players.at(0)->add_card(pack.deal_one());
        players.at(0)->add_card(pack.deal_one());
        players.at(1)->add_card(pack.deal_one());
        players.at(1)->add_card(pack.deal_one());
        players.at(2)->add_card(pack.deal_one());
        players.at(2)->add_card(pack.deal_one());
        players.at(2)->add_card(pack.deal_one());
        players.at(3)->add_card(pack.deal_one());
        players.at(3)->add_card(pack.deal_one());
        players.at(0)->add_card(pack.deal_one());
        players.at(0)->add_card(pack.deal_one());
        players.at(0)->add_card(pack.deal_one());

        Card upcard = pack.deal_one();

        return upcard;

    }

    void winner_index(vector<Player*> players, Player* winner, int &winnerindx){
        for(int a = 0; a<4; a++){
            if (players.at(a) == winner){
                winnerindx = a;
            }
        }
    }
  
  void new_dealer(){

    players.push_back(players.at(0));

    players.erase(players.begin());

    pack.reset();

  }
    
    void check_win(int team, int &one_wins, int  &two_wins){
        if(team == 1){
            one_wins++;
        }else{
            two_wins++;
        }
    }

    void make_trumpGame(std::vector<Player*> players,
                        Card &upcard, Suit &orderUpSuit, int &team){

        int round = 1;

        int i = 1;

        bool isDealer = false;

        while(!players[i]->make_trump(upcard, isDealer,
                                      round, orderUpSuit)){
            cout << *players[i] << " passes" << endl;
            i++;
            if (i > 3){
                i = 0;
                isDealer = true;
            }else{
                isDealer = false;
            }
            if (i == 1){
                round++ ;
            }
           // team = check_team(players.at(i));
        }
        team = check_team(players.at(i));
        cout << *players[i] << " orders up " << orderUpSuit
        << endl << endl;
        trump = orderUpSuit;
        if (round == 1){
            players[0]->add_and_discard(upcard);
        }
    }

  Player* won_round(int &leader_indx, Card led_card,
                    vector<Card> played_cards){

    int highestindx =0;
   //   int counter = 0;

    Card highest = played_cards.at(0);
     // cout << played_cards[0].get_suit() << "        ";
     /* for(int i = 1; i < 4; ++i){
          if(played_cards[i].get_suit() == played_cards[0].get_suit() && (played_cards[i].get_suit(trump) != trump) &&
             (played_cards[0].get_suit(trump)!= trump)){
              //cout << played_cards[i].get_suit() << " " << i << "  ";
              counter++;
          }
      }
      //cout << counter;
      if(counter == 0){
          return players.at(0);
          
      }
      */

    for (int i = 1; i< 4; i++){

        if(Card_less(highest, played_cards.at(i), led_card, trump)){

            highest = played_cards.at(i);

            highestindx = i;

        }

    }

    int winnerindx = (leader_indx + highestindx)%4;

    Player* winner = players.at(winnerindx);

      leader_indx = winnerindx;

    return winner;

    }



  int check_team(Player* p){

    if (p == team_one.at(0) || p == team_one.at(1)){

        return 1;

    }

    return 2;

  }

  };

int main(int argc, const char * argv[]) {
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
    if((!strcmp(argv[5], "Simple") && !strcmp(argv[5], "Human")) || 
    (!strcmp(argv[7], "Simple") && !strcmp(argv[7], "Human")) || 
    (!strcmp(argv[9], "Simple") && !strcmp(argv[9], "Human"))) {
        cout << "Usage: euchre.exe PACK_FILENAME [shuffle|noshuffle] "
        << "POINTS_TO_WIN NAME1 TYPE1 NAME2 TYPE2 NAME3 TYPE3 "
        << "NAME4 TYPE4" << endl;
        return 4;
    }
    
    string filename = argv[1];
    ifstream inFile;
    inFile.open(filename);
    if(!inFile.is_open()){
        cout << "Error opening " << filename << endl;
        return 5;
    }
    
    int pointsToWin = atoi(argv[3]);
    string shuffle = argv[2];
    vector <Player*> players1;
    players1.push_back(Player_factory(argv[4], argv[5]));
    players1.push_back(Player_factory(argv[6], argv[7]));
    players1.push_back(Player_factory(argv[8], argv[9]));
    players1.push_back(Player_factory(argv[10], argv[11]));
    
    
    
    bool isShuffle = false;
    if(shuffle  == "shuffle"){
        isShuffle = true;
    }
    Pack pack(inFile);
    Game game(pack, isShuffle, pointsToWin, players1);
    for(int i = 0; i < argc; i++){
        cout << argv[i] << " ";
    }
    cout << endl;
    game.play();
    inFile.close();
 //   game.deletePlayers();
    
    
    return 0;
}

