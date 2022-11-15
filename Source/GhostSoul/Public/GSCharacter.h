// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GSCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;
class UGSAttributeComponent;
class UGSInteractionComponent;
//class UGSActionComponent;

UCLASS()
class GHOSTSOUL_API AGSCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AGSCharacter();

protected:
	UPROPERTY(VisibleAnywhere)
	USpringArmComponent* SpringArmComp;
	UPROPERTY(VisibleAnywhere)
	UCameraComponent* CameraComp;

	UPROPERTY(EditDefaultsOnly, Category="Common")
	bool IsPlayer;
	UPROPERTY(EditDefaultsOnly, Category="Common")
	float MoveSpeed;

	UPROPERTY(VisibleAnywhere, Category="Component")
	UGSAttributeComponent* AttributeComp;
	UPROPERTY(VisibleAnywhere, Category="Component")
	UGSInteractionComponent* InteractionComp;
	// UPROPERTY(VisibleAnywhere, Category="Component")
	// UGSActionComponent* ActionComp;

	//切换角色
	void ChangeCharacter(AGSCharacter* TargetChatacter);
	
	//基本行为
	void MoveForward(float Value);
	void MoveRight(float Value);
	void Roll();
	void Clamber();
	void PrimaryAttack();
	void SpecialAttack();
	void Defend();
	void DefendBack();
	virtual void Jump() override;
	
	//委托事件
	UFUNCTION(Category="Delegate Event")
	void OnHpChanged(AActor* InstigatorActor, UGSAttributeComponent* OwingComp, float NewHp, float Delta);
	UFUNCTION(Category="Delegate Event")
	void OnMpChanged(AActor* InstigatorActor, UGSAttributeComponent* OwingComp, float NewMp, float Delta);
	
	virtual void PostInitializeComponents() override;
	
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
};
