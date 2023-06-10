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

public:
	void SetUIController(class UGameHUDUIController* value);

private:
	//Weak reference to the UI controller
	TWeakObjectPtr<UGameHUDUIController> _uiController;

	//UMG bindings
	UPROPERTY(meta=(BindWidget))
	class UVerticalBox* _pauseMenuVerticalBox;

	UPROPERTY(meta = (BindWidget))
	class UButton* _resumeGameButton;

	UPROPERTY(meta = (BindWidget))
	class UButton* _mainMenuButton;

	UPROPERTY(meta = (BindWidget))
	class UButton* _endGameButton;

	//UUserWidget overrides
	virtual void NativeOnInitialized() final override;
	
	//Functions
	void OpenPauseMenu();
	void ClosePauseMenu();

	//Callbacks
	UFUNCTION()
	void OnResumeGameButtonClicked();

	UFUNCTION()
	void OnMainMenuButtonClicked();

	UFUNCTION()
	void OnEndGameButtonClicked();
};
