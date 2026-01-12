#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

int main() {
    int N;
    string wordTemp;
    vector<string> wordArr;
    
    cin >> N;
    
    for (int i = 0; i < N; i++) {
      cin >> wordTemp;
	    wordArr.push_back(wordTemp);
    }
    
    sort(wordArr.begin(), wordArr.end(), [](const string &a, const string &b) {
	    if (a.length() == b.length())
		    return a < b;
		   return a.length() < b.length();
    }); // 람다 이용
    
    wordArr.erase(unique(wordArr.begin(), wordArr.end()), wordArr.end());

	  for (int i = 0; i < size(wordArr); i++) {
	    cout << wordArr[i] << "\n"; 
    }

    return 0;
}