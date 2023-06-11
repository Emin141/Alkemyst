// Showcase project of Lana Medved and Emin Turalic

#pragma once
#include "CoreMinimal.h"
#include "Alkemyst/AlkemystPlayerController.h"
#include "GameHUDUIController.generated.h"

/**
 * Acts as the controllers in the MVC pattern for the relevant widget.
 */
UCLASS(Blueprintable)
class ALKEMYST_API UGameHUDUIController : public UObject
{
	GENERATED_BODY()

public:
	void SetAlkemystPlayerController(class AAlkemystPlayerController* value);

	void QuitGame();
	void OpenMainMenu();

	void ShowMouseCursor(bool shouldShow = true);

	void PushDelegeToEscapeReleased(const AAlkemystPlayerController::FKeyEventDelegate& newDelegate);
	void PopDelegateFromEscapeReleased();

private:
	TWeakObjectPtr<AAlkemystPlayerController> _alkemystPlayerController;

};
