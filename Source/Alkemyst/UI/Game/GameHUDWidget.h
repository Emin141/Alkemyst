// Showcase project of Lana Medved and Emin Turalic

#pragma once
#include "Blueprint/UserWidget.h"
#include "GameHUDWidget.generated.h"

/**
 * Holds the relevant game level.
 */
UCLASS(Blueprintable)
class ALKEMYST_API UGameHUDWidget : public UUserWidget
{
	GENERATED_BODY()

private:
	//UUserWidget overrides
	virtual void NativeOnInitialized() final override;

	//Callbacks
	UFUNCTION()
	void OnEndGameButtonClicked();
};
