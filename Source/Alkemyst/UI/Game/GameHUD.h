// Showcase project of Lana Medved and Emin Turalic

#pragma once
#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "GameHUD.generated.h"

/**
 * Holds the relevant game level.
 */
UCLASS(Blueprintable)
class ALKEMYST_API AGameHUD : public AHUD
{
	GENERATED_BODY()

public:
	void QuitGame();
	void OpenMainMenu();

	//AActor overrides
	virtual void BeginPlay() final override;

private:
	//UMG widgets
	UPROPERTY()
	class UGameHUDWidget* _gameHUDWidget;

	UPROPERTY(EditDefaultsOnly, Category="Alkemyst", DisplayName="Game HUD widget blueprint")
	TSubclassOf<UGameHUDWidget> _gameHUDWidgetBlueprint;

	//Functions
	void CreateAndShowHUDWidget();
};
