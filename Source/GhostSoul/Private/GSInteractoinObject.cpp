// Fill out your copyright notice in the Description page of Project Settings.


#include "GSInteractoinObject.h"

// Sets default values
AGSInteractoinObject::AGSInteractoinObject()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AGSInteractoinObject::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGSInteractoinObject::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AGSInteractoinObject::Interact_Implementation(APawn* InstigatorPawn)
{
	// 交互接口实现
}