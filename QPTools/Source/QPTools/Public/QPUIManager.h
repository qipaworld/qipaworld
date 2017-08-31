// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"

#include "QPUIManager.generated.h"

/**
 *
 */

UCLASS()
class QPTOOLS_API AQPUIManager : public AActor
{
	GENERATED_BODY()

		static TMap<FString, TSubclassOf<UUserWidget>> _allUIPaths;
		static TMap<FString, UUserWidget*> _allUIs;
		static AQPUIManager* _uiManager;
public:

	//UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "UMG Path")
	//	TMap<FString, TSubclassOf<UUserWidget>> *UIPaths;

	AQPUIManager();
	// Called when the game starts
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintPure, Category = "QPUIManager")
	static AQPUIManager* GetInstance();
	
	UFUNCTION(BlueprintCallable, Category = "QPUIManager")
		UUserWidget* getUI(FString key);

	UUserWidget* newUI(FString);

	UFUNCTION(BlueprintCallable, Category = "QPUIManager")
		void addUIPath(FString key,TSubclassOf<UUserWidget> uiClass);

	UFUNCTION(BlueprintCallable, Category = "QPUIManager")
		void addUIPaths(TMap<FString, TSubclassOf<UUserWidget>>uiClasses);

};
