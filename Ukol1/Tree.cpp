#include <iostream>
#include <string>
#include "Tree.hpp"
 
using namespace std;
 
KVString::KVString(string k, string v){
    this->key = k;
    this->value = v;
    this->nextLeft=nullptr;
    this->nextRight=nullptr;
}
string KVString::GetKey(){
    return this-> key;
}
string KVString::GetValue(){
    return this-> value;
}
int KVString::GetLength(){
    return this-> length;
}
KVString* KVString::CreateTree(int n){
    this->n = n;
    this->nextLeft = CreateRecTree(n);
    this->nextRight = CreateRecTree(n);
    return this;
}
KVString* KVString::CreateRecTree(int n){
    if(n == 0) {
        return nullptr;
    }
    KVString* kvs = new KVString(this -> key, this -> value);
    kvs -> nextLeft = CreateRecTree(n-1);
    kvs -> nextRight = CreateRecTree(n-1);
    return kvs;
}
void KVString::Print(){
    for(int i = 0; i < this -> n; i++){
        cout<<"\t";
    }
    cout <<this->key<<endl; 
    if(this-> nextLeft == nullptr || this -> nextRight == nullptr)
    {
        return;
    }  

    for (int i = 0; i < this -> n-1; i ++){
        cout<<"\t";
    }
    cout <<"Left:" << this->nextLeft->key;

    for(int i = 0; i < this->n-1; i++){
        cout<<"\t";
    }
    cout <<"Right: "<<this->nextRight->key<<endl;

 
    this->nextLeft->PrintR(this->n-2);
    this->nextRight->PrintR(this->n-2);
}
void KVString::PrintR(int n){
    if(this->nextLeft == nullptr || this -> nextRight == nullptr)
    {
        return;
    }  
    for (int i = 0; i < n; i ++){
        cout<<"\t";
    }
    cout <<"L: " << this->nextLeft->key;

    for(int i = 0; i < n; i++){
        cout<<"\t";
    }
    cout <<"R: "<<this->nextRight->key;
 
    this->nextLeft->PrintR(n-1);
    this->nextRight->PrintR(n-1);

    cout<<endl;
}
 
 