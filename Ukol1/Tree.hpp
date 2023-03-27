#pragma once
#include <string>
using namespace std;
 
class KVString
{
private:
    string key;
    string value;
    int length;
    KVString *nextLeft;
    KVString *nextRight;
    int n;
public:
    KVString(string k, string v);
    ~KVString();
    string GetKey();
    string GetValue();
    int GetLength();
    KVString* CreateTree (int n);
    void Print();
    KVString* CreateRecTree(int n);
    void PrintR(int n);
};
 