//AC
//BOJ 16934 게임 닉네임
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#define SIZE 101010
using namespace std;
map<string, int> name;
set<string> ans;
class Node {
public:
    char data;      
    string strData; 
    int cnt = 0;
    vector<Node *> child;
};
class Trie {
private:
    Node *root = new Node;

public:
    void push(string str) {
        insert(str, 0, root);
    }
    void insert(string str, int idx, Node *node) {
        if (idx >= str.length()) {
            node->cnt += 1;
            node->strData = str; // 단어 저장
            return;
        }
        int next = -1;
        for (int i = 0; i < node->child.size(); i++) {
            if (str[idx] == node->child[i]->data) {
                node->cnt += 1;
                next = i;
                break;
            }
        }
        if (next != -1) {
            insert(str, idx + 1, node->child[next]);
        }
        else {
            Node *newNode = new Node; //해당 문자 없다면 노드 새로 생성
            newNode->data = str[idx];
            node->cnt += 1;
            node->child.push_back(newNode);
            insert(str, idx + 1, newNode);
        }
    }
    bool search(string str) {
        return findWord(str, 0, root);
    }
    bool findWord(string str, int idx, Node *node) {
        if (idx >= str.length()) {
            if(node->cnt == 1 ){
                return false;
            }
            else    return true;
        }
            
        int next = -1;
        for (int i = 0; i < node->child.size(); i++) {
            if (str[idx] == node->child[i]->data) {
                next = i;
                break;
            }
        }
        if (next != -1)
            return findWord(str, idx + 1, node->child[next]); 
        else {
            return true;
        }
    }
};
Trie *trie = new Trie;
int solve(string word) {
    if(!trie->search(word)) {
        if(!ans.count(word)) {
            return 1;
        }
        else return 0;
    }
    return 0;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    vector<string> v;
    int N;
    string s;
    cin >> N;
    for(int i=0; i<N; i++) {
        int check = false;
        string nickname;
        cin >> s;
        
            trie->push(s);
            string temp;
            for(int j=0; j<s.size(); j++) {
                temp.push_back(s[j]);
                check = solve(temp);
                if(check) {
                    nickname = temp;
                    name.insert({s, 2});
                    break;
                }
            }
            if(!check) {
                if(name.find(s) != name.end()){
                    if(name[s] > 1) {
                        nickname = s + to_string(name[s]);
                        name[s] += 1;
                    }
                    else {
                        nickname = s;
                        name[s] += 1;
                    }
                }
                else {
                    nickname = s;
                    name.insert({s, 2});
                }
            }
        v.push_back(nickname);
        ans.insert(nickname);
    }
    
    for(string answer : v) {
        cout << answer << "\n";
    }
    return 0;
}