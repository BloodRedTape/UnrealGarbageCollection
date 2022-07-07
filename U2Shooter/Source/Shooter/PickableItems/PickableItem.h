#pragma once

#include "CoreMinimal.h"
#include "PickableItemComponent.h"
#include "GameFramework/Actor.h"
#include "Shooter/Player/FirstPersonCharacter.h"
#include "Shooter/Items/Item.h"
#include "PickableItem.generated.h"

UCLASS(abstract)
class SHOOTER_API APickableItem : public AActor{
	GENERATED_BODY()
private:
	UPROPERTY(EditAnywhere, Category="PickableItem")
	TSubclassOf<AItem> ItemClass;

	USceneComponent *SceneComponent = nullptr;
	
	UPROPERTY(EditAnywhere, Category="PickableItem")
	UPickableItemComponent *PickableItemComponent = nullptr;
public:
	APickableItem();

	void OnPick(AFirstPersonCharacter *Character);
};
