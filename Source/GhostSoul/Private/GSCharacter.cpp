// Fill out your copyright notice in the Description page of Project Settings.


#include "GSCharacter.h"

#include "GSAttributeComponent.h"
#include "GSInteractionComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"

// Sets default values
AGSCharacter::AGSCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	GetCharacterMovement()->bOrientRotationToMovement = true;
	bUseControllerRotationYaw = false;

	SpringArmComp = CreateDefaultSubobject<USpringArmComponent>("SpringArmComp");
	SpringArmComp->bUsePawnControlRotation = true;
	SpringArmComp->SetupAttachment(RootComponent);

	CameraComp = CreateDefaultSubobject<UCameraComponent>("CameraComp");
	CameraComp->SetupAttachment(SpringArmComp);

	AttributeComp = CreateDefaultSubobject<UGSAttributeComponent>("AttributeComp");
	InteractionComp = CreateDefaultSubobject<UGSInteractionComponent>("InteractionComp");

	// ActionComp = CreateDefaultSubobject<UGSActionComponent>("ActionComp");
	// ActionComp->OwnerPawn = this;
}


void AGSCharacter::PostInitializeComponents()
{
	Super::PostInitializeComponents();
	AttributeComp->OnHpChanged.AddDynamic(this, &AGSCharacter::OnHpChanged);
	AttributeComp->OnMpChanged.AddDynamic(this, &AGSCharacter::OnMpChanged);
}

// Called when the game starts or when spawned
void AGSCharacter::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AGSCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void AGSCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis("MoveForward", this, &AGSCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AGSCharacter::MoveRight);

	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);

	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &AGSCharacter::Jump);

	PlayerInputComponent->BindAction("Roll", IE_Pressed, this, &AGSCharacter::Roll);
	PlayerInputComponent->BindAction("Clamber", IE_Pressed, this, &AGSCharacter::Clamber);
	PlayerInputComponent->BindAction("PrimaryAttack", IE_Pressed, this, &AGSCharacter::PrimaryAttack);
	//	PlayerInputComponent->BindAction("SpecialAttack", IE_Pressed, this, &AGSCharacter::SpecialAttack);
	PlayerInputComponent->BindAction("Defend", IE_Pressed, this, &AGSCharacter::Defend);
	//	PlayerInputComponent->BindAction("DefendBack", IE_Pressed, this, &AGSCharacter::DefendBack);
}

void AGSCharacter::MoveForward(float Value)
{
	FRotator ControlRot = GetControlRotation();
	ControlRot.Pitch = 0.0f;
	ControlRot.Roll = 0.0f;
	AddMovementInput(ControlRot.Vector(), Value);
}

void AGSCharacter::MoveRight(float Value)
{
	FRotator ControlRot = GetControlRotation();
	ControlRot.Pitch = 0.0f;
	ControlRot.Roll = 0.0f;
	FVector RightVector = FRotationMatrix(ControlRot).GetScaledAxis(EAxis::Y);
	AddMovementInput(RightVector, Value);
}

void AGSCharacter::Roll()
{
}

void AGSCharacter::Clamber()
{
}

void AGSCharacter::PrimaryAttack()
{
}

void AGSCharacter::SpecialAttack()
{
}

void AGSCharacter::Defend()
{
}

void AGSCharacter::DefendBack()
{
}

void AGSCharacter::Jump()
{
	Super::Jump();
}

void AGSCharacter::OnHpChanged(AActor* InstigatorActor, UGSAttributeComponent* OwingComp, float NewHp, float Delta)
{
}

void AGSCharacter::OnMpChanged(AActor* InstigatorActor, UGSAttributeComponent* OwingComp, float NewMp, float Delta)
{
}
