// Fill out your copyright notice in the Description page of Project Settings.

#include "QPTimeUtils.h"
#include "Runtime/Core/Public/Misc/DateTime.h"

UQPTimeUtils* UQPTimeUtils::GetInstance(int32 DefaultYear, int32 DefaultMonth, int32 DefaultDay, int32 DefaultHour, int32 DefaultMinute, int32 DefaultSecond) {
	UQPTimeUtils* timeUtils = NewObject<UQPTimeUtils>();
	timeUtils->SetDefaultTime(DefaultYear, DefaultMonth, DefaultDay, DefaultHour, DefaultMinute, DefaultSecond);
	return timeUtils;
}

UQPTimeUtils::UQPTimeUtils() {
	_isReset = false;
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
	if (_isReset){
		_DateTime = FDateTime(_Year, _Month, _Day, _Hour, _Minute, _Second, 0);
		_isReset = false;
	}
	return (FDateTime::Now() - _DateTime);
}

int64 UQPTimeUtils::GetElapsedYear() {

	int32 year, month, day;
	FDateTime time = FDateTime::Now();
	int64 hour = time.GetHour();
	int64 minutes = time.GetMinute();
	int64 seconds = time.GetSecond();
	time.GetDate(year, month, day);

	int64 yearNum = year - _Year;

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

int64 UQPTimeUtils::GetElapsedMonth(){

	int32 year, month, day;
	FDateTime time = FDateTime::Now();
	int64 hour = time.GetHour();
	int64 minutes = time.GetMinute();
	int64 seconds = time.GetSecond();

	time.GetDate(year, month, day);
	int64 yearNum = year - _Year;
	int64 monthNum = (year - _Year) * 12 + month - _Month;

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

int64 UQPTimeUtils::GetElapsedDay() {
	return GetElapsedDateTime().GetTotalDays();
}

int64 UQPTimeUtils::GetElapsedHour() {
	return GetElapsedDateTime().GetTotalHours();
}

int64 UQPTimeUtils::GetElapsedMinute() {
	return GetElapsedDateTime().GetTotalMinutes();
}

int64 UQPTimeUtils::GetElapsedSecond() {
	return GetElapsedDateTime().GetTotalSeconds();
}

FString UQPTimeUtils::GetElapsedStringYear() {

	return FString::SanitizeFloat(this->GetElapsedYear());
}

FString UQPTimeUtils::GetElapsedStringMonth(){

	return FString::SanitizeFloat(this->GetElapsedMonth());
	
}

FString UQPTimeUtils::GetElapsedStringDay() {
	return FString::SanitizeFloat(this->GetElapsedDay());
}

FString UQPTimeUtils::GetElapsedStringHour() {
	return FString::SanitizeFloat(this->GetElapsedHour());
}

FString UQPTimeUtils::GetElapsedStringMinute() {
	return FString::SanitizeFloat(this->GetElapsedMinute());
}

FString UQPTimeUtils::GetElapsedStringSecond() {
	return FString::SanitizeFloat(this->GetElapsedSecond());
}

FString UQPTimeUtils::GetFutureStringYear() {
	return FString::SanitizeFloat(-this->GetElapsedYear());
}

FString UQPTimeUtils::GetFutureStringMonth(){
	return FString::SanitizeFloat(-this->GetElapsedMonth());
}

FString UQPTimeUtils::GetFutureStringDay() {
	return FString::SanitizeFloat(-this->GetElapsedDay());
}

FString UQPTimeUtils::GetFutureStringHour() {
	return FString::SanitizeFloat(-this->GetElapsedHour());
}

FString UQPTimeUtils::GetFutureStringMinute() {
	return FString::SanitizeFloat(-this->GetElapsedMinute());
}

FString UQPTimeUtils::GetFutureStringSecond() {
	return FString::SanitizeFloat(-this->GetElapsedSecond());
}


void UQPTimeUtils::SetYear(int32 time){
	_isReset = true;
	_Year = time;
}

void UQPTimeUtils::SetMonth(int32 time){
	_isReset = true;
	_Month = time;
}

void UQPTimeUtils::SetDay(int32 time){
	_isReset = true;
	_Day = time;
}

void UQPTimeUtils::SetHour(int32 time){
	_isReset = true;
	_Hour = time;
}

void UQPTimeUtils::SetMinute(int32 time){
	_isReset = true;
	_Minute = time;
}

void UQPTimeUtils::SetSecond(int32 time){
	_isReset = true;
	_Second = time;
}

void UQPTimeUtils::SetTimeByKey(EQPTimeType key, int32 time) {
	_isReset = true;
	switch (key)
	{
	case EQPTimeType::Year :
		_Year = time;
		break;
	case EQPTimeType::Month :
		_Month = time;
		break;
	case EQPTimeType::Day :
		_Day = time;
		break;
	case EQPTimeType::Hour :
		_Hour = time;
		break;
	case EQPTimeType::Minute :
		_Minute = time;
		break;
	case EQPTimeType::Second :
		_Second = time;
		break;
	default:
		break;
	}
}


int32 UQPTimeUtils::GetYear(){
	return _Year;
}

int32 UQPTimeUtils::GetMonth(){
	return _Month;
}

int32 UQPTimeUtils::GetDay(){
	return _Day;
}

int32 UQPTimeUtils::GetHour(){
	return _Hour;
}

int32 UQPTimeUtils::GetMinute(){
	return _Minute;
}

int32 UQPTimeUtils::GetSecond(){
	return _Second;
}

int32 UQPTimeUtils::GetTimeByKey(EQPTimeType key){
	switch (key)
	{
	case EQPTimeType::Year :
		return _Year;
		break;
	case EQPTimeType::Month :
		return _Month;
		break;
	case EQPTimeType::Day :
		return _Day;
		break;
	case EQPTimeType::Hour :
		return _Hour;
		break;
	case EQPTimeType::Minute :
		return _Minute;
		break;
	case EQPTimeType::Second :
		return _Second;
		break;
	default:
		break;
	}
	return 0;
}