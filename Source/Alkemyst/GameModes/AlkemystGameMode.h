// Showcase project of Lana Medved and Emin Turalic

#pragma once
#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "AlkemystGameMode.generated.h"

/**
 * Responsible for handling global settings and data when a game level is loaded.
 */
UCLASS()
class ALKEMYST_API AAlkemystGameMode : public AGameMode
{
	GENERATED_BODY()

public:
	void EndGame();

};
