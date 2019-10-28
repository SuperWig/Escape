// Fill out your copyright notice in the Description page of Project Settings.


#include "EscapeCharacter.h"
#include "Components/InputComponent.h"
#include "Engine/World.h"

// Sets default values
AEscapeCharacter::AEscapeCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AEscapeCharacter::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AEscapeCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void AEscapeCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction(TEXT("Jump"), IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction(TEXT("Jump"), IE_Released, this, &ACharacter::StopJumping);
	PlayerInputComponent->BindAction(TEXT("Grab"), IE_Pressed, this, &AEscapeCharacter::Grab);
	PlayerInputComponent->BindAction(TEXT("Grab"), IE_Released, this, &AEscapeCharacter::Release);

	PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &AEscapeCharacter::MoveForward);
	PlayerInputComponent->BindAxis(TEXT("MoveRight"), this, &AEscapeCharacter::MoveRight);
	PlayerInputComponent->BindAxis(TEXT("LookUp"), this, &ACharacter::AddControllerPitchInput);
	PlayerInputComponent->BindAxis(TEXT("Turn"), this, &AEscapeCharacter::AddControllerYawInput);
	//Controller specific bindings
	PlayerInputComponent->BindAxis(TEXT("LookUpRate"), this, &AEscapeCharacter::LookUpRate);
	PlayerInputComponent->BindAxis(TEXT("TurnRate"), this, &AEscapeCharacter::TurnRate);
}

void AEscapeCharacter::MoveForward(float Value)
{
	if (Value != 0.f)
	{
		AddMovementInput(GetActorForwardVector(), Value);
	}
}

void AEscapeCharacter::MoveRight(float Value)
{
	if (Value != 0.f)
	{
		AddMovementInput(GetActorRightVector(), Value);
	}
}

void AEscapeCharacter::TurnRate(float Value)
{
	if (Value != 0.f)
	{
		AddControllerYawInput(TurnSpeed * Value * GetWorld()->GetDeltaSeconds());
	}
}

void AEscapeCharacter::LookUpRate(float Value)
{
	if (Value != 0.f)
	{
		AddControllerYawInput(LookUpSpeed * Value * GetWorld()->GetDeltaSeconds());
	}
}

void AEscapeCharacter::Grab()
{
	const FName TraceTag = TEXT("GrabTraceTag");
	GetWorld()->DebugDrawTraceTag = TraceTag;
	FCollisionQueryParams Params(TraceTag, false, this);

	const FVector Start = GetPawnViewLocation();
	const FVector End = Start + GetViewRotation().Vector() * 500;

	FHitResult HitResult;
	GetWorld()->LineTraceSingleByChannel(HitResult, Start, End, ECC_Camera, Params);
	AActor* HitActor = HitResult.GetActor();
	if (HitActor)
	{
		UE_LOG(LogTemp, Warning, TEXT("Hit: %s"), *HitActor->GetName())
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Didn't hit anything"))
	}
}

void AEscapeCharacter::Release()
{
}
