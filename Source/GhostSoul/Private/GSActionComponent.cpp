// Fill out your copyright notice in the Description page of Project Settings.


#include "GSActionComponent.h"

// Sets default values for this component's properties
UGSActionComponent::UGSActionComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

void UGSActionComponent::MoveForward(float Value)
{
	if(ensure(OwnerPawn))
	{
		FRotator ControlRot = OwnerPawn->GetControlRotation();
		ControlRot.Pitch = 0.0f;
		ControlRot.Roll = 0.0f;
		
		OwnerPawn->AddMovementInput(ControlRot.Vector(),Value);
	}
}

void UGSActionComponent::MoveRight(float Value)
{
	if (ensure(OwnerPawn))
	{
		FRotator ControlRot = OwnerPawn->GetControlRotation();
		ControlRot.Pitch = 0.0f;
		ControlRot.Roll = 0.0f;
		
		FVector RightVector = FRotationMatrix(ControlRot).GetScaledAxis(EAxis::Y);

		OwnerPawn->AddMovementInput(RightVector, Value);
	}
}



// Called when the game starts
void UGSActionComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UGSActionComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

