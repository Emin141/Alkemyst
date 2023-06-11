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

void UGameHUDUIController::ShowMouseCursor(bool shouldShow /*= true */)
{
	if (_alkemystPlayerController.IsValid())
	{
		if (shouldShow)
		{
			_alkemystPlayerController->SetInputMode(FInputModeGameAndUI());
		}
		else
		{
			_alkemystPlayerController->SetInputMode(FInputModeGameOnly());
		}

		_alkemystPlayerController->SetIgnoreLookInput(shouldShow);
		_alkemystPlayerController->SetShowMouseCursor(shouldShow);
	}
}

void UGameHUDUIController::PushDelegeToEscapeReleased(const AAlkemystPlayerController::FKeyEventDelegate& newDelegate)
{
	if (_alkemystPlayerController.IsValid())
	{
		_alkemystPlayerController->PushDelegeToEscapeReleased(newDelegate);
	}
}

void UGameHUDUIController::PopDelegateFromEscapeReleased()
{
	if (_alkemystPlayerController.IsValid())
	{
		_alkemystPlayerController->PopDelegateFromEscapeReleased();
	}
}
