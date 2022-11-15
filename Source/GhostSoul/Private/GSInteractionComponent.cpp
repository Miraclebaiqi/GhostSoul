// Fill out your copyright notice in the Description page of Project Settings.


#include "GSInteractionComponent.h"

// Sets default values for this component's properties
UGSInteractionComponent::UGSInteractionComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

// Called when the game starts
void UGSInteractionComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}

// Called every frame
void UGSInteractionComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

//基础交互方式实现(比如检测可交互物体，调用该物体的交互函数)
void UGSInteractionComponent::PrimaryInteract()
{
	
}

