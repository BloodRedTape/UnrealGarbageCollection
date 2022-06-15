#include "FirstPersonCharacter.h"

AFirstPersonCharacter::AFirstPersonCharacter(){
	PrimaryActorTick.bCanEverTick = true;
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("PlayerViewCamera"));
}
void AFirstPersonCharacter::PostActorCreated(){
	Super::PostActorCreated();
	
	Camera->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
	Camera->SetRelativeLocation(FVector(0, 0, 40));
	Camera->bUsePawnControlRotation = true;
}

void AFirstPersonCharacter::BeginPlay(){
	Super::BeginPlay();
}

void AFirstPersonCharacter::Tick(float DeltaTime){
	Super::Tick(DeltaTime);
}

void AFirstPersonCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent){
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("Forward", this, &AFirstPersonCharacter::MoveForward);
	PlayerInputComponent->BindAxis("Right", this, &AFirstPersonCharacter::MoveRight);
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAxis("Yaw", this, &AFirstPersonCharacter::AddControllerYawInput);
	PlayerInputComponent->BindAxis("Pitch", this, &AFirstPersonCharacter::AddControllerPitchInput);
}

void AFirstPersonCharacter::MoveForward(float Value){
	AddMovementInput(GetActorForwardVector(), Value);
}
	
void AFirstPersonCharacter::MoveRight(float Value){
	AddMovementInput(GetActorRightVector(), Value);
}

void AFirstPersonCharacter::MovePitch(float Value){
	Camera->SetRelativeRotation(Camera->GetRelativeRotation() + FRotator(Value, 0, 0));
}
