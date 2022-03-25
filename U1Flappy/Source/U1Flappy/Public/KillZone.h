#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "KillZone.generated.h"

UCLASS()
class U1FLAPPY_API AKillZone : public AActor{
	GENERATED_BODY()
private:
	UPROPERTY(EditAnywhere, Category="Kill Zone")
	UBoxComponent *KillZone = nullptr;
public:
	AKillZone();

	void BeginPlay()override;

	UFUNCTION()
	void OnKillZoneEnter(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, 
                         int32 OtherBodyIndex, bool bFromSweep, const FHitResult &SweepResult );
};
