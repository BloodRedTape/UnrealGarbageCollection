#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Item.generated.h"

UCLASS()
class SHOOTER_API AItem : public AActor{
	GENERATED_BODY()
public:

	virtual void Use();

	virtual void AttachToPlayerView(class UCameraComponent *View);

	// Just an idea for now
	// void OnEvict();
};
