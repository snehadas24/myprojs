// stats.cpp
#include "stats.hpp"
#include "p1_library.hpp"
#include <cassert>
#include <vector>
#include <cmath>
#include <utility>
#include <iostream>

using namespace std;

vector<pair<double, int> > summarize(vector<double> v) {
    vector<double> unique;
    vector<pair<double,int>> sum;
    for(int i = 0; i<v.size(); i++){
        if(unique.empty() == false){
            bool contains = false;
            for(int z = 0; z<unique.size(); z++){
                if (unique.at(z) == v.at(i)){
                    contains = true;
                }
            }
            if (contains == false){
            unique.insert(unique.end(), v.at(i));
            }
        }else{
            unique.insert(unique.end(), v.at(i));
        }
    }
    
    sort(unique);
    double current = 0;
    for(int y = 0; y<unique.size(); y++){
        current =  unique.at(y);
        int count = 0;
        for( int x = 0; x < v.size(); x++){
            if(v.at(x) == current){
                count ++;
            }
        }
        pair<double,int> temp = make_pair(current, count);
        sum.insert(sum.end(), temp);
    }
    return sum;
}

int count(vector<double> v) {
  return v.size();
}

double sum(vector<double> v) {
    double sum = 0;
    for(int i = 0; i<v.size(); i++){
        sum += v.at(i);
    }
    return sum;
}

double mean(vector<double> v) {
  double x = sum(v)/count(v);
  return x;
}

double median(vector<double> v) {
    while(v.size() > 2){
        v.pop_back();
        v.erase(v.begin());
    }
    if (v.size() == 2){
        return mean(v);
    }
    return v.at(0);
}

double mode(vector<double> v) {
    sort(v);
    int currcount = 0;
    double currnum = v.at(0);
    int modecount = 0;
    double currmode = v.at(0);
    for(int i = 0; i<v.size(); i++){
        if (v.at(i) == currnum){
            currcount++;
        }else{
            if (currcount>modecount){
                currmode = currnum;
                modecount = currcount;
            }
            currnum = v.at(i);
            currcount = 1;
        }
    }
    return currmode;
}

double min(vector<double> v) {
    double currentmin = v.at(0);
    for (int i = 0; i< v.size(); i++){
        if (v.at(i) <currentmin){
            currentmin =v.at(i);
        }
    }
    return currentmin;
}

double max(vector<double> v) {
  double currentmax = v.at(0);
    for (int i = 0; i< v.size(); i++){
        if (v.at(i) > currentmax){
            currentmax = v.at(i);
        }
    }
    return currentmax;
}

double stdev(vector<double> v) {
    double m = mean(v);
    double c =  count(v);
    int currtot = 0;
    for (int i = 0; i<v.size(); i++){
        currtot += (v.at(i) - m)*(v.at(i) - m);
    }
    double standarddev = sqrt(currtot/(c-1));
    return standarddev;
}

double percentile(vector<double> v, double p) {
    sort(v);
    if (p<100){
    double n = (p/100)*(count(v)-1) + 1;
    double k = 0;
    double d = 0;
    d = modf(n, &k);
    double vp = v.at(k-1) + d*(v.at(k)-v.at(k-1));
    return vp;
    }
    return v.at(v.size()-1);
    
}
