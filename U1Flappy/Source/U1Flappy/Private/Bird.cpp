#include "Bird.h"

ABird::ABird(){
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = Root = CreateDefaultSubobject<USceneComponent>(TEXT("MeshComponent"));

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Bird's Mesh"));
	Mesh->AttachTo(RootComponent);
}

void ABird::BeginPlay(){
	Super::BeginPlay();
	
}

void ABird::Tick(float DeltaTime){
	Super::Tick(DeltaTime);

	m_Velocity += m_Gravity * DeltaTime;

	FVector Location = GetActorLocation();
	Location.Z += m_Velocity;
	SetActorLocation(Location);
}

void ABird::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent){
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction(TEXT("Jump"), EInputEvent::IE_Pressed, this, &ABird::OnJump);
}

void ABird::AddForce(float Force){
	m_Velocity += Force / m_Mass;
}

void ABird::OnJump(){
	AddForce(m_JumpForce);
}