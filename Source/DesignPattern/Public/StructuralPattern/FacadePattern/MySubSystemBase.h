// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "MySubSystemBase.generated.h"

/**
 * 
 */
UCLASS()
class DESIGNPATTERN_API UMySubSystemBase : public UObject
{
	GENERATED_BODY()
public:
	virtual void Run()
	{
		UE_LOG(LogTemp, Warning, TEXT("UMySubSystemBase "));
	}
	virtual void Stop()
	{
		
	}
};

UCLASS()
class UAnimationSubSystem : public UMySubSystemBase
{
	GENERATED_BODY()
public:
	virtual void Run() override
	{
		UE_LOG(LogTemp, Warning, TEXT( "UAnimationSubSystem : Run"));
	}
	virtual void Stop() override
	{
		UE_LOG(LogTemp, Warning, TEXT("UAnimationSubSystem : Stop"));
	}
};

UCLASS()
class USoundSubSystem : public UMySubSystemBase
{
	GENERATED_BODY()
public:
	virtual void Run() override
	{
		UE_LOG(LogTemp, Warning, TEXT("USoundSubSystem : Run"));
	}
	virtual void Stop() override
	{
		UE_LOG(LogTemp, Warning, TEXT("USoundSubSystem : Stop"));
	}
};
UCLASS()
class UActionSubSystem : public UMySubSystemBase
{
	GENERATED_BODY()
public:
	virtual void Run() override
	{
		UE_LOG(LogTemp, Warning, TEXT("USoundSubSystem : Run"));
	}
	virtual void Stop() override
	{
		UE_LOG(LogTemp, Warning, TEXT("USoundSubSystem : Stop"));
	}
};

