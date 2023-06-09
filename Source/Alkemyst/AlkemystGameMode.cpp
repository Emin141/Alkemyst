// Copyright Epic Games, Inc. All Rights Reserved.

#include "Alkemyst/AlkemystGameMode.h"

void AAlkemystGameMode::BeginPlay()
{
	Super::BeginPlay();

	UE_LOG(LogTemp, Warning, L"Game started!");
}
