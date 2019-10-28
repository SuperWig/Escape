// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "EscapeCharacter.generated.h"

UCLASS()
class ESCAPE_API AEscapeCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AEscapeCharacter();

protected:
	void MoveForward(float Value);
	void MoveRight(float Value);

	void TurnRate(float Value);
	void LookUpRate(float Value);

	void Grab();
	void Release();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
private:
	float TurnSpeed = 45.f;
	float LookUpSpeed = 45.f;
	float PickupDistance = 300.f;

	UPROPERTY()
	USceneComponent* GrabPosition;
	UPROPERTY()
	class UPhysicsHandleComponent* PhysicsHandle;
};
