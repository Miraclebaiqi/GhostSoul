// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GSActionComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class GHOSTSOUL_API UGSActionComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGSActionComponent();

protected:
	void MoveForward(float Value);
	void MoveRight(float Value);
	void Jump();
	void Roll();
	void Clamber();
	void PrimaryAttack();
	void SpecialAttack();
	void Defend();
	void DefendBack();
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	
	UPROPERTY(VisibleAnywhere)
	APawn* OwnerPawn;
	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
