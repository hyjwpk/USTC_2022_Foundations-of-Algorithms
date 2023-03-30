/*勤奋的小明为了预习下学期的数据库课程，决定亲自实现一个简单的数据库系统。该数据库系统需要处理用户的数据库插入和查询语句，
并输出相应的输出。具体来说，用户的输入共包含若干条插入语句和查询语句。其中每条插入语句包含一个主键（唯一标识）id和一个字符串s_{id}
，表示在数据库中插入一个主键为id，属性值为s_{id}的条目。每条查询语句包含一个字符串k，
表示在数据库总查询是否有条目属性值为k，若存在属性值为k的条目，则输出该条目对应的主键（输入保证至多有一个条目满足要求），
否则输出一个-1表示不存在这样的条目。*/

#include <iostream>
#include <sstream>
#include <string>
using namespace std;

class Node {
public:
    string key;
    int value;
    class Node *next;
    Node() {
        key = value = 0;
        next = NULL;
    }
};

class HashTable {
public:
    Node **array;
    int size;
    HashTable(int size) {
        array = (Node **)malloc(size * sizeof(Node *));
        for (int i = 0; i < size; i++) {
            array[i] = NULL;
        }
        this->size = size;
    }
    int Hashfunc(string key) {
        int num = 0;
        for(int i = 0; i < key.length(); i++) {
            num += key[i];
        }
        return abs(num) % size;
    }
    Node *Search(string key) {
        for (Node *p = array[Hashfunc(key)]; p != NULL; p = p->next) {
            if (key == p->key) {
                return p;
            }
        }
        return NULL;
    }
    void Insert(string key, int value) {
        Node *p = new Node();
        p->key = key;
        p->value = value;
        p->next = array[Hashfunc(key)];
        array[Hashfunc(key)] = p;
    }
};

int main() {
    HashTable h(100005);
    string temp("");
    while (getline(cin, temp)) {
        stringstream line(temp);
        string operation, key, value;
        line >> operation;
        line >> value;
        line >> key;
        if (operation == "INSERT") {
            h.Insert(key, stoi(value));
        }
        else if(operation == "FIND"){
            Node *p = h.Search(value);
            if (p == NULL) {
                cout << "-1" << endl;
            }
            else {
                cout << p->value << endl;
            }
        }
        else if(operation == "EXIT"){
            break;
        }
    };
    return 0;
}