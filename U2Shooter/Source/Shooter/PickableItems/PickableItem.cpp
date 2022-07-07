#include "PickableItem.h"

APickableItem::APickableItem(){
	PrimaryActorTick.bCanEverTick = true;
	RootComponent = SceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	PickableItemComponent = CreateDefaultSubobject<UPickableItemComponent>(TEXT("PickableItemComponent"));
	PickableItemComponent->OnPick.BindUObject(this, &APickableItem::OnPick);
	PickableItemComponent->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
}

void APickableItem::OnPick(AFirstPersonCharacter* Character){
	check(ItemClass);
	
	AItem *Item = GetWorld()->SpawnActor<AItem>(ItemClass);
	Character->PickItem(Item);
}
