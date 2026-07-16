#pragma once

#pragma warning(disable : 4996)

#include <iostream>
#include <vector>
#include <ctime>
#include <string>
#include "clsString.h"
using namespace std;
class clsDate
{
private:
	short _Day;
	short _Month;
	short _Year;
public:
    clsDate() {
        *this = GetSystemTime();
    }
    clsDate( string DateString) {
        *this = StringToDate(DateString);
    }
    clsDate(short Day,short Month ,short Year) {
        _Day = Day;
        _Month = Month;
        _Year = Year;

    }
    clsDate(short DayOrderInYear ,short Year ) {
        *this = GetDateFromDayOrderInYear(DayOrderInYear, Year);

    }


    __declspec(property(get = GetDay, put = SetDay)) short Day;
    __declspec(property(get = GetMonth, put = SetMonth)) short Month;
    __declspec(property(get = GetYear, put = SetYear)) short Year;

    void SetDay(short Day)
    {
        _Day = Day;
    }

    short GetDay()
    {
        return _Day;
    }

    void SetMonth(short Month)
    {
        _Month = Month;
    }

    short GetMonth()
    {
        return _Month;
    }

    void SetYear(short Year)
    {
        _Year = Year;
    }

    short GetYear()
    {
        return _Year;
    }

    enum eDateCompare { Equal = 0, After = 1, Before = -1 };

    static clsDate GetSystemTime()
    {
        time_t t = time(0);
        tm* now = localtime(&t);

        return clsDate(
            now->tm_mday,
            now->tm_mon + 1,
            now->tm_year + 1900
        );
    }

   

   static clsDate StringToDate(std::string StringDate) {
       clsDate Date;
       std::vector<std::string> vDate;
       vDate = clsString::SplitString(StringDate, "/");
       Date.Day = stoi(vDate[0]);
       Date.Month = stoi(vDate[1]);
       Date.Year = stoi(vDate[2]);
       return Date;
   }


   static bool IsLeapYear(short year) {
        return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    }
   bool IsLeapYear() {
       return IsLeapYear(_Year);
   }

  static short NumberOFDaysInAYear(short year) {
        return IsLeapYear(year) ? 366 : 365;
    }
  short NumberOFDaysInThisYear() {
      return  NumberOFDaysInAYear(_Year);
  }


  static int NumberOfHoursInAYear(short Year) {
        return 24 * NumberOFDaysInAYear(Year);
    }
   int NumberOfHoursInThisYear() {
      return NumberOfHoursInAYear(_Year);
   }


   static int NumberOfHoursInAYear(short Year)
   {
       return 24 * NumberOFDaysInAYear(Year);
   }
   int NumberOfHoursInThisYear()
   {
       return NumberOfHoursInAYear(_Year);
   }


   static int NumberOfMinutesInAYear(short Year)
   {
       return 60 * NumberOfHoursInAYear(Year);
   }
   int NumberOfMinutesInThisYear()
   {
       return NumberOfMinutesInAYear(_Year);
   }

   static int NumberOfSecondsInAYear(short Year)
   {
       return 60 * NumberOfMinutesInAYear(Year);
   }
   int NumberOfSecondsInThisYear()
   {
       return NumberOfSecondsInAYear(_Year);
   }

   static short NumberOfDaysInMonth(short Month, short Year)
   {
       if (Month < 1 || Month > 12)
           return 0;

       short NumberOfDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
       return Month == 2 ? (IsLeapYear(Year) ? 29 : 28) : NumberOfDays[Month - 1];
   }
   short NumberOfDaysInThisMonth()
   {
       return NumberOfDaysInMonth(_Month, _Year);
   }


   static int NumberOfHoursInMonth(short Month, short Year)
   {
       return 24 * NumberOfDaysInMonth(Month, Year);
   }
   int NumberOfHoursInThisMonth()
   {
       return NumberOfHoursInMonth(_Month, _Year);
   }


