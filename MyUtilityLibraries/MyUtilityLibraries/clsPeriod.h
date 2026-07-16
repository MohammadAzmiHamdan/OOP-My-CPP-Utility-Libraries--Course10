#pragma once
#include<iostream>
#include "clsDate.h"
using namespace std; 
class clsPeriod
{
public:

    clsDate StartDate;
    clsDate EndDate;

    clsPeriod(clsDate StartDate, clsDate DateTo)
    {
        this->StartDate = StartDate;
        this->EndDate = EndDate;

    }

    static bool IsOverlapPeriods(clsPeriod Period1, clsPeriod Period2)
    {

        if (
            clsDate::CompareDates(Period2.EndDate, Period1.StartDate) == clsDate::eDateCompare::Before
            ||
            clsDate::CompareDates(Period2.StartDate, Period1.EndDate) == clsDate::eDateCompare::After
            )
            return false;
        else
            return true;

    }
    bool IsOverLapWith(clsPeriod Period2)
    {
        return IsOverlapPeriods(*this, Period2);
    }


   static int PeriodLengthInDays(clsPeriod Period, bool IncludeEndDate = false) {
        return clsDate::GetDifferenceInDays(Period.StartDate, Period.EndDate, IncludeEndDate);
    }
   int PeriodLengthInDays(bool IncludeEndDate = false) {
       return PeriodLengthInDays(*this, IncludeEndDate);

   }
   
   
   static bool IsDateInPeriod(clsDate Date, clsPeriod Period) {
        return !(clsDate::CompareDates(Date, Period.StartDate) == clsDate::eDateCompare::Before
            || clsDate::CompareDates(Date, Period.EndDate) == clsDate::eDateCompare::After);
    }
   bool IsDateInPeriod(clsDate Date) {
       return IsDateInPeriod(Date, *this);
   }


 static int CountOverlapDays(clsPeriod Period1, clsPeriod Period2) {
        int Period1Length = PeriodLengthInDays(Period1, true);
        int Period2Length = PeriodLengthInDays(Period2, true);

        if (!IsOverlapPeriods(Period1, Period2))
            return 0;

        int OverLapDays = 0;
        if (Period1Length < Period2Length) {
            while (clsDate::IsDate1BeforeDate2(Period1.StartDate, Period1.EndDate)) {
                if (IsDateInPeriod(Period1.StartDate, Period2))
                    OverLapDays++;
                Period1.StartDate = clsDate::IncreaseDateByOneDay(Period1.StartDate);
            }
        }
        else {
            while (clsDate::IsDate1BeforeDate2(Period2.StartDate, Period2.EndDate)) {
                if (IsDateInPeriod(Period2.StartDate, Period1))
                    OverLapDays++;
                Period2.StartDate = clsDate::IncreaseDateByOneDay(Period2.StartDate);
            }
        }
        return OverLapDays;
    }
 int CountOverlapDays(clsPeriod Period) {
     return  CountOverlapDays(*this, Period);
 }
   

 static void PrintPeriod(clsPeriod Period)
    {
     cout << "Period Start: ";
      Period.StartDate.Print();


     cout << "\nPeriod End: ";
     Period.EndDate.Print();


    }
 void Print() {
     PrintPeriod(*this);

 }

};
