// Showcase project of Lana Medved and Emin Turalic

#pragma once
#include "Blueprint/UserWidget.h"
#include "MainMenuWidget.generated.h"

class UMainMenuHUDUIController;
class UButton;

/**
 * Holds the relevant game level.
 */
UCLASS(Blueprintable)
class ALKEMYST_API UMainMenuWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	void SetUIController(UMainMenuHUDUIController* value);

private:
	//Weak reference to UI controller
	TWeakObjectPtr<UMainMenuHUDUIController> uiController_;

	//UMG editor bindings
	UPROPERTY(meta=(BindWidget))
	UButton* newGameButton_;

	UPROPERTY(meta = (BindWidget))
	UButton* loadGameButton_;

	UPROPERTY(meta = (BindWidget))
	UButton* settingsButton_;

	UPROPERTY(meta=(BindWidget))
	UButton* endGameButton_;

	//UUserWidget overrides
	virtual void NativeOnInitialized() final override;

	//Callbacks
	UFUNCTION()
	void OnStartGameButtonClicked();

	UFUNCTION()
	void OnLoadGameButtonClicked();

	UFUNCTION()
	void OnSettingsButtonClicked();

	UFUNCTION()
	void OnEndGameButtonClicked();

};
