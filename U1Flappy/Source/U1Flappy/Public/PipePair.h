#pragma once

#include <type_traits>
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PipePair.generated.h"

UCLASS()
class U1FLAPPY_API APipePair : public AActor{
	GENERATED_BODY()
private:
	UPROPERTY(EditAnywhere, Category="Gameplay")
	float Speed = 80;

	UPROPERTY(EditAnywhere, Category="Visuals")
	float PairHeight = 800;

	UPROPERTY(EditAnywhere, Category="Visuals")
	float HoleSize = 200;

	float HoleOffset;

	UPROPERTY(EditAnywhere, Category="Visuals")
	UStaticMesh *PipeBase = nullptr;

	UPROPERTY(EditAnywhere, Category="Visuals")
	UStaticMesh *PipeTop = nullptr;
public:
	APipePair();
	
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

	template <typename T, typename = decltype(static_cast<UActorComponent*>((T*)nullptr))>
	T *AddComponent(){
		T *Component = NewObject<T>(this, T::StaticClass());
		Component->RegisterComponent();
		return Component;
	}

	template <typename T, typename = decltype(static_cast<USceneComponent*>((T*)nullptr))>
	T *AddSceneComponent(USceneComponent *AttachTo){
		T *Component = AddComponent<T>();
		Component->AttachToComponent(AttachTo, FAttachmentTransformRules::KeepRelativeTransform);
		return Component;
	}
};
