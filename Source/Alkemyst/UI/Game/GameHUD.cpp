// Copyright Epic Games, Inc. All Rights Reserved.

#include "Alkemyst/UI/Game/GameHUD.h"
#include "Alkemyst/GameModes/AlkemystGameMode.h"
#include "Alkemyst/UI/Game/GameHUDWidget.h"

void AGameHUD::EndGame()
{
	if (AAlkemystGameMode* gameMode = Cast<AAlkemystGameMode>(GetWorld()->GetAuthGameMode()))
	{
		gameMode->EndGame();
	}
}

void AGameHUD::BeginPlay()
{
	Super::BeginPlay();

	ensure(IsValid(_gameHUDWidgetBlueprint));

	_gameHUDWidget = CreateWidget<UGameHUDWidget>(GetWorld(), _gameHUDWidgetBlueprint);
	ensure(_gameHUDWidget != nullptr);

	_gameHUDWidget->AddToViewport();
}
