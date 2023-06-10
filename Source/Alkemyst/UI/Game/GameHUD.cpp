// Showcase project of Lana Medved and Emin Turalic

#include "Alkemyst/UI/Game/GameHUD.h"
#include "Alkemyst/AlkemystPlayerController.h"
#include "Alkemyst/UI/Controllers/GameHUDUIController.h"
#include "Alkemyst/UI/Game/GameHUDWidget.h"

void AGameHUD::BeginPlay()
{
	Super::BeginPlay();

	SetupGameHUDWidget();
}

void AGameHUD::AddReferencedObjects(UObject* inThis, FReferenceCollector& collector)
{
	AGameHUD* gameHUD = Cast<AGameHUD>(inThis);

	collector.AddReferencedObject(gameHUD->_gameHUDUIController, inThis);

	Super::AddReferencedObjects(inThis, collector);
}

void AGameHUD::SetupGameHUDWidget()
{
	ensure(IsValid(_gameHUDWidgetBlueprint));

	_gameHUDWidget = CreateWidget<UGameHUDWidget>(GetWorld(), _gameHUDWidgetBlueprint);
	if (_gameHUDWidget.IsValid() == false)
	{
		UE_DEBUG_BREAK();
		return;
	}

	_gameHUDWidget->AddToViewport();

	_gameHUDUIController = NewObject<UGameHUDUIController>(this, UGameHUDUIController::StaticClass());
	if (_gameHUDUIController == nullptr)
	{
		UE_DEBUG_BREAK();
		return;
	}

	_gameHUDUIController->SetAlkemystPlayerController(Cast<AAlkemystPlayerController>(PlayerOwner));
	_gameHUDWidget->SetUIController(_gameHUDUIController);
}
