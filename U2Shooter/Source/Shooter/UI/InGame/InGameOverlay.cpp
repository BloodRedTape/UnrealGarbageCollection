#include "InGameOverlay.h"

void UInGameOverlay::SetAmmoCount(int Count){
	if(!AmmoCount)return;
	
	AmmoCount->SetText(FText::FromString(FString::Printf(TEXT("Ammo: %d"), Count)));
}
