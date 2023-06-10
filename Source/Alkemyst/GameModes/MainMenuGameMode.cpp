// Showcase project of Lana Medved and Emin Turalic

#include "Alkemyst/GameModes/MainMenuGameMode.h"
#include "Kismet/GameplayStatics.h"

void AMainMenuGameMode::StartGame()
{
	UGameplayStatics::OpenLevel(GetWorld(), levelToLoadOnStart_, true);
}
