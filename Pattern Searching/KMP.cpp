#include<bits/stdc++.h>

using namespace std;

int main () {
  int n;
  string pattern, txt;
  int lps[100000];
  cin >> n;
  getline(cin, pattern);

  for (int k=0;k<n;k++) {
    cin >> txt;
    cin >> pattern;
    int i,j;

    // Preprocessing LPS for KMP Algorithm
    i = 0;
    j = 1;

    lps[0] = 0;
    while (j < pattern.length()) {
      if (pattern[i] == pattern[j]) {
        i++;
        lps[j] = i;
        j++;
      } else {
        if (i != 0) {
          i = lps[i-1];
        } else {
          lps[j] = 0;
          j++;
        }
      }
    }

    // Pattern search using preprocessing LPS
    i = 0;
    j = 0;
    while (i < txt.length()) {
      if (pattern[j] == txt[i]) {
        j++;
        i++;
      } else if (i < txt.length()) {
        if (j > 0) {
          j = lps[j-1];
        } else {
          i++;
        }
      }

      if (j == pattern.length()) {
        cout << "Pattern found at index : " << i-j << endl;

        j = lps[j-1];
      }
    }

  }
}