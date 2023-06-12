// Showcase project of Lana Medved and Emin Turalic

#include "Alkemyst/AlkemystPlayerController.h"

void AAlkemystPlayerController::PushDelegeToEscapeReleased(const FKeyEventDelegate& keyEventDelegate)
{
	keyEventStack_.Push(keyEventDelegate);
}

void AAlkemystPlayerController::PopDelegateFromEscapeReleased()
{
	keyEventStack_.Pop();
}

void AAlkemystPlayerController::BeginPlay()
{
	ensure(InputComponent != nullptr);
	
	InputComponent->BindKey(EKeys::Escape, IE_Released, this, &AAlkemystPlayerController::OnEscapeReleased);
}

void AAlkemystPlayerController::OnEscapeReleased()
{
	if (keyEventStack_.Num() > 0)
	{
		FKeyEventDelegate topDelegate = keyEventStack_.Pop();
		topDelegate.ExecuteIfBound();
	}
}
