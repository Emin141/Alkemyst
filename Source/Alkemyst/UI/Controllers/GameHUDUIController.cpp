// Showcase project of Lana Medved and Emin Turalic

#include "Alkemyst/UI/Controllers/GameHUDUIController.h"
#include "Alkemyst/AlkemystPlayerController.h"
#include "Alkemyst/GameModes/AlkemystGameMode.h"
#include "Kismet/KismetSystemLibrary.h"

void UGameHUDUIController::SetAlkemystPlayerController(class AAlkemystPlayerController* value)
{
	_alkemystPlayerController = value;
}

void UGameHUDUIController::QuitGame()
{
	if (_alkemystPlayerController.IsValid())
	{
		UKismetSystemLibrary::QuitGame(this, _alkemystPlayerController.Get(), EQuitPreference::Quit, true);
	}
}

void UGameHUDUIController::OpenMainMenu()
{
	if (AAlkemystGameMode* gameMode = Cast<AAlkemystGameMode>(GetWorld()->GetAuthGameMode()))
	{
		gameMode->OpenMainMenu();
	}
}

void UGameHUDUIController::ChangeToUIMode()
{
	if (_alkemystPlayerController.IsValid())
	{
		_alkemystPlayerController->SetInputMode(FInputModeUIOnly());
		_alkemystPlayerController->SetShowMouseCursor(true);
	}
}

void UGameHUDUIController::ChangeToNonUIMode()
{
	if (_alkemystPlayerController.IsValid())
	{
		_alkemystPlayerController->SetInputMode(FInputModeGameOnly());
		_alkemystPlayerController->SetShowMouseCursor(false);
	}
}
