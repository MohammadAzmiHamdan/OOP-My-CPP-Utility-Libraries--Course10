#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <cctype>
using namespace std; 
///////////////////////////////////////////////////////////////////////////
/////////////////My string Utility lib ///////////////////////////////////
//////////////////////////////////////////////////////////////////////////

class clsString
{
private :
	string _Value;
public:
	clsString() {

		_Value = "";
	}
	clsString(string Value) {

		this->_Value = Value;
	}
	void SetValue(string Value) {
		this->_Value = Value;

	}
	string GetValue() {
		return _Value;
	}
	__declspec(property(get = GetValue, put = SetValue))  string _Value;
	//

   static std::vector<std::string> SplitString(std::string s, std::string Delimter) {
        std::vector<std::string> vString;
        std::string sWord;
        short pos;

        while ((pos = s.find(Delimter)) != std::string::npos) {
            sWord = s.substr(0, pos);

            if (sWord != "")
                vString.push_back(sWord);

            s.erase(0, pos + Delimter.length());
        }

        if (s != "")
            vString.push_back(s);

        return vString;
    }
   std::vector<std::string> SplitString( std::string Delimter) {
      return  SplitString(_Value,  Delimter);
   }
   
  static std::string RemovePunctuationFromString(std::string S1)
    {
        std::string s2 = "";

        for (char c : S1) {
            if (!std::ispunct(c))
                s2 += c;
        }

        return s2;
    }
  std::string RemovePunctuationFromString() {

      return RemovePunctuationFromString(_Value);
  }

  static std::string ReplaceWordInStringUsingBultInFunction(std::string S1, std::string StringToReplace, std::string sReplaceTo) {
        short Pos = S1.find(StringToReplace);
        while (Pos != std::string::npos) {
            S1 = S1.replace(Pos, StringToReplace.length(), sReplaceTo);
            Pos = S1.find(StringToReplace);
        }
        return S1;
    }
  std::string ReplaceWordInStringUsingBultInFunction( std::string StringToReplace, std::string sReplaceTo) {
      return  ReplaceWordInStringUsingBultInFunction(_Value, StringToReplace, sReplaceTo);
  }


static std::string ReverseWordsInString(std::string S1) {
        std::string S2 = "";
        std::vector<std::string> vString = SplitString(S1, " ");
        std::vector<std::string>::iterator iter = vString.end();

        while (iter != vString.begin()) {
            iter--;
            S2 += *iter + " ";
        }

        S2 = S2.substr(0, S2.length() - 1);
        return S2;
    }
std::string ReverseWordsInString() {
    return  ReverseWordsInString(_Value);
}


 static   std::string JoinString(std::vector<std::string> vString, std::string Delim) {
        std::string S1 = "";
        for (std::string& s : vString) {
            S1 += s + Delim;
        }
        return S1.substr(0, S1.length() - Delim.length());
    }

   static std::string JoinString(std::string arrString[100], short Length, std::string Delim) {
        std::string S1 = "";
        for (short i = 0; i < Length; i++) {
            S1 += arrString[i] + Delim;
        }
        return S1.substr(0, S1.length() - Delim.length());
    }

  static std::string TrimLeft(std::string s) {
        for (short i = 0; i < s.length(); i++) {
            if (s[i] != ' ') {
                return s.substr(i, s.length() - i);
            }
        }
        return "";
    }
  std::string TrimLeft() {
      return TrimLeft(_Value);
  }


 static std::string TrimRight(std::string s) {
        for (short i = s.length() - 1; i >= 0; i--) {
            if (s[i] != ' ') {
                return s.substr(0, i + 1);
            }
        }
        return "";
    }
 std::string TrimRight() {
     return  TrimRight(_Value);
 }


  static  std::string Trim(std::string s) {
        return TrimRight(TrimLeft(s));
    }
  std::string Trim() {
      return  Trim(_Value);
  }


   static void PrintEachWordInString(std::string s) {
        std::string Delimter = " ";
        std::string sWord;
        short pos;

        while ((pos = s.find(Delimter)) != std::string::npos) {
            sWord = s.substr(0, pos);

            if (sWord != "")
                std::cout << sWord << std::endl;

            s.erase(0, pos + Delimter.length());
        }

        if (s != "")
            std::cout << s << std::endl;
    }
   void PrintEachWordInString() {
       return  PrintEachWordInString(_Value);
   }


   static short CountWords(std::string s) {
        short counter = 0;
        std::string Delimter = " ";
        std::string sWord;
        short pos;

        while ((pos = s.find(Delimter)) != std::string::npos) {
            sWord = s.substr(0, pos);

            if (sWord != "")
                counter++;

            s.erase(0, pos + Delimter.length());
        }

        if (s != "")
            counter++;

        return counter;
    }
   short CountWords() {
       return  CountWords(_Value);

   
   }


    static std::string UpperAllLetters(std::string s1) {
        for (size_t i = 0; i < s1.length(); i++) {
            s1[i] = std::toupper(s1[i]);
        }
        return s1;
    }
    std::string UpperAllLetters() {
        return  UpperAllLetters(_Value);
    }


  static std::string LowerAllLetters(std::string s1) {
        for (size_t i = 0; i < s1.length(); i++) {
            s1[i] = std::tolower(s1[i]);
        }
        return s1;
    }
  std::string LowerAllLetters() {
      return  LowerAllLetters(_Value);
  }


