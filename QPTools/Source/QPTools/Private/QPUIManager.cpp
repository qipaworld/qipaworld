// Fill out your copyright notice in the Description page of Project Settings.

#include "QPUIManager.h"
#include "Runtime/UMG/Public/Blueprint/UserWidget.h"

AQPUIManager* AQPUIManager::_uiManager = nullptr;
TMap<FString, TSubclassOf<UUserWidget>>  AQPUIManager::_allUIPaths;
TMap<FString, UUserWidget*>  AQPUIManager::_allUIs;

AQPUIManager* AQPUIManager::GetInstance() {
	if (!_uiManager) {
		_uiManager = NewObject<AQPUIManager>();
		_uiManager->AddToRoot();
	}
	return _uiManager;
}

AQPUIManager::AQPUIManager() {
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts
void AQPUIManager::BeginPlay()
{
	Super::BeginPlay();

	// ...

}


// Called every frame
void AQPUIManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// ...
}


UUserWidget* AQPUIManager::getUI(FString key) {
	UUserWidget* ui = *_allUIs.Find(key);
	if (!ui) {
		ui = newUI(key);
	}
	return ui;
}
UUserWidget* AQPUIManager::newUI(FString key) {
	TSubclassOf<UUserWidget> uiClass = *_allUIPaths.Find(key);
	if (!uiClass) {
		return nullptr;
	}
	UUserWidget* ui = CreateWidget<UUserWidget>(GWorld, uiClass);
	if (!ui)
	{
		return nullptr;
	}
	ui->AddToViewport();
	_allUIs.Add(key,ui);
	return ui;
}
void AQPUIManager::addUIPath(FString key, TSubclassOf<UUserWidget> uiClass) {
	_allUIPaths.Add(key, uiClass);
}

void AQPUIManager::addUIPaths(TMap<FString, TSubclassOf<UUserWidget>> map) {
	for (auto& Elem : map)
	{
		_allUIPaths.Add(Elem.Key, Elem.Value);
	}
}
