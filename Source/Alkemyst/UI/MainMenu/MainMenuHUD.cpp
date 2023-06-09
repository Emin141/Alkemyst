// Copyright Epic Games, Inc. All Rights Reserved.

#include "Alkemyst/UI/MainMenu/MainMenuHUD.h"
#include "Alkemyst/GameModes/MainMenuGameMode.h"
#include "Alkemyst/UI/MainMenu/MainMenuWidget.h"

void AMainMenuHUD::StartGame()
{
	if (AMainMenuGameMode* gameMode = Cast<AMainMenuGameMode>(GetWorld()->GetAuthGameMode()))
	{
		gameMode->StartGame();
	}
}

void AMainMenuHUD::BeginPlay()
{
	Super::BeginPlay();

	ensure(IsValid(_mainMenuWidgetBlueprint));

	_mainMenuWidget = CreateWidget<UMainMenuWidget>(GetWorld(), _mainMenuWidgetBlueprint);
	ensure(_mainMenuWidget != nullptr);

	_mainMenuWidget->AddToViewport();
}
