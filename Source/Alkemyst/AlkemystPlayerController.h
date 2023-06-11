// Showcase project of Lana Medved and Emin Turalic

#pragma once
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "AlkemystPlayerController.generated.h"

/**
 * Acts as a per-player based singleton. Useful for input.
 */
UCLASS()
class ALKEMYST_API AAlkemystPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	//Declares it in the scope of the controller.
	DECLARE_DELEGATE(FKeyEventDelegate)

	//Might move this to something else later
	void PushDelegeToEscapeReleased(const FKeyEventDelegate& keyEventDelegate);
	void PopDelegateFromEscapeReleased();

private:
	//AActor overrides
	virtual void BeginPlay() final override;

	/**
	 * The escape key is kind of special and can have different actions bound to it
	 * depending on the context. In order to achieve this, any class that needs to change 
	 * the functionality of the key pushes a callable delegate to a stack of delegates.
	 * 
	 * When the key is then pressed/released/whatever, the top delegate is executed and 
	 * then popped from the stack. This will allow for the previous key binding to take 
	 * place. 
	 */
	TArray<FKeyEventDelegate> _keyEventStack;

	void OnEscapeReleased();

};
