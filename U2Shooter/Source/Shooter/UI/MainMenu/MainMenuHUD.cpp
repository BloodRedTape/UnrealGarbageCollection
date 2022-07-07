#include "MainMenuHUD.h"
#include "MainMenu.h"
#include "Kismet/GameplayStatics.h"

void AMainMenuHUD::BeginPlay(){
	Super::BeginPlay();

	if(!MainMenuClass)return;
	
	APlayerController* PC = Cast<APlayerController>( GetOwner() );

	MainMenu = CreateWidget<UMainMenu>(PC, MainMenuClass);
	MainMenu->AddToViewport();

	PC->SetShowMouseCursor(true);
	PC->SetInputMode(FInputModeUIOnly());
}

void AMainMenuHUD::EndPlay(const EEndPlayReason::Type EndPlayReason){
	Super::EndPlay(EndPlayReason);
	
	APlayerController* PC = Cast<APlayerController>( GetOwner() );
	PC->SetShowMouseCursor(false);
	PC->SetInputMode(FInputModeGameOnly());
}
