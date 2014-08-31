#include <iostream>
#include <cstdio>

using namespace std;

struct trie{
  int words;
  int prefixes;
  struct trie *edges[26];
};

void init(trie *vertex) {
  vertex->words = 0;
  vertex->prefixes = 0;
  for(int i=0; i<26; i++) {
    vertex->edges[i] = NULL;
  }
}

void addWord(trie *vertex, string word) {
  if(word.length() == 0) {
    vertex->words++;
  } else {
    vertex->prefixes++;
    int k = word[0] - 'a';
    if(!vertex->edges[k]) {
      vertex->edges[k] = new trie();
      init(vertex->edges[k]);
    }
    addWord(vertex->edges[k], word.substr(1));
  }
}

int countWords(trie vertex, string word) {
  int k = word[0] - 'a';
  if(word.length() == 0) {
    return vertex.words;
  } else if(!vertex.edges[k]) {
    return 0;
  } else {
    return countWords(*vertex.edges[k], word.substr(1));
  }
}

int countPrefixes(trie vertex, string prefix) {
  int k = prefix[0] - 'a';
  if(prefix.length() == 0) {
    return vertex.prefixes;
  } else if(!vertex.edges[k]) {
    return 0;
  } else {
    return countPrefixes(*vertex.edges[k], prefix.substr(1));
  }
}

int main() {
  trie index;
  init(&index);

  int n;
  scanf("%d", &n);

  string s;
  for(int i=0; i<n; i++) {
    cin >> s;
    addWord(&index, s);
  }

  cout << "There are " << countWords(index, "lol") << " lol words." << endl;
  cout << "There are " << countPrefixes(index, "lol") << " lol prefixes." << endl;

  return 0;
}
