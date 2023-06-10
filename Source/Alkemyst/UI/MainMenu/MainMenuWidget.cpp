// Showcase project of Lana Medved and Emin Turalic

#include "Alkemyst/UI/MainMenu/MainMenuWidget.h"
#include "Alkemyst/UI/MainMenu/MainMenuHUD.h"
#include "Components/Button.h"

void UMainMenuWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	ensure(_startGameButton != nullptr && _endGameButton != nullptr);

	_startGameButton->OnClicked.AddDynamic(this, &UMainMenuWidget::OnStartGameButtonClicked);
	_endGameButton->OnClicked.AddDynamic(this, &UMainMenuWidget::OnEndGameButtonClicked);
}

void UMainMenuWidget::OnStartGameButtonClicked()
{
	AMainMenuHUD* hud = Cast<AMainMenuHUD>(GetOwningPlayer()->GetHUD());
	ensure(hud);

	hud->StartGame();
}

void UMainMenuWidget::OnEndGameButtonClicked()
{
	AMainMenuHUD* hud = Cast<AMainMenuHUD>(GetOwningPlayer()->GetHUD());
	ensure(hud);

	hud->QuitGame();
}
