#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/TextBlock.h"
#include "InGameOverlay.generated.h"

UCLASS()
class SHOOTER_API UInGameOverlay : public UUserWidget{
	GENERATED_BODY()
private:
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	UTextBlock *AmmoCount;
public:
	void SetAmmoCount(int Count);
};
