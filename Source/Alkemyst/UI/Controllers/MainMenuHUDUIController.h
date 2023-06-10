// Showcase project of Lana Medved and Emin Turalic

#pragma once
#include "CoreMinimal.h"
#include "MainMenuHUDUIController.generated.h"

/**
 * Servers as the controller in the MVC pattern for the relevant widget.
 */
UCLASS()
class ALKEMYST_API UMainMenuHUDUIController : public UObject
{
	GENERATED_BODY()

public:
	void StartGame();
	void QuitGame();

public:
	void SetAlkemystPlayerController(class AAlkemystPlayerController* value);

private:
	//Holds a non-owning reference.
	TWeakObjectPtr<AAlkemystPlayerController> _alkemystPlayerController;

};
