// Showcase project of Lana Medved and Emin Turalic

#include "Alkemyst/UI/Controllers/MainMenuHUDUIController.h"
#include "Alkemyst/AlkemystPlayerController.h"
#include "Alkemyst/GameModes/MainMenuGameMode.h"
#include "Kismet/KismetSystemLibrary.h"

void UMainMenuHUDUIController::StartGame()
{
	if (_alkemystPlayerController.IsValid())
	{
		_alkemystPlayerController->SetInputMode(FInputModeGameOnly());
		_alkemystPlayerController->SetShowMouseCursor(false);
	}

	if (AMainMenuGameMode* gameMode = Cast<AMainMenuGameMode>(GetWorld()->GetAuthGameMode()))
	{
		gameMode->StartGame();
	}
}

void UMainMenuHUDUIController::QuitGame()
{
	if (_alkemystPlayerController.IsValid())
	{
		UKismetSystemLibrary::QuitGame(this, _alkemystPlayerController.Get(), EQuitPreference::Quit, true);
	}
}

void UMainMenuHUDUIController::SetAlkemystPlayerController(class AAlkemystPlayerController* value)
{
	_alkemystPlayerController = value;
}