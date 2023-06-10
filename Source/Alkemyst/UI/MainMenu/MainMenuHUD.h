// Showcase project of Lana Medved and Emin Turalic

#pragma once
#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "MainMenuHUD.generated.h"

/**
 * Holds the relevant game level.
 */
UCLASS(Blueprintable)
class ALKEMYST_API AMainMenuHUD : public AHUD
{
	GENERATED_BODY()

public:
	void StartGame();
	void QuitGame();

	//AActor overrides
	virtual void BeginPlay() final override;

private:
	//UMG bindings
	UPROPERTY()
	class UMainMenuWidget* _mainMenuWidget;

	UPROPERTY(EditDefaultsOnly, Category="Alkemyst", DisplayName="Main menu widget blueprint")
	TSubclassOf<UMainMenuWidget> _mainMenuWidgetBlueprint;

	//Functions
	void CreateAndShowMainMenuWidget();
};
