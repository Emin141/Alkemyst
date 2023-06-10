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
	//AActor overrides
	virtual void BeginPlay() final override;

protected:
	//I am actually not sure if blueprints do something to this function so it's better to have it protected.
	static void AddReferencedObjects(UObject* inThis, FReferenceCollector& collector);

private:
	//The widget is owned by the world.
	TWeakObjectPtr<class UMainMenuWidget> _mainMenuWidget;

	//Required to initialize the first widget.
	UPROPERTY(EditDefaultsOnly, Category="Alkemyst", DisplayName="Main menu widget blueprint")
	TSubclassOf<UMainMenuWidget> _mainMenuWidgetBlueprint;

	//Owning references to UI controllers, added in AddReferencedObjects.
	class UMainMenuHUDUIController* _mainMenuHUDUIController;

	//Functions
	void SetupMainMenuWidget();
};
