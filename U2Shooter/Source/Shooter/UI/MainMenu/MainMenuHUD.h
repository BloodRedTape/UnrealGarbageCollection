#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "MainMenuHUD.generated.h"

UCLASS()
class SHOOTER_API AMainMenuHUD : public AHUD{
	GENERATED_BODY()
private:
	class UMainMenu *MainMenu;	
	UPROPERTY(EditAnywhere, Category="UI")
	TSubclassOf<UMainMenu> MainMenuClass;	
public:
	void BeginPlay() override;	
};
