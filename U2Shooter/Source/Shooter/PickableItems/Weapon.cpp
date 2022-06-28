#include "Weapon.h"

AWeapon::AWeapon(){
	PrimaryActorTick.bCanEverTick = true;
}

void AWeapon::OnPick(AFirstPersonCharacter* Character){
	// Also if i could assume that weapon is the only attachable thing,
	// we could override GetDefaultAttachmentComponent in Character to return View
	// and AttachToActor
	AttachToComponent(Character->GetPlayerViewComponent(), FAttachmentTransformRules::SnapToTargetNotIncludingScale);
}