 static short CountLetter(const std::string& s, char Letter, bool MatchCase = true) {
        short counter = 0;

        for (short i = 0; i < s.length(); i++) {
            if (MatchCase) {
                if (s[i] == Letter)
                    counter++;
            }
            else {
                if (std::tolower(s[i]) == std::tolower(Letter))
                    counter++;
            }
        }

        return counter;
    }
 short CountLetter( char Letter, bool MatchCase = true) {

     return CountLetter(_Value, Letter, MatchCase);
 }


 static void PrintFirstLetterOfEachWord(std::string s1) {
        bool IsFirstLetter = true;

        for (size_t i = 0; i < s1.length(); i++) {
            if (s1[i] != ' ' && IsFirstLetter) {
                std::cout << s1[i] << " ";
            }

            IsFirstLetter = (s1[i] == ' ');
        }
    }
 void PrintFirstLetterOfEachWord() {
     return  PrintFirstLetterOfEachWord(_Value);
 }


   static bool IsVowel(char Ch1) {
        Ch1 = std::tolower(Ch1);
        return ((Ch1 == 'a') || (Ch1 == 'e') || (Ch1 == 'i') || (Ch1 == 'o') || (Ch1 == 'u'));
    }

  static short CountVowels(std::string s) {
        short counter = 0;
        for (char e : s) {
            if (IsVowel(e))
                counter++;
        }
        return counter;
    }
  short CountVowels() {
      return  CountVowels(_Value);
  }
  

  static void PrintVowelsInString(std::string s) {
        std::cout << "\nVowels in the string are : ";
        for (char e : s) {
            if (IsVowel(e))
                std::cout << e << " ";
        }
    }
  void PrintVowelsInString() {
      return  PrintVowelsInString(_Value);
  }


  static std::string UpperEachLetterOfEachWord(std::string s1) {
        bool IsFirstLetter = true;

        for (size_t i = 0; i < s1.length(); i++) {
            if (s1[i] != ' ' && IsFirstLetter) {
                s1[i] = std::toupper(s1[i]);
            }

            IsFirstLetter = (s1[i] == ' ');
        }

        return s1;
    }
  std::string UpperEachLetterOfEachWord() {
      return  UpperEachLetterOfEachWord(_Value);
  }


 static std::string LowerEachLetterOfEachWord(std::string s1) {
        bool IsFirstLetter = true;

        for (size_t i = 0; i < s1.length(); i++) {
            if (s1[i] != ' ' && IsFirstLetter) {
                s1[i] = std::tolower(s1[i]);
            }

            IsFirstLetter = (s1[i] == ' ');
        }

        return s1;
    }
 std::string LowerEachLetterOfEachWord() {
     return LowerEachLetterOfEachWord(_Value);
 }



  static char InvertLetterCase(char c) {
        return (std::isupper(c) ? std::tolower(c) : std::toupper(c));
    }
 
 
 
 static std::string InverAllStringLettersCase(std::string& s) {
        for (short i = 0; i < s.length(); i++) {
            s[i] = InvertLetterCase(s[i]);
        }
        return s;
    }
 std::string InverAllStringLettersCase() {
       return  InverAllStringLettersCase(_Value);

   }


   static short GetCapitalLerttersCount(std::string S1) {
        short CapitalCount = 0;
        for (short i = 0; i < S1.length(); i++) {
            if (std::isupper(S1[i]))
                CapitalCount++;
        }
        return CapitalCount;
    }
   short GetCapitalLerttersCount() {
       return  GetCapitalLerttersCount(_Value);
   }



   static short GetSmallLerttersCount(std::string S1) {
        short SmallCount = 0;
        for (short i = 0; i < S1.length(); i++) {
            if (std::islower(S1[i]))
                SmallCount++;
        }
        return SmallCount;
    }
   short GetSmallLerttersCount() {
       return  GetSmallLerttersCount(_Value);
   }


    enum enWhatToCount { SmallLetter = 0, CapitalLetter = 1, All = 3 };

   static short CountCharacters(const std::string& s, enWhatToCount WhatToCount = enWhatToCount::All) {
        if (WhatToCount == enWhatToCount::All)
            return s.length();

        short Counter = 0;

        for (short i = 0; i < s.length(); i++) {
            if (WhatToCount == enWhatToCount::CapitalLetter && std::isupper(s[i]))
                Counter++;

            if (WhatToCount == enWhatToCount::SmallLetter && std::islower(s[i]))
                Counter++;
        }

        return Counter;
    }
   short CountCharacters( enWhatToCount WhatToCount = enWhatToCount::All) 
       {

           return      CountCharacters(_Value, WhatToCount);


       }



    static std::string ReplaceWordInStringUsingSplit(std::string S1, std::string StringToReplace, std::string sRepalceTo, bool MatchCase = true) {
        std::vector<std::string> vString = SplitString(S1, " ");

        for (std::string& s : vString) {
            if (MatchCase) {
                if (s == StringToReplace)
                    s = sRepalceTo;
            }
            else {
                if (LowerAllLetters(s) == LowerAllLetters(StringToReplace))
                    s = sRepalceTo;
            }
        }

        return JoinString(vString, " ");
    }
    std::string ReplaceWordInStringUsingSplit(std::string StringToReplace, std::string sRepalceTo, bool MatchCase = true) {

        return  ReplaceWordInStringUsingSplit(_Value, StringToReplace, sRepalceTo, MatchCase);

    }

    static short Length(const string &  s) {
        return s.length();
    }
    short Length() {
        return Length(_Value);
    }
   
};

