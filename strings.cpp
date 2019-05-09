#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <ctype.h>
#include <string>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <cstdlib>
using namespace std;

// Is Unique: Implement an algorithm to determine if a string has all unique characters. What if you
// cannot use additional data structures?

string changelower ( string s ) {
  s.erase(remove_if(s.begin(), s.end(), ::isspace), s.end());
  transform(s.begin(), s.end(), s.begin(), ::tolower);
  return s;
}

bool isunique ( string s ) {   // duale   duaale 
  s = changelower(s);
  bool arr[128] = {false};
  for (int i = 0; i < s.size(); ++i ) {
     if ( arr[int(s[i])] == true ) {
       return false;
     }
     arr[int(s[i])] = true;
  }
  return true;
}

/*
Check Permutation: Given two strings, write a method to decide if one is a permutation of the
// other.

duale elaud 
*/


bool isPermutation ( string s , string t ) {
  transform(s.begin(), s.end(), s.begin(), ::tolower);
  transform(t.begin(), t.end(), t.begin(), ::tolower);
  if(s.size() != t.size()) return false;
  int arr[128] = {0};
  for (int i = 0; i < s.size(); ++i){
     arr[int(s[i])]++;
  }
  for (int i = 0; i < t.size(); ++i) {
    arr[int(t[i])]-=1;
    if (arr[int(t[i])] < 0) return false;
  }
  return true;
}



/*
Given a string, write a function to check if it is a permutation of
a palindrome. A palindrome is a word or phrase that is the same forwards and backwards. A
permutation is a rearrangement of letters. The palindrome does not need to be limited to just
dictionary words.
*/

string gameOfThrones(string s) {  // THE CONFIRMED ONES 
//   if (s.size() == 0) return "YES";
  int a[128] = {0};
  bool aa[128] = {false};
  int count = 0;
  for (int i = 0; i < s.size(); ++i ) {
    a[int(s[i])]++;
  }
  for (int i = 0; i < s.size(); ++i ) {
    if (a[int(s[i])] % 2 == 1 && aa[int(s[i])] == false)
      count++;
    aa[int(s[i])] = true;
    if (count > 1 ) return "NO";
  }
  return "YES";
}

bool ispalindromepermutions ( string s )  {
   // rivir
   transform(s.begin() , s.end() , s.begin() , ::tolower);
   s.erase(remove_if (s.begin() , s.end(), ::isspace) , s.end());
   int oddCount = 0;
   int arr[128] = {0};
   for (int i = 0; i < s.size(); ++i ) {
      arr[int(s[i])]++;
   }
   for (int i = 0; i < s.size(); ++i ) {
      if ( arr[int(s[i])] % 2 == 1) oddCount++;
      if (oddCount > 1) return false;
   }
   return true;
}

// There are three types of edits that can be performed on strings: insert a character,
// remove a character, or replace a character. Given two strings, write a function to check if they are
// one edit (or zero edits) away.

bool oneEditAway ( string str1 , string str2 ) {
  int t = abs(int(str1.length()) - int(str2.length()));
  if ( t > 1) return false;
  // pale  bale
  string s1 = str1.length() < str2.length() ? str1 : str2;
  string s2 = str1.length() < str2.length() ? str2 : str1;
  int index1 = 0;
  int index2 = 0;
  bool foundDifference = false;
  while (index2 < s2.length() && index1 < s1.length()) {
    if (  s1[index1]  != s2[index2] ) {
       // pale base 
 /* Ensure that this is the first difference found.*/
      if (foundDifference) return false;
          foundDifference = true;

       if (s1.length() == s2.length()) {    //On replace, move shorter pointer
           index1++;
         }
      } else {
     index1++; // If matching, move shorter pointer
    } 
        index2++; // Always move pointer for longer string
   }
      return true;
}


/*
One edit away ! 
*/

