// Showcase project of Lana Medved and Emin Turalic

#include "Alkemyst/UI/Game/GameHUDWidget.h"
#include "Alkemyst/UI/Controllers/GameHUDUIController.h"
#include "Alkemyst/UI/Game/GameHUD.h"
#include "Components/Button.h"
#include "Components/VerticalBox.h"

void UGameHUDWidget::SetUIController(class UGameHUDUIController* value)
{
	uiController_ = value;

	//Initial ESC binding.
	if (uiController_.IsValid())
	{
		AAlkemystPlayerController::FKeyEventDelegate openPauseMenuDelegate;
		openPauseMenuDelegate.BindUObject(this, &UGameHUDWidget::OpenPauseMenu);
		uiController_->PushDelegeToEscapeReleased(openPauseMenuDelegate);
	}
}

void UGameHUDWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	//None of these can be nullptr because they are bound in the editor.
	resumeGameButton_->OnClicked.AddDynamic(this, &UGameHUDWidget::OnResumeGameButtonClicked);
	saveGameButton_->OnClicked.AddDynamic(this, &UGameHUDWidget::OnSaveGameButtonClicked);
	loadGameButton_->OnClicked.AddDynamic(this, &UGameHUDWidget::OnLoadGameButtonClicked);
	settingsButton_->OnClicked.AddDynamic(this, &UGameHUDWidget::OnSettingsButtonClicked);
	mainMenuButton_->OnClicked.AddDynamic(this, &UGameHUDWidget::OnMainMenuButtonClicked);
	endGameButton_->OnClicked.AddDynamic(this, &UGameHUDWidget::OnEndGameButtonClicked);
}

void UGameHUDWidget::OpenPauseMenu()
{
	pauseMenuVerticalBox_->SetVisibility(ESlateVisibility::SelfHitTestInvisible);

	if (uiController_.IsValid())
	{
		uiController_->ShowMouseCursor();
	}

	//Rebind ESC to close the pause menu.
	if (uiController_.IsValid())
	{
		AAlkemystPlayerController::FKeyEventDelegate closePauseMenuDelegate;
		closePauseMenuDelegate.BindUObject(this, &UGameHUDWidget::ClosePauseMenu);
		uiController_->PushDelegeToEscapeReleased(closePauseMenuDelegate);
	}
}

void UGameHUDWidget::ClosePauseMenu()
{
	pauseMenuVerticalBox_->SetVisibility(ESlateVisibility::Collapsed);

	if (uiController_.IsValid())
	{
		uiController_->ShowMouseCursor(false);
	}

	//Rebind ESC to open the pause menu.
	if (uiController_.IsValid())
	{
		AAlkemystPlayerController::FKeyEventDelegate openPauseMenuDelegate;
		openPauseMenuDelegate.BindUObject(this, &UGameHUDWidget::OpenPauseMenu);
		uiController_->PushDelegeToEscapeReleased(openPauseMenuDelegate);
	}
}

void UGameHUDWidget::OnResumeGameButtonClicked()
{
	ClosePauseMenu();
}

void UGameHUDWidget::OnSaveGameButtonClicked()
{
	unimplemented();
}

void UGameHUDWidget::OnLoadGameButtonClicked()
{
	unimplemented();
}

void UGameHUDWidget::OnSettingsButtonClicked()
{
	unimplemented();
}

void UGameHUDWidget::OnMainMenuButtonClicked()
{
	if (uiController_.IsValid())
	{
		uiController_->OpenMainMenu();
	}
}

void UGameHUDWidget::OnEndGameButtonClicked()
{
	if (uiController_.IsValid())
	{
		uiController_->QuitGame();
	}
}
