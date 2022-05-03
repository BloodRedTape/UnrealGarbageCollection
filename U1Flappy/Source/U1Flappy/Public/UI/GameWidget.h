// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "Blueprint/UserWidget.h"
#include "GameWidget.generated.h"

/**
 * 
 */
UCLASS()
class U1FLAPPY_API UGameWidget: public UUserWidget{
	GENERATED_BODY()
private:

public:
	UFUNCTION(BlueprintNativeEvent)
	void SetScore(int NewScore);

	void SetScore_Implementation(int NewScore);
};
