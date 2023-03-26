#include<iostream>
#include <string>
using namespace std;

class KeyValue
{
    private:
        int key;
        double value;
        KeyValue *next;
    public:
        KeyValue(int k, double v);
        ~KeyValue();
        int GetKey();
        double GetValue();
        KeyValue* GetNext();
        KeyValue* CreateNext(int k, double v);
        void CreateLoop(int n);
        KeyValue* CreateRecursive(int n);
        void Print();
        void DeleteAtPos(int n);

};

class KVString{
    private:
        string key;
        string value;
        KVString * nextLeft;
        KVString * nextRight;
    public:
        KVString(string key, string value);
        ~KVString();
        KVString* CreateTree(int n);
        KVString* CreateRecTree(int n);
        void Print();
};

class KeyValues
{
    private:
        KeyValue ** keyValues;
        int count;
    public: 
        KeyValues(int n);
        ~KeyValues();
        KeyValue* CreateObject(int k, double v);
        KeyValue* SearchObject(int key);
        KeyValue* RemoveObject(int key);
        int Count();
};


KVString :: KVString(string key, string value){
    this->key = key;
    this->value = value;
    this->nextLeft = nullptr;
    this->nextRight = nullptr;
}
static int created = 0;
KVString* KVString :: CreateTree(int n){
    this ->nextLeft = CreateRecTree(n);
    this ->nextRight = CreateRecTree(n);
    return this;
}
KVString* KVString :: CreateRecTree(int n){
    if(n == 0) {
        return nullptr;
    }
    created ++;
    KVString* kvs = new KVString(this -> key, this -> value);
    kvs -> nextLeft = CreateRecTree(n-1);
    kvs -> nextRight = CreateRecTree(n-1);
    return kvs;
}

KVString :: ~KVString(){
    if(this->nextLeft != nullptr)
        delete this->nextLeft;
    if(this -> nextRight != nullptr)
        delete this->nextRight;
}
void KVString :: Print(){
    if(this->nextLeft == nullptr || this -> nextRight == nullptr)
        return;
    cout << "Left: " << this->nextLeft->key << " Right: " << this->nextRight->key << endl;
    this->nextLeft->Print();
    this->nextRight->Print();
}

int KeyValues::Count(){
    return this->count;
}

KeyValue* KeyValues::RemoveObject(int n){
    for(int i = 0; i < this->count; i ++){
        KeyValue* kv = this->keyValues[i];
        if(kv->GetKey() == n){
            this->keyValues[i] = nullptr;
            for(int j = i; j < this->count; j ++){
                this->keyValues[j-1] = this->keyValues[j];
            }
            count --;
            return kv;
        }
    }
    return nullptr;
}
KeyValues :: KeyValues(int n){
    this->count = 0;
    KeyValue** keyValues = new KeyValue*[n];
    this->keyValues = keyValues;
}

KeyValue* KeyValues::CreateObject(int k, double v){
    KeyValue* keyValue = new KeyValue(k, v);
    this->keyValues[this->count] = keyValue;

    count ++;
    return keyValue;
}
KeyValue* KeyValues::SearchObject(int key){
    for(int i = 0; i < this->count; i ++){
        KeyValue* kv = this->keyValues[i];
        if(kv->GetKey() == key){
            return kv;
        }
    }
    return nullptr;
}
void KeyValue::DeleteAtPos(int n){
    KeyValue* kv = this;
    KeyValue* kvl = this;

    for(size_t i = 0; i < n; i ++){
        kvl = kv;
        kv = kv -> GetNext();
    }
    kvl -> next = kv -> next;
}

//CreateLoop
void KeyValue :: CreateLoop(int n){
    KeyValue *kv = this;
    for (size_t i = 0; i < n; i++)
    {
        kv->CreateNext(kv -> GetKey() + 1, kv -> GetValue());
        kv = kv->GetNext();
    }
}
KeyValue* KeyValue :: CreateRecursive(int n){
    if(n == 0) return this;

    this->next = CreateRecursive(n-1);
}
void KeyValue :: Print(){
    KeyValue * kv = this;
    while(true){
        cout << kv->GetKey() << " " << kv->GetValue() << endl;
        if(kv->next == nullptr) break;
       
        kv = kv->next;
    }
}
KeyValues::~KeyValues(){
    for(int i = 0; i < this->count; i ++){
        delete this->keyValues[i];
    }
    delete[] this->keyValues;
}


KeyValue::~KeyValue(){
    if(this->next != nullptr){
        delete this->next;
        this->next = nullptr;
    }
}
KeyValue::KeyValue(int k, double v){
    this->key = k;
    this->value = v;
    this->next = nullptr;
}
int KeyValue::GetKey(){
    return this->key;
}
double KeyValue::GetValue(){
    return this->value;
}
KeyValue* KeyValue::GetNext(){
    return this->next;
}

KeyValue* KeyValue::CreateNext(int k, double v){
    this->next = new KeyValue(k,v);
    return this->next;
}



int main(){

    KeyValue * keyValue2 = new KeyValue(6,5);
    keyValue2->CreateNext(2, 2.5);
    cout << "Vypis" << endl;
    keyValue2->CreateLoop(4);
    keyValue2->Print();

    keyValue2->DeleteAtPos(2);
    keyValue2->Print();

    cout << "Vypis z uctu xd " << endl;

    KVString * kv = new KVString("pepa", "z depa");

  
    kv->CreateTree(3);

    cout << "Cfeated "<< created << endl;
    kv->Print();

    

/*


    cout << keyValue -> GetKey() << endl;
    cout << keyValue2 -> GetKey() << endl;


    KeyValues* keyValues = new KeyValues(2);

    keyValues->CreateObject(3,4.5);
    keyValues->CreateObject(2,3.2);

    cout << keyValues->SearchObject(2)->GetValue() << endl;

    keyValues->RemoveObject(2);
    
    cout << keyValues->SearchObject(2)->GetValue() << endl;

    return 0;
    */
   return 0;
}

//Du
/*
    Objekt faktura
    objekt osoba
    Faktura - cislo, osoba

*/