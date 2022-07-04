#include <iostream>
#include <fstream>
#include "sort.h"
#include "algorithm"
#include "iomanip"
#define MAXIN 100
#define MAXWORD 1000
using namespace std;

int main(){

    int n=0; //�����������ʸ���
    string xx[MAXIN];//�����ݴ浥��
    wordarr words[MAXWORD];       //  �洢���ʼ����Ƶ

    //���ļ�
    ifstream infile;
    try {
        infile.open("E:\\suanfa\\exp1\\test.txt",ios::in);  //.exe�ļ���txt�ļ�����ͬһĿ¼��

    }catch (const exception& e)
    {
        cerr << e.what() << endl;
    }

    char ch;
    string word  ; //������ŵ�ǰ�ķָ��
    cin.unsetf(ios::skipws);//ȡ��c++ cin������Ĭ�ϵĺ��Կհ��ַ���Ҳ���ǲ��ٺ��Կհ��ַ�


    do {
        infile.get(ch);
        //infile>>ch;
        //cout<<ch<<endl; ����ַ���ȡ�ļ���Ϣ

        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
            //˵�����ϵ��ʵ�Ҫ��
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

    //�ر��ļ�
    infile.close();
    //cout<<n;
//    for (int i = 0; i < n; ++i) {
//        cout<<xx[i]<<'\n';
//
//    }

    //���д�Ƶͳ��
    int numVerb = 0;        //��ʾ��ͬ���ʵ�����

    int j = 0;
    while (j<n) {
        int newWord = 1;        //�Ƿ����ʻ��
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
//    //���
//    for (int i = 0; i < numVerb; ++i) {
//        cout<<words[i].word<<'\t'<<words[i].count<<endl;
//    }
    //������ĸ���������
    sort(words,words+numVerb, cmpare);
    //���
    cout<<"������ĸ������---------------------------------"<<endl;
    cout<<"����\t\t��Ƶ"<<endl;
    cout<<"-----------------------------------------"<<endl;
    for (int i = 0; i < numVerb; ++i) {
        cout<<setw(10)<<setiosflags(ios::left)<<words[i].word<<"\t\t"<<words[i].count<<endl;
    }
    quicksort_count(words,0,numVerb);  //�Դ�Ƶ���п������򣨽���

//    //��ȡ������Ƶ
//�Կ�����֮������н��з�����ĸ����
        int wy[MAXIN];//�����洢��Ƶ���
        int wyy[MAXIN] = {0};//�����洢�������
    for (int i = 0; i < numVerb; ++i) {
        //��ȡ��Ƶ
        wy[i] = words[i].count;
    }
    for (int i = 0; i < numVerb;) {
        for (int k = i; k < numVerb; ++k) {
            //ȷ���������
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
    //���
    cout<<"���մ�Ƶ����---------------------------------"<<endl;
    cout<<"����\t\t��Ƶ"<<endl;
    cout<<"-----------------------------------------"<<endl;
    for (int i = 0; i < numVerb; ++i) {
        cout<<setw(10)<<setiosflags(ios::left)<<words[i].word<<"\t\t"<<words[i].count<<endl;
    }









    return 0;



}
