// Showcase project of Lana Medved and Emin Turalic

#pragma once
#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "MainMenuGameMode.generated.h"

/**
 * Responsible for loading save files and opening a relevant game level.
 */
UCLASS()
class ALKEMYST_API AMainMenuGameMode : public AGameMode
{
	GENERATED_BODY()

public:
	void StartGame();

private:
	/**
	 * If the game mode holds the name of the world to load, this can be extended
	 * to change the name depending on the save game data when loading saves.
	 */
	UPROPERTY(EditAnywhere, Category = "Alkemyst", DisplayName = "Level to load on start game")
	FName levelToLoadOnStart_;

};
