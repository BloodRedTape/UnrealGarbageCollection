// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PickableItemComponent.h"
#include "GameFramework/Actor.h"
#include "Ammo.generated.h"

UCLASS()
class SHOOTER_API AAmmo : public AActor{
	GENERATED_BODY()
private:
	UPROPERTY(EditAnywhere)
	UPickableItemComponent *PickableComponent;

	UPROPERTY(EditAnywhere)
	USceneComponent *Root;
public:
	AAmmo();

	void OnPick(AFirstPersonCharacter *Character);
};


