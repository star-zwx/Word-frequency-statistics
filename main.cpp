#include <iostream>
#include <fstream>
#include "sort.h"
#include "algorithm"
#include "iomanip"
#define MAXIN 100
#define MAXWORD 1000
using namespace std;

int main(){

    int n=0; //用来计数单词个数
    string xx[MAXIN];//用来暂存单词
    wordarr words[MAXWORD];       //  存储单词及其词频

    //打开文件
    ifstream infile;
    try {
        infile.open("E:\\suanfa\\exp1\\test.txt",ios::in);  //.exe文件和txt文件不在同一目录下

    }catch (const exception& e)
    {
        cerr << e.what() << endl;
    }

    char ch;
    string word  ; //用来存放当前的分割单词
    cin.unsetf(ios::skipws);//取消c++ cin输入流默认的忽略空白字符，也就是不再忽略空白字符


    do {
        infile.get(ch);
        //infile>>ch;
        //cout<<ch<<endl; 这个字符读取文件信息

        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
            //说明符合单词的要求
            word += ch;
        }

        if ((ch < 'A' || ch > 'Z') && (ch < 'a' || ch > 'z') || ch==32) {
            if (!word.empty()) {
                transform(word.begin(),word.end(),word.begin(),::tolower);
                xx[n] = word;
                //cout<<word<<endl;
                word = "";
                n += 1;
            }
        }

    }while(!infile.eof());

    //关闭文件
    infile.close();
    //cout<<n;
//    for (int i = 0; i < n; ++i) {
//        cout<<xx[i]<<'\n';
//
//    }

    //进行词频统计
    int numVerb = 0;        //表示不同单词的数量

    int j = 0;
    while (j<n) {
        int newWord = 1;        //是否进入词汇表
        for (int i = 0; i < numVerb; ++i) {
            if (words[i].word == xx[j]) {
                words[i].count++;
                newWord = 0;
            }

        }

        if (newWord == 1) {
            words[numVerb].word = xx[j];
            words[numVerb].count = 1;
            numVerb++;
        }

        j++;

    }
//    //输出
//    for (int i = 0; i < numVerb; ++i) {
//        cout<<words[i].word<<'\t'<<words[i].count<<endl;
//    }
    //按照字母表排序并输出
    sort(words,words+numVerb, cmpare);
    //输出
    cout<<"按照字母表排序---------------------------------"<<endl;
    cout<<"单词\t\t词频"<<endl;
    cout<<"-----------------------------------------"<<endl;
    for (int i = 0; i < numVerb; ++i) {
        cout<<setw(10)<<setiosflags(ios::left)<<words[i].word<<"\t\t"<<words[i].count<<endl;
    }
    quicksort_count(words,0,numVerb);  //对词频进行快速排序（降序）

//    //提取出最大词频
//对快排完之后的序列进行分组字母排序
        int wy[MAXIN];//用来存储词频情况
        int wyy[MAXIN] = {0};//用来存储分组情况
    for (int i = 0; i < numVerb; ++i) {
        //提取词频
        wy[i] = words[i].count;
    }
    for (int i = 0; i < numVerb;) {
        for (int k = i; k < numVerb; ++k) {
            //确定分组情况
            if (wy[k] == wy[i]){
                wyy[i] +=1;
            }

        }
        i+=wyy[i];
    }

    int t=0;
    int k = 0;
    for (int i = 0; i <numVerb,wyy[i]!=0; ++i) {
        while (k<numVerb && t<numVerb && wyy[i]!=0){

                k+=wyy[i];
                sort(words+t,words+k, cmpare);
                t = k;
                break;

        }
    }
    //输出
    cout<<"按照词频排序---------------------------------"<<endl;
    cout<<"单词\t\t词频"<<endl;
    cout<<"-----------------------------------------"<<endl;
    for (int i = 0; i < numVerb; ++i) {
        cout<<setw(10)<<setiosflags(ios::left)<<words[i].word<<"\t\t"<<words[i].count<<endl;
    }









    return 0;



}
