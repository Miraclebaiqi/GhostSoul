// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GSCharacter.h"
#include "Components/ActorComponent.h"
#include "GSAttributeComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_FourParams(FOnAttributeChanged, AActor*, InstigatorActor, UGSAttributeComponent*, OwingComp, float, NewValue, float, Delta);

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class GHOSTSOUL_API UGSAttributeComponent : public UActorComponent
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="Attribute")
	float Hp;
	UPROPERTY(EditDefaultsOnly, Category="Attribute")
	float MaxHp;
	UPROPERTY(EditDefaultsOnly, Category="Attribute")
	float Mp;
	UPROPERTY(EditDefaultsOnly, Category="Attribute")
	float MaxMp;
	UPROPERTY(EditDefaultsOnly, Category="Attribute")
	float Atk;
	UPROPERTY(EditDefaultsOnly, Category="Attribute")
	float Def;

	

public:
	UFUNCTION(BlueprintCallable, Category="Get")
	float GetHp() const;
	UFUNCTION(BlueprintCallable, Category="Get")
	float GetMaxHp() const;
	UFUNCTION(BlueprintCallable, Category="Get")
	float GetMp() const;
	UFUNCTION(BlueprintCallable, Category="Get")
	float GetMaxMp() const;
	UFUNCTION(BlueprintCallable, Category="Get")
	float GetAtk() const;
	UFUNCTION(BlueprintCallable, Category="Get")
	float GetDef() const;

	UFUNCTION(BlueprintCallable, Category="Change")
	bool ApplyHpChange(float Delta);
	UFUNCTION(BlueprintCallable, Category="Change")
	bool ApplyMaxHpChange(float Delta);
	UFUNCTION(BlueprintCallable, Category="Change")
	bool ApplyMpChange(float Delta);
	UFUNCTION(BlueprintCallable, Category="Change")
	bool ApplyMaxMpChange(float Delta);

	UPROPERTY(BlueprintAssignable)
	FOnAttributeChanged OnHpChanged;
	UPROPERTY(BlueprintAssignable)
	FOnAttributeChanged OnMpChanged;
	
	// Sets default values for this component's properties
	UGSAttributeComponent();
};
