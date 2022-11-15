// Fill out your copyright notice in the Description page of Project Settings.


#include "GSAttributeComponent.h"


// Sets default values for this component's properties
UGSAttributeComponent::UGSAttributeComponent()
{
	MaxHp = 100.0f;
	Hp = 100.0f;
	MaxMp = 100.0f;
	Mp = 100.0f;
	Atk = 10.0f;
	Def = 10.0f;
}

bool UGSAttributeComponent::ApplyHpChange(float Delta)
{
	float OldHp = Hp;
	Hp = FMath::Clamp(Hp + Delta, 0.0f, MaxHp);
	float RealDelta = Hp - OldHp;
	OnHpChanged.Broadcast(nullptr, this, Hp, RealDelta);

	return RealDelta != 0;
}

bool UGSAttributeComponent::ApplyMaxHpChange(float Delta)
{
	MaxHp += Delta;
	Hp += Delta;

	return Delta != 0;
}

bool UGSAttributeComponent::ApplyMpChange(float Delta)
{
	float OldMp = Mp;
	Hp = FMath::Clamp(Mp + Delta, 0.0f, MaxMp);
	float RealDelta = Mp - OldMp;
	OnMpChanged.Broadcast(nullptr, this, Mp, RealDelta);

	return RealDelta != 0;
}

bool UGSAttributeComponent::ApplyMaxMpChange(float Delta)
{
	MaxMp += Delta;
	Mp += Delta;

	return Delta != 0;
}


float UGSAttributeComponent::GetHp() const
{
	return Hp;
}

float UGSAttributeComponent::GetMaxHp() const
{
	return MaxHp;
}

float UGSAttributeComponent::GetMp() const
{
	return Mp;
}

float UGSAttributeComponent::GetMaxMp() const
{
	return MaxMp;
}

float UGSAttributeComponent::GetAtk() const
{
	return Atk;
}

float UGSAttributeComponent::GetDef() const
{
	return Def;
}
