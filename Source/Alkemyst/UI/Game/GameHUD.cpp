// Showcase project of Lana Medved and Emin Turalic

#include "Alkemyst/UI/Game/GameHUD.h"
#include "Alkemyst/UI/Game/GameHUDWidget.h"
#include "Alkemyst/GameModes/AlkemystGameMode.h"
#include "Kismet/KismetSystemLibrary.h"

void AGameHUD::QuitGame()
{
	UKismetSystemLibrary::QuitGame(this, PlayerOwner, EQuitPreference::Quit, true);
}

void AGameHUD::OpenMainMenu()
{
	if (AAlkemystGameMode* gameMode = Cast<AAlkemystGameMode>(GetWorld()->GetAuthGameMode()))
	{
		gameMode->OpenMainMenu();
	}
}

void AGameHUD::BeginPlay()
{
	Super::BeginPlay();

	CreateAndShowHUDWidget();
}

void AGameHUD::CreateAndShowHUDWidget()
{
	ensure(IsValid(_gameHUDWidgetBlueprint));

	_gameHUDWidget = CreateWidget<UGameHUDWidget>(GetWorld(), _gameHUDWidgetBlueprint);
	ensure(_gameHUDWidget != nullptr);

	_gameHUDWidget->AddToViewport();
}
