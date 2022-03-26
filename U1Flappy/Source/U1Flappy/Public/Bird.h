// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Components/SceneComponent.h"
#include "Bird.generated.h"

UCLASS()
class U1FLAPPY_API ABird : public APawn
{
	GENERATED_BODY()
private:
	UPROPERTY(EditAnywhere, Category="Physics")
	float Velocity = 0;

	UPROPERTY(EditAnywhere, Category="Physics")
	float Mass = 1;

	UPROPERTY(EditAnywhere, Category="Physics")
	float Gravity = -10;

	UPROPERTY(EditAnywhere, Category="Physics")
	float JumpForce = 5;

	UPROPERTY(VisibleAnywhere, Category="Visuals")
	USceneComponent *Root;

	UPROPERTY(EditAnywhere, Category="Visuals")
	UStaticMeshComponent *Mesh;
public:
	UPROPERTY(EditAnywhere, Category="Physics")
	bool bPhysicsEnabled = false;
public:
	ABird();

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
private:
	void AddForce(float Force);

	void OnJump();

	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, 
                         int32 OtherBodyIndex, bool bFromSweep, const FHitResult &SweepResult );
};
