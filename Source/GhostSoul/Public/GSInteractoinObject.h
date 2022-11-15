// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GSGameplayInterface.h"
#include "GameFramework/Actor.h"
#include "GSInteractoinObject.generated.h"

UCLASS()
class GHOSTSOUL_API AGSInteractoinObject : public AActor , public IGSGameplayInterface
{
	GENERATED_BODY()

	void Interact_Implementation(APawn* InstigatorPawn);
public:	
	// Sets default values for this actor's properties
	AGSInteractoinObject();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
