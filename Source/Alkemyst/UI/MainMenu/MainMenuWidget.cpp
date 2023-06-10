// Showcase project of Lana Medved and Emin Turalic

#include "Alkemyst/UI/MainMenu/MainMenuWidget.h"
#include "Alkemyst/UI/Controllers/MainMenuHUDUIController.h"
#include "Alkemyst/UI/MainMenu/MainMenuHUD.h"
#include "Components/Button.h"

void UMainMenuWidget::SetUIController(class UMainMenuHUDUIController* value)
{
	_uiController = value;
}

void UMainMenuWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	ensure(_startGameButton != nullptr && _endGameButton != nullptr);

	_startGameButton->OnClicked.AddDynamic(this, &UMainMenuWidget::OnStartGameButtonClicked);
	_endGameButton->OnClicked.AddDynamic(this, &UMainMenuWidget::OnEndGameButtonClicked);
}

void UMainMenuWidget::OnStartGameButtonClicked()
{
	if (_uiController.IsValid())
	{
		_uiController->StartGame();
	}
}

void UMainMenuWidget::OnEndGameButtonClicked()
{
	if (_uiController.IsValid())
	{
		_uiController->QuitGame();
	}
}
