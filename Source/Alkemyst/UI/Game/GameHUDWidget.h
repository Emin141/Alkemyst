// Showcase project of Lana Medved and Emin Turalic

#pragma once
#include "Blueprint/UserWidget.h"
#include "GameHUDWidget.generated.h"

class UGameHUDUIController;
class UVerticalBox;
class UButton;

/**
 * Holds the relevant game level.
 */
UCLASS(Blueprintable)
class ALKEMYST_API UGameHUDWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	void SetUIController(UGameHUDUIController* value);

private:
	//Weak reference to the UI controller
	TWeakObjectPtr<UGameHUDUIController> uiController_;

	//UMG bindings
	UPROPERTY(meta=(BindWidget))
	UVerticalBox* pauseMenuVerticalBox_;

	UPROPERTY(meta = (BindWidget))
	UButton* resumeGameButton_;

	UPROPERTY(meta = (BindWidget))
	UButton* saveGameButton_;

	UPROPERTY(meta = (BindWidget))
	UButton* loadGameButton_;

	UPROPERTY(meta = (BindWidget))
	UButton* settingsButton_;

	UPROPERTY(meta = (BindWidget))
	UButton* mainMenuButton_;

	UPROPERTY(meta = (BindWidget))
	UButton* endGameButton_;

	//UUserWidget overrides
	virtual void NativeOnInitialized() final override;
	
	//Functions
	void OpenPauseMenu();
	void ClosePauseMenu();

	//Callbacks
	UFUNCTION()
	void OnResumeGameButtonClicked();

	UFUNCTION()
	void OnSaveGameButtonClicked();

	UFUNCTION()
	void OnLoadGameButtonClicked();

	UFUNCTION()
	void OnSettingsButtonClicked();

	UFUNCTION()
	void OnMainMenuButtonClicked();

	UFUNCTION()
	void OnEndGameButtonClicked();
};
