#include "KillZone.h"

AKillZone::AKillZone(){
	KillZone = CreateDefaultSubobject<UBoxComponent>(TEXT("KillZone"));
}

void AKillZone::BeginPlay(){
    Super::BeginPlay();
	KillZone->OnComponentBeginOverlap.AddDynamic( this, &AKillZone::OnKillZoneEnter );
}

void AKillZone::OnKillZoneEnter(UPrimitiveComponent* OverlappedComponent, 
                      AActor* OtherActor, 
                      UPrimitiveComponent* OtherComp, 
                      int32 OtherBodyIndex, 
                      bool bFromSweep, 
                      const FHitResult &SweepResult ){

	OtherActor->Destroy();
}