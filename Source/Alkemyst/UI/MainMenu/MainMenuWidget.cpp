// Showcase project of Lana Medved and Emin Turalic

#include "Alkemyst/UI/MainMenu/MainMenuWidget.h"
#include "Alkemyst/UI/Controllers/MainMenuHUDUIController.h"
#include "Alkemyst/UI/MainMenu/MainMenuHUD.h"
#include "Components/Button.h"

void UMainMenuWidget::SetUIController(class UMainMenuHUDUIController* value)
{
	uiController_ = value;
}

void UMainMenuWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	//None of these can be nullptr because they are bound in the editor.
	newGameButton_->OnClicked.AddDynamic(this, &UMainMenuWidget::OnStartGameButtonClicked);
	loadGameButton_->OnClicked.AddDynamic(this, &UMainMenuWidget::OnLoadGameButtonClicked);
	settingsButton_->OnClicked.AddDynamic(this, &UMainMenuWidget::OnSettingsButtonClicked);
	endGameButton_->OnClicked.AddDynamic(this, &UMainMenuWidget::OnEndGameButtonClicked);
}

void UMainMenuWidget::OnStartGameButtonClicked()
{
	if (uiController_.IsValid())
	{
		uiController_->StartGame();
	}
}

void UMainMenuWidget::OnLoadGameButtonClicked()
{
	unimplemented();
}

void UMainMenuWidget::OnSettingsButtonClicked()
{
	unimplemented();
}

void UMainMenuWidget::OnEndGameButtonClicked()
{
	if (uiController_.IsValid())
	{
		uiController_->QuitGame();
	}
}
