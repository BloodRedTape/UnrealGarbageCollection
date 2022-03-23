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
	float m_Velocity = 0;

	UPROPERTY(EditAnywhere, Category="Physics")
	float m_Mass = 1;

	UPROPERTY(EditAnywhere, Category="Physics")
	float m_Gravity = -10;

	UPROPERTY(EditAnywhere, Category="Physics")
	float m_JumpForce = 5;

	UPROPERTY(VisibleAnywhere, Category="Visuals")
	USceneComponent *Root;

	UPROPERTY(EditAnywhere, Category="Visuals")
	UStaticMeshComponent *Mesh;
public:
	ABird();

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
private:
	void AddForce(float Force);

	void OnJump();
};
