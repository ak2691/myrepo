#include <iostream>
#include <string>
#include <cmath>
using namespace std;

// returns count of non-overlapping occurrences of 'sub' in 'str'
int countSubstring(const string& str, const string& sub)
{
	if (sub.length() == 0) return 0;
	int count = 0;
	for (int offset = str.find(sub); offset != string::npos; 
		offset = str.find(sub, offset + sub.length()))
	{
		++count;
    
	}
	return count;
}
int countWords(string& str) {
  int count{};

  bool aWord = true;
  for (int i = 0; i < str.length(); i++) {
    
    if (str[i] == ' ' && str[i-1] != ' ' && aWord) {
      count++;
      
    }
    else if(str[i] == ' ' && str[i-1] != ' ' && !aWord) {
      aWord = true;
    }
    else if(static_cast<int>(str[i]) >= 48 && static_cast<int>(str[i]) <= 57) {
      aWord = false;
    }
    if(i == str.length()-1) {
      count++;
    }
  }
  return count;
}

int countSentences(string& str) {
  int sentences{};
  for(int i = 0; i < str.length(); i++) {
    if(str[i] == '.' && str[i+1] != '.' && i!=str.length()-1) {
      sentences++;
    }
    else if(i == str.length()-1) {
      sentences++;
    }
  }
  return sentences;
}
int averageWordsPerSentence(string& str) {
  int words = countWords(str);
  int sentences = countSentences(str);
  return words / sentences;
}
int UniqueWords(string& str) {
  string strHolder = "";
  string word{};
  int uniqueWords{};
  bool aWord = true;
  for(int i = 0; i< str.length(); i++) {
    
    if(str[i] != '.' && str[i] != ' ') {
      word += str[i];
      if(static_cast<int>(str[i]) >= 48 && static_cast<int>(str[i]) <= 57) {
        aWord = false;
      }
      
    }
    

    
    else if(str[i] == '.' || str[i] == ' '){
      
    //testing
      if(strHolder.find(" " + word + " ") == string::npos &&  word != "" && aWord) {
        
        strHolder = strHolder + " " + word + " ";
        
        uniqueWords++;
      }
      
      word.clear();
      aWord = true;
    }
  }
  
  return uniqueWords;
}
int LexicalDensity(string& str) {

  
  return round((float)(UniqueWords(str))/(float)(countWords(str)) * 100);
  
  
}
int main()
{


	

   string source = ("I was born in Lousiana down on the ol bayou raised on shrimps and catfish mamas good gumbo.  I got the ramblin fever.  Said goodbye to ma and pa.   Crossed that ol red river and this is what I saw. I saw miles and miles of Texas 1000 stars up in the sky.  I saw miles and miles of Texas gonna live here till I die.");
  //string source = "Testing 1 2 3. My name is Allan. There should only be 11 unique words.";

  
  
  cout << "hello";
	cout << "substring count: " << countSubstring(source, "is")        << '\n';
  cout << "word count: " << countWords(source) << '\n';
  cout << "Unique word count: " << UniqueWords(source) << "\n";
  cout << "Lexical density: " << LexicalDensity(source) << "%" << "\n";
  cout << "test";
  cout << "testone";
  cout << "test";
  cout << "test2";
  //comment

	


	return 0;
}