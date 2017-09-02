// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"

/**
 *
 */
UENUM(BlueprintType)
enum class EQPTimeType : uint8
{
	Year,
	Month,
	Day,
	Hour,
	Minute,
	Second
};

#include "QPTimeUtils.generated.h"
UCLASS()
class  QPTOOLS_API UQPTimeUtils : public UObject
{
	GENERATED_BODY()
	
	FDateTime _DateTime;
	int32 _Year;
	int32 _Month;
	int32 _Day;
	int32 _Hour;
	int32 _Minute;
	int32 _Second;
	bool _isReset;
public:
	UQPTimeUtils();

	UFUNCTION(BlueprintPure, Category = "UQPTimeUtils")
	static UQPTimeUtils* GetInstance(int32 DefaultYear = 1, int32 DefaultMonth = 1, int32 DefaultDay = 1, int32 DefaultHour = 0, int32 DefaultMinute = 0, int32 DefaultSecond = 0);
	
	UFUNCTION(BlueprintCallable, Category = "UQPTimeUtils")
	void SetDefaultTime(int32 DefaultYear = 1, int32 DefaultMonth = 1, int32 DefaultDay = 1, int32 DefaultHour = 0, int32 DefaultMinute = 0, int32 DefaultSecond = 0);
	
	int64 GetElapsedYear();
	int64 GetElapsedMonth();
	int64 GetElapsedDay();
	int64 GetElapsedHour();
	int64 GetElapsedMinute();
	int64 GetElapsedSecond();

	UFUNCTION(BlueprintPure, Category = "UQPTimeUtils")
	FString GetElapsedStringYear();

	UFUNCTION(BlueprintPure, Category = "UQPTimeUtils")
	FString GetElapsedStringMonth();

	UFUNCTION(BlueprintPure, Category = "UQPTimeUtils")
	FString GetElapsedStringDay();

	UFUNCTION(BlueprintPure, Category = "UQPTimeUtils")
	FString GetElapsedStringHour();

	UFUNCTION(BlueprintPure, Category = "UQPTimeUtils")
	FString GetElapsedStringMinute();

	UFUNCTION(BlueprintPure, Category = "UQPTimeUtils")
	FString GetElapsedStringSecond();

	UFUNCTION(BlueprintPure, Category = "UQPTimeUtils")
	FString GetFutureStringYear();

	UFUNCTION(BlueprintPure, Category = "UQPTimeUtils")
	FString GetFutureStringMonth();

	UFUNCTION(BlueprintPure, Category = "UQPTimeUtils")
	FString GetFutureStringDay();

	UFUNCTION(BlueprintPure, Category = "UQPTimeUtils")
	FString GetFutureStringHour();

	UFUNCTION(BlueprintPure, Category = "UQPTimeUtils")
	FString GetFutureStringMinute();

	UFUNCTION(BlueprintPure, Category = "UQPTimeUtils")
	FString GetFutureStringSecond();

	UFUNCTION(BlueprintCallable, Category = "UQPTimeUtils")
		void SetYear(int32 time);

	UFUNCTION(BlueprintCallable, Category = "UQPTimeUtils")
		void SetMonth(int32 time);

	UFUNCTION(BlueprintCallable, Category = "UQPTimeUtils")
		void SetDay(int32 time);

	UFUNCTION(BlueprintCallable, Category = "UQPTimeUtils")
		void SetHour(int32 time);

	UFUNCTION(BlueprintCallable, Category = "UQPTimeUtils")
		void SetMinute(int32 time);

	UFUNCTION(BlueprintCallable, Category = "UQPTimeUtils")
		void SetSecond(int32 time);

	UFUNCTION(BlueprintCallable, Category = "UQPTimeUtils")
		void SetTimeByKey(EQPTimeType key,int32 time);


	UFUNCTION(BlueprintPure, Category = "UQPTimeUtils")
		int32 GetYear();

	UFUNCTION(BlueprintPure, Category = "UQPTimeUtils")
		int32 GetMonth();

	UFUNCTION(BlueprintPure, Category = "UQPTimeUtils")
		int32 GetDay();

	UFUNCTION(BlueprintPure, Category = "UQPTimeUtils")
		int32 GetHour();

	UFUNCTION(BlueprintPure, Category = "UQPTimeUtils")
		int32 GetMinute();

	UFUNCTION(BlueprintPure, Category = "UQPTimeUtils")
		int32 GetSecond();

	UFUNCTION(BlueprintPure, Category = "UQPTimeUtils")
		int32 GetTimeByKey(EQPTimeType key);

	FTimespan GetElapsedDateTime();
};