string compression ( string str ) {
   // aa
   // a3b3c2d2
   int arr[128] = {0};
   bool arr2[128] = {false};
   for (int i = 0; i < str.size(); ++i ) {
      arr[int(str[i])]++;
      arr2[int(str[i])] = false;
   }
   string  s = "";
   for (int i = 0; i < str.size(); ++i ) {
      if ( arr2[int(str[i])] == false ) {
         s+=str[i];
         s+= '0' + arr[int(str[i])];
      }
      arr2[int(str[i])] = true;
    
   }
  return s.size() < str.size() ? s : str;
  // return s;
}

// string compress ( string s ) {   // BETTER CHOICE 
//    //aaabbbccdd
//    string res = "";
//    int arr[128] = {0};
//    bool arr2[128] = {false};
//    for (int i = 0; i < s.size(); ++i ) {
//      arr[int(s[i])]++;
//       arr2[int(s[i])] = false;
//    }
//    for (int i = 0; i < s.size(); ++i ) {
//      if ( arr2[int(s[i])]  == false ) {
//        res+=s[i];
//        res = res + to_string(arr[int(s[i])]);
//      }
//       arr2[int(s[i])] = true;
//    }
//    return res;
// }


// Rotate Matrix: Given an image represented by an NxN matrix, where each pixel in the image is 4
// bytes, write a method to rotate the image by 90 degrees. Can you do this in place?


void rotataMatrix ( vector<vector<int>> & matrix ) {
    reverse (matrix.begin() , matrix.end());
    for(int i = 0; i < matrix.size(); ++i ) {
      for (int j = i; j < matrix.size(); ++j ) {
         int temp = matrix[i][j];
         matrix[i][j] = matrix[j][i];
         matrix[j][i] = temp;
      }
    }
    
}

/*
Write an algorithm such that if an element in an MxN matrix is 0, its entire row and
column are set to 0.
*/
void oneZeroAllZero ( vector<vector<int>> & matrix ) {
   int row[matrix.size()] = {0};
   int col[matrix[0].size()] = {0};

   for (int i = 0; i < matrix.size(); ++i ) {
     for (int j = 0; j < matrix[0].size(); j++) {
        if (matrix[i][j] == 0) {
          row[i] = 1;
          col[j] = 1;
        }
     }
   }

   for (int i = 0; i < matrix.size(); ++i ) {
     for (int j = 0; j < matrix[0].size(); j++) {
        if (row[i] == 1   ||  col[j] == 1 ) {
           matrix[i][j] = 0;
        }
     }
   }
}

// get the substring of a string using 

bool issubstring ( string substr , string mainstr) {
   if (mainstr.find(substr) !=  string::npos ) return true;
   return false;
}

bool oneCallrotation ( string s1 , string s2 ) {
  // "waterbottlewaterbottle" is a rotation of" erbottlewat").
   if (s1.size() == 0 ) return false;
   string res = s1 + s1;
   return issubstring(s2 , res);
}


/*
Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.
*/

// Version one : using arrays 
int firstUniqChar(string s) {
      int arr[256] = {0};
      for (int i = 0; i < s.size(); ++i){
         arr[s[i]]+=1;
      }
      for (int i = 0; i < s.size(); ++i) {
         if (arr[s[i]] == 1 ) {
           return s.find(s[i]);
         }
      }
      return -1;
    }
//Version two: using map 

class Solution {
public:
    int firstUniqChar(string s) {
      unordered_map <char , int> m;
      for (auto c : s ) m[c]++;
      for (int i = 0; i < s.size(); ++i) {
        if (m[s[i]] == 1) return i;
      }
      return -1;
    }
};


int main() {
  //  int a[] = { 1,2,3,4,5};
  //  int size = sizeof(a)/sizeof(int);
  //  ListNode * test = createList ( a , size);
  //  ListNode * tt = test;
  //  displayList(test);
  //  tt = reverseList (tt);
  // //  cout << endl;
  //  cout << endl;
  //   displayList(tt);

}


