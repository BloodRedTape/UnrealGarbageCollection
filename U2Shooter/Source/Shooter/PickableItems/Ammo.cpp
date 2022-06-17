#include "Ammo.h"

AAmmo::AAmmo(){
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	PickableComponent= CreateDefaultSubobject<UPickableItemComponent>(TEXT("Pickable Component"));
	PickableComponent->OnPick.BindUObject(this, &AAmmo::OnPick);
	PickableComponent->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
}

void AAmmo::OnPick(AFirstPersonCharacter* Character){
	Character->Inventory.Ammo++;

	Destroy();
}
