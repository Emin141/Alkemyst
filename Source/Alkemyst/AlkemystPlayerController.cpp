// Showcase project of Lana Medved and Emin Turalic

#include "Alkemyst/AlkemystPlayerController.h"

void AAlkemystPlayerController::PushDelegeToEscapeReleased(const FKeyEventDelegate& keyEventDelegate)
{
	_keyEventStack.Push(keyEventDelegate);
}

void AAlkemystPlayerController::PopDelegateFromEscapeReleased()
{
	_keyEventStack.Pop();
}

void AAlkemystPlayerController::BeginPlay()
{
	ensure(InputComponent != nullptr);
	
	InputComponent->BindKey(EKeys::Escape, IE_Released, this, &AAlkemystPlayerController::OnEscapeReleased);
}

void AAlkemystPlayerController::OnEscapeReleased()
{
	if (_keyEventStack.Num() > 0)
	{
		FKeyEventDelegate topDelegate = _keyEventStack.Pop();
		topDelegate.ExecuteIfBound();
	}
}
