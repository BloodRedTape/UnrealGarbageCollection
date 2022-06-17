#pragma once

#include "CoreMinimal.h"
#include "Inventory.generated.h"

USTRUCT()
struct SHOOTER_API FInventory{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category="Items")
	int32 Ammo = 0;
};
