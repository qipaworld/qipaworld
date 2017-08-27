// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "QPTimeUtils.generated.h"
/**
 *
 */
UCLASS()
class  UQPTimeUtils : public UObject
{
	GENERATED_BODY()
	
	FDateTime _DateTime;
	FDateTime _DateTimeNow;
	int32 _Year;
	int32 _Month;
	int32 _Day;
	int32 _Hour;
	int32 _Minute;
	int32 _Second;

public:
	UQPTimeUtils();

	UFUNCTION(BlueprintPure, Category = "UQPTimeUtils")
	static UQPTimeUtils* GetInstance(int32 DefaultYear = 1, int32 DefaultMonth = 1, int32 DefaultDay = 1, int32 DefaultHour = 0, int32 DefaultMinute = 0, int32 DefaultSecond = 0);
	
	UFUNCTION(BlueprintCallable, Category = "UQPTimeUtils")
	void SetDefaultTime(int32 DefaultYear = 1, int32 DefaultMonth = 1, int32 DefaultDay = 1, int32 DefaultHour = 0, int32 DefaultMinute = 0, int32 DefaultSecond = 0);
	
	UFUNCTION(BlueprintPure, Category = "UQPTimeUtils")
	int32 GetElapsedYear();

	UFUNCTION(BlueprintPure, Category = "UQPTimeUtils")
	int32 GetElapsedMonth();

	UFUNCTION(BlueprintPure, Category = "UQPTimeUtils")
	int32 GetElapsedDay();

	UFUNCTION(BlueprintPure, Category = "UQPTimeUtils")
	int32 GetElapsedHour();

	UFUNCTION(BlueprintPure, Category = "UQPTimeUtils")
	int32 GetElapsedMinute();

	UFUNCTION(BlueprintPure, Category = "UQPTimeUtils")
	int32 GetElapsedSecond();

	FTimespan GetElapsedDateTime();
};
