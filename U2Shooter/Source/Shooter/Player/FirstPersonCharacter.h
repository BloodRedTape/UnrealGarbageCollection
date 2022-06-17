#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/Character.h"
#include "Inventory.h"
#include "FirstPersonCharacter.generated.h"

UCLASS()
class SHOOTER_API AFirstPersonCharacter : public ACharacter{
	GENERATED_BODY()
private:
	UPROPERTY(EditAnywhere, Category="FirstPersonCharacter")
	UCameraComponent *Camera;
public:
	FInventory Inventory;
public:
	AFirstPersonCharacter();

	virtual void PostActorCreated() override;

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;

	void MoveForward(float Value);
	
	void MoveRight(float Value);

	void MovePitch(float Value);

	USceneComponent *GetPlayerViewComponent()const{ return Camera; }

	void AddAmmo(int Count);
};
