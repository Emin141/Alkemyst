// Showcase project of Lana Medved and Emin Turalic

#include "Alkemyst/UI/Game/GameHUDWidget.h"
#include "Alkemyst/UI/Controllers/GameHUDUIController.h"
#include "Alkemyst/UI/Game/GameHUD.h"
#include "Components/Button.h"
#include "Components/VerticalBox.h"

void UGameHUDWidget::SetUIController(class UGameHUDUIController* value)
{
	_uiController = value;

	//Initial ESC binding.
	if (_uiController.IsValid())
	{
		AAlkemystPlayerController::FKeyEventDelegate openPauseMenuDelegate;
		openPauseMenuDelegate.BindUObject(this, &UGameHUDWidget::OpenPauseMenu);
		_uiController->PushDelegeToEscapeReleased(openPauseMenuDelegate);
	}
}

void UGameHUDWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	ensure(_pauseMenuVerticalBox != nullptr && _resumeGameButton != nullptr &&
		_mainMenuButton != nullptr && _endGameButton != nullptr);

	_resumeGameButton->OnClicked.AddDynamic(this, &UGameHUDWidget::OnResumeGameButtonClicked);
	_mainMenuButton->OnClicked.AddDynamic(this, &UGameHUDWidget::OnMainMenuButtonClicked);
	_endGameButton->OnClicked.AddDynamic(this, &UGameHUDWidget::OnEndGameButtonClicked);
}

void UGameHUDWidget::OpenPauseMenu()
{
	_pauseMenuVerticalBox->SetVisibility(ESlateVisibility::SelfHitTestInvisible);

	if (_uiController.IsValid())
	{
		_uiController->ShowMouseCursor();
	}

	//Rebind ESC to close the pause menu.
	if (_uiController.IsValid())
	{
		AAlkemystPlayerController::FKeyEventDelegate closePauseMenuDelegate;
		closePauseMenuDelegate.BindUObject(this, &UGameHUDWidget::ClosePauseMenu);
		_uiController->PushDelegeToEscapeReleased(closePauseMenuDelegate);
	}
}

void UGameHUDWidget::ClosePauseMenu()
{
	_pauseMenuVerticalBox->SetVisibility(ESlateVisibility::Collapsed);

	if (_uiController.IsValid())
	{
		_uiController->ShowMouseCursor(false);
	}

	//Rebind ESC to open the pause menu.
	if (_uiController.IsValid())
	{
		AAlkemystPlayerController::FKeyEventDelegate openPauseMenuDelegate;
		openPauseMenuDelegate.BindUObject(this, &UGameHUDWidget::OpenPauseMenu);
		_uiController->PushDelegeToEscapeReleased(openPauseMenuDelegate);
	}
}

void UGameHUDWidget::OnResumeGameButtonClicked()
{
	ClosePauseMenu();
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
