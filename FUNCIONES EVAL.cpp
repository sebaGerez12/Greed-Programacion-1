
#include<iostream>
using namespace std;


int maximoVector (int vec[]){
    int i, maximo;
    maximo = vec[0];
    for (i=0; i<10; i++){
        if(vec[i]>maximo){
            return vec[i];
        }
    }

}

