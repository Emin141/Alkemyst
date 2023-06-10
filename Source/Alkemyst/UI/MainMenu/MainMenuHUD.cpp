// Showcase project of Lana Medved and Emin Turalic

#include "Alkemyst/UI/MainMenu/MainMenuHUD.h"
#include "Alkemyst/AlkemystPlayerController.h"
#include "Alkemyst/UI/Controllers/MainMenuHUDUIController.h"
#include "Alkemyst/UI/MainMenu/MainMenuWidget.h"

void AMainMenuHUD::BeginPlay()
{
	Super::BeginPlay();

	SetupMainMenuWidget();

	PlayerOwner->SetInputMode(FInputModeUIOnly());
	PlayerOwner->SetShowMouseCursor(true);
}

void AMainMenuHUD::AddReferencedObjects(UObject* inThis, FReferenceCollector& collector)
{
	AMainMenuHUD* mainMenuHUD = Cast<AMainMenuHUD>(inThis);

	collector.AddReferencedObject(mainMenuHUD->_mainMenuHUDUIController, inThis);

	Super::AddReferencedObjects(inThis, collector);
}

void AMainMenuHUD::SetupMainMenuWidget()
{
	ensure(IsValid(_mainMenuWidgetBlueprint));

	//Cache a reference.
	_mainMenuWidget = CreateWidget<UMainMenuWidget>(GetWorld(), _mainMenuWidgetBlueprint);
	if (_mainMenuWidget.IsValid() == false)
	{
		UE_DEBUG_BREAK();
		return;
	}
		
	_mainMenuWidget->AddToViewport();

	//Create and assign the UI controller. The reference is held by this class.
	_mainMenuHUDUIController = NewObject<UMainMenuHUDUIController>(this, UMainMenuHUDUIController::StaticClass());
	if (_mainMenuHUDUIController == nullptr)
	{
		UE_DEBUG_BREAK();
		return;
	}

	_mainMenuHUDUIController->SetAlkemystPlayerController(Cast<AAlkemystPlayerController>(PlayerOwner));
	_mainMenuWidget->SetUIController(_mainMenuHUDUIController);
}
