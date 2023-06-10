// Showcase project of Lana Medved and Emin Turalic

#include "Alkemyst/UI/MainMenu/MainMenuHUD.h"
#include "Alkemyst/GameModes/MainMenuGameMode.h"
#include "Alkemyst/UI/MainMenu/MainMenuWidget.h"
#include "Kismet/KismetSystemLibrary.h"

void AMainMenuHUD::StartGame()
{
	PlayerOwner->SetInputMode(FInputModeGameOnly());
	PlayerOwner->SetShowMouseCursor(false); 

	if (AMainMenuGameMode* gameMode = Cast<AMainMenuGameMode>(GetWorld()->GetAuthGameMode()))
	{
		gameMode->StartGame();
	}
}

void AMainMenuHUD::QuitGame()
{
	UKismetSystemLibrary::QuitGame(this, PlayerOwner, EQuitPreference::Quit, true);
}

void AMainMenuHUD::BeginPlay()
{
	Super::BeginPlay();

	CreateAndShowMainMenuWidget();

	PlayerOwner->SetInputMode(FInputModeUIOnly());
	PlayerOwner->SetShowMouseCursor(true);
}

void AMainMenuHUD::CreateAndShowMainMenuWidget()
{
	ensure(IsValid(_mainMenuWidgetBlueprint));

	_mainMenuWidget = CreateWidget<UMainMenuWidget>(GetWorld(), _mainMenuWidgetBlueprint);
	ensure(_mainMenuWidget != nullptr);

	_mainMenuWidget->AddToViewport();
}
