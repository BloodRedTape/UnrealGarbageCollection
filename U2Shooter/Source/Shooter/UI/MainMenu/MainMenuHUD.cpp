#include "MainMenuHUD.h"
#include "MainMenu.h"

void AMainMenuHUD::BeginPlay(){
	Super::BeginPlay();

	if(!MainMenuClass)return;
	
	APlayerController* PC = Cast<APlayerController>( GetOwner() );

	MainMenu = CreateWidget<UMainMenu>(PC, MainMenuClass);
	MainMenu->AddToViewport();
}
