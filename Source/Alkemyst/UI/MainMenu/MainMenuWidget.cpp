// Copyright Epic Games, Inc. All Rights Reserved.

#include "Alkemyst/UI/MainMenu/MainMenuWidget.h"
#include "Alkemyst/UI/MainMenu/MainMenuHUD.h"
#include "Components/Button.h"

void UMainMenuWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	ensure(_TEST_startButton != nullptr);

	_TEST_startButton->OnClicked.AddDynamic(this, &UMainMenuWidget::OnStartButtonClicked);
}

void UMainMenuWidget::OnStartButtonClicked()
{
	AMainMenuHUD* hud = Cast<AMainMenuHUD>(GetOwningPlayer()->GetHUD());
	ensure(hud);

	hud->StartGame();
}
