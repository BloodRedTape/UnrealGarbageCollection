#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Shooter/Player/FirstPersonCharacter.h"
#include "Weapon.generated.h"

UCLASS()
class SHOOTER_API AWeapon : public AActor{
	GENERATED_BODY()
public:
	AWeapon();

	void OnPick(AFirstPersonCharacter *Character);
};
