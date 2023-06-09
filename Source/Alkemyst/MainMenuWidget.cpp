// Copyright Epic Games, Inc. All Rights Reserved.

#include "Alkemyst/MainMenuWidget.h"
#include "Alkemyst/MainMenuHUD.h"
#include "Components/Button.h"

void UMainMenuWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	ensure(_TEST_startButton != nullptr);

	_TEST_startButton->OnClicked.AddDynamic(this, &UMainMenuWidget::OnStartButtonClicked);
}

void UMainMenuWidget::OnStartButtonClicked()
{
	AMainMenuHUD* mainMenuHUD = Cast<AMainMenuHUD>(GetOwningPlayer()->GetHUD());
	ensure(mainMenuHUD);

	mainMenuHUD->StartGame();
}
