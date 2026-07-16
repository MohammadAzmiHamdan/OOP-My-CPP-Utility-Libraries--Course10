# 🚀 C++ Utility Library Project
## String Manipulation & Date Management System

![Language](https://img.shields.io/badge/Language-C%2B%2B-blue)
![OOP](https://img.shields.io/badge/Concepts-OOP-green)
![Project](https://img.shields.io/badge/Project-Utility%20Library-orange)
<p align="center">
  <a href="https://github.com" style="text-decoration: none;">
    <kbd style="padding: 15px 35px; font-size: 18px; background: linear-gradient(135deg, #0366d6, #0056b3); color: #ffffff; border: 1px solid #0366d6; border-radius: 8px; font-family: -apple-system, BlinkMacSystemFont, 'Segoe UI', Helvetica, Arial, sans-serif; font-weight: bold; cursor: pointer; display: inline-block; box-shadow: 0 4px 12px rgba(3, 102, 214, 0.3); letter-spacing: 0.5px;">
      🚀 Related Project| Previous Project
    </kbd>
  </a>
</p>

## 📌 Overview

This project is a collection of reusable C++ utility classes developed during the fifth course of my C++ learning journey.

The project focuses on applying Object-Oriented Programming principles by designing independent classes that solve real-world programming problems.

The implemented classes are:

- `clsString` → Advanced string manipulation utility library.
- `clsDate` → Complete date management system.
- `clsPeriod` → Date period management and calculations.


The main goal of this project was not only implementing functions, but learning how to design clean, reusable, and maintainable C++ classes.


---

# 🧠 Object-Oriented Programming Concepts Applied

## 1. Encapsulation

Private data members are protected inside classes:

Example:

```cpp
private:
    string _Value;
private:
    short _Day;
    short _Month;
    short _Year;

Access is controlled using:

Getters
Setters
Properties
2. Constructors

Multiple constructors were implemented to initialize objects in different ways.

Example:

clsDate();
clsDate(string DateString);
clsDate(short Day, short Month, short Year);

Different object creation scenarios are supported:

clsDate Date1;

clsDate Date2("16/07/2026");

clsDate Date3(16,7,2026);
3. Static Functions

Functions that belong to the class itself instead of a specific object.

Example:

clsDate::IsLeapYear(2024);

Benefits:

Code reusability
Avoid unnecessary object creation
Better organization
4. Method Overloading

The same function name is used with different parameters.

Example:

DayOfWeekOrder(day,month,year);

DayOfWeekOrder(clsDate Date);
📂 Project Structure
📁 C++ Utility Library

│
├── clsString.h
│
├── clsDate.h
│
└── clsPeriod.h

🔤 clsString Class
Description

clsString is a custom string utility library that extends the basic functionality of C++ strings.

It provides operations for:

Splitting strings
Joining strings
Searching
Replacing
Formatting
Counting characters
Changing letter cases
clsString Features
Function	Description
SplitString	Splits string into vector using delimiter
RemovePunctuationFromString	Removes punctuation symbols
ReplaceWordInStringUsingBultInFunction	Replace words using find and replace
ReplaceWordInStringUsingSplit	Replace complete words
ReverseWordsInString	Reverse order of words
JoinString	Merge vector/string array into one string
TrimLeft	Remove spaces from left
TrimRight	Remove spaces from right
Trim	Remove spaces from both sides
CountWords	Count number of words
UpperAllLetters	Convert all letters to uppercase
LowerAllLetters	Convert all letters to lowercase
CountLetter	Count specific character
CountVowels	Count vowels
PrintVowelsInString	Display vowels
UpperEachLetterOfEachWord	Capitalize first letter of words
LowerEachLetterOfEachWord	Lowercase first letter of words
InvertLetterCase	Reverse letter case
InverAllStringLettersCase	Reverse all letters cases
GetCapitalLerttersCount	Count uppercase letters
GetSmallLerttersCount	Count lowercase letters
CountCharacters	Count characters based on type
PrintEachWordInString	Print each word separately
PrintFirstLetterOfEachWord	Display first letter of every word
Length	Return string length
📅 clsDate Class
Description

clsDate is a complete date handling system.

It manages:

Creating dates
Date validation
Date comparison
Date calculations
Calendar generation
Date formatting
Date Object Creation
clsDate Date1;

clsDate Date2("16/07/2026");

clsDate Date3(16,7,2026);

clsDate Date4(200,2026);
clsDate Features
Function	Description
GetSystemTime	Get current system date
StringToDate	Convert string to date object
IsLeapYear	Check leap year
NumberOfDaysInAYear	Get days in year
NumberOfHoursInAYear	Calculate hours
NumberOfMinutesInAYear	Calculate minutes
NumberOfSecondsInAYear	Calculate seconds
NumberOfDaysInMonth	Get month days
DayOfWeekOrder	Calculate weekday
DayShortName	Get weekday name
MonthShortName	Get month name
PrintMonthCalendar	Print monthly calendar
PrintYearCalenar	Print yearly calendar
NumberOfDaysFromTheBeginingOfTheYear	Days passed in year
GetDateFromDayOrderInYear	Convert day order to date
IncreaseDateByOneDay	Add one day
IncreaseDateByXDays	Add multiple days
IncreaseDateByOneMonth	Add month
IncreaseDateByXMonths	Add months
IncreaseDateByOneYear	Add year
IncreaseDateByXYears	Add years
DecreaseDateByOneDay	Subtract day
DecreaseDateByXDays	Subtract days
CompareDates	Compare two dates
GetDifferenceInDays	Calculate difference
IsValidDate	Validate date
DateToString	Convert date to string
FormateDate	Custom date formatting
⏳ clsPeriod Class
Description

clsPeriod manages a range between two dates.

Example:

Start Date
    |
    |
    |
End Date
clsPeriod Features
Function	Description
IsOverlapPeriods	Check if two periods overlap
IsOverLapWith	Check overlap with another period
PeriodLengthInDays	Calculate period length
IsDateInPeriod	Check if date exists inside period
CountOverlapDays	Calculate overlapping days
PrintPeriod	Display period information
💡 What I Learned

Through this project I improved my understanding of:

C++ OOP
Class design
Encapsulation
Constructors
Static members
Object interaction
Reusability
Programming Skills
Working with strings
Date algorithms
Problem solving
Designing utility libraries
Writing maintainable code
🚀 Future Improvements

Possible improvements:

Add exception handling
Add operator overloading
Add comparison operators
Add serialization support
Create unit tests
Improve documentation
👨‍💻 Author

Mohammad Hamdan

Computer Information Systems Student

C++ OOP Learning Journey

GitHub:
MohammadAzmiHamdan


---


I’m excited to share two new projects that I built during my C++ learning journey.

These projects focused on applying Object-Oriented Programming concepts and building reusable libraries from scratch.

📌 Project 1: clsString Utility Library

A custom string manipulation library that provides many useful operations such as:

✅ Splitting and joining strings
✅ Searching and replacing words
✅ Trimming spaces
✅ Counting characters and words
✅ Handling uppercase/lowercase conversion
✅ String formatting utilities

📌 Project 2: clsDate & clsPeriod Management System

A complete date management system that supports:

✅ Creating and formatting dates
✅ Date validation
✅ Leap year calculations
✅ Date comparison
✅ Date difference calculations
✅ Calendar generation
✅ Adding and subtracting days, months, years
✅ Managing periods and overlapping dates

One of the main things I focused on was applying OOP principles:

🔹 Encapsulation
🔹 Constructors
🔹 Static methods
🔹 Method overloading
🔹 Code reusability
🔹 Clean class design

Starting from simple concepts and gradually building real reusable components has been a great learning experience.

Every project is another step toward becoming a better software developer. 🚀

#Cplusplus
#OOP
#Programming
#SoftwareDevelopment
#ComputerScience
#LearningJourney
