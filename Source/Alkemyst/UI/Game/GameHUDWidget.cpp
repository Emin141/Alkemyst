// Showcase project of Lana Medved and Emin Turalic

#include "Alkemyst/UI/Game/GameHUDWidget.h"
#include "Alkemyst/UI/Controllers/GameHUDUIController.h"
#include "Alkemyst/UI/Game/GameHUD.h"
#include "Components/Button.h"
#include "Components/VerticalBox.h"

void UGameHUDWidget::SetUIController(class UGameHUDUIController* value)
{
	_uiController = value;
}

void UGameHUDWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	ensure(_pauseMenuVerticalBox != nullptr && _resumeGameButton != nullptr &&
		_mainMenuButton != nullptr && _endGameButton != nullptr);

	_resumeGameButton->OnClicked.AddDynamic(this, &UGameHUDWidget::OnResumeGameButtonClicked);
	_mainMenuButton->OnClicked.AddDynamic(this, &UGameHUDWidget::OnMainMenuButtonClicked);
	_endGameButton->OnClicked.AddDynamic(this, &UGameHUDWidget::OnEndGameButtonClicked);

	//#TODO: Create the stacked callback key binding here.
	GetOwningPlayer()->InputComponent->BindKey(EKeys::Escape, IE_Released, this, &UGameHUDWidget::OpenPauseMenu);
}

void UGameHUDWidget::OpenPauseMenu()
{
	_pauseMenuVerticalBox->SetVisibility(ESlateVisibility::SelfHitTestInvisible);

	if (_uiController.IsValid())
	{
		_uiController->ChangeToUIMode();
	}
}

void UGameHUDWidget::ClosePauseMenu()
{
	_pauseMenuVerticalBox->SetVisibility(ESlateVisibility::Collapsed);

	if (_uiController.IsValid())
	{
		_uiController->ChangeToNonUIMode();
	}
}

void UGameHUDWidget::OnResumeGameButtonClicked()
{
	ClosePauseMenu();

	//#TODO Pop the esc button callback
}

void UGameHUDWidget::OnMainMenuButtonClicked()
{
	if (_uiController.IsValid())
	{
		_uiController->OpenMainMenu();
	}
}

void UGameHUDWidget::OnEndGameButtonClicked()
{
	if (_uiController.IsValid())
	{
		_uiController->QuitGame();
	}
}
