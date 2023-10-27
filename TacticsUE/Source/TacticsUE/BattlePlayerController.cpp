// Fill out your copyright notice in the Description page of Project Settings.


#include "BattlePlayerController.h"

#include "EnhancedInputSubsystems.h"

ABattlePlayerController::ABattlePlayerController()
{
	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Default;
	CachedDestination = FVector::ZeroVector;
	FollowTime = 0.f;
}

void ABattlePlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent))
	{
		// Setup mouse input events
		EnhancedInputComponent->BindAction(ClickAction, ETriggerEvent::Started, this, &ABattlePlayerController::OnInputStarted);
		EnhancedInputComponent->BindAction(ClickAction, ETriggerEvent::Triggered, this, &ABattlePlayerController::OnInputTriggered);
		EnhancedInputComponent->BindAction(ClickAction, ETriggerEvent::Completed, this, &ABattlePlayerController::OnInputReleased);
	}
}

void ABattlePlayerController::BeginPlay()
{
	// Call the base class  
	Super::BeginPlay();

	//OnLeftClick.AddDynamic(this, &ABattlePlayerController::Test);

	//UE_LOG(LogTemp, Log, TEXT("Added truc"));

	//Add Input Mapping Context
	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		Subsystem->AddMappingContext(DefaultMappingContext, 0);
	}
}

void ABattlePlayerController::OnInputStarted()
{
	//UE_LOG(LogTemp, Log, TEXT("Input started"));
}

void ABattlePlayerController::OnInputTriggered()
{
	//UE_LOG(LogTemp, Log, TEXT("Input Triggered"));
}

void ABattlePlayerController::OnInputReleased()
{
	float mouseX;
	float mouseY;
	GetMousePosition(mouseX,mouseY);
	//UE_LOG(LogTemp, Log, TEXT("Mouse is %f %f"),mouseX,mouseY);

	if(OnLeftClick.IsBound()) OnLeftClick.Broadcast(mouseX,mouseY);
		
	//UE_LOG(LogTemp, Log, TEXT("Input Completed"));
}

