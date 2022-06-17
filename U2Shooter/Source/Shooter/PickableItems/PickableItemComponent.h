#pragma once

#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
#include "Delegates/Delegate.h"
#include "Shooter/Player/FirstPersonCharacter.h"
#include "PickableItemComponent.generated.h"

UCLASS()
class SHOOTER_API UPickableItemComponent : public UBoxComponent{
	GENERATED_BODY()
public:
	TDelegate<void(AFirstPersonCharacter*)> OnPick;
public:
	UPickableItemComponent();

	UFUNCTION()
	void OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, 
								AActor* OtherActor, 
								UPrimitiveComponent* OtherComp, 
								int32 OtherBodyIndex, 
								bool bFromSweep, 
								const FHitResult &SweepResult );
};
