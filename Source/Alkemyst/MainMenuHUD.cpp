// Copyright Epic Games, Inc. All Rights Reserved.

#include "Alkemyst/MainMenuHUD.h"
#include "Alkemyst/MainMenuGameMode.h"
#include "Alkemyst/MainMenuWidget.h"

void AMainMenuHUD::StartGame()
{
	if (AMainMenuGameMode* mmGm = Cast<AMainMenuGameMode>(GetWorld()->GetAuthGameMode()))
	{
		mmGm->StartGame();
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
