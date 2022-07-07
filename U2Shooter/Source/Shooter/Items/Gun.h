// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Item.h"
#include "Gun.generated.h"

UCLASS()
class SHOOTER_API AGun : public AItem{
	GENERATED_BODY()
public:
	void Use()override;
	
	void AttachToPlayerView(class UCameraComponent *View)override;
};
