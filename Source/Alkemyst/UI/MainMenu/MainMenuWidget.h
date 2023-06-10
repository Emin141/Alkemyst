// Showcase project of Lana Medved and Emin Turalic

#pragma once
#include "Blueprint/UserWidget.h"
#include "MainMenuWidget.generated.h"

/**
 * Holds the relevant game level.
 */
UCLASS(Blueprintable)
class ALKEMYST_API UMainMenuWidget : public UUserWidget
{
	GENERATED_BODY()

private:
	//UMG editor bindings
	UPROPERTY(meta=(BindWidget))
	class UButton* _startGameButton;

	UPROPERTY(meta = (BindWidget))
	UButton* _endGameButton;

	//UUserWidget overrides
	virtual void NativeOnInitialized() final override;

	//Callbacks
	UFUNCTION()
	void OnStartGameButtonClicked();

	UFUNCTION()
	void OnEndGameButtonClicked();

};
