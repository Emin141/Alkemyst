// Showcase project of Lana Medved and Emin Turalic

#include "Alkemyst/UI/Game/GameHUDWidget.h"
#include "Alkemyst/UI/Game/GameHUD.h"
#include "Components/Button.h"
#include "Components/VerticalBox.h"

void UGameHUDWidget::OpenPauseMenu()
{
	_pauseMenuVerticalBox->SetVisibility(ESlateVisibility::SelfHitTestInvisible);

	GetOwningPlayer()->SetInputMode(FInputModeUIOnly());
	GetOwningPlayer()->SetShowMouseCursor(true);
}

void UGameHUDWidget::ClosePauseMenu()
{
	_pauseMenuVerticalBox->SetVisibility(ESlateVisibility::Collapsed);

	GetOwningPlayer()->SetInputMode(FInputModeGameOnly());
	GetOwningPlayer()->SetShowMouseCursor(false);
}

void UGameHUDWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	ensure(_pauseMenuVerticalBox != nullptr &&
		_resumeGameButton != nullptr &&
		_mainMenuButton != nullptr &&
		_endGameButton != nullptr);

	_resumeGameButton->OnClicked.AddDynamic(this, &UGameHUDWidget::OnResumeGameButtonClicked);
	_mainMenuButton->OnClicked.AddDynamic(this, &UGameHUDWidget::OnMainMenuButtonClicked);
	_endGameButton->OnClicked.AddDynamic(this, &UGameHUDWidget::OnEndGameButtonClicked);

	GetOwningPlayer()->InputComponent->BindKey(EKeys::Escape, IE_Released, this, &UGameHUDWidget::OpenPauseMenu);
}

void UGameHUDWidget::OnResumeGameButtonClicked()
{
	ClosePauseMenu();
}

void UGameHUDWidget::OnMainMenuButtonClicked()
{
	AGameHUD* hud = Cast<AGameHUD>(GetOwningPlayer()->GetHUD());
	ensure(hud);

	hud->OpenMainMenu();
}

void UGameHUDWidget::OnEndGameButtonClicked()
{
	AGameHUD* hud = Cast<AGameHUD>(GetOwningPlayer()->GetHUD());
	ensure(hud);

	hud->QuitGame();
}
