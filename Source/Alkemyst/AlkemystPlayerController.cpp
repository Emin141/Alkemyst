// Showcase project of Lana Medved and Emin Turalic

#include "Alkemyst/AlkemystPlayerController.h"

void AAlkemystPlayerController::PushDelegeToEscapeReleased(const FKeyEventDelegate& keyEventDelegate)
{
	ensure(InputComponent != nullptr);

	if (_keyEventStack.Num() == 0) //First time adding.
	{
		InputComponent->BindKey(EKeys::Escape, IE_Released, this, &AAlkemystPlayerController::OnEscapeReleased);
	}
	else //Push to the stack.
	{
		_keyEventStack.Push(keyEventDelegate);
	}
}

void AAlkemystPlayerController::PopDelegateFromEscapeReleased()
{
	_keyEventStack.Pop();
}

void AAlkemystPlayerController::OnEscapeReleased()
{
	FKeyEventDelegate topDelegate = _keyEventStack.Pop();
	topDelegate.ExecuteIfBound();
}
