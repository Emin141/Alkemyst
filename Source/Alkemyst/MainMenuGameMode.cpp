// Copyright Epic Games, Inc. All Rights Reserved.

#include "Alkemyst/MainMenuGameMode.h"
#include "Alkemyst/AlkemystWorldSettings.h"
#include "Kismet/GameplayStatics.h"

void AMainMenuGameMode::StartGame()
{
	UGameplayStatics::OpenLevel(GetWorld(), levelToLoadOnStart_, true);
}
