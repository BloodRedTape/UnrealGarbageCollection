#include "PickableItemComponent.h"
#include "Logging/LogMacros.h"
#include "Shooter/Player/FirstPersonCharacter.h"

DEFINE_LOG_CATEGORY_STATIC(LogPickableItem, Log, All);

UPickableItemComponent::UPickableItemComponent(){
	PrimaryComponentTick.bCanEverTick = true;
	OnComponentBeginOverlap.AddDynamic(this, &UPickableItemComponent::OnBeginOverlap);
}

void UPickableItemComponent::OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, 
								AActor* OtherActor, 
								UPrimitiveComponent* OtherComp, 
								int32 OtherBodyIndex, 
								bool bFromSweep, 
								const FHitResult &SweepResult )
{
	AFirstPersonCharacter *Character = Cast<AFirstPersonCharacter>(OtherActor);

	if(!Character)return;

	OnPick.ExecuteIfBound(Character);
	UE_LOG(LogPickableItem, Display, TEXT("call OnPick"));

	GetOwner()->Destroy();
}