   static int NumberOfMinutesInMonth(short Month, short Year)
   {
       return 60 * NumberOfHoursInMonth(Month, Year);
   }
   int NumberOfMinutesInThisMonth()
   {
       return NumberOfMinutesInMonth(_Month, _Year);
   }


   static int NumberOfSecondsInMonth(short Month, short Year)
   {
       return 60 * NumberOfMinutesInMonth(Month, Year);
   }
   int NumberOfSecondsInThisMonth()
   {
       return NumberOfSecondsInMonth(_Month, _Year);
   }

  static short DayOfWeekOrder(short day, short month, short year) {
        short a, y, m;
        a = (14 - month) / 12;
        y = year - a;
        m = month + 12 * a - 2;
        return (day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
    }
  static  short DayOfWeekOrder(clsDate Date) {
        return DayOfWeekOrder(Date.Day, Date.Month, Date.Year);
    }
  short DayOfWeekOrder()
  {
      return DayOfWeekOrder(_Day, _Month, _Year);
  }


  static std::string DayShortName(short DayOfWeekOrder)
  {
      std::string arrDayNames[] = { "Sun","Mon","Tue","Wed","Thu","Fri","Sat" };
      return arrDayNames[DayOfWeekOrder];
  }
  std::string DayShortName()
  {
      return DayShortName(DayOfWeekOrder());
  }

  static std::string MonthShortName(short MonthNumber)
  {
      std::string Months[12] = {
          "Jan", "Feb", "Mar",
          "Apr", "May", "Jun",
          "Jul", "Aug", "Sep",
          "Oct", "Nov", "Dec"
      };
      return Months[MonthNumber - 1];
  }
  std::string MonthShortName()
  {
      return MonthShortName(_Month);
  }

  static void PrintMonthCalendar(short Month, short Year)
  {
      short current = DayOfWeekOrder(1, Month, Year);
      short NumberOfDays = NumberOfDaysInMonth(Month, Year);

      printf("\n  _______________%s_______________\n\n", MonthShortName(Month).c_str());
      printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

      short i;
      for (i = 0; i < current; i++) {
          printf("     ");
      }
      for (short j = 1; j <= NumberOfDays; j++) {
          printf("%5d", j);
          if (++i == 7) {
              i = 0;
              printf("\n");
          }
      }
      printf("\n __________________________________\n");
  }
  void PrintMonthCalendar()
  {
      PrintMonthCalendar(_Month, _Year);
  }

  static void PrintYearCalenar(short Year)
  {
      printf("\n __________________________________\n\n");
      printf("            Calendar - %d\n", Year);
      printf(" __________________________________\n");
      for (short i = 1; i <= 12; i++) {
          PrintMonthCalendar(i, Year);
      }
  }
  void PrintYearCalenar()
  {
      PrintYearCalenar(_Year);
  }

  static short NumberOfDaysFromTheBeginingOfTheYear(short day, short month, short year)
  {
      short DayNumbers = 0;
      for (short i = 1; i < month; i++) {
          DayNumbers += NumberOfDaysInMonth(i, year);
      }
      DayNumbers += day;
      return DayNumbers;
  }
  short NumberOfDaysFromTheBeginingOfTheYear()
  {
      return NumberOfDaysFromTheBeginingOfTheYear(_Day, _Month, _Year);
  }
  

  static clsDate ReadFullDate()
  {
      clsDate sDate;
      std::cout << " Please enter a year?";
      std::cin >> sDate._Year;
      std::cout << " Please enter a Month?";
      std::cin >> sDate._Month;
      std::cout << " Please enter a Day?";
      std::cin >> sDate._Day;
      return sDate;
  }
  void ReadFullDateFromUser()
  {
      *this = ReadFullDate();
  }

    static clsDate GetDateFromDayOrderInYear(short DayOrderInYear, short Year) {
        clsDate sDate;
        short RamainingDays = DayOrderInYear;
        sDate.Month = 1;
        sDate.Year = Year;
        short MonthDays;
        while (true) {
            MonthDays = NumberOfDaysInMonth(sDate.Month, Year);
            if (RamainingDays > MonthDays) {
                RamainingDays -= MonthDays;
                sDate.Month++;
            }
            else {
                sDate.Day = RamainingDays;
                break;
            }
        }
        return sDate;
    }

    clsDate DateAddDays(short Days, clsDate sDate) {
        short RamainingDays = Days + NumberOfDaysFromTheBeginingOfTheYear(sDate._Day, sDate._Month, sDate._Year);
        short MonthDays;
        sDate._Month = 1;
        while (true) {
            MonthDays = NumberOfDaysInMonth(sDate._Month, sDate._Year);
            if (RamainingDays > MonthDays) {
                sDate._Month++;
                RamainingDays -= MonthDays;
                if (sDate._Month > 12) {
                    sDate._Month = 1;
                    sDate._Year++;
                }
            }
            else {
                sDate._Day = RamainingDays;
                break;
            }
        }
        return sDate;
    }
    void DateAddDays(short Days)
    {
        *this = DateAddDays(Days, *this);
    }



    static bool IsDate1BeforeDate2(clsDate Date1, clsDate Date2)
    {
        return (Date1._Year < Date2._Year) ? true : (Date1._Year == Date2._Year ?
            (Date1._Month < Date2._Month) ? true : (Date1._Month == Date2._Month ?
                Date1._Day < Date2._Day : false) : false);
    }
    bool IsBeforeDate2(clsDate Date2)
    {
        return IsDate1BeforeDate2(*this, Date2);
    }

    static bool IsDate1EqualDate2(clsDate Date1, clsDate Date2)
    {
        return (Date1._Year == Date2._Year) && (Date1._Month == Date2._Month) && (Date1._Day == Date2._Day);
    }
    bool IsEqualDate2(clsDate Date2)
    {
        return IsDate1EqualDate2(*this, Date2);
    }

    static bool IsLastDayInAMonth(clsDate Date)
    {
        return Date._Day == NumberOfDaysInMonth(Date._Month, Date._Year);
    }
    bool IsLastDayInAMonth()
    {
        return IsLastDayInAMonth(*this);
    }

    static bool IsLastMonthInAYear(clsDate Date)
    {
        return Date._Month == 12;
    }
    bool IsLastMonthInAYear()
    {
        return IsLastMonthInAYear(*this);
    }

    static clsDate IncreaseDateByOneDay(clsDate Date)
    {
        if (IsLastDayInAMonth(Date)) {
            if (IsLastMonthInAYear(Date)) {
                Date._Day = 1;
                Date._Month = 1;
                Date._Year++;
            }
            else {
                Date._Day = 1;
                Date._Month++;
            }
        }
        else {
            Date._Day++;
        }
        return Date;
    }
    void IncreaseDateByOneDay()
    {
        *this = IncreaseDateByOneDay(*this);
    }

    //
    static void SwapDates(clsDate& Date1, clsDate& Date2)
    {
        clsDate TempDate;
        TempDate._Year = Date1._Year;
        TempDate._Month = Date1._Month;
        TempDate._Day = Date1._Day;

        Date1._Year = Date2._Year;
        Date1._Month = Date2._Month;
        Date1._Day = Date2._Day;

        Date2._Year = TempDate._Year;
        Date2._Month = TempDate._Month;
        Date2._Day = TempDate._Day;
    }
    void SwapDates(clsDate& Date2)
    {
        SwapDates(*this, Date2);
    }


    static int GetDifferenceInDays(clsDate Date1, clsDate Date2, bool IncludeEndDay = false)
    {
        int Days = 0;
        short SwapFlagValue = 1;

        if (!IsDate1BeforeDate2(Date1, Date2)) {
            SwapFlagValue = -1;
            SwapDates(Date1, Date2);
        }

        while (IsDate1BeforeDate2(Date1, Date2)) {
            Days++;
            Date1 = IncreaseDateByOneDay(Date1);
        }

        return IncludeEndDay ? (++Days) * SwapFlagValue : Days * SwapFlagValue;
    }
    int GetDifferenceInDays(clsDate Date2, bool IncludeEndDay = false)
    {
        return GetDifferenceInDays(*this, Date2, IncludeEndDay);
    }
   

    static clsDate IncreasDateByXDays(short Days, clsDate Date)
    {
        for (short i = 0; i < Days; i++) {
            Date = IncreaseDateByOneDay(Date);
        }
        return Date;
    }
    void IncreaseDateByXDays(short Days)
    {
        *this = IncreasDateByXDays(Days, *this);
    }


    static clsDate IncreaseDateByOneWeek(clsDate Date)
    {
        return IncreasDateByXDays(7, Date);
    }
    void IncreaseDateByOneWeek()
    {
        *this = IncreaseDateByOneWeek(*this);
    }


    static clsDate IncreaseDateByXWeeks(short Weeks, clsDate Date)
    {
        for (short i = 0; i < Weeks; i++) {
            Date = IncreaseDateByOneWeek(Date);
        }
        return Date;
    }
    void IncreaseDateByXWeeks(short Weeks)
    {
        *this = IncreaseDateByXWeeks(Weeks, *this);
    }


    static clsDate IncreaseDateByOneMonth(clsDate Date)
    {
        if (IsLastMonthInAYear(Date)) {
            Date._Day = 1;
            Date._Month = 1;
            Date._Year++;
        }
        else {
            Date._Month++;
        }

        short NumberOfDaysInCurrentMonth = NumberOfDaysInMonth(Date._Month, Date._Year);

        if (NumberOfDaysInCurrentMonth < Date._Day) {
            Date._Day = NumberOfDaysInCurrentMonth;
        }

        return Date;
    }
    void IncreaseDateByOneMonth()
    {
        *this = IncreaseDateByOneMonth(*this);
    }


    static clsDate IncreaseDateByXMonths(clsDate Date, short Months)
    {
        for (short i = 1; i <= Months; i++) {
            Date = IncreaseDateByOneMonth(Date);
        }
        return Date;
    }
    void IncreaseDateByXMonths(short Months)
    {
        *this = IncreaseDateByXMonths(*this, Months);
    }


    static clsDate IncreaseDateByOneYear(clsDate Date)
    {
        Date._Year++;
        return Date;
    }
    void IncreaseDateByOneYear()
    {
        *this = IncreaseDateByOneYear(*this);
    }


    static clsDate IncreaseDateByXYears(clsDate Date, short Years)
    {
        for (short i = 1; i <= Years; i++) {
            Date = IncreaseDateByOneYear(Date);
        }
        return Date;
    }
    void IncreaseDateByXYears(short Years)
    {
        *this = IncreaseDateByXYears(*this, Years);
    }

    static clsDate IncreaseDateByXYearsFaster(clsDate Date, short Years)
    {
        Date._Year += Years;
        return Date;
    }
    void IncreaseDateByXYearsFaster(short Years)
    {
        *this = IncreaseDateByXYearsFaster(*this, Years);
    }


    static clsDate IncreaseDateByOneDecade(clsDate Date)
    {
        Date._Year += 10;
        return Date;
    }
    void IncreaseDateByOneDecade()
    {
        *this = IncreaseDateByOneDecade(*this);
    }


    static clsDate IncreaseDateByXDecades(clsDate Date, short Decades)
    {
        for (short i = 1; i <= Decades; i++) {
            Date = IncreaseDateByOneDecade(Date);
        }
        return Date;
    }
    void IncreaseDateByXDecades(short Decades)
    {
        *this = IncreaseDateByXDecades(*this, Decades);
    }


    static clsDate IncreaseDateByXDecadesFaster(clsDate Date, short Decades)
    {
        Date._Year += 10 * Decades;
        return Date;
    }
    void IncreaseDateByXDecadesFaster(short Decades)
    {
        *this = IncreaseDateByXDecadesFaster(*this, Decades);
    }


    static clsDate IncreaseDateByOneCentury(clsDate Date)
    {
        Date._Year += 100;
        return Date;
    }
    void IncreaseDateByOneCentury()
    {
        *this = IncreaseDateByOneCentury(*this);
    }


    static clsDate IncreaseDateByOneMillennium(clsDate Date)
    {
        Date._Year += 1000;
        return Date;
    }
    void IncreaseDateByOneMillennium()
    {
        *this = IncreaseDateByOneMillennium(*this);
    }


    static clsDate DecreaseDateByOneDay(clsDate Date)
    {
        if (Date._Day == 1) {
            if (Date._Month == 1) {
                Date._Year--;
                Date._Month = 12;
                Date._Day = 31;
            }
            else {
                Date._Month--;
                Date._Day = NumberOfDaysInMonth(Date._Month, Date._Year);
            }
        }
        else {
            Date._Day--;
        }

        return Date;
    }
    void DecreaseDateByOneDay()
    {
        *this = DecreaseDateByOneDay(*this);
    }


    static clsDate DecreaseDateByXDays(clsDate Date, short Days)
    {
        for (short i = 1; i <= Days; i++) {
            Date = DecreaseDateByOneDay(Date);
        }

        return Date;
    }
    void DecreaseDateByXDays(short Days)
    {
        *this = DecreaseDateByXDays(*this, Days);
    }


    static clsDate DecreaseDateByOneWeek(clsDate Date)
    {
        for (short i = 1; i <= 7; i++) {
            Date = DecreaseDateByOneDay(Date);
        }

        return Date;
    }
    void DecreaseDateByOneWeek()
    {
        *this = DecreaseDateByOneWeek(*this);
    }


    static clsDate DecreaseDateByXWeeks(clsDate Date, short Weeks)
    {
        for (short i = 1; i <= Weeks; i++) {
            Date = DecreaseDateByOneWeek(Date);
        }

        return Date;
    }
    void DecreaseDateByXWeeks(short Weeks)
    {
        *this = DecreaseDateByXWeeks(*this, Weeks);
    }


    static clsDate DecreaseDateByOneMonth(clsDate Date)
    {
        if (Date._Month == 1) {
            Date._Year--;
            Date._Month = 12;
        }
        else {
            Date._Month--;
        }

        short NumberOfDaysInCurrentMonth = NumberOfDaysInMonth(Date._Month, Date._Year);

        if (Date._Day > NumberOfDaysInCurrentMonth) {
            Date._Day = NumberOfDaysInCurrentMonth;
        }

        return Date;
    }
    void DecreaseDateByOneMonth()
    {
        *this = DecreaseDateByOneMonth(*this);
    }

    static clsDate DecreaseDateByXMonths(clsDate Date, short Months)
    {
        for (short i = 1; i <= Months; i++) {
            Date = DecreaseDateByOneMonth(Date);
        }

        return Date;
    }
    void DecreaseDateByXMonths(short Months)
    {
        *this = DecreaseDateByXMonths(*this, Months);
    }


    static clsDate DecreaseDateByOneYear(clsDate Date)
    {
        Date._Year--;

        short NumberOfDaysInCurrentMonth = NumberOfDaysInMonth(Date._Month, Date._Year);

        if (Date._Day > NumberOfDaysInCurrentMonth) {
            Date._Day = NumberOfDaysInCurrentMonth;
        }

        return Date;
    }
    void DecreaseDateByOneYear()
    {
        *this = DecreaseDateByOneYear(*this);
    }


    static clsDate DecreaseDateByXYears(clsDate Date, short Years)
    {
        for (short i = 1; i <= Years; i++) {
            Date = DecreaseDateByOneYear(Date);
        }

        return Date;
    }
    void DecreaseDateByXYears(short Years)
    {
        *this = DecreaseDateByXYears(*this, Years);
    }


    static clsDate DecreaseDateByXYearsFaster(clsDate Date, short Years)
    {
        Date._Year -= Years;
        return Date;
    }
    void DecreaseDateByXYearsFaster(short Years)
    {
        *this = DecreaseDateByXYearsFaster(*this, Years);
    }


    static clsDate DecreaseDateByOneDecade(clsDate Date)
    {
        Date._Year -= 10;

        short NumberOfDaysInCurrentMonth = NumberOfDaysInMonth(Date._Month, Date._Year);

        if (Date._Day > NumberOfDaysInCurrentMonth) {
            Date._Day = NumberOfDaysInCurrentMonth;
        }

        return Date;
    }
    void DecreaseDateByOneDecade()
    {
        *this = DecreaseDateByOneDecade(*this);
    }


    static clsDate DecreaseDateByXDecades(clsDate Date, short Decades)
    {
        for (short i = 1; i <= Decades; i++) {
            Date = DecreaseDateByOneDecade(Date);
        }

        return Date;
    }
    void DecreaseDateByXDecades(short Decades)
    {
        *this = DecreaseDateByXDecades(*this, Decades);
    }


    static clsDate DecreaseDateByXDecadesFaster(clsDate Date, short Decades)
    {
        Date._Year -= Decades * 10;
        return Date;
    }
    void DecreaseDateByXDecadesFaster(short Decades)
    {
        *this = DecreaseDateByXDecadesFaster(*this, Decades);
    }


    static clsDate DecreaseDateByOneCentury(clsDate Date)
    {
        Date._Year -= 100;
        return Date;
    }
    void DecreaseDateByOneCentury()
    {
        *this = DecreaseDateByOneCentury(*this);
    }


    static clsDate DecreaseDateByOneMillennium(clsDate Date)
    {
        Date._Year -= 1000;
        return Date;
    }
    void DecreaseDateByOneMillennium()
    {
        *this = DecreaseDateByOneMillennium(*this);
    }


    static bool IsEndOfWeek(clsDate Date)
    {
        return DayOfWeekOrder(Date) == 6;
    }
    bool IsEndOfWeek()
    {
        return IsEndOfWeek(*this);
    }


    static bool IsWeekEnd(clsDate Date)
    {
        short DayIndex = DayOfWeekOrder(Date);
        return DayIndex == 6 || DayIndex == 5;
    }
    bool IsWeekEnd()
    {
        return IsWeekEnd(*this);
    }


    static bool IsBusinessDay(clsDate Date)
    {
        return !IsWeekEnd(Date);
    }
    bool IsBusinessDay()
    {
        return IsBusinessDay(*this);
    }

    static short DaysUntilTheEndOfWeek(clsDate Date)
    {
        return 6 - DayOfWeekOrder(Date);
    }
    short DaysUntilTheEndOfWeek()
    {
        return DaysUntilTheEndOfWeek(*this);
    }


    static short DaysUntilTheEndOfMonth(clsDate Date1)
    {
        clsDate EndOfMonthDate;

        EndOfMonthDate._Day = NumberOfDaysInMonth(Date1._Month, Date1._Year);
        EndOfMonthDate._Month = Date1._Month;
        EndOfMonthDate._Year = Date1._Year;

        return GetDifferenceInDays(Date1, EndOfMonthDate, true);
    }
    short DaysUntilTheEndOfMonth()
    {
        return DaysUntilTheEndOfMonth(*this);
    }


    static short DaysUntilTheEndOfYear(clsDate Date1)
    {
        clsDate EndOfYearDate;

        EndOfYearDate._Day = 31;
        EndOfYearDate._Month = 12;
        EndOfYearDate._Year = Date1._Year;

        return GetDifferenceInDays(Date1, EndOfYearDate, true);
    }
    short DaysUntilTheEndOfYear()
    {
        return DaysUntilTheEndOfYear(*this);
    }


    static short CalculateVacationDays(clsDate DateFrom, clsDate DateTo)
    {
        short DaysCount = 0;

        while (IsDate1BeforeDate2(DateFrom, DateTo)) {

            if (IsBusinessDay(DateFrom))
                DaysCount++;

            DateFrom = IncreaseDateByOneDay(DateFrom);
        }

        return DaysCount;
    }


    static clsDate CalculateVacationReturnDate(clsDate DateFrom, short VacationDays)
    {
        while (IsWeekEnd(DateFrom)) {
            DateFrom = IncreaseDateByOneDay(DateFrom);
        }

        short WeekEndCounter = 0;

        for (short i = 1; i <= VacationDays + WeekEndCounter; i++) {

            if (IsWeekEnd(DateFrom))
                WeekEndCounter++;

            DateFrom = IncreaseDateByOneDay(DateFrom);
        }

        while (IsWeekEnd(DateFrom)) {
            DateFrom = IncreaseDateByOneDay(DateFrom);
        }

        return DateFrom;
    }


    static bool IsDate1AfterDate2(clsDate Date1, clsDate Date2)
    {
        return (!IsDate1BeforeDate2(Date1, Date2) &&
            !IsDate1EqualDate2(Date1, Date2));
    }
    bool IsAfterDate2(clsDate Date2)
    {
        return IsDate1AfterDate2(*this, Date2);
    }


    static eDateCompare CompareDates(clsDate Date1, clsDate Date2)
    {
        if (IsDate1BeforeDate2(Date1, Date2))
            return eDateCompare::Before;

        if (IsDate1EqualDate2(Date1, Date2))
            return eDateCompare::Equal;

        return eDateCompare::After;
    }
    eDateCompare CompareDates(clsDate Date2)
    {
        return CompareDates(*this, Date2);
    }


    static bool IsValidDate(clsDate Date)
    {
        if (Date._Month < 1 || Date._Month > 12 || Date._Year < 0)
            return false;

        if (Date._Day < 1 || Date._Day > 31)
            return false;

        if (Date._Month == 2) {

            if (IsLeapYear(Date._Year)) {

                if (Date._Day > 29)
                    return false;
            }
            else {

                if (Date._Day > 28)
                    return false;
            }
        }

        short NumberOfDaysInCurrentMonth = NumberOfDaysInMonth(Date._Month, Date._Year);

        if (Date._Day > NumberOfDaysInCurrentMonth)
            return false;

        return true;
    }
    bool IsValidDate()
    {
        return IsValidDate(*this);
    }

    static std::string DateToString(clsDate Date)
    {
        return std::to_string(Date._Day) + "/" +
            std::to_string(Date._Month) + "/" +
            std::to_string(Date._Year);
    }
    std::string DateToString()
    {
        return DateToString(*this);
    }


    static std::string FormateDate(clsDate Date, std::string DateFormat = "dd/mm/yyyy")
    {
        std::string FormattedDateString = "";

        FormattedDateString = clsString::ReplaceWordInStringUsingSplit(DateFormat, "dd", std::to_string(Date._Day));

        FormattedDateString = clsString::ReplaceWordInStringUsingSplit(FormattedDateString, "mm", std::to_string(Date._Month));

        FormattedDateString = clsString::ReplaceWordInStringUsingSplit(FormattedDateString, "yyyy", std::to_string(Date._Year));

        return FormattedDateString;
    }
    std::string FormateDate(std::string DateFormat = "dd/mm/yyyy")
    {
        return FormateDate(*this, DateFormat);
    }



    static void Print(clsDate Date) {
        cout << Date.FormateDate();
    }
    void Print() {
        cout << FormateDate();
    }
};

