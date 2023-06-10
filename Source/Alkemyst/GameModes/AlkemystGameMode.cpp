// Showcase project of Lana Medved and Emin Turalic

#include "Alkemyst/GameModes/AlkemystGameMode.h"
#include "Kismet/GameplayStatics.h"

void AAlkemystGameMode::OpenMainMenu()
{
	UGameplayStatics::OpenLevel(GetWorld(), mainMenuLevel_, true);
}
