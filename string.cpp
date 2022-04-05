#include "stringheader.h"
#include <iostream>
#include <cstring>
#include <cstdlib>

Str::Str(int leng){
    len = leng; //str의 생성자가 매개변수로 정수를 받으면 해당 정수를 문자열의 길이를 의미하는 len에 저장
}

Str::Str(const char* neyong){
    len = strlen(neyong); //str의 생성자가 매개변수로 문자열을 받으면 len에 해당 문자열의 길이에 해당하는 길이를 저장
    str = new char[len + 1]; //(문자열의 길이 + 1)의 길이를 가지는 배열 str을 동적할당한다. 이때 len+1인 이유는 마지막에 \0을 저장할 공간이 필요하기 때문이다.
    strcpy(str, neyong); //strcpy를 이용해 neyong에 존재하는 문자열을 str에 복사한다.
}

Str::~Str(){
    delete [] str; //소멸자 ~str에서는 delete[]를 이용해 동적할당을 통해 생성한 배열을 제거한다.
}

int Str::length(void){
    return len;//문자열의 길이를 반환한다.
}

char* Str::contents(void){
    return str;//문자열을 반환한다.
}
int Str::compare(class Str& a){//이 함수는 매개변수로 str class의 객체를 받는 함수이다.
    int flag; //flag변수는 문자열의 동일성을 판단하기 위한 변수이다.
    if(strcmp(a.str, str)){//str class의 객체를 매개변수로 받아왔기에 a.str을 통해 a에 존재하는 문자열과 비교하고자 하는 문자열 str을 비교해야 한다.
        flag = 1;//만일 같다면 flag는 1이다.
    }
    else{
        flag=0;//만일 같이 않다면 flag는 0이다.
    }
    return flag;//flag를 반환한다.
}
int Str::compare(const char* a){//이 함수는 매개변수로 문자열을 받는 함수이다.
    int flag;
    if(strcmp(str, a)){//매개변수로 받은 문자열과 str을 비교한다.
        flag = 1;//만일 str과 매개변수로 받은 문자열이 동일하다면 1을 저장한다.
    }
    else{
        flag = 0;//만일 다르다면 0을 저장한다.
    }
    return flag; //flag를 반환하다.
}
void Str::operator=(const char *a){
    delete[] str;//
    int temp = strlen(a);
    len = temp;
    str = new char[temp + 1];
    strcpy(str, a);
}
void Str::operator=(class Str& a){
    delete[] str;
    int temp = strlen(a.str);
    len = temp;
    str = new char[temp + 1];
    strcpy(str, a);
}