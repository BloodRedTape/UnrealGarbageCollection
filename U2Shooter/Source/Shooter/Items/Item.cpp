#include "Item.h"
#include "Camera/CameraComponent.h"

DEFINE_LOG_CATEGORY_STATIC(LogItem, Log, All);

void AItem::Use(){
	UE_LOG(LogItem, Display, TEXT("AItem::%s::Use()"), *GetClass()->GetName());
}

void AItem::AttachToPlayerView(UCameraComponent* View){
	// Also if i could assume that weapon is the only attachable thing,
	// we could override GetDefaultAttachmentComponent in Character to return Camera 
	// and AttachToComponent(View->Actor something///)
	AttachToComponent(View, FAttachmentTransformRules::SnapToTargetNotIncludingScale);
}

