//
// Created by 86177 on 2022/6/28.
//

#ifndef EXP1_SORT_H
#define EXP1_SORT_H

#endif //EXP1_SORT_H

#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

typedef struct wordarray{
    string word;        //单词
    int count;          //词频

}wordarr;


int partition(wordarray *a,int p,int r){

    int i = p ;
    int j = r+1;
    wordarray x = a[p];
    while(true){
        while(a[--j].count < x.count);
        while(a[++i].count >x.count && i<r);
        if (i>j) break;
        std::swap(a[i],a[j]);
    }

a[p] =a[j];

a[j]=  x;
    return j;
}

void quicksort_count(wordarray *a,int p,int r){
    if (p<r){

        int q = partition(a,p,r);
        quicksort_count(a,p,q-1);
        quicksort_count(a,q+1,r);
    }


}

bool cmpare(const wordarray &a,const wordarray &b){
    return a.word <b.word;
}
