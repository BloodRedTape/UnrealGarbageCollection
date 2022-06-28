#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "MainMenu.generated.h"

UCLASS()
class SHOOTER_API UMainMenu : public UUserWidget{
	GENERATED_BODY()
private:
	UPROPERTY(meta = (BindWidget))
	UButton *Play = nullptr;
public:
	bool Initialize() override;

	UFUNCTION()
	void OnPlay();
};
