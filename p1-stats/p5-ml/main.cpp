

#include <iostream>
#include <ostream>
#include <fstream>
#include <cstring>
#include <set>
#include <sstream>
#include <map>
#include <iterator>
#include "csvstream.hpp"

using namespace std;


class Classifier{
public:
    Classifier(string stream1, string stream2){
        trainingFile.open(stream1);
        testingFile.open(stream2);
        
    }
    void training(){
        
        string str;
        while(trainingFile >> str){
            
        }
        
        
        
    }
    //make classifier?
    void read_file(vector<string> tags, vector<vector<string>> content, int lines){
        for(int i = 1; i< lines; i++){
            map<string, int> newtag;
            auto result = m.insert(make_pair(tags[i], newtag)).first;
            tag_occ[tags[i]]++;
            map<string, int>  curr_map = result->second;
            string *s = &content[i][0];
            while(s){
                curr_map[*s]++;
                all_words[*s]++;
                
            }
        }
    }
    void prediction(){
        
    }
    
    
    
private:
    map<string, int> all_words;
    bool debug;
    set<string> wordsUnique;
    int num_posts;
    set<string> unique_words(const string &str) {
        istringstream source(str);
        set<string> words;
        string word;
        while (source >> word) {
            words.insert(word);
        }
        return words;
    }
    ifstream trainingFile;
    ifstream testingFile;
    map<string, map<string, int>> m;
    map<string, int> tag_occ;
};


set<string> unique_words(const string &str) {
    istringstream source(str);
    set<string> words;
    string word;
    while (source >> word) {
        words.insert(word);
    }
    return words;
}
int main(int argc, const char * argv[]) {
    cout.precision(3);
    bool debug = false;
    if(argc != 3 && argc != 4){
        cout << "Usage: main.exe TRAIN_FILE TEST_FILE [--debug]" << endl;
        return 1;
    }
    
    if(argc == 4){
        if(strcmp(argv[3], "--debug")){
            cout << "Usage: main.exe TRAIN_FILE TEST_FILE [--debug]" << endl;
            return 2;
        }else{
            debug = true;
        }
    }
    string file1 = argv[1];
    int numPosts = 0;
    csvstream stream1(file1);
    map<string, string> row;
    map<string, int> wordInPosts;
   string all_content = "";
    map<string, int> tags;
    map<string, map<string, int>> bigMap;
    while(stream1 >> row){
        string initial = row["content"];
        set<string> unique = unique_words(initial);
        for(string s : unique){
            wordInPosts[s]++;
            bigMap[row["tag"]][s]++;
        }
        tags[row["tag"]]++;
        all_content += row["content"] + " ";
        numPosts++;
    }
    set<string> uniqueWords;
    int numUniqueWords = 0;
    uniqueWords = unique_words(all_content);
    for(string s : uniqueWords){
        cout << s << " ";
        numUniqueWords++;
    }
    cout << " " << wordInPosts["upcard"] << endl;
    cout << numUniqueWords << " ";
    cout << tags["euchre"] << " ";
    cout << "num upcard in euchre " << bigMap["euchre"]["upcard"] << " ";
    cout << " " << tags["calculator"];
    cout << " " << numPosts;
        ifstream inFile1;
        inFile1.open(file1);
        if(!inFile1.is_open()){
            cout << "Error opening " << file1 << endl;
            return 5;
        }
    string file2 = argv[2];
        ifstream inFile2;
        inFile2.open(file2);
        if(!inFile2.is_open()){
            cout << "Error opening " << file2 << endl;
            return 5;
        }
    int f2Lines = 0;
    string garbage;
    string f2String;
    getline(inFile2, garbage);
    while(getline(inFile2, f2String)){
        f2Lines++;
    }
    
   
    

    
    
    return 0;
}


// #include <iostream> //ostream
// #include <functional> //less
// #include <algorithm>
// #include <iostream>
// #include <ostream>
// #include <fstream>
// #include <cstring>
// #include <vector>
// #include <map>
// #include <set>
// #include <cmath>
// using namespace std;


// int main(int argc, const char * argv[]) {
//     cout.precision(3);
//     if(argc != 3 && argc != 4){
//         cout << "Usage: main.exe TRAIN_FILE TEST_FILE [--debug]" << endl;
//         return 1;
//     }
    
//     if(argc == 4){
//         if(!strcmp(argv[3], "--debug")){
//             cout << "Usage: main.exe TRAIN_FILE TEST_FILE [--debug]" << endl;
//             return 2;
//         }
//     }
//     string file1 = argv[1];
//         ifstream inFile1;
//         inFile1.open(file1);
//         if(!inFile1.is_open()){
//             cout << "Error opening " << file1 << endl;
//             return 5;
//         }
//     string file2 = argv[2];
//         ifstream inFile2;
//         inFile2.open(file2);
//         if(!inFile2.is_open()){
//             cout << "Error opening " << file2 << endl;
//             return 5;
//         }
//     // string line  =
    

    
    
//     return 0;
// }

// class Classifier{
// public:
//     set<string> unique_words(const string &str) {
//       istringstream source(str);
//       set<string> words;
//       string word;
//       while (source >> word) {
//         words.insert(word);
//       }
//       return words;
//     }

//     void read_file(vector<string> tags, vector<vector<string>> content, int lines ){
//         cout << "tested on " << lines << " examples" << endl << endl;
//         if(debug){
//             cout << "training data:" << endl;
//         }
//         for(int i = 0; i<lines; i++){
//             map<string, int> newtag;
//             auto result = m.insert(make_pair(tags[i], newtag)).first;
//             tag_occ[tags[i]]++;
//             map<string, int>  curr_map =  result->second;
//             string *s = &content[i][0];
//             while(s){
//                 curr_map[*s] ++;
//                 all_words[*s] ++;
//                 total_words++;
//             }
            
//         }
//     }
//     void training();
//     void prediction(vector<string> post, int words){
//         for(int i =0; i< m.size(); i++){
//             int log_prior = 
//         }

//     }
    
    
// private:
// map< string, map<string, int> > m;
// int total_words;
// map<string, int> all_words;
// int num_posts;
// set<string> unique_words;
// set<string> tags;
// map<string, int> tag_occ;
// bool debug;

// // int index_tag;
// // int index_content;
// };