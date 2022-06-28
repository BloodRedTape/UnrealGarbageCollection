#include "MainMenu.h"

#include "Kismet/GameplayStatics.h"
#include "Launch/Public/LaunchEngineLoop.h"

bool UMainMenu::Initialize(){
	Super::Initialize();

	if(Play)
		Play->OnClicked.AddDynamic(this, &UMainMenu::OnPlay);
	
	return true;
}

void UMainMenu::OnPlay(){
	UE_LOG(LogTemp, Display, TEXT("OnPlay!!!"));
	FString Error;
	GEngine->LoadMap(GEngine->GetWorldContextFromWorldChecked(GetWorld()), FURL(TEXT("/Game/Maps/InGame.umap")), nullptr, Error);
}
