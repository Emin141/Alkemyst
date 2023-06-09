// Copyright Epic Games, Inc. All Rights Reserved.

#include "Alkemyst/GameModes/MainMenuGameMode.h"
#include "Kismet/GameplayStatics.h"

void AMainMenuGameMode::StartGame()
{
	UGameplayStatics::OpenLevel(GetWorld(), levelToLoadOnStart_, true);
}
