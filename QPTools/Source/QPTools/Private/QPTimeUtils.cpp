// Fill out your copyright notice in the Description page of Project Settings.

#include "QPTimeUtils.h"
#include "Runtime/Core/Public/Misc/DateTime.h"

UQPTimeUtils* UQPTimeUtils::GetInstance(int32 DefaultYear, int32 DefaultMonth, int32 DefaultDay, int32 DefaultHour, int32 DefaultMinute, int32 DefaultSecond) {
	UQPTimeUtils* timeUtils = NewObject<UQPTimeUtils>();
	timeUtils->SetDefaultTime(DefaultYear, DefaultMonth, DefaultDay, DefaultHour, DefaultMinute, DefaultSecond);
	return timeUtils;
}

UQPTimeUtils::UQPTimeUtils() {
	_DateTimeNow = FDateTime::Now();
}

void UQPTimeUtils::SetDefaultTime(int32 DefaultYear, int32 DefaultMonth, int32 DefaultDay, int32 DefaultHour, int32 DefaultMinute, int32 DefaultSecond) {
	_Year = DefaultYear;
	_Month = DefaultMonth;
	_Day = DefaultDay;
	_Hour = DefaultHour;
	_Minute = DefaultMinute;
	_Second = DefaultSecond;
	_DateTime = FDateTime(_Year, _Month, _Day, _Hour, _Minute, _Second, 0);
}

FTimespan UQPTimeUtils::GetElapsedDateTime() {
	return (_DateTimeNow - _DateTime);
}

int32 UQPTimeUtils::GetElapsedYear() {

	int32 year, month, day;
	FDateTime time = FDateTime::Now();
	int32 hour = time.GetHour();
	int32 minutes = time.GetMinute();
	int32 seconds = time.GetSecond();
	time.GetDate(year, month, day);

	int32 yearNum = year - _Year;

	if (_Month > month + 1){
		yearNum--;
	}
	else if (_Month == month + 1){
		if (_Day > day){
			yearNum--;
		}
		else if (_Day == day){
			if (_Hour > hour){
				yearNum--;
			}
			else if (_Hour == hour){
				if (_Minute > minutes){
					yearNum--;
				}
				else if (_Minute == minutes){
					if (_Second > seconds){
						yearNum--;
					}
				}
			}
		}
	}
	return yearNum;
}

int32 UQPTimeUtils::GetElapsedMonth(){

	int32 year, month, day;
	FDateTime time = FDateTime::Now();
	int32 hour = time.GetHour();
	int32 minutes = time.GetMinute();
	int32 seconds = time.GetSecond();

	time.GetDate(year, month, day);
	int32 yearNum = year - _Year;
	int32 monthNum = (year - _Year) * 12 + month - _Month;

	if (_Day > day){
		monthNum--;
	}
	else if (_Day == day){
		if (_Hour > hour){
			monthNum--;
		}
		else if (_Hour == hour){
			if (_Minute > minutes){
				monthNum--;
			}
			else if (_Minute == minutes){
				if (_Second > seconds){
					monthNum--;
				}
			}
		}
	}
	return monthNum;
}

int32 UQPTimeUtils::GetElapsedDay() {
	return GetElapsedDateTime().GetTotalDays();
}

int32 UQPTimeUtils::GetElapsedHour() {
	return GetElapsedDateTime().GetTotalHours();
}

int32 UQPTimeUtils::GetElapsedMinute() {
	return GetElapsedDateTime().GetTotalMinutes();
}

int32 UQPTimeUtils::GetElapsedSecond() {
	return GetElapsedDateTime().GetTotalSeconds();
}
