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
	//AActor overrides
	virtual void BeginPlay() final override;

protected:
	//I am actually not sure if blueprints do something to this function so it's better to have it protected.
	static void AddReferencedObjects(UObject* inThis, FReferenceCollector& collector);

private:
	//The widget is already owned by the world.
	TWeakObjectPtr<class UGameHUDWidget> _gameHUDWidget;

	UPROPERTY(EditDefaultsOnly, Category="Alkemyst", DisplayName="Game HUD widget blueprint")
	TSubclassOf<UGameHUDWidget> _gameHUDWidgetBlueprint;

	//Owning references to UI controllers, added in AddReferencedObjects.
	class UGameHUDUIController* _gameHUDUIController;

	//Functions
	void SetupGameHUDWidget();
};
