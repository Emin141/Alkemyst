// Copyright Epic Games, Inc. All Rights Reserved.

#include "Alkemyst/UI/Game/GameHUDWidget.h"
#include "Alkemyst/UI/Game/GameHUD.h"
#include "Components/Button.h"

void UGameHUDWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();
}

void UGameHUDWidget::OnEndGameButtonClicked()
{
	AGameHUD* hud = Cast<AGameHUD>(GetOwningPlayer()->GetHUD());
	ensure(hud);

	hud->EndGame();
}
